\name{localfci_cpp}
\alias{localfci_cpp}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
This is the wrapper function for running the local FCI algorithm on a set of target nodes
}
\description{
Runs the local FCI algorithm on a set of target nodes for a set significance level using observational data
}
\usage{
localfci_cpp(data = NULL, true_dag = NULL, targets, lmax = 3, tol = 0.05, verbose = TRUE)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{data}{
%%     ~~Describe \code{data} here~~
}
  \item{true_dag}{
The adjacency matrix of the true DAG. Used to obtain the neighbors of nodes of interest
}
  \item{targets}{
The target nodes being considered in the algorithm
}
  \item{lmax}{
The largest possible size of a separating set
}
  \item{tol}{
The significance level of the conditional independence tests
}
  \item{mb_tol}{
The significance level for the Markov Blanket recovery algorithm  
}
  \item{verbose}{
Determines whether or not there is printed output. Usually used for debugging purposes.
}
}
\details{
%%  ~~ If necessary, more details than the description above ~~
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

## The function is currently defined as
function (data = NULL, true_dag = NULL, targets, lmax = 3, tol = 0.05, 
    verbose = TRUE) 
{
    node_names <- colnames(true_dag)
    if (is.data.frame(data)) {
        data <- as.matrix(data)
    }
    if (is.data.frame(true_dag)) {
        true_dag <- as.matrix(true_dag)
    }
    return(fci(true_dag, data, targets - 1, node_names, lmax, 
        tol, verbose))
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }% use one of  RShowDoc("KEYWORDS")
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
