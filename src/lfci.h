#ifndef LFCI_H
#define LFCI_H

#include "ConstrainedAlgo.h"

using namespace std::chrono;
using namespace Rcpp;

class LocalFCI : public ConstrainedAlgo {
public:
  LocalFCI(NumericMatrix true_dag,arma::mat df,
           NumericVector targets,
           StringVector names,
           int lmax,
           double signif_level,
           bool verbose,bool estDAG=false);
  
  LocalFCI(NumericMatrix true_dag, // population version
           NumericVector targets,
           StringVector names,
           int lmax,
           bool verbose);
  
  // Accessors
  void getSkeletonTotal();
  void getSkeletonTarget(const size_t &t);
  void getVStructures();
  std::vector<double> getTargetSkeletonTimes() { 
    return target_skeleton_times; 
  };
  double getTotalSkeletonTime() { return total_skeleton_time; };
  NumericVector getRulesCount() { return rules_used; };
  
  // Orientation Rules Helpers
  NumericVector minDiscPath(size_t a,size_t b,size_t c);
  NumericVector minUncovPdPath(size_t alpha,size_t beta,size_t gamma);
  
  // Orientation Rules
  // Rule 1
  void rule1search(size_t beta,size_t alpha,bool &track_changes);
  bool rule1(bool &track_changes);
  // Rule 2
  void rule2search(size_t beta,size_t alpha,
                   bool condition1,bool condition2,bool &track_changes);
  bool rule2(bool &track_changes);
  // Rule 3
  List rule3asearch(size_t beta,size_t alpha);
  void rule3bsearch(const size_t &alpha,const size_t &beta,const size_t &gamma,
                    bool &track_changes);
  bool rule3(bool &track_changes);
  // Rule 4
  bool check_sep_r4(size_t beta,NumericVector md_path);
  bool rule4(bool &track_changes);
  //Rule 8
  bool rule8(bool &track_changes);
  // Rule 9
  bool rule9(bool &track_changes);
  // Rule 10
  bool rule10(bool &track_changes);
  // All rules
  void allRules();
  
  // Function to run the algorithm
  void run();
  
  // Graph conversion
  void convertMixedGraph();
  void convertFinalGraph();
  
private:
  std::map<int,int> node_numbering;
  NumericVector rules_used = NumericVector(11);
  std::vector<double> target_skeleton_times;
  double total_skeleton_time;
};

#endif
