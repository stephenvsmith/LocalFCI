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
           bool verbose,bool estDAG=false);
  
  LocalPC(NumericMatrix true_dag, // population version
           NumericVector targets,
           NumericVector nodes_interest,
           StringVector names,
           int lmax,
           bool verbose);
  
  void getSkeletonTarget(const size_t &t);
  
  using ConstrainedAlgo::getVStructures;
  
  void convertFinalGraph();
  
  void run();
  
  void check();
  
  // Accessors
  std::vector<double> getTargetSkeletonTimes() { return target_skeleton_times; };
  
private:
  std::map<int,int> node_numbering;
  std::vector<double> target_skeleton_times;
};

#endif
