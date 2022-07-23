library(tidyverse,quietly = TRUE,verbose = FALSE)
library(pcalg,quietly = TRUE,verbose = FALSE)
library(bnlearn,verbose = FALSE)

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
  est <- localfci(data=asiadf,true_dag = asiaDAG,targets = t,verbose = FALSE)

  pc.fit <- as(pcalg::pc(suffStat = list(C = cor(asiadf), n = nrow(asiadf)),
                  indepTest = gaussCItest, ## indep.test: partial correlations
                  alpha=0.05, labels = colnames(asiaDAG),
                  verbose = FALSE,m.max=3),"amat")
  pc_asia <- matrix(pc.fit,nrow = 8)
  
  lfci_g <- empty.graph(colnames(asiaDAG))
  pc_g <- empty.graph(colnames(asiaDAG))
  amat(lfci_g) <- est$amat
  amat(pc_g) <- pc_asia
  graphviz.plot(lfci_g)
  graphviz.plot(pc_g)
  graphviz.compare(lfci_g,pc_g)
  expect_snapshot_output(all_metrics(est$amat,asiaDAG,pc_asia,t-1))
  
})

true_amat <- matrix(c(
  0,0,1,0,0,0,0,
  0,0,1,0,0,0,0,
  0,0,0,1,1,0,1,
  0,0,0,0,0,1,0,
  0,0,0,0,0,1,0,
  0,0,0,0,0,0,0,
  0,0,1,0,1,1,0
),byrow = TRUE,nrow = 7)

a <- empty.graph(as.character(1:7))
amat(a) <- true_amat
graphviz.plot(a)

test_that("Checking MB metric functions (Specific)",{
  
  # Remove the edge 7 -> 5
  test_amat <- true_amat
  test_amat[7,5] <- 0
  
  # Check results
  expect_equal(calcParentRecovery(true_amat,test_amat,5),
               c("tp"=1,
                 "fn"=1,
                 "fp"=0)
  )
  expect_equal(calcChildRecovery(true_amat,test_amat,5),
               c("tp"=1,
                 "fn"=0,
                 "fp"=0)
  )
  expect_equal(calcSpouseRecovery(true_amat,test_amat,5),
               c("tp"=1,
                 "fn"=0,
                 "fp"=1)
  )
  
  # Remove the edge from 1 -> 3 and add 1 -> 6
  test_amat[1,3] <- 0
  test_amat[1,6] <- 1
  # 1 is missing and 2 is correct
  expect_equal(calcParentRecovery(true_amat,test_amat,3),
               c("tp"=1,
                 "fn"=1,
                 "fp"=0)
  )
  # 3 is missing and 6 is added
  expect_equal(calcChildRecovery(true_amat,test_amat,1),
               c("tp"=0,
                 "fn"=1,
                 "fp"=1)
  )
  # 4,5,7 are correct, but 1 is added
  expect_equal(calcParentRecovery(true_amat,test_amat,6),
               c("tp"=3,
                 "fn"=0,
                 "fp"=1)
  )
  # 5 and 7 are true spouses, but 1 is added
  expect_equal(calcSpouseRecovery(true_amat,test_amat,4),
               c("tp"=2,
                 "fn"=0,
                 "fp"=1)
  )
  # 4 is a true spouse, but 1 and 5 are added
  expect_equal(calcSpouseRecovery(true_amat,test_amat,7),
               c("tp"=1,
                 "fn"=0,
                 "fp"=2)
  )
  # We've added 4,5,7 as spouses and are missing 2
  expect_equal(calcSpouseRecovery(true_amat,test_amat,1),
               c("tp"=0,
                 "fn"=1,
                 "fp"=3)
  )
})

test_that("Test MB Recovery (General) Function",{
  test_amat <- matrix(
    c(
      0,0,0,0,0,0,0,
      0,0,0,0,0,0,1,
      1,0,0,0,0,0,1,
      0,0,0,0,0,1,0,
      0,0,0,1,0,1,1,
      0,0,0,0,0,0,1,
      0,0,0,0,0,0,0
    ),
    nrow = 7,byrow = TRUE
  )
  b <- empty.graph(as.character(1:7))
  amat(b) <- test_amat
  graphviz.compare(b,a)
  # 1 is connected to 3, but loses 2 as spouse
  expect_equal(mbRecovery(true_amat,test_amat,1),
             c("mb_tp"=1,"mb_fn"=1,"mb_fp"=0)
  )
  # 2 loses 3 and 1 (spouse), adds 7 [At this stage we are double counting]
  expect_equal(mbRecovery(true_amat,test_amat,c(1,2)),
             c("mb_tp"=1,"mb_fn"=3,"mb_fp"=1)
  )
  # 6 has perfect recovery (4,5,7)
  expect_equal(mbRecovery(true_amat,test_amat,6),
             c("mb_tp"=3,"mb_fn"=0,"mb_fp"=0)
  )
  expect_equal(mbRecovery(true_amat,test_amat,c(1,2,6)),
               c("mb_tp"=4,"mb_fn"=3,"mb_fp"=1)
  )
  # 7 keeps 6,5,3 but loses 4 (spouse) and adds 2
  expect_equal(mbRecovery(true_amat,test_amat,7),
               c("mb_tp"=3,"mb_fn"=1,"mb_fp"=1)
  )
})








