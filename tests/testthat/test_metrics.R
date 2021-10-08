library(testthat)
library(tidyverse)
library(pcalg)

test_that("checking metric functions",{
  true_amat <- matrix(c(0,2,0,0,
                        2,0,2,2,
                        0,1,0,2,
                        0,3,3,0),byrow = TRUE,nrow = 4)
  
  perfect_skel <- matrix(c(0,2,0,0,
                           3,0,1,1,
                           0,1,0,2,
                           0,1,1,0),byrow = TRUE,nrow = 4)
  
  false_skel <- matrix(c(0,0,2,1,
                         0,0,2,2,
                         3,2,0,0,
                         1,2,0,0),byrow = TRUE,nrow = 4)
  testthat::expect_equal(compare_skeletons(false_skel,true_amat,FALSE),list("skel_fp"=2,"skel_fn"=2,"skel_correct"=2))
  testthat::expect_equal(compare_skeletons(perfect_skel,true_amat,FALSE),list("skel_fp"=0,"skel_fn"=0,"skel_correct"=4))
  
  testthat::expect_equal(compare_v_structures(false_skel,true_amat,FALSE),list("missing"=0,"added"=2,"correct"=0))
  testthat::expect_equal(compare_v_structures(perfect_skel,true_amat,FALSE),list("missing"=0,"added"=0,"correct"=0))
  
  true_amat <- matrix(c(0,2,2,0,0,2,
                        3,0,0,3,0,2,
                        1,0,0,1,0,0,
                        0,2,1,0,2,1,
                        0,0,0,2,0,2,
                        3,3,0,1,1,0),nrow = 6,byrow = TRUE)
  false_amat <- matrix(c(0,3,3,0,0,2,
                         2,0,0,1,0,2,
                         2,0,0,3,3,0,
                         0,1,2,0,0,1,
                         0,0,2,0,0,2,
                         3,3,0,1,3,0),nrow = 6,byrow = TRUE)
  testthat::expect_equal(compare_v_structures(false_amat,true_amat,FALSE),list("missing"=1,"added"=2,"correct"=2))
  
  true_amat_conv <- matrix(c(0,1,0,0,0,0,
                             0,0,0,1,1,0,
                             1,0,0,1,0,0,
                             0,0,0,0,1,1,
                             0,0,0,0,0,0,
                             0,0,0,0,0,0),nrow=6,byrow = TRUE)
  ta_conv <- convert_true_dag(true_amat_conv)
  arrowheads <- which(ta_conv==2,arr.ind = TRUE)
  arrow_flip <- arrowheads[order(arrowheads[,1]),2:1]
  colnames(arrow_flip) <- c("row","col")
  tails <- which(ta_conv==3,arr.ind = TRUE)
  testthat::expect_identical(arrow_flip,tails)
  
  pc_amat <- matrix(c(0,1,1,0,0,0,
                      1,0,0,1,1,0,
                      1,0,0,1,0,0,
                      0,0,0,0,0,1,
                      0,1,0,0,0,0,
                      0,0,0,1,0,0),nrow = 6,byrow = TRUE)
  
  pc_amat_conv <- convert_pc_amat(pc_amat)
  undir_edges <- which(pc_amat_conv==1,arr.ind = TRUE)
  undir_edges_flip <- undir_edges[,2:1]
  undir_edges_flip <- undir_edges_flip[order(undir_edges_flip[,2]),]
  colnames(undir_edges_flip) <- c("row","col")
  testthat::expect_identical(undir_edges,undir_edges_flip)
  
  dir_edges <- which(pc_amat_conv==2,arr.ind = TRUE,useNames = FALSE)
  dir_tails <- which(pc_amat_conv==3,arr.ind = TRUE,useNames = FALSE)
  dir_tails_flip <- dir_tails[,2:1]
  testthat::expect_identical(dir_edges,dir_tails_flip)
  
  parent_recovery_accuracy(pc_amat_conv,ta_conv,0:5,FALSE)
  
  t <- c(1,6,7,8)
  est <- localfci_cpp(asiadf,true_dag = asiaDAG,targets = t,verbose = FALSE)
  pc.fit <- as(pcalg::pc(suffStat = list(C = cor(asiadf), n = nrow(asiadf)),
                  indepTest = gaussCItest, ## indep.test: partial correlations
                  alpha=0.05, labels = colnames(asiaDAG),
                  verbose = FALSE,m.max=3),"amat")
  pc_asia <- matrix(pc.fit,nrow = 8)
  
  all_metrics(est$G,asiaDAG,pc_asia,t-1)
  
})