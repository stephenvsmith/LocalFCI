#include "SepSetList.h"

SepSetList::SepSetList(NumericVector &neighbors):nodes(neighbors){
  N = neighbors.size();
   for (size_t i : neighbors){
    List subset = List::create();
    for (size_t j : neighbors){
      subset.push_back(NumericVector::create(NA_REAL));
    }
    S.push_back(subset);
  }
}

void checkInputValues(size_t i,size_t j, 
                      size_t N){
  if (i<0 || i>=N){
    stop("Input i=%i is invalid",i);
  }
  if (j<0 || j>=N){
    stop("Input j=%i is invalid",j);
  }
}

void SepSetList::changeList(size_t i,size_t j,
                            NumericVector sep){
  checkInputValues(i,j,N);
  NumericVector sep_new;
  // since the vector is passed in by reference automatically,
  // We must clone it to make any changes to `sep` in further steps
  sep_new = clone(sep); 
  List sublist;
  sublist = S[i];
  sublist[j] = sep_new;
}

/*
 * Takes the efficient numbering for two nodes (i and j)
 * and returns the nodes in the sep set according to efficient numbering
 */
NumericVector SepSetList::getSepSet(size_t i,size_t j){
  // Identify separating sets for nodes i and j
  List sublist_i = S[i];
  return sublist_i[j];
}

// k is assumed to be according to the true Graph numbering
bool SepSetList::isSepSetMember(size_t i,size_t j,size_t k){
  checkInputValues(i,j,N);
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
    warning("Separation sets for %i and %i disagree",i,j);
  }
  
  return is_member && is_member_check;
}

bool SepSetList::isPotentialVStruct(size_t i,size_t j,size_t k) {
  return !isSepSetMember(i,j,k);
}

void SepSetList::printSepSetList(){
  List sublist;
  NumericVector sepLabels;
  for (size_t i=0;i<S.length();++i){
    sublist = S[i]; 
    for (size_t j=0;j<S.length();++j){
      Rcout << "S_{" << nodes(i) << "," << nodes(j) << "} = ";
      sepLabels = sublist[j];
      printVecElementsNoNames(sepLabels,"",""," ");
      Rcout << " ";
    }
    Rcout << std::endl;
  }
}

