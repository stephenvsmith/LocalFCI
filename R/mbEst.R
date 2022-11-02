# A function which provides information about the MB estimation procedure
mbEstMessage <- function(method,test,threshold){
  cat("Estimating Markov Blankets using\n",
      "Algorithm:",method,"\n",
      "Test:",test,"\n",
      "Tolerance:",threshold,"\n")
}
# Validates the input conditional independence test threshold
validateThreshold <- function(threshold){
  if (threshold<=0 | threshold > 1){
    stop("MB Estimation threshold is invalid. Threshold must be in (0,1]")
  }
}
# Validates the input MB estimation algorithm name
validateMethod <- function(method){
  if (!(method %in% c("MMPC","SES","gOMP","pc.sel"))){
    stop("Invalid MB estimation algorithm")
  }
}
# Validates the input target
validateTarget <- function(target,p){
  if (!(target %in% seq(p))){
    stop(paste0("Invalid target index (t=",target,")"))
  }
}

# TODO: Try these methods if we need more
# else if (method=="gOMP"){
#   mb <- MXM::gomp(target=target,dataset=dataset,test = test)$res[,1] # there are more options here to explore, also need to look closer at output
# } else if (method=="FBED"){
# mb <- MXM::fbed.reg(target = target,dataset = dataset,
#                     test = "testIndFisher",method = "LR",
#                     threshold = threshold)
# }# There is also fbed.reg, 

#' Estimate Markov Blanket of Target Node
#' 
#' `getMB()` applies a Markov Blanket estimation algorithm to a target node
#' 
#' @param target An integer identifying the target node whose MB we are attempting to recover
#' @param dataset A dataset used for estimation
#' @param threshold A positive real number designating the threshold for conditional independence tests used in the algorithm
#' @param method The name of the Markov Blanket estimation algorithm to use. Valid algorithms include "MMPC", "SES", and "gOMP".
#' @param test The conditional independence test to use in the algorithm. Default is the Fisher Independence test.
#' @param verbose Whether to provide detailed output
#' 
#' @returns A list containing a vector of the target node's estimated Markov Blanket,
#' the elapsed time for completing the estimation procedure, and the number of conditional
#' independence tests used by the algorithm 
#' @export
getMB <- function(target,dataset,threshold=0.01,lmax=3,
                  method="MMPC",test="testIndFisher",
                  verbose=FALSE){
  if (verbose) {
    mbEstMessage(method,test,threshold)
  }
  
  validateThreshold(threshold)
  validateMethod(method)
  validateTarget(target,ncol(dataset))
  
  if (method=="MMPC"){
    mb <- MXM::MMPC(target=target,dataset=dataset,
                    threshold=threshold,test=test,
                    max_k=lmax,hash = FALSE,
                    backward = FALSE)
    mb_vars <- mb@selectedVars
    n_tests <- length(mb_vars)+1 # Must change if we include backward phase
    runtime <- mb@runtime[3]
  } else if (method=="SES"){
    mb <- MXM::SES(target=target,dataset=dataset,
                   threshold=threshold,test=test,
                   max_k=lmax,hash = TRUE,
                   backward = FALSE)
    mb_vars <- mb@selectedVars
    n_tests <- mb@n.tests
    runtime <- mb@runtime[3]
  } else if (method=="pc.sel"){
    mb <- MXM::pc.sel(target=dataset[,target],
                      dataset=dataset[,-target],
                      threshold=threshold)
    mb_vars <- mb$vars
    n_tests <- sum(mb$n.tests)
    runtime <- mb$runtime[3]
  }
  
  if (verbose) {
    cat("Results for target",
        target,":",
        paste(mb@selectedVars,collapse = ","),"\n")
  }
  
  return(list("mb"=sort(mb_vars),
              "time"=runtime,
              "n_tests"=n_tests))
}

# This function provides us with the set of second-order neighbors of a
# target node, given a list with the target MBs and another list with 
# first-order neighbor MBs
getSecondOrderNeighbors <- function(target,
                                    pc_set,
                                    target_mbs,
                                    first_order_mbs,
                                    pairs_checked){
  
  # The union of P-C sets of the parents and children of target
  second_order_neighbors <- unique(unlist(
    lapply(pc_set,function(x){
      if (as.character(x) %in% names(target_mbs)){
        return(target_mbs[[as.character(x)]][["mb"]])
      } else {
        return(first_order_mbs[[as.character(x)]][["mb"]])
      }
    })
  ))
  # To obtain second-order neighbors, remove target and its parents and children
  # from the set obtained in the previous step
  second_order_neighbors_precheck <- sort(setdiff(second_order_neighbors,
                                                  c(target,pc_set)))
  second_order_neighbors <- c()
  # Remove any combinations of target and any of its second-order neighbors
  # which have already been checked for a spousal connection
  lapply(second_order_neighbors_precheck,function(x){
    if (!pairs_checked[target,x]){
      second_order_neighbors <<- c(
        second_order_neighbors,x
      )
    } 
  })
  return(second_order_neighbors)
}

