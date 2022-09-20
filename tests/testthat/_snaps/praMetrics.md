# Testing Parent Recovery Accuracy Metrics

    t: 2 | i: 0 | Est. Graph: Not a parent | True graph: Parent | Missing: 1
    t: 2 | i: 1 | Est. Graph: Parent | True graph: Not a parent | Added: 1
    t: 2 | i: 3 | Est. Graph: Parent | True graph: Not a parent | Added: 2
    t: 2 | i: 4
    t: 2 | i: 5
    t: 4 | i: 0
    t: 4 | i: 1 | Est. Graph: Parent | True graph:  | Parent | Correct: 1
    t: 4 | i: 2
    t: 4 | i: 3 | Est. Graph: Not a parent | True graph: Parent | Missing: 2 | Undirected edge in Est. Graph | Potential: 1
    t: 4 | i: 5 | Est. Graph: Parent | True graph:  | Undirected edge in True Graph | Potential: 2
    $missing
    [1] 2
    
    $added
    [1] 2
    
    $correct
    [1] 1
    
    $potential
    [1] 2
    

---

    Nodes 0 and 1 don't share the same target neighborhood
    0 is in the neighborhood of target node 2
    1 is in the neighborhood of target node 4
    Looking at nodes 0 and 1
    Checking if 0 is an unmediated ancestor of 1
    Node 1 is not a descendant of 0
    Checking if 1 is an unmediated ancestor of 0
    Node 0 is not a descendant of 1
    Nodes are unconnected in estimated graph
    0 and 2 are in the neighborhood of target 2
    0 and 3 are in the neighborhood of target 2
    Nodes 0 and 4 don't share the same target neighborhood
    0 is in the neighborhood of target node 2
    4 is in the neighborhood of target node 4
    Looking at nodes 0 and 4
    V0 is an ancestor of V4 3 levels up.
    Checking if 0 is an unmediated ancestor of 4
    V0 is an ancestor of V4 3 levels up.
    V0 is an ancestor of V3 2 levels up.
    3 and 4 are in the neighborhood of target 4
    Node 3 is a parent of 4 and is in the same target neighborhood, while also being a descendant of 0
    Checking if 4 is an unmediated ancestor of 0
    Node 0 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 0 and 5 don't share the same target neighborhood
    0 is in the neighborhood of target node 2
    5 is in the neighborhood of target node 4
    Looking at nodes 0 and 5
    Checking if 0 is an unmediated ancestor of 5
    Node 5 is not a descendant of 0
    Checking if 5 is an unmediated ancestor of 0
    Node 0 is not a descendant of 5
    Nodes are unconnected in estimated graph
    Nodes 1 and 2 don't share the same target neighborhood
    1 is in the neighborhood of target node 4
    2 is in the neighborhood of target node 2
    Looking at nodes 1 and 2
    Checking if 1 is an unmediated ancestor of 2
    Node 2 is not a descendant of 1
    Checking if 2 is an unmediated ancestor of 1
    Node 1 is not a descendant of 2
    Nodes are connected in estimated graph
    False positive ancestral relationship
    1 and 3 are in the neighborhood of target 4
    1 and 4 are in the neighborhood of target 4
    1 and 5 are in the neighborhood of target 4
    2 and 3 are in the neighborhood of target 2
    Nodes 2 and 4 don't share the same target neighborhood
    2 is in the neighborhood of target node 2
    4 is in the neighborhood of target node 4
    Looking at nodes 2 and 4
    V2 is an ancestor of V4 2 levels up.
    Checking if 2 is an unmediated ancestor of 4
    V2 is an ancestor of V4 2 levels up.
    V2 is an ancestor of V3 1 levels up.
    3 and 4 are in the neighborhood of target 4
    Node 3 is a parent of 4 and is in the same target neighborhood, while also being a descendant of 2
    Checking if 4 is an unmediated ancestor of 2
    Node 2 is not a descendant of 4
    Nodes are unconnected in estimated graph
    Nodes 2 and 5 don't share the same target neighborhood
    2 is in the neighborhood of target node 2
    5 is in the neighborhood of target node 4
    Looking at nodes 2 and 5
    Checking if 2 is an unmediated ancestor of 5
    Node 5 is not a descendant of 2
    Checking if 5 is an unmediated ancestor of 2
    Node 2 is not a descendant of 5
    Nodes are unconnected in estimated graph
    3 and 4 are in the neighborhood of target 4
    3 and 5 are in the neighborhood of target 4
    4 and 5 are in the neighborhood of target 4
    Edge between 0 and 2 appears in true graph but not in the estimated graph. FN=1
    Edge between 1 and 4 match. TP=1
    Edge between 2 and 3 appears in true graph but not in the estimated graph. FN=2
    Edge between 3 and 4 appears in true graph but not in the estimated graph. FN=3
    Edge between 4 and 5 appears in true graph but not in the estimated graph. FN=4
      lfci_skel_fp lfci_skel_fn lfci_skel_tp lfci_v_fn lfci_v_fp lfci_v_tp
    1            0            0            5         1         1         0
      lfci_pra_fn lfci_pra_fp lfci_pra_tp lfci_pra_potential lfci_ancestors_correct
    1           2           2           1                  2                      0
      lfci_ancestors_missing lfci_ancestors_fn_orient lfci_ancestors_reverse
    1                      0                        0                      0
      lfci_ancestors_fp_oriented lfci_ancestors_fp_connect lfci_overall_f1
    1                          1                         0       0.3333333
