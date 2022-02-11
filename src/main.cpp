#include <chrono>
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
#include "lfci.h"

using namespace std::chrono;
using namespace Rcpp;

// [[Rcpp::export]]
List fci(NumericMatrix true_dag,arma::mat df,
         NumericVector targets,
         StringVector names,int lmax=3,
         double signif_level = 0.05,
         bool verbose=true){
  // Variable to keep track of timing
  auto start = high_resolution_clock::now();
  
  // Instantiate the Local FCI object
  LocalFCI lfci(true_dag,df,targets,names,lmax,signif_level,verbose);
  
  lfci.get_skeleton_total(); // Finding the skeleton for the complete undirected graph on X_T U N_T
  
  // Track time for target skeleton estimation
  // Get the skeleton for each target node and its neighborhood
  std::for_each(targets.begin(),targets.end(),[&lfci](int t){ lfci.get_skeleton_target(t); });
  
  lfci.get_v_structures_efficient();

  lfci.allRules(verbose);
  lfci.convertMixedGraph();
  Graph* C_new = new Graph(lfci.getSize());
  C_new -> emptyGraph();
  lfci.convertFinalGraph(C_new); // This pointer is taken care of and set to nullptr inside function
  
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end-start);
  double total_time = duration.count() / 1000000.;
  
  return List::create(
    _["G"]=lfci.getAmat(),
    _["S"]=lfci.getSepSetList(),
    _["NumTests"]=lfci.getNumTests(),
    _["allNodes"]=lfci.getNeighborhood(),
    _["totalSkeletonTime"]=lfci.getTotalSkeletonTime(),
    _["targetSkeletonTimes"]=lfci.getTargetSkeletonTimes(),
    _["totalTime"]=total_time
  );
}

