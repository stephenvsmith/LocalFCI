# This function will return the Markov Blanket for a target value
getMB <- function(target,dataset,threshold=0.01,method="MMPC",test="testIndFisher"){
  if (method=="MMPC"){
    mb <- MXM::MMPC(target=target,dataset=dataset,threshold=threshold,test=test)
  } else if (method=="SES"){
    mb <- MXM::SES(target=target,dataset=dataset,threshold=threshold,test=test)
  }
  return(list("mb"=mb@selectedVars,
              "time"=mb@runtime[3]))
}

# This function will take a vector of targets and return a list of the markov blankets
getAllMBs <- function(targets,dataset,threshold=0.01,method="MMPC"){
  return(lapply(targets,getMB,dataset,threshold,method))
}

# This function will take a list of Markov Blankets and form an adjacency matrix
# All Markov Blanket nodes will be considered parents of the target for simplicity
getEstInitialDAG <- function(mbList,targets,p){
  adj <- matrix(0,nrow = p,ncol = p)
  lapply(1:length(targets),function(i){
    target <- targets[i]
    mb <- mbList[[i]][["mb"]]
    adj[mb,target] <<- 1

    # sapply(mb,function(neighbor){
    #   adj[neighbor,target] <<- 1
    # })
  })
  return(adj)
}

getTotalMBTime <- function(mbList){
  return(sum(sapply(mbList,function(mb){
    return(mb[["time"]])
  })))
}
