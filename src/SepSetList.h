#ifndef SepSetList_H
#define SepSetList_H

#include "sharedFunctions.h"

using namespace Rcpp;

class SepSetList {
public:
  SepSetList(NumericVector &neighbors);

  void changeList(size_t i,size_t j,
                  NumericVector sep=NumericVector::create(-1));

  NumericVector getSepSet(size_t i,size_t j); 

  bool isPotentialVStruct(size_t i, size_t j,size_t k);
  bool isSepSetMember(size_t i,size_t j,size_t k);
  
  void printSepSetList();
  List getS() { return S; };

private:
  size_t N;
  NumericVector nodes;
  List S;
};

#endif
