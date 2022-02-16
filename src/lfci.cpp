#include "lfci.h"

LocalFCI::LocalFCI(NumericMatrix true_dag,arma::mat df,
                   NumericVector targets,
                   StringVector names,int lmax,
                   double signif_level,
                   bool verbose) : verbose(verbose),lmax(lmax),signif_level(signif_level),names(names){
  
  num_targets = targets.length();
  if (verbose){
    Rcout << "There are " << num_targets << " targets.\n";
    print_vector_elements(targets,names,"Targets: ","\n");
  }
  p = true_dag.ncol();
  R = arma::cor(df);
  n = df.n_rows;
  num_tests=0;
  
  // Set DAG object
  true_DAG = new DAG(p,names,true_dag);
  
  // Find the neighborhood of the target nodes
  neighborhood = true_DAG -> getNeighborsMultiTargets(targets,verbose); //tested
  neighborhood = union_(neighborhood,targets); //tested
  std::sort(neighborhood.begin(),neighborhood.end()); //tested
  
  N = neighborhood.size();
  
  if (verbose){
    Rcout << "There are " << p << " nodes in the DAG.\n";
    Rcout << "There are " << N << " nodes in the neighborhood.\n";
    Rcout << "All nodes being considered: ";
    print_vector_elements_nonames(neighborhood,"","\n");
  }
  
  // Initial graph that will be modified through the process of the algorithm
  C_tilde = new Graph(N);
  
  if (verbose){
    Rcout << "Our starting matrix is " << C_tilde->getNRow() << "x" << C_tilde->getNCol() << ".\n";
    C_tilde -> printAmat();
    Rcout << "\n\n";
  }
  
  // Create the list that will store separating sets
  S = new SepSetList(neighborhood);
  if (verbose){
    Rcout << "\nOur initial separating sets:\n";
    S -> printSepSetList();
  }
  
  // Make a map to relate efficient numbering to true numbering
  // Map: true numbering -> efficient numbering
  for (int i=0;i<N;++i){
    node_numbering.insert(std::pair<int,int>(neighborhood(i),i));
  }
  if (verbose){
    Rcout << "Element mapping for efficient ordering:\n";
    for(auto it = node_numbering.cbegin(); it != node_numbering.cend(); ++it)
    {
      Rcout << it->first << " " << it->second  << "\n";
    }
  }
}

void LocalFCI::print_elements(){
  Rcout << "p: " << p << std::endl;
  Rcout << "n: " << n << std::endl;
  Rcout << "N: " << N << std::endl;
  Rcout << "Number of Targets: " << num_targets << std::endl;
  Rcout << "Node names: ";
  std::for_each(names.begin(),names.end(),[](String n) {Rcout << n.get_cstring() << " ";});
  Rcout << std::endl;
  Rcout << "lmax: " << lmax << std::endl;
  Rcout << "verbose: " << verbose << std::endl;
  Rcout << "Nodes under consideration: ";
  print_vector_elements_nonames(neighborhood);
  Rcout << std::endl << "Ctilde:\n";
  Rcout << "Our Ctilde matrix is " << C_tilde->getNRow() << "x" << C_tilde->getNCol() << std::endl;
  C_tilde->printAmat();
  Rcout << "Our DAG matrix is " << std::endl;
  true_DAG->printAmat();
  Rcout << "Separating Set Values:\n";
  S->printSepSetList();
}

void LocalFCI::checkSeparation(int l,int i,int j,NumericMatrix kvals){
  int k;
  int kp = kvals.cols();
  bool keep_checking_k;
  List test_result;
  
  // Initially assumes we are considering an empty set
  arma::uvec sep_arma;
  
  if (l == 0){
    sep = NA_REAL;
    test_result = condIndTest(R,neighborhood(i),neighborhood(j),sep_arma,n,signif_level);
    ++num_tests;
    p_vals.push_back(test_result["pval"]);
    if (verbose){
      Rcout << "The p-value is " << p_vals[p_vals.size()-1] << std::endl;
    }
    if (test_result["result"]){ // We have statistically significant evidence of conditional independence
      if (verbose){
        Rcout << names(neighborhood(i)) << " is separated from " << names(neighborhood(j));
        Rcout << " (p-value>" << signif_level << ")"<< std::endl;
        //Rcout << "i = " << i << " | j = " << j << " | N_i = " << neighborhood(i) << " | N_j = " << neighborhood(j) << std::endl;
      }
      S->changeList(i,j);
      S->changeList(j,i);
      
      C_tilde->setAmatVal(i,j,0);
      C_tilde->setAmatVal(j,i,0);
    }
  } else {
    k = 0;
    keep_checking_k = true;
    while (keep_checking_k && (k<kp)){
      sep = kvals( _ , k ); // sep is the vector of the true values of the potential separating nodes (i.e. not efficient numbering)
      sep_arma = as<arma::uvec>(sep);
      if (verbose){
        Rcout << "Efficient Setup: " << i << " -> " << neighborhood(i);
        Rcout << " | " << j << " -> " << neighborhood(j);
        Rcout << " | k (True Vals): ";
        print_vector_elements_nonames(sep,""," ("," ");
        print_vector_elements(sep,names,"",")\n");
      }
      test_result = condIndTest(R,neighborhood(i),neighborhood(j),sep_arma,n,signif_level);
      ++num_tests;
      p_vals.push_back(test_result["pval"]);
      //pval = as<double>(get_pval(i,j,true_dag,names,sep));
      if (verbose){
        Rcout << "The p-value is " << p_vals[p_vals.size()-1] << std::endl;
      }
      if (test_result["result"]){
        if (verbose){
          Rcout << names(neighborhood(i)) << " is separated from " << names(neighborhood(j)) << " by node(s): ";
          print_vector_elements(sep,names,""," ");
          Rcout << " (p-value>" << signif_level << ")"<< std::endl;
        }
        S->changeList(i,j,sep);
        S->changeList(j,i,sep);
        C_tilde->setAmatVal(i,j,0);
        C_tilde->setAmatVal(j,i,0);
        keep_checking_k = false;
      } else {
        if (verbose){
          Rcout << names(neighborhood(i)) << " is NOT separated from " << names(neighborhood(j)) << " by node(s): ";
          print_vector_elements(sep,names,""," ");
          Rcout << " (p-value<" << signif_level << ")"<< std::endl;
        }
      }
      ++k; // Increment to obtain the next potential separating set
    }
  }
}

