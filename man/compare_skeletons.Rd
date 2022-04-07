\name{compare_skeletons}
\alias{compare_skeletons}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Compare the skeletons of two graphs
}
\description{
An estimated graph adjacency matrix is compared to a reference adjacency matrix to identify the structural commonalities and differences between the two. These comparisons are made with respect to the skeleton.
}
\usage{
compare_skeletons(est, truth, verbose)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{est}{
%%     ~~Describe \code{est} here~~
}
  \item{truth}{
%%     ~~Describe \code{truth} here~~
}
  \item{verbose}{
%%     ~~Describe \code{verbose} here~~
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
%%  ~~who you are~~
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
function (est, truth, verbose) 
{
    .Call(`_LocalFCI_compare_skeletons`, est, truth, verbose)
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory (show via RShowDoc("KEYWORDS")):
% \keyword{ ~kwd1 }
% \keyword{ ~kwd2 }
% Use only one keyword per line.
% For non-standard keywords, use \concept instead of \keyword:
% \concept{ ~cpt1 }
% \concept{ ~cpt2 }
% Use only one concept per line.
