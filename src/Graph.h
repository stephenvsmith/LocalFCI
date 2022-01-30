#ifndef GRAPH_H
#define GRAPH_H

#include "sharedFunctions.h"
#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

// Base class
class Graph {
public:
  
  // Constructors
  Graph(int nodes); // Tested in graphtests.cpp and test_Graph.R
  Graph(int nodes,StringVector node_names,NumericMatrix adj) : 
  p(nodes),names(node_names),amat(adj) {}; // Tested in graphtests.cpp and test_Graph.R
  
  // Accessors
  int size() {
    return p;
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  StringVector getNodeNames(){
    return names;
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericMatrix getAmat(){
    return amat;
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  int getAmatVal(int i,int j){
    return amat(i,j);
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getAmatRow(int row){
    return amat(row,_);
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getAmatCol(int col){
    return amat(_,col);
  }
  
  int getNCol(){
    return amat.ncol();
  }
  
  int getNRow(){
    return amat.nrow();
  }
  // Tested in graphtests.cpp and test_Graph.R
  void printAmat();
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getAdjacent(int i);
  NumericVector getNonAdjacent(int i);
  
  // Setters
  void setSize(int s){
    p = s;
  }
  
  void setNames(StringVector n){
    names = n;
  }
  
  void setAmat(NumericMatrix m){
    amat = m;
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  void setAmatVal(int i,int j,int val){
    amat(i,j) = val;
  }
  
private:
  int p;
  StringVector names;
  NumericMatrix amat;
};

#endif