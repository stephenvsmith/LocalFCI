#ifndef GRAPH_H
#define GRAPH_H

#include "sharedFunctions.h"

using namespace Rcpp;

// Base class
class Graph {
public:
  
  // Constructors
  Graph(int nodes,bool verbose=false); // Tested
  Graph(int nodes,StringVector node_names,NumericMatrix adj,bool verbose=false); // Tested
  
  // Fills the adjacency matrix with zeros
  void emptyGraph(); // Tested
  
  // Tested in testGraph.cpp and test_Graph.R
  void printAmat();
  
  // Tested
  // Determines if two nodes are neighbors
  bool areNeighbors(int i,int j){
    return amat(i,j)!=0 || amat(j,i)!=0;
  }
  
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
      stop("Row index is too large");
    } else if (row < 0){
      stop("Row index is negative");
    }
    return amat(row,_);
  }
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getAmatCol(int col){
    if (col>=p){
      stop("Column index is too large");
    } else if (col < 0){
      stop("Column index is negative");
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
    p = m.ncol();
  }
  
  int operator ()(unsigned i,unsigned j) const    {return amat(i,j);}
  double & operator ()(unsigned i, unsigned j) {return amat(i,j);}
  
  // Tested
  void setAmatVal(int i,int j,int val){
    amat(i,j) = val;
  }

protected:
  NumericMatrix amat;
  bool verbose;
   
private:
  int p;
  StringVector names;

};

#endif
