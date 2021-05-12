data("asiadf")
a <- bnlearn::iamb(asiadf)
bnlearn::mb(a,"V1")
library(bnlearn)
graphviz.plot(a)
bnlearn::mb(a,"V6")

b <- bnlearn::hpc(asiadf,test = 'zf')
graphviz.plot(b)
mb(b,"V6")

