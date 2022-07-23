#include <chrono>
#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
#include "lfci.h"
#include "lpc.h"

using namespace std::chrono;
using namespace Rcpp;

// [[Rcpp::export]]
List localfci_cpp(NumericMatrix true_dag,arma::mat df,
              NumericVector targets,
              StringVector names,int lmax=3,
              double signif_level = 0.01,
              bool verbose=true){
  // Variable to keep track of timing
  auto start = high_resolution_clock::now();
  
  // Instantiate the Local FCI object
  LocalFCI lfci(true_dag,df,targets,names,lmax,signif_level,verbose);
  
  lfci.run(); 
  
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end-start);
  double total_time = duration.count() / 1e6;
  
  return List::create(
    _["G"]=lfci.getAmat(),
    _["S"]=lfci.getSepSetList(),
    _["NumTests"]=lfci.getNumTests(),
    _["allNodes"]=lfci.getNeighborhood(),
    _["totalSkeletonTime"]=lfci.getTotalSkeletonTime(),
    _["targetSkeletonTimes"]=lfci.getTargetSkeletonTimes(),
    _["algorithmTotalTime"]=lfci.getTotalTime(),
    _["totalTime"]=total_time
  );
}

// [[Rcpp::export]]
List localfci_cpp_pop(NumericMatrix true_dag,
                  NumericVector targets,
                  StringVector names,int lmax=3,
                  bool verbose=true){
  // Variable to keep track of timing
  auto start = high_resolution_clock::now();
  
  // Instantiate the Local FCI object
  LocalFCI lfci(true_dag,targets,names,lmax,verbose);
  
  if (verbose){
    Rcout << "Beginning algorithm over all neighborhoods.\n";
  }
  
  lfci.run();
  
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end-start);
  double total_time = duration.count() / 1e6;
  
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

// [[Rcpp::export]]
List localpc_cpp(NumericMatrix true_dag,arma::mat df,
             NumericVector targets,
             StringVector names,int lmax=3,
             double signif_level = 0.01,
             bool verbose=true){
  // Variable to keep track of timing
  auto start = high_resolution_clock::now();
  
  // Instantiate the Local FCI object
  LocalPC lpc(true_dag,df,targets,names,lmax,signif_level,verbose);
  
  lpc.run(); 
  
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end-start);
  double total_time = duration.count() / 1e6;
  
  return List::create(
    _["G"]=lpc.getAmat(),
    _["S"]=lpc.getSepSetList(),
    _["NumTests"]=lpc.getNumTests(),
    _["allNodes"]=lpc.getNeighborhood(),
    _["targetSkeletonTimes"]=lpc.getTargetSkeletonTimes(),
    _["algorithmTotalTime"]=lpc.getTotalTime(),
    _["totalTime"]=total_time
  );
}

// [[Rcpp::export]]
List localpc_cpp_pop(NumericMatrix true_dag,
                 NumericVector targets,
                 StringVector names,int lmax=3,
                 bool verbose=true){
  // Variable to keep track of timing
  auto start = high_resolution_clock::now();
  
  // Instantiate the Local FCI object
  LocalPC lpc(true_dag,targets,names,lmax,verbose);
  
  if (verbose){
    Rcout << "Beginning algorithm over all neighborhoods.\n";
  }
  
  lpc.run();
  
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end-start);
  double total_time = duration.count() / 1e6;
  
  return List::create(
    _["G"]=lpc.getAmat(),
    _["S"]=lpc.getSepSetList(),
    _["NumTests"]=lpc.getNumTests(),
    _["allNodes"]=lpc.getNeighborhood(),
    _["targetSkeletonTimes"]=lpc.getTargetSkeletonTimes(),
    _["totalTime"]=total_time
  );
}

