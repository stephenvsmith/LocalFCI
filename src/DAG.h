#ifndef DAG_H
#define DAG_H

#include "Graph.h"
#include "sharedFunctions.h"
#include <algorithm>

using namespace Rcpp;

class DAG : public Graph {
public:
  // Need to make a warning if there is a cycle or any undirected edges when constructing
  
  DAG(int nodes,bool verbose=false);
  DAG(int nodes,StringVector node_names,NumericMatrix adj,bool verbose=false);
  
  void getNonIncidentNodes(std::vector<int> &v);
  bool isAcyclic();
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getNeighbors(const int &i,bool &verbose);
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getNeighborsMultiTargets(const NumericVector &targets,bool &verbose);
  
  bool inNeighborhood(int i,int j);
  
  NumericVector getParents(int i);
  NumericVector getChildren(int i);
  bool isAncestor(int desc,int anc);

};

#endif
