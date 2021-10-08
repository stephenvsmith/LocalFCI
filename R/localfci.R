localfci_cpp <- function(data=NULL,true_dag=NULL,targets,lmax=3,tol=0.05,
                        verbose = TRUE){
  node_names <- colnames(true_dag)
  if (is.data.frame(data)){
    data <- as.matrix(data)
  }
  
  if (is.data.frame(true_dag)){
    true_dag <- as.matrix(true_dag)
  }
  
  # We change the target to target - 1 in order to accommodate change to C++
  return(fci(true_dag,data,targets-1,node_names,lmax,tol,verbose))
}