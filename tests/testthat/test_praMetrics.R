true_amat <- matrix(c(
  0,0,1,0,0,0,
  0,0,0,0,1,0,
  0,0,0,1,0,0,
  0,0,0,0,1,0,
  0,0,0,0,0,1,
  0,0,0,0,1,0
),nrow = 6,byrow = TRUE)

est_amat <- matrix(c(
  0,0,0,0,0,0,
  0,0,1,0,1,0,
  1,0,0,0,0,0,
  0,0,1,0,1,0,
  0,0,0,1,0,0,
  0,0,0,0,1,0
),nrow = 6,byrow = TRUE)

# g_t <- empty.graph(as.character(1:6))
# amat(g_t) <- true_amat
# g_est <- empty.graph(as.character(1:6))
# amat(g_est) <- est_amat
# par(mfrow=c(1,2))
# graphviz.plot(g_t)
# graphviz.plot(g_est)

# Nodes 3 and 5 are the targets
# TP: 2->5
# FP: 4->3 (Note: 2->3 doesn't count because they are in different neighborhoods)
# FN: 1->3 and 4->5
test_that("Testing Parent Recovery Accuracy Metrics",{
  expect_snapshot_output(parentRecoveryAccuracy(est_amat,true_amat,c(2,4),TRUE))
  
  expect_snapshot_output(allMetrics(est_amat,true_amat,c(2,4),algo = "lfci",verbose = TRUE))
})

