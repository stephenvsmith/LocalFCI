\name{get_current_edges}
\alias{get_current_edges}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Obtain Connected Nodes in Current Graph
}
\description{
A function that returns all of the nodes that are connected to the target node in the current graph using the current adjacency matrix.
}
\usage{
get_current_edges(i, p, graph)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{i}{
The target node
}
  \item{p}{
The number of nodes in the graph
}
  \item{graph}{
The adjacency matrix of the graph
}
}
\details{
This function assumes that we are considering an undirected graph, so it will only check the row of the adjacency matrix corresponding to the target node number.
}
\value{
%%  ~Describe the value returned
%%  If it is a LIST, use
%%  \item{comp1 }{Description of 'comp1'}
%%  \item{comp2 }{Description of 'comp2'}
%% ...
}
\references{
%% ~put references to the literature/web site here ~
}
\author{
Stephen Smith
}
\note{
This function is tested in the file test_total_skeleton.R. In it, we use a random graph of size 20 and test the function by comparing its results to the adjacency matrix.
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
  set.seed(123)
  N <- 20
  adj.mat <- matrix(nrow = N,ncol = N)
  diag(adj.mat) <- 0
  for (i in 1:(N-1)){
    for (j in (i+1):N){
      adj.mat[i,j] <- sample(c(0,1),1,prob = c(0.3,0.7))
      adj.mat[j,i] <- adj.mat[i,j]
    }
  }
  # Node 1: 1  3  6  7  9 10 12 13 14 15 17 18 19
  get_current_edges(0,N,adj.mat) # Should return which(adj.mat[1,]==1)-1
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.

