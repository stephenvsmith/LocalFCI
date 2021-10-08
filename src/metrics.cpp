#include <Rcpp.h>
#include <algorithm>
using namespace Rcpp;

/*
 * This function only compares the difference in skeletal structure between two graphs
 */

// [[Rcpp::export]]
List compare_skeletons(NumericMatrix est,NumericMatrix truth,bool verbose){
  int fp=0;
  int fn=0;
  int correct=0;
  
  int p = est.nrow();
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      if ((est(i,j)!=0 || est(j,i)!=0) && (truth(i,j)==0 && truth(j,i)==0)){
        ++fp;  
      } else if ((est(i,j)==0 && est(j,i)==0) && (truth(i,j)!=0 || truth(j,i)!=0)){
        ++fn;
      } else if ((est(i,j)!=0 && est(j,i)!=0) && (truth(i,j)!=0 && truth(j,i)!=0)){
        ++correct;  // TODO: May need to correct this for bidirected edges
      }
    }  
  }
  return List::create(
    _["skel_fp"]=fp,
    _["skel_fn"]=fn,
    _["skel_correct"]=correct
  );
}

/*
 * These functions serve to find the differences in the v-structures in two mixed graphs
 */
List check_triple(NumericMatrix g,int i,int j,int k,bool verbose){
  // check if i *-> k <-* j, then k *-> j <-* i, and j *-> i <-* k with each set of parents nonadjacent
  if (verbose){
    Rcout << "i: " << i << " | j: " << j << " | k: " << k << " | Conclusion: ";
  }
  if (g(i,k)==2 && g(j,k)==2 && g(i,j)==0 && g(j,i)==0)
  {
    if (verbose){
      Rcout << "i *-> k <-* j"; 
    }
    return List::create(_["result"]=true,_["order"]=NumericVector::create(i,k,j));  
  }
  else if (g(k,j)==2 && g(i,j)==2 && g(i,k)==0 && g(k,i)==0)
  {
    if (verbose){
      Rcout << "k *-> j <-* i";
    }
    
    return List::create(_["result"]=true,_["order"]=NumericVector::create(k,j,i));
  }
  else if (g(j,i)==2 && g(k,i)==2 && g(j,k)==0 && g(k,j)==0)
  {
    if (verbose){
      Rcout << "j *-> i <-* k";
    }
    return List::create(_["result"]=true,_["order"]=NumericVector::create(j,i,k));
  }
  else 
  {
    if (verbose){
      Rcout << "No unshielded triple\n";
      Rcout << std::endl;
    }
    return List::create(_["result"]=false,_["order"]=NA_REAL);
  }
}

bool check_other_triple(NumericMatrix g2,NumericVector v,bool verbose){
  // check v(0) *-> v(1) <-* v(2) with v(0) and v(2) nonadjacent
  if (g2(v(0),v(1))==2 && g2(v(2),v(1))==2 && g2(v(0),v(2))==0 && g2(v(2),v(0))==0)
  {
    if (verbose){
      Rcout << " | v-structure correctly recovered\n";
    }
    return true;
  }
  else
  {
    if (verbose){
      Rcout << " | v-structure *not* present in true graph\n";
    }
    return false;
  }
}

// [[Rcpp::export]]
List compare_v_structures(NumericMatrix est,NumericMatrix truth,bool verbose){
  int num_missing=0;
  int num_added=0;
  int num_correct=0;
  
  int p = est.nrow();
  List triple_check;
  bool continue_checking=true;
  
  for (int i=0;i<p-2;++i){
    for (int j=i+1;j<p-1;++j){
        for (int k=j+1;k<p;++k){
          if (verbose){
            Rcout << "Estimated Graph:\n";
          }
          triple_check = check_triple(est,i,j,k,verbose);
          if (triple_check["result"]){
            continue_checking=false;
            if (check_other_triple(truth,triple_check["order"],verbose))
              ++num_correct;
            else
              ++num_added;
          }
          
          // Now, we check if we missed any v-structures
          if (continue_checking)
          {
            if (verbose) {
              Rcout << "True Graph:\n";
            }
            triple_check = check_triple(truth,i,j,k,verbose);
            if (triple_check["result"])
            {
              if (verbose){
                Rcout << " | v-structure *not* present in estimated graph\n";
              }
              ++num_missing;
            }
          } else
            continue_checking=true;
        }
    }  
  }
  
  return List::create(
    _["missing"]=num_missing,
    _["added"]=num_added,
    _["correct"]=num_correct
  );
}

