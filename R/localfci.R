localfci_cpp <- function(data=NULL,true_dag=NULL,targets,node_names=NULL,lmax=3,tol=0.01,method="MMPC",
                        verbose = TRUE){
  if (is.null(node_names)){
    node_names <- paste0("V",0:(ncol(data)-1))
  }
  if (is.data.frame(data)){
    data <- as.matrix(data)
  }
  # Store data information
  data_means <- colMeans(data)
  data_cov <- stats::cov(data)
  
  # Scale the data
  data <- scale(data)
  
  # TODO: Add results from this to the final output
  if (is.null(true_dag)){
    # Find Markov Blankets
    mbList <- getAllMBs(targets,data,tol,method,verbose)
    
    # Create adjacency matrix based on Markov Blankets
    true_dag <- getEstInitialDAG(mbList,targets,ncol(data),verbose)
  } else {
    mbList <- list()
  }
  
  
  if (verbose){
    utils::head(data)
  }
  
  if (is.data.frame(true_dag)){
    true_dag <- as.matrix(true_dag)
  }
  
  if (verbose) {
    head(true_dag)
  }
  
  # To account for zero-indexing
  cpp_target <- targets-1 
  if (verbose){
    cat("The node value for the C++ function is",cpp_target)
  }
  
  results <- fci(true_dag,data,targets-1,node_names,lmax,tol,verbose)
  
  # We change the target to target - 1 in order to accommodate change to C++
  return(list(
    "amat"=results$G,
    "S"=results$S,
    "NumTests"=results$NumTests,
    "Nodes"=results$allNodes+1, # to convert to R numbering
    "totalSkeletonTime"=results$totalSkeletonTime,
    "targetSkeletonTimes"=results$targetSkeletonTimes,
    "totalTime"=results$totalTime,
    "referenceDAG"=true_dag,
    "mbList"=mbList,
    "data_means"=data_means,
    "data_cov"=data_cov)
  )
}