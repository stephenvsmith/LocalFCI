#include "DAG.h"

using namespace Rcpp;

DAG::DAG(int nodes,StringVector node_names,NumericMatrix adj,bool verbose) :
  Graph::Graph (nodes,node_names,adj,verbose)
  {}

DAG::DAG(int nodes,bool verbose) : 
  Graph::Graph(nodes,verbose)
  {}

void DAG::getNonIncidentNodes(std::vector<int> &v){
  int p = size();
  for (int j=0;j<p;++j){
    // print_vector_elements_nonames(getAmatCol(j));
    // Rcout << std::endl;
    if (is_true(all(getAmatCol(j)==0))){
      //Rcout << "Adding " << j << " to S." << std::endl;
      v.push_back(j);
    }
  }
}

bool checkAllZeroes(NumericMatrix &A){
  int p = A.nrow();
  for (int i=0;i<p;++i){
    for (int j=0;j<p;++j){
      if (A(i,j)==1){
        //Rcout << "There is still an edge between " << i << " and " << j << std::endl;
        return false;
      }
    }
  }
  return true;
}

// Kahn's algorithm for a topological sort
// If the graph has a topological sort, then there are no cycles
// Otherwise, the graph has at least one cycle.
bool DAG::isAcyclic(){
  int p = size();
  int n;
  if (p==0){
    return true;
  }
  NumericMatrix tmp = clone(getAmat());
  std::vector<int> L;
  std::vector<int> S;
  
  //Rcout << "Size of S = " << S.size() << std::endl;
  getNonIncidentNodes(S);
  //Rcout << "Size of S = " << S.size() << std::endl;
  
  while (!S.empty()){
    n = S.back();
    S.pop_back();
    L.push_back(n);
    //Rcout << "n = " << n << std::endl;
    for (int i=0;i<p;++i){
      if (tmp(n,i)==1){
        //Rcout << "Removing edge between " << n << " and " << i << std::endl;
        tmp(n,i)=0;
        // if i has no other incoming edges, insert into S
        //print_vector_elements_nonames(tmp(_,i));
        //Rcout << std::endl;
        if (is_true(all(tmp(_,i)==0))){
          //Rcout << "Adding " << i << " to S\n";
          S.push_back(i);
        }
      }
    }
  }
  
  return checkAllZeroes(tmp);
}

NumericVector DAG::getNeighbors(const int &i,bool &verbose){
  NumericVector neighbors;
  NumericVector parents;
  NumericVector children;
  int p = Graph::size();
  if (verbose){
    Rcout << "FUNCTION get_neighbors_from_dag. Node " << i << std::endl;
  }
  
  if (i < 0 || i >= p){
    stop("Invalid index (i = %i, p = %i)",i,p);
  }
  
  for (int j = 0;j<p;++j){
    if (amat(j,i)==1){ 
      parents.push_back(j);
      if (verbose)
        Rcout << "Call from get_neighbors_from_dag. Node " << j << " is a parent.\n";
    } else if (amat(i,j)==1){
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
      current_val = amat(j,*it);
      if (current_val == 1 && i != j){
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

bool DAG::inNeighborhood(int i,int j){
  // We consider a node in the same neighborhood as itself
  if (i==j){
    return true;
  }
  // This checks for adjacency
  if (Graph::areNeighbors(i,j)){
    return true;
  }
  // Find children of both nodes
  int p = Graph::size();
  
  // Determining if i and j are spouses
  for (int k = 0;k<p;++k){
    if (amat(i,k)==1 && amat(j,k)==1){
      if (amat(k,i)==0 && amat(k,j)==0){
        return true;
      }
    }
  }
  return false;
}

NumericVector DAG::getParents(int i){
  int p = Graph::size();
  NumericVector parents;
  for (int j=0;j<p;++j){
    if (getAmatVal(j,i)==1 && amat(i,j)==0){
      parents.push_back(j);
    }
  }
  return parents;
}

NumericVector DAG::getChildren(int i){
  int p = Graph::size();
  NumericVector children;
  for (int j=0;j<p;++j){
    if (getAmatVal(i,j)==1 && amat(j,i)==0){
      children.push_back(j);
    }
  }
  return children;
}

bool DAG::isAncestor(int desc,int anc){
  NumericVector current_ancestors;
  NumericVector next_level_ancestors;
  current_ancestors = getParents(desc);
  int level=1;
  
  while (current_ancestors.size()>0){
    if (isMember(current_ancestors,anc)){
      if (verbose){
        Rcout << anc << " is an ancestor of " << desc << " " << level << " levels up.\n";
      }
      return true;
    }
    std::for_each(current_ancestors.begin(),current_ancestors.end(),
                  [&next_level_ancestors,this](int node){
                    next_level_ancestors = union_(next_level_ancestors,getParents(node));
                  });
    current_ancestors = next_level_ancestors;
    next_level_ancestors = NumericVector::create();
    ++level;
    
  }
  return false;
}