/*
 * these functions serve to help us determine whether or not we accurately recover the parent sets of our target nodes
 */
void update_edge_values(NumericMatrix est,NumericMatrix truth,const int &i,const int &j,int &correct,int &missing,int &added,bool verbose){
  bool est_cond;
  bool truth_cond;
  
  est_cond = est(i,j)==2 && est(j,i)!=2;
  truth_cond = truth(i,j)==2 && truth(j,i)!=2;
  if (est_cond && truth_cond){
    if (verbose){
      Rcout << "Correct parent of " << j << ": " << i << std::endl;
    }
    ++correct;
  } else if (est_cond && !truth_cond){
    if (verbose){
      Rcout << "False positive parent of " << j << ": " << i << std::endl;
    }
    ++added;
  } else if (!est_cond && truth_cond){
    if (verbose){
      Rcout << "False negative parent of " << j << ": " << i << std::endl;
    }
    ++missing;
  }
}

/*
// [[Rcpp::export]]
List compare_directed_edges(NumericMatrix est,NumericMatrix truth){
  int num_correct=0;
  int num_missing=0;
  int num_added=0;
  
  int p = est.nrow();
  
  for (int i=0;i<p-1;++i){
    for (int j=i+1;j<p;++j){
      update_edge_values(est,truth,i,j,num_correct,num_missing,num_added);
      update_edge_values(est,truth,j,i,num_correct,num_missing,num_added);
    }  
  }
  
  return List::create(
    _["missing_par"]=num_missing,
    _["added_par"]=num_added,
    _["correct_par"]=num_correct
  );
}
*/
 
void pra_onetarget(NumericMatrix est,NumericMatrix truth,int t,int &correct,int &missing,int &added,int &potential,bool verbose){
  int p = est.nrow();
  for (int i=0;i<p;++i){
    if (i==t)
      continue;
    if (verbose){
      Rcout << "t: " << t << " | i: " << i;
    }
    if (est(i,t)==2 && est(t,i)!=2){
      if (verbose){
        Rcout << " | Est. Graph: Parent | True graph: ";
      }
      if (truth(i,t)!=2)
      {
        ++added;
        if (verbose){
          Rcout << "Not a parent | ";
          Rcout << "Added: " << added << std::endl;
        }
      }
      else {
        ++correct;
        if (verbose){
          Rcout << "Parent | ";
          Rcout << "Correct: " << correct << std::endl;
        }
      }
    } else {
      if (truth(i,t)==2 && truth(t,i)!=2){
        ++missing;
        if (verbose){
          Rcout << " | Est. Graph: Not a parent | True graph: Parent | ";
          Rcout << "Missing: " << missing;
        }
        if (est(i,t)==1 && est(t,i)==1){ // We have a potential parent here
          ++potential;
          if (verbose){
            Rcout << " | Open circle edge in Est. Graph | Potential: " << potential;
          }
        }
      } 
      if (verbose) Rcout << "\n";
    }
  }
}

// [[Rcpp::export]]
List parent_recovery_accuracy(NumericMatrix est,NumericMatrix truth,NumericVector targets,bool verbose){
  int num_correct=0;
  int num_added=0;
  int num_missing=0;
  int num_potential=0;
  
  int p = est.nrow();
  std::for_each(targets.begin(),targets.end(),[&](int t) {pra_onetarget(est,truth,t,num_correct,num_missing,num_added,num_potential,verbose);});
  
  return List::create(
    _["missing"]=num_missing,
    _["added"]=num_added,
    _["correct"]=num_correct,
    _["potential"]=num_potential
  );
}

/*
 * We need to work here to convert an adjacency matrix from the true DAG to the notation for a mixed graph for comparison
 * Every time there is a 1, it must be converted to a 2 and its counterpart on the other side of the diagonal must change from a 0 to a 3
 * All other 0's remain the same
 */
