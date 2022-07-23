#include "lpc.h"

// [[Rcpp::export]]
int checkInitializeLocalPC(NumericMatrix td,arma::mat df,
                           NumericVector t,StringVector names){
  LocalPC lpc(td,df,t,names,3,0.01,true);
  lpc.check();
  return lpc.getSize();
}


// [[Rcpp::export]]
NumericMatrix checkGetTargetSkel(NumericMatrix td,arma::mat df,
                                 NumericVector t,StringVector names){
  LocalPC lpc(td,df,t,names,3,0.01,true);
  lpc.getSkeletonTarget(t(0));
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkGetVStructures(NumericMatrix td,arma::mat df,
                                  NumericVector t,StringVector names){
  LocalPC lpc(td,df,t,names,3,0.02,true);
  lpc.getSkeletonTarget(t(0));
  lpc.getVStructures();
  return lpc.getAmat();
}

// [[Rcpp::export]]
int checkInitializeLocalPCPop(NumericMatrix td,NumericVector t,
                              StringVector names){
  LocalPC lpc(td,t,names,3,true);
  lpc.check();
  return lpc.getSize();
}

// [[Rcpp::export]]
NumericMatrix checkGetTargetSkelPop(NumericMatrix td,
                                    NumericVector t,StringVector names){
  LocalPC lpc(td,t,names,3,true);
  lpc.getSkeletonTarget(t(0));
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkGetVStructuresPop(NumericMatrix td,
                                     NumericVector t,StringVector names){
  LocalPC lpc(td,t,names,3,true);
  lpc.getSkeletonTarget(t(0));
  lpc.getVStructures();
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLocalPC(NumericMatrix td,arma::mat df,
                           NumericVector t,StringVector names){
  LocalPC lpc(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  // Get the skeleton for each target node and its neighborhood
  std::for_each(t.begin(),t.end(),[&lpc](int t){ lpc.getSkeletonTarget(t); });
  lpc.getVStructures();
  lpc.convertFinalGraph();
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLocalPCPop(NumericMatrix td,
                              NumericVector t,StringVector names){
  LocalPC lpc(td,t,names,3,true);
  std::for_each(t.begin(),t.end(),[&lpc](int t){ lpc.getSkeletonTarget(t); });
  lpc.getVStructures();
  lpc.convertFinalGraph();
  return lpc.getAmat();
}