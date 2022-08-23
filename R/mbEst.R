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
#' @export
getMB <- function(target,dataset,threshold=0.01,method="MMPC",test="testIndFisher",verbose=FALSE){
  if (verbose) cat("Estimating Markov Blankets using\n",
                   "Algorithm:",method,"\n",
                   "Test:",test,"\n",
                   "Tolerance:",threshold,"\n")
  
  if (threshold<=0 | threshold > 1){
    stop("MB Estimation threshold is invalid. Threshold must be in (0,1]")
  }
  
  if (!(method %in% c("MMPC","SES","gOMP"))){
    stop("Invalid MB estimation algorithm")
  }
  
  if (!(target %in% seq(1,ncol(dataset)))){
    stop(paste0("Invalid target index (t=",target,")"))
  }
  
  if (method=="MMPC"){
    mb <- MXM::MMPC(target=target,dataset=dataset,threshold=threshold,test=test)
  } else if (method=="SES"){
    mb <- MXM::SES(target=target,dataset=dataset,threshold=threshold,test=test)
  } 
  # else if (method=="gOMP"){
  #   mb <- MXM::gomp(target=target,dataset=dataset,test = test)$res[,1] # there are more options here to explore, also need to look closer at output
  # } # There is also fbed.reg, 
  if (verbose) cat("Results for target",target,":",paste(mb@selectedVars,collapse = ","),"\n")
  return(list("mb"=mb@selectedVars,
              "time"=mb@runtime[3]))
}

constructFinalMBList <- function(targets,target_mbs,
                                 dataset,threshold,method,test,verbose){
  # A vector to identify only the first-order neighbors
  first_order_neighbors <- unique(
    setdiff(
      getAllMBNodes(target_mbs),targets))
  # Apply MB algorithm again to obtain second-order neighbors
  if (length(first_order_neighbors)>0){
    second_order_mbs <- lapply(first_order_neighbors,
                               function(t) 
                                 getMB(t,dataset,
                                       threshold,
                                       method,
                                       test,verbose))
    # Combine first-order MBs and second-order MBs in one list
    final_list <- c(target_mbs,second_order_mbs)
    names(final_list) <- as.character(c(targets,
                                        first_order_neighbors))
    return(final_list)
  } else {
    names(target_mbs) <- as.character(targets)
    return(target_mbs)
  }
}


#' Estimate Markov Blankets of a vector of target nodes
#' 
#' `getAllMBs()` applies Markov Blanket algorithms to a vector of target nodes and
#' their first-order neighbors
#' 
#' @param targets a vector of integers which will identify the target nodes of our algorithm
#' @inheritParams getMB
#' @export
getAllMBs <- function(targets,dataset,threshold=0.01,method="MMPC",
                      test="testIndFisher",verbose=TRUE){
  p <- ncol(dataset)
  if (!(all(targets %in% seq(p)))){
    stop("Invalid target values for MB Estimation procedure")
  }
  
  if (any(duplicated(targets))){
    warning("Duplicate targets inputted. Removing duplicates.")
    targets <- unique(targets)
  }
  
  # Find the MBs for the target nodes
  target_mbs <- lapply(targets,
                       function(t) getMB(t,dataset,threshold,method,test,verbose))
  
  return(constructFinalMBList(targets,target_mbs,dataset,
                              threshold,method,test,verbose))
}