#' This is a helper function for `getAllMBs` to find all of the spouses
#' for algorithms such as MMPC and SES.
#' Any previously identified second-order neighbor could be a spouse of
#' a target node if they are conditionally dependent on the target node
#' given the P-C set
captureSpouses <- function(dataset,targets,target_mbs,first_order_mbs,
                           threshold,verbose){
  # Prepare the inputs for the conditional independence test
  C <- cor(dataset)
  n <- nrow(dataset)
  p <- ncol(dataset)
  num_tests <- 0
  spouses_added <- c()
  spouse_mbs <- list()
  # Keep track of which pairs of nodes have been checked
  pairs_checked <- matrix(0,nrow = p,ncol = p)
  # For each target, identify the P-C set and second-order nbrs
  for (target in targets){
    # All of the parent and children of target
    pc_set <- target_mbs[[as.character(target)]][["mb"]]
    second_order_neighbors <- getSecondOrderNeighbors(target,
                                                      pc_set,
                                                      target_mbs,
                                                      first_order_mbs,
                                                      pairs_checked)
    # Test conditional independence of target and second-order neighbor
    # given the P-C set. If there is dependence, then we have a spouse.
    if (length(second_order_neighbors>0)){
      lapply(second_order_neighbors,function(x){
        if (verbose){
          cat("Checking if node",x,"is a spouse of target",target,"...")
        }
        test <- condIndTest(C,target-1,x-1,pc_set-1,n,threshold)
        num_tests <<- num_tests + 1
        pairs_checked[target,x] <<- pairs_checked[x,target] <<- 1
        if (!test$result){
          # We reject H_0, and conclude in favor of conditional dependence
          # Add x to the Markov Blanket set
          if (verbose){
            cat(" yes. Adding",x,"to MB of",target,". ")
          }
          target_mbs[[as.character(target)]][["mb"]] <<- sort(c(
            target_mbs[[as.character(target)]][["mb"]],x
          ))
          # Situation where x (the new spouse) is another target node
          if (x %in% targets){
            if (verbose){
              cat("Adding",target,"to MB of",
                  x,"(another target node).")
            }
            target_mbs[[as.character(x)]][["mb"]] <<- sort(c(
              target_mbs[[as.character(x)]][["mb"]],target
            ))
          } else if (as.character(x) %in% names(first_order_mbs)){
            # x is a first-order neighbor for another target
            if (verbose){
              cat("Adding",target,"to MB of",
                  x,"(first-order neighbor).")
            }
            first_order_mbs[[as.character(x)]][["mb"]] <<- sort(c(
              first_order_mbs[[as.character(x)]][["mb"]],target
            ))
          } else {
            # otherwise, x was previously identified as exclusively a second-order 
            # neighbor 
            if (verbose){
              cat(x,"is a newly discovered 1st-order neighbor",
                  "(was previously 2nd-order).")
            }
            # We have to track which spouses are newly added, because
            # we must estimate their Markov Blankets as well
            spouses_added <<- c(spouses_added,x)
            # Add target to MB set for node x in special spouse_mb list
            # Additional MB identification will take place later
            spouse_mbs[[as.character(x)]] <<- unique(c(
              target,first_order_mbs[[as.character(x)]]
            ))
          }
        } else { # Accept H_0
          if (verbose){
            cat(" no")
          }
        }
        if (verbose){
          cat("\n")
        }
      })
    }
  }
  return(list(
    "target_mbs"=target_mbs,
    "f_o_mbs"=first_order_mbs,
    "spouse_mbs"=spouse_mbs,
    "num_tests"=num_tests,
    "spouses_added"=spouses_added))
}

