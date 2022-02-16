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
  Graph(int nodes); // Tested
  Graph(int nodes,StringVector node_names,NumericMatrix adj) : 
  p(nodes),names(node_names),amat(adj) {}; // Tested
  
  // Fills the adjacency matrix with zeros
  void emptyGraph();
  
  // Accessors
  int size() {
    return p;
  }
  
  // Tested
  StringVector getNodeNames(){
    return names;
  }
  
  // Tested
  NumericMatrix getAmat(){
    return amat;
  }
  
  // Tested
  int getAmatVal(int i,int j){
    if (i<0 || j<0){
      stop("Invalid negative index");
    }
    if (i>=p || j>=p){
      Rcout << "i = " << i << " | j = " << j << " | Number of Nodes=" << p << std::endl; 
      stop("Invalid index: too large");
    }
    return amat(i,j);
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getAmatRow(int row){
    if (row>=p){
      stop("Row value too large\n");
    }
    return amat(row,_);
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getAmatCol(int col){
    if (col>=p){
      stop("Column value too large\n");
    }
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
  
  int operator ()(unsigned i,unsigned j) const    {return amat(i,j);}
  double & operator ()(unsigned i, unsigned j) {return amat(i,j);}
  
  void setAmatVal(int i,int j,int val){
    amat(i,j) = val;
  }
  
private:
  int p;
  StringVector names;
  NumericMatrix amat;
};

#endif