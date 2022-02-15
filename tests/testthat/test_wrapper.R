library(testthat)
library(bnlearn)

data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)
p <- length(node_names)

# # Testing with one target
# for (i in 1:p){
#   results <- localfci_cpp(true_dag = asiaDAG,data = asiadf,targets = i,node_names=node_names,verbose = FALSE)
#   g <- empty.graph(node_names)
#   amat(g) <- results$G
#   location <- "~/Dropbox/Academics/Research/Code/Packages/LocalFCI/tests/testing_photos/"
#   jpeg(filename = paste0(location,"Target=",node_names[i],".jpeg"))
#   graphviz.plot(g)
#   dev.off()
# }
# 
# targets_2 <- combn(1:p,2)
# for (i in 1:ncol(targets_2)){
#   targets <- targets_2[,i]
#   results <- localfci_cpp(true_dag = asiaDAG,data = asiadf,targets = targets,node_names=node_names,verbose = FALSE)
#   g <- empty.graph(node_names)
#   amat(g) <- results$G
#   location <- "~/Dropbox/Academics/Research/Code/Packages/LocalFCI/tests/testing_photos/"
#   jpeg(filename = paste0(location,"Targets=",paste(node_names[targets],collapse = ","),".jpeg"))
#   graphviz.plot(g)
#   dev.off()
# }


test_that("Wrapper function works",{
  results <- localfci_cpp(true_dag = asiaDAG,data = asiadf,targets = c(1,6),node_names=node_names,verbose = FALSE)
  g <- empty.graph(node_names)
  amat(g) <- results$amat
  for (result_part in setdiff(names(results),c("totalSkeletonTime","targetSkeletonTimes","totalTime"))){
    #expect_snapshot_output(results$results[[result_part]])
    expect_snapshot_output(print(results[[result_part]]))
  }
})