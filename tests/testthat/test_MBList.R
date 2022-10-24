### Testing Markov Blanket List class

nodes <- seq(0,6)
mb_mat <- matrix(c(
  0,0,0,1,0,0,0,
  0,0,1,0,0,1,0,
  0,1,0,0,0,1,1,
  1,0,0,0,1,0,1,
  0,0,0,1,0,0,0,
  0,1,1,0,0,0,0,
  0,0,1,1,0,0,0
),byrow = TRUE,nrow = 7)
data(asiaDAG)

test_that("Initialization of Markov Blanket Object works (Sample)",{
  expect_snapshot_output(testInitializeMBList(nodes,mb_mat))
})

test_that("Access Markov Blanket for a node",{
  expect_equal(testAccessMB(nodes,mb_mat,0),c(3))
  expect_equal(testAccessMB(nodes,mb_mat,2),c(1,5,6))
  expect_equal(testAccessMB(nodes,mb_mat,1),c(2,5))
  expect_error(testAccessMB(nodes,mb_mat,50))
})

test_that("Access Markov Blanket for multiple nodes",{
  expect_equal(testAccessMultipleMB(nodes,mb_mat,c(0,1,2)),c(1,2,3,5,6))
  expect_equal(testAccessMultipleMB(nodes,mb_mat,c(0,2,1)),c(1,2,3,5,6))
})

test_that("Membership in MB function is correct",{
  expect_true(testIsMBMember(nodes,mb_mat,1,5))
  expect_true(testIsMBMember(nodes,mb_mat,3,6))
  expect_false(testIsMBMember(nodes,mb_mat,4,0))
  expect_false(testIsMBMember(nodes,mb_mat,3,2))
})

nodes <- seq(0,7)
node_names <- colnames(asiaDAG)
test_that("Initialization for Population Version works",{
  expect_snapshot_output(testInitializeMBListPop(nodes,asiaDAG))
})
