#include <Rcpp.h>
#include <vector>
using namespace Rcpp;

/*
 * 
 * Define functions for the rules used in the FCI algorithm
 * Definitions:
 * 0: No edge
 * 1: -o
 * 2: -> (arrowhead)
 * 3: - (tail)
 * 
 * Note that a * represents a wild card that can represent either an open circle or an arrow
 * When we are considering the PC algorithm, for nodes i and j, if we have i -> j,
 * we regard G(i,j) = 1 and G(j,i) = 0. Therefore, in keeping with this convention, for FCI we will consider the arrowhead
 * information stored in G to be related to the arrowhead incident on the second node for the edge in consideration.
 * For example, if i o-> j is the edge in consideration, G(i,j)=2, since the arrow is incident on j, the second node
 * Similarly, G(j,i)=1, since the circle is incident on node i, which is the second node for the edge between node
 * j and node i.
 */

/*
 * FUTURE DEVELOPMENT:
 * - don't check anything if all values are 0
 * 
 */

/*
 * For R1, we search for alpha *-> beta o-* gamma. 
 * If alpha and gamma are not adjacent, then orient the triple: alpha *-> beta -> gamma
 */

void rule1search(NumericMatrix &G, int beta,int alpha){
  int p = G.nrow();
  // Search for beta o-* gamma (beta (1) (!=0) gamma)
  for (int gamma=0;gamma<p;++gamma){
    if (G(gamma,beta)==1 && G(beta,gamma)!= 0){ 
      if (G(alpha,gamma)==0 & G(gamma,alpha)==0){
        if (G(beta,gamma)==3){
          Rcout << "Contradiction in Rule 1!\n";
        }
        G(beta,gamma) = 2; // arrowhead incident on gamma for edge connecting beta and gamma
        G(gamma,beta) = 3; // regular anchor incident on gamma for edge connecting beta and gamma
        Rcout << "Rule 1:\n";
        Rcout << "Orient: " << alpha << " *-> " << beta << " o-* " << gamma;
        Rcout << " as " << beta << " -> " << gamma << "\n";
      }
    }
  }
}

List rule1(NumericMatrix &G) {
  int p = G.nrow(); // Square matrix
  int gamma;
  // Outer loops: Go through every node to find an asterisk. The node it is incident on is alpha
  // The connected node is beta, which must have an arrowhead pointing into it.
  for (int alpha = 0;alpha<p;++alpha){
    for (int beta = 0;beta<p;++beta){
      if (G(alpha,beta)==2 && G(beta,alpha)!=0){ // alpha *-> beta
        rule1search(G,beta,alpha);
      }
    }
  }
  return List::create(
    _["G"] = G
  );
}

/*
 * 
 * Rule 2: Search for alpha -> beta *-> gamma (alpha (3) (2) beta (*) (2) gamma)
 * OR Search for alpha *-> beta -> gamma (alpha (*) (2) beta (3) (2) gamma)
 * For either case, if alpha *-o gamma, then orient alpha *-o gamma as alpha *-> gamma
 * 
 */

void rule2search(NumericMatrix &G, int beta,int alpha,bool condition1,bool condition2){
  int p = G.nrow();
  
  // Condition 1 refers to alpha -> beta *-> gamma
  if (condition1){
    for (int gamma=0;gamma<p;++gamma){
      if (G(gamma,beta)!=0 && G(beta,gamma)==2){ // beta *-> gamma
        if (G(alpha,gamma)==1 && G(gamma,alpha)!=0){ // alpha *-o gamma
          G(alpha,gamma) = 2; // alpha *-> gamma
          Rcout << "Rule 2:\n";
          Rcout << "Orient: " << alpha << " -> " << beta << " *-> " << gamma;
          Rcout << " as: " << alpha << " *-> " << gamma << std::endl;
        }
      }
    }
  } else if (condition2){ // Condition 2 refers to alpha *-> beta -> gamma
    for (int gamma=0;gamma<p;++gamma){
      if (G(gamma,beta)==3 & G(beta,gamma)==2){ // beta -> gamma
        if (G(alpha,gamma)==1 & G(gamma,alpha)!=0){ // alpha *-o gamma
          G(alpha,gamma) = 2; // alpha *-> gamma
          Rcout << "Rule 2:\n";
          Rcout << "Orient: " << alpha << " *-> " << beta << " -> " << gamma;
          Rcout << " as: " << alpha << " *-> " << gamma << std::endl;
        }
      }
    }
  } else {
    Rcout << "Both essential conditions for Rule 2 failed. This function was called incorrectly.\n";
  }
  

}

