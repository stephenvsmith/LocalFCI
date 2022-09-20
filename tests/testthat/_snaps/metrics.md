# Additional pra tests (1)

    t: 2 | i: 0
    t: 2 | i: 1
    t: 2 | i: 3 | Est. Graph: Parent | True graph:  | Undirected edge in True Graph | Potential: 1
    t: 2 | i: 4 | Est. Graph: Not a parent | True graph: Parent | Missing: 1
    t: 2 | i: 5
    t: 2 | i: 6
    t: 2 | i: 7
    t: 2 | i: 8
    t: 2 | i: 9
    t: 2 | i: 10
    t: 6 | i: 0
    t: 6 | i: 1
    t: 6 | i: 2
    t: 6 | i: 3
    t: 6 | i: 4
    t: 6 | i: 5
    t: 6 | i: 7
    t: 6 | i: 8
    t: 6 | i: 9 | Est. Graph: Not a parent | True graph: Parent | Missing: 2
    t: 6 | i: 10
    t: 10 | i: 0
    t: 10 | i: 1
    t: 10 | i: 2
    t: 10 | i: 3
    t: 10 | i: 4
    t: 10 | i: 5
    t: 10 | i: 6
    t: 10 | i: 7 | Est. Graph: Not a parent | True graph: Parent | Missing: 3
    t: 10 | i: 8 | Est. Graph: Parent | True graph:  | Parent | Correct: 1
    t: 10 | i: 9
    $missing
    [1] 3
    
    $added
    [1] 0
    
    $correct
    [1] 1
    
    $potential
    [1] 1
    

---

    t: 2 | i: 0
    t: 2 | i: 1
    t: 2 | i: 3 | Est. Graph: Parent | True graph:  | Undirected edge in True Graph | Potential: 1
    t: 2 | i: 4 | Est. Graph: Not a parent | True graph: Parent | Missing: 1
    t: 2 | i: 5
    t: 2 | i: 6
    t: 2 | i: 7
    t: 2 | i: 8
    t: 2 | i: 9
    t: 2 | i: 10
    t: 6 | i: 0
    t: 6 | i: 1
    t: 6 | i: 2
    t: 6 | i: 3
    t: 6 | i: 4
    t: 6 | i: 5
    t: 6 | i: 7
    t: 6 | i: 8
    t: 6 | i: 9 | Est. Graph: Not a parent | True graph: Parent | Missing: 2
    t: 6 | i: 10
    t: 10 | i: 0
    t: 10 | i: 1
    t: 10 | i: 2
    t: 10 | i: 3
    t: 10 | i: 4
    t: 10 | i: 5
    t: 10 | i: 6
    t: 10 | i: 7 | Est. Graph: Not a parent | True graph: Parent | Missing: 3 | Undirected edge in Est. Graph | Potential: 2
    t: 10 | i: 8 | Est. Graph: Parent | True graph:  | Parent | Correct: 1
    t: 10 | i: 9
    $missing
    [1] 3
    
    $added
    [1] 0
    
    $correct
    [1] 1
    
    $potential
    [1] 2
    

# Additional pra tests (2)

    t: 2 | i: 0
    t: 2 | i: 1
    t: 2 | i: 3 | Both graphs have undirected edges | Potential: 1
    t: 2 | i: 4 | Est. Graph: Not a parent | True graph: Parent | Missing: 1
    t: 2 | i: 5
    t: 2 | i: 6 | Est. Graph: Parent | True graph: Not a parent | Added: 1
    t: 2 | i: 7
    t: 2 | i: 8
    t: 2 | i: 9
    t: 2 | i: 10
    t: 6 | i: 0
    t: 6 | i: 1
    t: 6 | i: 2
    t: 6 | i: 3
    t: 6 | i: 4
    t: 6 | i: 5
    t: 6 | i: 7
    t: 6 | i: 8
    t: 6 | i: 9 | Est. Graph: Not a parent | True graph: Parent | Missing: 2
    t: 6 | i: 10
    t: 10 | i: 0
    t: 10 | i: 1
    t: 10 | i: 2
    t: 10 | i: 3
    t: 10 | i: 4
    t: 10 | i: 5
    t: 10 | i: 6
    t: 10 | i: 7 | Est. Graph: Not a parent | True graph: Parent | Missing: 3
    t: 10 | i: 8 | Est. Graph: Parent | True graph:  | Parent | Correct: 1
    t: 10 | i: 9
    $missing
    [1] 3
    
    $added
    [1] 1
    
    $correct
    [1] 1
    
    $potential
    [1] 1
    

# Additional pra tests (3)

    t: 2 | i: 0
    t: 2 | i: 1
    t: 2 | i: 3 | Est. Graph: Parent | True graph:  | Undirected edge in True Graph | Potential: 1
    t: 2 | i: 4 | Est. Graph: Not a parent | True graph: Parent | Missing: 1
    t: 2 | i: 5
    t: 2 | i: 6
    t: 2 | i: 7
    t: 2 | i: 8
    t: 2 | i: 9
    t: 2 | i: 10
    t: 6 | i: 0
    t: 6 | i: 1
    t: 6 | i: 2
    t: 6 | i: 3
    t: 6 | i: 4
    t: 6 | i: 5
    t: 6 | i: 7
    t: 6 | i: 8
    t: 6 | i: 9 | Est. Graph: Not a parent | True graph: Parent | Missing: 2
    t: 6 | i: 10
    t: 10 | i: 0
    t: 10 | i: 1
    t: 10 | i: 2
    t: 10 | i: 3
    t: 10 | i: 4
    t: 10 | i: 5
    t: 10 | i: 6
    t: 10 | i: 7 | Est. Graph: Not a parent | True graph: Parent | Missing: 3 | Undirected edge in Est. Graph | Potential: 2
    t: 10 | i: 8 | Est. Graph: Parent | True graph:  | Parent | Correct: 1
    t: 10 | i: 9
    $missing
    [1] 3
    
    $added
    [1] 0
    
    $correct
    [1] 1
    
    $potential
    [1] 2
    

# checking metric functions

      lfci_skel_fp lfci_skel_fn lfci_skel_tp lfci_v_fn lfci_v_fp lfci_v_tp
    1            0            0            6         1         0         1
      lfci_pra_fn lfci_pra_fp lfci_pra_tp lfci_pra_potential lfci_ancestors_correct
    1           1           0           4                  1                      0
      lfci_ancestors_missing lfci_ancestors_fn_orient lfci_ancestors_reverse
    1                      0                        0                      0
      lfci_ancestors_fp_oriented lfci_ancestors_fp_connect lfci_overall_f1
    1                          0                         0       0.9090909

---

      pc_skel_fp pc_skel_fn pc_skel_tp pc_v_fn pc_v_fp pc_v_tp pc_pra_fn pc_pra_fp
    1          0          0          6       2       1       0         5         2
      pc_pra_tp pc_pra_potential pc_ancestors_correct pc_ancestors_missing
    1         0                0                    0                    0
      pc_ancestors_fn_orient pc_ancestors_reverse pc_ancestors_fp_oriented
    1                      0                    0                        0
      pc_ancestors_fp_connect pc_overall_f1
    1                       0             0

# Detailed MB Recovery Stats

    [[1]]
      mb_children_fn mb_children_tp mb_parents_fn mb_parents_tp mb_spouses_fn
    1              0              1             0             0             1
      mb_spouses_tp mb_total_fp
    1             0           0
    

# Detailed MB Recovery Stats (2)

    [[1]]
      mb_children_fn mb_children_tp mb_parents_fn mb_parents_tp mb_spouses_fn
    1              0              1             0             0             1
      mb_spouses_tp mb_total_fp
    1             0           0
    
    [[2]]
      mb_children_fn mb_children_tp mb_parents_fn mb_parents_tp mb_spouses_fn
    1              1              0             0             0             1
      mb_spouses_tp mb_total_fp
    1             0           1
    
    [[3]]
      mb_children_fn mb_children_tp mb_parents_fn mb_parents_tp mb_spouses_fn
    1              0              0             0             3             0
      mb_spouses_tp mb_total_fp
    1             0           0
    

# Ancestral Relations

    0 and 1 are in the neighborhood of target 0
    Nodes 0 and 2 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 3 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 4 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 6 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 1 and 2 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 3 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 4 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 6 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 2 and 3 don't share the same target neighborhood
    Nodes 2 and 4 don't share the same target neighborhood
    Nodes 2 and 5 don't share the same target neighborhood
    Nodes 2 and 6 don't share the same target neighborhood
    Nodes 2 and 7 don't share the same target neighborhood
    Nodes 3 and 4 don't share the same target neighborhood
    Nodes 3 and 5 don't share the same target neighborhood
    Nodes 3 and 6 don't share the same target neighborhood
    Nodes 3 and 7 don't share the same target neighborhood
    Nodes 4 and 5 don't share the same target neighborhood
    Nodes 4 and 6 don't share the same target neighborhood
    Nodes 4 and 7 don't share the same target neighborhood
    Nodes 5 and 6 don't share the same target neighborhood
    Nodes 5 and 7 don't share the same target neighborhood
    Nodes 6 and 7 don't share the same target neighborhood
    $CorrectAncestors
    [1] 0
    
    $MissingAncestors
    [1] 0
    
    $MissingOrientation
    [1] 0
    
    $ReverseOrientation
    [1] 0
    
    $FPOrientedEdge
    [1] 0
    
    $AddedConnection
    [1] 0
    

