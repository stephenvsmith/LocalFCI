#include "lfci.h"
using namespace Rcpp;


// [[Rcpp::export]]
void initializeLocalFCI(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.print_elements();
}

// [[Rcpp::export]]
NumericMatrix checkSkeletonTotal(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.get_skeleton_total();
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkSkeletonBoth(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.get_skeleton_total();
  // Get the skeleton for each target node and its neighborhood
  std::for_each(t.begin(),t.end(),[&lfci](int t){ lfci.get_skeleton_target(t); });
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkVStruct(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.get_skeleton_total();
  // Get the skeleton for each target node and its neighborhood
  std::for_each(t.begin(),t.end(),[&lfci](int t){ lfci.get_skeleton_target(t); });
  lfci.get_v_structures_efficient();
  return lfci.getAmat();
}
