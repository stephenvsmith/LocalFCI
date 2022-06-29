#include "lpc.h"

void fillTargetNeighborhood(Graph* C_tilde,
                            std::map<int,int> node_numbering,
                            NumericVector nbhd_t){
  int i_eff; int j_eff;
  for (auto it=nbhd_t.begin();it<nbhd_t.end()-1;++it){
    i_eff = node_numbering.find(*it)->second;
    auto it2 = it+1;
    for (;it2<nbhd_t.end();++it2){
      j_eff = node_numbering.find(*it2)->second;
      C_tilde -> setAmatVal(i_eff,j_eff,1);
      C_tilde -> setAmatVal(j_eff,i_eff,1);
    }
  }
}

void createInitialAmat(DAG* true_DAG,Graph* C_tilde,
                       std::map<int,int> node_numbering,
                           NumericVector &targets,
                           NumericVector &neighborhood,
                           const int &N,bool verbose){
  if (verbose){
    Rcout << "FUNCTION createInitialAmat\n";
  }
  
  C_tilde -> emptyGraph();
  
  NumericVector nbhd_t;
  int i; // tracks the current target (true number)
  int j; // tracks the current neighbor (true number)
  int i_eff; // tracks the current target (efficient number)
  int j_eff; // tracks the current neighbor (efficient number)
  // Loop through each of the targets
  for (auto it=targets.begin();it<targets.end();++it){
    // Find the target's neighbors
    if (verbose){
      Rcout << "Target: " << *it << std::endl;
    }
    nbhd_t = true_DAG -> getNeighbors(*it,verbose);
    nbhd_t.push_back(*it);
    // Fill the target neighborhood
    fillTargetNeighborhood(C_tilde,node_numbering,nbhd_t);
  }
}

LocalPC::LocalPC(NumericMatrix true_dag,arma::mat df,
                 NumericVector targets,
                 StringVector names,int lmax,
                 double signif_level,
                 bool verbose) : 
  ConstrainedAlgo(true_dag,df,targets,names,lmax,
                  signif_level,verbose){
  
  // Make a map to relate efficient numbering to true numbering
  // Map: true numbering -> efficient numbering
  for (int i=0;i<N;++i){
    node_numbering.insert(std::pair<int,int>(neighborhood(i),i));
  }
  if (verbose){
    Rcout << "Element mapping for efficient ordering:\n";
    for(auto it = node_numbering.cbegin(); it != node_numbering.cend(); ++it)
    {
      Rcout << it->first << " " << it->second  << "\n";
    }
  }
  
  // Separate elements not belonging to the same neighborhood
  if (targets.length() > 1) {
    createInitialAmat(true_DAG,C_tilde,node_numbering,targets,neighborhood,N,verbose);
  }
}

LocalPC::LocalPC(NumericMatrix true_dag,
                   NumericVector targets,
                   StringVector names,int lmax,
                   bool verbose) : 
  ConstrainedAlgo(true_dag,targets,names,
                  lmax,verbose){
  pop = true;
  
  // Make a map to relate efficient numbering to true numbering
  // Map: true numbering -> efficient numbering
  for (int i=0;i<N;++i){
    node_numbering.insert(std::pair<int,int>(neighborhood(i),i));
  }
  if (verbose){
    Rcout << "Element mapping for efficient ordering:\n";
    for(auto it = node_numbering.cbegin(); it != node_numbering.cend(); ++it)
    {
      Rcout << it->first << " " << it->second  << "\n";
    }
  }
  
  // Separate elements not belonging to the same neighborhood
  createInitialAmat(true_DAG,C_tilde,node_numbering,targets,neighborhood,N,verbose);
}

void LocalPC::check(){
  Rcout << getSize() << std::endl;
}

void LocalPC::getSkeletonTarget(int t){}









