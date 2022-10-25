library(bnlearn)

data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)
p <- length(node_names)

test_that("Wrapper function works (Sample with true DAG)",{
  # Local FCI
  results <- localfci(true_dag = asiaDAG,data = asiadf,targets = c(1,6),node_names=node_names,verbose = FALSE)
  g <- empty.graph(node_names)
  amat(g) <- results$amat
  graphviz.plot(g)
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","mbEstTime","totalTime","MBNumTests"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  expect_equal(results[["MBNumTests"]],0)
  
  # Local PC
  results <- localpc(true_dag = asiaDAG,data = asiadf,targets = c(1,6),node_names=node_names,verbose = FALSE)
  g <- empty.graph(node_names)
  amat(g) <- results$amat
  graphviz.plot(g)
  for (result_part in setdiff(names(results),c("targetSkeletonTimes","totalTime","mbEstTime","MBNumTests"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  expect_equal(results[["MBNumTests"]],0)
})

test_that("Wrapper function works (Population)",{
  # Local FCI
  results <- localfci(true_dag = asiaDAG,targets = c(1,6),node_names=node_names,verbose = FALSE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","mbEstTime","totalTime","MBNumTests"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  expect_equal(results[["MBNumTests"]],0)
  
  # Local PC
  results <- localpc(true_dag = asiaDAG,targets = c(1,6),node_names=node_names,verbose = FALSE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("targetSkeletonTimes","totalTime","mbEstTime","MBNumTests"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  expect_equal(results[["MBNumTests"]],0)
  
})

test_that("Wrapper function works (Sample)",{
  # Local FCI
  results <- localfci(data = asiadf,targets = c(1,6),node_names=node_names,verbose = FALSE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","totalTime","mbList","mbEstTime","MBNumTests"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  results1 <- results[["MBNumTests"]]
  # Local PC
  results <- localpc(data = asiadf,targets = c(1,6),node_names=node_names,verbose = FALSE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("targetSkeletonTimes","totalTime","mbList","MBNumTests","mbEstTime"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  expect_snapshot_output(print(results1))
  expect_snapshot_output(print(results[["MBNumTests"]]))
})

test_that("Testing pre-checks",{
  expect_error(localfci(data = asiadf,targets = c(1,6),lmax = -1,node_names=node_names,verbose = FALSE))
  expect_error(localpc(data = asiadf,targets = c(1,6),lmax = -1,node_names=node_names,verbose = FALSE))
})







