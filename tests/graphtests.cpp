using namespace Rcpp;

NumericMatrix check_amat_works(int nodes,StringVector node_names,NumericMatrix adj){
  Graph g(nodes,node_names,adj);
  return g.getAmat();
}

// [[Rcpp::export]]
StringVector check_names_works(int nodes,StringVector node_names,NumericMatrix adj){
  Graph g(nodes,node_names,adj);
  return g.getNodeNames();
}

// [[Rcpp::export]]
void check_dag_object(int nodes,StringVector node_names,NumericMatrix adj){
  DAG g(nodes,node_names,adj);
  int i = 2;
  bool v = false;
  //return g.getNeighbors(i,v);
}


/*** R
set.seed(123)
nodes <- 4
n_names <- letters[1:nodes]
adj <- matrix(sample(c(0,1),nodes^2,replace = TRUE),ncol = nodes)
check_amat_works(nodes,n_names,adj)
check_names_works(nodes,n_names,adj)

check_dag_object(nodes,n_names,adj)
*/
