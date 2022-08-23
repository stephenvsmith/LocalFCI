#include "Graph.h"

using namespace Rcpp;

Graph::Graph(int nodes,StringVector node_names,NumericMatrix adj,bool verbose) : 
  p(nodes),names(node_names),amat(adj),verbose(verbose) {
  if (adj.nrow()!=adj.ncol()){
    stop("Dimensions of adjacency matrix do not match.");
  }
  if (nodes < adj.ncol()){
    warning("Given number of nodes is smaller than the number given by the rows and columns of the adjacency matrix. Changing the value to match the adj. matrix.");
    p = adj.ncol();
  }
};

Graph::Graph(int nodes,bool verbose) : p(nodes),verbose(verbose) {
  StringVector tmp(nodes);
  names = tmp;
  NumericMatrix tmp1(nodes);
  amat = tmp1;
  std::fill(amat.begin(), amat.end(), 1); //tested
  amat.fill_diag(0); //tested
}

void Graph::emptyGraph(){
  std::fill(amat.begin(),amat.end(),0);  
}

NumericVector Graph::getAdjacent(int i){
  if (i < 0 || i>=p){
    stop("Call from getAdjacent: invalid index (i=%i, p=%i)",i,p);
  }
  NumericVector current_edges;
  for (int j=0;j<p;++j){
    if (amat(i,j)==1 || amat(j,i)==1){
      current_edges.push_back(j);
    }
  }
  return current_edges;
}

// Returns nodes that are not adjacent to i in the estimated skeleton
NumericVector Graph::getNonAdjacent(int i){
  if (i < 0 || i>=p){
    stop("Call from getNonAdjacent: invalid index (i=%i, p=%i)",i,p);
  }
  NumericVector final;
  
  for (int j=0;j<p;++j){
    if (amat(i,j)==0 && amat(j,i)==0 && j!=i){
      final.push_back(j);
    }
  }
  
  return final;
}

void Graph::printAmat(){
  print_matrix(amat);
}
