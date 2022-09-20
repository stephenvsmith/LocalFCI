data("asiadf")
data("asiaDAG")
node_names <- colnames(asiaDAG)
asiaDAG <- matrix(asiaDAG,nrow = ncol(asiadf),ncol = ncol(asiadf))
asiadf <- as.matrix(asiadf)
p <- length(node_names)

test_that("Neighborhood Estimation",{
  # Bronc and Either are in dysp's Markov Blanket
  expect_equal(getMB(8,asiadf)$mb,c(5,6))
  expect_equal(getMB(8,asiadf,method = "SES")$mb,c(5,6))
  expect_equal(getMB(8,asiadf,method = "pc.sel")$mb,c(5,6))
  
  # Output should find MB for each target first
  # Then 3's non-target first-order neighbors: 4
  # Then 5's non-target first-order neighbors: none
  # Then 6's non-target first-order neighbors: 2, 7
  # Then 8's non-target first-order neighbors: none
  targets <- c(3,5,6,8)
  mbList <- getAllMBs(targets,asiadf)
  lapply(mbList,function(mb){
    expect_snapshot_output(mb$mb)
  })
  
  adj <- getEstInitialDAG(mbList,p)
  for (i in 1:length(targets)){
    target <- targets[i]
    neighbors <- mbList[[i]][["mb"]]
    for (neighbor in neighbors){
      expect_equal(adj[target,neighbor]+adj[neighbor,target],1)
    }
  }
  
  times <- rep(NA,length(targets))
  for (i in 1:length(targets)){
    times[i] <- mbList[[i]][["time"]]
  }
  expect_equal(getTotalMBTime(mbList),sum(times),tolerance = 1e-01)
})


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

test_that("Testing error and warning conditions",{
  # Error for invalid target index
  expect_error(getMB(8,asiadf),NA)
  expect_error(getMB(0,asiadf))
  expect_error(getMB(9,asiadf))
  expect_error(getMB(10,asiadf))
  expect_error(getMB(-1,asiadf))
  
  expect_error(getAllMBs(c(1,0,3),asiadf))
  expect_error(getAllMBs(c(1,8,9),asiadf))
  expect_error(getAllMBs(c(-1,1,3),asiadf))
  
  expect_warning(getAllMBs(c(1,4,5,5,7),asiadf))
  expect_warning(getAllMBs(c(1,4,5,7),asiadf),NA)
  
  # Invalid estimation algorithm
  expect_error(getMB(5,asiadf,method = "abc"))
  
  # Invalid testing threshold
  expect_error(getMB(5,asiadf,threshold = -0.1))
  expect_error(getMB(5,asiadf,threshold = 0))
  expect_error(getMB(5,asiadf,threshold = 1.4))
  
  # Invalid entries to construct reference graph
  expect_error(getEstInitialDAG(list(),1))
  targets <- c(3,5,6,8)
  mbList <- getAllMBs(targets,asiadf)
  expect_error(getEstInitialDAG(mbList,0))
  expect_error(getEstInitialDAG(mbList,-1))
  targets <- c(3,5)
  mbList <- getAllMBs(targets,asiadf)
  expect_error(getEstInitialDAG(mbList,6))
})

test_that("Misc. Tests for MB Functions",{
  targets <- c(1,3)
  target_mbs <- list(
    list(
      "mb"=c(3),
      "time"=0.1
    ),
    list(
      "mb"=1,
      "time"=0.3
    )
  )
  constructFinalMBList(targets,target_mbs,
                       asiadf,threshold=0.01,method="MMPC",test="testIndFisher",verbose=TRUE)
  
  targets <- c(3,5,6,8)
  mbList <- getAllMBs(targets,asiadf)
  expect_equal(getTotalMBTime(mbList),
               sum(unlist(lapply(mbList,
                                 function(x) {return(x$time)}))))

})
