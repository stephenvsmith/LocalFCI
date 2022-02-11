#ifndef LFCI_H
#define LFCI_H

#include <chrono>
#include <algorithm>
#include "DAG.h"
#include "SepSetList.h"
#include "pCorTest.h"
#include "sharedFunctions.h"
#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace std::chrono;
using namespace Rcpp;

class LocalFCI {
public:
  LocalFCI(NumericMatrix true_dag,arma::mat df,
           NumericVector targets,
           StringVector names,int lmax,
           double signif_level,
           bool verbose);
  
  ~LocalFCI(){delete C_tilde; delete true_DAG; delete S;};
  
  void change_S_0_efficient(int i,int j);
  void change_S_efficient(int i,int j,NumericVector sep);
  
  void print_elements();
  void printAmat(){ C_tilde -> printAmat(); };
  bool verbose;
  
  int getSize(){ return p; }
  
  void checkSeparation(int l,int i,int j,NumericMatrix kvals);
  
  void get_skeleton_total();
  void get_skeleton_target(int t);
  
  void get_v_structures_efficient();
  
  // Orientation Rules Helpers
  NumericVector minDiscPath(int a,int b,int c,bool verbose);
  NumericVector minUncovPdPath(int p,int alpha,int beta,int gamma,bool verbose);
  
  // Orientation Rules
  void rule1search(int beta,int alpha,bool &track_changes,bool verbose=false);
  bool rule1(bool &track_changes,bool verbose=false);
  void rule2search(int beta,int alpha,bool condition1,bool condition2,bool &track_changes,bool verbose=false);
  bool rule2(bool &track_changes,bool verbose=false);
  List rule3asearch(int beta,int alpha);
  void rule3bsearch(const int &alpha,const int &beta,const int &gamma,bool &track_changes,bool verbose=false);
  bool rule3(bool &track_changes,bool verbose=false);
  bool check_sep_r4(int beta,NumericVector md_path,bool verbose=false);
  bool rule4(bool &track_changes,bool verbose = false);
  bool rule8(bool &track_changes,bool verbose=false);
  bool rule9(bool &track_changes,bool verbose=false);
  bool rule10(bool &track_changes,bool verbose=false);
  void allRules(bool verbose);
  
  void convertMixedGraph();
  void convertFinalGraph(Graph* g);
  
  // Accessors
  NumericVector getNeighborhood() { return neighborhood; }
  NumericMatrix getAmat() { return C_tilde -> getAmat(); }
  List getSepSetList() { return S -> getS(); };
  int getNumTests() { return num_tests; };
  std::vector<double> getTargetSkeletonTimes() {return target_skeleton_times; };
  double getTotalSkeletonTime() { return total_skeleton_time; };
  double getMostRecentPVal() { return p_vals.back(); };
  NumericVector getAdjacent(int i) { return C_tilde -> getAdjacent(i); };
  
  // Setters (Useful for testing)
  void setAmat(NumericMatrix m){
    C_tilde -> setAmat(m);
  }
  
  void setS(int i,int j,NumericVector k){
    S -> changeList(i,j,k);
  }
  
  void setNeighbors(NumericVector neighbors){
    neighborhood = neighbors;  
  }
  
private:
  int lmax;
  int num_targets;
  int p;
  int n;
  int N;
  double signif_level;
  int num_tests=0;
  NumericVector neighborhood;
  StringVector names;
  Graph* C_tilde;
  DAG* true_DAG;
  SepSetList* S;
  NumericVector sep;
  std::map<int,int> node_numbering;
  arma::mat R;
  std::vector<double> p_vals;
  std::vector<double> target_skeleton_times;
  double total_skeleton_time;
};

#endif