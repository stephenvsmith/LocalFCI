# Rule 1 is correct.

    Rule 1:
    Orient: 1 *-> 3 o-* 4 as 3 -> 4
    Rule 1 has been used 1 times.
    Track changes: 1

# Rule 2 is correct.

    Rule 2:
    Orient: 0 *-> 1 -> 2 as: 0 *-> 2
    Rule 2 has been used 1 times.
    Rule 2:
    Orient: 3 -> 4 *-> 5 as: 3 *-> 5
    Rule 2 has been used 2 times.
    Track changes: 1

# Rule 3 is correct.

    Rule 3:
    Orient: 6 *-> 4
    Rule 3 has been used 1 times.
    Track changes: 1

# Rule 4 is correct.

    
    Potential values: 1
    Creating path list
    New Path: 3 1
    mpath: 3 1
    Size of old path list: 1
    Size of new path list: 2
    Path 0: 3 1
    Path 1: 3 1 0
    mpath: 3 1 0
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 3 1
    Path 1: 3 1 0
    Path 2: 3 1 0 6
    mpath: 3 1 0 6
    Minimum Discriminating Path: 6 0 1 3 4 5
    Checking separation of 6 and 5 by 4...finished
    
    Rule 4
    There is a discriminating path between 6 and 5 for 4 and 4 is in the SepSet of 5 and 6. Orient: 4 -> 5
    Rule 4 has been used 1 times.
    Track changes: 1

# Rule 4 is correct (beta not in separation set).

    
    Potential values: 1
    Creating path list
    New Path: 3 1
    mpath: 3 1
    Size of old path list: 1
    Size of new path list: 2
    Path 0: 3 1
    Path 1: 3 1 0
    mpath: 3 1 0
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 3 1
    Path 1: 3 1 0
    Path 2: 3 1 0 6
    mpath: 3 1 0 6
    Minimum Discriminating Path: 6 0 1 3 4 5
    Checking separation of 6 and 5 by 4...finished
    
    Rule 4
    There is a discriminating path between 6 and 5 for 4 and 4 is NOT in the SepSet of 5 and 6. Orient: 3 <-> 4 <-> 5
    Rule 4 has been used 1 times.
    Track changes: 1

# Rule 4 testing conditions

    
    Potential values: 
    No discriminating path for these nodes.
    Track changes: 0
         [,1] [,2] [,3] [,4]
    [1,]    0    1    2    1
    [2,]    2    0    1    0
    [3,]    3    1    0    0
    [4,]    1    0    0    0

# Rule 8 is correct.

    
    Rule 8
    Orient: 0 o-> 1 -> 5 with 0 o-> 5 as 0 -> 5
    Rule 8 has been used 1 times.
    
    Rule 8
    Orient: 3 -> 4 -> 5 with 3 o-> 5 as 3 -> 5
    Rule 8 has been used 2 times.
    Track changes: 1

# Rule 9 is correct.

    Potential alpha: 4 | Potential gamma: 6
    Potential beta: 3
    Potential beta: 5
    Checking for paths of 4 or more
    Potential theta: 7
    Creating path list
    New Path: 5 7
    mpath: 5 7
    Potential New Value in Path: 0
    Size of old path list: 1
    Size of new path list: 2
    Path 0: 5 7
    Path 1: 5 7 0
    Counter: 1 | Number of paths: 2
    mpath: 5 7 0
    Potential New Value in Path: 1
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 5 7
    Path 1: 5 7 0
    Path 2: 5 7 0 1
    Counter: 2 | Number of paths: 3
    mpath: 5 7 0 1
    Potential New Value in Path: 2
    Size of old path list: 3
    Size of new path list: 4
    Path 0: 5 7
    Path 1: 5 7 0
    Path 2: 5 7 0 1
    Path 3: 5 7 0 1 2
    Counter: 3 | Number of paths: 4
    mpath: 5 7 0 1 2
    Found a final node on the uncovered p.d. path: 2
    Path: 4 5 7 0 1 2 6
    Final Path: 4 5 7 0 1 2 6
    Counter: 4 | Number of paths: 4
    Rule 9: There exists an uncovered potentially directed path between 4 and 6
    Orient: 4 -> 6
    Rule 9 has been used 1 times.
    Potential alpha: 5 | Potential gamma: 7
    Potential beta: 4
    Checking for paths of 4 or more
    Potential theta: 3
    Potential theta: 6
    Creating path list
    New Path: 4 3
    New Path: 4 6
    mpath: 4 3
    Counter: 1 | Number of paths: 2
    mpath: 4 6
    Potential New Value in Path: 2
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 4 3
    Path 1: 4 6
    Path 2: 4 6 2
    Counter: 2 | Number of paths: 3
    mpath: 4 6 2
    Potential New Value in Path: 1
    Size of old path list: 3
    Size of new path list: 4
    Path 0: 4 3
    Path 1: 4 6
    Path 2: 4 6 2
    Path 3: 4 6 2 1
    Counter: 3 | Number of paths: 4
    mpath: 4 6 2 1
    Potential New Value in Path: 0
    Size of old path list: 4
    Size of new path list: 5
    Path 0: 4 3
    Path 1: 4 6
    Path 2: 4 6 2
    Path 3: 4 6 2 1
    Path 4: 4 6 2 1 0
    Counter: 4 | Number of paths: 5
    mpath: 4 6 2 1 0
    Counter: 5 | Number of paths: 5
    Track changes: 1

