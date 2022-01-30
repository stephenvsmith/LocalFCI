#ifndef RULESHELPERS_H
#define RULESHELPERS_H

#include "sharedFunctions.h"
#include "Graph.h"

NumericVector minDiscPath(Graph *pag, int a,int b,int c,bool verbose);

NumericVector minUncovPdPath(int p,Graph *G,int alpha,int beta,int gamma,bool verbose);

#endif