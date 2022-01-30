#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
#include "lfci.h"

using namespace Rcpp;

// [[Rcpp::export]]
List fci(NumericMatrix true_dag,arma::mat df,
         NumericVector targets,
         StringVector names,int lmax=3,
         double signif_level = 0.05,
         bool verbose=true){
  // Variables for reference
  int num_targets = targets.length();
  
  // Instantiate the Local FCI object
  LocalFCI lfci(true_dag,df,targets,names,lmax,signif_level,verbose);
  
  lfci.get_skeleton_total(); // Finding the skeleton for the complete undirected graph on X_T U N_T
  
  // Get the skeleton for each target node and its neighborhood
  std::for_each(targets.begin(),targets.end(),[&lfci](int t){ lfci.get_skeleton_target(t); });
  
  lfci.get_v_structures_efficient();

  lfci.allRules(verbose);
  lfci.convertMixedGraph();
  //NumericMatrix Gfinal(p);
  //NumericVector neighborhood = v_struct["neighborhood"];
  
  //makeFinalGraph(Gfinal,G,neighborhood);
  
  return List::create(
    _["tmp"]=lfci.getNeighborhood()
    /*_["G"]=Gfinal,
    _["S"]=v_struct["S"],
    _["NumTests"]=v_struct["NumTests"],
    _["neighborhood"]=neighborhood*/
  );
}

