#ifndef DAG_H
#define DAG_H

#include "Graph.h"

using namespace Rcpp;

class DAG : public Graph {
public:
  // Need to make a warning if there is a cycle or any undirected edges when constructing
  
  DAG(int nodes);
  DAG(int nodes,StringVector node_names,NumericMatrix adj);
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getNeighbors(const int &i,bool &verbose);
  
  // Tested in graphtests.cpp and test_Graph.R
  NumericVector getNeighborsMultiTargets(const NumericVector &targets,bool &verbose);
  
  // Basically tested, but is a redundant function
  NumericVector getPotentialSepNodes(const int &i,const int &j,bool &verbose);
  
  // TODO: CHECK ACYCLICITY
};

#endif