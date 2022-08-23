#include "lfci.h"
using namespace Rcpp;


// [[Rcpp::export]]
void initializeLocalFCI(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.print_elements();
}

// [[Rcpp::export]]
void initializeLocalFCIPop(NumericMatrix td,NumericVector t,StringVector names){
  LocalFCI lfci(td,t,names,3,true);
  Rcout << "\n\n";
  lfci.print_elements();
}

// [[Rcpp::export]]
NumericMatrix checkSkeletonTotal(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.getSkeletonTotal();
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkSkeletonTotalPop(NumericMatrix td,NumericVector t,StringVector names){
  LocalFCI lfci(td,t,names,3,true);
  Rcout << "\n\n";
  lfci.getSkeletonTotal();
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkVStruct(NumericMatrix td,arma::mat df,NumericVector t,StringVector names){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  Rcout << "\n\n";
  lfci.getSkeletonTotal();
  // Get the skeleton for each target node and its neighborhood
  std::for_each(t.begin(),t.end(),[&lfci](int t){ lfci.getSkeletonTarget(t); });
  lfci.getVStructures();
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkVStructPop(NumericMatrix td,NumericVector t,StringVector names){
  LocalFCI lfci(td,t,names,3,true);
  Rcout << "\n\n";
  lfci.getSkeletonTotal();
  // Get the skeleton for each target node and its neighborhood
  std::for_each(t.begin(),t.end(),[&lfci](int t){ lfci.getSkeletonTarget(t); });
  lfci.getVStructures();
  lfci.convertMixedGraph();
  lfci.convertFinalGraph();
  return lfci.getAmat();
}

/*
 * This needs to be checked more rigorously with an appropriate test graph
 */
// [[Rcpp::export]]
NumericMatrix checkAdjMatConversion(NumericMatrix td,arma::mat df,NumericVector t,StringVector names,
                                    NumericMatrix m,NumericVector neighbors){
  LocalFCI lfci(td,df,t,names,3,0.01,true);
  lfci.setAmat(m);
  lfci.setNeighbors(neighbors);
  lfci.convertMixedGraph();
  lfci.convertFinalGraph();
  
  Rcout << "Final\n";
  lfci.print_elements();
  return lfci.getAmat();
}

// [[Rcpp::export]]
double checkSeparationTest(NumericMatrix td,arma::mat df,NumericVector t,StringVector names,
                           int i,int j,int l,NumericVector nodes_to_skip){ //
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
  
  return lfci.getMostRecentPVal();
}

// [[Rcpp::export]]
NumericMatrix checkLocalFCISummary(NumericMatrix td,arma::mat df,
                                   NumericVector targets,StringVector names){
  // Instantiate the Local FCI object
  LocalFCI lfci(td,df,targets,names,3,0.05,false);
  lfci.getSkeletonTotal();
  std::for_each(targets.begin(),
                targets.end(),
                [&lfci](int t){ lfci.getSkeletonTarget(t); });
  
  // Rule 0: Obtain V Structures
  lfci.getVStructures();
  
  // Remaining FCI Rules
  lfci.allRules();
  
  lfci.convertMixedGraph();
  
  lfci.convertFinalGraph();
  lfci.print_elements();
  
  return lfci.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLocalFCISummaryPop(NumericMatrix td,
                                   NumericVector targets,StringVector names){
  // Instantiate the Local FCI object
  LocalFCI lfci(td,targets,names,3,false);
  lfci.getSkeletonTotal();
  std::for_each(targets.begin(),
                targets.end(),
                [&lfci](int t){ lfci.getSkeletonTarget(t); });

  // Rule 0: Obtain V Structures
  lfci.getVStructures();

  // Remaining FCI Rules
  lfci.allRules();

  lfci.convertMixedGraph();

  lfci.convertFinalGraph();
  lfci.print_elements();

  return lfci.getAmat();
}