List rule2(NumericMatrix &G) {
  int p = G.nrow(); // Square matrix
  int gamma;
  bool condition1;
  bool condition2;
  // Searching for alpha -> beta OR alpha *-> beta
  for (int alpha = 0;alpha<p;++alpha){
    for (int beta = 0;beta<p;++beta){
      condition1 = (G(alpha,beta)==2) & (G(beta,alpha)==3); // alpha -> beta
      condition2 = (G(alpha,beta)==2) & (G(beta,alpha)!=0); // alpha *-> beta
      if (condition1 | condition2){
        rule2search(G,beta,alpha,condition1,condition2);
      }
    }
  }
  return List::create(
    _["G"] = G
  );
}


/*
 * 
 * Rule 3: Search for alpha *-> beta <-* gamma (alpha (*) (2) beta (2) (*) gamma)
 * AND alpha *-o theta o-* gamma (alpha (*) (1) theta (1) (*) gamma)
 * If alpha and gamma are not adjacent and theta *-o beta, then orient theta *-o beta as theta *-> beta
 * 
 */

List rule3asearch(NumericMatrix &G, int beta,int alpha){
  int p = G.nrow();
  NumericVector gammafinal; // There may be multiple values of gamma for which this holds. This assures we get them all.
  bool success = false;
  
  for (int gamma=0;gamma<p;++gamma){
    // Search for beta <-* gamma
    if (G(gamma,beta)==2 && G(beta,gamma)!=0 && gamma!= alpha){
      gammafinal.push_back(gamma);
      if (!success){
        success = true;
      }
    }
  }
  
  return List::create(
    _["gamma"] = gammafinal,
    _["rule3success"] = success
  );
}

void rule3bsearch(NumericMatrix &G,const int &alpha,const int &beta,const int &gamma){
  int p = G.ncol();
  bool condition1;
  bool condition2;
  // We are searching for alpha (*) (1) theta (1) (*) gamma
  for (int theta = 0;theta<p;++theta){
    condition1 = G(alpha,theta)==1 & G(theta,alpha)!=0; // alpha *-o theta
    condition2 = G(theta,gamma)!=0 & G(gamma,theta)==1; // theta o-* gamma
    if (condition1 && condition2){
      if (G(alpha,gamma)==0 && G(gamma,alpha)==0){ // alpha and gamma are not adjacent
        if (G(theta,beta)==1 && G(beta,theta)!=0){ // theta *-o beta
          G(theta,beta) = 2; // theta *-> beta
          Rcout << "Rule 3:\n";
          Rcout << "Orient: " << theta << " *-> " << beta << std::endl;
        }
      }
    }
  }
}

List rule3(NumericMatrix &G) {
  int p = G.nrow(); // Square matrix
  int gamma;
  List searchResults;
  NumericVector gammaVals;
  bool condition1;
  bool condition2;
  // (alpha (*) (2) beta (2) (*) gamma)
  for (int alpha = 0;alpha<p;++alpha){
    for (int beta = 0;beta<p;++beta){
      if (G(alpha,beta)==2 & G(beta,alpha)!=0){ // alpha *-> beta <-* gamma
        searchResults = rule3asearch(G,beta,alpha); // Search for gamma
        if (searchResults["rule3success"]){
          // Iterate over all values of gamma to find values of theta
          gammaVals = searchResults["gamma"];
          for (NumericVector::iterator it = gammaVals.begin();it != gammaVals.end();++it){
            gamma = *it;
            rule3bsearch(G,alpha,beta,gamma);
          }
        }
      }
    }
  }
  return List::create(
    _["G"] = G
  );
}


/*
 * Minimum Discriminating Path
 * Purpose: find a minimal discriminating path for a,b,c.
 */

NumericVector get_d_vals(NumericMatrix &pag,int &a,LogicalVector &visited){
  int p = pag.nrow();
  NumericVector d_vals;
  for (int i=0;i<p;++i){
    // We need d *-> a
    if (pag(a,i)!=0 && pag(i,a)==2 && !visited(i)){
      d_vals.push_back(i);
    }
  }
  return d_vals;
}

NumericVector get_r_vals(NumericMatrix &pag,int d,LogicalVector &visited){
  int p = pag.nrow();
  NumericVector r_vals;
  for (int i=0;i<p;++i){
    // We need r *-> d
    if (pag(d,i)!=0 && pag(i,d)==2 && !visited(i)){
      r_vals.push_back(i);  
    }
  }
  return r_vals;
}

List createPathList(int a,NumericVector set){
  int num_paths = set.length();
  NumericVector path = {0};
  path[0] = a;
  List paths_to_try(num_paths);
  
  NumericVector new_path;
  
  for (int i = 0;i<num_paths;++i){
    paths_to_try[i] = clone(path);
    new_path = paths_to_try[i];
    new_path.push_back(set(i));
  }
  
  return paths_to_try;
}

List updatePathList(NumericVector mpath,NumericVector &set,List &old_paths){
  int old_size = old_paths.length();
  int num_paths = set.length();
  //mpath.erase(0); // we don't need to go over this point again
  List new_paths(old_size+num_paths);
  
  NumericVector new_path;
  
  for (int i=0;i<old_size+num_paths;++i){
    if (i < old_size){
      new_paths[i] = old_paths[i];  
    } else {
      new_paths[i] = clone(mpath);
      new_path = new_paths[i];
      new_path.push_back(set(i-old_size));
    }
  }
  return new_paths;
}

