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

// [[Rcpp::export]]
NumericMatrix checkAdjMatConversion(NumericMatrix td,arma::mat df,NumericVector t,StringVector names,
                                    NumericMatrix m,NumericVector neighbors){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  lfci.setAmat(m);
  lfci.setNeighbors(neighbors);
  lfci.convertMixedGraph();
  //lfci.printAmat();
  Graph* C_new = new Graph(lfci.getSize());
  C_new -> emptyGraph();
  lfci.convertFinalGraph(C_new);
  C_new = nullptr;
  //lfci.printAmat();
  
  Rcout << "Final\n";
  lfci.print_elements();
  return lfci.getAmat();
}

// [[Rcpp::export]]
List checkSeparationTest(NumericMatrix td,arma::mat df,NumericVector t,StringVector names,
                           int i,int j,int l,NumericVector nodes_to_skip){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  NumericVector edges_i = lfci.getAdjacent(i);
  // Find neighbors of i and j from the current graph C
  NumericVector neighbors = setdiff(union_(edges_i,lfci.getAdjacent(j)),NumericVector::create(i,j));
  neighbors = setdiff(neighbors,nodes_to_skip);
  if (neighbors.length()>= l){
    if (l>0){
      if (neighbors.length() > 1){
        Rcout << "There are " << neighbors.length() << " neighbors.\n";
      } else {
        Rcout << "There is " << neighbors.length() << " neighbor.\n";
      }
    }
    NumericMatrix kvals = combn_cpp(lfci.getNeighborhood()[neighbors],l);
    // check whether nodes i and j are separated by any of the potential separating sets in kvals
    lfci.checkSeparation(l,i,j,kvals);
  }
  
  return List::create(
    _["pval"]=lfci.getMostRecentPVal(),
    _["G"]=lfci.getAmat(),
    _["S"]=lfci.getSepSetList()
  );
}
