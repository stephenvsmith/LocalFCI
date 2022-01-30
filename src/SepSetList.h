#ifndef SepSetList_H
#define SepSetList_H

#include "sharedFunctions.h"
using namespace Rcpp;

class SepSetList {
public:
  SepSetList(NumericVector &neighbors);
  
  //void changeListTrue(int i,int j,NumericVector sep);
  void changeListEfficient(int i,int j,NumericVector sep); // Tested
  void changeListEfficient(int i,int j); // Tested | TODO: INCORPORATE THIS INTO THE REST OF THE CODE
  
  //NumericVector getSepSetEfficient(int i,int j); // tested
  NumericVector getSepSetTrue(int i,int j); // tested

  //bool isSeparatedEfficient(int i, int j,int k);
  bool isSeparatedTrue(int i, int j,int k);
  
  void printSepSetList(); // tested
private:
  NumericVector nodes;
  List S;
};

#endif