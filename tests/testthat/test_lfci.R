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

test_that("Testing the total skeleton function (two targets)",{

  testthat::expect_snapshot_output(result_amat <- checkSkeletonBoth(asiaDAG,asiadf,c(3,4),node_names))

  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,4,5,7)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})


test_that("Testing V-Structure function",{
  testthat::expect_snapshot_output(result_amat <- checkVStruct(asiaDAG,asiadf,c(3,4),node_names))
  
  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,4,5,7)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})







