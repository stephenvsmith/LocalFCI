# Separation test is accurate

    There are 8 targets.
    Targets: asia tub smoke lung bronc either xray dysp
    Target: 0
    FUNCTION get_neighbors_from_dag. Node 0
    Call from get_neighbors_from_dag. Node 1 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 1
    Neighbors of node 0: 1
    
    Target: 1
    FUNCTION get_neighbors_from_dag. Node 1
    Call from get_neighbors_from_dag. Node 0 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
    Neighbors of node 1: 0, 3, 5
    
    Target: 2
    FUNCTION get_neighbors_from_dag. Node 2
    Call from get_neighbors_from_dag. Node 3 is a child.
    Call from get_neighbors_from_dag. Node 4 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 3
    Call from get_neighbors_from_dag. We are evaluating the following child: 4
    Neighbors of node 2: 3, 4
    
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Target: 5
    FUNCTION get_neighbors_from_dag. Node 5
    Call from get_neighbors_from_dag. Node 1 is a parent.
    Call from get_neighbors_from_dag. Node 3 is a parent.
    Call from get_neighbors_from_dag. Node 6 is a child.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 6
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
    Neighbors of node 5: 1, 3, 4, 6, 7
    
    Target: 6
    FUNCTION get_neighbors_from_dag. Node 6
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 6: 5
    
    Target: 7
    FUNCTION get_neighbors_from_dag. Node 7
    Call from get_neighbors_from_dag. Node 4 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 7: 4, 5
    
    Total Neighborhood:
    
    There are 8 nodes in the DAG.
    There are 8 nodes in the neighborhood.
    All nodes being considered: 0 1 2 3 4 5 6 7
    Our starting matrix is 8x8.
    0 1 1 1 1 1 1 1
    1 0 1 1 1 1 1 1
    1 1 0 1 1 1 1 1
    1 1 1 0 1 1 1 1
    1 1 1 1 0 1 1 1
    1 1 1 1 1 0 1 1
    1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 0
    
    
    
    Our initial separating sets:
    S[[0]][[0]] = nan S[[0]][[1]] = nan S[[0]][[2]] = nan S[[0]][[3]] = nan S[[0]][[4]] = nan S[[0]][[5]] = nan S[[0]][[6]] = nan S[[0]][[7]] = nan 
    S[[1]][[0]] = nan S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[4]] = nan S[[1]][[5]] = nan S[[1]][[6]] = nan S[[1]][[7]] = nan 
    S[[2]][[0]] = nan S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = nan S[[2]][[6]] = nan S[[2]][[7]] = nan 
    S[[3]][[0]] = nan S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = nan S[[3]][[5]] = nan S[[3]][[6]] = nan S[[3]][[7]] = nan 
    S[[4]][[0]] = nan S[[4]][[1]] = nan S[[4]][[2]] = nan S[[4]][[3]] = nan S[[4]][[4]] = nan S[[4]][[5]] = nan S[[4]][[6]] = nan S[[4]][[7]] = nan 
    S[[5]][[0]] = nan S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[4]] = nan S[[5]][[5]] = nan S[[5]][[6]] = nan S[[5]][[7]] = nan 
    S[[6]][[0]] = nan S[[6]][[1]] = nan S[[6]][[2]] = nan S[[6]][[3]] = nan S[[6]][[4]] = nan S[[6]][[5]] = nan S[[6]][[6]] = nan S[[6]][[7]] = nan 
    S[[7]][[0]] = nan S[[7]][[1]] = nan S[[7]][[2]] = nan S[[7]][[3]] = nan S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[6]] = nan S[[7]][[7]] = nan 
    Element mapping for efficient ordering:
    0 0
    1 1
    2 2
    3 3
    4 4
    5 5
    6 6
    7 7
    The p-value is 0.631592
    tub is separated from lung (p-value>0.01)

