#include "sharedFunctions.h"

using namespace Rcpp;

// Returns adjacent nodes from the estimated skeleton
NumericVector get_adjacent(NumericMatrix M,int i){
  NumericVector final;
  int p = M.ncol();
  
  for (int j=0;j<p;++j){
    if (M(i,j)==1){
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
bool isMember(NumericVector x,int i){
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
void makeFinalGraph(NumericMatrix &G,const NumericMatrix &C,NumericVector &neighborhood){
  int N = C.ncol();
  for (int i = 0;i < N;++i){
    for (int j = i+1;j < N;++j){
      if (C(i,j)!=0){
        //Rcout << "C[" << i << "," << j << "] = 1" << std::endl;
        //Rcout << "Updating (" << neighborhood(i) << "," << neighborhood(j) << ")\n";
        G(neighborhood(i),neighborhood(j))=C(i,j);
        G(neighborhood(j),neighborhood(i))=C(j,i);
        //Rcout << "Updated Gfinal:\n";
        //print_matrix(G);
      }
    }
  }
}
/*
// Reviewed: 12/16/20
// We are trying to identify structures i -> k <- j
// Where i and j are not adjacent, and k is not in the separating set of i and j
// [[Rcpp::export]]
List get_v_structures_efficient(List L) {
  List S = L["S"]; //separating sets
  NumericMatrix G = L["C"]; // current graph
  NumericVector neighborhood = L["neighborhood"]; //neighborhood of nodes under consideration
  StringVector names = L["names"];
  bool verbose = L["verbose"];
  
  int p = L["p"]; // number of total nodes in the network
  int N = G.nrow(); // number of nodes under consideration
  
  int j;
  int k;
  
  bool no_neighbors;
  bool j_invalid;
  NumericVector placeholder;
  
  NumericVector i_adj;
  NumericVector j_adj;
  NumericVector j_vals;
  NumericVector k_vals;
  
  if (verbose){
    Rcout << "Beginning loops to find v-structures.\n";
  }
  // We are searching for i-k-j where i and j are not adjacent and k is 
  // not in the separating set for i and j
  for (int i=0;i<N;++i){
    placeholder = G(i,_); // We will search this vector for nodes connected to node i
    no_neighbors = (all(placeholder==0)).is_true();
    if (!no_neighbors){
      if (verbose){
        Rcout << "i: "<< i << " (" << names(neighborhood(i)) << ")" << std::endl;
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
        j_invalid = j_invalid || G(j,i)!= 0 || j <= i;
        if (!j_invalid){
          if (verbose){
            Rcout << "j: " << j << " (" << names(neighborhood(j)) << ")"<< std::endl;
          }
          j_adj = get_adjacent(G,j);
          k_vals = intersect(i_adj,j_adj); // k must be a neighbor of i and j
          if (verbose && k_vals.length()>0){
            Rcout << "Potential k values: ";
            print_vector_elements(k_vals,names[neighborhood],"","\n");
          }
          // If there are no common neighbors, move to next j
          if (k_vals.length()!=0){
            for (NumericVector::iterator it2 = k_vals.begin();it2!=k_vals.end();++it2){
              k = *it2;
              if (verbose){
                Rcout << "k: " << k << " (" << names(neighborhood(k)) << ")\n"; 
              }
              // Verify if k is in separating set for i and j
              if (S->isSeparated(i,j,k)){
                if (verbose){
                  Rcout << " | V-Structure: " << node_i.get_cstring() << "*->" << node_k << "<-*" << node_j.get_cstring() << std::endl; 
                }
                G(i,k) = 2; // An arrow is denoted by "2"
                G(j,k) = 2; // i and j are separated ("0")
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
    _["C"]=G,
    _["NumTests"]=L["NumTests"],
    _["S"]=S,
    _["neighborhood"] = L["neighborhood"],
    _["names"] = L["names"],
    _["verbose"] = L["verbose"],
    _["p"] = L["p"]
  );
}
*/
