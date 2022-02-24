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
  return(list("mb"=mb@selectedVars,
              "time"=mb@runtime[3]))
}

# This function will take a vector of targets and return a list of the markov blankets
getAllMBs <- function(targets,dataset,threshold=0.01,method="MMPC",
                      test="testIndFisher",verbose=TRUE){
  return(lapply(targets,
                function(t) getMB(t,dataset,threshold,method,test,verbose)))
}

# This function will take a list of Markov Blankets and form an adjacency matrix
# All Markov Blanket nodes will be considered parents of the target for simplicity
getEstInitialDAG <- function(mbList,targets,p,verbose=FALSE){
  
  if (verbose) cat("Creating the reference DAG using Markov Blanket list.\n")
  adj <- matrix(0,nrow = p,ncol = p)
  all_nodes <- targets
  lapply(1:length(targets),function(i){
    target <- targets[i]
    mb <- mbList[[i]][["mb"]]
    adj[mb,target] <<- 1
    all_nodes <<- union(all_nodes,mb)
    # sapply(mb,function(neighbor){
    #   adj[neighbor,target] <<- 1
    # })
  })
  if (verbose) cat("Nodes being considered:",
                   paste(all_nodes,collapse = ","),
                   "\n\n")
  return(adj)
}

getTotalMBTime <- function(mbList){
  return(sum(sapply(mbList,function(mb){
    return(mb[["time"]])
  })))
}
