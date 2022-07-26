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
  // print_vector_elements_nonames(sep,"Separation Values:","\n"," ");
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

// k is assumed to be according to the true Graph numbering
bool SepSetList::isSepSetMember(int i,int j,int k){
  NumericVector sepset_ji;
  NumericVector sepset_ij;
  bool is_member;
  bool is_member_check;

  
  sepset_ji = getSepSet(j,i);
  sepset_ij = getSepSet(i,j);
  // Verify if k is in separating set for i and j
  is_member = isMember(sepset_ij,k);
  // Check other way just in case
  is_member_check = isMember(sepset_ji,k);
  
  if (is_member != is_member_check){
    warning("Warning: separation sets for %i and %i disagree",i,j);
  }
  
  return is_member && is_member_check;
}

bool SepSetList::isPotentialVStruct(int i,int j,int k) {
  return !isSepSetMember(i,j,k);
}

void SepSetList::printSepSetList(){
  List sublist;
  NumericVector sepLabels;
  for (int i=0;i<S.length();++i){
    sublist = S[i]; 
    for (int j=0;j<S.length();++j){
      Rcout << "S_{" << nodes(i) << "," << nodes(j) << "} = ";
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