void LocalFCI::get_skeleton_total(){
  auto total_skeleton_start = high_resolution_clock::now();
  NumericVector neighbors;
  NumericVector edges_i;
  
  NumericMatrix kvals;
  
  int l = -1;
  //Rcout << "Finding the skeleton for the complete undirected graph on X_T U N_T\n\n";
  while (l < lmax){
    l += 1;
    if (verbose){
      Rcout << "The value of l is " << l << std::endl;
    }
    
    for (int i=0;i<N;++i){
      if (verbose){
        Rcout << "The value of i is " << i;
        Rcout << " (" << names(neighborhood(i)) << ")"<< std::endl;
      }
      // Work through potential neighbors with separating set of size l
      // These potential neighbors are those currently connected to node i in the current iteration's estimated graph
      edges_i = C_tilde->getAdjacent(i);
      for (NumericVector::iterator it = edges_i.begin(); it != edges_i.end(); ++it){
        int j = *it;
        if (j > i){
          
          if (verbose){
            Rcout << "The value of j is " << j;
            Rcout << " (" << names(neighborhood(j)) << ")"<< std::endl;
          }
          // Find neighbors of i and j from the current graph C
          neighbors = setdiff(union_(edges_i,C_tilde->getAdjacent(j)),NumericVector::create(i,j));
          
          // If there are enough potential neighbors to match the current separating set size, we continue
          if (neighbors.length()>= l){
            if (verbose && l>0){
              if (neighbors.length() > 1){
                Rcout << "There are " << neighbors.length() << " neighbors.\n";
              } else {
                Rcout << "There is " << neighbors.length() << " neighbor.\n";
              }
            }
            if (neighbors.length()>neighborhood.length()){
              stop("Invalid number of neighbors for nodes i and j.\n");
            }

            std::for_each(neighbors.begin(),neighbors.end(),[this](int n){
              if (n>=N){
                stop("Neighbor value %i is too large.",n);
              } else if (n<0){
                stop("Neighbor value is negative");
              }
            });
            kvals = combn_cpp(neighborhood[neighbors],l);
            // check whether nodes i and j are separated by any of the potential separating sets in kvals
            checkSeparation(l,i,j,kvals);
          }
        }
      }
      
    }
    
  }
  if (verbose){
    Rcout << "\n\nValues after Total Skeleton Run\n\n";
    print_elements();
  }
  auto total_skeleton_end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(total_skeleton_end-total_skeleton_start);
  total_skeleton_time = duration.count() / 1000000.;
}

