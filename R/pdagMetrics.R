library(ggm)

# Create metrics for PDAG precision/recall/F1 against the underlying MAG
getPDAGMetrics <- function(est_mat,true_dag,node_names,rm_nodes){
  # Establish the underlying MAG 
  mag_amat <- MAG(true_dag,M=node_names[rm_nodes],plot = TRUE)
  return(mag_amat)
}