// [[Rcpp::export]]
NumericMatrix convert_true_dag(NumericMatrix G){
  
  NumericMatrix Gc = clone(G);
  int p = Gc.ncol();
  
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      if (Gc(i,j)==1){
        Gc(i,j)=2;
        Gc(j,i)=3;
      } else if (Gc(j,i)==1){
        Gc(j,i)=2;
        Gc(i,j)=3;
      }
    }
  }
  
  return Gc;
}

/*
 * Convert PC amat
 * All directed edges must change: if (i,j)==1 and (j,i)==0, those must be changed to 2 and 3 respectively
 * All undirected edges remain the same (1's)
 * All other unconnected edges also remain the same (0's)
 */

// [[Rcpp::export]]
NumericMatrix convert_pc_amat(NumericMatrix G){
  NumericMatrix Gc = clone(G);
  int p = Gc.ncol();
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      if (Gc(i,j)==1 && Gc(j,i)==0){
        Gc(i,j)=2;
        Gc(j,i)=3;
      } else if (Gc(j,i)==1 && Gc(i,j)==0){
        Gc(j,i)=2;
        Gc(i,j)=3;
      }
    }
  }
  return Gc;
}

int get_edge_number(NumericMatrix G){
  int p = G.nrow();
  int total_edges=0;
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      if (G(i,j)!=0 || G(j,i)!=0){
        ++total_edges;
      }
    }
  }
  return total_edges;
}

// [[Rcpp::export]]
DataFrame all_metrics(NumericMatrix est,NumericMatrix true_dag,NumericMatrix cpdag,NumericVector targets,bool verbose=false){
  // Convert true_dag and cpdag to mixed graph notation
  NumericMatrix true_dag_conv = convert_true_dag(true_dag);
  NumericMatrix cpdag_conv = convert_pc_amat(cpdag);
  
  // Get all cpdag results first
  List cpdag_skeleton = compare_skeletons(cpdag_conv,true_dag_conv,verbose);
  List cpdag_vstruct = compare_v_structures(cpdag_conv,true_dag_conv,verbose);
  List cpdag_pra = parent_recovery_accuracy(cpdag_conv,true_dag_conv,targets,verbose);
  
  // Get the estimated dag next
  List est_skeleton = compare_skeletons(est,true_dag_conv,verbose);
  List est_vstruct = compare_v_structures(est,true_dag_conv,verbose);
  List est_pra = parent_recovery_accuracy(est,true_dag_conv,targets,verbose);
  
  return DataFrame::create(
    _["pc_skel_fp"]=cpdag_skeleton["skel_fp"],
    _["pc_skel_fn"]=cpdag_skeleton["skel_fn"],
    _["pc_skel_correct"]=cpdag_skeleton["skel_correct"],
    _["fci_skel_fp"]=est_skeleton["skel_fp"],
    _["fci_skel_fn"]=est_skeleton["skel_fn"],
    _["fci_skel_correct"]=est_skeleton["skel_correct"],
    _["pc_v_missing"] = cpdag_vstruct["missing"],
    _["pc_v_added"] = cpdag_vstruct["added"],
    _["pc_v_correct"] = cpdag_vstruct["correct"],
    _["fci_v_missing"] = est_vstruct["missing"],
    _["fci_v_added"] = est_vstruct["added"],
    _["fci_v_correct"] = est_vstruct["correct"],
    _["pc_pra_missing"]=cpdag_pra["missing"],
    _["pc_pra_added"] = cpdag_pra["added"],
    _["pc_pra_correct"] = cpdag_pra["correct"],
    _["pc_pra_potential"] = cpdag_pra["potential"],
    _["fci_pra_missing"]=est_pra["missing"],
    _["fci_pra_added"] = est_pra["added"],
    _["fci_pra_correct"] = est_pra["correct"],
    _["fci_pra_potential"] = est_pra["potential"]
  );
}

// [[Rcpp::export]]
DataFrame neighborhood_metrics(NumericMatrix G){
  return DataFrame::create(
    _["size"]=G.ncol(),
    _["num_edges"]=get_edge_number(G)
  );
}








