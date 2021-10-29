\name{get_skeleton_total}
\alias{get_skeleton_total}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Skeleton Recovery Algorithm (Part I)
}
\description{
This function implements the first of the two-part skeleton recovery algorithm. We consider a complete graph on all the target nodes and their neighbors. From there, we remove edges based on conditional independence tests.
}
\usage{
get_skeleton_total(var_list, df, signif_level)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{var_list}{
Contains 
}
  \item{df}{
The input data to be used for independence tests
}
  \item{signif_level}{
The significance level for the conditional independence tests
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
function (var_list, df, signif_level) 
{
    .Call(`_LocalFCI_get_skeleton_total`, var_list, df, signif_level)
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ skeleton }% use one of  RShowDoc("KEYWORDS")
\keyword{ pc }% __ONLY ONE__ keyword per line
\keyword{ fci }% __ONLY ONE__ keyword per line
