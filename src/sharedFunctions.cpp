#include "sharedFunctions.h"
using namespace Rcpp;

/*
 * This function generates all possible combinations of a vector x of length l and puts them in a matrix
 * It uses the R function combn to produce the results.
 * Tested: 12/16/20
 */
// [[Rcpp::export]]
NumericMatrix combn_cpp(NumericVector x,int l){
  int xlength = x.length();
  NumericMatrix result;
  
  if (l > x.length()){
    stop("There aren't enough neighbors for the current value of l");
  } else if (l < 0){
    stop("The value of l is negative");
  }
  
  if (l==0){
    result = NumericMatrix(1,1);
    result(0,0) = NA_REAL;
  } else if (xlength==1 && l == 1){
    result = NumericMatrix(1,1);
    result(0,0) = x(0);
  } else if (l>=1 && xlength>1) {
    Function f("combn");
    result = f(Named("x")=x,_["m"]=l);
  }
  
  return result;
}

// Determines whether or not i is in vector x
// [[Rcpp::export]]
bool isMember(NumericVector x,int i){
  NumericVector::iterator it = x.begin();
  int j;
  
  for (;it!=x.end();++it){
    j = *it;
    if (i == j){
      return true;
    }
  }
  
  return false;
}


// PRINTING FUNCTIONS (DEBUGGING)

/*
 * 
 * Functions for printing different values 
 * 
 */

void print_vector_elements(NumericVector v,StringVector names,String opening,String closing){
  int ln = v.length();
  Rcout << opening.get_cstring();
  for (int i = 0;i<ln;++i) {
    Rcout << names(v(i));
    if (i < ln-1){
      Rcout << " ";
    }
  }
  Rcout << closing.get_cstring();
}


void print_vector_elements_nonames(NumericVector v,String opening,String closing,String sep){
  int l = v.length();
  Rcout << opening.get_cstring();
  for (int i = 0;i<l;++i) {
    Rcout << v(i);
    if (i<l-1){
      Rcout << sep.get_cstring();
    }
  }
  Rcout << closing.get_cstring();
}


void print_matrix(NumericMatrix m){
  int n = m.nrow();
  int p = m.ncol();
  String ending;
  for (int i = 0;i<n;++i){
    for (int j = 0;j<p;++j){
      if (j==p-1){
        ending = "\n";
      } else{
        ending = " ";
      }
      Rcout << m(i,j) << ending.get_cstring();
    }
  }
}


// void iteration_print(const int &l,const int &i,const int &j,const NumericVector &sep,const StringVector &names,const double &pval){
//   Rcout << "l: " << l << " | i: " << i << " | j: " << j << " | k: ";
//   if (l == 0){
//     Rcout << sep;
//   } else {
//     print_vector_elements(sep,names);
//   }
//   Rcout << " | p-val: " << pval;
//   Rcout << std::endl;
// }


