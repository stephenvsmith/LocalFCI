data("asiaDAG")
data("asiadf")
true_dag <- asiaDAG
nodes <- colnames(asiaDAG)
p <- ncol(asiaDAG)

test_that("Combination generation function (combn) works correctly",{
  l <- 0
  vec <- 1:8
  expect_equal(is.na(combn_cpp(vec,l)[1,1]),TRUE)
  
  for (l in 1:5){
    expect_equal(all(combn_cpp(vec,l)==combn(vec,l)),TRUE)
  }
})

test_that("Obtains the correct neighborhood from the reference graph",{
  expect_equal(nodes[check_neighbors_retrieval(p,nodes,asiaDAG,0)+1],"tub")
  expect_equal(sort(nodes[check_neighbors_retrieval(
    ncol(asiaDAG),nodes,asiaDAG,which(nodes=="either")-1)+1]),
    c("bronc","dysp","lung","tub","xray"))
})

test_that("Separation test is accurate",{
  target <- which(nodes=="either")-1
  neighborhood <- sort(union(target,check_neighbors_retrieval(p,nodes,asiaDAG,target)))
  R <- cor(asiadf)
  sep <- 0
  pval <- 0.5
  signif_level <- 0.05
  verbose <- FALSE
  num_tests <- 0
  n <- nrow(asiadf)
  
  i <- 1
  j <- 3
  l <- 0
  expect_snapshot_output(res <- checkSeparationTest(asiaDAG,as.matrix(asiadf),0:7,nodes,
                      i,j,l,numeric()))
  expect_equal(res$G[i+1,j+1],0)
  expect_equal(res$G[i+1,j+1],0)

  l <- 1
  # Tub should not be considered independent of lung when conditioned on either
  # This is due to a v-structure in the graph
  expect_snapshot_output(res <- checkSeparationTest(asiaDAG,as.matrix(asiadf),0:7,nodes,
                                                    i,j,l,setdiff(0:7,5)))
  expect_equal(res$G[i+1,j+1],1)
  expect_equal(res$G[i+1,j+1],1)
  
})