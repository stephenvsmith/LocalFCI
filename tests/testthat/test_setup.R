context("Testing setup functions")

test_that("Obtains the correct neighborhood from the reference graph (1 target)",{
  data("asiaDAG")
  nodes <- colnames(asiaDAG)
  p <- ncol(asiaDAG)
  
  expect_equal(nodes[get_neighbors_from_dag(0,p,asiaDAG)+1],"tub")
  expect_equal(sort(nodes[get_neighbors_from_dag(which(nodes=="either")-1,p,asiaDAG)+1]),c("bronc","dysp","lung","tub","xray"))
})

