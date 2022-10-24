data("asiaDAG")
data("asiadf")
t <- 5
names <- colnames(asiaDAG)
df <- as.matrix(asiadf)
asiaDAG <- as.matrix(asiaDAG)
p <- ncol(asiaDAG)

test_that("Sample Local PC (given true Markov Blankets)",{
  expect_equal(checkInitializeLocalPC(asiaDAG,df,t,seq(0,p-1),names),8)
  
  pc_dag <- empty.graph(names[c(2,4,5,6,7,8)])
  amat(pc_dag) <- checkGetTargetSkel(asiaDAG,df,t,seq(0,p-1),names)
  #graphviz.plot(pc_dag)
  
  amat(pc_dag) <- checkGetVStructures(asiaDAG,df,t,seq(0,p-1),names)
  #graphviz.plot(pc_dag) 
})

test_that("Population Local PC",{
  pc_dag_pop <- empty.graph(names[c(2,4,5,6,7,8)])
  expect_equal(checkInitializeLocalPCPop(asiaDAG,t,seq(0,p-1),names),8)
  # amat(pc_dag_pop) <- checkGetTargetSkelPop(asiaDAG,t,seq(0,p-1),names)
  # graphviz.plot(pc_dag_pop)
  # 
  # amat(pc_dag_pop) <- checkGetVStructuresPop(asiaDAG,t,seq(0,p-1),names)
  # graphviz.plot(pc_dag_pop)
})

test_that("Multiple Targets",{
  # lpc_test <- empty.graph(names)
  amat_test <- checkLocalPC(asiaDAG,df,c(3,4),seq(0,p-1),names)
  # amat(lpc_test) <- amat_test
  # graphviz.plot(lpc_test)
  expect_output(cat(amat_test))
  
  # lpc_test_pop <- empty.graph(names)
  amat_pop <- checkLocalPCPop(asiaDAG,c(3,4),seq(0,p-1),names)
  # amat(lpc_test_pop) <- amat_pop
  # graphviz.plot(lpc_test_pop)
  # expect_output(cat(amat_pop))
  
  # lpc_test_pop2 <- empty.graph(names)
  amat_pop2 <- checkLocalPCPop(asiaDAG,c(0,5),seq(0,p-1),names)
  # amat(lpc_test_pop2) <- amat_pop2
  # graphviz.plot(lpc_test_pop2)
  expect_output(cat(amat_pop2))
})


test_that("Wrapper function (Population Version)",{
  expect_snapshot_output(wrapper_res <- localpc(true_dag = asiaDAG,targets = c(3,4),
                                                node_names = names))
  # res_g <- empty.graph(names)
  # amat(res_g) <- wrapper_res$amat
  # graphviz.plot(res_g)
})

test_that("Wrapper function (Semi-Sample Version)",{
  expect_snapshot_output(wrapper_res_semi <- localpc(data = asiadf,true_dag = asiaDAG,
                                              targets = c(3,4),node_names = names))
})

test_that("Wrapper function (Sample Version)",{
  expect_snapshot_output(wrapper_res_sample <- localpc(data = asiadf,targets = c(3,4),
                                                node_names = names))
  # Same as above, but without names
  expect_snapshot_output(wrapper_res_sample <- localpc(data = asiadf,targets = c(3,4)))
})

test_that("Testing data structure correctness",{
  dag_df <- data.frame(asiaDAG)
  expect_error(tmp <- localpc(true_dag = dag_df,targets = t),NA)
})
