#include "lpc.h"

void separateNeighborhoods(DAG* true_DAG,Graph* C_tilde,NumericVector &targets,std::map<int,int> &node_numbering,const int &N,bool verbose){
  NumericVector nbhd_t;
  NumericVector nbhd_t_efficient;
  int j;
  for (NumericVector::iterator it=targets.begin();it<targets.end();++it){
    nbhd_t = true_DAG -> getNeighbors(*it,verbose);
    nbhd_t.push_back(*it);
    for (int i=0;i<N;++i){
      j = node_numbering.find(*it)->second; // Obtain the true value
      if (!(true_DAG -> areNeighbors(*it,j))){
        // Remove edges between Ne(target) and j
        for (NumericVector::iterator it2=nbhd_t.begin();it2<nbhd_t.end();++i){
          C_tilde -> setAmatVal(*it2,j,0);
          C_tilde -> setAmatVal(j,*it2,0);
        }
      }
      
    }
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
  separateNeighborhoods(true_DAG,C_tilde,targets,node_numbering,N,verbose);
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
  separateNeighborhoods(true_DAG,C_tilde,targets,node_numbering,N,verbose);
}

void LocalPC::check(){
  Rcout << getSize() << std::endl;
}











