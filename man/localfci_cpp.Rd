\name{localfci_cpp}
\alias{localfci_cpp}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Local FCI
}
\description{
Runs the local FCI algorithm on a set of target nodes for a set significance level using observational data. Markov Blankets are also estimated according to user-specifications
}
\usage{
localfci_cpp(data,true_dag,targets,node_names,lmax,tol,mb_tol,method,test,verbose)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{data}{
The sample data used for inferring conditional independence relationships. The data may be a dataframe object or a matrix object, but it will be converted to a matrix in the data.
}
  \item{true_dag}{
The adjacency matrix of the true DAG. Used to obtain the neighbors of nodes of interest.
}
  \item{targets}{
The target nodes being considered in the algorithm
}
  \item{node_names}{
A vector of strings providing the names of the nodes in the network.
}
  \item{lmax}{
The largest possible size of a separating set
}
  \item{tol}{
The significance level of the conditional independence tests. The default is 0.01.
}
  \item{mb_tol}{
The significance level used in the Markov Blanket recovery algorithm. The default is 0.05
}
  \item{method}{
The algorithm used for Markov Blanket recovery, if the true DAG is not provided. Default is MMPC.
}
  \item{test}{
The test used for the Markov Blanket Recovery algorithm. Default is Fisher's Independent Test. 
}
  \item{verbose}{
Determines whether or not there is printed output. Usually used for debugging purposes. Default is TRUE.
}
}
\details{
%%  ~~ If necessary, more details than the description above ~~
}
\value{
\item{amat}{The estimated adjacency matrix returned by the algorithm}
\item{S}{The separating sets determined by the algorithm}
\item{NumTests}{The number of conditional independence tests conducted by the algorithm}
\item{Nodes}{All of the nodes considered in the algorithm}
\item{totalSkeletonTime}{The time it took for the algorithm's total skeleton recovery subroutine}
\item{targetSkeletonTimes}{A vector of the time taken for each target skeleton recovery subroutine}
\item{totalTime}{The total time taken for the underlying C++ function to complete the algorithm. Does not include the time taken in the R function.}
\item{referenceDAG}{Either the true DAG inputted in the function, or the estimated Markov Blankets returned as an adjacency matrix}
\item{mbList}{A list of the Markov Blankets for the nodes and their first-order neighbors}
\item{data_means}{A vector of sample means from the data, returned for each node prior to normalization}
\item{data_cov}{A sample variance-covariance matrix of the inputted data, prior to normalization}
}
\references{
%% ~put references to the literature/web site here ~
}
\author{
Stephen Smith
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
##---- Should be DIRECTLY executable !! ----
##-- ==>  Define data, use random,
##--	or do  help(data=index)  for the standard data sets.

}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
