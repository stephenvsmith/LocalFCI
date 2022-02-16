#include "SepSetList.h"
using namespace Rcpp;

SepSetList::SepSetList(NumericVector &neighbors):nodes(neighbors){
  N = neighbors.length();
  for (int i=0;i<N;++i){
    List subset = List::create();
    for (int j=0;j<N;++j){
      subset.push_back(NumericVector::create(NA_REAL));
    }
    S.push_back(subset);
  }
}

void checkInputValues(int i,int j, int N){
  if (i<0 || i>=N){
    stop("Input i=%i is invalid",i);
  }
  if (j<0 || j>=N){
    stop("Input j=%i is invalid",j);
  }
}

void SepSetList::changeList(int i,int j,NumericVector sep){
  checkInputValues(i,j,N);
  print_vector_elements_nonames(sep,"Separation Values:","\n"," ");
  NumericVector sep_new;
  sep_new = clone(sep);
  List sublist;
  sublist = S[i];
  sublist[j] = sep_new;
}

void SepSetList::changeList(int i,int j){
  NumericVector tmp = { -1 };
  changeList(i,j,tmp);  
}

/*
 * Takes the efficient numbering for two nodes (i and j)
 * and returns the nodes in the sep set according to efficient numbering
 */
NumericVector SepSetList::getSepSet(int i,int j){
  // Identify separating sets for nodes i and j
  List sublist_i = S[i];
  return sublist_i[j];
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

 // True just refers to numbering
bool SepSetList::isPotentialVStruct(int i,int j,int k) {
  NumericVector sepset_ji;
  NumericVector sepset_ij;
  bool valid_v_struct;
  bool valid_v_struct_check;
  int node_k;
  
  sepset_ji = getSepSet(j,i);
  sepset_ij = getSepSet(i,j);
  // Verify if k is in separating set for i and j
  node_k = k; // We are assuming the input of the true value of node k
  valid_v_struct = !isMember(sepset_ij,node_k);
  // Check other way just in case
  valid_v_struct_check = !isMember(sepset_ji,node_k);
  // TODO error message if these are not the same
  return valid_v_struct && valid_v_struct_check;
}

bool SepSetList::isSeparated(int i,int j,int k){
  return !isPotentialVStruct(i,j,k); // Result should be true if k is a member of S_ij or S_ji in this case
}

void SepSetList::printSepSetList(){
  List sublist;
  NumericVector sepLabels;
  for (int i=0;i<S.length();++i){
    sublist = S[i]; 
    for (int j=0;j<S.length();++j){
      Rcout << "S[[" << nodes(i) << "]][[" << nodes(j) << "]] = ";
      sepLabels = sublist[j];
      // if (!(is_na(efficientLabels)[0])){
      //   if (efficientLabels[0]!=-1){
      //     efficientLabels = nodes[efficientLabels];
      //   }
      // }
      print_vector_elements_nonames(sepLabels,"",""," ");
      Rcout << " ";
    }
    Rcout << std::endl;
  }
}

