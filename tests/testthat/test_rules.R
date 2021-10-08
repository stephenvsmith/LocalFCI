library(testthat)
library(bnlearn)

test_that("Rule 1 is correct.",{
  cat("\n")
  nodes <- c("a","b","alpha","beta","gamma")
  track_changes <- FALSE
  adj.mat1 <- matrix(c(0,1,1,0,0,
                       1,0,0,2,0,
                       1,0,0,2,0,
                       0,3,1,0,1,
                       0,0,0,1,0),nrow = 5,byrow = TRUE)
  adj.mat1orig <- matrix(c(0,1,1,0,0,
                           1,0,0,2,0,
                           1,0,0,2,0,
                           0,3,1,0,1,
                           0,0,0,1,0),nrow = 5,byrow = TRUE)
  track_changes <- rule1(adj.mat1,track_changes,FALSE)
  expect_equal(adj.mat1[4,5],2)
  expect_equal(adj.mat1[5,4],3)
  expect_true(track_changes)
  for (i in 1:nrow(adj.mat1)){
    for (j in 1:ncol(adj.mat1)){
      cond1 <- i==4 & j==5
      cond2 <- i==5 & j==4
      if (!(cond1 | cond2)){
        expect_equal(adj.mat1orig[i,j],adj.mat1[i,j])
      }
    }
  }
})

test_that("Rule 2 is correct.",{
  adj.mat2 <- matrix(c(0,2,1,1,0,0,
                       1,0,2,0,0,0,
                       1,3,0,0,0,0,
                       1,0,0,0,2,1,
                       0,0,0,3,0,2,
                       0,0,0,1,1,0),nrow = 6,byrow = TRUE)
  adj.mat2orig <- matrix(c(0,2,1,1,0,0,
                           1,0,2,0,0,0,
                           1,3,0,0,0,0,
                           1,0,0,0,2,1,
                           0,0,0,3,0,2,
                           0,0,0,1,1,0),nrow = 6,byrow = TRUE)
  track_changes <- FALSE
  track_changes <- rule2(adj.mat2,track_changes,FALSE)
  expect_equal(adj.mat2[1,3],2)
  expect_equal(adj.mat2[4,6],2)
  expect_true(track_changes)
  for (i in 1:nrow(adj.mat2)){
    for (j in 1:ncol(adj.mat2)){
      cond1 <- i==1 & j==3
      cond2 <- i==4 & j==6
      if (!(cond1 | cond2)){
        expect_equal(adj.mat2[i,j],adj.mat2orig[i,j])
      }
    }
  }
})

test_that("Rule 3 is correct.",{
  adj.mat3 <- matrix(c(0,2,2,1,0,0,1,
                       1,0,0,0,0,1,0,
                       3,0,0,0,0,0,0,
                       1,0,0,0,2,0,1,
                       0,0,0,1,0,1,1,
                       0,1,0,0,2,0,1,
                       1,0,0,1,1,1,0),nrow = 7,byrow = TRUE)
  adj.mat3orig <- matrix(c(0,2,2,1,0,0,1,
                           1,0,0,0,0,1,0,
                           3,0,0,0,0,0,0,
                           1,0,0,0,2,0,1,
                           0,0,0,1,0,1,1,
                           0,1,0,0,2,0,1,
                           1,0,0,1,1,1,0),nrow = 7,byrow = TRUE)
  track_changes <- FALSE
  track_changes <- rule3(adj.mat3,track_changes,FALSE)
  expect_equal(adj.mat3[7,5],2)
  expect_true(track_changes)
  for (i in 1:nrow(adj.mat3)){
    for (j in 1:ncol(adj.mat3)){
      cond1 <- i==7 & j==5
      if (!cond1){
        expect_equal(adj.mat3[i,j],adj.mat3orig[i,j])
      }
    }
  } 
})

# Need to finish this one
test_that("Rule 4 is correct.",{
  adj.mat4 <- matrix(c(0,2,1,0,0,2,3,
                       2,0,0,2,0,2,0,
                       3,0,0,0,3,0,1,
                       0,2,0,0,2,2,0,
                       0,0,2,2,0,1,0,
                       3,3,0,3,1,0,0,
                       2,0,1,0,0,0,0),nrow = 7,byrow = TRUE)
  adj.mat4orig <- matrix(c(0,2,1,0,0,2,3,
                       2,0,0,2,0,2,0,
                       3,0,0,0,3,0,1,
                       0,2,0,0,2,2,0,
                       0,0,2,2,0,1,0,
                       3,3,0,3,1,0,0,
                       2,0,1,0,0,0,0),nrow = 7,byrow = TRUE)
  track_changes <- FALSE
  S <- create_conditioning_sets_efficient_cpp2(seq(0,6))
  nodes <- c("a","b","c","alpha","beta","gamma","theta")
  S[["6"]][["5"]] <- 4
  S[["5"]][["6"]] <- 4
  
  track_changes <- rule4(adj.mat4,S,seq(0,6),track_changes,FALSE)
  expect_equal(adj.mat4[5,6],2)
  expect_equal(adj.mat4[6,5],3)
  expect_true(track_changes)
  
  for (i in 1:nrow(adj.mat4)){
    for (j in 1:ncol(adj.mat4)){
      cond1 <- (i==5 & j==6) | (i==6 & j==5)
      if (!cond1){
        expect_equal(adj.mat4[i,j],adj.mat4orig[i,j])
      }
    }
  } 
})

