#include "DAG.h"

using namespace Rcpp;

DAG::DAG(int nodes,StringVector node_names,NumericMatrix adj) :
  Graph::Graph (nodes,node_names,adj)
  {}

DAG::DAG(int nodes) : 
  Graph::Graph(nodes)
  {}

NumericVector DAG::getNeighbors(const int &i,bool &verbose){
  NumericVector neighbors;
  NumericVector parents;
  NumericVector children;
  int p = Graph::size();
  if (verbose){
    Rcout << "FUNCTION get_neighbors_from_dag. Node " << i << std::endl;
  }
  if (p<Graph::getNCol()){
    Rcout << "WARNING: iteration stop value is less than the number of columns in the adj. matrix.\n"; 
  }
  for (int j = 0;j<p;++j){
    if (Graph::getAmatVal(j,i)==1){ 
      parents.push_back(j);
      if (verbose)
        Rcout << "Call from get_neighbors_from_dag. Node " << j << " is a parent.\n";
    } else if (Graph::getAmatVal(i,j)==1){
      children.push_back(j);
      if (verbose)
        Rcout << "Call from get_neighbors_from_dag. Node " << j << " is a child.\n";
    }
  }
  
  NumericVector potential_spouses;
  int current_val;
  for (NumericVector::iterator it = children.begin(); it != children.end(); ++it){
    if (verbose)
      Rcout << "Call from get_neighbors_from_dag. We are evaluating the following child: " << *it << std::endl;
    for (int j = 0; j<p; ++j){
      current_val = Graph::getAmatVal(j,*it);
      if (current_val == 1 & i != j){
        potential_spouses.push_back(j);
        if (verbose)
          Rcout << "Call from get_neighbors_from_dag. Node " << j << " is a potential spouse of node " << i << ".\n";
      }
    }
  }
  
  neighbors = union_(parents,children);
  neighbors = union_(neighbors,potential_spouses);
  neighbors = setdiff(neighbors,NumericVector::create(i));
  std::sort(neighbors.begin(),neighbors.end());
  if (verbose){
    Rcout << "Neighbors of node " << i;
    print_vector_elements_nonames(neighbors,": ","",", ");
    Rcout << "\n\n";
  }
  
  return neighbors;
}

// Retrieves the neighbors of all the target nodes, and excludes the target nodes
// themselves for the final result.
NumericVector DAG::getNeighborsMultiTargets(const NumericVector &targets,bool &verbose){
  NumericVector neighbors;
  int num_targets = targets.length();
  int t;
  
  for (int i = 0; i<num_targets; ++i){
    t = targets(i);
    if (verbose)
      Rcout << "Target: " << t << std::endl;
    if (i == 0){
      neighbors = getNeighbors(t,verbose);
    } else {
      neighbors = union_(neighbors,getNeighbors(t,verbose));
    }
  }
  neighbors = setdiff(neighbors,targets);
  std::sort(neighbors.begin(),neighbors.end());
  if (verbose){
    Rcout << "Total Neighborhood:\n";
    print_vector_elements_nonames(neighbors,"","\n",", ");
  }
  
  return neighbors;
}

// TODO: should probably change all instances of this to just using the function above
NumericVector DAG::getPotentialSepNodes(const int &i,const int &j,bool &verbose){
  NumericVector targets = NumericVector::create(i,j);
  NumericVector potential_seps = getNeighborsMultiTargets(targets,verbose);
  return potential_seps;
}
