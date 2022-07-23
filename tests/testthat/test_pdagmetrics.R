data("asiaDAG")
data("asiadf")
node_names <- colnames(asiaDAG)
p <- nrow(asiaDAG)

targets <- c("asia","either")
est_result <- localfci(data = asiadf,true_dag = asiaDAG,targets = 1,verbose = FALSE)

getPDAGMetrics(est_result$amat,true_dag = asiaDAG,node_names,setdiff(1:p,est_result$Nodes))