# Rule 9 (completeness of upd function)

    Potential alpha: 1 | Potential gamma: 6
    Potential alpha: 2 | Potential gamma: 4
    Potential beta: 3
    Checking for paths of 4 or more
    Potential theta: 0
    Potential theta: 1
    Creating path list
    New Path: 3 0
    New Path: 3 1
    mpath: 3 0
    Potential New Value in Path: 5
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 3 0
    Path 1: 3 1
    Path 2: 3 0 5
    Counter: 1 | Number of paths: 3
    mpath: 3 1
    Potential New Value in Path: 6
    Size of old path list: 3
    Size of new path list: 4
    Path 0: 3 0
    Path 1: 3 1
    Path 2: 3 0 5
    Path 3: 3 1 6
    Counter: 2 | Number of paths: 4
    mpath: 3 0 5
    Found a final node on the uncovered p.d. path: 5
    Path: 2 3 0 5 4
    This path is invalid because it is covered.
    Counter: 3 | Number of paths: 4
    mpath: 3 1 6
    Potential New Value in Path: 7
    Size of old path list: 4
    Size of new path list: 5
    Path 0: 3 0
    Path 1: 3 1
    Path 2: 3 0 5
    Path 3: 3 1 6
    Path 4: 3 1 6 7
    Counter: 4 | Number of paths: 5
    mpath: 3 1 6 7
    Found a final node on the uncovered p.d. path: 7
    Path: 2 3 1 6 7 4
    Final Path: 2 3 1 6 7 4
    Counter: 5 | Number of paths: 5
    Rule 9: There exists an uncovered potentially directed path between 2 and 4
    Orient: 2 -> 4
    Rule 9 has been used 1 times.
    Potential alpha: 3 | Potential gamma: 1
    Potential beta: 0
    Potential beta: 2
    Potential beta: 5
    Checking for paths of 4 or more
    Potential theta: 4
    Creating path list
    New Path: 5 4
    mpath: 5 4
    Counter: 1 | Number of paths: 1
    Checking for paths of 4 or more
    Potential theta: 4
    Creating path list
    New Path: 2 4
    mpath: 2 4
    Counter: 1 | Number of paths: 1
    Checking for paths of 4 or more
    Potential alpha: 7 | Potential gamma: 4
    Potential beta: 6
    Checking for paths of 4 or more
    Track changes: 1
         [,1] [,2] [,3] [,4] [,5] [,6] [,7] [,8]
    [1,]    0    0    0    3    0    2    0    0
    [2,]    0    0    0    1    0    0    2    0
    [3,]    0    0    0    1    2    1    0    0
    [4,]    1    2    1    0    0    2    0    0
    [5,]    0    0    3    0    0    3    0    1
    [6,]    3    0    1    3    2    0    0    0
    [7,]    0    1    0    0    0    0    0    1
    [8,]    0    0    0    0    2    0    1    0

# Rule 10 is correct.

    Checking for paths of 4 or more
    Potential theta: 0
    Creating path list
    New Path: 6 0
    mpath: 6 0
    Found a final node on the uncovered p.d. path: 0
    Path: 2 6 0 3
    Final Path: 2 6 0 3
    Counter: 1 | Number of paths: 1
    t1: 2 6 0 3
    Checking for paths of 4 or more
    Potential theta: 1
    Creating path list
    New Path: 7 1
    mpath: 7 1
    Found a final node on the uncovered p.d. path: 1
    Path: 2 7 1 5
    Final Path: 2 7 1 5
    Counter: 1 | Number of paths: 1
    
    Rule 10
    Orient: 2 -> 4
    Rule 10 has been used 1 times.
    Track changes: 1

# Rule 10 (simple)

    
    Rule 10 [easy]:
    Orient: 0 -> 2
    Rule 10 has been used 1 times.
    Track changes: 1