#' This function is a helper for `constructFinalMBList` that obtains 
#' first-order neighbor Markov Blankets and the number of tests required to
#' obtain all the neighborhoods.
getFirstOrderNeighborMBs <- function(first_order_neighbors,
                                     dataset,threshold,lmax,
                                     method,test,verbose){
  first_order_mbs <- lapply(first_order_neighbors,
                            function(t) 
                              getMB(t,dataset,
                                    threshold,
                                    lmax,
                                    method,
                                    test,verbose))
  names(first_order_mbs) <- as.character(first_order_neighbors)
  second_order_nbrs_tests <- sum(unlist(
    lapply(first_order_mbs,function(x) return(x[["n_tests"]]))
  ))
  return(list(
    "f_o_mbs"=first_order_mbs,
    "s_o_tests"=second_order_nbrs_tests
  ))
}

# This function takes the results from `getMB` being run on all of the targets
# and does the following:
# 1. Obtains the Markov Blankets for each first-order neighbor
# 2a. Captures spouse variables if necessary
# 2b. Finds Markov Blankets for any newly identified first-order neighbors
# 3. Combines all MBs into one list and returns it along with all the tests and the total time
constructFinalMBList <- function(targets,target_mbs,
                                 dataset,threshold,lmax,method,
                                 test,verbose){
  # Capture number of conditional independence tests for second-order neighbors
  second_order_nbrs_tests <- 0
  # Capture number of conditional independence tests for capturing spouses
  spouse_num_tests <- 0
  # A vector to identify only the first-order neighbors
  first_order_neighbors <- unique(
    setdiff(
      getAllMBNodes(target_mbs),targets
    )
  )
  # Number of tests for first-order neighbor identification
  first_order_nbrs_tests <- sum(unlist(
    lapply(target_mbs,function(x) return(x[["n_tests"]]))
  ))
  # Apply MB algorithm again to obtain MBs of first-order neighbors
  if (length(first_order_neighbors)>0){
    f_o_list <- getFirstOrderNeighborMBs(first_order_neighbors,dataset,
                                         threshold,lmax,
                                         method,test,verbose)
    first_order_mbs <- f_o_list$f_o_mbs
    second_order_nbrs_tests <- f_o_list$s_o_tests
    # For certain algorithms, obtain spouses using additional independence test
    if (method %in% c("MMPC","SES")){
      # Find spouses using an additional cond. indep. test
      result <- captureSpouses(dataset,targets,target_mbs,first_order_mbs,
                               threshold,verbose)
      # Updated MB list for target nodes and first-order neighbors
      target_mbs <- result$target_mbs
      first_order_mbs <- result$f_o_mbs
      spouse_num_tests <- result$num_tests
      # The spouses added for which MB has not been estimated
      spouses_added <- result$spouses_added
      # The list containing information about targets and their spouses
      spouse_mbs <- result$spouse_mbs
      if (length(spouses_added)>0){
        # These are nodes for which we have not yet estimated MB
        spouses_mb_list <- lapply(spouses_added,function(t){
          mb_list <- getMB(t,dataset,threshold,lmax,method,test,verbose)
          if (verbose){
            cat("Adding target nodes to spouse's MB List:",
                paste(spouse_mbs[[as.character(t)]],collapse = ", "),
                "\n")
          }
          mb_list$mb <- sort(c(mb_list$mb,
                               spouse_mbs[[as.character(t)]]))
          return(mb_list)
        })
        names(spouses_mb_list) <- as.character(spouses_added)
        first_order_mbs <- c(first_order_mbs,spouses_mb_list)
      }
    }
    # Combine first-order MBs and second-order MBs in one list
    final_list <- c(target_mbs,first_order_mbs)
  } else {
    final_list <- target_mbs
    names(final_list) <- as.character(targets)
  }
  mb_time <- sum(unlist(
    lapply(final_list,function(x) return(x[["time"]]))
  ))
  return(list(
    "mb_list"=final_list,
    "num_tests"=spouse_num_tests+first_order_nbrs_tests+second_order_nbrs_tests,
    "mb_time"=mb_time))
}

checkUniqueTargets <- function(targets){
  if (any(duplicated(targets))){
    warning("Duplicate targets inputted. Removing duplicates.")
    targets <- unique(targets)
  }
  return(targets)
}

