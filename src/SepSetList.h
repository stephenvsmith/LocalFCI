#ifndef SepSetList_H
#define SepSetList_H

#include "sharedFunctions.h"
#include <algorithm>
using namespace Rcpp;

class SepSetList {
public:
  SepSetList(NumericVector &neighbors);

  void changeList(int i,int j,NumericVector sep); // Tested
  void changeList(int i,int j); // Tested

  NumericVector getSepSet(int i,int j); // tested

  bool isPotentialVStruct(int i, int j,int k);
  bool isSeparated(int i,int j,int k);
  
  void printSepSetList(); // tested
  
  List getS() { return S; };
private:
  NumericVector nodes;
  List S;
};

#endif