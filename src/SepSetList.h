#ifndef SepSetList_H
#define SepSetList_H

#include "sharedFunctions.h"

using namespace Rcpp;

class SepSetList {
public:
  SepSetList(NumericVector &neighbors); // Tested

  void changeList(int i,int j,NumericVector sep); // Tested
  void changeList(int i,int j); // Tested

  NumericVector getSepSet(int i,int j); // Tested

  bool isPotentialVStruct(int i, int j,int k); // Tested
  bool isSepSetMember(int i,int j,int k); // Tested
  
  void printSepSetList(); // Tested
  
  List getS() { return S; };
private:
  int N;
  NumericVector nodes;
  List S;
};

#endif
