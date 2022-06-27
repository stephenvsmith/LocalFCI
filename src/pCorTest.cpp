#include "pCorTest.h"

using namespace Rcpp;

// Here, we are treating C as the correlation matrix
// [[Rcpp::export]]
double get_partial_correlation(arma::mat C,int i,int j,arma::uvec k){
  if (i == j){
    return(1.0);
  }
  
  double pc;
  int k_size = k.size();
  
  if (k_size==0){
    return C(i,j);
  } else if (k_size==1){
    pc = (C(i,j)-C(i,k(0))*C(j,k(0))) / sqrt( (1-pow(C(i,k(0)),2))*(1-pow(C(j,k(0)),2)));
  } else {
    arma::uvec indices(k_size+2);
    indices(0) = i;
    indices(1) = j;
    for (int l=0;l<k_size;++l){
      indices(l+2) = k(l);
    }
    arma::mat Cinv = arma::pinv(C(indices,indices));
    pc = -Cinv(0, 1)/sqrt(Cinv(0, 0) * Cinv(1, 1));
  }
  
  return pc;
}

double log_part(double r){
  double result;
  if (r == 1){ // Perfect correlation means this value will approach infinity
    result = 1000;
  } else {
    result = log1p((2*r)/(1-r));
  }
  return result; // returns log_e(1 + (2*r/(1-r)))
}

// [[Rcpp::export]]
double fisherZ(double pc,int n,int k_size){
  return sqrt(n - k_size - 3) * 0.5 * log_part(pc);
}

void printListVals(List l){
  bool a = l["result"];
  double b = l["pval"];
  Rcout << "List Values:\n";
  Rcout << "Result: " << a;
  Rcout << "P-Value: " << b;
}

// [[Rcpp::export]]
List condIndTest(arma::mat &C,const int &i,const int &j,const arma::uvec &k,const int &n,const double &signif_level){
  double pc = get_partial_correlation(C,i,j,k);
  double pc_transformed = fisherZ(pc,n,k.size());

  bool lower = pc_transformed < 0;
  
  double cutoff = R::qnorm(1-signif_level/2,0.0,1.0,true,false);
  // Rcpp::Rcout << "Value = " << pc_transformed << " | Cutoff = " << cutoff << " | Result = " << std::abs(pc_transformed) - cutoff << std::endl;
  // Rcpp::Rcout << "Results: " << (std::abs(pc_transformed) <= cutoff) << " | " << 2*R::pnorm(pc_transformed,0.0,1.0,lower,false) << std::endl;
  
  bool accept_H0 = std::abs(pc_transformed) <= cutoff;
  double pval=2*R::pnorm(pc_transformed,0.0,1.0,lower,false);
  //printListVals(res);
  
  return List::create(
    _["result"]=accept_H0, // The null hypothesis is accepted (p-value large) => H_0: r = 0 => Conditional independence
    _["pval"]=pval
  );
}

// [[Rcpp::export]]
List condIndTestPop(NumericMatrix G,const int &i,const int &j,const arma::uvec &k){
  Function my_dsep("my_dsep");
  NumericVector tmp = my_dsep(G,i,j,k);
  double pval = tmp[0];
  bool accept_H0 = static_cast<bool>(pval);  
  // if (accept_H0){
  //   Rcout << "We accept H_0 => Conditional independence established\n";
  // } else {
  //   Rcout << "We don't accept H_0 => Still dependent\n";
  // }
  return List::create(
    _["result"]=accept_H0, // The null hypothesis is accepted (p-value large) => H_0: r = 0 => Conditional independence
    _["pval"]=pval
  );
}