# More ancestral checks (3)

    0 and 1 are in the neighborhood of target 0
    Nodes 0 and 2 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 3 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 4 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 7
    Looking at nodes 0 and 4
    Checking if 0 is an unmediated ancestor of 4
    Node 4 is not a descendant of 0
    Checking if 4 is an unmediated ancestor of 0
    Node 0 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 7
    Looking at nodes 0 and 5
    V0 is an ancestor of V5 2 levels up.
    Checking if 0 is an unmediated ancestor of 5
    V0 is an ancestor of V5 2 levels up.
    V0 is an ancestor of V1 1 levels up.
    Nodes 1 and 5 don't share the same target neighborhood
    V1 is an ancestor of V5 1 levels up.
    1 and 0 are in the neighborhood of target 0
    Node 1 is a child of 0 and is in the same target neighborhood, while also being an ancestor of 5
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 0 and 6 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 7
    Looking at nodes 0 and 7
    V0 is an ancestor of V7 3 levels up.
    Checking if 0 is an unmediated ancestor of 7
    V0 is an ancestor of V7 3 levels up.
    V0 is an ancestor of V5 2 levels up.
    5 and 7 are in the neighborhood of target 7
    Node 5 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 7 is an unmediated ancestor of 0
    Node 0 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 1 and 2 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 3 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 4 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 7
    Looking at nodes 1 and 4
    Checking if 1 is an unmediated ancestor of 4
    Node 4 is not a descendant of 1
    Checking if 4 is an unmediated ancestor of 1
    Node 1 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 7
    Looking at nodes 1 and 5
    V1 is an ancestor of V5 1 levels up.
    Checking if 1 is an unmediated ancestor of 5
    V1 is an ancestor of V5 1 levels up.
    There is an unmediated ancestral path between 1 and 5
    Checking if 5 is an unmediated ancestor of 1
    Node 1 is not a descendant of 5
    Nodes are connected in estimated graph
    True ancestral relationship (i->j)
    Nodes 1 and 6 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 7
    Looking at nodes 1 and 7
    V1 is an ancestor of V7 2 levels up.
    Checking if 1 is an unmediated ancestor of 7
    V1 is an ancestor of V7 2 levels up.
    V1 is an ancestor of V5 1 levels up.
    5 and 7 are in the neighborhood of target 7
    Node 5 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 1
    Checking if 7 is an unmediated ancestor of 1
    Node 1 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 2 and 3 don't share the same target neighborhood
    Nodes 2 and 4 don't share the same target neighborhood
    Nodes 2 and 5 don't share the same target neighborhood
    Nodes 2 and 6 don't share the same target neighborhood
    Nodes 2 and 7 don't share the same target neighborhood
    Nodes 3 and 4 don't share the same target neighborhood
    Nodes 3 and 5 don't share the same target neighborhood
    Nodes 3 and 6 don't share the same target neighborhood
    Nodes 3 and 7 don't share the same target neighborhood
    4 and 5 are in the neighborhood of target 7
    Nodes 4 and 6 don't share the same target neighborhood
    4 is in the neighborhood of target node 7
    4 and 7 are in the neighborhood of target 7
    Nodes 5 and 6 don't share the same target neighborhood
    5 is in the neighborhood of target node 7
    5 and 7 are in the neighborhood of target 7
    Nodes 6 and 7 don't share the same target neighborhood
    $CorrectAncestors
    [1] 1
    
    $MissingAncestors
    [1] 0
    
    $MissingOrientation
    [1] 0
    
    $ReverseOrientation
    [1] 0
    
    $FPOrientedEdge
    [1] 0
    
    $AddedConnection
    [1] 0
    

---

    0 and 1 are in the neighborhood of target 0
    Nodes 0 and 2 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 3 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 4 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 7
    Looking at nodes 0 and 4
    Checking if 0 is an unmediated ancestor of 4
    Node 4 is not a descendant of 0
    Checking if 4 is an unmediated ancestor of 0
    Node 0 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 7
    Looking at nodes 0 and 5
    V0 is an ancestor of V5 2 levels up.
    Checking if 0 is an unmediated ancestor of 5
    V0 is an ancestor of V5 2 levels up.
    V0 is an ancestor of V1 1 levels up.
    Nodes 1 and 5 don't share the same target neighborhood
    V1 is an ancestor of V5 1 levels up.
    1 and 0 are in the neighborhood of target 0
    Node 1 is a child of 0 and is in the same target neighborhood, while also being an ancestor of 5
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 0 and 6 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 7
    Looking at nodes 0 and 7
    V0 is an ancestor of V7 3 levels up.
    Checking if 0 is an unmediated ancestor of 7
    V0 is an ancestor of V7 3 levels up.
    V0 is an ancestor of V5 2 levels up.
    5 and 7 are in the neighborhood of target 7
    Node 5 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 7 is an unmediated ancestor of 0
    Node 0 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 1 and 2 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 3 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 4 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 7
    Looking at nodes 1 and 4
    Checking if 1 is an unmediated ancestor of 4
    Node 4 is not a descendant of 1
    Checking if 4 is an unmediated ancestor of 1
    Node 1 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 7
    Looking at nodes 1 and 5
    V1 is an ancestor of V5 1 levels up.
    Checking if 1 is an unmediated ancestor of 5
    V1 is an ancestor of V5 1 levels up.
    There is an unmediated ancestral path between 1 and 5
    Checking if 5 is an unmediated ancestor of 1
    Node 1 is not a descendant of 5
    Nodes are connected in estimated graph
    Missing orientation of ancestral relationship (i->j)
    Nodes 1 and 6 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 7
    Looking at nodes 1 and 7
    V1 is an ancestor of V7 2 levels up.
    Checking if 1 is an unmediated ancestor of 7
    V1 is an ancestor of V7 2 levels up.
    V1 is an ancestor of V5 1 levels up.
    5 and 7 are in the neighborhood of target 7
    Node 5 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 1
    Checking if 7 is an unmediated ancestor of 1
    Node 1 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 2 and 3 don't share the same target neighborhood
    Nodes 2 and 4 don't share the same target neighborhood
    Nodes 2 and 5 don't share the same target neighborhood
    Nodes 2 and 6 don't share the same target neighborhood
    Nodes 2 and 7 don't share the same target neighborhood
    Nodes 3 and 4 don't share the same target neighborhood
    Nodes 3 and 5 don't share the same target neighborhood
    Nodes 3 and 6 don't share the same target neighborhood
    Nodes 3 and 7 don't share the same target neighborhood
    4 and 5 are in the neighborhood of target 7
    Nodes 4 and 6 don't share the same target neighborhood
    4 is in the neighborhood of target node 7
    4 and 7 are in the neighborhood of target 7
    Nodes 5 and 6 don't share the same target neighborhood
    5 is in the neighborhood of target node 7
    5 and 7 are in the neighborhood of target 7
    Nodes 6 and 7 don't share the same target neighborhood
    $CorrectAncestors
    [1] 0
    
    $MissingAncestors
    [1] 0
    
    $MissingOrientation
    [1] 1
    
    $ReverseOrientation
    [1] 0
    
    $FPOrientedEdge
    [1] 0
    
    $AddedConnection
    [1] 0
    

---

    Nodes 0 and 1 don't share the same target neighborhood
    Nodes 0 and 2 don't share the same target neighborhood
    Nodes 0 and 3 don't share the same target neighborhood
    Nodes 0 and 4 don't share the same target neighborhood
    Nodes 0 and 5 don't share the same target neighborhood
    Nodes 0 and 6 don't share the same target neighborhood
    Nodes 0 and 7 don't share the same target neighborhood
    Nodes 1 and 2 don't share the same target neighborhood
    Nodes 1 and 3 don't share the same target neighborhood
    Nodes 1 and 4 don't share the same target neighborhood
    Nodes 1 and 5 don't share the same target neighborhood
    Nodes 1 and 6 don't share the same target neighborhood
    Nodes 1 and 7 don't share the same target neighborhood
    2 and 3 are in the neighborhood of target 2
    2 and 4 are in the neighborhood of target 2
    Nodes 2 and 5 don't share the same target neighborhood
    2 is in the neighborhood of target node 2
    5 is in the neighborhood of target node 6
    Looking at nodes 2 and 5
    V2 is an ancestor of V5 2 levels up.
    Checking if 2 is an unmediated ancestor of 5
    V2 is an ancestor of V5 2 levels up.
    V2 is an ancestor of V3 1 levels up.
    Nodes 3 and 5 don't share the same target neighborhood
    V3 is an ancestor of V5 1 levels up.
    3 and 2 are in the neighborhood of target 2
    Node 3 is a child of 2 and is in the same target neighborhood, while also being an ancestor of 5
    Checking if 5 is an unmediated ancestor of 2
    Node 2 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 2 and 6 don't share the same target neighborhood
    2 is in the neighborhood of target node 2
    6 is in the neighborhood of target node 6
    Looking at nodes 2 and 6
    V2 is an ancestor of V6 3 levels up.
    Checking if 2 is an unmediated ancestor of 6
    V2 is an ancestor of V6 3 levels up.
    V2 is an ancestor of V5 2 levels up.
    5 and 6 are in the neighborhood of target 6
    Node 5 is a parent of 6 and is in the same target neighborhood, while also being a descendant of 2
    Checking if 6 is an unmediated ancestor of 2
    Node 2 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 2 and 7 don't share the same target neighborhood
    2 is in the neighborhood of target node 2
    3 and 4 are in the neighborhood of target 2
    Nodes 3 and 5 don't share the same target neighborhood
    3 is in the neighborhood of target node 2
    5 is in the neighborhood of target node 6
    Looking at nodes 3 and 5
    V3 is an ancestor of V5 1 levels up.
    Checking if 3 is an unmediated ancestor of 5
    V3 is an ancestor of V5 1 levels up.
    There is an unmediated ancestral path between 3 and 5
    Checking if 5 is an unmediated ancestor of 3
    Node 3 is not a descendant of 5
    Nodes are connected in estimated graph
    Missing orientation of ancestral relationship (i->j)
    Nodes 3 and 6 don't share the same target neighborhood
    3 is in the neighborhood of target node 2
    6 is in the neighborhood of target node 6
    Looking at nodes 3 and 6
    V3 is an ancestor of V6 2 levels up.
    Checking if 3 is an unmediated ancestor of 6
    V3 is an ancestor of V6 2 levels up.
    V3 is an ancestor of V5 1 levels up.
    5 and 6 are in the neighborhood of target 6
    Node 5 is a parent of 6 and is in the same target neighborhood, while also being a descendant of 3
    Checking if 6 is an unmediated ancestor of 3
    Node 3 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 3 and 7 don't share the same target neighborhood
    3 is in the neighborhood of target node 2
    Nodes 4 and 5 don't share the same target neighborhood
    4 is in the neighborhood of target node 2
    5 is in the neighborhood of target node 6
    Looking at nodes 4 and 5
    Checking if 4 is an unmediated ancestor of 5
    Node 5 is not a descendant of 4
    Checking if 5 is an unmediated ancestor of 4
    Node 4 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 4 and 6 don't share the same target neighborhood
    4 is in the neighborhood of target node 2
    6 is in the neighborhood of target node 6
    Looking at nodes 4 and 6
    Checking if 4 is an unmediated ancestor of 6
    Node 6 is not a descendant of 4
    Checking if 6 is an unmediated ancestor of 4
    Node 4 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 4 and 7 don't share the same target neighborhood
    4 is in the neighborhood of target node 2
    5 and 6 are in the neighborhood of target 6
    Nodes 5 and 7 don't share the same target neighborhood
    5 is in the neighborhood of target node 6
    Nodes 6 and 7 don't share the same target neighborhood
    6 is in the neighborhood of target node 6
    $CorrectAncestors
    [1] 0
    
    $MissingAncestors
    [1] 0
    
    $MissingOrientation
    [1] 1
    
    $ReverseOrientation
    [1] 0
    
    $FPOrientedEdge
    [1] 0
    
    $AddedConnection
    [1] 0
    

