test_that("Checking to make sure the Graph class works",{
  # Create an arbitrary graph
  set.seed(123)
  nodes <- 4
  n_names <- letters[1:nodes]
  adj <- matrix(sample(c(0,1),nodes^2,replace = TRUE),ncol = nodes)
  diag(adj) <- 0
  # Make a slight adjustment so we can check spousal recovery
  adj[1,4] <- 0
  adj[1,3] <- 1
  
  # Check to make sure that the adjacency matrix is properly saved
  expect_equal(check_amat_works(nodes,n_names,adj),adj)
  # Should give us a complete graph if we only supply the nodes
  complete_graph <- matrix(1,nrow = nodes,ncol = nodes)
  diag(complete_graph) <- 0
  # Check that the one parameter constructor works and creates a complete graph on the vertex set
  expect_equal(check_amat_works_onepar(nodes),complete_graph) #TODO: ADD A VERBOSE ARGUMENT
  # Check that the node names are correctly specified
  expect_equal(check_names_works(nodes,n_names,adj),n_names)
  # Check to make sure neighbor detection functions work
  expect_equal(check_dag_object(nodes,n_names,adj),list("OneNeighbor"=c(0,1,2),"TwoNeighbors"=c(1,3)))
  
  # Check to make sure adj. mat. value "getter" is correct
  for (i in 1:nodes){
    expect_equal(check_amat_row_retrieval(nodes,n_names,adj,i-1),adj[i,])
    cat('\n')
    cat("Row",i,":",unlist(check_adjacent_non_adjacent(nodes,n_names,adj,i-1)['adj'],use.names = FALSE))
    expect_equal(unlist(check_adjacent_non_adjacent(nodes,n_names,adj,i-1)['adj'],use.names = FALSE),
                 sort(union(which(adj[i,]!=0)-1,which(adj[,i]!=0)-1)))
    for (j in 1:nodes){
      expect_equal(check_amat_retrieval(nodes,n_names,adj,i-1,j-1),adj[i,j])
      expect_equal(check_amat_col_retrieval(nodes,n_names,adj,j-1),adj[,j])
    }
  }
  
  # Check to make sure adj. mat. "setter" works
  adj_test <- adj
  for (i in 1:nodes){
    for (j in 1:nodes){
      expect_equal(check_amat_retrieval(nodes,n_names,adj,i-1,j-1),adj_test[i,j])
      val <- sample(1:6,1)
      adj_test[i,j] <- val
      expect_equal(check_amat_setval(nodes,n_names,adj,i-1,j-1,val),adj_test[i,j])
    }
  }
  
})

test_that("Testing Graph and DAG classes using asia data",{
  data("asiaDAG")
  nodes <- colnames(asiaDAG)
  p <- ncol(asiaDAG)
  
  # Neighbor of "asia" should be "tub"
  target <- which(nodes=="asia")-1
  result <- which(nodes=="tub")-1
  expect_equal(check_neighbors_retrieval(p,nodes,asiaDAG,target),result)
  
  # Neighbors of "either" should be "bronc" (spouse), "dysp" and "xray" (children), and "lung" and "tub" (parents)
  # expect_equal(sort(nodes[get_neighbors_from_dag(which(nodes=="either")-1,p,asiaDAG,verbose=FALSE)+1]),c("bronc","dysp","lung","tub","xray"))
})
