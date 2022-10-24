#include "Graph.h"

Graph::Graph(size_t nodes,StringVector node_names,
             NumericMatrix adj,bool verbose) : 
  p(nodes),names(node_names),amat(adj),verbose(verbose) {
  validateAdjMatrix(adj);
  if (nodes < adj.ncol()){
    warning("Number of nodes < rows and columns of the adjacency matrix.");
    warning("Changing the value to match the adj. matrix.");
    p = adj.ncol();
  }
};

// Initializes a complete graph without names
Graph::Graph(size_t nodes,bool verbose) : 
  p(nodes),verbose(verbose) {
  names = StringVector(nodes);
  amat = NumericMatrix(nodes);
  std::fill(amat.begin(), amat.end(), 1);
  amat.fill_diag(0);
}

void Graph::emptyGraph(){
  std::fill(amat.begin(),amat.end(),0);  
}

NumericVector Graph::getAdjacent(const size_t &i){
  validateIndex(i);
  NumericVector adj_nodes;
  for (size_t j=0;j<p;++j){
    if (amat(i,j)!=0 || amat(j,i)!=0){
      adj_nodes.push_back(j);
    }
  }
  return adj_nodes;
}

// Returns nodes that are not adjacent to i in the graph
NumericVector Graph::getNonAdjacent(const size_t &i){
  validateIndex(i);
  NumericVector non_adj;
  
  for (size_t j=0;j<p;++j){
    if (amat(i,j)==0 && amat(j,i)==0 && j!=i){
      non_adj.push_back(j);
    }
  }
  
  return non_adj;
}

void Graph::printAmat(){
  printMatrix(amat);
}
