#include "Graph.h"

using namespace Rcpp;

Graph::Graph(int nodes) : p(nodes) {
  Rcout << "Constructing our graph.\n";
  StringVector tmp(nodes);
  names = tmp;
  NumericMatrix tmp1(nodes);
  amat = tmp1;
  std::fill(amat.begin(), amat.end(), 1); //tested
  amat.fill_diag(0); //tested
  Rcout << "Our current matrix:\n";
  print_matrix(amat);
}

NumericVector Graph::getAdjacent(int i){
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
