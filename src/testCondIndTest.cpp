#include "lfci.h"
using namespace Rcpp;

// [[Rcpp::export]]
List testCondInd(arma::mat R,const int &i,const int &j,const arma::uvec &k,const int &n,const double &signif_level){
  arma::uvec sep_arma;
  NumericVector sep;
  List test_result;

  sep = NA_REAL;
  Rcout << "Size of arma vector when l=0: " << sep_arma.size() << std::endl;
  test_result = condIndTest(R,i,j,sep_arma,n,signif_level);
  
  return test_result;
}