# Rule 10 (capture simple unprotected pd paths)

    Checking for paths of 4 or more
    Potential theta: 3
    Creating path list
    New Path: 4 3
    mpath: 4 3
    Potential New Value in Path: 2
    Size of old path list: 1
    Size of new path list: 2
    Path 0: 4 3
    Path 1: 4 3 2
    Counter: 1 | Number of paths: 2
    mpath: 4 3 2
    Counter: 2 | Number of paths: 2
    t1: 
    Checking for paths of 4 or more
    t1: 0 5 1
    Checking for paths of 4 or more
    
    Rule 10
    Orient: 0 -> 2
    Rule 10 has been used 1 times.
    Track changes: 1
         [,1] [,2] [,3] [,4] [,5] [,6]
    [1,]    0    0    2    0    1    2
    [2,]    0    0    2    0    0    3
    [3,]    3    3    0    3    0    0
    [4,]    0    0    2    0    1    0
    [5,]    1    0    0    2    0    0
    [6,]    3    2    0    0    0    0

# All Rules is correct.

    Rule 1:
    Orient: 2 *-> 6 o-* 0 as 6 -> 0
    Rule 1 has been used 1 times.
    Rule 1:
    Orient: 6 *-> 0 o-* 3 as 0 -> 3
    Rule 1 has been used 2 times.
    Rule 1:
    Orient: 7 *-> 1 o-* 5 as 1 -> 5
    Rule 1 has been used 3 times.
    Potential alpha: 2 | Potential gamma: 4
    Potential beta: 6
    Potential beta: 7
    Checking for paths of 4 or more
    Potential theta: 1
    Creating path list
    New Path: 7 1
    mpath: 7 1
    Potential New Value in Path: 5
    Size of old path list: 1
    Size of new path list: 2
    Path 0: 7 1
    Path 1: 7 1 5
    Counter: 1 | Number of paths: 2
    mpath: 7 1 5
    Found a final node on the uncovered p.d. path: 5
    Path: 2 7 1 5 4
    Final Path: 2 7 1 5 4
    Counter: 2 | Number of paths: 2
    Rule 9: There exists an uncovered potentially directed path between 2 and 4
    Orient: 2 -> 4
    Rule 9 has been used 1 times.
    Potential alpha: 7 | Potential gamma: 1
    Potential beta: 2
    Checking for paths of 4 or more
    Potential theta: 4
    Potential theta: 6
    Creating path list
    New Path: 2 4
    New Path: 2 6
    mpath: 2 4
    Counter: 1 | Number of paths: 2
    mpath: 2 6
    Potential New Value in Path: 0
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 2 4
    Path 1: 2 6
    Path 2: 2 6 0
    Counter: 2 | Number of paths: 3
    mpath: 2 6 0
    Potential New Value in Path: 3
    Size of old path list: 3
    Size of new path list: 4
    Path 0: 2 4
    Path 1: 2 6
    Path 2: 2 6 0
    Path 3: 2 6 0 3
    Counter: 3 | Number of paths: 4
    mpath: 2 6 0 3
    Counter: 4 | Number of paths: 4
    Potential alpha: 7 | Potential gamma: 1
    Potential beta: 2
    Checking for paths of 4 or more
    Potential theta: 4
    Potential theta: 6
    Creating path list
    New Path: 2 4
    New Path: 2 6
    mpath: 2 4
    Counter: 1 | Number of paths: 2
    mpath: 2 6
    Potential New Value in Path: 0
    Size of old path list: 2
    Size of new path list: 3
    Path 0: 2 4
    Path 1: 2 6
    Path 2: 2 6 0
    Counter: 2 | Number of paths: 3
    mpath: 2 6 0
    Potential New Value in Path: 3
    Size of old path list: 3
    Size of new path list: 4
    Path 0: 2 4
    Path 1: 2 6
    Path 2: 2 6 0
    Path 3: 2 6 0 3
    Counter: 3 | Number of paths: 4
    mpath: 2 6 0 3
    Counter: 4 | Number of paths: 4

