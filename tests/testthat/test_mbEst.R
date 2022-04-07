data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)
p <- length(node_names)

connections <- list(
  "asia"=c("tub"),
  "tub"=c("asia","lung","either"),
  "either"=c("tub","lung","xray","dysp","bronc"),
  "lung"=c("either","tub","smoke"),
  "smoke"=c("lung","bronc"),
  "bronc"=c("smoke","dysp","either"),
  "dysp"=c("either","bronc"),
  "xray"=c("either")
)

test_that("Markov Blanket Estimation",{
  for (algo in c("MMPC","SES")){
    cat("\nAlgorithm:",algo,"\n\n")
    for (i in 1:p){
      cat("\nNode",node_names[i],"\n")
      res <- getMB(i,asiadf,threshold = 0.01,method = algo,test = "testIndFisher",verbose = FALSE)
      mb <- node_names[res$mb]
      cat("# True Positives / # Total Est =",mean(mb %in% connections[[node_names[i]]]),"\n")
      cat("# True positives / # Total =",mean(connections[[node_names[i]]] %in% mb))
      expect_snapshot_output(mean(mb %in% connections[[node_names[i]]]))
      expect_snapshot_output(mean(connections[[node_names[i]]] %in% mb))
    }
  }
})

test_that("All Markov Blankets (multiple targets)",{
  expect_snapshot_output(res <- getAllMBs(targets = c(4,8),asiadf))
})

test_that("Obtaining Markov Blanket Nodes from List",{
  res <- getAllMBs(targets = c(4,8),asiadf,verbose = FALSE)
  node_list <- getAllMBNodes(res)
  true_res <- list(
    "4"=c(3,6),
    "8"=c(5,6),
    "3"=c(4,5),
    "6"=c(2,4,7,8),
    "5"=c(3,8)
  )
  expect_setequal(node_list,unique(unlist(true_res)))
})

test_that("Create adjacency matrix from MB List",{
  res <- getAllMBs(targets = c(4,8),asiadf,verbose = FALSE)
  node_list <- getAllMBNodes(res)
  true_res <- list(
    "4"=c(3,6),
    "8"=c(5,6),
    "3"=c(4,5),
    "6"=c(2,4,7,8),
    "5"=c(3,8)
  )
  adj <- getEstInitialDAG(res,p)
  for (i in names(true_res)){
    n <- as.numeric(i)
    expect_setequal(which(adj[n,]==1 | adj[,n]==1),true_res[[i]])
  }
  
  remaining_nodes <- setdiff(1:p,node_list)
  for (i in remaining_nodes){
    for (j in remaining_nodes){
      expect_equal(adj[i,j],0)
    }
  }
})