# More ancestral relations tests (1)

    0 and 1 are in the neighborhood of target 3
    0 and 2 are in the neighborhood of target 3
    0 and 3 are in the neighborhood of target 3
    0 and 4 are in the neighborhood of target 3
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 0 and 5
    Checking if 0 is an unmediated ancestor of 5
    Node 5 is not a descendant of 0
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    0 and 6 are in the neighborhood of target 3
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 0 and 7
    V0 is an ancestor of V7 3 levels up.
    Checking if 0 is an unmediated ancestor of 7
    V0 is an ancestor of V7 3 levels up.
    V0 is an ancestor of V8 2 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 7 is an unmediated ancestor of 0
    Node 0 is not a descendant of 7
    Nodes are unconnected in estimated graph
    0 and 8 are in the neighborhood of target 3
    Nodes 0 and 9 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    Nodes 0 and 10 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    Nodes 0 and 11 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 0 and 11
    Checking if 0 is an unmediated ancestor of 11
    Node 11 is not a descendant of 0
    V11 is an ancestor of V0 3 levels up.
    Checking if 11 is an unmediated ancestor of 0
    V11 is an ancestor of V0 3 levels up.
    V11 is an ancestor of V10 2 levels up.
    Nodes 10 and 0 don't share the same target neighborhood
    V15 is an ancestor of V0 2 levels up.
    Nodes 15 and 11 don't share the same target neighborhood
    There is an unmediated ancestral path between 11 and 0
    Nodes are connected in estimated graph
    Orientation Reversed: i->j instead of j->i
    Nodes 0 and 12 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 0 and 12
    Checking if 0 is an unmediated ancestor of 12
    Node 12 is not a descendant of 0
    V12 is an ancestor of V0 4 levels up.
    Checking if 12 is an unmediated ancestor of 0
    V12 is an ancestor of V0 4 levels up.
    V12 is an ancestor of V10 3 levels up.
    Nodes 10 and 0 don't share the same target neighborhood
    V11 is an ancestor of V0 3 levels up.
    11 and 12 are in the neighborhood of target 12
    Node 11 is a child of 12 and is in the same target neighborhood, while also being an ancestor of 0
    Nodes are unconnected in estimated graph
    Nodes 0 and 13 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 0 and 13
    Checking if 0 is an unmediated ancestor of 13
    Node 13 is not a descendant of 0
    Checking if 13 is an unmediated ancestor of 0
    Node 0 is not a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 0 and 14 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 0 and 14
    Checking if 0 is an unmediated ancestor of 14
    Node 14 is not a descendant of 0
    Checking if 14 is an unmediated ancestor of 0
    Node 0 is not a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 0 and 15 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    1 and 2 are in the neighborhood of target 3
    1 and 3 are in the neighborhood of target 3
    1 and 4 are in the neighborhood of target 3
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 1 and 5
    Checking if 1 is an unmediated ancestor of 5
    Node 5 is not a descendant of 1
    Checking if 5 is an unmediated ancestor of 1
    Node 1 is not a descendant of 5
    Nodes are unconnected in estimated graph
    1 and 6 are in the neighborhood of target 3
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 1 and 7
    V1 is an ancestor of V7 3 levels up.
    Checking if 1 is an unmediated ancestor of 7
    V1 is an ancestor of V7 3 levels up.
    V1 is an ancestor of V8 2 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 1
    Checking if 7 is an unmediated ancestor of 1
    Node 1 is not a descendant of 7
    Nodes are unconnected in estimated graph
    1 and 8 are in the neighborhood of target 3
    Nodes 1 and 9 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    Nodes 1 and 10 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    Nodes 1 and 11 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 1 and 11
    Checking if 1 is an unmediated ancestor of 11
    Node 11 is not a descendant of 1
    Checking if 11 is an unmediated ancestor of 1
    Node 1 is not a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 1 and 12 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 1 and 12
    Checking if 1 is an unmediated ancestor of 12
    Node 12 is not a descendant of 1
    Checking if 12 is an unmediated ancestor of 1
    Node 1 is not a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 1 and 13 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 1 and 13
    Checking if 1 is an unmediated ancestor of 13
    Node 13 is not a descendant of 1
    Checking if 13 is an unmediated ancestor of 1
    Node 1 is not a descendant of 13
    Nodes are connected in estimated graph
    False positive connection
    Nodes 1 and 14 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 1 and 14
    Checking if 1 is an unmediated ancestor of 14
    Node 14 is not a descendant of 1
    Checking if 14 is an unmediated ancestor of 1
    Node 1 is not a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 1 and 15 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    2 and 3 are in the neighborhood of target 3
    2 and 4 are in the neighborhood of target 3
    Nodes 2 and 5 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 2 and 5
    Checking if 2 is an unmediated ancestor of 5
    Node 5 is not a descendant of 2
    V5 is an ancestor of V2 3 levels up.
    Checking if 5 is an unmediated ancestor of 2
    V5 is an ancestor of V2 3 levels up.
    V5 is an ancestor of V3 2 levels up.
    3 and 2 are in the neighborhood of target 3
    Node 3 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 5
    Nodes are unconnected in estimated graph
    2 and 6 are in the neighborhood of target 3
    Nodes 2 and 7 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 2 and 7
    Checking if 2 is an unmediated ancestor of 7
    Node 7 is not a descendant of 2
    Checking if 7 is an unmediated ancestor of 2
    Node 2 is not a descendant of 7
    Nodes are unconnected in estimated graph
    2 and 8 are in the neighborhood of target 3
    Nodes 2 and 9 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    Nodes 2 and 10 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    Nodes 2 and 11 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 2 and 11
    Checking if 2 is an unmediated ancestor of 11
    Node 11 is not a descendant of 2
    V11 is an ancestor of V2 4 levels up.
    Checking if 11 is an unmediated ancestor of 2
    V11 is an ancestor of V2 4 levels up.
    V11 is an ancestor of V0 3 levels up.
    0 and 2 are in the neighborhood of target 3
    Node 0 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 2 and 12 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 2 and 12
    Checking if 2 is an unmediated ancestor of 12
    Node 12 is not a descendant of 2
    V12 is an ancestor of V2 4 levels up.
    Checking if 12 is an unmediated ancestor of 2
    V12 is an ancestor of V2 4 levels up.
    V12 is an ancestor of V0 4 levels up.
    0 and 2 are in the neighborhood of target 3
    Node 0 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 2 and 13 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 2 and 13
    Checking if 2 is an unmediated ancestor of 13
    Node 13 is not a descendant of 2
    V13 is an ancestor of V2 4 levels up.
    Checking if 13 is an unmediated ancestor of 2
    V13 is an ancestor of V2 4 levels up.
    V13 is an ancestor of V3 3 levels up.
    3 and 2 are in the neighborhood of target 3
    Node 3 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 2 and 14 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 2 and 14
    Checking if 2 is an unmediated ancestor of 14
    Node 14 is not a descendant of 2
    V14 is an ancestor of V2 3 levels up.
    Checking if 14 is an unmediated ancestor of 2
    V14 is an ancestor of V2 3 levels up.
    V14 is an ancestor of V3 2 levels up.
    3 and 2 are in the neighborhood of target 3
    Node 3 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 2 and 15 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    3 and 4 are in the neighborhood of target 3
    Nodes 3 and 5 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 3 and 5
    Checking if 3 is an unmediated ancestor of 5
    Node 5 is not a descendant of 3
    V5 is an ancestor of V3 2 levels up.
    Checking if 5 is an unmediated ancestor of 3
    V5 is an ancestor of V3 2 levels up.
    V5 is an ancestor of V4 1 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 5
    Nodes are unconnected in estimated graph
    3 and 6 are in the neighborhood of target 3
    Nodes 3 and 7 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 3 and 7
    V3 is an ancestor of V7 2 levels up.
    Checking if 3 is an unmediated ancestor of 7
    V3 is an ancestor of V7 2 levels up.
    V3 is an ancestor of V8 1 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 3
    Checking if 7 is an unmediated ancestor of 3
    Node 3 is not a descendant of 7
    Nodes are unconnected in estimated graph
    3 and 8 are in the neighborhood of target 3
    Nodes 3 and 9 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    Nodes 3 and 10 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    Nodes 3 and 11 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 3 and 11
    Checking if 3 is an unmediated ancestor of 11
    Node 11 is not a descendant of 3
    V11 is an ancestor of V3 4 levels up.
    Checking if 11 is an unmediated ancestor of 3
    V11 is an ancestor of V3 4 levels up.
    V11 is an ancestor of V0 3 levels up.
    0 and 3 are in the neighborhood of target 3
    Node 0 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 3 and 12 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 3 and 12
    Checking if 3 is an unmediated ancestor of 12
    Node 12 is not a descendant of 3
    V12 is an ancestor of V3 3 levels up.
    Checking if 12 is an unmediated ancestor of 3
    V12 is an ancestor of V3 3 levels up.
    V12 is an ancestor of V0 4 levels up.
    0 and 3 are in the neighborhood of target 3
    Node 0 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 3 and 13 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 3 and 13
    Checking if 3 is an unmediated ancestor of 13
    Node 13 is not a descendant of 3
    V13 is an ancestor of V3 3 levels up.
    Checking if 13 is an unmediated ancestor of 3
    V13 is an ancestor of V3 3 levels up.
    V13 is an ancestor of V4 2 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 3 and 14 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 3 and 14
    Checking if 3 is an unmediated ancestor of 14
    Node 14 is not a descendant of 3
    V14 is an ancestor of V3 2 levels up.
    Checking if 14 is an unmediated ancestor of 3
    V14 is an ancestor of V3 2 levels up.
    V14 is an ancestor of V6 1 levels up.
    6 and 3 are in the neighborhood of target 3
    Node 6 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are connected in estimated graph
    False positive connection
    Nodes 3 and 15 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    Nodes 4 and 5 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 4 and 5
    Checking if 4 is an unmediated ancestor of 5
    Node 5 is not a descendant of 4
    V5 is an ancestor of V4 1 levels up.
    Checking if 5 is an unmediated ancestor of 4
    V5 is an ancestor of V4 1 levels up.
    V5 is an ancestor of V9 2 levels up.
    Nodes 9 and 4 don't share the same target neighborhood
    V13 is an ancestor of V4 2 levels up.
    13 and 5 are in the neighborhood of target 12
    Node 13 is a child of 5 and is in the same target neighborhood, while also being an ancestor of 4
    Nodes are unconnected in estimated graph
    4 and 6 are in the neighborhood of target 3
    Nodes 4 and 7 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 4 and 7
    V4 is an ancestor of V7 3 levels up.
    Checking if 4 is an unmediated ancestor of 7
    V4 is an ancestor of V7 3 levels up.
    V4 is an ancestor of V8 2 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 4
    Checking if 7 is an unmediated ancestor of 4
    Node 4 is not a descendant of 7
    Nodes are unconnected in estimated graph
    4 and 8 are in the neighborhood of target 3
    Nodes 4 and 9 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    Nodes 4 and 10 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    Nodes 4 and 11 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 4 and 11
    Checking if 4 is an unmediated ancestor of 11
    Node 11 is not a descendant of 4
    Checking if 11 is an unmediated ancestor of 4
    Node 4 is not a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 4 and 12 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 4 and 12
    Checking if 4 is an unmediated ancestor of 12
    Node 12 is not a descendant of 4
    V12 is an ancestor of V4 3 levels up.
    Checking if 12 is an unmediated ancestor of 4
    V12 is an ancestor of V4 3 levels up.
    V12 is an ancestor of V9 2 levels up.
    Nodes 9 and 4 don't share the same target neighborhood
    V13 is an ancestor of V4 2 levels up.
    13 and 12 are in the neighborhood of target 12
    Node 13 is a child of 12 and is in the same target neighborhood, while also being an ancestor of 4
    Nodes are unconnected in estimated graph
    Nodes 4 and 13 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 4 and 13
    Checking if 4 is an unmediated ancestor of 13
    Node 13 is not a descendant of 4
    V13 is an ancestor of V4 2 levels up.
    Checking if 13 is an unmediated ancestor of 4
    V13 is an ancestor of V4 2 levels up.
    V13 is an ancestor of V9 1 levels up.
    Nodes 9 and 4 don't share the same target neighborhood
    V9 is an ancestor of V4 1 levels up.
    Nodes 9 and 13 don't share the same target neighborhood
    There is an unmediated ancestral path between 13 and 4
    Nodes are connected in estimated graph
    Missing orientation of ancestral relationship (j->i)
    Nodes 4 and 14 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 4 and 14
    Checking if 4 is an unmediated ancestor of 14
    Node 14 is not a descendant of 4
    Checking if 14 is an unmediated ancestor of 4
    Node 4 is not a descendant of 14
    Nodes are connected in estimated graph
    False positive ancestral relationship
    Nodes 4 and 15 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    Nodes 5 and 6 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    6 is in the neighborhood of target node 3
    Looking at nodes 5 and 6
    Checking if 5 is an unmediated ancestor of 6
    Node 6 is not a descendant of 5
    Checking if 6 is an unmediated ancestor of 5
    Node 5 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 5 and 7 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    7 is in the neighborhood of target node 7
    Looking at nodes 5 and 7
    V5 is an ancestor of V7 4 levels up.
    Checking if 5 is an unmediated ancestor of 7
    V5 is an ancestor of V7 4 levels up.
    V5 is an ancestor of V8 3 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 5
    Checking if 7 is an unmediated ancestor of 5
    Node 5 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 5 and 8 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    8 is in the neighborhood of target node 3
    Looking at nodes 5 and 8
    V5 is an ancestor of V8 3 levels up.
    Checking if 5 is an unmediated ancestor of 8
    V5 is an ancestor of V8 3 levels up.
    V5 is an ancestor of V3 2 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 5
    Checking if 8 is an unmediated ancestor of 5
    Node 5 is not a descendant of 8
    Nodes are unconnected in estimated graph
    Nodes 5 and 9 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    Nodes 5 and 10 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    5 and 11 are in the neighborhood of target 12
    5 and 12 are in the neighborhood of target 12
    5 and 13 are in the neighborhood of target 12
    5 and 14 are in the neighborhood of target 12
    Nodes 5 and 15 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    6 and 7 are in the neighborhood of target 7
    6 and 8 are in the neighborhood of target 3
    Nodes 6 and 9 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    Nodes 6 and 10 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    Nodes 6 and 11 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 6 and 11
    Checking if 6 is an unmediated ancestor of 11
    Node 11 is not a descendant of 6
    Checking if 11 is an unmediated ancestor of 6
    Node 6 is not a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 6 and 12 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 6 and 12
    Checking if 6 is an unmediated ancestor of 12
    Node 12 is not a descendant of 6
    V12 is an ancestor of V6 2 levels up.
    Checking if 12 is an unmediated ancestor of 6
    V12 is an ancestor of V6 2 levels up.
    V12 is an ancestor of V14 1 levels up.
    Nodes 14 and 6 don't share the same target neighborhood
    V14 is an ancestor of V6 1 levels up.
    14 and 12 are in the neighborhood of target 12
    Node 14 is a child of 12 and is in the same target neighborhood, while also being an ancestor of 6
    Nodes are unconnected in estimated graph
    Nodes 6 and 13 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 6 and 13
    Checking if 6 is an unmediated ancestor of 13
    Node 13 is not a descendant of 6
    Checking if 13 is an unmediated ancestor of 6
    Node 6 is not a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 6 and 14 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 6 and 14
    Checking if 6 is an unmediated ancestor of 14
    Node 14 is not a descendant of 6
    V14 is an ancestor of V6 1 levels up.
    Checking if 14 is an unmediated ancestor of 6
    V14 is an ancestor of V6 1 levels up.
    There is an unmediated ancestral path between 14 and 6
    Nodes are unconnected in estimated graph
    Missing ancestral relationship
    Nodes 6 and 15 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    7 and 8 are in the neighborhood of target 7
    Nodes 7 and 9 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    Nodes 7 and 10 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    Nodes 7 and 11 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    11 is in the neighborhood of target node 12
    Looking at nodes 7 and 11
    Checking if 7 is an unmediated ancestor of 11
    Node 11 is not a descendant of 7
    V11 is an ancestor of V7 6 levels up.
    Checking if 11 is an unmediated ancestor of 7
    V11 is an ancestor of V7 6 levels up.
    V11 is an ancestor of V8 5 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 7 and 12 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    12 is in the neighborhood of target node 12
    Looking at nodes 7 and 12
    Checking if 7 is an unmediated ancestor of 12
    Node 12 is not a descendant of 7
    V12 is an ancestor of V7 3 levels up.
    Checking if 12 is an unmediated ancestor of 7
    V12 is an ancestor of V7 3 levels up.
    V12 is an ancestor of V6 2 levels up.
    6 and 7 are in the neighborhood of target 7
    Node 6 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 7 and 13 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    13 is in the neighborhood of target node 12
    Looking at nodes 7 and 13
    Checking if 7 is an unmediated ancestor of 13
    Node 13 is not a descendant of 7
    V13 is an ancestor of V7 5 levels up.
    Checking if 13 is an unmediated ancestor of 7
    V13 is an ancestor of V7 5 levels up.
    V13 is an ancestor of V8 4 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 7 and 14 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    14 is in the neighborhood of target node 12
    Looking at nodes 7 and 14
    Checking if 7 is an unmediated ancestor of 14
    Node 14 is not a descendant of 7
    V14 is an ancestor of V7 2 levels up.
    Checking if 14 is an unmediated ancestor of 7
    V14 is an ancestor of V7 2 levels up.
    V14 is an ancestor of V6 1 levels up.
    6 and 7 are in the neighborhood of target 7
    Node 6 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 7 and 15 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    Nodes 8 and 9 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    Nodes 8 and 10 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    Nodes 8 and 11 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 8 and 11
    Checking if 8 is an unmediated ancestor of 11
    Node 11 is not a descendant of 8
    V11 is an ancestor of V8 5 levels up.
    Checking if 11 is an unmediated ancestor of 8
    V11 is an ancestor of V8 5 levels up.
    V11 is an ancestor of V3 4 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 8 and 12 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 8 and 12
    Checking if 8 is an unmediated ancestor of 12
    Node 12 is not a descendant of 8
    V12 is an ancestor of V8 4 levels up.
    Checking if 12 is an unmediated ancestor of 8
    V12 is an ancestor of V8 4 levels up.
    V12 is an ancestor of V3 3 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are connected in estimated graph
    False positive connection
    Nodes 8 and 13 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 8 and 13
    Checking if 8 is an unmediated ancestor of 13
    Node 13 is not a descendant of 8
    V13 is an ancestor of V8 4 levels up.
    Checking if 13 is an unmediated ancestor of 8
    V13 is an ancestor of V8 4 levels up.
    V13 is an ancestor of V3 3 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 8 and 14 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 8 and 14
    Checking if 8 is an unmediated ancestor of 14
    Node 14 is not a descendant of 8
    V14 is an ancestor of V8 3 levels up.
    Checking if 14 is an unmediated ancestor of 8
    V14 is an ancestor of V8 3 levels up.
    V14 is an ancestor of V3 2 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 8 and 15 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    Nodes 9 and 10 don't share the same target neighborhood
    Nodes 9 and 11 don't share the same target neighborhood
    Nodes 9 and 12 don't share the same target neighborhood
    Nodes 9 and 13 don't share the same target neighborhood
    Nodes 9 and 14 don't share the same target neighborhood
    Nodes 9 and 15 don't share the same target neighborhood
    Nodes 10 and 11 don't share the same target neighborhood
    Nodes 10 and 12 don't share the same target neighborhood
    Nodes 10 and 13 don't share the same target neighborhood
    Nodes 10 and 14 don't share the same target neighborhood
    Nodes 10 and 15 don't share the same target neighborhood
    11 and 12 are in the neighborhood of target 12
    11 and 13 are in the neighborhood of target 12
    11 and 14 are in the neighborhood of target 12
    Nodes 11 and 15 don't share the same target neighborhood
    11 is in the neighborhood of target node 12
    12 and 13 are in the neighborhood of target 12
    12 and 14 are in the neighborhood of target 12
    Nodes 12 and 15 don't share the same target neighborhood
    12 is in the neighborhood of target node 12
    13 and 14 are in the neighborhood of target 12
    Nodes 13 and 15 don't share the same target neighborhood
    13 is in the neighborhood of target node 12
    Nodes 14 and 15 don't share the same target neighborhood
    14 is in the neighborhood of target node 12
    $CorrectAncestors
    [1] 0
    
    $MissingAncestors
    [1] 1
    
    $MissingOrientation
    [1] 1
    
    $ReverseOrientation
    [1] 1
    
    $FPOrientedEdge
    [1] 1
    
    $AddedConnection
    [1] 3
    

