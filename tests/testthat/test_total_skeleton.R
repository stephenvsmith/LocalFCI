test_that("get correct current edges in the graph",{
  set.seed(123)
  N <- 20
  adj.mat <- matrix(nrow = N,ncol = N)
  diag(adj.mat) <- 0
  for (i in 1:(N-1)){
    for (j in (i+1):N){
      adj.mat[i,j] <- sample(c(0,1),1,prob = c(0.3,0.7))
      adj.mat[j,i] <- adj.mat[i,j]
    }
  }
  
  for (i in 0:(N-1)){
    current_connections <- LocalFCI::get_current_edges(i,N,adj.mat)
    expect_equal(sort(current_connections),sort(which(adj.mat[i+1,]==1)-1))
    expect_equal(sort(current_connections),sort(which(adj.mat[,i+1]==1)-1))
  }
  
})

test_that("Check to ensure that set difference function works",{
  set.seed(123)
  N <- 20
  adj.mat <- matrix(nrow = N,ncol = N)
  diag(adj.mat) <- 0
  for (i in 1:(N-1)){
    for (j in (i+1):N){
      adj.mat[i,j] <- sample(c(0,1),1,prob = c(0.3,0.7))
      adj.mat[j,i] <- adj.mat[i,j]
    }
  }
  Rcpp::cppFunction("NumericVector v(int i,int j,NumericVector vi,NumericVector vj) {
    return setdiff(union_(vi,vj),NumericVector::create(i,j));}")
  for (i in 0:(N-2)){
    for (j in (i+1):(N-1)){
      cat("i:",i,"| j:",j," | Union of neighbors:",v(i,j,
            LocalFCI::get_current_edges(i,N,adj.mat),
            LocalFCI::get_current_edges(j,N,adj.mat)),"\n")
      expect_equal(any(c(i,j) %in% v(i,j,
                                     LocalFCI::get_current_edges(i,N,adj.mat),
                                     LocalFCI::get_current_edges(j,N,adj.mat))),
                   FALSE)
    }
  }
})