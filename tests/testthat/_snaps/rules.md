# Rule 1 is correct.

    Rule 1:
    Orient: 1 *-> 3 o-* 4 as 3 -> 4
    Track changes: 1

# Rule 2 is correct.

    Rule 2:
    Orient: 0 *-> 1 -> 2 as: 0 *-> 2
    Rule 2:
    Orient: 3 -> 4 *-> 5 as: 3 *-> 5
    Track changes: 1

# Rule 3 is correct.

    Rule 3:
    Orient: 6 *-> 4
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
    Track changes: 1

# Rule 8 is correct.

    
    Rule 8
    Orient: 0 o-> 1 -> 5 with 0 o-> 5 as 0 -> 5
    
    Rule 8
    Orient: 3 -> 4 -> 5 with 3 o-> 5 as 3 -> 5
    Track changes: 1

# Rule 9 is correct.

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
    Track changes: 1

# All Rules is correct.

    Rule 1:
    Orient: 2 *-> 6 o-* 0 as 6 -> 0
    Rule 1:
    Orient: 6 *-> 0 o-* 3 as 0 -> 3
    Rule 1:
    Orient: 7 *-> 1 o-* 5 as 1 -> 5
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