# More ancestral relations tests (2)

    0 and 1 are in the neighborhood of target 3
    0 and 2 are in the neighborhood of target 3
    0 and 3 are in the neighborhood of target 3
    0 and 4 are in the neighborhood of target 3
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 0 and 5
    Checking if 0 is an unmediated ancestor of 5
    Node 5 is not a descendant of 0
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    0 and 6 are in the neighborhood of target 3
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 0 and 7
    V0 is an ancestor of V7 3 levels up.
    Checking if 0 is an unmediated ancestor of 7
    V0 is an ancestor of V7 3 levels up.
    V0 is an ancestor of V8 2 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 7 is an unmediated ancestor of 0
    Node 0 is not a descendant of 7
    Nodes are unconnected in estimated graph
    0 and 8 are in the neighborhood of target 3
    Nodes 0 and 9 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    Nodes 0 and 10 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    Nodes 0 and 11 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 0 and 11
    Checking if 0 is an unmediated ancestor of 11
    Node 11 is not a descendant of 0
    V11 is an ancestor of V0 3 levels up.
    Checking if 11 is an unmediated ancestor of 0
    V11 is an ancestor of V0 3 levels up.
    V11 is an ancestor of V10 2 levels up.
    Nodes 10 and 0 don't share the same target neighborhood
    V15 is an ancestor of V0 2 levels up.
    Nodes 15 and 11 don't share the same target neighborhood
    There is an unmediated ancestral path between 11 and 0
    Nodes are connected in estimated graph
    True ancestral relationship (j->i)
    Nodes 0 and 12 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 0 and 12
    Checking if 0 is an unmediated ancestor of 12
    Node 12 is not a descendant of 0
    V12 is an ancestor of V0 4 levels up.
    Checking if 12 is an unmediated ancestor of 0
    V12 is an ancestor of V0 4 levels up.
    V12 is an ancestor of V10 3 levels up.
    Nodes 10 and 0 don't share the same target neighborhood
    V11 is an ancestor of V0 3 levels up.
    11 and 12 are in the neighborhood of target 12
    Node 11 is a child of 12 and is in the same target neighborhood, while also being an ancestor of 0
    Nodes are unconnected in estimated graph
    Nodes 0 and 13 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 0 and 13
    Checking if 0 is an unmediated ancestor of 13
    Node 13 is not a descendant of 0
    Checking if 13 is an unmediated ancestor of 0
    Node 0 is not a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 0 and 14 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 0 and 14
    Checking if 0 is an unmediated ancestor of 14
    Node 14 is not a descendant of 0
    Checking if 14 is an unmediated ancestor of 0
    Node 0 is not a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 0 and 15 don't share the same target neighborhood
    0 is in the neighborhood of target node 3
    1 and 2 are in the neighborhood of target 3
    1 and 3 are in the neighborhood of target 3
    1 and 4 are in the neighborhood of target 3
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 1 and 5
    Checking if 1 is an unmediated ancestor of 5
    Node 5 is not a descendant of 1
    Checking if 5 is an unmediated ancestor of 1
    Node 1 is not a descendant of 5
    Nodes are unconnected in estimated graph
    1 and 6 are in the neighborhood of target 3
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 1 and 7
    V1 is an ancestor of V7 3 levels up.
    Checking if 1 is an unmediated ancestor of 7
    V1 is an ancestor of V7 3 levels up.
    V1 is an ancestor of V8 2 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 1
    Checking if 7 is an unmediated ancestor of 1
    Node 1 is not a descendant of 7
    Nodes are unconnected in estimated graph
    1 and 8 are in the neighborhood of target 3
    Nodes 1 and 9 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    Nodes 1 and 10 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    Nodes 1 and 11 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 1 and 11
    Checking if 1 is an unmediated ancestor of 11
    Node 11 is not a descendant of 1
    Checking if 11 is an unmediated ancestor of 1
    Node 1 is not a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 1 and 12 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 1 and 12
    Checking if 1 is an unmediated ancestor of 12
    Node 12 is not a descendant of 1
    Checking if 12 is an unmediated ancestor of 1
    Node 1 is not a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 1 and 13 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 1 and 13
    Checking if 1 is an unmediated ancestor of 13
    Node 13 is not a descendant of 1
    Checking if 13 is an unmediated ancestor of 1
    Node 1 is not a descendant of 13
    Nodes are connected in estimated graph
    False positive connection
    Nodes 1 and 14 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 1 and 14
    Checking if 1 is an unmediated ancestor of 14
    Node 14 is not a descendant of 1
    Checking if 14 is an unmediated ancestor of 1
    Node 1 is not a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 1 and 15 don't share the same target neighborhood
    1 is in the neighborhood of target node 3
    2 and 3 are in the neighborhood of target 3
    2 and 4 are in the neighborhood of target 3
    Nodes 2 and 5 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 2 and 5
    Checking if 2 is an unmediated ancestor of 5
    Node 5 is not a descendant of 2
    V5 is an ancestor of V2 3 levels up.
    Checking if 5 is an unmediated ancestor of 2
    V5 is an ancestor of V2 3 levels up.
    V5 is an ancestor of V3 2 levels up.
    3 and 2 are in the neighborhood of target 3
    Node 3 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 5
    Nodes are unconnected in estimated graph
    2 and 6 are in the neighborhood of target 3
    Nodes 2 and 7 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 2 and 7
    Checking if 2 is an unmediated ancestor of 7
    Node 7 is not a descendant of 2
    Checking if 7 is an unmediated ancestor of 2
    Node 2 is not a descendant of 7
    Nodes are unconnected in estimated graph
    2 and 8 are in the neighborhood of target 3
    Nodes 2 and 9 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    Nodes 2 and 10 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    Nodes 2 and 11 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 2 and 11
    Checking if 2 is an unmediated ancestor of 11
    Node 11 is not a descendant of 2
    V11 is an ancestor of V2 4 levels up.
    Checking if 11 is an unmediated ancestor of 2
    V11 is an ancestor of V2 4 levels up.
    V11 is an ancestor of V0 3 levels up.
    0 and 2 are in the neighborhood of target 3
    Node 0 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 2 and 12 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 2 and 12
    Checking if 2 is an unmediated ancestor of 12
    Node 12 is not a descendant of 2
    V12 is an ancestor of V2 4 levels up.
    Checking if 12 is an unmediated ancestor of 2
    V12 is an ancestor of V2 4 levels up.
    V12 is an ancestor of V0 4 levels up.
    0 and 2 are in the neighborhood of target 3
    Node 0 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 2 and 13 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 2 and 13
    Checking if 2 is an unmediated ancestor of 13
    Node 13 is not a descendant of 2
    V13 is an ancestor of V2 4 levels up.
    Checking if 13 is an unmediated ancestor of 2
    V13 is an ancestor of V2 4 levels up.
    V13 is an ancestor of V3 3 levels up.
    3 and 2 are in the neighborhood of target 3
    Node 3 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 2 and 14 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 2 and 14
    Checking if 2 is an unmediated ancestor of 14
    Node 14 is not a descendant of 2
    V14 is an ancestor of V2 3 levels up.
    Checking if 14 is an unmediated ancestor of 2
    V14 is an ancestor of V2 3 levels up.
    V14 is an ancestor of V3 2 levels up.
    3 and 2 are in the neighborhood of target 3
    Node 3 is a parent of 2 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 2 and 15 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    3 and 4 are in the neighborhood of target 3
    Nodes 3 and 5 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 3 and 5
    Checking if 3 is an unmediated ancestor of 5
    Node 5 is not a descendant of 3
    V5 is an ancestor of V3 2 levels up.
    Checking if 5 is an unmediated ancestor of 3
    V5 is an ancestor of V3 2 levels up.
    V5 is an ancestor of V4 1 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 5
    Nodes are unconnected in estimated graph
    3 and 6 are in the neighborhood of target 3
    Nodes 3 and 7 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 3 and 7
    V3 is an ancestor of V7 2 levels up.
    Checking if 3 is an unmediated ancestor of 7
    V3 is an ancestor of V7 2 levels up.
    V3 is an ancestor of V8 1 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 3
    Checking if 7 is an unmediated ancestor of 3
    Node 3 is not a descendant of 7
    Nodes are unconnected in estimated graph
    3 and 8 are in the neighborhood of target 3
    Nodes 3 and 9 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    Nodes 3 and 10 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    Nodes 3 and 11 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 3 and 11
    Checking if 3 is an unmediated ancestor of 11
    Node 11 is not a descendant of 3
    V11 is an ancestor of V3 4 levels up.
    Checking if 11 is an unmediated ancestor of 3
    V11 is an ancestor of V3 4 levels up.
    V11 is an ancestor of V0 3 levels up.
    0 and 3 are in the neighborhood of target 3
    Node 0 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 3 and 12 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 3 and 12
    Checking if 3 is an unmediated ancestor of 12
    Node 12 is not a descendant of 3
    V12 is an ancestor of V3 3 levels up.
    Checking if 12 is an unmediated ancestor of 3
    V12 is an ancestor of V3 3 levels up.
    V12 is an ancestor of V0 4 levels up.
    0 and 3 are in the neighborhood of target 3
    Node 0 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 3 and 13 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 3 and 13
    Checking if 3 is an unmediated ancestor of 13
    Node 13 is not a descendant of 3
    V13 is an ancestor of V3 3 levels up.
    Checking if 13 is an unmediated ancestor of 3
    V13 is an ancestor of V3 3 levels up.
    V13 is an ancestor of V4 2 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 3 and 14 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 3 and 14
    Checking if 3 is an unmediated ancestor of 14
    Node 14 is not a descendant of 3
    V14 is an ancestor of V3 2 levels up.
    Checking if 14 is an unmediated ancestor of 3
    V14 is an ancestor of V3 2 levels up.
    V14 is an ancestor of V6 1 levels up.
    6 and 3 are in the neighborhood of target 3
    Node 6 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are connected in estimated graph
    False positive connection
    Nodes 3 and 15 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    Nodes 4 and 5 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 12
    Looking at nodes 4 and 5
    Checking if 4 is an unmediated ancestor of 5
    Node 5 is not a descendant of 4
    V5 is an ancestor of V4 1 levels up.
    Checking if 5 is an unmediated ancestor of 4
    V5 is an ancestor of V4 1 levels up.
    V5 is an ancestor of V9 2 levels up.
    Nodes 9 and 4 don't share the same target neighborhood
    V13 is an ancestor of V4 2 levels up.
    13 and 5 are in the neighborhood of target 12
    Node 13 is a child of 5 and is in the same target neighborhood, while also being an ancestor of 4
    Nodes are unconnected in estimated graph
    4 and 6 are in the neighborhood of target 3
    Nodes 4 and 7 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 7
    Looking at nodes 4 and 7
    V4 is an ancestor of V7 3 levels up.
    Checking if 4 is an unmediated ancestor of 7
    V4 is an ancestor of V7 3 levels up.
    V4 is an ancestor of V8 2 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 4
    Checking if 7 is an unmediated ancestor of 4
    Node 4 is not a descendant of 7
    Nodes are unconnected in estimated graph
    4 and 8 are in the neighborhood of target 3
    Nodes 4 and 9 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    Nodes 4 and 10 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    Nodes 4 and 11 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 4 and 11
    Checking if 4 is an unmediated ancestor of 11
    Node 11 is not a descendant of 4
    Checking if 11 is an unmediated ancestor of 4
    Node 4 is not a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 4 and 12 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 4 and 12
    Checking if 4 is an unmediated ancestor of 12
    Node 12 is not a descendant of 4
    V12 is an ancestor of V4 3 levels up.
    Checking if 12 is an unmediated ancestor of 4
    V12 is an ancestor of V4 3 levels up.
    V12 is an ancestor of V9 2 levels up.
    Nodes 9 and 4 don't share the same target neighborhood
    V13 is an ancestor of V4 2 levels up.
    13 and 12 are in the neighborhood of target 12
    Node 13 is a child of 12 and is in the same target neighborhood, while also being an ancestor of 4
    Nodes are unconnected in estimated graph
    Nodes 4 and 13 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 4 and 13
    Checking if 4 is an unmediated ancestor of 13
    Node 13 is not a descendant of 4
    V13 is an ancestor of V4 2 levels up.
    Checking if 13 is an unmediated ancestor of 4
    V13 is an ancestor of V4 2 levels up.
    V13 is an ancestor of V9 1 levels up.
    Nodes 9 and 4 don't share the same target neighborhood
    V9 is an ancestor of V4 1 levels up.
    Nodes 9 and 13 don't share the same target neighborhood
    There is an unmediated ancestral path between 13 and 4
    Nodes are connected in estimated graph
    Missing orientation of ancestral relationship (j->i)
    Nodes 4 and 14 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 4 and 14
    Checking if 4 is an unmediated ancestor of 14
    Node 14 is not a descendant of 4
    Checking if 14 is an unmediated ancestor of 4
    Node 4 is not a descendant of 14
    Nodes are connected in estimated graph
    False positive ancestral relationship
    Nodes 4 and 15 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    Nodes 5 and 6 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    6 is in the neighborhood of target node 3
    Looking at nodes 5 and 6
    Checking if 5 is an unmediated ancestor of 6
    Node 6 is not a descendant of 5
    Checking if 6 is an unmediated ancestor of 5
    Node 5 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 5 and 7 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    7 is in the neighborhood of target node 7
    Looking at nodes 5 and 7
    V5 is an ancestor of V7 4 levels up.
    Checking if 5 is an unmediated ancestor of 7
    V5 is an ancestor of V7 4 levels up.
    V5 is an ancestor of V8 3 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 5
    Checking if 7 is an unmediated ancestor of 5
    Node 5 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 5 and 8 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    8 is in the neighborhood of target node 3
    Looking at nodes 5 and 8
    V5 is an ancestor of V8 3 levels up.
    Checking if 5 is an unmediated ancestor of 8
    V5 is an ancestor of V8 3 levels up.
    V5 is an ancestor of V3 2 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 5
    Checking if 8 is an unmediated ancestor of 5
    Node 5 is not a descendant of 8
    Nodes are unconnected in estimated graph
    Nodes 5 and 9 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    Nodes 5 and 10 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    5 and 11 are in the neighborhood of target 12
    5 and 12 are in the neighborhood of target 12
    5 and 13 are in the neighborhood of target 12
    5 and 14 are in the neighborhood of target 12
    Nodes 5 and 15 don't share the same target neighborhood
    5 is in the neighborhood of target node 12
    6 and 7 are in the neighborhood of target 7
    6 and 8 are in the neighborhood of target 3
    Nodes 6 and 9 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    Nodes 6 and 10 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    Nodes 6 and 11 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 6 and 11
    Checking if 6 is an unmediated ancestor of 11
    Node 11 is not a descendant of 6
    Checking if 11 is an unmediated ancestor of 6
    Node 6 is not a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 6 and 12 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 6 and 12
    Checking if 6 is an unmediated ancestor of 12
    Node 12 is not a descendant of 6
    V12 is an ancestor of V6 2 levels up.
    Checking if 12 is an unmediated ancestor of 6
    V12 is an ancestor of V6 2 levels up.
    V12 is an ancestor of V14 1 levels up.
    Nodes 14 and 6 don't share the same target neighborhood
    V14 is an ancestor of V6 1 levels up.
    14 and 12 are in the neighborhood of target 12
    Node 14 is a child of 12 and is in the same target neighborhood, while also being an ancestor of 6
    Nodes are unconnected in estimated graph
    Nodes 6 and 13 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 6 and 13
    Checking if 6 is an unmediated ancestor of 13
    Node 13 is not a descendant of 6
    Checking if 13 is an unmediated ancestor of 6
    Node 6 is not a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 6 and 14 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 6 and 14
    Checking if 6 is an unmediated ancestor of 14
    Node 14 is not a descendant of 6
    V14 is an ancestor of V6 1 levels up.
    Checking if 14 is an unmediated ancestor of 6
    V14 is an ancestor of V6 1 levels up.
    There is an unmediated ancestral path between 14 and 6
    Nodes are unconnected in estimated graph
    Missing ancestral relationship
    Nodes 6 and 15 don't share the same target neighborhood
    6 is in the neighborhood of target node 3
    7 and 8 are in the neighborhood of target 7
    Nodes 7 and 9 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    Nodes 7 and 10 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    Nodes 7 and 11 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    11 is in the neighborhood of target node 12
    Looking at nodes 7 and 11
    Checking if 7 is an unmediated ancestor of 11
    Node 11 is not a descendant of 7
    V11 is an ancestor of V7 6 levels up.
    Checking if 11 is an unmediated ancestor of 7
    V11 is an ancestor of V7 6 levels up.
    V11 is an ancestor of V8 5 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 7 and 12 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    12 is in the neighborhood of target node 12
    Looking at nodes 7 and 12
    Checking if 7 is an unmediated ancestor of 12
    Node 12 is not a descendant of 7
    V12 is an ancestor of V7 3 levels up.
    Checking if 12 is an unmediated ancestor of 7
    V12 is an ancestor of V7 3 levels up.
    V12 is an ancestor of V6 2 levels up.
    6 and 7 are in the neighborhood of target 7
    Node 6 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are unconnected in estimated graph
    Nodes 7 and 13 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    13 is in the neighborhood of target node 12
    Looking at nodes 7 and 13
    Checking if 7 is an unmediated ancestor of 13
    Node 13 is not a descendant of 7
    V13 is an ancestor of V7 5 levels up.
    Checking if 13 is an unmediated ancestor of 7
    V13 is an ancestor of V7 5 levels up.
    V13 is an ancestor of V8 4 levels up.
    8 and 7 are in the neighborhood of target 7
    Node 8 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 7 and 14 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    14 is in the neighborhood of target node 12
    Looking at nodes 7 and 14
    Checking if 7 is an unmediated ancestor of 14
    Node 14 is not a descendant of 7
    V14 is an ancestor of V7 2 levels up.
    Checking if 14 is an unmediated ancestor of 7
    V14 is an ancestor of V7 2 levels up.
    V14 is an ancestor of V6 1 levels up.
    6 and 7 are in the neighborhood of target 7
    Node 6 is a parent of 7 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 7 and 15 don't share the same target neighborhood
    7 is in the neighborhood of target node 7
    Nodes 8 and 9 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    Nodes 8 and 10 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    Nodes 8 and 11 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    11 is in the neighborhood of target node 12
    Looking at nodes 8 and 11
    Checking if 8 is an unmediated ancestor of 11
    Node 11 is not a descendant of 8
    V11 is an ancestor of V8 5 levels up.
    Checking if 11 is an unmediated ancestor of 8
    V11 is an ancestor of V8 5 levels up.
    V11 is an ancestor of V3 4 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 11
    Nodes are unconnected in estimated graph
    Nodes 8 and 12 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    12 is in the neighborhood of target node 12
    Looking at nodes 8 and 12
    Checking if 8 is an unmediated ancestor of 12
    Node 12 is not a descendant of 8
    V12 is an ancestor of V8 4 levels up.
    Checking if 12 is an unmediated ancestor of 8
    V12 is an ancestor of V8 4 levels up.
    V12 is an ancestor of V3 3 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 12
    Nodes are connected in estimated graph
    False positive connection
    Nodes 8 and 13 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    13 is in the neighborhood of target node 12
    Looking at nodes 8 and 13
    Checking if 8 is an unmediated ancestor of 13
    Node 13 is not a descendant of 8
    V13 is an ancestor of V8 4 levels up.
    Checking if 13 is an unmediated ancestor of 8
    V13 is an ancestor of V8 4 levels up.
    V13 is an ancestor of V3 3 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 13
    Nodes are unconnected in estimated graph
    Nodes 8 and 14 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    14 is in the neighborhood of target node 12
    Looking at nodes 8 and 14
    Checking if 8 is an unmediated ancestor of 14
    Node 14 is not a descendant of 8
    V14 is an ancestor of V8 3 levels up.
    Checking if 14 is an unmediated ancestor of 8
    V14 is an ancestor of V8 3 levels up.
    V14 is an ancestor of V3 2 levels up.
    3 and 8 are in the neighborhood of target 3
    Node 3 is a parent of 8 and is in the same target neighborhood, while also being a descendant of 14
    Nodes are unconnected in estimated graph
    Nodes 8 and 15 don't share the same target neighborhood
    8 is in the neighborhood of target node 3
    Nodes 9 and 10 don't share the same target neighborhood
    Nodes 9 and 11 don't share the same target neighborhood
    Nodes 9 and 12 don't share the same target neighborhood
    Nodes 9 and 13 don't share the same target neighborhood
    Nodes 9 and 14 don't share the same target neighborhood
    Nodes 9 and 15 don't share the same target neighborhood
    Nodes 10 and 11 don't share the same target neighborhood
    Nodes 10 and 12 don't share the same target neighborhood
    Nodes 10 and 13 don't share the same target neighborhood
    Nodes 10 and 14 don't share the same target neighborhood
    Nodes 10 and 15 don't share the same target neighborhood
    11 and 12 are in the neighborhood of target 12
    11 and 13 are in the neighborhood of target 12
    11 and 14 are in the neighborhood of target 12
    Nodes 11 and 15 don't share the same target neighborhood
    11 is in the neighborhood of target node 12
    12 and 13 are in the neighborhood of target 12
    12 and 14 are in the neighborhood of target 12
    Nodes 12 and 15 don't share the same target neighborhood
    12 is in the neighborhood of target node 12
    13 and 14 are in the neighborhood of target 12
    Nodes 13 and 15 don't share the same target neighborhood
    13 is in the neighborhood of target node 12
    Nodes 14 and 15 don't share the same target neighborhood
    14 is in the neighborhood of target node 12
    $CorrectAncestors
    [1] 1
    
    $MissingAncestors
    [1] 1
    
    $MissingOrientation
    [1] 1
    
    $ReverseOrientation
    [1] 0
    
    $FPOrientedEdge
    [1] 1
    
    $AddedConnection
    [1] 3
    

