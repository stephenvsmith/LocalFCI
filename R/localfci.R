#' Local FCI Algorithm
#' 
#' `localfci()` applies the local FCI algorithm to a dataset over 
#' certain target neighborhoods, which may be provided by the user 
#' through the true DAG or may be estimated by a 
#' Markov Blanket estimation algorithm 
#' 
#' @param data A dataframe or matrix containing network data
#' @param true_dag An optional parameter used primarily for simulations 
#' in order to obtain the Markov Blankets of certain target nodes
#' @param targets A numeric vector specifying the target nodes
#' @param node_names A string vector with the node names, useful for tracking output
#' @param lmax The maximum size of separating set considered in the algorithm. Default is 3
#' @param tol The significance level of our conditional independence tests. Default is 0.01
#' @param mb_tol The significance level of our Markov Blanket estimation algorithms. Default is 0.05
#' @param method Algorithm used for Markov Blanket estimation. Default is MMPC.
#' @param test The conditional independence test used for all algorithms.
#' @param verbose A boolean which determines whether or not to print a trace of the output.
#' 
#' @returns A list containing various elements computed from or during the algorithm.
#' @return A list including the estimated adjacency matrix, timing calculations, 
#' the number of conditional independence tests, 
#' a matrix providing Markov Blanket information, a list containing 
#' separating sets, and statistics about the original dataset
#' 
#' @export

localfci <- function(data=NULL,true_dag=NULL,targets,
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
    results <- localfci_cpp_pop(true_dag,cpp_targets,node_names,lmax,verbose)
  } else {
    results <- localfci_cpp(true_dag,data,cpp_targets,node_names,lmax,tol,verbose)
  }
  
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





