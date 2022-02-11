#ifndef SHAREDFUNCTIONS_H
#define SHAREDFUNCTIONS_H

#include<RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;

NumericMatrix combn_cpp(NumericVector x,int l);

void print_vector_elements(NumericVector v,StringVector names, String opening="",String closing="");

void print_vector_elements_nonames(NumericVector v,String opening="",String closing="",String sep=" ");

void print_matrix(NumericMatrix m);

void iteration_print(const int &l,const int &i,const int &j,const NumericVector &sep,const StringVector &names,const double &pval);

#endif