---

    There are 8 targets.
    Targets: asia tub smoke lung bronc either xray dysp
    Target: 0
    FUNCTION get_neighbors_from_dag. Node 0
    Call from get_neighbors_from_dag. Node 1 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 1
    Neighbors of node 0: 1
    
    Target: 1
    FUNCTION get_neighbors_from_dag. Node 1
    Call from get_neighbors_from_dag. Node 0 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
    Neighbors of node 1: 0, 3, 5
    
    Target: 2
    FUNCTION get_neighbors_from_dag. Node 2
    Call from get_neighbors_from_dag. Node 3 is a child.
    Call from get_neighbors_from_dag. Node 4 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 3
    Call from get_neighbors_from_dag. We are evaluating the following child: 4
    Neighbors of node 2: 3, 4
    
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Target: 5
    FUNCTION get_neighbors_from_dag. Node 5
    Call from get_neighbors_from_dag. Node 1 is a parent.
    Call from get_neighbors_from_dag. Node 3 is a parent.
    Call from get_neighbors_from_dag. Node 6 is a child.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 6
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
    Neighbors of node 5: 1, 3, 4, 6, 7
    
    Target: 6
    FUNCTION get_neighbors_from_dag. Node 6
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 6: 5
    
    Target: 7
    FUNCTION get_neighbors_from_dag. Node 7
    Call from get_neighbors_from_dag. Node 4 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 7: 4, 5
    
    Total Neighborhood:
    
    There are 8 nodes in the DAG.
    There are 8 nodes in the neighborhood.
    All nodes being considered: 0 1 2 3 4 5 6 7
    Our starting matrix is 8x8.
    0 1 1 1 1 1 1 1
    1 0 1 1 1 1 1 1
    1 1 0 1 1 1 1 1
    1 1 1 0 1 1 1 1
    1 1 1 1 0 1 1 1
    1 1 1 1 1 0 1 1
    1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 0
    
    
    
    Our initial separating sets:
    S[[0]][[0]] = nan S[[0]][[1]] = nan S[[0]][[2]] = nan S[[0]][[3]] = nan S[[0]][[4]] = nan S[[0]][[5]] = nan S[[0]][[6]] = nan S[[0]][[7]] = nan 
    S[[1]][[0]] = nan S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[4]] = nan S[[1]][[5]] = nan S[[1]][[6]] = nan S[[1]][[7]] = nan 
    S[[2]][[0]] = nan S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = nan S[[2]][[6]] = nan S[[2]][[7]] = nan 
    S[[3]][[0]] = nan S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = nan S[[3]][[5]] = nan S[[3]][[6]] = nan S[[3]][[7]] = nan 
    S[[4]][[0]] = nan S[[4]][[1]] = nan S[[4]][[2]] = nan S[[4]][[3]] = nan S[[4]][[4]] = nan S[[4]][[5]] = nan S[[4]][[6]] = nan S[[4]][[7]] = nan 
    S[[5]][[0]] = nan S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[4]] = nan S[[5]][[5]] = nan S[[5]][[6]] = nan S[[5]][[7]] = nan 
    S[[6]][[0]] = nan S[[6]][[1]] = nan S[[6]][[2]] = nan S[[6]][[3]] = nan S[[6]][[4]] = nan S[[6]][[5]] = nan S[[6]][[6]] = nan S[[6]][[7]] = nan 
    S[[7]][[0]] = nan S[[7]][[1]] = nan S[[7]][[2]] = nan S[[7]][[3]] = nan S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[6]] = nan S[[7]][[7]] = nan 
    Element mapping for efficient ordering:
    0 0
    1 1
    2 2
    3 3
    4 4
    5 5
    6 6
    7 7
    There is 1 neighbor.
    Efficient Setup: 1 -> 1 | 3 -> 3 | k (True Vals): 5 (either)
    The p-value is 7.20705e-08
    tub is NOT separated from lung by node(s): either  (p-value<0.01)

