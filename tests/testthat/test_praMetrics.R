true_amat <- matrix(c(
  0,0,1,0,0,0,
  0,0,0,0,1,0,
  0,0,0,1,0,0,
  0,0,0,0,1,0,
  0,0,0,0,0,1,
  0,0,0,0,1,0
),nrow = 6,byrow = TRUE)

est_amat <- matrix(c(
  0,0,0,0,0,0,
  0,0,1,0,1,0,
  1,0,0,0,0,0,
  0,0,1,0,1,0,
  0,0,0,1,0,0,
  0,0,0,0,1,0
),nrow = 6,byrow = TRUE)

parent_recovery_accuracy(est_amat,true_amat,c(2,4),TRUE)

all_metrics(est_amat,true_amat,est_amat,c(2,4),verbose = TRUE)
