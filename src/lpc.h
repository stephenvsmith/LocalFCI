#ifndef LPC_H
#define LPC_H

#include "ConstrainedAlgo.h"
// for tracking time
using namespace std::chrono;

class LocalPC : public ConstrainedAlgo {
public:
  LocalPC(NumericMatrix true_dag,arma::mat df,
           NumericVector targets,
           NumericVector nodes_interest,
           StringVector names,
           int lmax,
           double signif_level,
           bool verbose,bool estDAG=false); // tested
  
  LocalPC(NumericMatrix true_dag, // population version
           NumericVector targets,
           NumericVector nodes_interest,
           StringVector names,
           int lmax,
           bool verbose); // tested
  
  void getSkeletonTarget(const size_t &t); // tested
  
  using ConstrainedAlgo::getVStructures; // tested
  
  void convertFinalGraph(); // tested
  
  void run(); // tested
  
  // Accessors
  std::vector<double> getTargetSkeletonTimes() { return target_skeleton_times; };
  
private:
  std::map<int,int> node_numbering;
  std::vector<double> target_skeleton_times;
};

#endif
