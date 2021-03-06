#include "constrainedAlgo.h"

// Sample version
ConstrainedAlgo::ConstrainedAlgo(NumericMatrix true_dag,arma::mat df,
                                 NumericVector targets,
                                 StringVector names,int lmax,
                                 double signif_level,
                                 bool verbose) : targets(targets),verbose(verbose),
                                 lmax(lmax),df(df),signif_level(signif_level),names(names){
  num_targets = targets.length();
  if (verbose){
    Rcout << "There is (are) " << num_targets << " target(s).\n";
    print_vector_elements(targets,names,"Targets: ","\n");
  }
  p = true_dag.ncol();
  R = arma::cor(df);
  n = df.n_rows;
  num_tests=0;
  
  // Set DAG object (We use this object to obtain neighborhoods)
  true_DAG = new DAG(p,names,true_dag);
  
  // Find the neighborhood of the target nodes
  neighborhood = true_DAG -> getNeighborsMultiTargets(targets,verbose); //tested
  neighborhood = union_(neighborhood,targets); //tested
  std::sort(neighborhood.begin(),neighborhood.end()); //tested
  
  N = neighborhood.size();
  
  if (verbose){
    Rcout << "There are " << p << " nodes in the DAG.\n";
    Rcout << "There are " << N << " nodes in the neighborhoods we are considering.\n";
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
}

// Population version of the algorithm object
ConstrainedAlgo::ConstrainedAlgo(NumericMatrix true_dag,
                                 NumericVector targets,
                                 StringVector names,int lmax,
                                 bool verbose) : verbose(verbose),targets(targets),
                                 lmax(lmax),names(names) {
  num_targets = targets.length();
  if (verbose){
    Rcout << "Population Version\n";
    Rcout << "There are " << num_targets << " targets.\n";
    print_vector_elements(targets,names,"Targets: ","\n");
  }
  p = true_dag.ncol();
  pop = true;
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
}

void ConstrainedAlgo::print_elements(){
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
  if (n>0){
    Rcout << "First and last elements of the dataset: ";
    Rcout << df(0,0) << " " << df(df.n_rows-1,df.n_cols-1) << std::endl;
  }
}

// i and j are efficient values and must be transformed to true values
// kvals are true values and do not need to be transformed
void ConstrainedAlgo::checkSeparation(int l,int i,int j,NumericMatrix kvals){
  int k;
  int kp = kvals.cols();
  bool keep_checking_k;
  List test_result;
  
  // Initially assumes we are considering an empty set
  arma::uvec sep_arma;
  if (l == 0){
    sep = NA_REAL;
    if (pop){
      NumericMatrix g = true_DAG -> getAmat();
      test_result = condIndTestPop(g,neighborhood(i),neighborhood(j),sep_arma);
    } else {
      test_result = condIndTest(R,neighborhood(i),neighborhood(j),sep_arma,n,signif_level);
    }
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
      std::sort(sep.begin(),sep.end());
      sep_arma = as<arma::uvec>(sep);
      if (verbose){
        Rcout << "Efficient Setup: " << i << " -> " << neighborhood(i);
        Rcout << " | " << j << " -> " << neighborhood(j);
        Rcout << " | k (True Vals): ";
        print_vector_elements_nonames(sep,""," ("," ");
        print_vector_elements(sep,names,"",")\n");
      }
      if (pop){
        test_result = condIndTestPop(true_DAG->getAmat(),neighborhood(i),neighborhood(j),sep_arma);
      } else {
        test_result = condIndTest(R,neighborhood(i),neighborhood(j),sep_arma,n,signif_level);
      }
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

// We are trying to identify structures i -> k <- j
// Where i and j are not adjacent, and k is not in the separating set of i and j
void ConstrainedAlgo::getVStructures() {
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
        // or if i and j are from separate neighborhoods
        placeholder = C_tilde->getAmatRow(j);
        j_invalid = (all(placeholder==0)).is_true();
        j_invalid = j_invalid || (C_tilde->getAmatVal(j,i)!= 0) ||  j <= i;
        // j must be in the neighborhood of i for it to make a v-structure with it 
        j_invalid = j_invalid || !(true_DAG->inNeighborhood(neighborhood(i),neighborhood(j)));
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
              if (S->isPotentialVStruct(i,j,k)){ 
                if (verbose){
                  Rcout << "Separation Set: ";
                  print_vector_elements_nonames(sepset_ij);
                  Rcout << " | V-Structure (True Numbering): " << neighborhood(i) << "*->" << k << "<-*" << neighborhood(j) << std::endl; 
                }
                C_tilde->setAmatVal(i,k_eff,1);
                C_tilde->setAmatVal(j,k_eff,1);
                C_tilde->setAmatVal(k_eff,i,0);
                C_tilde->setAmatVal(k_eff,j,0);
              }
            }
          }
        }
      }
    }
  }
}

