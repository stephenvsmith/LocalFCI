#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
#include "sharedFunctions.h"
#include "skeletonHelpersEfficient.h"
#include "vStructHelpers.h"
#include "Rules.h"
using namespace Rcpp;

// [[Rcpp::export]]
List get_skeleton_total(List var_list,arma::mat df,double signif_level){
  int l = -1;
  int lmax = var_list["lmax"];
  int p = var_list["p"];
  bool verbose = var_list["verbose"];
  NumericMatrix C = var_list["C_tilde"];
  NumericMatrix true_dag = var_list["true_dag"];
  NumericVector neighborhood = var_list["neighborhood"];
  int N = neighborhood.size();
  StringVector names = var_list["names"];
  List S = var_list["S"];
  
  arma::mat R = arma::cor(df);
  int n = df.n_rows;
  
  NumericVector neighbors;
  NumericVector edges_i;
  NumericVector sep;
  
  NumericMatrix kvals;
  double pval=0.0;
  
  int num_tests=0;
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
      edges_i = get_current_edges(i,N,C);
      for (NumericVector::iterator it = edges_i.begin(); it != edges_i.end(); ++it){
        int j = *it;
        if (j > i){
          
          if (verbose){
            Rcout << "The value of j is " << j;
            Rcout << " (" << names(neighborhood(j)) << ")"<< std::endl;
          }
          // Find neighbors of i and j from the current graph C
          neighbors = setdiff(union_(edges_i,get_current_edges(j,N,C)),NumericVector::create(i,j));
          
          // If there are enough potential neighbors to match the current separating set size, we continue
          if (neighbors.length()>= l){
            if (verbose && l>0){
              if (neighbors.length() > 1){
                Rcout << "There are " << neighbors.length() << " neighbors.\n";
              } else {
                Rcout << "There is " << neighbors.length() << " neighbor.\n";
              }
            }
            kvals = combn_cpp(neighbors,l);
            
            check_separation_sample_efficient(l,i,j,kvals,sep,true_dag,names,neighborhood,C,S,pval,num_tests,R,n,signif_level,verbose);
            
            if (verbose){
              iteration_print(l,i,j,sep,names,pval);
            }
          }
        }
      }
      
    }
    
  }
  if (verbose){
    Rcout << "The final C matrix:\n";
    print_matrix(C);
    Rcout << "Conclusion of algorithm.\n";
  }
  
  return List::create(
    _["C"]=C,
    _["S"]=S,
    _["neighborhood"]=neighborhood,
    _["p"]=p,
    _["NumTests"]=num_tests,
    _["verbose"]=verbose,
    _["lmax"]=lmax,
    _["true_dag"]=true_dag,
    _["names"]=names,
    _["R"]=R
  );
}

