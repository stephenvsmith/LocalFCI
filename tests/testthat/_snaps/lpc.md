# Wrapper function (Population Version)

    Code
      wrapper_res <- localpc(true_dag = asiaDAG, targets = c(3, 4), node_names = names)
    Output
      The node value for the C++ function is 2,3 
      Population Version:
      Population Version (C++):
      There are 2 targets.
      Targets: smoke lung
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
      There are 8 nodes in the DAG.
      There are 5 nodes in the neighborhood.
      All nodes being considered: 1 2 3 4 5
      Our starting matrix is 5x5.
      0 1 1 1 1
      1 0 1 1 1
      1 1 0 1 1
      1 1 1 0 1
      1 1 1 1 0
      
      
      
      Our initial separating sets:
      S_{1,1} = nan S_{1,2} = nan S_{1,3} = nan S_{1,4} = nan S_{1,5} = nan 
      S_{2,1} = nan S_{2,2} = nan S_{2,3} = nan S_{2,4} = nan S_{2,5} = nan 
      S_{3,1} = nan S_{3,2} = nan S_{3,3} = nan S_{3,4} = nan S_{3,5} = nan 
      S_{4,1} = nan S_{4,2} = nan S_{4,3} = nan S_{4,4} = nan S_{4,5} = nan 
      S_{5,1} = nan S_{5,2} = nan S_{5,3} = nan S_{5,4} = nan S_{5,5} = nan 
      Element mapping for efficient ordering (True -> Efficient):
      1 0
      2 1
      3 2
      4 3
      5 4
      FUNCTION createInitialAmat
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
      
      Initial Adj. Matrix:
      0 1 1 0 1
      1 0 1 1 1
      1 1 0 1 1
      0 1 1 0 0
      1 1 1 0 0
      Beginning algorithm over all neighborhoods.
      Beginning the population Local PC algorithm over all neighborhoods.
      
      
      Finding skeleton for the neighborhood of target 2 (Name: smoke, Efficient Number: 1)
      Neighborhood nodes under consideration: 0 1 2 3 4 | (tub(1) smoke(2) lung(3) bronc(4) either(5))
      The value of l is 0
      The value of i is 0
      The value of j is 1
      The p-value is 1
      tub is separated from smoke (p-value>0.01)
      The value of j is 2
      The p-value is 1
      tub is separated from lung (p-value>0.01)
      The value of j is 4
      The p-value is 0
      The value of i is 1
      The value of j is 2
      The p-value is 0
      The value of j is 3
      The p-value is 0
      The value of j is 4
      The p-value is 0
      The value of i is 2
      The value of j is 3
      The p-value is 0
      The value of j is 4
      The p-value is 0
      The value of i is 3
      The value of i is 4
      The value of l is 1
      The value of i is 0
      The value of j is 4
      Target: 1
      FUNCTION get_neighbors_from_dag. Node 1
      Call from get_neighbors_from_dag. Node 0 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
      Neighbors of node 1: 0, 3, 5
      
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
      0, 3, 4, 6, 7
      Potential separating nodes: 0 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 (asia)
      The p-value is 0
      tub is NOT separated from either by node(s): asia  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 (lung)
      The p-value is 0
      tub is NOT separated from either by node(s): lung  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 (bronc)
      The p-value is 0
      tub is NOT separated from either by node(s): bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 6 (xray)
      The p-value is 0
      tub is NOT separated from either by node(s): xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 7 (dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): dysp  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 (bronc)
      The p-value is 0
      smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
      The p-value is 0
      smoke is NOT separated from lung by node(s): either  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from bronc by node(s): lung  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 (either)
      The p-value is 0
      smoke is NOT separated from bronc by node(s): either  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 7 (dysp)
      The p-value is 0
      smoke is NOT separated from bronc by node(s): dysp  (p-value<0.01)
      The value of j is 4
      Target: 2
      FUNCTION get_neighbors_from_dag. Node 2
      Call from get_neighbors_from_dag. Node 3 is a child.
      Call from get_neighbors_from_dag. Node 4 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 3
      Call from get_neighbors_from_dag. We are evaluating the following child: 4
      Neighbors of node 2: 3, 4
      
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
      1, 3, 4, 6, 7
      Potential separating nodes: 1 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 1 (tub)
      The p-value is 0
      smoke is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 3 (lung)
      The p-value is 1
      smoke is separated from either by node(s): lung  (p-value>0.01)
      The value of i is 2
      The value of j is 3
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
      Potential separating nodes: 1 2 5 7
      There are 4 neighbor(s).
      Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 1 (tub)
      The p-value is 0
      lung is NOT separated from bronc by node(s): tub  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 2 (smoke)
      The p-value is 1
      lung is separated from bronc by node(s): smoke  (p-value>0.01)
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
      The p-value is 0
      lung is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 (smoke)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 (bronc)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 6 (xray)
      The p-value is 0
      lung is NOT separated from either by node(s): xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 7 (dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): dysp  (p-value<0.01)
      The value of i is 3
      The value of i is 4
      The value of l is 2
      The value of i is 0
      The value of j is 4
      Target: 1
      FUNCTION get_neighbors_from_dag. Node 1
      Call from get_neighbors_from_dag. Node 0 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
      Neighbors of node 1: 0, 3, 5
      
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
      0, 3, 4, 6, 7
      Potential separating nodes: 0 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 (asia lung)
      The p-value is 0
      tub is NOT separated from either by node(s): asia lung  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 4 (asia bronc)
      The p-value is 0
      tub is NOT separated from either by node(s): asia bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 6 (asia xray)
      The p-value is 0
      tub is NOT separated from either by node(s): asia xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 7 (asia dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): asia dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 4 (lung bronc)
      The p-value is 0
      tub is NOT separated from either by node(s): lung bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 6 (lung xray)
      The p-value is 0
      tub is NOT separated from either by node(s): lung xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 7 (lung dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): lung dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 6 (bronc xray)
      The p-value is 0
      tub is NOT separated from either by node(s): bronc xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 7 (bronc dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 6 7 (xray dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): xray dysp  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub bronc  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 1 5 (tub either)
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub either  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 5 (bronc either)
      The p-value is 0
      smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from bronc by node(s): lung either  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 3 7 (lung dysp)
      The p-value is 0
      smoke is NOT separated from bronc by node(s): lung dysp  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 3 -> 4 | k (True Vals): 5 7 (either dysp)
      The p-value is 0
      smoke is NOT separated from bronc by node(s): either dysp  (p-value<0.01)
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
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 (tub bronc)
      The p-value is 0
      lung is NOT separated from either by node(s): tub bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 6 (tub xray)
      The p-value is 0
      lung is NOT separated from either by node(s): tub xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 7 (tub dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 (smoke bronc)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 6 (smoke xray)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 7 (smoke dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 6 (bronc xray)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 7 (bronc dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 6 7 (xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): xray dysp  (p-value<0.01)
      The value of i is 3
      The value of i is 4
      The value of l is 3
      The value of i is 0
      The value of j is 4
      Target: 1
      FUNCTION get_neighbors_from_dag. Node 1
      Call from get_neighbors_from_dag. Node 0 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
      Neighbors of node 1: 0, 3, 5
      
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
      0, 3, 4, 6, 7
      Potential separating nodes: 0 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 4 (asia lung bronc)
      The p-value is 0
      tub is NOT separated from either by node(s): asia lung bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 6 (asia lung xray)
      The p-value is 0
      tub is NOT separated from either by node(s): asia lung xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 7 (asia lung dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): asia lung dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 4 6 (asia bronc xray)
      The p-value is 0
      tub is NOT separated from either by node(s): asia bronc xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 4 7 (asia bronc dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): asia bronc dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 6 7 (asia xray dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): asia xray dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 4 6 (lung bronc xray)
      The p-value is 0
      tub is NOT separated from either by node(s): lung bronc xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 4 7 (lung bronc dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): lung bronc dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 6 7 (lung xray dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): lung xray dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
      The p-value is 0
      tub is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub bronc either  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from bronc by node(s): lung either dysp  (p-value<0.01)
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
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 6 (tub smoke xray)
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 6 (tub bronc xray)
      The p-value is 0
      lung is NOT separated from either by node(s): tub bronc xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 7 (tub bronc dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub bronc dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 6 7 (tub xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub xray dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 6 (smoke bronc xray)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke bronc xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 7 (smoke bronc dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke bronc dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 6 7 (smoke xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke xray dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
      The value of i is 3
      The value of i is 4
      The final C matrix:
      0 0 0 0 1
      0 0 1 1 0
      0 1 0 0 1
      0 1 0 0 0
      1 0 1 0 0
      Conclusion of algorithm.
      
      
      Finding skeleton for the neighborhood of target 3 (Name: lung, Efficient Number: 2)
      Neighborhood nodes under consideration: 1 2 4 | (smoke(2) lung(3) either(5))
      The value of l is 0
      The value of i is 1
      The value of j is 2
      The p-value is 0
      The value of i is 2
      The value of j is 4
      The p-value is 0
      The value of i is 4
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
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 (bronc)
      The p-value is 0
      smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 5 (either)
      The p-value is 0
      smoke is NOT separated from lung by node(s): either  (p-value<0.01)
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
      The p-value is 0
      lung is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 (smoke)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 (bronc)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 6 (xray)
      The p-value is 0
      lung is NOT separated from either by node(s): xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 7 (dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): dysp  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub bronc  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 1 5 (tub either)
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub either  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 2 -> 3 | k (True Vals): 4 5 (bronc either)
      The p-value is 0
      smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
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
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 (tub bronc)
      The p-value is 0
      lung is NOT separated from either by node(s): tub bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 6 (tub xray)
      The p-value is 0
      lung is NOT separated from either by node(s): tub xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 7 (tub dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 (smoke bronc)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 6 (smoke xray)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 7 (smoke dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 6 (bronc xray)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 7 (bronc dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 6 7 (xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): xray dysp  (p-value<0.01)
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
      The p-value is 0
      smoke is NOT separated from lung by node(s): tub bronc either  (p-value<0.01)
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
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke bronc  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 6 (tub smoke xray)
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 6 (tub bronc xray)
      The p-value is 0
      lung is NOT separated from either by node(s): tub bronc xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 4 7 (tub bronc dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub bronc dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 1 6 7 (tub xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): tub xray dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 6 (smoke bronc xray)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke bronc xray  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 4 7 (smoke bronc dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke bronc dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 2 6 7 (smoke xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): smoke xray dysp  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 4 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
      The p-value is 0
      lung is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
      The value of i is 4
      The final C matrix:
      0 0 0 0 1
      0 0 1 1 0
      0 1 0 0 1
      0 1 0 0 0
      1 0 1 0 0
      Conclusion of algorithm.
      Beginning loops to find v-structures.
      i: 0 (tub)
      j: 2 (lung)
      Potential k values: either
      k: 4 (either)
      Separation Set: -1 | V-Structure (True Numbering): 1*->5<-*3
      i: 1 (smoke)
      i: 2 (lung)
      i: 3 (bronc)

# Wrapper function (Semi-Sample Version)

    Code
      wrapper_res_semi <- localpc(data = asiadf, true_dag = asiaDAG, targets = c(3, 4),
      node_names = names)
    Output
      The node value for the C++ function is 2,3 
      Semi-Sample Version:
      There is (are) 2 target(s).
      Targets: smoke lung
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
      There are 8 nodes in the DAG.
      There are 5 nodes in the neighborhoods we are considering.
      All nodes being considered: 1 2 3 4 5
      Our starting matrix is 5x5.
      0 1 1 1 1
      1 0 1 1 1
      1 1 0 1 1
      1 1 1 0 1
      1 1 1 1 0
      
      
      
      Our initial separating sets:
      S_{1,1} = nan S_{1,2} = nan S_{1,3} = nan S_{1,4} = nan S_{1,5} = nan 
      S_{2,1} = nan S_{2,2} = nan S_{2,3} = nan S_{2,4} = nan S_{2,5} = nan 
      S_{3,1} = nan S_{3,2} = nan S_{3,3} = nan S_{3,4} = nan S_{3,5} = nan 
      S_{4,1} = nan S_{4,2} = nan S_{4,3} = nan S_{4,4} = nan S_{4,5} = nan 
      S_{5,1} = nan S_{5,2} = nan S_{5,3} = nan S_{5,4} = nan S_{5,5} = nan 
      Element mapping for efficient ordering:
      1 0
      2 1
      3 2
      4 3
      5 4
      FUNCTION createInitialAmat
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
      
      Initial Adj. Matrix:
      0 1 1 0 1
      1 0 1 1 1
      1 1 0 1 1
      0 1 1 0 0
      1 1 1 0 0
      Beginning the Local PC algorithm over all neighborhoods.
      
      
      Finding skeleton for the neighborhood of target 2 (Name: smoke, Efficient Number: 1)
      Neighborhood nodes under consideration: 0 1 2 3 4 | (tub(1) smoke(2) lung(3) bronc(4) either(5))
      The value of l is 0
      The value of i is 0
      The value of j is 1
      The p-value is 0.0664439
      tub is separated from smoke (p-value>0.01)
      The value of j is 2
      The p-value is 0.631592
      tub is separated from lung (p-value>0.01)
      The value of j is 4
      The p-value is 2.96476e-07
      The value of i is 1
      The value of j is 2
      The p-value is 3.57115e-12
      The value of j is 3
      The p-value is 6.44217e-19
      The value of j is 4
      The p-value is 3.62121e-05
      The value of i is 2
      The value of j is 3
      The p-value is 0.00672051
      The value of j is 4
      The p-value is 2.97187e-109
      The value of i is 3
      The value of i is 4
      The value of l is 1
      The value of i is 0
      The value of j is 4
      Target: 1
      FUNCTION get_neighbors_from_dag. Node 1
      Call from get_neighbors_from_dag. Node 0 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
      Neighbors of node 1: 0, 3, 5
      
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
      0, 3, 4, 6, 7
      Potential separating nodes: 0 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 (asia)
      The p-value is 2.04304e-06
      tub is NOT separated from either by node(s): asia  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 (lung)
      The p-value is 9.35856e-14
      tub is NOT separated from either by node(s): lung  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 (bronc)
      The p-value is 2.02399e-07
      tub is NOT separated from either by node(s): bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 6 (xray)
      The p-value is 0.000285486
      tub is NOT separated from either by node(s): xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 7 (dysp)
      The p-value is 1.75872e-05
      tub is NOT separated from either by node(s): dysp  (p-value<0.01)
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
      The value of j is 4
      Target: 2
      FUNCTION get_neighbors_from_dag. Node 2
      Call from get_neighbors_from_dag. Node 3 is a child.
      Call from get_neighbors_from_dag. Node 4 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 3
      Call from get_neighbors_from_dag. We are evaluating the following child: 4
      Neighbors of node 2: 3, 4
      
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
      1, 3, 4, 6, 7
      Potential separating nodes: 1 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 1 (tub)
      The p-value is 2.64846e-06
      smoke is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 1 -> 2 | 4 -> 5 | k (True Vals): 3 (lung)
      The p-value is 0.0944292
      smoke is separated from either by node(s): lung  (p-value>0.01)
      The value of i is 2
      The value of j is 3
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
      Potential separating nodes: 1 2 5 7
      There are 4 neighbor(s).
      Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 1 (tub)
      The p-value is 0.00650387
      lung is NOT separated from bronc by node(s): tub  (p-value<0.01)
      Efficient Setup: 2 -> 3 | 3 -> 4 | k (True Vals): 2 (smoke)
      The p-value is 0.868413
      lung is separated from bronc by node(s): smoke  (p-value>0.01)
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
      The value of i is 3
      The value of i is 4
      The value of l is 2
      The value of i is 0
      The value of j is 4
      Target: 1
      FUNCTION get_neighbors_from_dag. Node 1
      Call from get_neighbors_from_dag. Node 0 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
      Neighbors of node 1: 0, 3, 5
      
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
      0, 3, 4, 6, 7
      Potential separating nodes: 0 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 (asia lung)
      The p-value is 1.47654e-12
      tub is NOT separated from either by node(s): asia lung  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 4 (asia bronc)
      The p-value is 1.5435e-06
      tub is NOT separated from either by node(s): asia bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 6 (asia xray)
      The p-value is 0.000863371
      tub is NOT separated from either by node(s): asia xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 7 (asia dysp)
      The p-value is 4.49478e-05
      tub is NOT separated from either by node(s): asia dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 4 (lung bronc)
      The p-value is 9.79205e-14
      tub is NOT separated from either by node(s): lung bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 6 (lung xray)
      The p-value is 1.99198e-10
      tub is NOT separated from either by node(s): lung xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 7 (lung dysp)
      The p-value is 6.06083e-12
      tub is NOT separated from either by node(s): lung dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 6 (bronc xray)
      The p-value is 0.000231813
      tub is NOT separated from either by node(s): bronc xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 7 (bronc dysp)
      The p-value is 5.99369e-05
      tub is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 6 7 (xray dysp)
      The p-value is 0.00156137
      tub is NOT separated from either by node(s): xray dysp  (p-value<0.01)
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
      The value of i is 3
      The value of i is 4
      The value of l is 3
      The value of i is 0
      The value of j is 4
      Target: 1
      FUNCTION get_neighbors_from_dag. Node 1
      Call from get_neighbors_from_dag. Node 0 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Call from get_neighbors_from_dag. Node 3 is a potential spouse of node 1.
      Neighbors of node 1: 0, 3, 5
      
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
      0, 3, 4, 6, 7
      Potential separating nodes: 0 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 4 (asia lung bronc)
      The p-value is 1.51885e-12
      tub is NOT separated from either by node(s): asia lung bronc  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 6 (asia lung xray)
      The p-value is 1.63002e-09
      tub is NOT separated from either by node(s): asia lung xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 3 7 (asia lung dysp)
      The p-value is 3.548e-11
      tub is NOT separated from either by node(s): asia lung dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 4 6 (asia bronc xray)
      The p-value is 0.000733463
      tub is NOT separated from either by node(s): asia bronc xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 4 7 (asia bronc dysp)
      The p-value is 0.000122697
      tub is NOT separated from either by node(s): asia bronc dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 0 6 7 (asia xray dysp)
      The p-value is 0.00285872
      tub is NOT separated from either by node(s): asia xray dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 4 6 (lung bronc xray)
      The p-value is 2.14787e-10
      tub is NOT separated from either by node(s): lung bronc xray  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 4 7 (lung bronc dysp)
      The p-value is 1.02418e-10
      tub is NOT separated from either by node(s): lung bronc dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 3 6 7 (lung xray dysp)
      The p-value is 2.54582e-09
      tub is NOT separated from either by node(s): lung xray dysp  (p-value<0.01)
      Efficient Setup: 0 -> 1 | 4 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
      The p-value is 0.000856835
      tub is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
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
      The value of i is 3
      The value of i is 4
      The final C matrix:
      0 0 0 0 1
      0 0 1 1 0
      0 1 0 0 1
      0 1 0 0 0
      1 0 1 0 0
      Conclusion of algorithm.
      
      
      Finding skeleton for the neighborhood of target 3 (Name: lung, Efficient Number: 2)
      Neighborhood nodes under consideration: 1 2 4 | (smoke(2) lung(3) either(5))
      The value of l is 0
      The value of i is 1
      The value of j is 2
      The p-value is 3.57115e-12
      The value of i is 2
      The value of j is 4
      The p-value is 2.97187e-109
      The value of i is 4
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
      The value of i is 4
      The final C matrix:
      0 0 0 0 1
      0 0 1 1 0
      0 1 0 0 1
      0 1 0 0 0
      1 0 1 0 0
      Conclusion of algorithm.
      Beginning loops to find v-structures.
      i: 0 (tub)
      j: 2 (lung)
      Potential k values: either
      k: 4 (either)
      Separation Set: -1 | V-Structure (True Numbering): 1*->5<-*3
      i: 1 (smoke)
      i: 2 (lung)
      i: 3 (bronc)

# Wrapper function (Sample Version)

    Code
      wrapper_res_sample <- localpc(data = asiadf, targets = c(3, 4), node_names = names)
    Output
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 3 : 4,5 
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 4 : 3,6 
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 5 : 3,8 
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 6 : 2,4,7,8 
      Creating the reference DAG using Markov Blanket list.
      Nodes being considered: 2,3,4,5,6,7,8 
      
      The node value for the C++ function is 2,3 
      Sample Version:
      There is (are) 2 target(s).
      Targets: smoke lung
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      There are 8 nodes in the DAG.
      There are 4 nodes in the neighborhoods we are considering.
      All nodes being considered: 2 3 4 5
      Our starting matrix is 4x4.
      0 1 1 1
      1 0 1 1
      1 1 0 1
      1 1 1 0
      
      
      
      Our initial separating sets:
      S_{2,2} = nan S_{2,3} = nan S_{2,4} = nan S_{2,5} = nan 
      S_{3,2} = nan S_{3,3} = nan S_{3,4} = nan S_{3,5} = nan 
      S_{4,2} = nan S_{4,3} = nan S_{4,4} = nan S_{4,5} = nan 
      S_{5,2} = nan S_{5,3} = nan S_{5,4} = nan S_{5,5} = nan 
      Element mapping for efficient ordering:
      2 0
      3 1
      4 2
      5 3
      FUNCTION createInitialAmat
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
      Neighbors of node 3: 2, 5
      
      Initial Adj. Matrix:
      0 1 1 1
      1 0 1 1
      1 1 0 0
      1 1 0 0
      Beginning the Local PC algorithm over all neighborhoods.
      
      
      Finding skeleton for the neighborhood of target 2 (Name: smoke, Efficient Number: 0)
      Neighborhood nodes under consideration: 0 1 2 3 | (smoke(2) lung(3) bronc(4) either(5))
      The value of l is 0
      The value of i is 0
      The value of j is 1
      The p-value is 3.57115e-12
      The value of j is 2
      The p-value is 6.44217e-19
      The value of j is 3
      The p-value is 3.62121e-05
      The value of i is 1
      The value of j is 2
      The p-value is 0.00672051
      The value of j is 3
      The p-value is 2.97187e-109
      The value of i is 2
      The value of i is 3
      The value of l is 1
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 (bronc)
      The p-value is 1.73265e-10
      smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 5 (either)
      The p-value is 6.33935e-09
      smoke is NOT separated from lung by node(s): either  (p-value<0.01)
      The value of j is 2
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
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 (lung)
      The p-value is 3.36192e-17
      smoke is NOT separated from bronc by node(s): lung  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 5 (either)
      The p-value is 5.30428e-18
      smoke is NOT separated from bronc by node(s): either  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 7 (dysp)
      The p-value is 1.40787e-17
      smoke is NOT separated from bronc by node(s): dysp  (p-value<0.01)
      The value of j is 3
      Target: 2
      FUNCTION get_neighbors_from_dag. Node 2
      Call from get_neighbors_from_dag. Node 3 is a child.
      Call from get_neighbors_from_dag. Node 4 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 3
      Call from get_neighbors_from_dag. We are evaluating the following child: 4
      Neighbors of node 2: 3, 4
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 3, 4, 6, 7
      Potential separating nodes: 1 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 2 | 3 -> 5 | k (True Vals): 1 (tub)
      The p-value is 2.64846e-06
      smoke is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 3 -> 5 | k (True Vals): 3 (lung)
      The p-value is 0.0944292
      smoke is separated from either by node(s): lung  (p-value>0.01)
      The value of i is 1
      The value of j is 2
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 4
      FUNCTION get_neighbors_from_dag. Node 4
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
      Neighbors of node 4: 2, 5, 7
      
      Total Neighborhood:
      2, 5, 7
      Potential separating nodes: 2 5 7
      There are 3 neighbor(s).
      Efficient Setup: 1 -> 3 | 2 -> 4 | k (True Vals): 2 (smoke)
      The p-value is 0.868413
      lung is separated from bronc by node(s): smoke  (p-value>0.01)
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 (tub)
      The p-value is 3.10595e-117
      lung is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 (smoke)
      The p-value is 5.05153e-105
      lung is NOT separated from either by node(s): smoke  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 (bronc)
      The p-value is 7.07433e-108
      lung is NOT separated from either by node(s): bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 (xray)
      The p-value is 7.13973e-73
      lung is NOT separated from either by node(s): xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 7 (dysp)
      The p-value is 1.21991e-94
      lung is NOT separated from either by node(s): dysp  (p-value<0.01)
      The value of i is 2
      The value of i is 3
      The value of l is 2
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 5 (bronc either)
      The p-value is 3.38235e-08
      smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
      The value of j is 2
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
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 5 (lung either)
      The p-value is 3.00083e-17
      smoke is NOT separated from bronc by node(s): lung either  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 7 (lung dysp)
      The p-value is 1.66923e-06
      smoke is NOT separated from bronc by node(s): lung dysp  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 5 7 (either dysp)
      The p-value is 5.75598e-07
      smoke is NOT separated from bronc by node(s): either dysp  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 (tub smoke)
      The p-value is 4.9879e-111
      lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 (tub bronc)
      The p-value is 1.31928e-115
      lung is NOT separated from either by node(s): tub bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 (tub xray)
      The p-value is 7.25594e-80
      lung is NOT separated from either by node(s): tub xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 7 (tub dysp)
      The p-value is 2.39758e-102
      lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 (smoke bronc)
      The p-value is 7.70358e-105
      lung is NOT separated from either by node(s): smoke bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 (smoke xray)
      The p-value is 4.10318e-71
      lung is NOT separated from either by node(s): smoke xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 7 (smoke dysp)
      The p-value is 3.88973e-81
      lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 (bronc xray)
      The p-value is 2.45256e-72
      lung is NOT separated from either by node(s): bronc xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 7 (bronc dysp)
      The p-value is 2.35293e-54
      lung is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 7 (xray dysp)
      The p-value is 1.5714e-67
      lung is NOT separated from either by node(s): xray dysp  (p-value<0.01)
      The value of i is 2
      The value of i is 3
      The value of l is 3
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      The value of j is 2
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
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 5 7 (lung either dysp)
      The p-value is 5.76336e-07
      smoke is NOT separated from bronc by node(s): lung either dysp  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 4 (tub smoke bronc)
      The p-value is 7.80299e-111
      lung is NOT separated from either by node(s): tub smoke bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 6 (tub smoke xray)
      The p-value is 6.27627e-77
      lung is NOT separated from either by node(s): tub smoke xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
      The p-value is 3.4474e-87
      lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 6 (tub bronc xray)
      The p-value is 3.50039e-79
      lung is NOT separated from either by node(s): tub bronc xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 7 (tub bronc dysp)
      The p-value is 1.16445e-60
      lung is NOT separated from either by node(s): tub bronc dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 7 (tub xray dysp)
      The p-value is 5.4123e-74
      lung is NOT separated from either by node(s): tub xray dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 6 (smoke bronc xray)
      The p-value is 5.33318e-71
      lung is NOT separated from either by node(s): smoke bronc xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 7 (smoke bronc dysp)
      The p-value is 4.21368e-54
      lung is NOT separated from either by node(s): smoke bronc dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 7 (smoke xray dysp)
      The p-value is 1.8416e-59
      lung is NOT separated from either by node(s): smoke xray dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
      The p-value is 1.00846e-44
      lung is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
      The value of i is 2
      The value of i is 3
      The final C matrix:
      0 1 1 0
      1 0 0 1
      1 0 0 0
      0 1 0 0
      Conclusion of algorithm.
      
      
      Finding skeleton for the neighborhood of target 3 (Name: lung, Efficient Number: 1)
      Neighborhood nodes under consideration: 0 1 3 | (smoke(2) lung(3) either(5))
      The value of l is 0
      The value of i is 0
      The value of j is 1
      The p-value is 3.57115e-12
      The value of i is 1
      The value of j is 3
      The p-value is 2.97187e-109
      The value of i is 3
      The value of l is 1
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 (bronc)
      The p-value is 1.73265e-10
      smoke is NOT separated from lung by node(s): bronc  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 5 (either)
      The p-value is 6.33935e-09
      smoke is NOT separated from lung by node(s): either  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 (tub)
      The p-value is 3.10595e-117
      lung is NOT separated from either by node(s): tub  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 (smoke)
      The p-value is 5.05153e-105
      lung is NOT separated from either by node(s): smoke  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 (bronc)
      The p-value is 7.07433e-108
      lung is NOT separated from either by node(s): bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 (xray)
      The p-value is 7.13973e-73
      lung is NOT separated from either by node(s): xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 7 (dysp)
      The p-value is 1.21991e-94
      lung is NOT separated from either by node(s): dysp  (p-value<0.01)
      The value of i is 3
      The value of l is 2
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 5 (bronc either)
      The p-value is 3.38235e-08
      smoke is NOT separated from lung by node(s): bronc either  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 (tub smoke)
      The p-value is 4.9879e-111
      lung is NOT separated from either by node(s): tub smoke  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 (tub bronc)
      The p-value is 1.31928e-115
      lung is NOT separated from either by node(s): tub bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 (tub xray)
      The p-value is 7.25594e-80
      lung is NOT separated from either by node(s): tub xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 7 (tub dysp)
      The p-value is 2.39758e-102
      lung is NOT separated from either by node(s): tub dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 (smoke bronc)
      The p-value is 7.70358e-105
      lung is NOT separated from either by node(s): smoke bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 (smoke xray)
      The p-value is 4.10318e-71
      lung is NOT separated from either by node(s): smoke xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 7 (smoke dysp)
      The p-value is 3.88973e-81
      lung is NOT separated from either by node(s): smoke dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 (bronc xray)
      The p-value is 2.45256e-72
      lung is NOT separated from either by node(s): bronc xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 7 (bronc dysp)
      The p-value is 2.35293e-54
      lung is NOT separated from either by node(s): bronc dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 7 (xray dysp)
      The p-value is 1.5714e-67
      lung is NOT separated from either by node(s): xray dysp  (p-value<0.01)
      The value of i is 3
      The value of l is 3
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 4 (tub smoke bronc)
      The p-value is 7.80299e-111
      lung is NOT separated from either by node(s): tub smoke bronc  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 6 (tub smoke xray)
      The p-value is 6.27627e-77
      lung is NOT separated from either by node(s): tub smoke xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 7 (tub smoke dysp)
      The p-value is 3.4474e-87
      lung is NOT separated from either by node(s): tub smoke dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 6 (tub bronc xray)
      The p-value is 3.50039e-79
      lung is NOT separated from either by node(s): tub bronc xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 7 (tub bronc dysp)
      The p-value is 1.16445e-60
      lung is NOT separated from either by node(s): tub bronc dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 7 (tub xray dysp)
      The p-value is 5.4123e-74
      lung is NOT separated from either by node(s): tub xray dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 6 (smoke bronc xray)
      The p-value is 5.33318e-71
      lung is NOT separated from either by node(s): smoke bronc xray  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 7 (smoke bronc dysp)
      The p-value is 4.21368e-54
      lung is NOT separated from either by node(s): smoke bronc dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 7 (smoke xray dysp)
      The p-value is 1.8416e-59
      lung is NOT separated from either by node(s): smoke xray dysp  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 7 (bronc xray dysp)
      The p-value is 1.00846e-44
      lung is NOT separated from either by node(s): bronc xray dysp  (p-value<0.01)
      The value of i is 3
      The final C matrix:
      0 1 1 0
      1 0 0 1
      1 0 0 0
      0 1 0 0
      Conclusion of algorithm.
      Beginning loops to find v-structures.
      i: 0 (smoke)
      i: 1 (lung)
      i: 2 (bronc)
      j: 3 (either)
      i: 3 (either)

---

    Code
      wrapper_res_sample <- localpc(data = asiadf, targets = c(3, 4))
    Output
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 3 : 4,5 
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 4 : 3,6 
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 5 : 3,8 
      Estimating Markov Blankets using
       Algorithm: MMPC 
       Test: testIndFisher 
       Tolerance: 0.05 
      Results for target 6 : 2,4,7,8 
      Creating the reference DAG using Markov Blanket list.
      Nodes being considered: 2,3,4,5,6,7,8 
      
      The node value for the C++ function is 2,3 
      Sample Version:
      There is (are) 2 target(s).
      Targets: V2 V3
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      There are 8 nodes in the DAG.
      There are 4 nodes in the neighborhoods we are considering.
      All nodes being considered: 2 3 4 5
      Our starting matrix is 4x4.
      0 1 1 1
      1 0 1 1
      1 1 0 1
      1 1 1 0
      
      
      
      Our initial separating sets:
      S_{2,2} = nan S_{2,3} = nan S_{2,4} = nan S_{2,5} = nan 
      S_{3,2} = nan S_{3,3} = nan S_{3,4} = nan S_{3,5} = nan 
      S_{4,2} = nan S_{4,3} = nan S_{4,4} = nan S_{4,5} = nan 
      S_{5,2} = nan S_{5,3} = nan S_{5,4} = nan S_{5,5} = nan 
      Element mapping for efficient ordering:
      2 0
      3 1
      4 2
      5 3
      FUNCTION createInitialAmat
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
      Neighbors of node 3: 2, 5
      
      Initial Adj. Matrix:
      0 1 1 1
      1 0 1 1
      1 1 0 0
      1 1 0 0
      Beginning the Local PC algorithm over all neighborhoods.
      
      
      Finding skeleton for the neighborhood of target 2 (Name: V2, Efficient Number: 0)
      Neighborhood nodes under consideration: 0 1 2 3 | (V2(2) V3(3) V4(4) V5(5))
      The value of l is 0
      The value of i is 0
      The value of j is 1
      The p-value is 3.57115e-12
      The value of j is 2
      The p-value is 6.44217e-19
      The value of j is 3
      The p-value is 3.62121e-05
      The value of i is 1
      The value of j is 2
      The p-value is 0.00672051
      The value of j is 3
      The p-value is 2.97187e-109
      The value of i is 2
      The value of i is 3
      The value of l is 1
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 (V4)
      The p-value is 1.73265e-10
      V2 is NOT separated from V3 by node(s): V4  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 5 (V5)
      The p-value is 6.33935e-09
      V2 is NOT separated from V3 by node(s): V5  (p-value<0.01)
      The value of j is 2
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
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 (V3)
      The p-value is 3.36192e-17
      V2 is NOT separated from V4 by node(s): V3  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 5 (V5)
      The p-value is 5.30428e-18
      V2 is NOT separated from V4 by node(s): V5  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 7 (V7)
      The p-value is 1.40787e-17
      V2 is NOT separated from V4 by node(s): V7  (p-value<0.01)
      The value of j is 3
      Target: 2
      FUNCTION get_neighbors_from_dag. Node 2
      Call from get_neighbors_from_dag. Node 3 is a child.
      Call from get_neighbors_from_dag. Node 4 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 3
      Call from get_neighbors_from_dag. We are evaluating the following child: 4
      Neighbors of node 2: 3, 4
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 3, 4, 6, 7
      Potential separating nodes: 1 3 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 0 -> 2 | 3 -> 5 | k (True Vals): 1 (V1)
      The p-value is 2.64846e-06
      V2 is NOT separated from V5 by node(s): V1  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 3 -> 5 | k (True Vals): 3 (V3)
      The p-value is 0.0944292
      V2 is separated from V5 by node(s): V3  (p-value>0.01)
      The value of i is 1
      The value of j is 2
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 4
      FUNCTION get_neighbors_from_dag. Node 4
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 5 is a potential spouse of node 4.
      Neighbors of node 4: 2, 5, 7
      
      Total Neighborhood:
      2, 5, 7
      Potential separating nodes: 2 5 7
      There are 3 neighbor(s).
      Efficient Setup: 1 -> 3 | 2 -> 4 | k (True Vals): 2 (V2)
      The p-value is 0.868413
      V3 is separated from V4 by node(s): V2  (p-value>0.01)
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 (V1)
      The p-value is 3.10595e-117
      V3 is NOT separated from V5 by node(s): V1  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 (V2)
      The p-value is 5.05153e-105
      V3 is NOT separated from V5 by node(s): V2  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 (V4)
      The p-value is 7.07433e-108
      V3 is NOT separated from V5 by node(s): V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 (V6)
      The p-value is 7.13973e-73
      V3 is NOT separated from V5 by node(s): V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 7 (V7)
      The p-value is 1.21991e-94
      V3 is NOT separated from V5 by node(s): V7  (p-value<0.01)
      The value of i is 2
      The value of i is 3
      The value of l is 2
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 5 (V4 V5)
      The p-value is 3.38235e-08
      V2 is NOT separated from V3 by node(s): V4 V5  (p-value<0.01)
      The value of j is 2
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
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 5 (V3 V5)
      The p-value is 3.00083e-17
      V2 is NOT separated from V4 by node(s): V3 V5  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 7 (V3 V7)
      The p-value is 1.66923e-06
      V2 is NOT separated from V4 by node(s): V3 V7  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 5 7 (V5 V7)
      The p-value is 5.75598e-07
      V2 is NOT separated from V4 by node(s): V5 V7  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 (V1 V2)
      The p-value is 4.9879e-111
      V3 is NOT separated from V5 by node(s): V1 V2  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 (V1 V4)
      The p-value is 1.31928e-115
      V3 is NOT separated from V5 by node(s): V1 V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 (V1 V6)
      The p-value is 7.25594e-80
      V3 is NOT separated from V5 by node(s): V1 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 7 (V1 V7)
      The p-value is 2.39758e-102
      V3 is NOT separated from V5 by node(s): V1 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 (V2 V4)
      The p-value is 7.70358e-105
      V3 is NOT separated from V5 by node(s): V2 V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 (V2 V6)
      The p-value is 4.10318e-71
      V3 is NOT separated from V5 by node(s): V2 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 7 (V2 V7)
      The p-value is 3.88973e-81
      V3 is NOT separated from V5 by node(s): V2 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 (V4 V6)
      The p-value is 2.45256e-72
      V3 is NOT separated from V5 by node(s): V4 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 7 (V4 V7)
      The p-value is 2.35293e-54
      V3 is NOT separated from V5 by node(s): V4 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 7 (V6 V7)
      The p-value is 1.5714e-67
      V3 is NOT separated from V5 by node(s): V6 V7  (p-value<0.01)
      The value of i is 2
      The value of i is 3
      The value of l is 3
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      The value of j is 2
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
      Efficient Setup: 0 -> 2 | 2 -> 4 | k (True Vals): 3 5 7 (V3 V5 V7)
      The p-value is 5.76336e-07
      V2 is NOT separated from V4 by node(s): V3 V5 V7  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 4 (V1 V2 V4)
      The p-value is 7.80299e-111
      V3 is NOT separated from V5 by node(s): V1 V2 V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 6 (V1 V2 V6)
      The p-value is 6.27627e-77
      V3 is NOT separated from V5 by node(s): V1 V2 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 7 (V1 V2 V7)
      The p-value is 3.4474e-87
      V3 is NOT separated from V5 by node(s): V1 V2 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 6 (V1 V4 V6)
      The p-value is 3.50039e-79
      V3 is NOT separated from V5 by node(s): V1 V4 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 7 (V1 V4 V7)
      The p-value is 1.16445e-60
      V3 is NOT separated from V5 by node(s): V1 V4 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 7 (V1 V6 V7)
      The p-value is 5.4123e-74
      V3 is NOT separated from V5 by node(s): V1 V6 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 6 (V2 V4 V6)
      The p-value is 5.33318e-71
      V3 is NOT separated from V5 by node(s): V2 V4 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 7 (V2 V4 V7)
      The p-value is 4.21368e-54
      V3 is NOT separated from V5 by node(s): V2 V4 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 7 (V2 V6 V7)
      The p-value is 1.8416e-59
      V3 is NOT separated from V5 by node(s): V2 V6 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 7 (V4 V6 V7)
      The p-value is 1.00846e-44
      V3 is NOT separated from V5 by node(s): V4 V6 V7  (p-value<0.01)
      The value of i is 2
      The value of i is 3
      The final C matrix:
      0 1 1 0
      1 0 0 1
      1 0 0 0
      0 1 0 0
      Conclusion of algorithm.
      
      
      Finding skeleton for the neighborhood of target 3 (Name: V3, Efficient Number: 1)
      Neighborhood nodes under consideration: 0 1 3 | (V2(2) V3(3) V5(5))
      The value of l is 0
      The value of i is 0
      The value of j is 1
      The p-value is 3.57115e-12
      The value of i is 1
      The value of j is 3
      The p-value is 2.97187e-109
      The value of i is 3
      The value of l is 1
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 (V4)
      The p-value is 1.73265e-10
      V2 is NOT separated from V3 by node(s): V4  (p-value<0.01)
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 5 (V5)
      The p-value is 6.33935e-09
      V2 is NOT separated from V3 by node(s): V5  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 (V1)
      The p-value is 3.10595e-117
      V3 is NOT separated from V5 by node(s): V1  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 (V2)
      The p-value is 5.05153e-105
      V3 is NOT separated from V5 by node(s): V2  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 (V4)
      The p-value is 7.07433e-108
      V3 is NOT separated from V5 by node(s): V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 (V6)
      The p-value is 7.13973e-73
      V3 is NOT separated from V5 by node(s): V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 7 (V7)
      The p-value is 1.21991e-94
      V3 is NOT separated from V5 by node(s): V7  (p-value<0.01)
      The value of i is 3
      The value of l is 2
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      There are 2 neighbor(s).
      Efficient Setup: 0 -> 2 | 1 -> 3 | k (True Vals): 4 5 (V4 V5)
      The p-value is 3.38235e-08
      V2 is NOT separated from V3 by node(s): V4 V5  (p-value<0.01)
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 (V1 V2)
      The p-value is 4.9879e-111
      V3 is NOT separated from V5 by node(s): V1 V2  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 (V1 V4)
      The p-value is 1.31928e-115
      V3 is NOT separated from V5 by node(s): V1 V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 (V1 V6)
      The p-value is 7.25594e-80
      V3 is NOT separated from V5 by node(s): V1 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 7 (V1 V7)
      The p-value is 2.39758e-102
      V3 is NOT separated from V5 by node(s): V1 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 (V2 V4)
      The p-value is 7.70358e-105
      V3 is NOT separated from V5 by node(s): V2 V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 (V2 V6)
      The p-value is 4.10318e-71
      V3 is NOT separated from V5 by node(s): V2 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 7 (V2 V7)
      The p-value is 3.88973e-81
      V3 is NOT separated from V5 by node(s): V2 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 (V4 V6)
      The p-value is 2.45256e-72
      V3 is NOT separated from V5 by node(s): V4 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 7 (V4 V7)
      The p-value is 2.35293e-54
      V3 is NOT separated from V5 by node(s): V4 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 6 7 (V6 V7)
      The p-value is 1.5714e-67
      V3 is NOT separated from V5 by node(s): V6 V7  (p-value<0.01)
      The value of i is 3
      The value of l is 3
      The value of i is 0
      The value of j is 1
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
      Neighbors of node 3: 2, 5
      
      Total Neighborhood:
      4, 5
      Potential separating nodes: 4 5
      The value of i is 1
      The value of j is 3
      Target: 3
      FUNCTION get_neighbors_from_dag. Node 3
      Call from get_neighbors_from_dag. Node 2 is a parent.
      Call from get_neighbors_from_dag. Node 5 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 5
      Neighbors of node 3: 2, 5
      
      Target: 5
      FUNCTION get_neighbors_from_dag. Node 5
      Call from get_neighbors_from_dag. Node 1 is a child.
      Call from get_neighbors_from_dag. Node 3 is a parent.
      Call from get_neighbors_from_dag. Node 6 is a child.
      Call from get_neighbors_from_dag. Node 7 is a child.
      Call from get_neighbors_from_dag. We are evaluating the following child: 1
      Call from get_neighbors_from_dag. We are evaluating the following child: 6
      Call from get_neighbors_from_dag. We are evaluating the following child: 7
      Call from get_neighbors_from_dag. Node 4 is a potential spouse of node 5.
      Neighbors of node 5: 1, 3, 4, 6, 7
      
      Total Neighborhood:
      1, 2, 4, 6, 7
      Potential separating nodes: 1 2 4 6 7
      There are 5 neighbor(s).
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 4 (V1 V2 V4)
      The p-value is 7.80299e-111
      V3 is NOT separated from V5 by node(s): V1 V2 V4  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 6 (V1 V2 V6)
      The p-value is 6.27627e-77
      V3 is NOT separated from V5 by node(s): V1 V2 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 2 7 (V1 V2 V7)
      The p-value is 3.4474e-87
      V3 is NOT separated from V5 by node(s): V1 V2 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 6 (V1 V4 V6)
      The p-value is 3.50039e-79
      V3 is NOT separated from V5 by node(s): V1 V4 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 4 7 (V1 V4 V7)
      The p-value is 1.16445e-60
      V3 is NOT separated from V5 by node(s): V1 V4 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 1 6 7 (V1 V6 V7)
      The p-value is 5.4123e-74
      V3 is NOT separated from V5 by node(s): V1 V6 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 6 (V2 V4 V6)
      The p-value is 5.33318e-71
      V3 is NOT separated from V5 by node(s): V2 V4 V6  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 4 7 (V2 V4 V7)
      The p-value is 4.21368e-54
      V3 is NOT separated from V5 by node(s): V2 V4 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 2 6 7 (V2 V6 V7)
      The p-value is 1.8416e-59
      V3 is NOT separated from V5 by node(s): V2 V6 V7  (p-value<0.01)
      Efficient Setup: 1 -> 3 | 3 -> 5 | k (True Vals): 4 6 7 (V4 V6 V7)
      The p-value is 1.00846e-44
      V3 is NOT separated from V5 by node(s): V4 V6 V7  (p-value<0.01)
      The value of i is 3
      The final C matrix:
      0 1 1 0
      1 0 0 1
      1 0 0 0
      0 1 0 0
      Conclusion of algorithm.
      Beginning loops to find v-structures.
      i: 0 (V2)
      i: 1 (V3)
      i: 2 (V4)
      j: 3 (V5)
      i: 3 (V5)

