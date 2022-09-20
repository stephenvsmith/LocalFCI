#ifndef DAG_H
#define DAG_H

#include "Graph.h"
#include "sharedFunctions.h"
#include <algorithm>

using namespace Rcpp;

class DAG : public Graph {
public:
  // Need to make a warning if there is a cycle or any undirected edges when constructing
  // Need to make a warning (or stop) if there are adj. mat entries not equal to 1 or 0
  DAG(unsigned int nodes,bool verbose=false);
  DAG(unsigned int nodes,StringVector node_names,
      NumericMatrix adj,bool estDAG=false,bool verbose=false);
  
  void getNonIncidentNodes(std::vector<int> &v);
  bool isAcyclic();
  
  // Obtain the neighbors of a (multiple) target node(s)
  // where a neighbor is either adjacent or a spouse
  NumericVector getParents(const unsigned int &i);
  NumericVector getChildren(const unsigned int &i);
  NumericVector getNeighbors(const unsigned int &i,bool &verbose);
  NumericVector getNeighborsMultiTargets(const NumericVector &targets,
                                         bool &verbose);
  
  bool inNeighborhood(const unsigned int &i,const unsigned int &j);
  
  bool isAncestor(const unsigned int &desc,const unsigned int &anc);
  
private:
  bool estDAG=false;
};

#endif
