localpc <- function(data=NULL,true_dag=NULL,targets,
                          node_names=NULL,lmax=3,tol=0.01,mb_tol=0.05,
                          method="MMPC",test="testIndFisher",verbose = TRUE){
  p <- ifelse(is.null(data),ncol(true_dag),ncol(data))
  if (is.null(node_names)){
    node_names <- paste0("V",0:(p-1))
  }

  data_means <- NA
  data_cov <- NA
  if (!is.null(data)){
    if (is.data.frame(data)){
      data <- as.matrix(data)
    }
    # Store data information
    data_means <- colMeans(data)
    data_cov <- stats::cov(data)
    
    # Scale the data
    data <- scale(data)
  }
  
  if (is.null(true_dag)){
    # Find Markov Blankets (mbEst.R)
    mbList <- getAllMBs(targets,data,mb_tol,method,test,verbose)
    
    # Create adjacency matrix based on Markov Blankets (mbEst.R)
    true_dag <- getEstInitialDAG(mbList,ncol(data),verbose)
    
  } else {
    mbList <- list()
  }
  
  # Convert any data frame to a matrix
  if (is.data.frame(true_dag)){
    true_dag <- as.matrix(true_dag)
  }
  
  # To account for zero-indexing in C++
  cpp_targets <- targets-1 
  if (verbose){
    cat("The node value for the C++ function is",
        paste(cpp_targets,collapse = ","),
        "\n")
  }
  
  if (is.null(data)){
    if (verbose){
      cat("Population Version:\n")
    }
    results <- localpc_cpp_pop(true_dag,cpp_targets,node_names,lmax,verbose)
  } else {
    results <- localpc_cpp(true_dag,data,cpp_targets,node_names,lmax,tol,verbose)
  }
  
  # We change the target to target - 1 in order to accommodate change to C++
  return(list(
    "amat"=results$G,
    "S"=results$S,
    "NumTests"=results$NumTests,
    "Nodes"=results$allNodes+1, # to convert to R numbering
    "targetSkeletonTimes"=results$targetSkeletonTimes,
    "totalTime"=results$totalTime,
    "referenceDAG"=true_dag,
    "mbList"=mbList,
    "data_means"=data_means,
    "data_cov"=data_cov)
  )
}