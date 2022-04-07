data("asiadf")
p <- ncol(asiadf)
# [1] 1 "asia"   2"tub"    3"smoke"  4"lung"   5"bronc"  6"either" 7"xray"   8"dysp"  

test_that("Neighborhood Estimation",{
  expect_equal(getMB(8,asiadf)$mb,c(5,6))
  
  targets <- c(3,5,6,8)
  mbList <- getAllMBs(targets,asiadf)
  lapply(mbList,function(mb){
    expect_snapshot_output(mb$mb)
  })
  
  adj <- getEstInitialDAG(mbList,p)
  for (i in 1:length(targets)){
    target <- targets[i]
    neighbors <- mbList[[i]][["mb"]]
    for (neighbor in neighbors){
      expect_equal(adj[target,neighbor]+adj[neighbor,target],1)
    }
  }
  
  times <- rep(NA,length(targets))
  for (i in 1:length(targets)){
    times[i] <- mbList[[i]][["time"]]
  }
  expect_equal(getTotalMBTime(mbList),sum(times),tolerance = 1e-02)
})