# Additional ancestral comparison tests

    0 and 1 are in the neighborhood of target 0
    Nodes 0 and 2 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    2 is in the neighborhood of target node 3
    Looking at nodes 0 and 2
    V0 is an ancestor of V2 2 levels up.
    Checking if 0 is an unmediated ancestor of 2
    V0 is an ancestor of V2 2 levels up.
    V0 is an ancestor of V1 1 levels up.
    Nodes 1 and 2 don't share the same target neighborhood
    V1 is an ancestor of V2 1 levels up.
    1 and 0 are in the neighborhood of target 0
    Node 1 is a child of 0 and is in the same target neighborhood, while also being an ancestor of 2
    Checking if 2 is an unmediated ancestor of 0
    Node 0 is not a descendant of 2
    Nodes are unconnected in estimated graph
    Nodes 0 and 3 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    3 is in the neighborhood of target node 3
    Looking at nodes 0 and 3
    V0 is an ancestor of V3 3 levels up.
    Checking if 0 is an unmediated ancestor of 3
    V0 is an ancestor of V3 3 levels up.
    V0 is an ancestor of V2 2 levels up.
    2 and 3 are in the neighborhood of target 3
    Node 2 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 3 is an unmediated ancestor of 0
    Node 0 is not a descendant of 3
    Nodes are unconnected in estimated graph
    Nodes 0 and 4 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 3
    Looking at nodes 0 and 4
    Checking if 0 is an unmediated ancestor of 4
    Node 4 is not a descendant of 0
    Checking if 4 is an unmediated ancestor of 0
    Node 0 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 6
    Looking at nodes 0 and 5
    Checking if 0 is an unmediated ancestor of 5
    Node 5 is not a descendant of 0
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 0 and 6 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    6 is in the neighborhood of target node 6
    Looking at nodes 0 and 6
    Checking if 0 is an unmediated ancestor of 6
    Node 6 is not a descendant of 0
    Checking if 6 is an unmediated ancestor of 0
    Node 0 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 6
    Looking at nodes 0 and 7
    Checking if 0 is an unmediated ancestor of 7
    Node 7 is not a descendant of 0
    Checking if 7 is an unmediated ancestor of 0
    Node 0 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 1 and 2 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    2 is in the neighborhood of target node 3
    Looking at nodes 1 and 2
    V1 is an ancestor of V2 1 levels up.
    Checking if 1 is an unmediated ancestor of 2
    V1 is an ancestor of V2 1 levels up.
    There is an unmediated ancestral path between 1 and 2
    Checking if 2 is an unmediated ancestor of 1
    Node 1 is not a descendant of 2
    Nodes are connected in estimated graph
    Orientation Reversed: j->i instead of i->j
    Nodes 1 and 3 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    3 is in the neighborhood of target node 3
    Looking at nodes 1 and 3
    V1 is an ancestor of V3 2 levels up.
    Checking if 1 is an unmediated ancestor of 3
    V1 is an ancestor of V3 2 levels up.
    V1 is an ancestor of V2 1 levels up.
    2 and 3 are in the neighborhood of target 3
    Node 2 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 1
    Checking if 3 is an unmediated ancestor of 1
    Node 1 is not a descendant of 3
    Nodes are unconnected in estimated graph
    Nodes 1 and 4 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 3
    Looking at nodes 1 and 4
    Checking if 1 is an unmediated ancestor of 4
    Node 4 is not a descendant of 1
    Checking if 4 is an unmediated ancestor of 1
    Node 1 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 6
    Looking at nodes 1 and 5
    Checking if 1 is an unmediated ancestor of 5
    Node 5 is not a descendant of 1
    Checking if 5 is an unmediated ancestor of 1
    Node 1 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 1 and 6 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    6 is in the neighborhood of target node 6
    Looking at nodes 1 and 6
    Checking if 1 is an unmediated ancestor of 6
    Node 6 is not a descendant of 1
    Checking if 6 is an unmediated ancestor of 1
    Node 1 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 6
    Looking at nodes 1 and 7
    Checking if 1 is an unmediated ancestor of 7
    Node 7 is not a descendant of 1
    Checking if 7 is an unmediated ancestor of 1
    Node 1 is not a descendant of 7
    Nodes are unconnected in estimated graph
    2 and 3 are in the neighborhood of target 3
    2 and 4 are in the neighborhood of target 3
    Nodes 2 and 5 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 6
    Looking at nodes 2 and 5
    Checking if 2 is an unmediated ancestor of 5
    Node 5 is not a descendant of 2
    Checking if 5 is an unmediated ancestor of 2
    Node 2 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 2 and 6 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    6 is in the neighborhood of target node 6
    Looking at nodes 2 and 6
    Checking if 2 is an unmediated ancestor of 6
    Node 6 is not a descendant of 2
    Checking if 6 is an unmediated ancestor of 2
    Node 2 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 2 and 7 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 6
    Looking at nodes 2 and 7
    Checking if 2 is an unmediated ancestor of 7
    Node 7 is not a descendant of 2
    Checking if 7 is an unmediated ancestor of 2
    Node 2 is not a descendant of 7
    Nodes are unconnected in estimated graph
    3 and 4 are in the neighborhood of target 3
    Nodes 3 and 5 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 6
    Looking at nodes 3 and 5
    Checking if 3 is an unmediated ancestor of 5
    Node 5 is not a descendant of 3
    V5 is an ancestor of V3 2 levels up.
    Checking if 5 is an unmediated ancestor of 3
    V5 is an ancestor of V3 2 levels up.
    V5 is an ancestor of V4 1 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 3 and 6 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    6 is in the neighborhood of target node 6
    Looking at nodes 3 and 6
    Checking if 3 is an unmediated ancestor of 6
    Node 6 is not a descendant of 3
    V6 is an ancestor of V3 3 levels up.
    Checking if 6 is an unmediated ancestor of 3
    V6 is an ancestor of V3 3 levels up.
    V6 is an ancestor of V4 2 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 3 and 7 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 6
    Looking at nodes 3 and 7
    Checking if 3 is an unmediated ancestor of 7
    Node 7 is not a descendant of 3
    Checking if 7 is an unmediated ancestor of 3
    Node 3 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 4 and 5 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 6
    Looking at nodes 4 and 5
    Checking if 4 is an unmediated ancestor of 5
    Node 5 is not a descendant of 4
    V5 is an ancestor of V4 1 levels up.
    Checking if 5 is an unmediated ancestor of 4
    V5 is an ancestor of V4 1 levels up.
    There is an unmediated ancestral path between 5 and 4
    Nodes are unconnected in estimated graph
    Missing ancestral relationship
    Nodes 4 and 6 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    6 is in the neighborhood of target node 6
    Looking at nodes 4 and 6
    Checking if 4 is an unmediated ancestor of 6
    Node 6 is not a descendant of 4
    V6 is an ancestor of V4 2 levels up.
    Checking if 6 is an unmediated ancestor of 4
    V6 is an ancestor of V4 2 levels up.
    V6 is an ancestor of V5 1 levels up.
    Nodes 5 and 4 don't share the same target neighborhood
    V5 is an ancestor of V4 1 levels up.
    5 and 6 are in the neighborhood of target 6
    Node 5 is a child of 6 and is in the same target neighborhood, while also being an ancestor of 4
    Nodes are connected in estimated graph
    False positive connection
    Nodes 4 and 7 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 6
    Looking at nodes 4 and 7
    Checking if 4 is an unmediated ancestor of 7
    Node 7 is not a descendant of 4
    Checking if 7 is an unmediated ancestor of 4
    Node 4 is not a descendant of 7
    Nodes are unconnected in estimated graph
    5 and 6 are in the neighborhood of target 6
    5 and 7 are in the neighborhood of target 6
    6 and 7 are in the neighborhood of target 6
    $CorrectAncestors
    [1] 0
    
    $MissingAncestors
    [1] 1
    
    $MissingOrientation
    [1] 0
    
    $ReverseOrientation
    [1] 1
    
    $FPOrientedEdge
    [1] 0
    
    $AddedConnection
    [1] 1
    

