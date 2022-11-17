# Local FCI Package

[![codecov](https://codecov.io/gh/stephenvsmith/LocalFCI/branch/main/graph/badge.svg?token=0CBQROKQRK)](https://codecov.io/gh/stephenvsmith/LocalFCI)

`LocalFCI` is a R package for learning the local graphical structure of a causal DAG for specified target nodes. This package implements the local FCI and local PC algorithms, with the latter being the preferred method.

## Installation

    if (!require("devtools")) {
      install.packages("devtools") 
    } 
    devtools::install_github("stephenvsmith/LocalFCI")

## Simple Example

```
library(LocalFCI)
data("asiaDAG")
data("asiadf")
asiadf <- as.matrix(asiadf)

# Run the local FCI algorithm on targets 1 (asia) and 6 (either)
localfci(data = asiadf,targets = c(1,6),verbose = FALSE)
```