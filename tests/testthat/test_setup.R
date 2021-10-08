test_that("Obtains the correct neighborhood from the reference graph (1 target)",{
  data("asiaDAG")
  nodes <- colnames(asiaDAG)
  p <- ncol(asiaDAG)
  
  # Neighbor of "asia" should be "tub"
  expect_equal(nodes[get_neighbors_from_dag(0,p,asiaDAG,verbose=FALSE)+1],"tub")
  # Neighbors of "either" should be "bronc" (spouse), "dysp" and "xray" (children), and "lung" and "tub" (parents)
  expect_equal(sort(nodes[get_neighbors_from_dag(which(nodes=="either")-1,p,asiaDAG,verbose=FALSE)+1]),c("bronc","dysp","lung","tub","xray"))
})

test_that("Obtains the correct neighborhood from the reference graph (multiple targets)",{
  data("asiaDAG")
  nodes <- colnames(asiaDAG)
  p <- ncol(asiaDAG)
  
  # Neighbors of "either","asia", and "lung" should be "smoke", "either", "bronc", "dysp", "xray", "lung", and "tub"
  expect_equal(sort(nodes[
    get_multiple_neighbors_from_dag(c(0,which(nodes=="either")-1,which(nodes=="lung")-1),
                           p,asiaDAG,verbose=FALSE)+1]),
    c("bronc","dysp","either","lung","smoke","tub","xray"))
})

test_that("Create conditioning sets correctly",{
  data("asiaDAG")
  
  nodes <- colnames(asiaDAG)
  p <- ncol(asiaDAG)
  target <- 5 # "either" is the target
  neighbors <- get_neighbors_from_dag(target,p,asiaDAG,FALSE)
  neighbor_names <- nodes[neighbors+1]
  expect_equal(nodes[target+1],"either")
  expect_equal(setdiff(neighbor_names,c("tub","lung","xray","dysp","bronc")),character(0))
  
  set.seed(111)
  neighborhood_full <- sample(1:8,8,replace = FALSE)
  S <- create_conditioning_sets_efficient_cpp2(neighborhood_full)
  expect_equal(sort(names(S)),as.character(1:8))
  expect_equal(sort(names(S$`1`)),as.character(setdiff(1:8,1)))
})

test_that("Complete setup is correct",{
  data("asiaDAG")
  targets <- c(5,0) # "either", "asia" are the targets
  setup <- fci_setup(asiaDAG,targets,colnames(asiaDAG),lmax = 3,verbose = FALSE)
  expect_equal(length(setup),9) 
  expect_equal(length(setup$S),7)
})
