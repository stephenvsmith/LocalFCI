my_dsep <- function(true_dag,x,y,z){
  tmp <- empty.graph(nodes=as.character(1:ncol(true_dag)))
  if (!is.null(colnames(true_dag))){
    colnames(true_dag) <- NULL
  }
  if (!is.null(rownames(true_dag))){
    rownames(true_dag) <- NULL
  }
  amat(tmp) <- true_dag

  if (nrow(z)==0){
    res <- as.numeric(bnlearn::dsep(tmp,as.character(x+1),as.character(y+1)))
  } else {
    res <- as.numeric(bnlearn::dsep(tmp,as.character(x+1),as.character(y+1),as.character(z[,1]+1)))
  }
  return(res)
}