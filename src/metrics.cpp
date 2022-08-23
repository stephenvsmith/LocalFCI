#include <algorithm>
#include "DAG.h"
#include "sharedFunctions.h"
#include <string>
using namespace Rcpp;

/*
 * This function only compares the difference in skeletal structure between two graphs
 */

void validateInputs(NumericMatrix est,NumericMatrix truth){
  if (est.ncol() != est.nrow() || truth.ncol() != truth.nrow()){
    stop("Inputted matrices are not both square matrices");
  }
  
  if (est.ncol() != truth.ncol()){
    stop("Inputted matrices do not have matching dimensions");
  }
}

void validateTargets(NumericMatrix g,NumericVector targets){
  if ( is_true(any(targets > g.ncol())) ){
    stop("Invalid target index: value(s) greater than size of graph");
  } else if ( is_true(any(targets < 0)) ){
    stop("Invalid target index: negative value(s)");
  }
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

/*
 * In order to be considered for the within-neighborhood metrics,
 * both nodes must be in the same target neighborhood for at least
 * one target. If not, even if they are in the same neighborhood as each other,
 * we will not consider them in a shared neighborhood
 */
// [[Rcpp::export]]
bool sharedNeighborhood(NumericMatrix reference,NumericVector targets,
                        int i,int j,bool verbose = false){
  int p = reference.nrow();
  StringVector node_names;
  for (int i=0;i<p;++i){
    String node("V");
    node += i;
    node_names.push_back(node);
  }
  
  DAG g_ref(p,node_names,reference);
  
  for (NumericVector::iterator it=targets.begin();it<targets.end();++it){
    // Check if i and j share a neighborhood with a particular target
    if (g_ref.inNeighborhood(*it,i) && g_ref.inNeighborhood(*it,j)){
      if (verbose){
        Rcout << i << " and " << j << " are in the neighborhood of target " << *it << std::endl;
      }
      return true;
    }
  }
  
  // Otherwise, return false
  if (verbose){
    Rcout << "Nodes " << i << " and " << j << " don't share the same target neighborhood\n";
  }
  return false;
}

// [[Rcpp::export]]
bool inTargetNeighborhood(NumericMatrix reference,NumericVector targets,
                          int i,bool verbose = false){
  validateTargets(reference,targets);
  int p = reference.nrow();
  StringVector node_names;
  for (int i=0;i<p;++i){
    String node("V");
    node += i;
    node_names.push_back(node);
  }
  
  DAG g_ref(p,node_names,reference);
  for (NumericVector::iterator it=targets.begin();it<targets.end();++it){
    // Check if i is in target neighborhood
    if (g_ref.inNeighborhood(*it,i)){
      if (verbose){
        Rcout << i << " is in the neighborhood of target node " << *it << std::endl;
      }
      return true;
    }
  }
  
  // Otherwise, return false
  return false;
}

// [[Rcpp::export]]
List compare_skeletons(NumericMatrix est,NumericMatrix truth,NumericVector targets){
  validateInputs(est,truth);
  int fp=0;
  int fn=0;
  int correct=0;
  
  int p = est.nrow();
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      // Only consider nodes that are in the same target neighborhood
      if (sharedNeighborhood(truth,targets,i,j)){
        if ((est(i,j)!=0 || est(j,i)!=0) && (truth(i,j)==0 && truth(j,i)==0)){
          ++fp;  // Est: i,j adjacent but truth not adjacent
        } else if ((est(i,j)==0 && est(j,i)==0) && (truth(i,j)!=0 || truth(j,i)!=0)){
          ++fn; // Est: i,j not adjacent but adjacent in truth
        } else if ((est(i,j)!=0 || est(j,i)!=0) && (truth(i,j)!=0 || truth(j,i)!=0)){
          ++correct; // i,j adjacent in both graphs
        }
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
List check_triple(NumericMatrix g,int i,int j,int k){
  // check if i *-> k <-* j, then k *-> j <-* i, and j *-> i <-* k with each set of parents nonadjacent
  //Rcout << "i: " << i << " | j: " << j << " | k: " << k << " | Conclusion: ";
  
  if (g(i,k)==1 && g(k,i)==0 && g(j,k)==1 && g(k,j)==0 && g(i,j)==0 && g(j,i)==0)
  {
    
    //Rcout << "i -> k <- j"; 
    
    return List::create(_["result"]=true,_["order"]=NumericVector::create(i,k,j));  
  }
  else if (g(k,j)==1 && g(j,k)==0 && g(i,j)==1 && g(j,i)==0 && g(i,k)==0 && g(k,i)==0)
  {
    
    //Rcout << "i -> j <- k";
    
    
    return List::create(_["result"]=true,_["order"]=NumericVector::create(k,j,i));
  }
  else if (g(j,i)==1 && g(i,j)==0 && g(k,i)==1 && g(i,k)==0 && g(j,k)==0 && g(k,j)==0)
  {
    
    //Rcout << "j -> i <- k";
    
    return List::create(_["result"]=true,_["order"]=NumericVector::create(j,i,k));
  }
  else 
  {
    
    //Rcout << "No unshielded triple\n";
    //Rcout << std::endl;
    
    return List::create(_["result"]=false,_["order"]=NA_REAL);
  }
}

bool check_other_triple(NumericMatrix g2,NumericVector v){
  // check v(0) -> v(1) <- v(2) with v(0) and v(2) nonadjacent
  if (g2(v(0),v(1))==1 && g2(v(1),v(0))==0 && 
      g2(v(2),v(1))==1 && g2(v(1),v(2))==0 && 
      g2(v(0),v(2))==0 && g2(v(2),v(0))==0){
    //Rcout << " | v-structure correctly recovered\n";
    return true;
  } else {
    //Rcout << " | v-structure *not* present in true graph\n";
    return false;
  }
}

// [[Rcpp::export]]
List compare_v_structures(NumericMatrix est,NumericMatrix truth,NumericVector targets){
  validateInputs(est,truth);
  int num_missing=0;
  int num_added=0;
  int num_correct=0;
  
  int p = est.nrow();
  List triple_check;
  bool continue_checking=true;
  
  for (int i=0;i<p-2;++i){
    for (int j=i+1;j<p-1;++j){
      for (int k=j+1;k<p;++k){
        // only proceed if i, j, and k are all in the same target's neighborhood
        if (sharedNeighborhood(truth,targets,i,j) && sharedNeighborhood(truth,targets,i,k) && sharedNeighborhood(truth,targets,j,k)){
          //Rcout << "Checking: " << i << ", " << j << ", and " << k << std::endl;
          //Rcout << "Estimated Graph:\n";
          triple_check = check_triple(est,i,j,k);
          if (triple_check["result"]){
            if (check_other_triple(truth,triple_check["order"])){
              continue_checking=false; // We don't need to check the true graph since v-structure was correctly identified
              ++num_correct;
            } else {
              ++num_added; // there could be a missing v-structure
            }
          }
          
          // Now, we check if we missed any v-structures
          if (continue_checking){
            //Rcout << "True Graph:\n";
            
            triple_check = check_triple(truth,i,j,k);
            if (triple_check["result"]){
              //Rcout << " | v-structure *not* present in estimated graph\n";
              ++num_missing;
            } else {
              continue_checking=true;
            }
          }
        }
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
// void update_edge_values(NumericMatrix est,NumericMatrix truth,const int &i,const int &j,int &correct,int &missing,int &added,bool verbose){
//   bool est_cond;
//   bool truth_cond;
//   // Estimated: i -> j | Ground: i -> j
//   est_cond = est(i,j)==1 && est(j,i)!=1;
//   truth_cond = truth(i,j)==1 && truth(j,i)!=1;
//   if (est_cond && truth_cond){
//     if (verbose){
//       Rcout << "Correct parent of " << j << ": " << i << std::endl;
//     }
//     ++correct;
//   } else if (est_cond && !truth_cond){
//     if (verbose){
//       Rcout << "False positive parent of " << j << ": " << i << std::endl;
//     }
//     ++added;
//   } else if (!est_cond && truth_cond){
//     if (verbose){
//       Rcout << "False negative parent of " << j << ": " << i << std::endl;
//     }
//     ++missing;
//   }
// }

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

void pra_onetarget(NumericMatrix est,NumericMatrix truth,int t,NumericVector &targets,
                   int &correct,int &missing,int &added,int &potential,bool verbose){
  int p = est.nrow();
  for (int i=0;i<p;++i){
    if (i==t || !sharedNeighborhood(truth,targets,t,i)){
      continue;
    }
    if (verbose){
      Rcout << "t: " << t << " | i: " << i; 
    }
    
    /*
     * We first deal with the case where the estimated graph has i as a parent of t
     * We can have:
     * a) False positive: not adjacent in true graph or t -> i
     * b) Correct
     * c) Potential: undirected edge for t - i in the true graph
     * 
     * We then deal with the case where the estimated graph does not have i as a parent of t
     * We can have:
     * a) False negative: i -> t in true graph
     * b) Correct: Not noted since this is a true negative
     * c) Potential: undirected edge i - t in estimated graph and i -> t in true graph
     * d) Potential: undirected edge for both
     */
    if (est(i,t)==1 && est(t,i)==0){ // Est: i -> t
      //Rcout << " | Est. Graph: Parent | True graph: ";
      // Truth: Either i <- t or i and t are not adjacent
      if (truth(i,t)==0){
        ++added;
        //Rcout << "Not a parent | ";
        //Rcout << "Added: " << added << std::endl;
      }
      else if (truth(i,t)==1 && truth(t,i)==0) { // Truth: i -> t
        ++correct;
        if (verbose){
          Rcout << " | Parent | ";
          Rcout << "Correct: " << correct << std::endl;
        }
        
      } else if (truth(i,t)==1 && truth(t,i)==1){ // Truth: i - t
        ++potential;
        if (verbose){
          Rcout << " | Undirected edge in True Graph | Potential: " << potential << std::endl;  
        }
      }
    } else { // Est: Either i - t or i and t are not adjacent
      if (truth(i,t)==1 && truth(t,i)!=1){ // Truth: i -> t
        ++missing;
        if (verbose){
          Rcout << " | Est. Graph: Not a parent | True graph: Parent | ";
          Rcout << "Missing: " << missing;
        }
        if (est(i,t)==1 && est(t,i)==1){ // Est: i - t
          ++potential;
          if (verbose){
            Rcout << " | Undirected edge in Est. Graph | Potential: " << potential;
          }
        }
      } else if (truth(i,t)==1 && truth(t,i)==1 && est(i,t)==1 && est(t,i)==1){ // Both undirected
        ++potential;
        if (verbose){
          Rcout << " | Both graphs have undirected edges | Potential: " << potential;  
        }
        
      } 
    }
    if (verbose) {
      Rcout << "\n";
    }
  }
}

// [[Rcpp::export]]
List parent_recovery_accuracy(NumericMatrix est,NumericMatrix truth,NumericVector targets,bool verbose=false){
  validateInputs(est,truth);
  validateTargets(est,targets);
  int num_correct=0;
  int num_added=0;
  int num_missing=0;
  int num_potential=0;
  
  std::for_each(targets.begin(),
                targets.end(),
                [&](int t) {pra_onetarget(est,truth,t,targets,
                    num_correct,num_missing,num_added,num_potential,verbose);});
  
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
// // [[Rcpp::export]]
// NumericMatrix convert_true_dag(NumericMatrix G){
//   
//   NumericMatrix Gc = clone(G);
//   int p = Gc.ncol();
//   
//   for (int i=0;i<p;++i){
//     for (int j=i+1;j<p;++j){
//       if (Gc(i,j)==1){
//         Gc(i,j)=2;
//         Gc(j,i)=3;
//       } else if (Gc(j,i)==1){
//         Gc(j,i)=2;
//         Gc(i,j)=3;
//       }
//     }
//   }
//   
//   return Gc;
// }

/*
 * Convert PC amat
 * All directed edges must change: if (i,j)==1 and (j,i)==0, those must be changed to 2 and 3 respectively
 * All undirected edges remain the same (1's)
 * All other unconnected edges also remain the same (0's)
 */

// // [[Rcpp::export]]
// NumericMatrix convert_pc_amat(NumericMatrix G){
//   NumericMatrix Gc = clone(G);
//   int p = Gc.ncol();
//   for (int i=0;i<p;++i){
//     for (int j=i+1;j<p;++j){
//       if (Gc(i,j)==1 && Gc(j,i)==0){
//         Gc(i,j)=2;
//         Gc(j,i)=3;
//       } else if (Gc(j,i)==1 && Gc(i,j)==0){
//         Gc(j,i)=2;
//         Gc(i,j)=3;
//       }
//     }
//   }
//   return Gc;
// }

void makeNodeNames(int p,StringVector &node_names){
  for (int i=0;i<p;++i){
    String node("V");
    node += i;
    node_names.push_back(node);
  }
}

bool idAncestors(NumericMatrix reference,int i,int j,bool verbose=true){
  int p = reference.nrow();
  StringVector node_names;
  makeNodeNames(p,node_names);
  
  DAG g_ref(p,node_names,reference,verbose);
  return g_ref.isAncestor(i,j);
}

// Returns true if there is an ancestral path between anc and desc
// that is not mediated by any node in the target neighborhood
bool checkAncestralPath(NumericMatrix reference,NumericVector targets,
                        int anc,int desc,bool verbose=true){
  if (verbose){
    Rcout << "Checking if " << anc << " is an unmediated ancestor of " << desc << std::endl;
  }
  int p = reference.nrow();
  StringVector node_names;
  makeNodeNames(p,node_names);
  DAG g_ref(p,node_names,reference,verbose);
  
  if (!g_ref.isAncestor(desc,anc)){
    if (verbose){
      Rcout << "Node " << desc << " is not a descendant of " << anc << std::endl;
    }
    return false;
  }
  
  // Get parents of the potential descendant node
  NumericVector parent_set = g_ref.getParents(desc);
  NumericVector::iterator parent=parent_set.begin();
  for (;parent<parent_set.end();++parent){
    // Check if there is a parent node in the same target neighborhood
    // as the descendant node which is also a descendant of the ancestral node
    if (g_ref.isAncestor(*parent,anc) && 
        sharedNeighborhood(reference,targets,*parent,desc,verbose)){
      if (verbose){
        Rcout << "Node " << *parent << " is a parent of " << desc;
        Rcout << " and is in the same target neighborhood, while also being a ";
        Rcout << "descendant of " << anc << std::endl;
      }
      return false;
    }
  }
  
  NumericVector children_set = g_ref.getChildren(anc);
  NumericVector::iterator child=children_set.begin();
  for (;child<children_set.end();++child){
    // Check if there is a parent node in the same target neighborhood
    // as the descendant node which is also a descendant of the ancestral node
    if (g_ref.isAncestor(desc,*child) && 
        sharedNeighborhood(reference,targets,*child,anc,verbose)){
      if (verbose){
        Rcout << "Node " << *child << " is a child of " << anc;
        Rcout << " and is in the same target neighborhood, while also being an ";
        Rcout << "ancestor of " << desc << std::endl;
      }
      return false;
    }
  }
  // There are no mediating nodes in the path from anc to desc
  // which share the same target neighborhood as desc
  if (verbose){
    Rcout << "There is an unmediated ancestral path between " << anc << " and " << desc << std::endl;
  }
  return true;

}

// [[Rcpp::export]]
List interNeighborhoodEdgeMetrics(NumericMatrix est,NumericMatrix reference,
                                  NumericVector targets,bool verbose=true){
  int p = est.nrow();
  
  int true_ancestor = 0;
  int missing_ancestor = 0;
  int missing_orientation = 0;
  int reverse_orientation = 0;
  int added_connection = 0;
  int false_positive_arrow = 0;
  
  bool connected; // tracks whether two nodes are connected in estimated graph
  bool is_i_ancestor_j; // tracks whether i is an ancestor of j
  bool is_j_ancestor_i; // tracks whether j is an ancestor of i
  bool is_anc_path_unmediated_ij; // tracks whether the ancestral path is mediated between i and j
  bool is_anc_path_unmediated_ji; // tracks whether the ancestral path is mediated between j and i
  bool i_arrow_j;
  bool j_arrow_i;
  bool undirected;
  bool bidirected;
  
  for (int i=0;i<p-1;++i){
    for (int j=i+1;j<p;++j){
      // check the following:
      // i and j each belong to a target neighborhood 
      // both belong to different target neighborhoods
      if (!sharedNeighborhood(reference,targets,i,j,verbose) && 
          inTargetNeighborhood(reference,targets,i,verbose) && 
          inTargetNeighborhood(reference,targets,j,verbose)){
        
        if (verbose){
          Rcout << "Looking at nodes " << i << " and " << j << std::endl;
        }
        
        // Check if i is connected to j in estimated graph
        connected = est(i,j) != 0 || est(j,i) != 0;
        if (est(i,j)==3 && est(j,i)==3){
          warning("Adjacency matrix entries for (%i,%i) and (%i,%i) are both 3.",i,j,j,i);
        } 
        is_i_ancestor_j = idAncestors(reference,j,i,verbose);
        is_anc_path_unmediated_ij = checkAncestralPath(reference,targets,i,j,verbose);
        is_j_ancestor_i = idAncestors(reference,i,j,verbose);
        is_anc_path_unmediated_ji = checkAncestralPath(reference,targets,j,i,verbose);
        if (!connected){
          if (verbose){
            Rcout << "Nodes are unconnected in estimated graph\n";
          }
          if ((is_j_ancestor_i && is_anc_path_unmediated_ji) || 
              (is_i_ancestor_j && is_anc_path_unmediated_ij)){
            if (verbose){
              Rcout << "Missing ancestral relationship\n";
            }
            ++missing_ancestor;
          }
        } else { // i and j are connected in estimated graph
          if (verbose){
            Rcout << "Nodes are connected in estimated graph\n";
          }
          i_arrow_j = (est(i,j)==2 && est(j,i)!=2) || (est(i,j)==1 && est(j,i)==0);
          j_arrow_i = (est(j,i)==2 && est(i,j)!=2) || (est(i,j)==0 && est(j,i)==1);
          undirected = est(i,j)==1 && est(j,i)==1;
          bidirected = est(i,j)==2 && est(j,i)==2;
          if (is_i_ancestor_j && i_arrow_j && is_anc_path_unmediated_ij){
            if (verbose){
              Rcout << "True ancestral relationship (i->j)\n";
            }
            ++true_ancestor;
          } else if (is_j_ancestor_i && j_arrow_i && is_anc_path_unmediated_ji){
            if (verbose){
              Rcout << "True ancestral relationship (j->i)\n";
            }
            ++true_ancestor;
          } else if (is_i_ancestor_j && (undirected || bidirected) && is_anc_path_unmediated_ij){
            if (verbose){
              Rcout << "Missing orientation of ancestral relationship (i->j)\n";
            }
            ++missing_orientation;
          } else if (is_j_ancestor_i && (undirected || bidirected) && is_anc_path_unmediated_ji){
            if (verbose){
              Rcout << "Missing orientation of ancestral relationship (j->i)\n";
            }
            ++missing_orientation;
          } else if (is_i_ancestor_j && j_arrow_i && is_anc_path_unmediated_ij){
            if (verbose){
              Rcout << "Orientation Reversed: j->i instead of i->j\n";
            }
            ++reverse_orientation;
          } else if (is_j_ancestor_i && i_arrow_j && is_anc_path_unmediated_ji){
            if (verbose){
              Rcout << "Orientation Reversed: i->j instead of j->i\n";
            }
            ++reverse_orientation;
          } else if ((i_arrow_j || j_arrow_i) && !(is_i_ancestor_j || is_j_ancestor_i)){
            if (verbose){
              Rcout << "False positive ancestral relationship\n";
            }
            ++false_positive_arrow;
          } else {
            if (verbose){
              Rcout << "False positive connection\n"; 
            }
            ++added_connection;
          }
        }
      }
    }
  }
  return List::create(
    _["CorrectAncestors"]=true_ancestor,
    _["MissingAncestors"]=missing_ancestor,
    _["MissingOrientation"]=missing_orientation,
    _["ReverseOrientation"]=reverse_orientation,
    _["FPOrientedEdge"]=false_positive_arrow,
    _["AddedConnection"]=added_connection
  );
}

/*
 * A true positive is when the orientation exactly matches in both graphs
 * A true negative is when there is no edge in both graphs
 * A false positive is when there is an edge in the est. graph but no edge in true
 * A false negative is whenever there is an edge in the true graph 
 * which does not exactly match the edge in the estimated graph
 */
// [[Rcpp::export]]
double overallF1(NumericMatrix est,NumericMatrix ref,
                 NumericVector targets,bool verbose){
  validateInputs(est,ref);
  validateTargets(ref,targets);

  double tp = 0;
  double fp = 0;
  double fn = 0.;
  int p = est.nrow();
  
  int e_ij;
  int e_ji;
  int t_ij;
  int t_ji;
  
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      if (sharedNeighborhood(ref,targets,i,j)){
        e_ij = est(i,j); e_ji = est(j,i); t_ij = ref(i,j); t_ji = ref(j,i);
        if ((e_ij==t_ij) && (e_ji==t_ji) && (e_ij!=0 || e_ji!=0)){
          tp += 1;
          if (verbose){
            Rcout << "Edge between " << i << " and " << j << " match. TP=";
            Rcout << tp << std::endl;
          }
        } else if ((e_ij!=t_ij) || (e_ji!=t_ji)){
          if (t_ij!=0 || t_ji != 0){
            fn += 1;
            if (verbose){
              Rcout << "Edge between " << i << " and " << j;
              Rcout << " appears in true graph but not in the estimated graph.";
              Rcout << " FN=" << fn << std::endl;
            }
          } else {
            fp += 1;
            if (verbose){
              Rcout << "Edge between " << i << " and " << j;
              Rcout << " appears in estimated graph but not in the true graph.";
              Rcout << " FP=" << fp << std::endl;
            }
          }
        }
      }
    }
  }
  double f1 = (2.0 * tp) / (2.0*tp + fp + fn);
  
  return f1;
}


// [[Rcpp::export]]
DataFrame all_metrics(NumericMatrix est,NumericMatrix ref_graph,
                      NumericVector targets,bool verbose=false,
                      std::string algo="pc",std::string ref="sub_cpdag"){
  validateInputs(est,ref_graph);
  validateTargets(ref_graph,targets);
  
  // Get the estimated dag next
  List est_skeleton = compare_skeletons(est,ref_graph,targets);
  List est_vstruct = compare_v_structures(est,ref_graph,targets);
  List est_pra = parent_recovery_accuracy(est,ref_graph,targets);
  List est_ancestors = interNeighborhoodEdgeMetrics(est,ref_graph,targets,verbose);
  
  return DataFrame::create(
    _[algo+"_skel_fp"]=est_skeleton["skel_fp"],
    _[algo+"_skel_fn"]=est_skeleton["skel_fn"],
    _[algo+"_skel_tp"]=est_skeleton["skel_correct"],
    _[algo+"_v_fn"] = est_vstruct["missing"],
    _[algo+"_v_fp"] = est_vstruct["added"],
    _[algo+"_v_tp"] = est_vstruct["correct"],
    _[algo+"_pra_fn"]=est_pra["missing"],
    _[algo+"_pra_fp"] = est_pra["added"],
    _[algo+"_pra_tp"] = est_pra["correct"],
    _[algo+"_pra_potential"] = est_pra["potential"],
    _[algo+"_ancestors_correct"]=est_ancestors["CorrectAncestors"],
    _[algo+"_ancestors_missing"]=est_ancestors["MissingAncestors"],
    _[algo+"_ancestors_fn_orient"]=est_ancestors["MissingOrientation"],
    _[algo+"_ancestors_reverse"]=est_ancestors["ReverseOrientation"],
    _[algo+"_ancestors_fp_oriented"]=est_ancestors["FPOrientedEdge"],
    _[algo+"_ancestors_fp_connect"]=est_ancestors["AddedConnection"],
    _[algo+"_overall_f1"]=overallF1(est,ref_graph,targets,verbose)                                             
  );
}

// [[Rcpp::export]]
DataFrame neighborhood_metrics(NumericMatrix G){
  return DataFrame::create(
    _["size"]=G.ncol(),
    _["num_edges"]=get_edge_number(G)
  );
}

// TODO: create a function to compare the estimated DAG to the reference DAG






