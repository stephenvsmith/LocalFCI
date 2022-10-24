library(tidyverse)
data("asiaDAG")
nodes <- colnames(asiaDAG)
p <- ncol(asiaDAG)

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
  expect_equal(check_amat_works_onepar(nodes),complete_graph)
  
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
  # Neighbor of "asia" should be "tub"
  target <- which(nodes=="asia")-1
  result <- which(nodes=="tub")-1
  expect_equal(check_neighbors_retrieval(p,nodes,asiaDAG,target),result)
  expect_warning(expect_warning(check_neighbors_retrieval(3,nodes,asiaDAG,target)))
  
  # Neighbors of "either" should be "bronc" (spouse), "dysp" and "xray" (children), and "lung" and "tub" (parents)
  # expect_equal(sort(nodes[get_neighbors_from_dag(which(nodes=="either")-1,p,asiaDAG,verbose=FALSE)+1]),c("bronc","dysp","lung","tub","xray"))
  
  # Check if adjacent nodes are properly detected
  expect_false(checkIfNeighbors(p,nodes,asiaDAG,which(nodes=="asia")-1,which(nodes=="dysp")-1))
  expect_true(checkIfNeighbors(p,nodes,asiaDAG,which(nodes=="asia")-1,which(nodes=="tub")-1))
  expect_false(checkIfNeighbors(p,nodes,asiaDAG,which(nodes=="bronc")-1,which(nodes=="lung")-1))
  expect_true(checkIfNeighbors(p,nodes,asiaDAG,which(nodes=="bronc")-1,which(nodes=="smoke")-1))
})

test_that("Testing miscellaneous graph functions",{
  expect_equal(checkEmptyGraph(10),matrix(0,ncol = 10,nrow = 10))
  expect_snapshot_output(check_dag_object2(10))
})

test_that("Testing acyclicity",{
  expect_true(checkAcyclicity(p,nodes,asiaDAG))
  
  amat <- matrix(c(
    0,1,0,0,1,
    0,0,1,0,0,
    0,0,0,1,1,
    0,0,0,0,0,
    0,1,0,0,0
  ),nrow = 5,ncol=5,byrow = TRUE)
  expect_false(checkAcyclicity(5,LETTERS[1:5],amat))
  
  expect_true(checkAcyclicity(0,nodes,matrix(nrow = 0,ncol = 0)))
})

test_that("Test for identifying ancestors",{
  checkIsAncestor(p,nodes,asiaDAG,7,0,TRUE)
  g <- empty.graph(nodes)
  amat(g) <- asiaDAG
  for (i in 1:p){
    for (j in 1:p){
      if (i!=j){
        expect_equal(checkIsAncestor(p,nodes,asiaDAG,i-1,j-1),
                     nodes[j] %in% bnlearn::ancestors(g,nodes[i]))
        expect_equal(checkIsAncestor(p,nodes,asiaDAG,j-1,i-1),
                     nodes[i] %in% bnlearn::ancestors(g,nodes[j]))
      } else {
        expect_warning(res <- checkIsAncestor(p,nodes,asiaDAG,i-1,j-1),NA)
        expect_false(res)
      }
    }
  }
})

test_that("Testing for correct errors and warnings",{
  # different numbers of rows and columns
  expect_error(check_amat_works(5,paste0("V",1:5),matrix(0,nrow = 5,ncol = 4)))
  
  # Index for getNeighbors (DAG) is invalid
  expect_error(check_neighbors_retrieval(p,nodes,asiaDAG,p))
  expect_error(check_neighbors_retrieval(p,nodes,asiaDAG,-3))
  expect_error(check_neighbors_retrieval(p,nodes,asiaDAG,p+1))
  expect_error(check_neighbors_retrieval(p,nodes,asiaDAG,p-1),NA)
  
  # Index for getAdjacent (Graph) is invalid
  expect_error(check_adjacent_non_adjacent(p,nodes,asiaDAG,p))
  expect_error(check_adjacent_non_adjacent(p,nodes,asiaDAG,-2))
  expect_error(check_adjacent_non_adjacent(p,nodes,asiaDAG,p+1))
  expect_error(check_adjacent_non_adjacent(p,nodes,asiaDAG,p-1),NA)
  
  # Index for getNonAdjacent (Graph) is invalid
  expect_error(check_non_adjacent_solo(p,nodes,asiaDAG,p))
  expect_error(check_non_adjacent_solo(p,nodes,asiaDAG,-1))
  expect_error(check_non_adjacent_solo(p,nodes,asiaDAG,p+1))
  expect_error(check_non_adjacent_solo(p,nodes,asiaDAG,p-1),NA)
  
  # Index for getAmatVal is invalid
  n_names <- colnames(asiaDAG)
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,p,0))
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,0,p))
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,p+1,0))
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,0,p+1))
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,p-1,0),NA)
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,0,p-1),NA)
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,-2,0))
  expect_error(check_amat_retrieval_function(p,n_names,asiaDAG,0,-1))
  
  # Index for getAmat(Col|Row) is invalid
  expect_error(check_amat_row_retrieval(p,n_names,asiaDAG,p))
  expect_error(check_amat_row_retrieval(p,n_names,asiaDAG,p-1),NA)
  expect_error(check_amat_row_retrieval(p,n_names,asiaDAG,p+1))
  expect_error(check_amat_row_retrieval(p,n_names,asiaDAG,-1))
  expect_error(check_amat_col_retrieval(p,n_names,asiaDAG,p))
  expect_error(check_amat_col_retrieval(p,n_names,asiaDAG,p-1),NA)
  expect_error(check_amat_col_retrieval(p,n_names,asiaDAG,p+1))
  expect_error(check_amat_col_retrieval(p,n_names,asiaDAG,-1))
})

test_that("Testing inNeighborhood function",{
  true_amat <- matrix(c(
    0,0,0,0,0,0,
    1,0,0,0,0,0,
    1,1,0,0,0,0,
    0,0,0,0,0,1,
    0,0,0,0,0,1,
    0,0,1,0,0,0
  ),byrow = TRUE,ncol = 6)
  correct_responses <- tibble(
    "i"=rep(0:5,each=6),
    "j"=rep(0:5,6),
    "result"=c(
      TRUE,TRUE,TRUE,FALSE,FALSE,FALSE,
      TRUE,TRUE,TRUE,FALSE,FALSE,FALSE,
      TRUE,TRUE,TRUE,FALSE,FALSE,TRUE,
      FALSE,FALSE,FALSE,TRUE,TRUE,TRUE,
      FALSE,FALSE,FALSE,TRUE,TRUE,TRUE,
      FALSE,FALSE,TRUE,TRUE,TRUE,TRUE
    )
  )
  for (i in 0:5){
    for (j in setdiff(0:5,i)){
      true_val <- correct_responses %>% 
        filter(i==!!i) %>% filter(j==!!j) %>% 
        select(result) %>% unlist()
      names(true_val) <- NULL
      cat("i =",i,"|","j =",j,"| ")
      cat(checkInNeighborhood(p,nodes,true_amat,i,j),"|",
          true_val,
          "\n")
      expect_equal(checkInNeighborhood(p,nodes,true_amat,i,j),true_val)
    }
  }
})




