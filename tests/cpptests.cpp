#include<RcppArmadillo.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector test_union(NumericVector x, NumericVector y) {
  x = union_(x,y);
  return x;
}

// [[Rcpp::export]]
NumericVector test_sort(NumericVector x) {
  NumericVector y = clone(x);
  std::sort(y.begin(),y.end());
  return y;
}

// [[Rcpp::export]]
NumericVector test_fill(int nrow,int ncol,int value){
  NumericMatrix x(nrow,ncol);
  std::fill(x.begin(),x.end(),value);
  return x;
}

// [[Rcpp::export]]
NumericMatrix test_fill_diag(NumericMatrix x,int value){
  x.fill_diag(value);
  return x;
}

// [[Rcpp::export]]
NumericVector test_create(double x1,double x2){
  return NumericVector::create(x1,x2);
}

// [[Rcpp::export]]
NumericVector test_setdiff(NumericVector v1,NumericVector v2){
  return setdiff(v1,v2);
}

// [[Rcpp::export]]
NumericVector test_intersect(NumericVector v1,NumericVector v2){
  return intersect(v1,v2);
}

// [[Rcpp::export]]
std::map<int,int> test_map_insert(IntegerVector v1,IntegerVector v2){
  int n = v1.length();
  std::map<int,int> my_map;
  for (int i=0;i<n;++i){
    my_map.insert(std::pair<int,int>(v1[i],v2[i]));
  }
  return my_map;
}

// [[Rcpp::export]]
void test_map_find(IntegerVector v1,IntegerVector v2,int a){
  std::map<int,int> m = test_map_insert(v1,v2);
  std::map<int,int>::iterator it = m.find(a);
  Rcout << "(" << it->first << "," << it->second << ")\n";
} 

// [[Rcpp::export]]
NumericMatrix combn_cpp(NumericVector x,int l){
  int xlength = x.length();
  NumericMatrix result;
  
  if (l > x.length()){
    Rcout << "There aren't enough neighbors for the current value of l\n";
  }
  
  if (l==0){
    result = NumericMatrix(1,1);
    result(0,0) = NA_REAL;
    return result;
  } else if (xlength==1 & l == 1){
    result = NumericMatrix(1,1);
    result(0,0) = x(0);
    return result;
  } else if (l>=1 & xlength>1) {
    Function f("combn");
    result = f(Named("x")=x,_["m"]=l);
    return result;
  } else {
    Rcout << "The value of l is negative: " << l << std::endl;
    Rcout << "Or the value of l is less than the size of the vector. Length of input vector: " << x.length() << std::endl;
  }
  
  return result;
}

// [[Rcpp::export]]
arma::uvec test_sep_arma(){
  arma::uvec sep_arma;
  Rcout << "Size of arma vector when l=0: " << sep_arma.size() << std::endl;
  return sep_arma;
}

// [[Rcpp::export]]
arma::mat test_subset_mat(arma::mat m,NumericVector i){
  arma::uvec ind = as<arma::uvec>(i);
  return arma::cor(m.cols(ind)); //USE THIS TO CHANGE CORRELATION MATRIX AND MAKE FUNCTION TRANSLATION EASIER
}

// [[Rcpp::export]]
NumericMatrix test_NumMat_value(NumericMatrix G){
  NumericMatrix Gc = clone(G);
  Gc(0,0) = 10;
  return Gc;
}

// [[Rcpp::export]]
void test_change_bool(bool &b){
  b = !b;
}

// [[Rcpp::export]]
void test_decrement_matrix(NumericMatrix &G){
  --G(0,0);
  ++G(1,1);
}

/*** R
x <- test_union(c(1,5,7,10,42),c(14,19,20,1,5))
x
test_sort(x)
test_fill(3,5,10)
test_fill_diag(test_fill(6,6,0),1)
(v <- test_create(3.5,9.1))
str(v)
v1 <- c(8,10,12,19,24)
v2 <- c(12,24,0,9)
test_setdiff(v1,v2)
test_setdiff(v2,v1)
test_intersect(v1,v2)
test_setdiff(v1,v1)

set.seed(111)
v1 <- sample(1:10,5)
v2 <- sample(40:50,5)
ind <- order(v1)
(m <- test_map_insert(v1,v2))
v1[ind]
v2[ind]

test_map_find(v1,v2,3)

#microbenchmark::microbenchmark(combn(1:30,4),combn_cpp(1:30,4))

test_sep_arma()

df <- matrix(rnorm(500),nrow = 100)
ind <- c(0,2,4)
test_subset_mat(df,ind)
cor(df[,ind+1])

# NumericMatrix passes by reference
g <- matrix(c(1,1,1,1),nrow = 2)
g1 <- test_NumMat_value(g)
g
g1

bl <- FALSE
test_change_bool(bl)
bl

g <- matrix(rep(1,4),nrow = 2)
g
test_decrement_matrix(g)
g
*/
