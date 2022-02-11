library(testthat)
library(bnlearn)

data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)

test_that("Testing the LocalFCI object",{
  
  testthat::expect_snapshot_output(initializeLocalFCI(asiaDAG,asiadf,3,node_names))
  
})

test_that("Testing the total skeleton function (one target)",{
  
  testthat::expect_snapshot_output(result_amat <- checkSkeletonTotal(asiaDAG,asiadf,3,node_names))
  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,5)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})


test_that("Testing the total skeleton function (two targets)",{

  testthat::expect_snapshot_output(result_amat <- checkSkeletonTotal(asiaDAG,asiadf,c(3,4),node_names))

  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,4,5,7)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})

test_that("Testing V-Structure function",{
  testthat::expect_snapshot_output(result_amat <- checkVStruct(asiaDAG,asiadf,c(3,4),node_names))
  
  for (i in 1:nrow(result_amat)){
    for (j in 1:ncol(result_amat)){
      if (result_amat[i,j]==2){
        result_amat[i,j] <- 1
        result_amat[j,i] <- 0
      }
    }
  }
  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,4,5,7)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})

test_that("Testing Adjacency Matrix Conversion",{
  test_mat <- matrix(c(0,2,0,0,1,0,
                       2,0,2,0,0,0,
                       0,1,0,2,0,0,
                       0,0,3,0,0,0,
                       1,0,0,0,0,1,
                       0,0,0,0,3,0),nrow = 6,byrow = TRUE)
  
  final_mat <- matrix(c(rep(0,11),
                        0,0,0,1,0,0,0,0,1,0,0,
                        rep(0,11),
                        0,1,0,0,1,0,0,0,0,0,0,
                        0,0,0,0,0,0,1,0,0,0,0,
                        rep(0,11),
                        rep(0,11),
                        rep(0,11),
                        0,1,0,0,0,0,0,0,0,0,1,
                        rep(0,11),
                        rep(0,11)),nrow = 11,byrow = TRUE)
  
  result_amat <- checkAdjMatConversion(matrix(data = 0,nrow = 11,ncol = 11),asiadf,c(3,4),node_names,
                                       test_mat,c(1,3,4,6,8,10))
  expect_equal(result_amat,final_mat)
  conv_graph <- empty.graph(as.character(0:10))
  amat(conv_graph) <- result_amat
  graphviz.plot(conv_graph)
})





