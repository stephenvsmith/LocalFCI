# Testing the LocalFCI object

    There is (are) 1 target(s).
    Targets: lung
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
    Total Neighborhood:
    1, 2, 5
    There are 8 nodes in the DAG.
    There are 4 nodes in the neighborhoods we are considering.
    All nodes being considered: 1 2 3 5
    Our starting matrix is 4x4.
    0 1 1 1
    1 0 1 1
    1 1 0 1
    1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[5]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[5]] = nan 
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    5 3
    
    
    p: 8
    n: 500
    N: 4
    Number of Targets: 1
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 5
    Ctilde:
    Our Ctilde matrix is 4x4
    0 1 1 1
    1 0 1 1
    1 1 0 1
    1 1 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[5]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[5]] = nan 
    First and last elements of the dataset: -0.641447 0.198884

# Testing the LocalFCI object (Population)

    There are 1 targets.
    Targets: lung
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
    Total Neighborhood:
    1, 2, 5
    There are 8 nodes in the DAG.
    There are 4 nodes in the neighborhood.
    All nodes being considered: 1 2 3 5
    Our starting matrix is 4x4.
    0 1 1 1
    1 0 1 1
    1 1 0 1
    1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[5]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[5]] = nan 
    Population Version
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    5 3
    
    
    p: 8
    n: 0
    N: 4
    Number of Targets: 1
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 5
    Ctilde:
    Our Ctilde matrix is 4x4
    0 1 1 1
    1 0 1 1
    1 1 0 1
    1 1 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[5]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[5]] = nan 

