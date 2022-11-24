#include "lpc.h"

// Change adj. mat. so that we have a complete graph within the target nbhd.
void fillTargetNeighborhood(Graph* C_tilde,
                            std::map<int,int> node_numbering,
                            NumericVector nbhd_t){
  size_t i_eff; size_t j_eff;
  for (auto it=nbhd_t.begin();it<nbhd_t.end()-1;++it){
    // Efficient number of nbhd node
    i_eff = node_numbering.find(*it)->second; 
    for (auto it2 = it+1;it2<nbhd_t.end();++it2){
      // Efficient number of other nbhd node
      j_eff = node_numbering.find(*it2)->second;
      C_tilde -> setAmatVal(i_eff,j_eff,1);
      C_tilde -> setAmatVal(j_eff,i_eff,1);
    }
  }
}

/*
 * Create the adjacency matrix representing complete graphs for each neighborhood
 */
void createInitialAmat(Graph* C_tilde,
                       std::map<int,int> node_numbering,
                       MBList* mb_list,
                       NumericVector &targets,
                       NumericVector &neighborhood,
                       const size_t &N,bool verbose){
  if (verbose){
    Rcout << "FUNCTION createInitialAmat\n";
  }
  // Begin with empty graph rather than a complete one
  C_tilde -> emptyGraph();
  
  NumericVector nbhd_t;

  // Loop through each of the targets
  for (auto it=targets.begin();it<targets.end();++it){
    // Find the target's neighbors (true numbering)
    if (verbose){
      Rcout << "Target: " << *it << std::endl;
    }
    // Stores Markov Blanket of target and the target
    nbhd_t = mb_list -> getMB(*it);
    nbhd_t.push_back(*it);
    // Begin with a complete graph in the target neighborhood
    fillTargetNeighborhood(C_tilde,node_numbering,nbhd_t);
  }
  
  if (verbose){
    Rcout << "Initial Adj. Matrix:\n";
    C_tilde -> printAmat();
  }
}

// Population version of the constructor
LocalPC::LocalPC(NumericMatrix true_dag,
                 NumericVector targets,
                 NumericVector nodes_interest,
                 StringVector names,
                 int lmax,
                 bool verbose) : 
  ConstrainedAlgo(true_dag,targets,nodes_interest,names,
                  lmax,verbose){
  pop = true;
  
  // Make a map to relate efficient numbering to true numbering
  // Map: true numbering -> efficient numbering
  for (size_t i=0;i<N;++i){
    node_numbering.insert(std::pair<int,int>(neighborhood(i),i));
  }
  if (verbose){
    Rcout << "Element mapping for efficient ordering (True -> Efficient):\n";
    for(auto it = node_numbering.cbegin(); it != node_numbering.cend(); ++it)
    {
      Rcout << it->first << " " << it->second  << "\n";
    }
  }
  
  // Separate elements not belonging to the same neighborhood
  // otherwise, we begin with default complete graph
  if (targets.length()>1){
    createInitialAmat(C_tilde,node_numbering,mb_list,targets,neighborhood,N,verbose); 
  }
}

// Sample version of the constructor
LocalPC::LocalPC(NumericMatrix true_dag,arma::mat df,
                 NumericVector targets,
                 NumericVector nodes_interest,
                 StringVector names,
                 int lmax,
                 double signif_level,
                 bool verbose,bool estDAG) : 
  ConstrainedAlgo(true_dag,df,targets,nodes_interest,names,lmax,
                  signif_level,verbose,estDAG){
  
  // Make a map to relate efficient numbering to true numbering
  // Map: true numbering -> efficient numbering
  for (size_t i=0;i<N;++i){
    node_numbering.insert(std::pair<int,int>(neighborhood(i),i));
  }
  if (verbose){
    Rcout << "Element mapping for efficient ordering:\n";
    for(auto it = node_numbering.cbegin(); it != node_numbering.cend(); ++it)
    {
      Rcout << it->first << " " << it->second << "\n";
    }
  }
  
  // Separate elements not belonging to the same neighborhood
  // otherwise, we begin with default complete graph
  if (targets.length() > 1) {
    createInitialAmat(C_tilde,node_numbering,mb_list,targets,neighborhood,N,verbose);
  }
}

// [[Rcpp::export]]
void validateTargetLPC(NumericVector targets,const size_t &t){
  if (!isMember(targets,t)){
    stop("Target %i is not a member of the target vector");
  }
}

