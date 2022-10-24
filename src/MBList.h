#ifndef MBLIST_H
#define MBLIST_H

#include "DAG.h" // Needed for true_DAG

using std::map;
using std::pair;
using std::sort;
using std::endl;

class MBList{
public:
  // Sample version constructor with vector of nodes and matrix of nodes in MB
  MBList(NumericVector node_vec,NumericMatrix mb_mat,bool verbose=false);
  
  // Population version constructor with true DAG
  MBList(NumericVector node_vec,NumericMatrix true_dag,size_t p,bool verbose=false);
  
  // Accessors
  NumericVector getMB(size_t i){
    if (mb_list.count(i)==0){
      stop("%i is not an element of the map.\n",i);
    }
    return mb_list.find(i)->second;
  }
  
  /*
   * include_targets argument specifies that we will return targets U nbhd(targets)
   * exclude_targets argument specifies that we will remove any targets which appear
   * in the neighborhood of another target
   * exclude_targets will take precedence
   */
  NumericVector getMBMultipleTargets(NumericVector targets,
                                     bool include_targets=false,
                                     bool exclude_targets=false);
  
  size_t getSize(){
    return size;
  }
  
  // Determine whether a node is in another node's MB
  bool isInMB(size_t target,size_t i);
  
  // Print Markov Blankets
  void printMBs();
  
  // Silences output
  bool silencer(){
    bool tmp = verbose;
    verbose = false;
    return tmp;
  }
  
  void removeSilencer(bool v){
    verbose = v;
  }
  
private:
  map<size_t,NumericVector> mb_list;
  size_t size;
  bool verbose;
};

#endif