#' Estimate Markov Blankets of a vector of target nodes
#' 
#' `getAllMBs()` applies Markov Blanket algorithms to a vector of target nodes and
#' their first-order neighbors to obtain the full list of neighborhoods necessary to run the 
#' local FCI algorithm.
#' 
#' @param targets a vector of integers which will identify the target nodes of our algorithm
#' @inheritParams getMB
#' @export
getAllMBs <- function(targets,dataset,threshold=0.01,lmax=3,
                      method="MMPC",test="testIndFisher",
                      verbose=TRUE){
  start <- Sys.time()
  targets <- checkUniqueTargets(targets)
  
  # Find the MBs for the target nodes
  target_mbs <- lapply(targets,
                       function(t) 
                         getMB(t,dataset,threshold,lmax,method,test,verbose)
  )
  names(target_mbs) <- as.character(targets)
  result <- constructFinalMBList(targets,target_mbs,dataset,
                                 threshold,lmax,method,test,verbose)
  stop <- Sys.time()
  diff <- stop - start
  units(diff) <- "secs"
  result$time <- as.numeric(diff)
  
  return(result)
}

#' Generate Markov Blanket Inclusion Matrix from List
#' 
#' `getEstInitialDAG()` prepares the estimated neighborhoods for use in our local algorithms by storing them
#' in an "inclusion matrix". This will be used in the Rcpp implementation as what determines neighborhoods.
#'  It is a symmetric matrix where M[i,j] = M[j,i] = 1 if nodes i or j are identified to be in either one's neighborhood
#' 
#' @param mbList is a named list containing the estimated Markov Blankets for the targets and their first-order neighbors
#' @param p is the number of nodes in the graph
#' @param verbose 
getEstInitialDAG <- function(mbList,p,verbose=FALSE){
  if (verbose) {
    cat("Creating the reference DAG using Markov Blanket list.\n")
  }
  
  if (p <= 0){
    stop("Invalid network size p")
  }
  
  if (length(mbList)==0){
    stop("MB List is empty")
  }
  # Matrix to store neighborhood information
  adj <- matrix(0,nrow = p,ncol = p)
  all_nodes <- as.numeric(names(mbList))
  nodes_seq <- all_nodes
  lapply(1:length(nodes_seq),function(i){
    node <- nodes_seq[i]
    mb <- mbList[[as.character(node)]][["mb"]]
    if (length(mb)>0){
      sapply(mb,function(x){
        if (node > p | x > p){
          stop("Invalid index. The value for p is too small.\n")
        }
        # Add node and x to one another's neighborhood
        if (adj[node,x]==0){
          adj[node,x] <<- 1
          adj[x,node] <<- 1
        }
      })
      all_nodes <<- union(all_nodes,mb)
    }
  })
  if (verbose) {
    cat("Nodes being considered:",
        paste(sort(all_nodes),collapse = ","),
        "\n\n")
  }
  return(adj)
}

# Obtain the total time taken for estimating the Markov Blankets as stored in the
# value returned by the `getMB` function
getTotalMBTime <- function(mbList){
  return(sum(sapply(mbList,function(mb){
    return(mb[["time"]])
  })))
}

# Obtain the total time taken for estimating the Markov Blankets as stored in the
# value returned by the `getMB` function
getTotalMBTests <- function(mbList){
  return(sum(sapply(mbList,function(mb){
    return(mb[["n_tests"]])
  })))
}

# Obtain only a vector of nodes returned by the `getMB` function
getAllMBNodes <- function(mbList){
  nodes <- unique(
    unlist(
      sapply(mbList,
             function(x) return(x[["mb"]])
      )
    )
  )
  names(nodes) <- NULL
  return(nodes)
}

# Measurement Functions ----------------------------------------------------

calcParentRecovery <- function(ref,est,target){
  # Get all the parent nodes in both graphs
  parent_ref <- which(ref[,target]==1 & ref[target,]!=1) 
  parent_est <- which(est[,target]==1 & est[target,]!=1) 
  
  # If a node is in both vectors, then it is a true positive
  # If it is in the reference but not in the estimated, then it is a false negative
  # If it is in the estimated but not the reference, then it is a false positive
  return(c(
    "tp"=length(intersect(parent_ref,parent_est)),
    "fn"=length(setdiff(parent_ref,parent_est)),
    "fp"=length(setdiff(parent_est,parent_ref))
  ))
}

calcChildRecovery <- function(ref,est,target){
  # Get all the child nodes in both graphs
  child_ref <- which(ref[target,]==1) 
  child_est <- which(est[target,]==1) 
  # If a node is in both vectors, then it is a true positive
  # If it is in the reference but not in the estimated, then it is a false negative
  # If it is in the estimated but not the reference, then it is a false positive
  return(c(
    "tp"=length(intersect(child_ref,child_est)),
    "fn"=length(setdiff(child_ref,child_est)),
    "fp"=length(setdiff(child_est,child_ref))
  ))
}