# Test conversion of Mixed Graph

    Population Version (C++):
    There are 2 targets.
    Targets: V2 V10
    Target: 1
    FUNCTION getNeighbors. Node 1
    Call from getNeighbors. Node 0 is a parent.
    Call from getNeighbors. Node 2 is a child.
    Call from getNeighbors. We are evaluating the following child: 2
    Call from getNeighbors. Node 3 is a potential spouse of node 1.
    Neighbors of node 1: 0, 2, 3
    
    Target: 9
    FUNCTION getNeighbors. Node 9
    Call from getNeighbors. Node 7 is a child.
    Call from getNeighbors. Node 8 is a child.
    Call from getNeighbors. Node 11 is a parent.
    Call from getNeighbors. We are evaluating the following child: 7
    Call from getNeighbors. Node 6 is a potential spouse of node 9.
    Call from getNeighbors. We are evaluating the following child: 8
    Call from getNeighbors. Node 10 is a potential spouse of node 9.
    Neighbors of node 9: 6, 7, 8, 10, 11
    
    Total Neighborhood:
    0, 2, 3, 6, 7, 8, 10, 11
    There are 12 nodes in the DAG.
    There are 10 nodes in the neighborhood.
    All nodes being considered: 0 1 2 3 6 7 8 9 10 11
    Our starting matrix is 10x10.
    0 1 1 1 1 1 1 1 1 1
    1 0 1 1 1 1 1 1 1 1
    1 1 0 1 1 1 1 1 1 1
    1 1 1 0 1 1 1 1 1 1
    1 1 1 1 0 1 1 1 1 1
    1 1 1 1 1 0 1 1 1 1
    1 1 1 1 1 1 0 1 1 1
    1 1 1 1 1 1 1 0 1 1
    1 1 1 1 1 1 1 1 0 1
    1 1 1 1 1 1 1 1 1 0
    
    
    
    Our initial separating sets:
    S_{0,0} = nan S_{0,1} = nan S_{0,2} = nan S_{0,3} = nan S_{0,6} = nan S_{0,7} = nan S_{0,8} = nan S_{0,9} = nan S_{0,10} = nan S_{0,11} = nan 
    S_{1,0} = nan S_{1,1} = nan S_{1,2} = nan S_{1,3} = nan S_{1,6} = nan S_{1,7} = nan S_{1,8} = nan S_{1,9} = nan S_{1,10} = nan S_{1,11} = nan 
    S_{2,0} = nan S_{2,1} = nan S_{2,2} = nan S_{2,3} = nan S_{2,6} = nan S_{2,7} = nan S_{2,8} = nan S_{2,9} = nan S_{2,10} = nan S_{2,11} = nan 
    S_{3,0} = nan S_{3,1} = nan S_{3,2} = nan S_{3,3} = nan S_{3,6} = nan S_{3,7} = nan S_{3,8} = nan S_{3,9} = nan S_{3,10} = nan S_{3,11} = nan 
    S_{6,0} = nan S_{6,1} = nan S_{6,2} = nan S_{6,3} = nan S_{6,6} = nan S_{6,7} = nan S_{6,8} = nan S_{6,9} = nan S_{6,10} = nan S_{6,11} = nan 
    S_{7,0} = nan S_{7,1} = nan S_{7,2} = nan S_{7,3} = nan S_{7,6} = nan S_{7,7} = nan S_{7,8} = nan S_{7,9} = nan S_{7,10} = nan S_{7,11} = nan 
    S_{8,0} = nan S_{8,1} = nan S_{8,2} = nan S_{8,3} = nan S_{8,6} = nan S_{8,7} = nan S_{8,8} = nan S_{8,9} = nan S_{8,10} = nan S_{8,11} = nan 
    S_{9,0} = nan S_{9,1} = nan S_{9,2} = nan S_{9,3} = nan S_{9,6} = nan S_{9,7} = nan S_{9,8} = nan S_{9,9} = nan S_{9,10} = nan S_{9,11} = nan 
    S_{10,0} = nan S_{10,1} = nan S_{10,2} = nan S_{10,3} = nan S_{10,6} = nan S_{10,7} = nan S_{10,8} = nan S_{10,9} = nan S_{10,10} = nan S_{10,11} = nan 
    S_{11,0} = nan S_{11,1} = nan S_{11,2} = nan S_{11,3} = nan S_{11,6} = nan S_{11,7} = nan S_{11,8} = nan S_{11,9} = nan S_{11,10} = nan S_{11,11} = nan 
    Element mapping for efficient ordering:
    0 0
    1 1
    2 2
    3 3
    6 4
    7 5
    8 6
    9 7
    10 8
    11 9
    We are manually changing the current adjacency matrix.
    0 0 2 2 0 0 0 0
    0 0 2 0 0 0 0 0
    3 1 0 2 0 0 1 2
    2 0 1 0 1 0 0 2
    0 0 0 1 0 0 0 1
    0 0 0 0 0 0 1 3
    0 0 3 0 0 2 0 0
    0 0 3 2 2 1 0 0
    True: 1 | Renumbered: 0
    True: 3 | Renumbered: 1
    True: 2 | Renumbered: 2
    True: 6 | Renumbered: 3
    True: 7 | Renumbered: 4
    True: 8 | Renumbered: 5
    True: 10 | Renumbered: 6
    True: 9 | Renumbered: 7
         [,1] [,2] [,3] [,4] [,5] [,6] [,7] [,8]
    [1,]    0    0    1    2    0    0    0    0
    [2,]    0    0    1    0    0    0    0    0
    [3,]    0    0    0    2    0    0    1    1
    [4,]    2    0    1    0    1    0    0    1
    [5,]    0    0    0    1    0    0    0    0
    [6,]    0    0    0    0    0    0    0    0
    [7,]    0    0    3    0    0    1    0    0
    [8,]    0    0    0    1    1    1    0    0

