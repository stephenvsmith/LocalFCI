#include "SepSetList.h"
#include "vStructHelpers.h"
#include <algorithm>
using namespace Rcpp;

SepSetList::SepSetList(NumericVector &neighbors):nodes(neighbors){
  int N = neighbors.length();
  for (int i=0;i<N;++i){
    List subset = List::create();
    for (int j=0;j<N;++j){
      subset.push_back(NumericVector::create(NA_REAL));
    }
    S.push_back(subset);
  }
}

void SepSetList::changeListEfficient(int i,int j,NumericVector sep){
  NumericVector sep_new;
  sep_new = clone(sep);
  List sublist;
  sublist = S[i];
  sublist[j] = sep_new;
  //S[i] = sublist; // TODO: Not sure this line is necessary
}

void SepSetList::changeListEfficient(int i,int j){
  changeListEfficient(i,j,NumericVector::create(-1));  
}

/*
 * Takes the efficient numbering for two nodes (i and j)
 * and returns the nodes in the sep set according to efficient numbering
 */
NumericVector SepSetList::getSepSetTrue(int i,int j){
  // Identify separating sets for nodes i and j
  List sublist_i = S[i];
  return sublist_i[j];
}

// NumericVector SepSetList::getSepSetTrue(int i,int j){
//   NumericVector efficientSet = getSepSetEfficient(i,j);
//   return nodes[efficientSet];
// }


// bool SepSetList::isSeparatedEfficient(int i,int j,int k) {
//   NumericVector sepset_ji;
//   NumericVector sepset_ij;
//   bool valid_v_struct;
//   bool valid_v_struct_check;
//   
//   sepset_ji = getSepSetEfficient(j,i);
//   sepset_ij = getSepSetEfficient(i,j);
//   // Verify if k is in separating set for i and j
//   valid_v_struct = !isMember(sepset_ij,k);
//   // Check other way just in case
//   valid_v_struct_check = !isMember(sepset_ji,k);
//   return valid_v_struct && valid_v_struct_check;
// }
 // True just refers to numbering
bool SepSetList::isSeparatedTrue(int i,int j,int k) {
  NumericVector sepset_ji;
  NumericVector sepset_ij;
  bool valid_v_struct;
  bool valid_v_struct_check;
  int node_k;
  
  sepset_ji = getSepSetTrue(j,i);
  sepset_ij = getSepSetTrue(i,j);
  // Verify if k is in separating set for i and j
  node_k = nodes(k);
  valid_v_struct = !isMember(sepset_ij,node_k);
  // Check other way just in case
  valid_v_struct_check = !isMember(sepset_ji,node_k);
  // TODO error message if these are not the same
  return valid_v_struct && valid_v_struct_check;
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

