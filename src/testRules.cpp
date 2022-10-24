#include "lfci.h"
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix testRule1(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule1(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule2(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule2(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule3(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule3(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule4(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m,int i,int j,NumericVector k){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  lfci.setS(i,j,k);
  lfci.setS(j,i,k);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule4(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule8(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule8(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule9(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule9(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testRule10(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  bool track_changes=false;
  lfci.setVerboseTrue();
  lfci.rule10(track_changes);
  Rcout << "Track changes: " << track_changes << std::endl;
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testAllRules(NumericMatrix td,arma::mat dummy_df,NumericVector dummy_t,StringVector names,NumericMatrix m){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,dummy_df,dummy_t,nodes_interest,names,3,0.01,false);
  lfci.setAmat(m);
  lfci.setVerboseTrue();
  lfci.allRules();
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix testConvertMixed(NumericMatrix td,NumericVector t,StringVector names,NumericMatrix m,NumericVector v){
  NumericVector nodes_interest;
  for (int i=0;i<td.ncol();++i){
    nodes_interest.push_back(i);
  }
  LocalFCI lfci(td,t,nodes_interest,names,3,true);
  lfci.setAmat(m);
  lfci.setNeighbors(v);
  lfci.convertMixedGraph();
  return lfci.getAmat();
}


