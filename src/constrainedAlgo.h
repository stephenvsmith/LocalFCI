#ifndef CONSTRAINEDALGO_H
#define CONSTRAINEDALGO_H

#include <algorithm> // Needed for sort
#include "DAG.h" // Needed for true_DAG
#include "SepSetList.h" // Needed for S
#include "pCorTest.h" // Needed for checkSeparation
#include "sharedFunctions.h" // Needed for printing elements and combn
#include <RcppArmadillo.h> // Needed for dataframe
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

class ConstrainedAlgo {
public:
  ConstrainedAlgo(NumericMatrix true_dag,arma::mat df,
                  NumericVector targets,
                  StringVector names,
                  int lmax,
                  double signif_level,
                  bool verbose,bool estDAG=false);
  
  ConstrainedAlgo(NumericMatrix true_dag, // population version
                  NumericVector targets,
                  StringVector names,
                  int lmax,
                  bool verbose);
  
  ~ConstrainedAlgo(){delete C_tilde; delete true_DAG; delete S;};
  
  //Printing Functions
  void print_elements();
  void printAmat(){ C_tilde -> printAmat(); };
  
  size_t getSize(){ return p; }
  
  virtual void checkSeparation(int l,size_t i,size_t j,
                               NumericMatrix kvals);
  
  // Every algorithm must define their own target neighborhood skeleton algorithm
  virtual void getSkeletonTarget(const size_t &t) = 0;
  
  virtual void getVStructures();
  
  // Accessors
  NumericMatrix getAmat() { return C_tilde -> getAmat(); }
  List getSepSetList() { return S -> getS(); };
  size_t getNumTests() { return num_tests; };
  NumericVector getAdjacent(size_t i) { return C_tilde -> getAdjacent(i); };
  NumericVector getNeighborhood() { return neighborhood; };
  double getMostRecentPVal() { return p_vals[p_vals.size()-1];};
  double getTotalTime() { return total_time; };
  
  // Setters (Useful for testing)
  void setAmat(NumericMatrix m){
    if (verbose){
      Rcout << "We are manually changing the current adjacency matrix.\n";
    }
    C_tilde -> setAmat(m);
    N = C_tilde -> size();
    if (verbose){
      C_tilde -> printAmat();
    }
  }
  
  void setS(size_t i,size_t j,NumericVector k){
    S -> changeList(i,j,k);
  }
  
  void setNeighbors(NumericVector neighbors){
    neighborhood = neighbors;
    N = neighborhood.size();
    if (verbose){
      for (size_t i=0;i<N;++i){
        Rcout << "True: " << neighborhood(i) << " | Renumbered: " << i << std::endl;
      }
    }
  }
  
  void setVerboseTrue(){
    verbose = true;
  }
  
protected:
  int lmax;
  size_t num_targets;
  size_t p;
  size_t n=0;
  size_t N; // Tracks the size of the C_tilde matrix
  size_t num_tests=0;
  double total_time;
  NumericVector targets;
  NumericVector neighborhood;
  StringVector names;
  Graph* C_tilde;
  DAG* true_DAG;
  SepSetList* S;
  arma::mat df;
  arma::mat R;
  std::vector<double> p_vals;
  double signif_level=0.01;
  // Assume we are using the sample algorithm unless no data is inputted
  bool pop = false;
  
  // For debugging and algorithm analysis
  bool verbose_history=false;
  bool verbose=false;
  void silencer(){
    verbose_history = verbose;
    verbose = false;
  }
  void removeSilencer(){
    verbose = verbose_history;
  }

private:
  NumericVector sep;
};

#endif
