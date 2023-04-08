#include "LocalPC.h"

// [[Rcpp::export]]
int checkInitializeLocalPC(NumericMatrix td,arma::mat df,
                           NumericVector t,
                           NumericVector nodes_interest,
                           StringVector names){
  LocalPC lpc(td,df,t,nodes_interest,names,3,0.01,true);
  Rcout << lpc.getSize() << std::endl;
  return lpc.getSize();
}


// [[Rcpp::export]]
NumericMatrix checkGetTargetSkel(NumericMatrix td,arma::mat df,
                                 NumericVector t,
                                 NumericVector nodes_interest,StringVector names){
  LocalPC lpc(td,df,t,nodes_interest,names,3,0.01,true);
  lpc.getSkeletonTarget(t(0));
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkGetVStructures(NumericMatrix td,arma::mat df,
                                  NumericVector t,
                                  NumericVector nodes_interest,StringVector names){
  LocalPC lpc(td,df,t,nodes_interest,names,3,0.02,true);
  lpc.getSkeletonTarget(t(0));
  int rule_0_used = lpc.getVStructures();
  Rcout << "Rules Used (0) " << rule_0_used;
  return lpc.getAmat();
}

// [[Rcpp::export]]
int checkInitializeLocalPCPop(NumericMatrix td,NumericVector t,
                              NumericVector nodes_interest,StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  Rcout << lpc.getSize() << std::endl;
  return lpc.getSize();
}

// [[Rcpp::export]]
NumericMatrix checkGetTargetSkelPop(NumericMatrix td,
                                    NumericVector t,
                                    NumericVector nodes_interest,
                                    StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.getSkeletonTarget(t(0));
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkGetVStructuresPop(NumericMatrix td,
                                     NumericVector t,
                                     NumericVector nodes_interest,
                                     StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.getSkeletonTarget(t(0));
  int rule_0_used = lpc.getVStructures();
  Rcout << "Rules Used (0) " << rule_0_used;
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkRule1(NumericMatrix td,
                         NumericMatrix test_mat,
                         NumericVector t,
                         NumericVector nodes_interest,
                         StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.setAmat(test_mat);
  bool no_changes = true;
  lpc.rule1(no_changes);
  if (no_changes){
    Rcout << "There was no change\n";
  } else {
    Rcout << "There was a change\n";
  }
  Rcout << "Rules Used (1) " << lpc.getRulesUsed()(1);
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkRule2(NumericMatrix td,
                         NumericMatrix test_mat,
                         NumericVector t,
                         NumericVector nodes_interest,
                         StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.setAmat(test_mat);
  bool no_changes = true;
  lpc.rule2(no_changes);
  if (no_changes){
    Rcout << "There was no change\n";
  } else {
    Rcout << "There was a change\n";
  }
  Rcout << "Rules Used (2) " << lpc.getRulesUsed()(2);
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkRule3(NumericMatrix td,
                         NumericMatrix test_mat,
                         NumericVector t,
                         NumericVector nodes_interest,
                         StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.setAmat(test_mat);
  bool no_changes = true;
  lpc.rule3(no_changes);
  if (no_changes){
    Rcout << "There was no change\n";
  } else {
    Rcout << "There was a change\n";
  }
  Rcout << "Rules Used (3) " << lpc.getRulesUsed()(3);
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkRule4(NumericMatrix td,
                         NumericMatrix test_mat,
                         NumericVector t,
                         NumericVector nodes_interest,
                         StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.setAmat(test_mat);
  bool no_changes = true;
  lpc.rule4(no_changes);
  if (no_changes){
    Rcout << "There was no change\n";
  } else {
    Rcout << "There was a change\n";
  }
  Rcout << "Rules Used (4) " << lpc.getRulesUsed()(4);
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLPCRules(NumericMatrix td,
                            NumericMatrix test_mat,
                            NumericVector t,
                            NumericVector nodes_interest,
                            StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  lpc.setAmat(test_mat);
  lpc.meeksRules();
  NumericVector num_used = lpc.getRulesUsed();
  int i=0;
  std::for_each(num_used.begin(),num_used.end(),[&i](int num){ Rcout << "Rule " << i++ << ": " << num << std::endl;});
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLocalPC(NumericMatrix td,arma::mat df,
                           NumericVector t,
                           NumericVector nodes_interest,StringVector names){
  LocalPC lpc(td,df,t,nodes_interest,names,3,0.01,true);
  Rcout << "\n\n";
  // Get the skeleton for each target node and its neighborhood
  std::for_each(t.begin(),t.end(),[&lpc](int t){ lpc.getSkeletonTarget(t); });
  lpc.getVStructures();
  lpc.convertFinalGraph();
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLocalPCRun(NumericMatrix td,arma::mat df,
                              NumericVector t,
                              NumericVector nodes_interest,StringVector names){
  LocalPC lpc(td,df,t,nodes_interest,names,3,0.01,true);
  lpc.run();
  NumericVector num_used = lpc.getRulesUsed();
  int i=0;
  std::for_each(num_used.begin(),num_used.end(),[&i](int num){ Rcout << "Rule " << i++ << ": " << num << std::endl;});
  return lpc.getAmat();
}

// [[Rcpp::export]]
NumericMatrix checkLocalPCPop(NumericMatrix td,
                              NumericVector t,
                              NumericVector nodes_interest,
                              StringVector names){
  LocalPC lpc(td,t,nodes_interest,names,3,true);
  std::for_each(t.begin(),t.end(),[&lpc](int t){ lpc.getSkeletonTarget(t); });
  lpc.getVStructures();
  lpc.convertFinalGraph();
  return lpc.getAmat();
}
