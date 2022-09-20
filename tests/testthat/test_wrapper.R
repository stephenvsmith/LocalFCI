library(bnlearn)

data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)
p <- length(node_names)

test_that("Wrapper function works (Sample with true DAG)",{
  # Local FCI
  results <- localfci(true_dag = asiaDAG,data = asiadf,targets = c(1,6),node_names=node_names,verbose = TRUE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","totalTime"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  
  # Local PC
  results <- localpc(true_dag = asiaDAG,data = asiadf,targets = c(1,6),node_names=node_names,verbose = TRUE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("targetSkeletonTimes","totalTime"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
})

test_that("Wrapper function works (Population)",{
  # Local FCI
  results <- localfci(true_dag = asiaDAG,targets = c(1,6),node_names=node_names,verbose = TRUE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","totalTime"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  
  # Local PC
  results <- localpc(true_dag = asiaDAG,targets = c(1,6),node_names=node_names,verbose = TRUE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("targetSkeletonTimes","totalTime"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
})

test_that("Wrapper function works (Sample)",{
  # Local FCI
  results <- localfci(data = asiadf,targets = c(1,6),node_names=node_names,verbose = TRUE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","totalTime","mbList"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
  
  # Local PC
  results <- localpc(data = asiadf,targets = c(1,6),node_names=node_names,verbose = TRUE)
  # g <- empty.graph(node_names)
  # amat(g) <- results$amat
  # graphviz.plot(g)
  for (result_part in setdiff(names(results),c("targetSkeletonTimes","totalTime","mbList"))){
    expect_snapshot_output(print(results[[result_part]]))
  }
})

