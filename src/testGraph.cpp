#include "DAG.h"

using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix check_amat_works(int nodes,StringVector node_names,NumericMatrix adj){
  Graph g(nodes,node_names,adj);
  return g.getAmat();
}

// [[Rcpp::export]]
NumericMatrix check_amat_works_onepar(int nodes){
  Graph g(nodes);
  return g.getAmat();
}

// [[Rcpp::export]]
StringVector check_names_works(int nodes,StringVector node_names,NumericMatrix adj){
  Graph g(nodes,node_names,adj);
  return g.getNodeNames();
}

// [[Rcpp::export]]
List check_dag_object(int nodes,StringVector node_names,NumericMatrix adj){
  DAG g(nodes,node_names,adj);
  int i = 3;
  bool v = false;
  Rcout << "Adjacency Matrix:\n";
  g.printAmat();
  Rcout << "The neighbors of node " << i << " are " << g.getNeighbors(i,v) << std::endl;
  NumericVector t {0,2};
  Rcout << "The neighbors of nodes " << t << " are " << g.getNeighborsMultiTargets(t,v) << std::endl;
  return List::create(
    _["OneNeighbor"]=g.getNeighbors(i,v),
    _["TwoNeighbors"]=g.getNeighborsMultiTargets(t,v)
  );
}

// [[Rcpp::export]]
void check_dag_object2(int nodes){
  DAG g(nodes);
  g.printAmat();
}

// [[Rcpp::export]]
NumericVector check_neighbors_retrieval(int nodes,StringVector node_names,NumericMatrix adj,int t){
  DAG g(nodes,node_names,adj);
  bool v = false;
  
  return g.getNeighbors(t,v);
}

// [[Rcpp::export]]
int check_amat_retrieval(int nodes,StringVector node_names,NumericMatrix adj,int i,int j){
  DAG g(nodes,node_names,adj);
  return g(i,j);
}

// [[Rcpp::export]]
int check_amat_retrieval_function(int nodes,StringVector node_names,NumericMatrix adj,int i,int j){
  DAG g(nodes,node_names,adj);
  return g.getAmatVal(i,j);
}

// [[Rcpp::export]]
NumericVector check_amat_row_retrieval(int nodes,StringVector node_names,NumericMatrix adj,int i){
  DAG g(nodes,node_names,adj);
  return g.getAmatRow(i);
}

// [[Rcpp::export]]
NumericVector check_amat_col_retrieval(int nodes,StringVector node_names,NumericMatrix adj,int j){
  DAG g(nodes,node_names,adj);
  return g.getAmatCol(j);
}

// [[Rcpp::export]]
List check_adjacent_non_adjacent(int nodes,StringVector node_names,NumericMatrix adj,int i){
  DAG g(nodes,node_names,adj);
  return List::create(
    _["adj"]=g.getAdjacent(i),
    _["nonadj"]=g.getNonAdjacent(i)
  );
}

// [[Rcpp::export]]
NumericVector check_non_adjacent_solo(int nodes,StringVector node_names,NumericMatrix adj,int i){
  Graph g(nodes,node_names,adj);
  return g.getNonAdjacent(i);
}

// [[Rcpp::export]]
int check_amat_setval(int nodes,StringVector node_names,NumericMatrix adj,int i,int j,int val){
  Graph g(nodes,node_names,adj);
  g.setAmatVal(i,j,val);
  //g(i,j)=val;
  
  return g.getAmatVal(i,j);
}

// [[Rcpp::export]]
bool checkIfNeighbors(int nodes,StringVector node_names,NumericMatrix adj,int i,int j){
  Graph g(nodes,node_names,adj);
  return g.areNeighbors(i,j);
}

// [[Rcpp::export]]
NumericMatrix checkEmptyGraph(int p){
  Graph g(p);
  g.printAmat();
  g.emptyGraph();
  return g.getAmat();
}

// [[Rcpp::export]]
bool checkAcyclicity(int nodes,StringVector node_names,NumericMatrix adj){
  DAG g(nodes,node_names,adj);
  return g.isAcyclic();
}

// [[Rcpp::export]]
bool checkIsAncestor(int nodes,StringVector node_names,NumericMatrix adj,int desc,int anc){
  DAG g(nodes,node_names,adj);
  return g.isAncestor(desc,anc);
}