getSpouses <- function(g,children,target){
  
  return(
    sort(
      unique(
        unlist(
          lapply(children,function(child){
            # Find parents of the child that are not connected to target
            child_parents <- which(g[,child]==1 & g[child,]==0 & g[target,]==0 & g[,target]==0)
            return(setdiff(child_parents,target))
          }))
      )
    )
  )
}

calcSpouseRecovery <- function(ref,est,target){
  # Get all the child nodes in both graphs
  child_ref <- which(ref[target,]==1 & ref[,target]==0) 
  child_est <- which(est[target,]==1 & est[,target]==0) 
  
  spouses_ref <- getSpouses(ref,child_ref,target)
  spouses_est <- getSpouses(est,child_est,target)
  
  # If a node is in both vectors, then it is a true positive
  # If it is in the reference but not in the estimated, then it is a false negative
  # If it is in the estimated but not the reference, then it is a false positive
  return(c(
    "tp"=length(intersect(spouses_ref,spouses_est)),
    "fn"=length(setdiff(spouses_ref,spouses_est)),
    "fp"=length(setdiff(spouses_est,spouses_ref))
  ))
}

getConnections <- function(g,target){
  if (!setequal(g[target,],g[,target])){
    warning("Some Markov Blankets don't agree")
  }
  # Get all target children or parents
  return(which(g[target,]==1 | g[,target]==1))
}

### Input the initial matrix from the MB estimation algorithm
# and determine which MB nodes were correctly identified
mbRecoveryMetricsList <- function(ref,est,targets){
  return(lapply(targets,function(target){
    # cat("Target:",target,"\n")
    # Get estimated MB nodes
    mb_nodes <- getConnections(est,target)
    # cat("Estimated Markov Blanket:",paste(mb_nodes,collapse = " "),"\n")
    children <- which(ref[target,]==1 & ref[,target]==0)
    # cat("True Children:",paste(children,collapse = " "),"\n")
    parents <- which(ref[,target]==1 & ref[target,]==0) 
    # cat("True Parents:",paste(parents,collapse = " "),"\n")
    spouses <- getSpouses(ref,children,target)
    # cat("True Spouses:",paste(spouses,collapse = " "),"\n")
    return(data.frame(
      "mb_children_fn"=sum(!(children %in% mb_nodes)),
      "mb_children_tp"=sum(children %in% mb_nodes),
      "mb_parents_fn"=sum(!(parents %in% mb_nodes)),
      "mb_parents_tp"=sum(parents %in% mb_nodes),
      "mb_spouses_fn"=sum(!(spouses %in% mb_nodes)),
      "mb_spouses_tp"=sum(spouses %in% mb_nodes),
      "mb_total_fp"=sum(!(mb_nodes %in% c(children,parents,spouses)))
    ))
  }))
}

mbRecoveryMetrics <- function(ref,est,targets){
  metrics_list <- mbRecoveryMetricsList(ref,est,targets)
  df <- as.data.frame(do.call(rbind,metrics_list))
  if (nrow(df)==1){
    return(df)
  } else {
    df <- apply(df,2,unlist)
    combined_results <- data.frame(t(colSums(df)))
    return(combined_results)
  }
}

spouseRecovery <- function(g,target){
  # First, obtain children
  children <- which(g[target,]==1 & g[,target]==0)
  # obtain reference spouses
  spouse <- getSpouses(g,children,target)
  return(spouse)
}

mbRecoveryTarget <- function(ref,est,target){
  
  # Obtain all children and parents from Reference and Target Graphs
  ref_nodes <- getConnections(ref,target)
  est_nodes <- getConnections(est,target)
  
  # Obtain spouse nodes from reference
  ref_nodes <- c(ref_nodes,spouseRecovery(ref,target))
  
  # Compare MB recovery
  return(
    c("mb_tp"=length(intersect(ref_nodes,est_nodes)),
      "mb_fn"=length(setdiff(ref_nodes,est_nodes)),
      "mb_fp"=length(setdiff(est_nodes,ref_nodes)))
  )
}

mbRecovery <- function(ref,est,targets){
  recovery_list <- lapply(targets,function(t) mbRecoveryTarget(ref,est,t))
  recovery_vec <- Reduce("+",recovery_list)
  return(data.frame(t(recovery_vec)))
}