// [[Rcpp::export]]
List get_skeleton_target(List var_list,int target,arma::mat df,double signif_level=0.05){
  int l = -1;
  int lmax = var_list["lmax"];
  int p = var_list["p"];
  bool verbose = var_list["verbose"];
  NumericMatrix C = var_list["C"];
  NumericMatrix true_dag = var_list["true_dag"];
  NumericVector neighborhood = var_list["neighborhood"];
  int N = neighborhood.size();
  StringVector names = var_list["names"];
  List S = var_list["S"];
  
  int i;
  int j;
  
  arma::mat R = var_list["R"];
  int n = df.n_rows;
  
  NumericVector neighbors;
  NumericVector edges_i;
  NumericVector sep;
  
  NumericMatrix kvals;
  double pval=0.0;
  
  int num_tests=var_list["NumTests"];
  
  // Make a map to relate efficient numbering with true numbering
  // Map: true numbering -> efficient numbering
  std::map<int,int> node_numbering;
  for (int i=0;i<N;++i){
    node_numbering.insert(std::pair<int,int>(neighborhood(i),i));
  }
  
  // Making an adjustment to target based on efficient numbering
  int target_efficient = node_numbering.find(target)->second;
  // Find neighborhood just surrounding the target node
  NumericVector target_neighborhood = get_current_edges(target_efficient,N,C);
  target_neighborhood.push_back(target_efficient);
  
  if (verbose){
    Rcout << "\n\nFinding skeleton for the neighborhood of target " << target;
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
      edges_i = intersect(get_current_edges(i,N,C),target_neighborhood);
      for (NumericVector::iterator it2 = edges_i.begin(); it2 != edges_i.end(); ++it2){
        j = *it2;
        if (j > i){
          
          if (verbose){
            Rcout << "The value of j is " << j << std::endl;
          }
          
          if (l>0){
            // Find neighbors of i and j from the true DAG (or they are estimated)
            // These neighbors are using the true node numbers (check documentation for this function)
            neighbors = get_potential_sep(i,j,neighborhood,p,true_dag);
            if (verbose){
              print_vector_elements_nonames(neighbors,"Potential separating nodes: ","\n");  
            }
          } else {
            neighbors = NA_REAL;  
          }
          
          // If there are enough potential neighbors to match the current separating set size, we continue
          if (neighbors.length()>= l){
            if (verbose && l>0){
              Rcout << "There are " << neighbors.length() << " neighbor(s).\n";
            }
            kvals = combn_cpp(neighbors,l);
            
            check_separation_sample_efficient_target(l,i,j,kvals,sep,true_dag,names,neighborhood,C,S,pval,num_tests,R,n,signif_level,verbose);
            
            if (verbose){
              iteration_print(l,i,j,sep,names,pval);
            }
          }
        }
      }
      
    }
    
  }
  if (verbose){
    Rcout << "The final C matrix:\n";
    print_matrix(C);
    Rcout << "Conclusion of algorithm.\n";
  }
  
  return List::create(
    _["C"]=C,
    _["S"]=S,
    _["R"]=R,
    _["neighborhood"]=neighborhood,
    _["p"]=p,
    _["names"]=names,
    _["lmax"]=lmax,
    _["true_dag"]=true_dag,
    _["NumTests"]=num_tests,
    _["verbose"]=verbose
  );
}

// [[Rcpp::export]]
List fci(NumericMatrix true_dag,arma::mat df,
                             NumericVector targets,
                             StringVector names,int lmax=3,
                             double signif_level = 0.05,
                             bool verbose=true){
  int num_targets = targets.length();
  int p = true_dag.ncol();
  int target;
  if (verbose){
    Rcout << "There are " << num_targets << " targets.\n";
    print_vector_elements(targets,names,"Targets: ","\n");
  }
  
  List var_list = fci_setup(true_dag,targets,names,lmax,verbose); // Well tested
  
  List first_skeleton_list = get_skeleton_total(var_list,df,signif_level); // tested
  
  List final_skeleton_list;
  for (int i=0;i<num_targets;++i){
    target = targets(i); // target is with respect to large graph
    if (i==0){ // We need to initialize final_skeleton_list
      final_skeleton_list = get_skeleton_target(first_skeleton_list,target,df,signif_level);
    } else { //Now we are updating final_skeleton_list
      final_skeleton_list = get_skeleton_target(final_skeleton_list,target,df,signif_level);  
    }
  }
  
  List v_struct = get_v_structures_efficient(final_skeleton_list);
  NumericMatrix G = v_struct["C"];
  
  allRules(G,v_struct["S"],v_struct["neighborhood"],verbose);
  NumericMatrix Gfinal(p);
  NumericVector neighborhood = v_struct["neighborhood"];
  
  makeFinalGraph(Gfinal,G,neighborhood);
  
  return List::create(
    _["G"]=Gfinal,
    _["S"]=v_struct["S"],
    _["NumTests"]=v_struct["NumTests"],
    _["neighborhood"]=neighborhood
  );
}