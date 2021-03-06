library(bnlearn)

data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)

test_that("Testing the LocalFCI object",{
  
  testthat::expect_snapshot_output(initializeLocalFCI(asiaDAG,asiadf,3,node_names))
  
})

test_that("Testing the LocalFCI object (Population)",{
  
  testthat::expect_snapshot_output(initializeLocalFCIPop(asiaDAG,3,node_names))
  
})

test_that("Testing Separation Test Function",{
  # Check if tub and lung are separated by the empty set
  expect_true(checkSeparationTest(asiaDAG,asiadf,3,node_names,0,2,0,1)>0.1)
  
  # Check if either and smoke are separated by tub (removing lung)
  expect_true(checkSeparationTest(asiaDAG,asiadf,3,node_names,1,3,1,2)<0.05)
  
  # Check if either and smoke are separated by lung (removing tub)
  expect_true(checkSeparationTest(asiaDAG,asiadf,3,node_names,1,3,1,0)>0.05)
})

test_that("Testing the total skeleton function (one target)",{
  # lung is the target
  testthat::expect_snapshot_output(result_amat <- checkSkeletonTotal(asiaDAG,asiadf,3,node_names))
  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,5)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})


test_that("Testing the total skeleton function (two targets)",{
  # Targets are lung and bronc
  testthat::expect_snapshot_output(result_amat <- checkSkeletonTotal(asiaDAG,asiadf,c(3,4),node_names))

  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,4,5,7)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})

test_that("Testing the total skeleton function for population (one target)",{
  
  testthat::expect_snapshot_output(result_amat <- checkSkeletonTotalPop(asiaDAG,3,node_names))
  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,5)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})

test_that("Testing the total skeleton function for population (two targets)",{
  
  testthat::expect_snapshot_output(result_amat <- checkSkeletonTotalPop(asiaDAG,c(3,4),node_names))
  
  total_skel <- bnlearn::empty.graph(node_names[c(1,2,3,4,5,7)+1])
  amat(total_skel) <- result_amat
  graphviz.plot(total_skel)
})

test_that("Testing Skeleton Target function and V-Structure function",{
  testthat::expect_snapshot_output(result_amat <- checkVStruct(asiaDAG,asiadf,c(3,4),node_names))
  
  # Convert to PDAG numbering
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
  # Check v-structure with tub -> either <- lung
  expect_equal(result_amat[1,5],1)
  expect_equal(result_amat[5,1],0)
  expect_equal(result_amat[3,5],1)
  expect_equal(result_amat[5,3],0)
  expect_equal(result_amat[1,3],0)
  expect_equal(result_amat[3,1],0)
  
  # Check v-structure either -> dysp <- bronc
  expect_equal(result_amat[5,6],1)
  expect_equal(result_amat[6,5],0)
  expect_equal(result_amat[4,6],1)
  expect_equal(result_amat[6,4],0)
  expect_equal(result_amat[4,5],0)
  expect_equal(result_amat[5,4],0)
  
  # Population Version
  result_amat <- checkVStructPop(asiaDAG,c(3,4),node_names)
  pop_graph <- empty.graph(node_names)
  amat(pop_graph) <- result_amat
  graphviz.plot(pop_graph,highlight = list("nodes"=c("lung","bronc")))
  
  modified_asia_dag <- asiaDAG
  # Remove asia and xray from consideration
  modified_asia_dag[1,] <- 0
  modified_asia_dag[,7] <- 0
  # smoke - lung
  modified_asia_dag[4,3] <- 1
  # smoke - bronc
  modified_asia_dag[5,3] <- 1
  
  expect_equal(result_amat,modified_asia_dag)
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
  
  result_amat <- checkAdjMatConversion(final_mat,asiadf,c(3,4),node_names,
                                       test_mat,c(1,3,4,6,8,10))
  expect_equal(result_amat,final_mat)
  conv_graph <- empty.graph(as.character(0:10))
  amat(conv_graph) <- result_amat
  graphviz.plot(conv_graph)
  
  asia_test <- matrix(c(
    0,2,0,2,
    2,0,1,2,
    0,1,0,0,
    1,1,0,0
  ),byrow = TRUE,nrow = 4)
  asia_result <- checkAdjMatConversion(asiaDAG,asiadf,c(4,5),node_names,asia_test,4:7)

})

test_that("Local FCI (Putting it all together)",{
  sample_g <- empty.graph(node_names)
  amat(sample_g) <- checkLocalFCISummary(asiaDAG,asiadf,c(0,5),node_names)
  expect_snapshot(amat(sample_g))
  graphviz.plot(sample_g)
  
  pop_g <- empty.graph(node_names)
  amat(pop_g) <- checkLocalFCISummaryPop(asiaDAG,c(0,5),node_names)
  expect_snapshot(amat(pop_g))
  graphviz.plot(pop_g)
  
  pop_g <- empty.graph(node_names)
  amat(pop_g) <- checkLocalFCISummaryPop(asiaDAG,c(2,7),node_names)
  expect_snapshot(amat(pop_g))
  graphviz.plot(pop_g)
  
  pop_g <- empty.graph(node_names)
  amat(pop_g) <- checkLocalFCISummaryPop(asiaDAG,c(1,3,7),node_names)
  expect_snapshot(amat(pop_g))
  graphviz.plot(pop_g)
  
  pop_g <- empty.graph(node_names)
  amat(pop_g) <- checkLocalFCISummaryPop(asiaDAG,c(0,6),node_names)
  expect_snapshot(amat(pop_g))
  graphviz.plot(pop_g)
})



