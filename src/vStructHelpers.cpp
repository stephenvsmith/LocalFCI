#include "sharedFunctions.h"

using namespace Rcpp;

// Returns adjacent nodes from the estimated skeleton
NumericVector get_adjacent(NumericMatrix M,int i){
  NumericVector final;
  int p = M.ncol();
  
  for (int j=0;j<p;++j){
    if (M(i,j)!=0){
      final.push_back(j);
    }
  }
  
  return final;
}

// Returns nodes that are not adjacent to i in the estimated skeleton
NumericVector get_nonadjacent(NumericMatrix M,int i){
  NumericVector final;
  int p = M.ncol();
  
  for (int j=0;j<p;++j){
    if (M(i,j)==0 & j!=i){
      final.push_back(j);
    }
  }
  
  return final;
}

// Determines whether or not i is in vector x
bool check_membership(NumericVector x,int i){
  NumericVector::iterator it = x.begin();
  int j;
  
  for (;it!=x.end();++it){
    j = *it;
    if (i == j){
      return true;
    }
  }
  
  return false;
}

/*
 * Translates the estimated skeleton in shrunken form to the estimated skeleton in the final, expanded form
 * That is, this is the estimated skeleton adjacency matrix when we have p nodes
 * In this function, we only use the upper triangular matrix for efficiency
 */
// [[Rcpp::export]]
void makeFinalGraph(NumericMatrix &G,NumericMatrix &C,NumericVector &neighborhood,const int &N){
  for (int i = 0;i < N;++i){
    for (int j = i+1;j < N;++j){
      if (C(i,j)==1){
        //Rcout << "C[" << i << "," << j << "] = 1" << std::endl;
        //Rcout << "Updating (" << neighborhood(i) << "," << neighborhood(j) << ")\n";
        G(neighborhood(i),neighborhood(j))=1;
        G(neighborhood(j),neighborhood(i))=1;
        //Rcout << "Updated Gfinal:\n";
        //print_matrix(G);
      }
    }
  }
}

// Reviewed: 12/16/20
List get_v_structures_efficient(List L) {
  List S = L["S"];
  NumericMatrix G = L["C"];
  NumericVector neighborhood = L["neighborhood"];
  bool verbose = L["verbose"];
  
  int p = L["p"];
  int N = G.nrow();
  
  // Making the final graph the correct size (p x p)
  NumericMatrix Gfinal(p);
  makeFinalGraph(Gfinal,G,neighborhood,N);
  if (verbose){
    Rcout << "Final Graph setup" << std::endl;
    print_matrix(Gfinal);
    Rcout << std::endl << std::endl;
    Rcout << "Initial graph setup" << std::endl;
    print_matrix(G);
  }
  
  int j;
  int k;
  
  bool no_neighbors;
  bool j_invalid;
  NumericVector placeholder;
  
  NumericVector i_adj;
  NumericVector j_adj;
  NumericVector j_vals;
  NumericVector k_vals;
  
  List sublist;
  bool valid_v_struct;
  bool valid_v_struct_check;
  String node_i;
  String node_j;
  int node_k;
  
  if (verbose){
    Rcout << "Beginning loops to find v-structures.\n";
  }
  // We are searching for i-k-j where i and j are not adjacent and k is 
  // not in the separating set for i and j
  for (int i=0;i<N;++i){
    placeholder = G(i,_);
    no_neighbors = (all(placeholder==0)).is_true();
    if (!no_neighbors){
      if (verbose){
        Rcout << "i: " << i << std::endl;
      }
      i_adj = get_adjacent(G,i); // potential values of k
      j_vals = get_nonadjacent(G,i); // potential values of j
      // Iterate over possible j values
      for (NumericVector::iterator it=j_vals.begin();it != j_vals.end();++it){
        j = *it;
        // Node j has no children,
        // j is parent to i, 
        // or we are repeating an analysis and this j should not be considered
        placeholder = G(j,_);
        j_invalid = (all(placeholder==0)).is_true();
        j_invalid = j_invalid || G(j,i)!= 0 || j < i;
        if (!j_invalid){
          if (verbose){
            Rcout << "j: " << j << std::endl;
          }
          j_adj = get_adjacent(G,j);
          k_vals = intersect(i_adj,j_adj); // k must be a neighbor
          // If there are no common neighbors, move to next j
          if (k_vals.length()!=0){
            // We loop through all of the common neighbors
            for (NumericVector::iterator it2 = k_vals.begin();it2!=k_vals.end();++it2){
              k = *it2;
              if (verbose){
                Rcout << "k: " << k << std::endl; 
              }
              // Verify if k is in separating set for i and j
              node_i = String((char) neighborhood(i));
              node_j = String((char) neighborhood(j));
              sublist = S[node_j];
              node_k = neighborhood(k);
              valid_v_struct = !check_membership(sublist[node_i],node_k);
              // Check other way just in case
              sublist = S[node_i];
              valid_v_struct_check = !check_membership(sublist[node_j],node_k);
              if (valid_v_struct && valid_v_struct_check){
                if (verbose){
                  Rcout << "Separation Set: ";
                  print_vector_elements_nonames(sublist[node_j]);
                  Rcout << " | V-Structure: " << node_i.get_cstring() << "*->" << node_k << "<-*" << node_j.get_cstring() << std::endl; 
                }
                Gfinal(neighborhood(i),neighborhood(k)) = 2; // An arrow is denoted by "2"
                Gfinal(neighborhood(j),neighborhood(k)) = 2; // i and j are separated ("0")
              } else if (valid_v_struct && !valid_v_struct_check){
                Rcout << "Error in separating set construction: S_ij != S_ji\n";
              }
            }
          }
        }
      }
    }
  }
  
  
  return List::create(
    _["G"]=Gfinal,
    _["NumTests"]=L["NumTests"],
    _["S"]=S
  );
}