NumericVector minDiscPath(NumericMatrix pag, int a,int b,int c){
  int p = pag.nrow();
  LogicalVector visited(p);
  visited(a) = true;
  visited(b) = true;
  visited(c) = true;
  
  NumericVector d_vals = get_d_vals(pag,a,visited);
  if (d_vals.length()>0){
    List path_list = createPathList(a,d_vals);
    int list_length = path_list.length();
    int counter = 0;
    NumericVector mpath;
    int m;
    int d;
    int pred;
    while (counter < list_length){
      mpath = path_list[counter];
      m = mpath.length();
      d = mpath(m-1);
      if (pag(c,d)==0 && pag(d,c)==0){
        NumericVector minDiscPath;
        for (int i=m-1;i>=0;--i){
          minDiscPath.push_back(mpath(i));
        }
        minDiscPath.push_back(b);
        minDiscPath.push_back(c);
        return minDiscPath;
      } // End If
      pred = mpath(m-2);
      ++counter;
      
      // d is connected to c, so we search iteratively
      if (pag(d,c)==2 && pag(c,d)==3 && pag(pred,d)==2){
        visited(d) = true;
        // Find all neighbors of d not visited yet
        NumericVector r_vals = get_r_vals(pag,d,visited);
        if (r_vals.length()>0){
            path_list = updatePathList(mpath,r_vals,path_list);
        }
      }
    }
  }
  return NA_REAL;
}

bool check_inclusion(int val,NumericVector set){
  int n_s = set.length();
  for (int i=0;i<n_s;++i){
    if (val == set(i)){
      return true;
    }
  }
  return false;
}

bool check_sep_r4(int beta,NumericVector md_path,List sepsets){
  int n = md_path.length();
  String theta = String((char) md_path(0));
  String gamma = String((char) n);
  List tmp1 = sepsets[theta];
  List tmp2 = sepsets[gamma];
  NumericVector set = tmp1[gamma];
  bool cond1 = check_inclusion(beta,set);
  set = tmp2[theta];
  bool cond2 = check_inclusion(beta,set);
  return (cond1 && cond2);
}

/*
 * Rule 4: If we have a discriminating path between theta and gamma for beta,
 * <theta,...,alpha,beta,gamma>
 * and beta o-* gamma; then if beta is in the separating set for theta and gamma
 * then we orient beta -> gamma; otherwise orient (alpha,beta,gamma) as 
 * alpha <-> beta <-> gamma
 * 
 */
void rule4(NumericMatrix &G,List sepsets){
  int p = G.nrow();
  bool cond1;
  bool cond2;
  bool done;
  NumericVector md_path;
  for (int beta=0;beta<p;++beta){
    for (int gamma=0;gamma<p;++gamma){
      if (G(beta,gamma)!=0 && G(gamma,beta)==1){
        for (int alpha=0;alpha<p;++alpha){
          cond1 = G(beta,alpha)==2 && G(alpha,beta)!=0;
          cond2 = G(gamma,alpha)==3 && G(alpha,gamma)==2; // triangle structure exists but is not oriented
          if (cond1 && cond2){
            done = false;
            while(G(gamma,beta)==1){
                while(!done && G(alpha,beta)!=0 && G(alpha,gamma)!=0 && G(beta,gamma)!=0){
                  md_path = minDiscPath(G,alpha,beta,gamma);
                  if (NumericVector::is_na(md_path(0))){
                    done = true; // We are done with this triangle  
                  } else {
                    if(check_sep_r4(beta,md_path,sepsets)){
                      Rcout << "\nRule4\nThere is a discriminating path between";
                      Rcout << md_path(0) << " and " << gamma << " for " << beta;
                      Rcout << " and " << beta << " is in the SepSet of " << gamma;
                      Rcout << " and " << md_path(0) << ". Orient: ";
                      Rcout << beta << " -> " << gamma << std::endl;
                      G(beta,gamma) = 2;
                      G(gamma,beta) = 3;
                    } else {
                      // b is not in sepset
                      Rcout << "\nRule4\nThere is a discriminating path between";
                      Rcout << md_path(0) << " and " << gamma << " for " << beta;
                      Rcout << " and " << beta << " is NOT in the SepSet of ";
                      Rcout << gamma << " and " << md_path(0) << ". Orient: ";
                      Rcout << alpha << " <-> " << beta << " <-> " << gamma << std::endl;
                      G(beta,gamma)=2;
                      G(gamma,beta)=2;
                      if (G(alpha,beta)==3){
                        Rcout << "\nContradiction in Rule 4b\n";  
                      }
                      G(alpha,beta) = 2;
                    }
                    done = true;
                  }
                }
            } 
          }  
        }
      }
    }  
  }
}


