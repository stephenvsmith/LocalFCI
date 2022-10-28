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
  lapply(mbList$mb_list,function(mb){
    expect_snapshot_output(mb$mb)
  })
  expect_equal(mbList$num_tests,30)
  
  adj <- getEstInitialDAG(mbList$mb_list,p)
  for (i in 1:length(targets)){
    target <- targets[i]
    neighbors <- mbList$mb_list[[i]][["mb"]]
    for (neighbor in neighbors){
      expect_equal(adj[target,neighbor]+adj[neighbor,target],2)
    }
  }
  
  times <- rep(NA,length(targets))
  for (i in 1:length(targets)){
    times[i] <- mbList$mb_list[[i]][["time"]]
  }
  expect_equal(getTotalMBTime(mbList$mb_list),sum(times),tolerance = 1e-01)
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
  node_list <- getAllMBNodes(res$mb_list)
  true_res <- list(
    "4"=c(2,3,6),
    "8"=c(5,6),
    "3"=c(4,5),
    "6"=c(2,4,7,8),
    "5"=c(3,8),
    "2"=c(1,4,6)
  )
  expect_setequal(node_list,unique(unlist(true_res)))
})

test_that("Create adjacency matrix from MB List",{
  res <- getAllMBs(targets = c(4,8),asiadf,verbose = FALSE)
  node_list <- getAllMBNodes(res$mb_list)
  true_res <- list(
    "4"=c(2,3,6),
    "8"=c(5,6),
    "3"=c(4,5),
    "6"=c(2,4,7,8),
    "5"=c(3,8)
  )
  adj <- getEstInitialDAG(res$mb_list,p)
  for (i in names(true_res)){
    n <- as.numeric(i)
    expect_equal(which(adj[n,]==1),true_res[[i]])
  }
  
  remaining_nodes <- setdiff(1:p,node_list)
  for (i in remaining_nodes){
    for (j in remaining_nodes){
      expect_equal(adj[i,j],0)
    }
  }
})

mb_mat <- matrix(c(
  0,1,0,0,0,0,0,0,
  1,0,0,1,0,1,0,0,
  0,0,0,1,1,0,0,0,
  0,1,1,0,0,1,0,0,
  0,0,1,0,0,1,0,1,
  0,1,0,1,1,0,1,1,
  0,0,0,0,0,1,0,0,
  0,0,0,0,1,1,0,0
),nrow = 8,ncol = 8,byrow = TRUE)

mb_list <- list(
  "asia"=list("children"=1,"parents"=0,"spouses"=0),
  "tub"=list("children"=1,"parents"=1,"spouses"=1),
  "smoke"=list("children"=2,"parents"=0,"spouses"=0),
  "lung"=list("children"=1,"parents"=1,"spouses"=1),
  "bronc"=list("children"=1,"parents"=1,"spouses"=1),
  "either"=list("children"=2,"parents"=2,"spouses"=1),
  "xray"=list("children"=0,"parents"=1,"spouses"=0),
  "dysp"=list("children"=0,"parents"=2,"spouses"=0)
)

test_that("Testing Markov Blanket Recovery Metrics Function",{
  
  for (i in seq(8)){
    results <- mbRecoveryMetrics(asiaDAG,mb_mat,i)
    expect_equal(results$mb_children_tp,mb_list[[node_names[i]]]$children)
    expect_equal(results$mb_parents_tp,mb_list[[node_names[i]]]$parents)
    expect_equal(results$mb_spouses_tp,mb_list[[node_names[i]]]$spouses)
    expect_equal(results$mb_children_fn,0)
    expect_equal(results$mb_parents_fn,0)
    expect_equal(results$mb_spouses_fn,0)
    expect_equal(results$mb_total_fp,0)
  }
  
  pairs <- combn(seq(8),2)
  apply(pairs,2,function(x){
    results <- mbRecoveryMetrics(asiaDAG,mb_mat,x)
    true_children <- mb_list[[node_names[x[1]]]]$children+mb_list[[node_names[x[2]]]]$children
    true_parents <- mb_list[[node_names[x[1]]]]$parents+mb_list[[node_names[x[2]]]]$parents
    true_spouses <- mb_list[[node_names[x[1]]]]$spouses+mb_list[[node_names[x[2]]]]$spouses
    expect_equal(results$mb_children_tp,true_children)
    expect_equal(results$mb_parents_tp,true_parents)
    expect_equal(results$mb_spouses_tp,true_spouses)
    expect_equal(results$mb_children_fn,0)
    expect_equal(results$mb_parents_fn,0)
    expect_equal(results$mb_spouses_fn,0)
    expect_equal(results$mb_total_fp,0)
  })
  
  # Remove tub as a child of asia
  mb_mat[1,2] <- 0
  expect_warning(mbRecoveryMetrics(asiaDAG,mb_mat,1))
  mb_mat[2,1] <- 0
  expect_equal(mbRecoveryMetrics(asiaDAG,mb_mat,1)$mb_children_fn,1)
  # Remove either as child of lung, tub as spouse of lung
  # Add dysp as a child of asia
  mb_mat[4,6] <- mb_mat[6,4] <- 0
  mb_mat[4,2] <- mb_mat[2,4] <- 0
  mb_mat[1,8] <- mb_mat[8,1] <- 1
  expect_equal(mbRecoveryMetrics(asiaDAG,mb_mat,c(1,2,6)),
               data.frame("mb_children_fn"=1, # tub is not a child of asia
                          "mb_children_tp"=3, # either is still a child of tub, xray and dysp of either
                          "mb_parents_fn"=2, # asia is no longer parent of tub, either not a child of tub
                          "mb_parents_tp"=1, # tub is still parent of either
                          "mb_spouses_fn"=1, # lung no longer spouse of tub
                          "mb_spouses_tp"=1, # bronc is still a spouse of either
                          "mb_total_fp"=1)) # dysp and asia now in each other's mb
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
  mbList <- getAllMBs(targets,asiadf)$mb_list
  expect_error(getEstInitialDAG(mbList,0))
  expect_error(getEstInitialDAG(mbList,-1))
  targets <- c(3,5)
  mbList <- getAllMBs(targets,asiadf)
  expect_error(getEstInitialDAG(mbList$mb_list,6))
})

test_that("Misc. Tests for MB Functions",{
  targets <- c(1,3)
  target_mbs <- list(
    list(
      "mb"=c(3),
      "time"=0.1,
      "n_tests"=3
    ),
    list(
      "mb"=1,
      "time"=0.3,
      "n_tests"=10
    )
  )
  constructFinalMBList(targets,target_mbs,
                       asiadf,threshold=0.01,method="MMPC",test="testIndFisher",verbose=TRUE)
  
  targets <- c(3,5,6,8)
  mbList <- getAllMBs(targets,asiadf)$mb_list
  expect_equal(getTotalMBTime(mbList),
               sum(unlist(lapply(mbList,
                                 function(x) {return(x$time)}))))
  expect_equal(getTotalMBTests(mbList),22)

})
