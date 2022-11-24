#ifndef SepSetList_H
#define SepSetList_H

#include "sharedFunctions.h"

class SepSetList {
public:
  SepSetList(NumericVector &neighbors); // tested

  void changeList(size_t i,size_t j,
                  NumericVector sep=NumericVector::create(-1)); // tested

  NumericVector getSepSet(size_t i,size_t j); // tested

  bool isPotentialVStruct(size_t i, size_t j,size_t k);// implicitly tested with isSepSetMember
  bool isSepSetMember(size_t i,size_t j,size_t k); // tested
  
  void printSepSetList();
  List getS() { return S; };

private:
  size_t N;
  NumericVector nodes;
  List S;
};

#endif