# This function will take a list of Markov Blankets and form an adjacency matrix
# All Markov Blanket nodes will be considered children of the 
# targets and first-order neighbors for simplicity
#' Create Initial Graph from MB List
#' 
#' `getEstInitialDAG()` connects nodes in a list containing Markov Blankets for an initial graph used by our local algorithms. 
#' For simplicity, all nodes in a Markov Blanket will be considered a child of the target or first-order neighbor in the initial adjacency matrix.
#' 
#' @param mbList is a named list containing the estimated Markov Blankets for the targets and their first-order neighbors
#' @param p is the number of nodes in the graph
#' @param verbose 
getEstInitialDAG <- function(mbList,p,verbose=FALSE){
  if (verbose) cat("Creating the reference DAG using Markov Blanket list.\n")
  
  if (p <= 0){
    stop("Invalid network size p")
  }
  
  if (length(mbList)==0){
    stop("MB List is empty")
  }
  
  adj <- matrix(0,nrow = p,ncol = p)
  all_nodes <- as.numeric(names(mbList))
  nodes_seq <- all_nodes
  lapply(1:length(nodes_seq),function(i){
    node <- all_nodes[i]
    mb <- mbList[[as.character(node)]][["mb"]]
    if (length(mb)>0){
      sapply(mb,function(x){
        if (node > p | x > p){
          stop("Invalid index. The value for p is too small.\n")
        }
        if (adj[node,x]==0 & adj[x,node]==0){
          adj[node,x] <<- 1
        }
      })
      all_nodes <<- union(all_nodes,mb)
    }
  })
  if (verbose) cat("Nodes being considered:",
                   paste(sort(all_nodes),collapse = ","),
                   "\n\n")
  return(adj)
}

# Obtain the total time taken for estimating the Markov Blankets as stored in the
# value returned by the `getMB` function
getTotalMBTime <- function(mbList){
  return(sum(sapply(mbList,function(mb){
    return(mb[["time"]])
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

# Measurement Function ----------------------------------------------------

# Calculate metrics for recovery of Markov Blankets
calcUndirRecovery <- function(ref,est,target){
  # Get all the nodes connected to target via undirected edge in both graphs
  undir_ref <- which(ref[target,]==1 & ref[,target]==1) 
  undir_est <- which(est[target,]==1 & est[,target]==1) 
  # If a node is in both vectors, then it is a true positive
  # If it is in the reference but not in the estimated, then it is a false negative
  # If it is in the estimated but not the reference, then it is a false positive
  return(c(
    "tp"=length(intersect(undir_ref,undir_est)),
    "fn"=length(setdiff(undir_ref,undir_est)),
    "fp"=length(setdiff(undir_est,undir_ref))
  ))
}

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

mbRecoveryMetricsList <- function(ref,est,targets){
  return(lapply(targets,function(target){
    list(
      "undirected"=calcUndirRecovery(ref,est,target),
      "parent"=calcParentRecovery(ref,est,target),
      "child"=calcChildRecovery(ref,est,target),
      "spouse"=calcSpouseRecovery(ref,est,target)
    )
  }))
}

getConnections <- function(g,target){
  # Get all target children or parents
  return(which(g[target,]==1 | g[,target]==1))
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
  recoveryList <- lapply(targets,function(t) mbRecoveryTarget(ref,est,t))
  return(Reduce("+",recoveryList))
}

mbRecoverySpecific <- function(mbRecList){
  return(
    data.frame(
      "undirectedMB_fn"=sum(sapply(mbRecList,function(x) return(x$undirected['fn']))),
      "undirectedMB_fp"=sum(sapply(mbRecList,function(x) return(x$undirected['fp']))),
      "undirectedMB_tp"=sum(sapply(mbRecList,function(x) return(x$undirected['tp']))),
      "parentMB_fn"=sum(sapply(mbRecList,function(x) return(x$parent['fn']))),
      "parentMB_fp"=sum(sapply(mbRecList,function(x) return(x$parent['fp']))),
      "parentMB_tp"=sum(sapply(mbRecList,function(x) return(x$parent['tp']))),
      "childMB_fn"=sum(sapply(mbRecList,function(x) return(x$child['fn']))),
      "childMB_fp"=sum(sapply(mbRecList,function(x) return(x$child['fp']))),
      "childMB_tp"=sum(sapply(mbRecList,function(x) return(x$child['tp']))),
      "spouseMB_fn"=sum(sapply(mbRecList,function(x) return(x$spouse['fn']))),
      "spouseMB_fp"=sum(sapply(mbRecList,function(x) return(x$spouse['fp']))),
      "spouseMB_tp"=sum(sapply(mbRecList,function(x) return(x$spouse['tp'])))
    )
  )
}



