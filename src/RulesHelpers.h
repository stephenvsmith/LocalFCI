#ifndef RULESHELPERS_H
#define RULESHELPERS_H

#include "sharedFunctions.h"

NumericVector minDiscPath(NumericMatrix pag, int a,int b,int c,bool verbose);
bool check_inclusion(int val,NumericVector set);

NumericVector minUncovPdPath(int p,NumericMatrix G,int alpha,int beta,int gamma,bool verbose);

#endif