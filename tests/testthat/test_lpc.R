data("asiaDAG")
data("asiadf")
t <- 5
names <- colnames(asiaDAG)
df <- as.matrix(asiadf)
asiaDAG <- as.matrix(asiaDAG)

test_that("Sample Local PC",{
  expect_equal(checkInitializeLocalPC(asiaDAG,df,t,names),8)
  
  pc_dag <- empty.graph(names[c(2,4,5,6,7,8)])
  amat(pc_dag) <- checkGetTargetSkel(asiaDAG,df,t,names)
  graphviz.plot(pc_dag)
  
  amat(pc_dag) <- checkGetVStructures(asiaDAG,df,t,names)
  graphviz.plot(pc_dag) 
})

test_that("Population Local PC",{
  pc_dag_pop <- empty.graph(names[c(2,4,5,6,7,8)])
  expect_equal(checkInitializeLocalPCPop(asiaDAG,t,names),8)
  amat(pc_dag_pop) <- checkGetTargetSkelPop(asiaDAG,t,names)
  graphviz.plot(pc_dag_pop)
  
  amat(pc_dag_pop) <- checkGetVStructuresPop(asiaDAG,t,names)
  graphviz.plot(pc_dag_pop)
})

test_that("Multiple Targets",{
  lpc_test <- empty.graph(names)
  amat_test <- checkLocalPC(asiaDAG,df,c(3,4),names)
  amat(lpc_test) <- amat_test
  graphviz.plot(lpc_test)
  expect_output(cat(amat_test))
  
  lpc_test_pop <- empty.graph(names)
  amat_pop <- checkLocalPCPop(asiaDAG,c(3,4),names)
  amat(lpc_test_pop) <- amat_pop
  graphviz.plot(lpc_test_pop)
  expect_output(cat(amat_pop))
  
  lpc_test_pop2 <- empty.graph(names)
  amat_pop2 <- checkLocalPCPop(asiaDAG,c(0,5),names)
  amat(lpc_test_pop2) <- amat_pop2
  graphviz.plot(lpc_test_pop2)
  expect_output(cat(amat_pop2))
})