test_that("Rule 8 is correct.",{
  adj.mat8 <- matrix(c(0,1,0,0,0,2,0,
                       3,0,2,0,0,2,0,
                       0,3,0,0,0,0,0,
                       0,0,0,0,2,2,0,
                       0,0,0,3,0,2,1,
                       1,3,0,1,3,0,0,
                       0,1,0,0,0,0,0),nrow = 7,byrow = TRUE)
  adj.mat8orig <- matrix(c(0,1,0,0,0,2,0,
                       3,0,2,0,0,2,0,
                       0,3,0,0,0,0,0,
                       0,0,0,0,2,2,0,
                       0,0,0,3,0,2,1,
                       1,3,0,1,3,0,0,
                       0,1,0,0,0,0,0),nrow = 7,byrow = TRUE)
  track_changes <- FALSE
  track_changes <- rule8(adj.mat8,track_changes,FALSE)
  
  expect_true(track_changes)
  expect_equal(adj.mat8[6,1],3)
  expect_equal(adj.mat8[1,6],2)
  expect_equal(adj.mat8[6,4],3)
  expect_equal(adj.mat8[4,6],2)
  for (i in 1:nrow(adj.mat8)){
    for (j in 1:ncol(adj.mat8)){
      cond1 <- (i==6 & j==1) | (i==6 & j==4)
      if (!cond1){
        expect_equal(adj.mat8[i,j],adj.mat8orig[i,j])
      }
    }
  }
  
  
})

test_that("Rule 9 is correct.",{
  adj.mat9 <- matrix(c(0,1,0,0,0,0,0,3,
                       1,0,1,0,0,0,0,0,
                       0,1,0,0,0,0,1,0,
                       0,0,0,0,1,0,0,0,
                       0,0,0,1,0,1,2,0,
                       0,0,0,0,1,0,0,2,
                       0,0,1,0,1,0,0,0,
                       2,0,0,0,0,1,0,0),nrow = 8,byrow = TRUE)
  adj.mat9orig <- matrix(c(0,1,0,0,0,0,0,3,
                       1,0,1,0,0,0,0,0,
                       0,1,0,0,0,0,1,0,
                       0,0,0,0,1,0,0,0,
                       0,0,0,1,0,1,2,0,
                       0,0,0,0,1,0,0,2,
                       0,0,1,0,1,0,0,0,
                       2,0,0,0,0,1,0,0),nrow = 8,byrow = TRUE)
  track_changes <- FALSE

  track_changes <- rule9(adj.mat9,track_changes,FALSE)
  expect_true(track_changes)
  expect_equal(adj.mat9[5,7],2)
  expect_equal(adj.mat9[7,5],3)
  
  for (i in 1:nrow(adj.mat9)){
    for (j in 1:ncol(adj.mat9)){
      cond1 <- i==7 & j==5
      if (!cond1){
        expect_equal(adj.mat9[i,j],adj.mat9orig[i,j])
      }
    }
  }
})

test_that("Rule 10 is correct.",{
  adj.mat10 <- matrix(c(0,0,0,2,0,0,1,0,
                        0,0,0,0,0,1,0,1,
                        0,0,0,0,2,0,2,1,
                        1,0,0,0,2,0,0,0,
                        0,0,1,3,0,3,0,0,
                        0,1,0,0,2,0,0,0,
                        1,0,3,0,0,0,0,0,
                        0,2,1,0,0,0,0,0),nrow = 8,byrow = TRUE)
  adj.mat10orig <- matrix(c(0,0,0,2,0,0,1,0,
                        0,0,0,0,0,1,0,1,
                        0,0,0,0,2,0,2,1,
                        1,0,0,0,2,0,0,0,
                        0,0,1,3,0,3,0,0,
                        0,1,0,0,2,0,0,0,
                        1,0,3,0,0,0,0,0,
                        0,2,1,0,0,0,0,0),nrow = 8,byrow = TRUE)
  track_changes <- FALSE
  track_changes <- rule10(adj.mat10,track_changes,FALSE)
  expect_true(track_changes)
  expect_equal(adj.mat10[3,5],2)
  expect_equal(adj.mat10[5,3],3)
  for (i in 1:nrow(adj.mat10)){
    for (j in 1:ncol(adj.mat10)){
      cond1 <- (i==5 & j==3)
      if (!cond1){
        expect_equal(adj.mat10[i,j],adj.mat10orig[i,j])
      }
    }
  }
})

# test_that("All Rules Function is correct",{
#   adj.mat4 <- matrix(c(0,2,1,0,0,2,3,
#                        2,0,0,2,0,2,0,
#                        3,0,0,0,3,0,1,
#                        0,2,0,0,2,2,0,
#                        0,0,2,2,0,1,0,
#                        3,3,0,3,1,0,0,
#                        2,0,1,0,0,0,0),nrow = 7,byrow = TRUE)
#   adj.mat4orig <- matrix(c(0,2,1,0,0,2,3,
#                            2,0,0,2,0,2,0,
#                            3,0,0,0,3,0,1,
#                            0,2,0,0,2,2,0,
#                            0,0,2,2,0,1,0,
#                            3,3,0,3,1,0,0,
#                            2,0,1,0,0,0,0),nrow = 7,byrow = TRUE)
#   track_changes <- FALSE
#   S <- create_conditioning_sets_efficient_cpp2(seq(0,6))
#   nodes <- c("a","b","c","alpha","beta","gamma","theta")
#   S[["6"]][["5"]] <- 4
#   S[["5"]][["6"]] <- 4
#   
#   allRules(adj.mat4,sepsets = S)
# })


