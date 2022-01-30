#include "../src/lfci.h"

// [[Rcpp::export]]
void check_object_works(NumericMatrix true_dag,arma::mat df,
                        NumericVector targets,
                        StringVector names,int lmax,
                        double signif_level,
                        bool verbose){
  LocalFCI test(true_dag,df,targets,names,lmax,signif_level,verbose);

  test.get_skeleton_total();
  test.print_elements();
}

/***R
library(LocalFCI)
check_object_works(asiaDAG,as.matrix(asiadf),c(1,4),colnames(asiaDAG),3,0.01,FALSE)
*/