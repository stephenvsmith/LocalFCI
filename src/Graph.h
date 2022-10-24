#ifndef GRAPH_H
#define GRAPH_H

#include "sharedFunctions.h"

// Base class
class Graph {
public:
  // Constructors
  Graph(size_t nodes,bool verbose=false); 
  Graph(size_t nodes,StringVector node_names,
        NumericMatrix adj,bool verbose=false);
  
  void validateIndex(const size_t &ind) const {
    if (ind < 0){
      stop("Invalid index: negative value");
    } else if (ind >= p){
      stop("Invalid index: too large");
    }
  }
  
  void validateAdjMatrix(const NumericMatrix adj){
    if (adj.nrow()!=adj.ncol()){
      stop("Dimensions of adjacency matrix do not match.");
    }
  }
  
  // Accessors
  int size() { return p; }
  StringVector getNodeNames(){ return names; }
  NumericMatrix getAmat(){ return amat; }
  int getAmatVal(const size_t &i,const size_t &j){
    validateIndex(i); validateIndex(j);
    return amat(i,j);
  }
  int operator ()(const size_t &i,const size_t &j) const { 
    validateIndex(i); validateIndex(j);
    return amat(i,j); 
  }
  
  NumericVector getAmatRow(const size_t &row){
    validateIndex(row);
    return amat(row,_);
  }
  
  NumericVector getAmatCol(const size_t &col){
    validateIndex(col);
    return amat(_,col);
  }
  
  int getNCol(){ return amat.ncol(); }
  int getNRow(){ return amat.nrow(); }
  NumericVector getAdjacent(const size_t &i);
  NumericVector getNonAdjacent(const size_t &i);
  
  // Setters
  void setSize(const size_t &s){ p = s; }
  void setNames(StringVector n){ names = n; }
  void setAmat(NumericMatrix m){ 
    validateAdjMatrix(m); 
    amat = m; 
    p = m.ncol(); 
  }
  double & operator ()(const size_t &i, const size_t &j) {
    return amat(i,j);
  }
  void setAmatVal(const size_t &i,
                  const size_t &j,
                  const size_t &val){
    validateIndex(i); validateIndex(j);
    amat(i,j) = val;
  }
  
  // Fills the adjacency matrix with zeros
  void emptyGraph(); 
  void printAmat();
  // Determines if two nodes are neighbors
  bool areNeighbors(const size_t &i,const size_t &j){
    validateIndex(i); validateIndex(j);
    return amat(i,j)!=0 || amat(j,i)!=0;
  }

protected:
  NumericMatrix amat;
  bool verbose;
   
private:
  size_t p;
  StringVector names;
};

#endif
