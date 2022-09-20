#include "DAG.h"
#include "sharedFunctions.h"

using namespace Rcpp;

DAG::DAG(unsigned int nodes,StringVector node_names,
         NumericMatrix adj,bool estDAG,bool verbose) :
  Graph::Graph (nodes,node_names,adj,verbose),estDAG(estDAG)
  {}

// Makes a graph without any edges
DAG::DAG(unsigned int nodes,bool verbose) : 
  Graph::Graph(nodes,verbose) {
    emptyGraph();
  }

// Helpers for function determining acyclicity
// Adds nodes to v which have no incoming edges in the DAG
void DAG::getNonIncidentNodes(std::vector<int> &v){
  int p = size();
  for (int j=0;j<p;++j){
    if (is_true(all(getAmatCol(j)==0))){
      v.push_back(j);
    }
  }
}

// Returns true if there are no edges in adj. matrix A
bool checkAllZeroes(NumericMatrix &A){
  int p = A.nrow();
  for (int i=0;i<p;++i){
    for (int j=0;j<p;++j){
      if (A(i,j)!=0){
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
  int n; // takes the value of a node w/o an incoming edge
  if (p==0){
    return true;
  }
  NumericMatrix tmp = clone(getAmat());
  std::vector<int> L; // records checked nodes
  std::vector<int> S; // records nodes without incoming edges
  
  getNonIncidentNodes(S);
  
  while (!S.empty()){
    n = S.back();
    S.pop_back();
    L.push_back(n);
    // Remove all edges from n to another node
    for (int i=0;i<p;++i){
      if (tmp(n,i)==1){
        tmp(n,i)=0;
        // if i has no other incoming edges, insert into S
        if (is_true(all(tmp(_,i)==0))){
          S.push_back(i);
        }
      }
    }
  }
  // If there are still edges, then there is a cycle
  return checkAllZeroes(tmp);
}

NumericVector DAG::getParents(const unsigned int &i){
  validateIndex(i);
  int p = Graph::size();
  NumericVector parents;
  for (int j=0;j<p;++j){
    if (amat(j,i)==1 && amat(i,j)==0){
      parents.push_back(j);
    }
  }
  return parents;
}

NumericVector DAG::getChildren(const unsigned int &i){
  validateIndex(i);
  int p = Graph::size();
  NumericVector children;
  for (int j=0;j<p;++j){
    if (amat(i,j)==1 && amat(j,i)==0){
      children.push_back(j);
    }
  }
  return children;
}

// Returns the parents, children, and spouses of node i
// Differs from Graph::getAdjacent b/c it returns spouse nodes
NumericVector DAG::getNeighbors(const unsigned int &i,bool &verbose){
  validateIndex(i);
  NumericVector neighbors;
  NumericVector parents;
  NumericVector children;
  int p = Graph::size();
  if (verbose){
    Rcout << "FUNCTION getNeighbors. Node " << i << std::endl;
  }
  // Obtain parents and children of i
  for (int j=0;j<p;++j){
    if (amat(j,i)==1){ 
      parents.push_back(j);
      if (verbose){
        Rcout << "Call from getNeighbors. Node " << j << " is a parent.\n";
      }
    } else if (amat(i,j)==1){
      children.push_back(j);
      if (verbose){
        Rcout << "Call from getNeighbors. Node " << j << " is a child.\n";
      }
    }
  }
  // Create vector to store parents U children
  neighbors = union_(parents,children);
  // If we have a DAG with estimated Markov Blankets encoded,
  // We should not include spouses in the set of neighbors
  if (!estDAG){
    // Find nonadjacent common parents with i (spouses)
    NumericVector potential_spouses;
    int current_val;
    for (NumericVector::iterator it = children.begin(); 
         it != children.end(); ++it){
      if (verbose){
        Rcout << "Call from getNeighbors. We are evaluating the following child: " << *it << std::endl;
      }
      for (int j=0;j<p;++j){
        current_val = amat(j,*it);
        // We don't check for adjacency b/c those nodes will be picked up
        // in the parent or the child sets already.
        if (current_val == 1 && i != j){
          potential_spouses.push_back(j);
          if (verbose)
            Rcout << "Call from getNeighbors. Node " << j << " is a potential spouse of node " << i << ".\n";
        }
      }
    }
    neighbors = union_(neighbors,potential_spouses);
  } else {
    if (verbose){
      Rcout << "Using Estimated Markov Blankets => Not identifying spouses from Reference DAG\n";
    }
  }

  std::sort(neighbors.begin(),neighbors.end());
  if (verbose){
    Rcout << "Neighbors of node " << i;
    printVecElementsNoNames(neighbors,": ","",", ");
    Rcout << "\n\n";
  }
  
  return neighbors;
}

// Retrieves the neighbors of all the target nodes, and excludes the target nodes
// themselves for the final result.
NumericVector DAG::getNeighborsMultiTargets(const NumericVector &targets,
                                            bool &verbose){
  NumericVector neighbors;
  int num_targets = targets.length();
  
  for (auto t : targets){
    validateIndex(t);
    if (verbose){
      Rcout << "Target: " << t << std::endl;
    }
    neighbors = union_(neighbors,getNeighbors(t,verbose));
  }

  // Remove target nodes from final vector
  neighbors = setdiff(neighbors,targets);
  std::sort(neighbors.begin(),neighbors.end());
  if (verbose){
    Rcout << "Total Neighborhood:\n";
    printVecElementsNoNames(neighbors,"","\n",", ");
  }
  
  return neighbors;
}

// Returns true if i and j are in the same neighborhood 
// (i.e. one is the parent of another, or they share a common child)
// for this function, we consider a node in the same nbhd as itself
bool DAG::inNeighborhood(const unsigned int &i,
                         const unsigned int &j){
  validateIndex(i); validateIndex(j);
  // We consider a node in the same neighborhood as itself
  if (i==j){
    return true;
  }
  // This checks for adjacency
  if (Graph::areNeighbors(i,j)){
    return true;
  }
  // Check for spouses if we are using a true DAG
  if (!estDAG){
    // Find children of both nodes
    int p = Graph::size();
    
    // Determining if i and j are spouses
    // Don't need to check for adjacency since that has already been checked
    for (int k = 0;k<p;++k){
      if (amat(i,k)==1 && amat(j,k)==1){
        return true;
      }
    }
  }
  return false;
}

bool DAG::isAncestor(const unsigned int &desc,const unsigned int &anc){
  validateIndex(desc); validateIndex(anc);
  if (desc==anc){
    return false;
  }
  StringVector node_names = getNodeNames();
  NumericVector current_ancestors;
  NumericVector next_level_ancestors;
  current_ancestors = getParents(desc);
  int level=1;
  
  while (current_ancestors.size()>0){
    if (isMember(current_ancestors,anc)){
      if (verbose){
        Rcout << node_names(anc) << " is an ancestor of " << node_names(desc) << " " << level << " levels up.\n";
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

