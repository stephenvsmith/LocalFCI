adj.mat.example <- matrix(c(0,1,0,1,0,0,
                            1,0,1,0,1,1,
                            0,1,0,1,0,1,
                            1,0,1,0,1,1,
                            0,1,0,1,0,1,
                            0,1,1,1,1,0),nrow = 6,byrow = TRUE)
nodes <- paste0("X",1:6)
ex <- empty.graph(nodes)
amat(ex) <- adj.mat.example
graphviz.plot(ex)

S <- create_conditioning_sets_efficient_cpp2(0:5)
S[["0"]][["2"]] <- 3
S[["2"]][["0"]] <- 3
S[["1"]][["3"]] <- 2
S[["3"]][["1"]] <- 2
S[["2"]][["4"]] <- 1
S[["4"]][["2"]] <- 1
S[["0"]][["4"]] <- c(1,2,3)
S[["4"]][["0"]] <- c(1,2,3)
S[["0"]][["5"]] <- c(1,2,3)
S[["5"]][["0"]] <- c(1,2,3)
S


my_verbose <- TRUE
my_list <- list("S"=S,"C"=adj.mat.example,"neighborhood"=0:5,
                "names"=nodes,verbose=my_verbose,"p"=6)
nbhd <- 0:5
p <- 6
NumTests <- 50

my_list <- get_v_structures_efficient(convert_list(S,adj.mat.example,nbhd,nodes,my_verbose,p,NumTests))

G <- rule1(my_list$G)
Gnew <- rule2(G$G)
Gnew <- rule3(G$G)
Gnew <- rule4(G$G,S)
Gnew2 <- rule8(G$G)
Gnew2 <- rule9(G$G)
Gnew2 <- rule10(G$G)

my_list2 <- get_v_structures_efficient(convert_list(S,G$G,nbhd,nodes,my_verbose,p,NumTests))
Gnew2 <- rule1(G$G)
Gnew3 <- rule2(Gnew2$G)
Gnew3 <- rule3(Gnew2$G)
Gnew3 <- rule4(Gnew2$G,S)
Gnew3 <- rule8(Gnew2$G)
Gnew3 <- rule9(Gnew2$G)
Gnew3 <- rule10(Gnew2$G)
