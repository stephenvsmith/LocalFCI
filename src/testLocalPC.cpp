#include "lpc.h"

// [[Rcpp::export]]
int checkInitializeLocalPC(NumericMatrix td,arma::mat df,
                           NumericVector t,StringVector names){
  LocalPC lpc(td,df,t,names,3,0.01,true);
  lpc.check();
  return lpc.getSize();
}
