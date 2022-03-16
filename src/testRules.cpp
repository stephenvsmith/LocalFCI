#include "lfci.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix testRule1(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule1(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule2(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule2(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule3(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule3(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule4(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m,int i,int j,NumericVector k){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  lfci.setS(i,j,k);
  lfci.setS(j,i,k);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule4(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule8(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule8(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule9(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule9(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule10(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.verbose = true;
  lfci.rule10(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testallRules(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  LocalFCI lfci(td,dummy_df,dummy_t,names,3,0.01,false);
  lfci.setAmat(m);
  lfci.verbose = true;
  lfci.allRules();
  return lfci.getAmat();
}









