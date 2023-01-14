# Testing Parent Recovery Accuracy Metrics

    t: 2 | i: 0 | Est. Graph: Not a parent | True graph: Parent | Missing: 1
    t: 2 | i: 1 | Est. Graph: Parent | True graph: Not a parent | Added: 1
    t: 2 | i: 3 | Est. Graph: Parent | True graph: Not a parent | Added: 2
    t: 2 | i: 4
    t: 2 | i: 5
    t: 4 | i: 0
    t: 4 | i: 1 | Est. Graph: Parent | True graph: Parent | Correct: 1
    t: 4 | i: 2
    t: 4 | i: 3 | Undirected edge in Est. Graph | Potential: 1
    t: 4 | i: 5 | Est. Graph: Parent | True graph: Not a parent | Undirected edge in True Graph | Added: 3
    $missing
    [1] 1
    
    $added
    [1] 3
    
    $correct
    [1] 1
    
    $potential
    [1] 1
    

---

      lfci__skel_fp lfci__skel_fn lfci__skel_tp lfci__v_fn lfci__v_fp lfci__v_tp
    1             1             0             5          1          2          0
      lfci_pra_fn lfci_pra_fp lfci_pra_tp lfci_pra_potential lfci_ancestors_correct
    1           1           3           1                  1                      0
      lfci_ancestors_incorrect lfci_ancestors_total lfci_overall_f1
    1                        0                    0       0.3333333

