#include "MBList.h"

// The child of node x in the matrix providing Markov Blanket 
// information is included in the MB of x.
NumericVector getMBFromMat(NumericMatrix mb_mat,size_t x){
  size_t p = mb_mat.nrow();
  NumericVector mb_vec = NumericVector::create();
  for (size_t i=0;i<p;++i){
    if (mb_mat(x,i)!=0 || mb_mat(i,x)!=0){
      mb_vec.push_back(i);
    }
  }
  return mb_vec;
}

bool MBList::isInMB(size_t target,size_t i){
  if (mb_list.count(i)==0){
    stop("%i is not an element of the map.\n",i);
  }
  return isMember(mb_list.find(target)->second,i);
}

// Sample version
MBList::MBList(NumericVector node_vec,NumericMatrix mb_mat,bool verbose):
  verbose(verbose){
  std::sort(node_vec.begin(),node_vec.end());
  for (size_t node : node_vec){
    mb_list.insert(pair<size_t,NumericVector>(node,getMBFromMat(mb_mat,node)));
  }
  size = node_vec.size();
  if (verbose){
    printMBs();
  }
}

// Population version
MBList::MBList(NumericVector node_vec,NumericMatrix true_dag,size_t p,bool verbose):
  verbose(verbose){
  StringVector node_names = StringVector::create();
  makeNodeNames(p,node_names);
  DAG* my_dag = new DAG(p,node_names,true_dag,verbose);
  NumericVector first_order_neighbors = NumericVector::create();
  NumericVector mb;
  for (size_t node : node_vec){
    mb = my_dag->getNeighbors(node,false);
    mb_list.insert(pair<size_t,NumericVector>(node,mb));
    first_order_neighbors = union_(first_order_neighbors,mb);
  }
  // remove nodes already covered
  first_order_neighbors = setdiff(first_order_neighbors,node_vec);
  for (size_t node : first_order_neighbors){
    mb_list.insert(pair<size_t,NumericVector>(node,my_dag->getNeighbors(node,false)));
  }
  size = node_vec.size() + first_order_neighbors.size();
  if (verbose){
    printMBs();
  }
  delete my_dag;
}

/*
 * Returns the union of the target neighborhoods (Markov Blankets)
 */
NumericVector MBList::getMBMultipleTargets(NumericVector targets,
                                           bool include_targets,
                                           bool exclude_targets){
  if (targets.size()==0){
    return(NumericVector::create());
  }
  if (include_targets && exclude_targets){
    warning("Inclusion/Exclusion of targets are conflicting. Exclusion takes precedence.");
  }
  NumericVector neighbors;
  if (include_targets){
    if (verbose){
      Rcout << "We are including the target variables in the final set.\n";
    }
    neighbors = targets;
  }
  for (auto t : targets){
    if (verbose){
      Rcout << "Node: " << t << std::endl;
    }
    neighbors = union_(neighbors,getMB(t));
  }
  if (exclude_targets){
    if (verbose){
      Rcout << "Removing targets from final set\n";
    }
    neighbors = setdiff(neighbors,targets);
  }
  std::sort(neighbors.begin(),neighbors.end());
  if (verbose){
    Rcout << "All nodes from neighborhoods:\n";
    printVecElementsNoNames(neighbors,"","\n",", ");
  }
  return neighbors;
}

void MBList::printMBs(){
  Rcout << "MBList Size: " << size << endl;
  Rcout << "Markov Blankets:\n";
  
  for (auto const &it : mb_list){
    Rcout << it.first << ": ";
    printVecElementsNoNames(it.second);
    Rcout << endl;
  }
}
