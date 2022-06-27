#ifndef LFCI_H
#define LFCI_H

#include "constrainedAlgo.h"

using namespace std::chrono;
using namespace Rcpp;

class LocalFCI : public ConstrainedAlgo {
public:
  LocalFCI(NumericMatrix true_dag,arma::mat df,
           NumericVector targets,
           StringVector names,int lmax,
           double signif_level,
           bool verbose);
  
  LocalFCI(NumericMatrix true_dag, // population version
           NumericVector targets,
           StringVector names,int lmax,
           bool verbose);
  
  // Accessors
  void getSkeletonTotal();
  void getSkeletonTarget(int t);
  void getVStructures();
  std::vector<double> getTargetSkeletonTimes() {return target_skeleton_times; };
  double getTotalSkeletonTime() { return total_skeleton_time; };
  
  // Orientation Rules Helpers
  NumericVector minDiscPath(int a,int b,int c); // TODO: remove verbose
  NumericVector minUncovPdPath(int alpha,int beta,int gamma);
  
  // Orientation Rules
  void rule1search(int beta,int alpha,bool &track_changes);
  bool rule1(bool &track_changes);
  void rule2search(int beta,int alpha,bool condition1,bool condition2,bool &track_changes);
  bool rule2(bool &track_changes);
  List rule3asearch(int beta,int alpha);
  void rule3bsearch(const int &alpha,const int &beta,const int &gamma,bool &track_changes);
  bool rule3(bool &track_changes);
  bool check_sep_r4(int beta,NumericVector md_path);
  bool rule4(bool &track_changes);
  bool rule8(bool &track_changes);
  bool rule9(bool &track_changes);
  bool rule10(bool &track_changes);
  void allRules();
  
  // Graph conversion
  void convertMixedGraph();
  void convertFinalGraph(Graph* g);
  
private:
  std::map<int,int> node_numbering;
  std::vector<double> target_skeleton_times;
  double total_skeleton_time;
  // TODO: Add total time
};

#endif