# Additional ancestral comparison tests (2)

    0 and 1 are in the neighborhood of target 0
    Nodes 0 and 2 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    2 is in the neighborhood of target node 3
    Looking at nodes 0 and 2
    V0 is an ancestor of V2 2 levels up.
    Checking if 0 is an unmediated ancestor of 2
    V0 is an ancestor of V2 2 levels up.
    V0 is an ancestor of V1 1 levels up.
    Nodes 1 and 2 don't share the same target neighborhood
    V1 is an ancestor of V2 1 levels up.
    1 and 0 are in the neighborhood of target 0
    Node 1 is a child of 0 and is in the same target neighborhood, while also being an ancestor of 2
    Checking if 2 is an unmediated ancestor of 0
    Node 0 is not a descendant of 2
    Nodes are unconnected in estimated graph
    Nodes 0 and 3 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    3 is in the neighborhood of target node 3
    Looking at nodes 0 and 3
    V0 is an ancestor of V3 3 levels up.
    Checking if 0 is an unmediated ancestor of 3
    V0 is an ancestor of V3 3 levels up.
    V0 is an ancestor of V2 2 levels up.
    2 and 3 are in the neighborhood of target 3
    Node 2 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 3 is an unmediated ancestor of 0
    Node 0 is not a descendant of 3
    Nodes are unconnected in estimated graph
    Nodes 0 and 4 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 3
    Looking at nodes 0 and 4
    Checking if 0 is an unmediated ancestor of 4
    Node 4 is not a descendant of 0
    Checking if 4 is an unmediated ancestor of 0
    Node 0 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 6
    Looking at nodes 0 and 5
    Checking if 0 is an unmediated ancestor of 5
    Node 5 is not a descendant of 0
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 0 and 6 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    6 is in the neighborhood of target node 6
    Looking at nodes 0 and 6
    Checking if 0 is an unmediated ancestor of 6
    Node 6 is not a descendant of 0
    Checking if 6 is an unmediated ancestor of 0
    Node 0 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 0 and 7 don't share the same target neighborhood
    0 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 6
    Looking at nodes 0 and 7
    Checking if 0 is an unmediated ancestor of 7
    Node 7 is not a descendant of 0
    Checking if 7 is an unmediated ancestor of 0
    Node 0 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 1 and 2 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    2 is in the neighborhood of target node 3
    Looking at nodes 1 and 2
    V1 is an ancestor of V2 1 levels up.
    Checking if 1 is an unmediated ancestor of 2
    V1 is an ancestor of V2 1 levels up.
    There is an unmediated ancestral path between 1 and 2
    Checking if 2 is an unmediated ancestor of 1
    Node 1 is not a descendant of 2
    Nodes are connected in estimated graph
    Orientation Reversed: j->i instead of i->j
    Nodes 1 and 3 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    3 is in the neighborhood of target node 3
    Looking at nodes 1 and 3
    V1 is an ancestor of V3 2 levels up.
    Checking if 1 is an unmediated ancestor of 3
    V1 is an ancestor of V3 2 levels up.
    V1 is an ancestor of V2 1 levels up.
    2 and 3 are in the neighborhood of target 3
    Node 2 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 1
    Checking if 3 is an unmediated ancestor of 1
    Node 1 is not a descendant of 3
    Nodes are unconnected in estimated graph
    Nodes 1 and 4 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    4 is in the neighborhood of target node 3
    Looking at nodes 1 and 4
    Checking if 1 is an unmediated ancestor of 4
    Node 4 is not a descendant of 1
    Checking if 4 is an unmediated ancestor of 1
    Node 1 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 1 and 5 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    5 is in the neighborhood of target node 6
    Looking at nodes 1 and 5
    Checking if 1 is an unmediated ancestor of 5
    Node 5 is not a descendant of 1
    Checking if 5 is an unmediated ancestor of 1
    Node 1 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 1 and 6 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    6 is in the neighborhood of target node 6
    Looking at nodes 1 and 6
    Checking if 1 is an unmediated ancestor of 6
    Node 6 is not a descendant of 1
    Checking if 6 is an unmediated ancestor of 1
    Node 1 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 1 and 7 don't share the same target neighborhood
    1 is in the neighborhood of target node 0
    7 is in the neighborhood of target node 6
    Looking at nodes 1 and 7
    Checking if 1 is an unmediated ancestor of 7
    Node 7 is not a descendant of 1
    Checking if 7 is an unmediated ancestor of 1
    Node 1 is not a descendant of 7
    Nodes are unconnected in estimated graph
    2 and 3 are in the neighborhood of target 3
    2 and 4 are in the neighborhood of target 3
    Nodes 2 and 5 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 6
    Looking at nodes 2 and 5
    Checking if 2 is an unmediated ancestor of 5
    Node 5 is not a descendant of 2
    Checking if 5 is an unmediated ancestor of 2
    Node 2 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 2 and 6 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    6 is in the neighborhood of target node 6
    Looking at nodes 2 and 6
    Checking if 2 is an unmediated ancestor of 6
    Node 6 is not a descendant of 2
    Checking if 6 is an unmediated ancestor of 2
    Node 2 is not a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 2 and 7 don't share the same target neighborhood
    2 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 6
    Looking at nodes 2 and 7
    Checking if 2 is an unmediated ancestor of 7
    Node 7 is not a descendant of 2
    Checking if 7 is an unmediated ancestor of 2
    Node 2 is not a descendant of 7
    Nodes are unconnected in estimated graph
    3 and 4 are in the neighborhood of target 3
    Nodes 3 and 5 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 6
    Looking at nodes 3 and 5
    Checking if 3 is an unmediated ancestor of 5
    Node 5 is not a descendant of 3
    V5 is an ancestor of V3 2 levels up.
    Checking if 5 is an unmediated ancestor of 3
    V5 is an ancestor of V3 2 levels up.
    V5 is an ancestor of V4 1 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 3 and 6 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    6 is in the neighborhood of target node 6
    Looking at nodes 3 and 6
    Checking if 3 is an unmediated ancestor of 6
    Node 6 is not a descendant of 3
    V6 is an ancestor of V3 3 levels up.
    Checking if 6 is an unmediated ancestor of 3
    V6 is an ancestor of V3 3 levels up.
    V6 is an ancestor of V4 2 levels up.
    4 and 3 are in the neighborhood of target 3
    Node 4 is a parent of 3 and is in the same target neighborhood, while also being a descendant of 6
    Nodes are unconnected in estimated graph
    Nodes 3 and 7 don't share the same target neighborhood
    3 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 6
    Looking at nodes 3 and 7
    Checking if 3 is an unmediated ancestor of 7
    Node 7 is not a descendant of 3
    Checking if 7 is an unmediated ancestor of 3
    Node 3 is not a descendant of 7
    Nodes are unconnected in estimated graph
    Nodes 4 and 5 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    5 is in the neighborhood of target node 6
    Looking at nodes 4 and 5
    Checking if 4 is an unmediated ancestor of 5
    Node 5 is not a descendant of 4
    V5 is an ancestor of V4 1 levels up.
    Checking if 5 is an unmediated ancestor of 4
    V5 is an ancestor of V4 1 levels up.
    There is an unmediated ancestral path between 5 and 4
    Nodes are connected in estimated graph
    True ancestral relationship (j->i)
    Nodes 4 and 6 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    6 is in the neighborhood of target node 6
    Looking at nodes 4 and 6
    Checking if 4 is an unmediated ancestor of 6
    Node 6 is not a descendant of 4
    V6 is an ancestor of V4 2 levels up.
    Checking if 6 is an unmediated ancestor of 4
    V6 is an ancestor of V4 2 levels up.
    V6 is an ancestor of V5 1 levels up.
    Nodes 5 and 4 don't share the same target neighborhood
    V5 is an ancestor of V4 1 levels up.
    5 and 6 are in the neighborhood of target 6
    Node 5 is a child of 6 and is in the same target neighborhood, while also being an ancestor of 4
    Nodes are connected in estimated graph
    False positive connection
    Nodes 4 and 7 don't share the same target neighborhood
    4 is in the neighborhood of target node 3
    7 is in the neighborhood of target node 6
    Looking at nodes 4 and 7
    Checking if 4 is an unmediated ancestor of 7
    Node 7 is not a descendant of 4
    Checking if 7 is an unmediated ancestor of 4
    Node 4 is not a descendant of 7
    Nodes are unconnected in estimated graph
    5 and 6 are in the neighborhood of target 6
    5 and 7 are in the neighborhood of target 6
    6 and 7 are in the neighborhood of target 6
    $CorrectAncestors
    [1] 1
    
    $MissingAncestors
    [1] 0
    
    $MissingOrientation
    [1] 0
    
    $ReverseOrientation
    [1] 1
    
    $FPOrientedEdge
    [1] 0
    
    $AddedConnection
    [1] 1
    

# Testing Overall F1 Score Function

    Edge between 0 and 1 appears in true graph but not in the estimated graph. FN=1
    Edge between 2 and 3 appears in true graph but not in the estimated graph. FN=2
    Edge between 3 and 4 match. TP=1
    Edge between 5 and 6 appears in true graph but not in the estimated graph. FN=3
    Edge between 6 and 7 match. TP=2
    [1] 0.5714286

# Testing Overall F1 (2)

    Edge between 0 and 1 appears in true graph but not in the estimated graph. FN=1
    Edge between 2 and 3 appears in true graph but not in the estimated graph. FN=2
    Edge between 3 and 4 match. TP=1
    Edge between 5 and 6 match. TP=2
    Edge between 6 and 7 match. TP=3
    [1] 0.75

# Testing Overall F1 (3)

    Edge between 0 and 1 appears in true graph but not in the estimated graph. FN=1
    Edge between 2 and 3 appears in true graph but not in the estimated graph. FN=2
    Edge between 3 and 4 match. TP=1
    Edge between 5 and 6 appears in true graph but not in the estimated graph. FN=3
    Edge between 5 and 7 appears in estimated graph but not in the true graph. FP=1
    Edge between 6 and 7 match. TP=2
    [1] 0.5