void LocalFCI::get_skeleton_target(int t){
  // TODO: Ensure that t is in targets
  auto target_skeleton_start = high_resolution_clock::now();
  int l = -1;
  int i;
  int j;
  NumericVector neighbors;
  NumericVector edges_i;
  NumericMatrix kvals;
  
  // Making an adjustment to target based on efficient numbering
  int target_efficient = node_numbering.find(t)->second;
  // Find neighborhood just surrounding the target node
  NumericVector target_neighborhood = C_tilde->getAdjacent(target_efficient);
  target_neighborhood.push_back(target_efficient);
  std::sort(target_neighborhood.begin(),target_neighborhood.end());
  
  if (verbose){
    Rcout << "\n\nFinding skeleton for the neighborhood of target " << t;
    Rcout << " (Efficient Number: " << target_efficient << ")"<< std::endl;
    Rcout << "Neighborhood nodes under consideration: ";
    print_vector_elements_nonames(target_neighborhood,""," | (");
    for (int i=0;i<target_neighborhood.length();++i){
      if (i<target_neighborhood.length()-1){
        Rcout << names(neighborhood(target_neighborhood(i))) << "(" << neighborhood(target_neighborhood(i)) << ")" << " ";  
      } else {
        Rcout << names(neighborhood(target_neighborhood(i))) << "(" << neighborhood(target_neighborhood(i)) << ")" << ")\n";
      } 
    }
  }
  
  while (l < lmax){
    l += 1;
    if (verbose){
      Rcout << "The value of l is " << l << std::endl;
    }
    
    // We only consider the target and its neighborhood in the graph currently
    for (NumericVector::iterator it=target_neighborhood.begin();it<target_neighborhood.end();++it){
      i = *it;
      if (verbose){
        Rcout << "The value of i is " << i << std::endl;
      }
      // Work through potential neighbors with separating set of size l
      // These potential neighbors are those currently connected to node i in the current iteration's estimated graph
      // We do not want to separate the connections between two different cliques
      // TODO: explain why we need this line in more detail
      edges_i = intersect(C_tilde->getAdjacent(i),target_neighborhood);
      for (NumericVector::iterator it2 = edges_i.begin(); it2 != edges_i.end(); ++it2){
        j = *it2;
        if (j > i){
          if (verbose){
            Rcout << "The value of j is " << j << std::endl;
          }
          if (l>0){
            // Find neighbors of i and j from the true DAG (or they are estimated)
            // These neighbors are using the true node numbers (check documentation for this function)
            neighbors = true_DAG -> getNeighborsMultiTargets(NumericVector::create(neighborhood(i),neighborhood(j)),
                                                             verbose);
            if (verbose){
              print_vector_elements_nonames(neighbors,"Potential separating nodes: ","\n");  
            }
          } else {
            neighbors = NA_REAL;  // l = 0
          }
          
          // If there are enough potential neighbors to match the current separating set size, we continue
          if (neighbors.length()>= l){
            if (verbose && l>0){
              Rcout << "There are " << neighbors.length() << " neighbor(s).\n";
            }
            kvals = combn_cpp(neighbors,l);
            
            checkSeparation(l,i,j,kvals);
            
            if (verbose){
              iteration_print(l,i,j,sep,names,p_vals.back());
            }
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

// We are trying to identify structures i -> k <- j
// Where i and j are not adjacent, and k is not in the separating set of i and j
void LocalFCI::get_v_structures_efficient() {
  int j;
  int k;
  int k_eff;
  
  bool no_neighbors;
  bool j_invalid;
  NumericVector placeholder;
  
  NumericVector i_adj;
  NumericVector j_adj;
  NumericVector j_vals;
  NumericVector k_vals;
  
  List sublist_i;
  List sublist_j;

  String node_i;
  String node_j;
  
  NumericVector sepset_ij;
  NumericVector sepset_ji;
  
  if (verbose){
    Rcout << "Beginning loops to find v-structures.\n";
  }
  // We are searching for i-k-j where i and j are not adjacent and k is 
  // not in the separating set for i and j
  for (int i=0;i<N;++i){
    placeholder = C_tilde->getAmatRow(i); // We will search this vector for nodes connected to node i
    no_neighbors = (all(placeholder==0)).is_true();
    if (!no_neighbors){ // If there are neighbors to consider
      if (verbose){
        Rcout << "i: "<< i << " (" << names(neighborhood(i)) << ")" << std::endl;
      }
      i_adj = C_tilde->getAdjacent(i); // potential values of k
      j_vals = C_tilde->getNonAdjacent(i); // potential values of j
      // Iterate over possible j values
      for (NumericVector::iterator it=j_vals.begin();it != j_vals.end();++it){
        j = *it;
        // We move on if:
        // Node j has no children,
        // j is parent to i, 
        // or we are repeating an analysis and this j should not be considered
        placeholder = C_tilde->getAmatRow(j);
        j_invalid = (all(placeholder==0)).is_true();
        j_invalid = j_invalid || C_tilde->getAmatVal(j,i)!= 0 || j <= i;
        if (!j_invalid){
          if (verbose){
            Rcout << "j: " << j << " (" << names(neighborhood(j)) << ")"<< std::endl;
          }
          j_adj = C_tilde->getAdjacent(j);
          k_vals = intersect(i_adj,j_adj); // k must be a neighbor of i and j
          std::sort(k_vals.begin(),k_vals.end());
          if (verbose && k_vals.length()>0){
            Rcout << "Potential k values: ";
            print_vector_elements(k_vals,names[neighborhood],"","\n");
          }
          // If there are no common neighbors, move to next j
          if (k_vals.length()!=0){
            // We loop through all of the common neighbors
            sepset_ij = S->getSepSet(i,j);
            sepset_ji = S->getSepSet(j,i);
            for (NumericVector::iterator it2 = k_vals.begin();it2!=k_vals.end();++it2){
              k = *it2;
              if (verbose){
                Rcout << "k: " << k << " (" << names(neighborhood(k)) << ")\n"; 
              }
              // Verify if k is in separating set for i and j
              k_eff = k;
              k = neighborhood(k); // Switch k to true numbering
              if (S->isPotentialVStruct(i,j,k)){ // True just refers to numbering
                if (verbose){
                  Rcout << "Separation Set: ";
                  print_vector_elements_nonames(sepset_ij);
                  Rcout << " | V-Structure (True Numbering): " << neighborhood(i) << "*->" << k << "<-*" << neighborhood(j) << std::endl; 
                }
                C_tilde->setAmatVal(i,k_eff,2); // An arrow is denoted by "2"
                C_tilde->setAmatVal(j,k_eff,2); // i and j are separated ("0")
              }
            }
          }
        }
      }
    }
  }
}








/*
 * 
 * Define functions for the rules used in the FCI algorithm
 * Definitions:
 * 0: No edge
 * 1: -o
 * 2: -> (arrowhead)
 * 3: - (tail)
 * 
 * Note that a * represents a wild card that can represent either an open circle or an arrow
 * When we are considering the PC algorithm, for nodes i and j, if we have i -> j,
 * we regard G(i,j) = 2 and G(j,i) = 3. Therefore, in keeping with this convention, for FCI we will consider the arrowhead
 * information stored in G to be related to the arrowhead incident on the second node for the edge in consideration.
 * For example, if i o-> j is the edge in consideration, G(i,j)=2, since the arrow is incident on j, the second node
 * Similarly, G(j,i)=1, since the circle is incident on node i, which is the second node for the edge between node
 * j and node i.
 */

/*
 * FUTURE DEVELOPMENT:
 * - don't check anything if all values are 0
 * 
 */

/*
 * For R1, we search for alpha *-> beta o-* gamma. 
 * If alpha and gamma are not adjacent, then orient the triple: alpha *-> beta -> gamma
 */

void LocalFCI::rule1search(int beta,int alpha,bool &track_changes,bool verbose){
  // Search for beta o-* gamma (beta (1) (!=0) gamma)
  for (int gamma=0;gamma<N;++gamma){
    if ((C_tilde->operator()(gamma,beta)==1) && (C_tilde->operator()(beta,gamma)!= 0)){ 
      if ((C_tilde->getAmatVal(alpha,gamma)==0) && (C_tilde->getAmatVal(gamma,alpha)==0)){
        if (C_tilde->getAmatVal(beta,gamma)==3){
          Rcout << "Contradiction in Rule 1! " << "G(" << beta << "," << gamma << ")=3 when it must be changed to 2\n";
        }
        C_tilde->operator()(beta,gamma)=2;
        C_tilde->operator()(gamma,beta)=3;
        //C_tilde->setAmatVal(beta,gamma,2); // arrowhead incident on gamma for edge connecting beta and gamma
        //C_tilde->setAmatVal(gamma,beta,3); // regular anchor incident on gamma for edge connecting beta and gamma
        if (verbose){
          Rcout << "Rule 1:\n";
          Rcout << "Orient: " << alpha << " *-> " << beta << " o-* " << gamma;
          Rcout << " as " << beta << " -> " << gamma << "\n";
        }
        track_changes=true;
      }
    }
  }
}

bool LocalFCI::rule1(bool &track_changes,bool verbose) {
  //int gamma;
  // Outer loops: Go through every node to find an asterisk. The node it is incident on is alpha
  // The connected node is beta, which must have an arrowhead pointing into it.
  for (int alpha = 0;alpha<N;++alpha){
    for (int beta = 0;beta<N;++beta){
      if (C_tilde->getAmatVal(alpha,beta)==2 && C_tilde->getAmatVal(beta,alpha)!=0){ // alpha *-> beta
        rule1search(beta,alpha,track_changes,verbose);
      }
    }
  }
  return track_changes;
}

/*
 * 
 * Rule 2: Search for alpha -> beta *-> gamma (alpha (3) (2) beta (*) (2) gamma)
 * OR Search for alpha *-> beta -> gamma (alpha (*) (2) beta (3) (2) gamma)
 * For either case, if alpha *-o gamma, then orient alpha *-o gamma as alpha *-> gamma
 * 
 */

void LocalFCI::rule2search(int beta,int alpha,bool condition1,bool condition2,bool &track_changes,bool verbose){
  
  // Condition 1 refers to alpha -> beta *-> gamma
  if (condition1){
    for (int gamma=0;gamma<N;++gamma){
      if (C_tilde->getAmatVal(gamma,beta)!=0 && C_tilde->getAmatVal(beta,gamma)==2){ // beta *-> gamma
        if (C_tilde->getAmatVal(alpha,gamma)==1 && C_tilde->getAmatVal(gamma,alpha)!=0){ // alpha *-o gamma
          C_tilde->setAmatVal(alpha,gamma,2); // alpha *-> gamma
          track_changes = true;
          if (verbose){
            Rcout << "Rule 2:\n";
            Rcout << "Orient: " << alpha << " -> " << beta << " *-> " << gamma;
            Rcout << " as: " << alpha << " *-> " << gamma << std::endl;
          }
        }
      }
    }
  } else if (condition2){ // Condition 2 refers to alpha *-> beta -> gamma
    for (int gamma=0;gamma<N;++gamma){
      if ((C_tilde->getAmatVal(gamma,beta)==3) && (C_tilde->getAmatVal(beta,gamma)==2)){ // beta -> gamma
        if ((C_tilde->getAmatVal(alpha,gamma)==1) && (C_tilde->getAmatVal(gamma,alpha)!=0)){ // alpha *-o gamma
          C_tilde->setAmatVal(alpha,gamma,2); // alpha *-> gamma
          if (verbose){
            Rcout << "Rule 2:\n";
            Rcout << "Orient: " << alpha << " *-> " << beta << " -> " << gamma;
            Rcout << " as: " << alpha << " *-> " << gamma << std::endl;
          }
          track_changes = true;
        }
      }
    }
  } else {
    Rcout << "Both essential conditions for Rule 2 failed. This function was called incorrectly.\n";
  }
  
  
}

bool LocalFCI::rule2(bool &track_changes,bool verbose) {
  //int gamma;
  bool condition1;
  bool condition2;
  // Searching for alpha -> beta OR alpha *-> beta
  for (int alpha = 0;alpha<N;++alpha){
    for (int beta = 0;beta<N;++beta){
      condition1 = (C_tilde->getAmatVal(alpha,beta)==2) && (C_tilde->getAmatVal(beta,alpha)==3); // alpha -> beta
      condition2 = (C_tilde->getAmatVal(alpha,beta)==2) && (C_tilde->getAmatVal(beta,alpha)!=0); // alpha *-> beta
      if (condition1 | condition2){
        rule2search(beta,alpha,condition1,condition2,track_changes,verbose);
      }
    }
  }
  return track_changes;
}

/*
 * 
 * Rule 3: Search for alpha *-> beta <-* gamma (alpha (*) (2) beta (2) (*) gamma)
 * AND alpha *-o theta o-* gamma (alpha (*) (1) theta (1) (*) gamma)
 * If alpha and gamma are not adjacent and theta *-o beta, then orient theta *-o beta as theta *-> beta
 * 
 */

List LocalFCI::rule3asearch(int beta,int alpha){
  NumericVector gammafinal; // There may be multiple values of gamma for which this holds. This assures we get them all.
  bool success = false;
  for (int gamma=0;gamma<N;++gamma){
    // Search for beta <-* gamma
    if (C_tilde->getAmatVal(gamma,beta)==2 && C_tilde->getAmatVal(beta,gamma)!=0 && gamma!= alpha){
      gammafinal.push_back(gamma);
      if (!success){
        success = true;
      }
    }
  }
  
  return List::create(
    _["gamma"] = gammafinal,
    _["rule3success"] = success
  );
}

void LocalFCI::rule3bsearch(const int &alpha,const int &beta,const int &gamma,bool &track_changes,bool verbose){
  bool condition1;
  bool condition2;
  // We are searching for alpha (*) (1) theta (1) (*) gamma
  for (int theta = 0;theta<N;++theta){
    condition1 = (C_tilde->getAmatVal(alpha,theta)==1) && (C_tilde->getAmatVal(theta,alpha)!=0); // alpha *-o theta
    condition2 = (C_tilde->getAmatVal(theta,gamma)!=0) && (C_tilde->getAmatVal(gamma,theta)==1); // theta o-* gamma
    if (condition1 && condition2){
      if ((C_tilde->getAmatVal(alpha,gamma)==0) && (C_tilde->getAmatVal(gamma,alpha)==0)){ // alpha and gamma are not adjacent
        if ((C_tilde->getAmatVal(theta,beta)==1) && (C_tilde->getAmatVal(beta,theta)!=0)){ // theta *-o beta
          C_tilde->setAmatVal(theta,beta,2); // theta *-> beta
          if (verbose){
            Rcout << "Rule 3:\n";
            Rcout << "Orient: " << theta << " *-> " << beta << std::endl;
          }
          track_changes = true;
        }
      }
    }
  }
}


bool LocalFCI::rule3(bool &track_changes,bool verbose) {
  int gamma;
  List searchResults;
  NumericVector gammaVals;
  //bool condition1;
  //bool condition2;
  // (alpha (*) (2) beta (2) (*) gamma)
  for (int alpha = 0;alpha<N;++alpha){
    for (int beta = 0;beta<N;++beta){
      if ((C_tilde->getAmatVal(alpha,beta)==2) && (C_tilde->getAmatVal(beta,alpha)!=0)){ // alpha *-> beta <-* gamma
        searchResults = rule3asearch(beta,alpha); // Search for gamma
        if (searchResults["rule3success"]){
          // Iterate over all values of gamma to find values of theta
          gammaVals = searchResults["gamma"];
          for (NumericVector::iterator it = gammaVals.begin();it != gammaVals.end();++it){
            gamma = *it;
            rule3bsearch(alpha,beta,gamma,track_changes,verbose);
          }
        }
      }
    }
  }
  return track_changes;
}


/*
 * Rule 4: If we have a discriminating path between theta and gamma for beta,
 * <theta,...,alpha,beta,gamma>
 * and beta o-* gamma; then if beta is in the separating set for theta and gamma
 * then we orient beta -> gamma; otherwise orient (alpha,beta,gamma) as 
 * alpha <-> beta <-> gamma
 * 
 */

bool LocalFCI::check_sep_r4(int beta,NumericVector md_path,bool verbose){
  if (verbose) Rcout << "Checking separation";
  int n = md_path.length();
  int theta = md_path(0);
  int gamma = md_path(n-1);
  
  if (verbose) Rcout << " of " << theta << " and " << gamma << " by " << neighborhood(beta);
  bool cond1 = S->isSeparated(theta,gamma,neighborhood(beta));
  if (verbose) Rcout << "...finished\n";
  return (cond1);
}

bool LocalFCI::rule4(bool &track_changes,bool verbose){
  bool cond1;
  bool cond2;
  bool done;
  NumericVector md_path;
  for (int beta=0;beta<N;++beta){
    for (int gamma=0;gamma<N;++gamma){
      if (C_tilde->getAmatVal(beta,gamma)!=0 && C_tilde->getAmatVal(gamma,beta)==1){
        //Rcout << "Potential beta: " << beta << " | Potential gamma: " << gamma;
        for (int alpha=0;alpha<N;++alpha){
          cond1 = C_tilde->getAmatVal(beta,alpha)==2 && C_tilde->getAmatVal(alpha,beta)!=0;
          cond2 = C_tilde->getAmatVal(gamma,alpha)==3 && C_tilde->getAmatVal(alpha,gamma)==2; // triangle structure exists but is not oriented
          if (cond1 && cond2){
            //Rcout << " | Potential alpha: " << alpha;
            done = false;
            while(C_tilde->getAmatVal(gamma,beta)==1){
              while(!done && C_tilde->getAmatVal(alpha,beta)!=0 && C_tilde->getAmatVal(alpha,gamma)!=0 && C_tilde->getAmatVal(beta,gamma)!=0){
                //Rcout << "# of Nodes: " << G.ncol() << std::endl;
                md_path = minDiscPath(alpha,beta,gamma,verbose);
                if (NumericVector::is_na(md_path(0))){
                  done = true; // We are done with this triangle  
                } else {
                  if(check_sep_r4(beta,md_path,verbose)){
                    if (verbose){
                      Rcout << "\nRule 4\nThere is a discriminating path between ";
                      Rcout << md_path(0) << " and " << gamma << " for " << beta;
                      Rcout << " and " << beta << " is in the SepSet of " << gamma;
                      Rcout << " and " << md_path(0) << ". Orient: ";
                      Rcout << beta << " -> " << gamma << std::endl;
                    }
                    C_tilde->setAmatVal(beta,gamma,2);
                    C_tilde->setAmatVal(gamma,beta,3);
                  } else {
                    // b is not in sepset
                    if (verbose){
                      Rcout << "\nRule 4\nThere is a discriminating path between ";
                      Rcout << md_path(0) << " and " << gamma << " for " << beta;
                      Rcout << " and " << beta << " is NOT in the SepSet of ";
                      Rcout << gamma << " and " << md_path(0) << ". Orient: ";
                      Rcout << alpha << " <-> " << beta << " <-> " << gamma << std::endl;
                    }
                    C_tilde->setAmatVal(beta,gamma,2);
                    C_tilde->setAmatVal(gamma,beta,2);
                    if (C_tilde->getAmatVal(alpha,beta)==3){
                      Rcout << "\nContradiction in Rule 4b\n";  
                    }
                    C_tilde->setAmatVal(alpha,beta,2);
                  }
                  done = true;
                  track_changes = true;
                }
              }
            } 
          }  
        }
      }
    }  
  }
  return track_changes;
}


bool LocalFCI::rule8(bool &track_changes,bool verbose){
  bool cond1;
  bool cond2;
  bool cond3;
  for (int alpha=0;alpha<N;++alpha){
    for (int gamma=0;gamma<N;++gamma){
      if (C_tilde->getAmatVal(alpha,gamma)==2 && C_tilde->getAmatVal(gamma,alpha)==1){ // alpha o-> gamma
        for (int beta=0;beta<N;++beta){
          cond1 = C_tilde->getAmatVal(beta,alpha)==3 && C_tilde->getAmatVal(alpha,beta)==2; // alpha -> beta
          cond2 = C_tilde->getAmatVal(beta,alpha)==3 && C_tilde->getAmatVal(alpha,beta)==1; // alpha -o beta
          if (cond1 || cond2){
            cond3 = C_tilde->getAmatVal(beta,gamma)==2 && C_tilde->getAmatVal(gamma,beta)==3; // beta -> gamma
            if (cond3){
              C_tilde->setAmatVal(gamma,alpha,3); // alpha -> gamma
              if (cond1){
                if (verbose){
                  Rcout << "\nRule 8\nOrient: " << alpha << " -> " << beta << " -> " << gamma;
                  Rcout << " with " << alpha << " o-> " << gamma << " as ";
                  Rcout << alpha << " -> " << gamma << std::endl;
                }
              } else {
                if (verbose){
                  Rcout << "\nRule 8\nOrient: " << alpha << " o-> " << beta << " -> " << gamma;
                  Rcout << " with " << alpha << " o-> " << gamma << " as ";
                  Rcout << alpha << " -> " << gamma << std::endl;  
                }
              }
              track_changes = true;
            }
          }
        }
      }  
    }  
  }
  return track_changes;
}


bool LocalFCI::rule9(bool &track_changes,bool verbose){
  bool cond1;
  bool cond2;
  bool cond3;
  bool cond4;
  bool cond_final;
  std::vector<int> beta_vals;
  int beta_current;
  NumericVector upd;

  for (int alpha=0;alpha<N;++alpha){
    for (int gamma=0;gamma<N;++gamma){
      if (C_tilde->getAmatVal(alpha,gamma)==2 && C_tilde->getAmatVal(gamma,alpha)==1){ // alpha o-> gamma
        //Rcout << "Potential alpha: " << alpha << " | Potential gamma: " << gamma << std::endl;
        beta_vals.clear();
        // Find all beta such that alpha (o-)-(o>) beta, and beta and gamma are not connected
        for (int beta=0;beta<N;++beta){
          cond1 = C_tilde->getAmatVal(alpha,beta) == 2 || C_tilde->getAmatVal(alpha,beta) == 1;
          cond2 = C_tilde->getAmatVal(beta,alpha) == 1 || C_tilde->getAmatVal(beta,alpha) == 3;
          cond3 = C_tilde->getAmatVal(gamma,beta) == 0 && C_tilde->getAmatVal(beta,gamma) == 0;
          cond4 = beta != gamma;
          cond_final = cond1 && cond2 && cond3 && cond4;
          if (cond_final){
            //Rcout << "Potential beta: " << beta << std::endl;
            beta_vals.push_back(beta);
          }
        }
        while (beta_vals.size() > 0 && C_tilde->getAmatVal(gamma,alpha)==1){
          beta_current = beta_vals[beta_vals.size()-1];
          beta_vals.pop_back();
          upd = minUncovPdPath(p,alpha,beta_current,gamma,verbose);
          //Rcout << "Length of upd: " << upd.length() << std::endl;
          if (upd.length()>1){
            C_tilde->setAmatVal(gamma,alpha,3);
            if (verbose){
              Rcout << "Rule 9: There exists an uncovered potentially directed ";
              Rcout << "path between " << alpha << " and " << gamma << std::endl;
              Rcout << "Orient: " << alpha << " -> " << gamma << std::endl;
            }
            track_changes = true;
          }
        }
      }  
    }
  }
  return track_changes;
}


bool LocalFCI::rule10(bool &track_changes,bool verbose){
  bool cond1;
  bool cond2;
  bool cond3;
  bool cond4;
  bool cond5;
  
  NumericVector beta_vals;
  int counter_b=0;
  int beta;
  
  int counter_d=0;
  NumericVector rem;
  NumericVector d_vals;
  int d;
  
  NumericVector x_vals;
  NumericVector x2_vals;
  int counter_x1;
  int first_pos;
  
  int counter_x2;
  int second_pos;
  
  NumericVector t1;
  NumericVector t2;
  
  
  
  for (int alpha=0;alpha<N;++alpha){
    for (int gamma=0;gamma<N;++gamma){ // search for alpha o-> gamma
      cond1 = C_tilde->getAmatVal(alpha,gamma)==2 && C_tilde->getAmatVal(gamma,alpha)==1;
      if (cond1){
        //Rcout << "Potential alpha: " << alpha << " | Potential gamma: " << gamma << std::endl;
        for (int b=0;b<N;++b){ // search for beta -> gamma
          cond1 = C_tilde->getAmatVal(gamma,b)==3 && C_tilde->getAmatVal(b,gamma)==2;
          if (cond1){
            //Rcout << "Potential beta: " << b << std::endl;
            beta_vals.push_back(b);  
          }
        }
        if (beta_vals.length()>=2){
          counter_b=0;
          while (counter_b<beta_vals.length() && C_tilde->getAmatVal(gamma,alpha)==1){
            beta = beta_vals(counter_b);
            ++counter_b;
            counter_d=0;
            rem = NumericVector::create(beta);
            //Rcout << "Current beta: " << beta << std::endl;
            d_vals = setdiff(beta_vals,rem);
            //print_vector_elements_nonames(d_vals,"d_vals: ","\n");
            counter_d = 0;
            while ((counter_d < d_vals.length()) && (C_tilde->getAmatVal(gamma,alpha)==1)){
              d = d_vals(counter_d);
              //Rcout << "Current theta: " << d << std::endl;
              ++counter_d;
              // The following is the easiest
              cond1 = C_tilde->getAmatVal(alpha,beta)==1 || C_tilde->getAmatVal(alpha,beta)==2;
              cond2 = C_tilde->getAmatVal(beta,alpha)==1 || C_tilde->getAmatVal(beta,alpha)==3;
              cond3 = C_tilde->getAmatVal(alpha,d)==1 || C_tilde->getAmatVal(alpha,d)==2;
              cond4 = C_tilde->getAmatVal(d,alpha)==1 || C_tilde->getAmatVal(d,alpha)==3;
              cond5 = C_tilde->getAmatVal(d,beta)==0 && C_tilde->getAmatVal(beta,d)==0;
              if (cond1&cond2&cond3&cond4&cond5){
                C_tilde->setAmatVal(gamma,alpha,3);
                if (verbose) Rcout << "\nRule 10 [easy]:\nOrient: " << alpha << " -> " << gamma << std::endl;
                track_changes = true;
              } else { // search for two minimal uncovered p.d. paths
                // Find all x s.t. a (-o)-(o>) x  
                x_vals = NumericVector(0); // Creates an empty vector
                for (int x=0;x<N;++x){
                  cond1 = C_tilde->getAmatVal(alpha,x)==1 || C_tilde->getAmatVal(alpha,x)==2;
                  cond2 = C_tilde->getAmatVal(x,alpha)==1 || C_tilde->getAmatVal(x,alpha)==3;
                  cond3 = x != gamma;
                  if (cond1 && cond2 && cond3){
                    x_vals.push_back(x);
                  }
                }
                if (x_vals.length()>=2){
                  counter_x1 = 0;
                  while ((counter_x1 < x_vals.length()) && C_tilde->getAmatVal(gamma,alpha)==1){
                    first_pos = x_vals(counter_x1);
                    //Rcout << "Potential first node on uncovered p.d. path p1: " << first_pos << std::endl;
                    ++counter_x1;
                    rem = NumericVector::create(first_pos);
                    x2_vals = setdiff(x_vals,rem);
                    counter_x2 = 0;
                    while (counter_x2 < x2_vals.length() && C_tilde->getAmatVal(gamma,alpha)==1){
                      second_pos = x2_vals(counter_x2);
                      //Rcout << "Potential first node on uncovered p.d. path p2: " << second_pos << std::endl;
                      ++counter_x2;
                      t1 = minUncovPdPath(p,alpha,first_pos,beta,verbose);
                      if (verbose) print_vector_elements_nonames(t1,"t1: ","\n");
                      if (t1.length()>1){
                        t2 = minUncovPdPath(p,alpha,second_pos,d,verbose);
                        if (t2.length()>1 && first_pos!=second_pos && C_tilde->getAmatVal(first_pos,second_pos)==0){
                          C_tilde->setAmatVal(gamma,alpha,3);
                          if (verbose) Rcout << "\nRule 10\nOrient: " << alpha << " -> " << gamma << std::endl;
                          track_changes = true;
                        } 
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }  
  }
  return track_changes;
}

void LocalFCI::allRules(bool verbose){
  bool track_changes = true;
  while (track_changes){
    track_changes = false;
    track_changes = rule1(track_changes,verbose);
    track_changes = rule2(track_changes,verbose);
    track_changes = rule3(track_changes,verbose);
    track_changes = rule4(track_changes,verbose);
    track_changes = rule8(track_changes,verbose);
    track_changes = rule9(track_changes,verbose);
    track_changes = rule10(track_changes,verbose);
  }
}

/*
 * Because of the special circumstances of our algorithm,
 * we are able to reassign certain edges because of our knowledge of targets
 * <-> => - ([2,2] to [1,1]) DONE
 * o-> => -> (decrement both i and j by 1) DONE
 * -> => -> (no change, but adj. matrix has to account differently, [3,2] to [0,1]) DONE 
 * o-o => - (no change in adj. matrix) DONE
 * -o => -> ([3,1] to [0,1]) DONE
 */

void LocalFCI::convertMixedGraph(){
  int G_ij;
  int G_ji;
  for (int i=0;i<N;++i){
    for (int j=0;j<N;++j){
      G_ij = C_tilde -> getAmatVal(i,j);
      G_ji = C_tilde -> getAmatVal(j,i);
      if (C_tilde->getAmatVal(i,j)==2 && C_tilde->getAmatVal(j,i)==2){
        // Convert bidirected edge to undirected
        C_tilde->setAmatVal(i,j,1);
        C_tilde->setAmatVal(j,i,1);
      } else if ((C_tilde->getAmatVal(i,j)==1 && C_tilde->getAmatVal(j,i)==2) || (C_tilde->getAmatVal(i,j)==2 && C_tilde->getAmatVal(j,i)==1)){
        // Convert o-> to ->
        C_tilde->setAmatVal(i,j,G_ij-1);
        C_tilde->setAmatVal(j,i,G_ji-1);
      } else if (C_tilde->getAmatVal(i,j)==2 && C_tilde->getAmatVal(j,i)==3){
        // Convert -> [3,2] to -> [0,1]
        C_tilde->setAmatVal(i,j,G_ij-1);
        C_tilde->setAmatVal(j,i,0);
      } else if (C_tilde->getAmatVal(j,i)==2 && C_tilde->getAmatVal(i,j)==3){
        // Convert <- [2,3] to <- [1,0]  
        C_tilde->setAmatVal(j,i,1);
        C_tilde->setAmatVal(i,j,0);
      } else if (C_tilde->getAmatVal(i,j)==3 && C_tilde->getAmatVal(j,i)==1){
        // Convert -o [3,1] to -> [0,1]
        C_tilde->setAmatVal(i,j,0);
      } else if (C_tilde->getAmatVal(i,j)==1 && C_tilde->getAmatVal(j,i)==3){
        // Convert o- [1,3] to <- [1,0]
        C_tilde->setAmatVal(j,i,0);  
      }
    }
  }
}

void LocalFCI::convertFinalGraph(Graph* g){
  int current_val = 0;
  int nrow = C_tilde ->getNRow();
  int ncol = C_tilde -> getNCol();
  for (int i=0;i<nrow;++i){
    for (int j=0;j<ncol;++j){
      //Rcout << "(" << neighborhood(i) << "," << neighborhood(j) << "): ";
      current_val = C_tilde -> getAmatVal(i,j);
      //Rcout << current_val << std::endl;
      g -> setAmatVal(neighborhood(i),neighborhood(j),current_val);  
    }
  }

  delete C_tilde;
  C_tilde = g;
  g = nullptr;
}


/*
 * Minimum Discriminating Path
 * Purpose: find a minimal discriminating path for a,b,c.
 */

// Obtain values "d" that haven't been visited and d*->a
NumericVector get_d_vals(Graph *pag,int &a,LogicalVector &visited,bool verbose=false){
  int p = pag->size();
  NumericVector d_vals;
  for (int i=0;i<p;++i){
    // We need d *-> a
    if (pag->getAmatVal(a,i)!=0 && pag->getAmatVal(i,a)==2 && !visited(i)){
      d_vals.push_back(i);
    }
  }
  if (verbose) print_vector_elements_nonames(d_vals,"\nPotential values: ","\n");
  return d_vals;
}

NumericVector get_r_vals(Graph *pag,int d,LogicalVector &visited,bool verbose=false){
  int p = pag->size();
  NumericVector r_vals;
  for (int i=0;i<p;++i){
    // We need r *-> d
    if (pag->getAmatVal(d,i)!=0 && pag->getAmatVal(i,d)==2 && !visited(i)){
      r_vals.push_back(i);  
    }
  }
  if (verbose) print_vector_elements_nonames(r_vals,"Potential values for the path: ","\n");
  return r_vals;
}

List createPathList(int a,NumericVector set,bool verbose=false){
  if (verbose) Rcout << "Creating path list\n";
  int num_paths = set.length();
  NumericVector path = {0};
  path[0] = a;
  
  List paths_to_try(num_paths);
  
  NumericVector new_path;
  
  for (int i = 0;i<num_paths;++i){
    new_path = clone(path);
    new_path.push_back(set(i));
    paths_to_try[i] = new_path;
    if (verbose) print_vector_elements_nonames(paths_to_try[i],"New Path: ","\n");
  }
  
  return paths_to_try;
}

List updatePathList(NumericVector mpath,NumericVector &set,List &old_paths,bool verbose=false){
  int old_size = old_paths.length();
  if (verbose) Rcout << "Size of old path list: " << old_size << std::endl;
  int num_paths = set.length();
  //mpath.erase(0); // we don't need to go over this point again
  List new_paths(old_size+num_paths);
  if (verbose) Rcout << "Size of new path list: " << new_paths.length() << std::endl;
  
  NumericVector new_path;
  String starter1 = String("Path ");
  String starter2;
  for (int i=0;i<old_size+num_paths;++i){
    if (i < old_size){
      new_paths[i] = old_paths[i]; 
    } else {
      new_path = clone(mpath);
      new_path.push_back(set(i-old_size));
      new_paths[i] = new_path;
    }
    starter2 = starter1;
    starter2 += std::to_string(i);
    starter2 += ": ";
    if (verbose) print_vector_elements_nonames(new_paths[i],starter2,"\n");
  }
  return new_paths;
}


NumericVector LocalFCI::minDiscPath(int a,int b,int c,bool verbose=false){
  LogicalVector visited(p);
  visited(a) = true;
  visited(b) = true;
  visited(c) = true;
  
  NumericVector d_vals = get_d_vals(C_tilde,a,visited,verbose); // Obtain values that are colliders on a path from the nodes to c
  if (d_vals.length()>0){
    List path_list = createPathList(a,d_vals,verbose);
    int counter = 0; // ensures that we go through each vector in the list
    int list_length = path_list.length();
    NumericVector mpath; // tracks the potential minimum discriminating path
    int m; // tracks the current length of the minimum discriminating path
    int d; // gives the last value in the path
    int pred;
    while (counter < list_length){
      mpath = path_list[counter];
      if (verbose) print_vector_elements_nonames(mpath,"mpath: ","\n");
      m = mpath.length();
      d = mpath(m-1);
      if (C_tilde->getAmatVal(c,d)==0 && C_tilde->getAmatVal(d,c)==0){
        NumericVector minDiscPath;
        for (int i=m-1;i>=0;--i){
          minDiscPath.push_back(mpath(i));
        }
        minDiscPath.push_back(b);
        minDiscPath.push_back(c);
        if (verbose) print_vector_elements_nonames(minDiscPath,"Minimum Discriminating Path: ","\n");
        return minDiscPath;
      } // End If
      pred = mpath(m-2);
      ++counter;
      
      // d is connected to c, so we search iteratively
      if (C_tilde->getAmatVal(d,c)==2 && C_tilde->getAmatVal(c,d)==3 && C_tilde->getAmatVal(pred,d)==2){
        visited(d) = true;
        // Find all neighbors of d not visited yet
        NumericVector r_vals = get_r_vals(C_tilde,d,visited);
        if (r_vals.length()>0){
          path_list = updatePathList(mpath,r_vals,path_list,verbose);
        }
      }
      list_length = path_list.length();
    }
  }
  return NA_REAL;
}


NumericVector LocalFCI::minUncovPdPath(int p, int alpha,int beta,int gamma,bool verbose){
  NumericVector path;
  NumericVector mpath;
  NumericVector final_path(0);
  NumericVector theta_vals(0);
  List path_list;
  int counter;
  int m;
  int d;
  int n;
  bool uncov;
  bool done = false;
  NumericVector r_vals(0);
  
  
  bool cond1 = C_tilde->getAmatVal(beta,gamma)==1 || C_tilde->getAmatVal(beta,gamma)==2;
  bool cond2 = C_tilde->getAmatVal(gamma,beta)==1 || C_tilde->getAmatVal(gamma,beta)==3;
  bool cond3 = C_tilde->getAmatVal(gamma,alpha)==0 && C_tilde->getAmatVal(alpha,gamma)==0;
  std::vector<bool> visited;
  if (cond1 && cond2 && cond3){
    final_path = NumericVector::create(alpha,beta,gamma);
    done = true;
    // TODO: Add print statement here
  }
  
  // Check for paths of 4 or more (what we are interested in for rule 9)
  if (verbose) Rcout << "Checking for paths of 4 or more\n";
  if (!done){
    visited.assign(p,false);
    visited[alpha]=true;
    visited[beta]=true;
    visited[gamma]=true;
    for (int theta=0;theta<p;++theta){
      cond1 = C_tilde->getAmatVal(beta,theta)==1 || C_tilde->getAmatVal(beta,theta)==2;
      cond2 = C_tilde->getAmatVal(theta,beta)==1 || C_tilde->getAmatVal(theta,beta)==3;
      cond3 = C_tilde->getAmatVal(theta,alpha) == 0 && C_tilde->getAmatVal(alpha,theta)== 0 && !visited[theta];
      if (cond1 && cond2 && cond3){
        if (verbose) Rcout << "Potential theta: " << theta << std::endl;
        theta_vals.push_back(theta);
      }
    }
    if (theta_vals.length()>0){
      path_list = createPathList(beta,theta_vals,verbose);
      counter = 0;
      while ((counter<path_list.length()) && (!done)){
        mpath = path_list[counter];
        if (verbose) print_vector_elements_nonames(mpath,"mpath: ","\n");
        m = mpath.length();
        d = mpath(m-1);
        visited[d]=true;
        cond1 = C_tilde->getAmatVal(d,gamma)==1 || C_tilde->getAmatVal(d,gamma)==2;
        cond2 = C_tilde->getAmatVal(gamma,d)==1 || C_tilde->getAmatVal(gamma,d)==3;
        if (cond1 && cond2){
          if (verbose) Rcout << "Found a final node on the uncovered p.d. path: " << d << std::endl;
          path = NumericVector::create(alpha);
          for (int i=0;i<m;++i){
            path.push_back(mpath(i));  
          }
          path.push_back(gamma);
          if (verbose) print_vector_elements_nonames(path,"Path: ","\n");
          n = path.length();
          uncov=true;
          for (int i=0;i<n-2;++i){
            cond1 = (C_tilde->getAmatVal(path(i),path(i+2))==0) && (C_tilde->getAmatVal(path(i+2),path(i))==0);
            if (!cond1){
              uncov = false;
              break;
            }
          }
          // TODO: add a print statement here
          if (uncov){
            final_path = path;
            if (verbose) print_vector_elements_nonames(final_path,"Final Path: ","\n");
            done = true;
          }
        } else {
          // d and c are not connected or connected with a "wrong" edge
          // iteratively search for neighbors of d not yet visited
          // and add them to potential members of the path
          for (int i=0;i<p;++i){
            cond1 = C_tilde->getAmatVal(d,i) == 1 || C_tilde->getAmatVal(d,i)==2;
            cond2 = C_tilde->getAmatVal(i,d) == 1 || C_tilde->getAmatVal(i,d)==3;
            cond3 = !visited[i];
            if (cond1 && cond2 && cond3){
              if (verbose) Rcout << "Potential New Value in Path: " << i << std::endl;
              r_vals.push_back(i);  
            }
          }
          if (r_vals.length()>0){
            path_list = updatePathList(mpath,r_vals,path_list,verbose);
          }
        }
        ++counter;
        r_vals = NumericVector(0);
        if (verbose) Rcout << "Counter: " << counter << " | Number of paths: " << path_list.length() << std::endl;
      } // End while
    }
  }
  if (final_path.length()==0){
    return NumericVector(0);  
  } else {
    return final_path;  
  }
}



