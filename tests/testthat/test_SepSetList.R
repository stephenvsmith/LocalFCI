data("asiaDAG")

nodes <- colnames(asiaDAG)
p <- ncol(asiaDAG)
target <- 5 # "either" is the target
neighbors <- getNbhd(p,nodes,asiaDAG,target,verbose = FALSE)
neighbor_names <- nodes[neighbors+1]

test_that("Get correct neighbors and check separating set update",{
  expect_equal(nodes[target+1],"either")
  expect_equal(setdiff(neighbor_names,c("tub","lung","xray","dysp","bronc","either")),character(0))
  
  expect_snapshot_output(printS(neighbors))
  
})

test_that("Checking initialization and member functions",{
  size <- length(neighbors)-1
  for (n in 0:size){
    for (n2 in setdiff(0:size,n)){
      #cat("\nNeighbor 1: ",n," | ","Neighbor 2: ",n2,"\n")
      testthat::expect_true(is.na(getInitialValues(neighbors,n,n2)))
    }
  }
  set.seed(111)
  neighborhood_shuffled <- sample(1:size,size,replace = FALSE)
  expect_equal(setListEmptySet(neighbors,neighborhood_shuffled[1],neighborhood_shuffled[2]),-1)
  expect_equal(setListEmptySet(neighbors,neighborhood_shuffled[2],neighborhood_shuffled[5]),-1)
})

test_that("More member functions to check",{
  i <- 0
  j <- 1
  kvals <- 4:5
  cat('\n\n')
  expect_equal(setListEfficient(neighbors,i,j,kvals),kvals)
  cat('\n\n')
  expect_equal(setListEfficient(neighbors,j,i,kvals),kvals)
  cat('\n\n')
  
  # Checking if nodes 0 and 1 are separated by node 2 when S_{0,1}={4,5}
  expect_false(checkSeparationFunc(neighbors,i,j,kvals,2))
  # Checking if nodes 0 and 1 are separated by node 5 when S_{0,1}={4,5}
  # Should produce warning and should be false because both separation sets not
  # correctly defined
  expect_warning(tmp <- checkSeparationFunc(neighbors,i,j,kvals,5)) 
  expect_false(tmp)
  # Corrected Version
  expect_true(checkSeparationFuncCorrected(neighbors,i,j,kvals,5)) 
})

test_that("Checks for errors and warnings in values",{
  # Negative values
  expect_error(setListEfficient(neighbors,i=-1,j=0,c(1,2)))
  expect_error(setListEfficient(neighbors,i=0,j=-1,c(1,2)))
  expect_error(setListEfficient(neighbors,i=5,j=0,c(1,2)),NA)
  expect_error(setListEfficient(neighbors,i=6,j=0,c(1,2)))
  expect_error(setListEfficient(neighbors,i=3,j=6,c(1,2)))
  
  # Separation sets disagree
  expect_warning(checkIsSepSetMember(neighbors,0,1,c(3,4),c(4,5),4),NA)
  expect_warning(checkIsSepSetMember(neighbors,0,1,c(3,4),c(4,5),3))
})


