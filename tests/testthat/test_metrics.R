library(testthat)
library(tidyverse,quietly = TRUE)
library(pcalg,quietly = TRUE)
library(bnlearn)

test_that("checking metric functions",{
  true_amat <- matrix(c(0,1,0,0,
                        1,0,1,1,
                        0,0,0,1,
                        0,0,0,0),byrow = TRUE,nrow = 4)
  
  perfect_skel <- matrix(c(0,1,0,0,
                           0,0,0,1,
                           0,1,0,1,
                           0,0,0,0),byrow = TRUE,nrow = 4)
  
  false_skel <- matrix(c(0,0,1,1,
                         0,0,1,1,
                         0,0,0,0,
                         0,0,0,0),byrow = TRUE,nrow = 4)
  testthat::expect_equal(compare_skeletons(false_skel,true_amat,FALSE),list("skel_fp"=2,"skel_fn"=2,"skel_correct"=2))
  testthat::expect_equal(compare_skeletons(perfect_skel,true_amat,FALSE),list("skel_fp"=0,"skel_fn"=0,"skel_correct"=4))
  
  testthat::expect_equal(compare_v_structures(false_skel,true_amat,FALSE),list("missing"=0,"added"=2,"correct"=0))
  testthat::expect_equal(compare_v_structures(perfect_skel,true_amat,FALSE),list("missing"=0,"added"=1,"correct"=0))
  
  true_amat <- matrix(c(0,1,1,0,0,1,
                        0,0,0,0,0,1,
                        0,0,0,1,0,0,
                        0,1,1,0,1,1,
                        0,0,0,1,0,1,
                        0,0,0,1,0,0),nrow = 6,byrow = TRUE)
  false_amat <- matrix(c(0,0,0,0,0,1,
                         1,0,0,1,0,1,
                         1,0,0,0,0,0,
                         0,1,1,0,0,1,
                         0,0,1,0,0,1,
                         0,0,0,1,0,0),nrow = 6,byrow = TRUE)
  testthat::expect_equal(compare_v_structures(false_amat,true_amat,FALSE),list("missing"=1,"added"=2,"correct"=2))
  
  t <- c(1,6,7,8)
  data("asiaDAG")
  data("asiadf")
  est <- localfci_cpp(data=asiadf,true_dag = asiaDAG,targets = t,verbose = FALSE)
  est <- est$results
  pc.fit <- as(pcalg::pc(suffStat = list(C = cor(asiadf), n = nrow(asiadf)),
                  indepTest = gaussCItest, ## indep.test: partial correlations
                  alpha=0.05, labels = colnames(asiaDAG),
                  verbose = FALSE,m.max=3),"amat")
  pc_asia <- matrix(pc.fit,nrow = 8)
  
  lfci_g <- empty.graph(colnames(asiaDAG))
  pc_g <- empty.graph(colnames(asiaDAG))
  # amat(lfci_g) <- est$G
  # amat(pc_g) <- pc_asia
  # graphviz.plot(lfci_g)
  # graphviz.plot(pc_g)
  # graphviz.compare(lfci_g,pc_g)
  expect_snapshot_output(all_metrics(est$G,asiaDAG,pc_asia,t-1))
  
})