# Testing the total skeleton function (one target)

    There is (are) 1 target(s).
    Targets: lung
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
    Total Neighborhood:
    1, 2, 5
    There are 8 nodes in the DAG.
    There are 4 nodes in the neighborhoods we are considering.
    All nodes being considered: 1 2 3 5
    Our starting matrix is 4x4.
    0 1 1 1
    1 0 1 1
    1 1 0 1
    1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[5]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[5]] = nan 
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    5 3
    
    
    The value of l is 0
    The value of i is 0 (tub)
    The value of j is 1 (smoke)
    The p-value is 0.0664439
    tub is separated from smoke (p-value>0.01)
    The value of j is 2 (lung)
    The p-value is 0.631592
    tub is separated from lung (p-value>0.01)
    The value of j is 3 (either)
    The p-value is 2.96476e-07
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The p-value is 3.57115e-12
    The value of j is 3 (either)
    The p-value is 3.62121e-05
    The value of i is 2 (lung)
    The value of j is 3 (either)
    The p-value is 2.97187e-109
    The value of i is 3 (either)
    The value of l is 1
    The value of i is 0 (tub)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 0 -> 1 | 3 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 2.23369e-08
    tub is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 3 -> 5 | k (True Vals): 3 (lung)
    The p-value is 9.35856e-14
    tub is NOT separated from either by node(s): lung  (p-value<0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There is 1 neighbor.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
    The p-value is 6.33935e-09
    smoke is NOT separated from lung by node(s): either  (p-value<0.01)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 5 | k (True Vals): 3 (lung)
    The p-value is 0.0944292
    smoke is separated from either by node(s): lung  (p-value>0.01)
    The value of i is 2 (lung)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 5.05153e-105
    lung is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 3 -> 5 | k (True Vals): 1 (tub)
    The p-value is 3.10595e-117
    lung is NOT separated from either by node(s): tub  (p-value<0.01)
    The value of i is 3 (either)
    The value of l is 2
    The value of i is 0 (tub)
    The value of j is 3 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of i is 2 (lung)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 5 | k (True Vals): 1 2 (tub smoke)
    The p-value is 4.9879e-111
    lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
    The value of i is 3 (either)
    The value of l is 3
    The value of i is 0 (tub)
    The value of j is 3 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of i is 2 (lung)
    The value of j is 3 (either)
    The value of i is 3 (either)
    
    
    Values after Total Skeleton Run
    
    p: 8
    n: 500
    N: 4
    Number of Targets: 1
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 5
    Ctilde:
    Our Ctilde matrix is 4x4
    0 0 0 1
    0 0 1 0
    0 1 0 1
    1 0 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = -1 S[[1]][[3]] = -1 S[[1]][[5]] = nan 
    S[[2]][[1]] = -1 S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = 3 
    S[[3]][[1]] = -1 S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = 3 S[[5]][[3]] = nan S[[5]][[5]] = nan 
    First and last elements of the dataset: -0.641447 0.198884

# Testing the total skeleton function (two targets)

    There is (are) 2 target(s).
    Targets: lung bronc
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
    
    Total Neighborhood:
    1, 2, 5, 7
    There are 8 nodes in the DAG.
    There are 6 nodes in the neighborhoods we are considering.
    All nodes being considered: 1 2 3 4 5 7
    Our starting matrix is 6x6.
    0 1 1 1 1 1
    1 0 1 1 1 1
    1 1 0 1 1 1
    1 1 1 0 1 1
    1 1 1 1 0 1
    1 1 1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[4]] = nan S[[1]][[5]] = nan S[[1]][[7]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = nan S[[2]][[7]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = nan S[[3]][[5]] = nan S[[3]][[7]] = nan 
    S[[4]][[1]] = nan S[[4]][[2]] = nan S[[4]][[3]] = nan S[[4]][[4]] = nan S[[4]][[5]] = nan S[[4]][[7]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[4]] = nan S[[5]][[5]] = nan S[[5]][[7]] = nan 
    S[[7]][[1]] = nan S[[7]][[2]] = nan S[[7]][[3]] = nan S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[7]] = nan 
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    4 3
    5 4
    7 5
    
    
    The value of l is 0
    The value of i is 0 (tub)
    The value of j is 1 (smoke)
    The p-value is 0.0664439
    tub is separated from smoke (p-value>0.01)
    The value of j is 2 (lung)
    The p-value is 0.631592
    tub is separated from lung (p-value>0.01)
    The value of j is 3 (bronc)
    The p-value is 0.579122
    tub is separated from bronc (p-value>0.01)
    The value of j is 4 (either)
    The p-value is 2.96476e-07
    The value of j is 5 (dysp)
    The p-value is 0.0049716
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The p-value is 3.57115e-12
    The value of j is 3 (bronc)
    The p-value is 6.44217e-19
    The value of j is 4 (either)
    The p-value is 3.62121e-05
    The value of j is 5 (dysp)
    The p-value is 8.722e-05
    The value of i is 2 (lung)
    The value of j is 3 (bronc)
    The p-value is 0.00672051
    The value of j is 4 (either)
    The p-value is 2.97187e-109
    The value of j is 5 (dysp)
    The p-value is 9.83333e-14
    The value of i is 3 (bronc)
    The value of j is 4 (either)
    The p-value is 0.0431059
    bronc is separated from either (p-value>0.01)
    The value of j is 5 (dysp)
    The p-value is 6.74668e-84
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    The p-value is 9.48354e-32
    The value of i is 5 (dysp)
    The value of l is 1
    The value of i is 0 (tub)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 7 (dysp)
    The p-value is 1.75872e-05
    tub is NOT separated from either by node(s): dysp  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 (lung)
    The p-value is 9.35856e-14
    tub is NOT separated from either by node(s): lung  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 2.23369e-08
    tub is NOT separated from either by node(s): smoke  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 0.669315
    tub is separated from dysp by node(s): either  (p-value>0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 7 (dysp)
    The p-value is 1.85744e-19
    smoke is NOT separated from lung by node(s): dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 (bronc)
    The p-value is 1.73265e-10
    smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
    The p-value is 6.33935e-09
    smoke is NOT separated from lung by node(s): either  (p-value<0.01)
    The value of j is 3 (bronc)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 (lung)
    The p-value is 3.36192e-17
    smoke is NOT separated from bronc by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 7 (dysp)
    The p-value is 1.40787e-17
    smoke is NOT separated from bronc by node(s): dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 (either)
    The p-value is 5.30428e-18
    smoke is NOT separated from bronc by node(s): either  (p-value<0.01)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 3 (lung)
    The p-value is 0.0944292
    smoke is separated from either by node(s): lung  (p-value>0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 3 (lung)
    The p-value is 4.7219e-12
    smoke is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 4 (bronc)
    The p-value is 0.0018733
    smoke is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 2.3399e-12
    smoke is NOT separated from dysp by node(s): either  (p-value<0.01)
    The value of i is 2 (lung)
    The value of j is 3 (bronc)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 2 (smoke)
    The p-value is 0.868413
    lung is separated from bronc by node(s): smoke  (p-value>0.01)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 (bronc)
    The p-value is 7.07433e-108
    lung is NOT separated from either by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 (tub)
    The p-value is 3.10595e-117
    lung is NOT separated from either by node(s): tub  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 5.05153e-105
    lung is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 7 (dysp)
    The p-value is 1.21991e-94
    lung is NOT separated from either by node(s): dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 4.8985e-21
    lung is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 4 (bronc)
    The p-value is 3.01325e-48
    lung is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 0.0810771
    lung is separated from dysp by node(s): either  (p-value>0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    There are 2 neighbors.
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 3.28744e-82
    bronc is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 1.86754e-176
    bronc is NOT separated from dysp by node(s): either  (p-value<0.01)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 3 (lung)
    The p-value is 1.21054e-19
    either is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 (tub)
    The p-value is 7.29264e-30
    either is NOT separated from dysp by node(s): tub  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 1.15967e-39
    either is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 4 (bronc)
    The p-value is 8.04073e-114
    either is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    The value of l is 2
    The value of i is 0 (tub)
    The value of j is 4 (either)
    There are 2 neighbors.
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 7 (lung dysp)
    The p-value is 6.06083e-12
    tub is NOT separated from either by node(s): lung dysp  (p-value<0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 7 (bronc dysp)
    The p-value is 2.32256e-08
    smoke is NOT separated from lung by node(s): bronc dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 7 (either dysp)
    The p-value is 3.23618e-08
    smoke is NOT separated from lung by node(s): either dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 5 (bronc either)
    The p-value is 3.38235e-08
    smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
    The value of j is 3 (bronc)
    There are 2 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 7 (lung dysp)
    The p-value is 1.66923e-06
    smoke is NOT separated from bronc by node(s): lung dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 3 4 (lung bronc)
    The p-value is 0.53713
    smoke is separated from dysp by node(s): lung bronc  (p-value>0.01)
    The value of i is 2 (lung)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 (tub smoke)
    The p-value is 4.9879e-111
    lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 7 (smoke dysp)
    The p-value is 3.88973e-81
    lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 7 (tub dysp)
    The p-value is 2.39758e-102
    lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    There are 2 neighbors.
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 5 (smoke either)
    The p-value is 9.14632e-161
    bronc is NOT separated from dysp by node(s): smoke either  (p-value<0.01)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 3 (tub lung)
    The p-value is 8.41815e-18
    either is NOT separated from dysp by node(s): tub lung  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 4 (tub bronc)
    The p-value is 1.59159e-110
    either is NOT separated from dysp by node(s): tub bronc  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 3 4 (lung bronc)
    The p-value is 1.28527e-59
    either is NOT separated from dysp by node(s): lung bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    The value of l is 3
    The value of i is 0 (tub)
    The value of j is 4 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of j is 3 (bronc)
    The value of i is 2 (lung)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
    The p-value is 3.4474e-87
    lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 3 4 (tub lung bronc)
    The p-value is 3.62282e-56
    either is NOT separated from dysp by node(s): tub lung bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    
    
    Values after Total Skeleton Run
    
    p: 8
    n: 500
    N: 6
    Number of Targets: 2
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 4 5 7
    Ctilde:
    Our Ctilde matrix is 6x6
    0 0 0 0 1 0
    0 0 1 1 0 0
    0 1 0 0 1 0
    0 1 0 0 0 1
    1 0 1 0 0 1
    0 0 0 1 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = -1 S[[1]][[3]] = -1 S[[1]][[4]] = -1 S[[1]][[5]] = nan S[[1]][[7]] = 5 
    S[[2]][[1]] = -1 S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = 3 S[[2]][[7]] = 3 4 
    S[[3]][[1]] = -1 S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = 2 S[[3]][[5]] = nan S[[3]][[7]] = 5 
    S[[4]][[1]] = -1 S[[4]][[2]] = nan S[[4]][[3]] = 2 S[[4]][[4]] = nan S[[4]][[5]] = -1 S[[4]][[7]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = 3 S[[5]][[3]] = nan S[[5]][[4]] = -1 S[[5]][[5]] = nan S[[5]][[7]] = nan 
    S[[7]][[1]] = 5 S[[7]][[2]] = 3 4 S[[7]][[3]] = 5 S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[7]] = nan 
    First and last elements of the dataset: -0.641447 0.198884

# Testing the total skeleton function for population (one target)

    There are 1 targets.
    Targets: lung
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
    Total Neighborhood:
    1, 2, 5
    There are 8 nodes in the DAG.
    There are 4 nodes in the neighborhood.
    All nodes being considered: 1 2 3 5
    Our starting matrix is 4x4.
    0 1 1 1
    1 0 1 1
    1 1 0 1
    1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[5]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[5]] = nan 
    Population Version
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    5 3
    
    
    The value of l is 0
    The value of i is 0 (tub)
    The value of j is 1 (smoke)
    x: 2 
    y: 3 
    z:  
    The p-value is 1
    tub is separated from smoke (p-value>0.01)
    The value of j is 2 (lung)
    x: 2 
    y: 4 
    z:  
    The p-value is 1
    tub is separated from lung (p-value>0.01)
    The value of j is 3 (either)
    x: 2 
    y: 6 
    z:  
    The p-value is 0
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    x: 3 
    y: 4 
    z:  
    The p-value is 0
    The value of j is 3 (either)
    x: 3 
    y: 6 
    z:  
    The p-value is 0
    The value of i is 2 (lung)
    The value of j is 3 (either)
    x: 4 
    y: 6 
    z:  
    The p-value is 0
    The value of i is 3 (either)
    The value of l is 1
    The value of i is 0 (tub)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 0 -> 1 | 3 -> 5 | k (True Vals): 2 (smoke)
    x: 2 
    y: 6 
    z: 3 
    The p-value is 0
    tub is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 3 -> 5 | k (True Vals): 3 (lung)
    x: 2 
    y: 6 
    z: 4 
    The p-value is 0
    tub is NOT separated from either by node(s): lung  (p-value<0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There is 1 neighbor.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
    x: 3 
    y: 4 
    z: 6 
    The p-value is 0
    smoke is NOT separated from lung by node(s): either  (p-value<0.01)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 5 | k (True Vals): 3 (lung)
    x: 3 
    y: 6 
    z: 4 
    The p-value is 1
    smoke is separated from either by node(s): lung  (p-value>0.01)
    The value of i is 2 (lung)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 5 | k (True Vals): 2 (smoke)
    x: 4 
    y: 6 
    z: 3 
    The p-value is 0
    lung is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 3 -> 5 | k (True Vals): 1 (tub)
    x: 4 
    y: 6 
    z: 2 
    The p-value is 0
    lung is NOT separated from either by node(s): tub  (p-value<0.01)
    The value of i is 3 (either)
    The value of l is 2
    The value of i is 0 (tub)
    The value of j is 3 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of i is 2 (lung)
    The value of j is 3 (either)
    There are 2 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 5 | k (True Vals): 1 2 (tub smoke)
    x: 4 
    y: 6 
    z: 2, 3 
    The p-value is 0
    lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
    The value of i is 3 (either)
    The value of l is 3
    The value of i is 0 (tub)
    The value of j is 3 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of i is 2 (lung)
    The value of j is 3 (either)
    The value of i is 3 (either)
    
    
    Values after Total Skeleton Run
    
    p: 8
    n: 0
    N: 4
    Number of Targets: 1
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 5
    Ctilde:
    Our Ctilde matrix is 4x4
    0 0 0 1
    0 0 1 0
    0 1 0 1
    1 0 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = -1 S[[1]][[3]] = -1 S[[1]][[5]] = nan 
    S[[2]][[1]] = -1 S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[5]] = 3 
    S[[3]][[1]] = -1 S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[5]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = 3 S[[5]][[3]] = nan S[[5]][[5]] = nan 

# Testing the total skeleton function for population (two targets)

    There are 2 targets.
    Targets: lung bronc
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
    
    Total Neighborhood:
    1, 2, 5, 7
    There are 8 nodes in the DAG.
    There are 6 nodes in the neighborhood.
    All nodes being considered: 1 2 3 4 5 7
    Our starting matrix is 6x6.
    0 1 1 1 1 1
    1 0 1 1 1 1
    1 1 0 1 1 1
    1 1 1 0 1 1
    1 1 1 1 0 1
    1 1 1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[4]] = nan S[[1]][[5]] = nan S[[1]][[7]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = nan S[[2]][[7]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = nan S[[3]][[5]] = nan S[[3]][[7]] = nan 
    S[[4]][[1]] = nan S[[4]][[2]] = nan S[[4]][[3]] = nan S[[4]][[4]] = nan S[[4]][[5]] = nan S[[4]][[7]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[4]] = nan S[[5]][[5]] = nan S[[5]][[7]] = nan 
    S[[7]][[1]] = nan S[[7]][[2]] = nan S[[7]][[3]] = nan S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[7]] = nan 
    Population Version
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    4 3
    5 4
    7 5
    
    
    The value of l is 0
    The value of i is 0 (tub)
    The value of j is 1 (smoke)
    x: 2 
    y: 3 
    z:  
    The p-value is 1
    tub is separated from smoke (p-value>0.01)
    The value of j is 2 (lung)
    x: 2 
    y: 4 
    z:  
    The p-value is 1
    tub is separated from lung (p-value>0.01)
    The value of j is 3 (bronc)
    x: 2 
    y: 5 
    z:  
    The p-value is 1
    tub is separated from bronc (p-value>0.01)
    The value of j is 4 (either)
    x: 2 
    y: 6 
    z:  
    The p-value is 0
    The value of j is 5 (dysp)
    x: 2 
    y: 8 
    z:  
    The p-value is 0
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    x: 3 
    y: 4 
    z:  
    The p-value is 0
    The value of j is 3 (bronc)
    x: 3 
    y: 5 
    z:  
    The p-value is 0
    The value of j is 4 (either)
    x: 3 
    y: 6 
    z:  
    The p-value is 0
    The value of j is 5 (dysp)
    x: 3 
    y: 8 
    z:  
    The p-value is 0
    The value of i is 2 (lung)
    The value of j is 3 (bronc)
    x: 4 
    y: 5 
    z:  
    The p-value is 0
    The value of j is 4 (either)
    x: 4 
    y: 6 
    z:  
    The p-value is 0
    The value of j is 5 (dysp)
    x: 4 
    y: 8 
    z:  
    The p-value is 0
    The value of i is 3 (bronc)
    The value of j is 4 (either)
    x: 5 
    y: 6 
    z:  
    The p-value is 0
    The value of j is 5 (dysp)
    x: 5 
    y: 8 
    z:  
    The p-value is 0
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    x: 6 
    y: 8 
    z:  
    The p-value is 0
    The value of i is 5 (dysp)
    The value of l is 1
    The value of i is 0 (tub)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 7 (dysp)
    x: 2 
    y: 6 
    z: 8 
    The p-value is 0
    tub is NOT separated from either by node(s): dysp  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 (lung)
    x: 2 
    y: 6 
    z: 4 
    The p-value is 0
    tub is NOT separated from either by node(s): lung  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 2 (smoke)
    x: 2 
    y: 6 
    z: 3 
    The p-value is 0
    tub is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 (bronc)
    x: 2 
    y: 6 
    z: 5 
    The p-value is 0
    tub is NOT separated from either by node(s): bronc  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 5 (either)
    x: 2 
    y: 8 
    z: 6 
    The p-value is 0
    tub is NOT separated from dysp by node(s): either  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 3 (lung)
    x: 2 
    y: 8 
    z: 4 
    The p-value is 0
    tub is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 2 (smoke)
    x: 2 
    y: 8 
    z: 3 
    The p-value is 0
    tub is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 4 (bronc)
    x: 2 
    y: 8 
    z: 5 
    The p-value is 0
    tub is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 7 (dysp)
    x: 3 
    y: 4 
    z: 8 
    The p-value is 0
    smoke is NOT separated from lung by node(s): dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 (bronc)
    x: 3 
    y: 4 
    z: 5 
    The p-value is 0
    smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
    x: 3 
    y: 4 
    z: 6 
    The p-value is 0
    smoke is NOT separated from lung by node(s): either  (p-value<0.01)
    The value of j is 3 (bronc)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 (lung)
    x: 3 
    y: 5 
    z: 4 
    The p-value is 0
    smoke is NOT separated from bronc by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 7 (dysp)
    x: 3 
    y: 5 
    z: 8 
    The p-value is 0
    smoke is NOT separated from bronc by node(s): dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 (either)
    x: 3 
    y: 5 
    z: 6 
    The p-value is 0
    smoke is NOT separated from bronc by node(s): either  (p-value<0.01)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 3 (lung)
    x: 3 
    y: 6 
    z: 4 
    The p-value is 1
    smoke is separated from either by node(s): lung  (p-value>0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 3 (lung)
    x: 3 
    y: 8 
    z: 4 
    The p-value is 0
    smoke is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 4 (bronc)
    x: 3 
    y: 8 
    z: 5 
    The p-value is 0
    smoke is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 5 (either)
    x: 3 
    y: 8 
    z: 6 
    The p-value is 0
    smoke is NOT separated from dysp by node(s): either  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 1 (tub)
    x: 3 
    y: 8 
    z: 2 
    The p-value is 0
    smoke is NOT separated from dysp by node(s): tub  (p-value<0.01)
    The value of i is 2 (lung)
    The value of j is 3 (bronc)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 2 (smoke)
    x: 4 
    y: 5 
    z: 3 
    The p-value is 1
    lung is separated from bronc by node(s): smoke  (p-value>0.01)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 (bronc)
    x: 4 
    y: 6 
    z: 5 
    The p-value is 0
    lung is NOT separated from either by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 (tub)
    x: 4 
    y: 6 
    z: 2 
    The p-value is 0
    lung is NOT separated from either by node(s): tub  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 (smoke)
    x: 4 
    y: 6 
    z: 3 
    The p-value is 0
    lung is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 7 (dysp)
    x: 4 
    y: 6 
    z: 8 
    The p-value is 0
    lung is NOT separated from either by node(s): dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 4 (bronc)
    x: 4 
    y: 8 
    z: 5 
    The p-value is 0
    lung is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 5 (either)
    x: 4 
    y: 8 
    z: 6 
    The p-value is 0
    lung is NOT separated from dysp by node(s): either  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 1 (tub)
    x: 4 
    y: 8 
    z: 2 
    The p-value is 0
    lung is NOT separated from dysp by node(s): tub  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 2 (smoke)
    x: 4 
    y: 8 
    z: 3 
    The p-value is 0
    lung is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    The value of i is 3 (bronc)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 3 -> 4 | 4 -> 5 | k (True Vals): 1 (tub)
    x: 5 
    y: 6 
    z: 2 
    The p-value is 0
    bronc is NOT separated from either by node(s): tub  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 4 -> 5 | k (True Vals): 2 (smoke)
    x: 5 
    y: 6 
    z: 3 
    The p-value is 1
    bronc is separated from either by node(s): smoke  (p-value>0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 5 (either)
    x: 5 
    y: 8 
    z: 6 
    The p-value is 0
    bronc is NOT separated from dysp by node(s): either  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 1 (tub)
    x: 5 
    y: 8 
    z: 2 
    The p-value is 0
    bronc is NOT separated from dysp by node(s): tub  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 (smoke)
    x: 5 
    y: 8 
    z: 3 
    The p-value is 0
    bronc is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 3 (lung)
    x: 5 
    y: 8 
    z: 4 
    The p-value is 0
    bronc is NOT separated from dysp by node(s): lung  (p-value<0.01)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 3 (lung)
    x: 6 
    y: 8 
    z: 4 
    The p-value is 0
    either is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 (tub)
    x: 6 
    y: 8 
    z: 2 
    The p-value is 0
    either is NOT separated from dysp by node(s): tub  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 2 (smoke)
    x: 6 
    y: 8 
    z: 3 
    The p-value is 0
    either is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 4 (bronc)
    x: 6 
    y: 8 
    z: 5 
    The p-value is 0
    either is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    The value of l is 2
    The value of i is 0 (tub)
    The value of j is 4 (either)
    There are 2 neighbors.
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 7 (lung dysp)
    x: 2 
    y: 6 
    z: 4, 8 
    The p-value is 0
    tub is NOT separated from either by node(s): lung dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 3 5 (lung either)
    x: 2 
    y: 8 
    z: 4, 6 
    The p-value is 1
    tub is separated from dysp by node(s): lung either  (p-value>0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 7 (bronc dysp)
    x: 3 
    y: 4 
    z: 5, 8 
    The p-value is 0
    smoke is NOT separated from lung by node(s): bronc dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 7 (either dysp)
    x: 3 
    y: 4 
    z: 6, 8 
    The p-value is 0
    smoke is NOT separated from lung by node(s): either dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 5 (bronc either)
    x: 3 
    y: 4 
    z: 5, 6 
    The p-value is 0
    smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
    The value of j is 3 (bronc)
    There are 2 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 7 (lung dysp)
    x: 3 
    y: 5 
    z: 4, 8 
    The p-value is 0
    smoke is NOT separated from bronc by node(s): lung dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 3 4 (lung bronc)
    x: 3 
    y: 8 
    z: 4, 5 
    The p-value is 1
    smoke is separated from dysp by node(s): lung bronc  (p-value>0.01)
    The value of i is 2 (lung)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 (tub smoke)
    x: 4 
    y: 6 
    z: 2, 3 
    The p-value is 0
    lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 7 (smoke dysp)
    x: 4 
    y: 6 
    z: 3, 8 
    The p-value is 0
    lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 7 (tub dysp)
    x: 4 
    y: 6 
    z: 2, 8 
    The p-value is 0
    lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 2 5 (smoke either)
    x: 4 
    y: 8 
    z: 3, 6 
    The p-value is 1
    lung is separated from dysp by node(s): smoke either  (p-value>0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    There are 2 neighbors.
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 5 (smoke either)
    x: 5 
    y: 8 
    z: 3, 6 
    The p-value is 0
    bronc is NOT separated from dysp by node(s): smoke either  (p-value<0.01)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 3 (tub lung)
    x: 6 
    y: 8 
    z: 2, 4 
    The p-value is 0
    either is NOT separated from dysp by node(s): tub lung  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 4 (tub bronc)
    x: 6 
    y: 8 
    z: 2, 5 
    The p-value is 0
    either is NOT separated from dysp by node(s): tub bronc  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 3 4 (lung bronc)
    x: 6 
    y: 8 
    z: 4, 5 
    The p-value is 0
    either is NOT separated from dysp by node(s): lung bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    The value of l is 3
    The value of i is 0 (tub)
    The value of j is 4 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of j is 3 (bronc)
    The value of i is 2 (lung)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
    x: 4 
    y: 6 
    z: 2, 3, 8 
    The p-value is 0
    lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 3 4 (tub lung bronc)
    x: 6 
    y: 8 
    z: 2, 4, 5 
    The p-value is 0
    either is NOT separated from dysp by node(s): tub lung bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    
    
    Values after Total Skeleton Run
    
    p: 8
    n: 0
    N: 6
    Number of Targets: 2
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 4 5 7
    Ctilde:
    Our Ctilde matrix is 6x6
    0 0 0 0 1 0
    0 0 1 1 0 0
    0 1 0 0 1 0
    0 1 0 0 0 1
    1 0 1 0 0 1
    0 0 0 1 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = -1 S[[1]][[3]] = -1 S[[1]][[4]] = -1 S[[1]][[5]] = nan S[[1]][[7]] = 3 5 
    S[[2]][[1]] = -1 S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = 3 S[[2]][[7]] = 3 4 
    S[[3]][[1]] = -1 S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = 2 S[[3]][[5]] = nan S[[3]][[7]] = 2 5 
    S[[4]][[1]] = -1 S[[4]][[2]] = nan S[[4]][[3]] = 2 S[[4]][[4]] = nan S[[4]][[5]] = 2 S[[4]][[7]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = 3 S[[5]][[3]] = nan S[[5]][[4]] = 2 S[[5]][[5]] = nan S[[5]][[7]] = nan 
    S[[7]][[1]] = 3 5 S[[7]][[2]] = 3 4 S[[7]][[3]] = 2 5 S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[7]] = nan 

# Testing V-Structure function

    There is (are) 2 target(s).
    Targets: lung bronc
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
    
    Total Neighborhood:
    1, 2, 5, 7
    There are 8 nodes in the DAG.
    There are 6 nodes in the neighborhoods we are considering.
    All nodes being considered: 1 2 3 4 5 7
    Our starting matrix is 6x6.
    0 1 1 1 1 1
    1 0 1 1 1 1
    1 1 0 1 1 1
    1 1 1 0 1 1
    1 1 1 1 0 1
    1 1 1 1 1 0
    
    
    
    Our initial separating sets:
    S[[1]][[1]] = nan S[[1]][[2]] = nan S[[1]][[3]] = nan S[[1]][[4]] = nan S[[1]][[5]] = nan S[[1]][[7]] = nan 
    S[[2]][[1]] = nan S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = nan S[[2]][[7]] = nan 
    S[[3]][[1]] = nan S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = nan S[[3]][[5]] = nan S[[3]][[7]] = nan 
    S[[4]][[1]] = nan S[[4]][[2]] = nan S[[4]][[3]] = nan S[[4]][[4]] = nan S[[4]][[5]] = nan S[[4]][[7]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = nan S[[5]][[3]] = nan S[[5]][[4]] = nan S[[5]][[5]] = nan S[[5]][[7]] = nan 
    S[[7]][[1]] = nan S[[7]][[2]] = nan S[[7]][[3]] = nan S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[7]] = nan 
    Element mapping for efficient ordering:
    1 0
    2 1
    3 2
    4 3
    5 4
    7 5
    
    
    The value of l is 0
    The value of i is 0 (tub)
    The value of j is 1 (smoke)
    The p-value is 0.0664439
    tub is separated from smoke (p-value>0.01)
    The value of j is 2 (lung)
    The p-value is 0.631592
    tub is separated from lung (p-value>0.01)
    The value of j is 3 (bronc)
    The p-value is 0.579122
    tub is separated from bronc (p-value>0.01)
    The value of j is 4 (either)
    The p-value is 2.96476e-07
    The value of j is 5 (dysp)
    The p-value is 0.0049716
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The p-value is 3.57115e-12
    The value of j is 3 (bronc)
    The p-value is 6.44217e-19
    The value of j is 4 (either)
    The p-value is 3.62121e-05
    The value of j is 5 (dysp)
    The p-value is 8.722e-05
    The value of i is 2 (lung)
    The value of j is 3 (bronc)
    The p-value is 0.00672051
    The value of j is 4 (either)
    The p-value is 2.97187e-109
    The value of j is 5 (dysp)
    The p-value is 9.83333e-14
    The value of i is 3 (bronc)
    The value of j is 4 (either)
    The p-value is 0.0431059
    bronc is separated from either (p-value>0.01)
    The value of j is 5 (dysp)
    The p-value is 6.74668e-84
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    The p-value is 9.48354e-32
    The value of i is 5 (dysp)
    The value of l is 1
    The value of i is 0 (tub)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 7 (dysp)
    The p-value is 1.75872e-05
    tub is NOT separated from either by node(s): dysp  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 (lung)
    The p-value is 9.35856e-14
    tub is NOT separated from either by node(s): lung  (p-value<0.01)
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 2.23369e-08
    tub is NOT separated from either by node(s): smoke  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 0 -> 1 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 0.669315
    tub is separated from dysp by node(s): either  (p-value>0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 7 (dysp)
    The p-value is 1.85744e-19
    smoke is NOT separated from lung by node(s): dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 (bronc)
    The p-value is 1.73265e-10
    smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
    The p-value is 6.33935e-09
    smoke is NOT separated from lung by node(s): either  (p-value<0.01)
    The value of j is 3 (bronc)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 (lung)
    The p-value is 3.36192e-17
    smoke is NOT separated from bronc by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 7 (dysp)
    The p-value is 1.40787e-17
    smoke is NOT separated from bronc by node(s): dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 (either)
    The p-value is 5.30428e-18
    smoke is NOT separated from bronc by node(s): either  (p-value<0.01)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 3 (lung)
    The p-value is 0.0944292
    smoke is separated from either by node(s): lung  (p-value>0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 3 (lung)
    The p-value is 4.7219e-12
    smoke is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 4 (bronc)
    The p-value is 0.0018733
    smoke is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 2.3399e-12
    smoke is NOT separated from dysp by node(s): either  (p-value<0.01)
    The value of i is 2 (lung)
    The value of j is 3 (bronc)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 2 (smoke)
    The p-value is 0.868413
    lung is separated from bronc by node(s): smoke  (p-value>0.01)
    The value of j is 4 (either)
    There are 4 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 (bronc)
    The p-value is 7.07433e-108
    lung is NOT separated from either by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 (tub)
    The p-value is 3.10595e-117
    lung is NOT separated from either by node(s): tub  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 5.05153e-105
    lung is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 7 (dysp)
    The p-value is 1.21991e-94
    lung is NOT separated from either by node(s): dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 4.8985e-21
    lung is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 4 (bronc)
    The p-value is 3.01325e-48
    lung is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 0.0810771
    lung is separated from dysp by node(s): either  (p-value>0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    There are 2 neighbors.
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 3.28744e-82
    bronc is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 1.86754e-176
    bronc is NOT separated from dysp by node(s): either  (p-value<0.01)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 4 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 3 (lung)
    The p-value is 1.21054e-19
    either is NOT separated from dysp by node(s): lung  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 (tub)
    The p-value is 7.29264e-30
    either is NOT separated from dysp by node(s): tub  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 1.15967e-39
    either is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 4 (bronc)
    The p-value is 8.04073e-114
    either is NOT separated from dysp by node(s): bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    The value of l is 2
    The value of i is 0 (tub)
    The value of j is 4 (either)
    There are 2 neighbors.
    Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 7 (lung dysp)
    The p-value is 6.06083e-12
    tub is NOT separated from either by node(s): lung dysp  (p-value<0.01)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 7 (bronc dysp)
    The p-value is 2.32256e-08
    smoke is NOT separated from lung by node(s): bronc dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 7 (either dysp)
    The p-value is 3.23618e-08
    smoke is NOT separated from lung by node(s): either dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 5 (bronc either)
    The p-value is 3.38235e-08
    smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
    The value of j is 3 (bronc)
    There are 2 neighbors.
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 7 (lung dysp)
    The p-value is 1.66923e-06
    smoke is NOT separated from bronc by node(s): lung dysp  (p-value<0.01)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 1 -> 2 | 5 -> 7 | k (True Vals): 3 4 (lung bronc)
    The p-value is 0.53713
    smoke is separated from dysp by node(s): lung bronc  (p-value>0.01)
    The value of i is 2 (lung)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 (tub smoke)
    The p-value is 4.9879e-111
    lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 7 (smoke dysp)
    The p-value is 3.88973e-81
    lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 7 (tub dysp)
    The p-value is 2.39758e-102
    lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    There are 2 neighbors.
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 5 (smoke either)
    The p-value is 9.14632e-161
    bronc is NOT separated from dysp by node(s): smoke either  (p-value<0.01)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 3 (tub lung)
    The p-value is 8.41815e-18
    either is NOT separated from dysp by node(s): tub lung  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 4 (tub bronc)
    The p-value is 1.59159e-110
    either is NOT separated from dysp by node(s): tub bronc  (p-value<0.01)
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 3 4 (lung bronc)
    The p-value is 1.28527e-59
    either is NOT separated from dysp by node(s): lung bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    The value of l is 3
    The value of i is 0 (tub)
    The value of j is 4 (either)
    The value of i is 1 (smoke)
    The value of j is 2 (lung)
    The value of j is 3 (bronc)
    The value of i is 2 (lung)
    The value of j is 4 (either)
    There are 3 neighbors.
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
    The p-value is 3.4474e-87
    lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
    The value of i is 3 (bronc)
    The value of j is 5 (dysp)
    The value of i is 4 (either)
    The value of j is 5 (dysp)
    There are 3 neighbors.
    Efficient Setup: 4 -> 5 | 5 -> 7 | k (True Vals): 1 3 4 (tub lung bronc)
    The p-value is 3.62282e-56
    either is NOT separated from dysp by node(s): tub lung bronc  (p-value<0.01)
    The value of i is 5 (dysp)
    
    
    Values after Total Skeleton Run
    
    p: 8
    n: 500
    N: 6
    Number of Targets: 2
    Node names: asia tub smoke lung bronc either xray dysp 
    lmax: 3
    verbose: 1
    Nodes under consideration: 1 2 3 4 5 7
    Ctilde:
    Our Ctilde matrix is 6x6
    0 0 0 0 1 0
    0 0 1 1 0 0
    0 1 0 0 1 0
    0 1 0 0 0 1
    1 0 1 0 0 1
    0 0 0 1 1 0
    Our DAG matrix is 
    0 1 0 0 0 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 1 1 0 0 0
    0 0 0 0 0 1 0 0
    0 0 0 0 0 0 0 1
    0 0 0 0 0 0 1 1
    0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0
    Separating Set Values:
    S[[1]][[1]] = nan S[[1]][[2]] = -1 S[[1]][[3]] = -1 S[[1]][[4]] = -1 S[[1]][[5]] = nan S[[1]][[7]] = 5 
    S[[2]][[1]] = -1 S[[2]][[2]] = nan S[[2]][[3]] = nan S[[2]][[4]] = nan S[[2]][[5]] = 3 S[[2]][[7]] = 3 4 
    S[[3]][[1]] = -1 S[[3]][[2]] = nan S[[3]][[3]] = nan S[[3]][[4]] = 2 S[[3]][[5]] = nan S[[3]][[7]] = 5 
    S[[4]][[1]] = -1 S[[4]][[2]] = nan S[[4]][[3]] = 2 S[[4]][[4]] = nan S[[4]][[5]] = -1 S[[4]][[7]] = nan 
    S[[5]][[1]] = nan S[[5]][[2]] = 3 S[[5]][[3]] = nan S[[5]][[4]] = -1 S[[5]][[5]] = nan S[[5]][[7]] = nan 
    S[[7]][[1]] = 5 S[[7]][[2]] = 3 4 S[[7]][[3]] = 5 S[[7]][[4]] = nan S[[7]][[5]] = nan S[[7]][[7]] = nan 
    First and last elements of the dataset: -0.641447 0.198884
    
    
    Finding skeleton for the neighborhood of target 3 (Efficient Number: 2)
    Neighborhood nodes under consideration: 1 2 4 | (smoke(2) lung(3) either(5))
    The value of l is 1
    The value of i is 1
    The value of j is 2
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
    
    Total Neighborhood:
    1, 4, 5
    Potential separating nodes: 1 4 5
    There are 3 neighbor(s).
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 1 (tub)
    The p-value is 2.27427e-12
    smoke is NOT separated from lung by node(s): tub  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 (bronc)
    The p-value is 1.73265e-10
    smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
    The p-value is 6.33935e-09
    smoke is NOT separated from lung by node(s): either  (p-value<0.01)
    l: 1 | i: 1 | j: 2 | k: either | p-val: 6.33935e-09
    The value of i is 2
    The value of j is 4
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
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
    
    Total Neighborhood:
    1, 2, 4, 6, 7
    Potential separating nodes: 1 2 4 6 7
    There are 5 neighbor(s).
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 (tub)
    The p-value is 3.10595e-117
    lung is NOT separated from either by node(s): tub  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 (smoke)
    The p-value is 5.05153e-105
    lung is NOT separated from either by node(s): smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 (bronc)
    The p-value is 7.07433e-108
    lung is NOT separated from either by node(s): bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 6 (xray)
    The p-value is 7.13973e-73
    lung is NOT separated from either by node(s): xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 7 (dysp)
    The p-value is 1.21991e-94
    lung is NOT separated from either by node(s): dysp  (p-value<0.01)
    l: 1 | i: 2 | j: 4 | k: dysp | p-val: 1.21991e-94
    The value of i is 4
    The value of l is 2
    The value of i is 1
    The value of j is 2
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
    
    Total Neighborhood:
    1, 4, 5
    Potential separating nodes: 1 4 5
    There are 3 neighbor(s).
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 1 4 (tub bronc)
    The p-value is 1.14143e-10
    smoke is NOT separated from lung by node(s): tub bronc  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 1 5 (tub either)
    The p-value is 1.29347e-07
    smoke is NOT separated from lung by node(s): tub either  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 5 (bronc either)
    The p-value is 3.38235e-08
    smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
    l: 2 | i: 1 | j: 2 | k: bronc either | p-val: 3.38235e-08
    The value of i is 2
    The value of j is 4
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
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
    
    Total Neighborhood:
    1, 2, 4, 6, 7
    Potential separating nodes: 1 2 4 6 7
    There are 5 neighbor(s).
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 (tub smoke)
    The p-value is 4.9879e-111
    lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 (tub bronc)
    The p-value is 1.31928e-115
    lung is NOT separated from either by node(s): tub bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 6 (tub xray)
    The p-value is 7.25594e-80
    lung is NOT separated from either by node(s): tub xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 7 (tub dysp)
    The p-value is 2.39758e-102
    lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 (smoke bronc)
    The p-value is 7.70358e-105
    lung is NOT separated from either by node(s): smoke bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 6 (smoke xray)
    The p-value is 4.10318e-71
    lung is NOT separated from either by node(s): smoke xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 7 (smoke dysp)
    The p-value is 3.88973e-81
    lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 6 (bronc xray)
    The p-value is 2.45256e-72
    lung is NOT separated from either by node(s): bronc xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 7 (bronc dysp)
    The p-value is 2.35293e-54
    lung is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 6 7 (xray dysp)
    The p-value is 1.5714e-67
    lung is NOT separated from either by node(s): xray dysp  (p-value<0.01)
    l: 2 | i: 2 | j: 4 | k: xray dysp | p-val: 1.5714e-67
    The value of i is 4
    The value of l is 3
    The value of i is 1
    The value of j is 2
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
    
    Total Neighborhood:
    1, 4, 5
    Potential separating nodes: 1 4 5
    There are 3 neighbor(s).
    Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 1 4 5 (tub bronc either)
    The p-value is 4.79431e-07
    smoke is NOT separated from lung by node(s): tub bronc either  (p-value<0.01)
    l: 3 | i: 1 | j: 2 | k: tub bronc either | p-val: 4.79431e-07
    The value of i is 2
    The value of j is 4
    Target: 3
    FUNCTION get_neighbors_from_dag. Node 3
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 5
    Call from get_neighbors_from_dag. Node 1 is a potential spouse of node 3.
    Neighbors of node 3: 1, 2, 5
    
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
    
    Total Neighborhood:
    1, 2, 4, 6, 7
    Potential separating nodes: 1 2 4 6 7
    There are 5 neighbor(s).
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 4 (tub smoke bronc)
    The p-value is 7.80299e-111
    lung is NOT separated from either by node(s): tub smoke bronc  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 6 (tub smoke xray)
    The p-value is 6.27627e-77
    lung is NOT separated from either by node(s): tub smoke xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
    The p-value is 3.4474e-87
    lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 6 (tub bronc xray)
    The p-value is 3.50039e-79
    lung is NOT separated from either by node(s): tub bronc xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 7 (tub bronc dysp)
    The p-value is 1.16445e-60
    lung is NOT separated from either by node(s): tub bronc dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 6 7 (tub xray dysp)
    The p-value is 5.4123e-74
    lung is NOT separated from either by node(s): tub xray dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 6 (smoke bronc xray)
    The p-value is 5.33318e-71
    lung is NOT separated from either by node(s): smoke bronc xray  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 7 (smoke bronc dysp)
    The p-value is 4.21368e-54
    lung is NOT separated from either by node(s): smoke bronc dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 6 7 (smoke xray dysp)
    The p-value is 1.8416e-59
    lung is NOT separated from either by node(s): smoke xray dysp  (p-value<0.01)
    Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
    The p-value is 1.00846e-44
    lung is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
    l: 3 | i: 2 | j: 4 | k: bronc xray dysp | p-val: 1.00846e-44
    The value of i is 4
    The final C matrix:
    0 0 0 0 1 0
    0 0 1 1 0 0
    0 1 0 0 1 0
    0 1 0 0 0 1
    1 0 1 0 0 1
    0 0 0 1 1 0
    Conclusion of algorithm.
    
    
    Finding skeleton for the neighborhood of target 4 (Efficient Number: 3)
    Neighborhood nodes under consideration: 1 3 5 | (smoke(2) bronc(4) dysp(7))
    The value of l is 1
    The value of i is 1
    The value of j is 3
    Target: 2
    FUNCTION get_neighbors_from_dag. Node 2
    Call from get_neighbors_from_dag. Node 3 is a child.
    Call from get_neighbors_from_dag. Node 4 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 3
    Call from get_neighbors_from_dag. We are evaluating the following child: 4
    Neighbors of node 2: 3, 4
    
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Total Neighborhood:
    3, 5, 7
    Potential separating nodes: 3 5 7
    There are 3 neighbor(s).
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 (lung)
    The p-value is 3.36192e-17
    smoke is NOT separated from bronc by node(s): lung  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 (either)
    The p-value is 5.30428e-18
    smoke is NOT separated from bronc by node(s): either  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 7 (dysp)
    The p-value is 1.40787e-17
    smoke is NOT separated from bronc by node(s): dysp  (p-value<0.01)
    l: 1 | i: 1 | j: 3 | k: dysp | p-val: 1.40787e-17
    The value of i is 3
    The value of j is 5
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Target: 7
    FUNCTION get_neighbors_from_dag. Node 7
    Call from get_neighbors_from_dag. Node 4 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 7: 4, 5
    
    Total Neighborhood:
    2, 5
    Potential separating nodes: 2 5
    There are 2 neighbor(s).
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 (smoke)
    The p-value is 3.28744e-82
    bronc is NOT separated from dysp by node(s): smoke  (p-value<0.01)
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 5 (either)
    The p-value is 1.86754e-176
    bronc is NOT separated from dysp by node(s): either  (p-value<0.01)
    l: 1 | i: 3 | j: 5 | k: either | p-val: 1.86754e-176
    The value of i is 5
    The value of l is 2
    The value of i is 1
    The value of j is 3
    Target: 2
    FUNCTION get_neighbors_from_dag. Node 2
    Call from get_neighbors_from_dag. Node 3 is a child.
    Call from get_neighbors_from_dag. Node 4 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 3
    Call from get_neighbors_from_dag. We are evaluating the following child: 4
    Neighbors of node 2: 3, 4
    
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Total Neighborhood:
    3, 5, 7
    Potential separating nodes: 3 5 7
    There are 3 neighbor(s).
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 5 (lung either)
    The p-value is 3.00083e-17
    smoke is NOT separated from bronc by node(s): lung either  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 7 (lung dysp)
    The p-value is 1.66923e-06
    smoke is NOT separated from bronc by node(s): lung dysp  (p-value<0.01)
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 7 (either dysp)
    The p-value is 5.75598e-07
    smoke is NOT separated from bronc by node(s): either dysp  (p-value<0.01)
    l: 2 | i: 1 | j: 3 | k: either dysp | p-val: 5.75598e-07
    The value of i is 3
    The value of j is 5
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Target: 7
    FUNCTION get_neighbors_from_dag. Node 7
    Call from get_neighbors_from_dag. Node 4 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 7: 4, 5
    
    Total Neighborhood:
    2, 5
    Potential separating nodes: 2 5
    There are 2 neighbor(s).
    Efficient Setup: 3 -> 4 | 5 -> 7 | k (True Vals): 2 5 (smoke either)
    The p-value is 9.14632e-161
    bronc is NOT separated from dysp by node(s): smoke either  (p-value<0.01)
    l: 2 | i: 3 | j: 5 | k: smoke either | p-val: 9.14632e-161
    The value of i is 5
    The value of l is 3
    The value of i is 1
    The value of j is 3
    Target: 2
    FUNCTION get_neighbors_from_dag. Node 2
    Call from get_neighbors_from_dag. Node 3 is a child.
    Call from get_neighbors_from_dag. Node 4 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 3
    Call from get_neighbors_from_dag. We are evaluating the following child: 4
    Neighbors of node 2: 3, 4
    
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Total Neighborhood:
    3, 5, 7
    Potential separating nodes: 3 5 7
    There are 3 neighbor(s).
    Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 5 7 (lung either dysp)
    The p-value is 5.76336e-07
    smoke is NOT separated from bronc by node(s): lung either dysp  (p-value<0.01)
    l: 3 | i: 1 | j: 3 | k: lung either dysp | p-val: 5.76336e-07
    The value of i is 3
    The value of j is 5
    Target: 4
    FUNCTION get_neighbors_from_dag. Node 4
    Call from get_neighbors_from_dag. Node 2 is a parent.
    Call from get_neighbors_from_dag. Node 7 is a child.
    Call from get_neighbors_from_dag. We are evaluating the following child: 7
    Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
    Neighbors of node 4: 2, 5, 7
    
    Target: 7
    FUNCTION get_neighbors_from_dag. Node 7
    Call from get_neighbors_from_dag. Node 4 is a parent.
    Call from get_neighbors_from_dag. Node 5 is a parent.
    Neighbors of node 7: 4, 5
    
    Total Neighborhood:
    2, 5
    Potential separating nodes: 2 5
    The value of i is 5
    The final C matrix:
    0 0 0 0 1 0
    0 0 1 1 0 0
    0 1 0 0 1 0
    0 1 0 0 0 1
    1 0 1 0 0 1
    0 0 0 1 1 0
    Conclusion of algorithm.
    Beginning loops to find v-structures.
    i: 0 (tub)
    j: 1 (smoke)
    j: 2 (lung)
    Potential k values: either
    k: 4 (either)
    Separation Set: -1 | V-Structure (True Numbering): 1*->5<-*3
    j: 3 (bronc)
    j: 5 (dysp)
    Potential k values: either
    k: 4 (either)
    i: 1 (smoke)
    j: 4 (either)
    Potential k values: lung
    k: 2 (lung)
    j: 5 (dysp)
    Potential k values: bronc
    k: 3 (bronc)
    i: 2 (lung)
    j: 3 (bronc)
    Potential k values: smoke
    k: 1 (smoke)
    j: 5 (dysp)
    Potential k values: either
    k: 4 (either)
    i: 3 (bronc)
    j: 4 (either)
    Potential k values: dysp
    k: 5 (dysp)
    Separation Set: -1 | V-Structure (True Numbering): 4*->7<-*5
    i: 4 (either)
    i: 5 (dysp)

