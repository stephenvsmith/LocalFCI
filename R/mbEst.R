# This function will return the Markov Blanket for a target value
getMB <- function(target,dataset,threshold=0.01,method="MMPC",test="testIndFisher",verbose=FALSE){
  if (verbose) cat("Estimating Markov Blankets using\n",
                   "Algorithm:",method,"\n",
                   "Test:",test,"\n",
                   "Tolerance:",threshold,"\n")

  if (method=="MMPC"){
    mb <- MXM::MMPC(target=target,dataset=dataset,threshold=threshold,test=test)
  } else if (method=="SES"){
    mb <- MXM::SES(target=target,dataset=dataset,threshold=threshold,test=test)
  } else if (method=="gOMP"){
    mb <- MXM::gomp(target=target,dataset=dataset,test = test)$res[,1] # there are more options here to explore, also need to look closer at output
  } # There is also fbed.reg, 
  if (verbose) cat("Results for target",target,":",paste(mb@selectedVars,collapse = ","),"\n")
  return(list("mb"=mb@selectedVars,
              "time"=mb@runtime[3]))
}


# This function will take a vector of targets and return a list of the markov blankets
getAllMBs <- function(targets,dataset,threshold=0.01,method="MMPC",
                      test="testIndFisher",verbose=TRUE){
  target_mbs <- lapply(targets,
                       function(t) getMB(t,dataset,threshold,method,test,verbose))
  additional_nodes <- unique(
    setdiff(
      getAllMBNodes(target_mbs),targets))
  if (length(additional_nodes)>0){
    second_order_mbs <- lapply(additional_nodes,
                               function(t) 
                                 getMB(t,dataset,
                                       threshold,
                                       method,
                                       test,verbose))
    final_list <- c(target_mbs,second_order_mbs)
    names(final_list) <- as.character(c(targets,additional_nodes))
    return(final_list)
  } else {
    names(target_mbs) <- as.character(targets)
    return(target_mbs)
  }
}

# This function will take a list of Markov Blankets and form an adjacency matrix
# All Markov Blanket nodes will be considered children of the 
# targets and first-order neighbors for simplicity
getEstInitialDAG <- function(mbList,p,verbose=FALSE){
  if (verbose) cat("Creating the reference DAG using Markov Blanket list.\n")
  adj <- matrix(0,nrow = p,ncol = p)
  all_nodes <- as.numeric(names(mbList))
  nodes_seq <- all_nodes
  lapply(1:length(nodes_seq),function(i){
    node <- all_nodes[i]
    mb <- mbList[[as.character(node)]][["mb"]]
    if (length(mb)>0){
      sapply(mb,function(x){
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
    c("tp"=length(intersect(ref_nodes,est_nodes)),
      "fn"=length(setdiff(ref_nodes,est_nodes)),
      "fp"=length(setdiff(est_nodes,ref_nodes)))
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



