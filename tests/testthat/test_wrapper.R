library(testthat)
test_that("Wrapper function works",{
  data("asiaDAG")
  data("asiadf")
  localfci_cpp(asiadf,asiaDAG,c(1,6))
})