void LocalPC::getSkeletonTarget(const size_t &t){
  // Ensure that t is in targets
  validateTargetLPC(targets,t);
  auto target_skeleton_start = high_resolution_clock::now();
  int l = -1;
  NumericVector neighbors;
  NumericVector edges_i;
  NumericMatrix kvals;
  
  // Making an adjustment to target based on efficient numbering
  size_t target_efficient = node_numbering.find(t)->second;
  // Find neighborhood just surrounding the target node
  NumericVector target_neighborhood = C_tilde->getAdjacent(target_efficient);
  target_neighborhood.push_back(target_efficient);
  std::sort(target_neighborhood.begin(),target_neighborhood.end());
  
  if (verbose){
    Rcout << "\n\nFinding skeleton for the neighborhood of target " << t;
    Rcout << " (Name: " << names(t) << 
      ", Efficient Number: " << target_efficient << ")"<< std::endl;
    Rcout << "Neighborhood nodes under consideration: ";
    printVecElementsNoNames(target_neighborhood,""," | (");
    for (size_t i=0;i<target_neighborhood.length();++i){
      if (i<target_neighborhood.length()-1){
        Rcout << names(neighborhood(target_neighborhood(i))) << 
          "(" << neighborhood(target_neighborhood(i)) << ")" << " ";  
      } else {
        Rcout << names(neighborhood(target_neighborhood(i))) << 
          "(" << neighborhood(target_neighborhood(i)) << ")" << ")\n";
      } 
    }
  }
  
  while (l < lmax){
    l += 1;
    if (verbose){
      Rcout << "The value of l is " << l << std::endl;
    }
    
    // We only consider the target and its neighborhood in the graph currently
    for (auto i : target_neighborhood){
      if (verbose){
        Rcout << "The value of i is " << i << std::endl;
      }
      // Work through potential neighbors with separating set of size l
      // These potential neighbors are those currently connected to node i 
      // in the current iteration's estimated graph.
      // We do not want to separate the connections between two different cliques
      // when they share a node
      edges_i = intersect(C_tilde->getAdjacent(i),target_neighborhood);
      for (auto j : edges_i){
        if (j > i){
          if (verbose){
            Rcout << "The value of j is " << j << std::endl;
          }
          if (l>0){
            // Find neighbors of i and j from the true DAG (or they are estimated)
            // These neighbors are using the true node numbers (check documentation for this function)
            bool tmp = mb_list -> silencer();
            neighbors = mb_list -> getMBMultipleTargets(
              NumericVector::create(neighborhood(i),neighborhood(j)),
              false,true); // don't include target nodes
            mb_list -> removeSilencer(tmp);
            if (verbose){
              printVecElementsNoNames(neighbors,"Potential separating nodes: ","\n");  
            }
          } else {
            neighbors = NA_REAL;  // l = 0
          }
          // If there are enough potential neighbors to match the current separating set size, we continue
          if (neighbors.length()>= l){
            if (verbose && l>0){
              Rcout << "There are " << neighbors.length() << " neighbor(s).\n";
            }
            // We use all combinations of the Markov Blanket of size l
            // to see if we can separate nodes i and j
            kvals = combn_cpp(neighbors,l);
            checkSeparation(l,i,j,kvals);
          }
        }
      }
    }
  }
  if (verbose){
    Rcout << "The final C matrix:\n";
    C_tilde -> printAmat();
    Rcout << "Conclusion of algorithm.\n";
  }
  // Save the amount of time taken for the algorithm
  auto target_skeleton_end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(target_skeleton_end-target_skeleton_start);
  double total_time = duration.count() / 1000000.;
  
  target_skeleton_times.push_back(total_time);
}

/*
 * Take the values from the adj. mat. using efficient numbering 
 * and transfer them to the final adj. mat. with correct dimensions
 */
void LocalPC::convertFinalGraph(){
  // New empty graph of full size
  Graph* g = new Graph(p);
  g -> emptyGraph();
  size_t current_val = 0;
  
  for (size_t i=0;i<N;++i){
    for (size_t j=0;j<N;++j){
      // Transfer values to final graph
      current_val = C_tilde -> getAmatVal(i,j);
      g -> setAmatVal(neighborhood(i),neighborhood(j),current_val);  
    }
  }
  // Delete the old, efficient graph and exchange it for the new
  delete C_tilde;
  C_tilde = g;
  g = nullptr;
}

void LocalPC::run(){
  if (verbose){
    Rcout << "Beginning the";
    if (pop){
      Rcout << " population";
    }
    Rcout << " Local PC algorithm over all neighborhoods.\n";
  }

  // Get the skeleton for each target node and its neighborhood
  std::for_each(targets.begin(),targets.end(),
                [this](size_t t){ getSkeletonTarget(t); });
  // Find v-structures
  getVStructures();
  // Convert the adj. mat. to the proper dimensions
  convertFinalGraph();
  // Add up all the times for the target skeletons
  total_time += std::accumulate(target_skeleton_times.begin(),
                                target_skeleton_times.end(),0);
}

