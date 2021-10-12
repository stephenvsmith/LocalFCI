#include "Rules.h"

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
 * we regard G(i,j) = 2 and G(j,i) = 3. Therefore, in keeping with this convention, for FCI we will consider the arrowhead
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

void rule1search(NumericMatrix &G, int beta,int alpha,bool &track_changes,bool verbose=false){
  int p = G.nrow();
  // Search for beta o-* gamma (beta (1) (!=0) gamma)
  for (int gamma=0;gamma<p;++gamma){
    if (G(gamma,beta)==1 && G(beta,gamma)!= 0){ 
      if (G(alpha,gamma)==0 & G(gamma,alpha)==0){
        if (G(beta,gamma)==3){
          Rcout << "Contradiction in Rule 1! " << "G(" << beta << "," << gamma << ")=3 when it must be changed to 2\n";
        }
        G(beta,gamma) = 2; // arrowhead incident on gamma for edge connecting beta and gamma
        G(gamma,beta) = 3; // regular anchor incident on gamma for edge connecting beta and gamma
        if (verbose){
          Rcout << "Rule 1:\n";
          Rcout << "Orient: " << alpha << " *-> " << beta << " o-* " << gamma;
          Rcout << " as " << beta << " -> " << gamma << "\n";
        }
        track_changes=true;
      }
    }
  }
}

// [[Rcpp::export]]
bool rule1(NumericMatrix &G,bool &track_changes,bool verbose=false) {
  int p = G.nrow(); // Square matrix
  //int gamma;
  // Outer loops: Go through every node to find an asterisk. The node it is incident on is alpha
  // The connected node is beta, which must have an arrowhead pointing into it.
  for (int alpha = 0;alpha<p;++alpha){
    for (int beta = 0;beta<p;++beta){
      if (G(alpha,beta)==2 && G(beta,alpha)!=0){ // alpha *-> beta
        rule1search(G,beta,alpha,track_changes,verbose);
      }
    }
  }
  return track_changes;
}

/*
 * 
 * Rule 2: Search for alpha -> beta *-> gamma (alpha (3) (2) beta (*) (2) gamma)
 * OR Search for alpha *-> beta -> gamma (alpha (*) (2) beta (3) (2) gamma)
 * For either case, if alpha *-o gamma, then orient alpha *-o gamma as alpha *-> gamma
 * 
 */

void rule2search(NumericMatrix &G, int beta,int alpha,bool condition1,bool condition2,bool &track_changes,bool verbose=false){
  int p = G.nrow();
  
  // Condition 1 refers to alpha -> beta *-> gamma
  if (condition1){
    for (int gamma=0;gamma<p;++gamma){
      if (G(gamma,beta)!=0 && G(beta,gamma)==2){ // beta *-> gamma
        if (G(alpha,gamma)==1 && G(gamma,alpha)!=0){ // alpha *-o gamma
          G(alpha,gamma) = 2; // alpha *-> gamma
          track_changes = true;
          if (verbose){
            Rcout << "Rule 2:\n";
            Rcout << "Orient: " << alpha << " -> " << beta << " *-> " << gamma;
            Rcout << " as: " << alpha << " *-> " << gamma << std::endl;
          }
        }
      }
    }
  } else if (condition2){ // Condition 2 refers to alpha *-> beta -> gamma
    for (int gamma=0;gamma<p;++gamma){
      if (G(gamma,beta)==3 & G(beta,gamma)==2){ // beta -> gamma
        if (G(alpha,gamma)==1 & G(gamma,alpha)!=0){ // alpha *-o gamma
          G(alpha,gamma) = 2; // alpha *-> gamma
          if (verbose){
            Rcout << "Rule 2:\n";
            Rcout << "Orient: " << alpha << " *-> " << beta << " -> " << gamma;
            Rcout << " as: " << alpha << " *-> " << gamma << std::endl;
          }
          track_changes = true;
        }
      }
    }
  } else {
    Rcout << "Both essential conditions for Rule 2 failed. This function was called incorrectly.\n";
  }
  
  
}

// [[Rcpp::export]]
bool rule2(NumericMatrix &G,bool &track_changes,bool verbose=false) {
  int p = G.nrow(); // Square matrix
  //int gamma;
  bool condition1;
  bool condition2;
  // Searching for alpha -> beta OR alpha *-> beta
  for (int alpha = 0;alpha<p;++alpha){
    for (int beta = 0;beta<p;++beta){
      condition1 = (G(alpha,beta)==2) & (G(beta,alpha)==3); // alpha -> beta
      condition2 = (G(alpha,beta)==2) & (G(beta,alpha)!=0); // alpha *-> beta
      if (condition1 | condition2){
        rule2search(G,beta,alpha,condition1,condition2,track_changes,verbose);
      }
    }
  }
  return track_changes;
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

void rule3bsearch(NumericMatrix &G,const int &alpha,const int &beta,const int &gamma,bool &track_changes,bool verbose=false){
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
          if (verbose){
            Rcout << "Rule 3:\n";
            Rcout << "Orient: " << theta << " *-> " << beta << std::endl;
          }
          track_changes = true;
        }
      }
    }
  }
}

// [[Rcpp::export]]
bool rule3(NumericMatrix &G,bool &track_changes,bool verbose=false) {
  int p = G.nrow(); // Square matrix
  int gamma;
  List searchResults;
  NumericVector gammaVals;
  //bool condition1;
  //bool condition2;
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
            rule3bsearch(G,alpha,beta,gamma,track_changes,verbose);
          }
        }
      }
    }
  }
  return track_changes;
}

bool check_sep_r4(int beta,NumericVector md_path,List sepsets,NumericVector neighborhood,bool verbose=false){
  if (verbose) Rcout << "Checking separation";
  int n = md_path.length();
  String theta = String((char) neighborhood(md_path(0)));
  String gamma = String((char) neighborhood(md_path(n-1)));
  List tmp1 = sepsets[theta];
  List tmp2 = sepsets[gamma];
  NumericVector set = tmp1[gamma];
  bool cond1 = check_inclusion(beta,set);
  set = tmp2[theta];
  bool cond2 = check_inclusion(beta,set);
  if (verbose) Rcout << "...finished\n";
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
// [[Rcpp::export]]
bool rule4(NumericMatrix &G,List sepsets,NumericVector neighborhood,bool &track_changes,bool verbose = false){
  int p = G.nrow();
  bool cond1;
  bool cond2;
  bool done;
  NumericVector md_path;
  for (int beta=0;beta<p;++beta){
    for (int gamma=0;gamma<p;++gamma){
      if (G(beta,gamma)!=0 && G(gamma,beta)==1){
        //Rcout << "Potential beta: " << beta << " | Potential gamma: " << gamma;
        for (int alpha=0;alpha<p;++alpha){
          cond1 = G(beta,alpha)==2 && G(alpha,beta)!=0;
          cond2 = G(gamma,alpha)==3 && G(alpha,gamma)==2; // triangle structure exists but is not oriented
          if (cond1 && cond2){
            //Rcout << " | Potential alpha: " << alpha;
            done = false;
            while(G(gamma,beta)==1){
              while(!done && G(alpha,beta)!=0 && G(alpha,gamma)!=0 && G(beta,gamma)!=0){
                //Rcout << "# of Nodes: " << G.ncol() << std::endl;
                md_path = minDiscPath(G,alpha,beta,gamma,verbose);
                if (NumericVector::is_na(md_path(0))){
                  done = true; // We are done with this triangle  
                } else {
                  if(check_sep_r4(beta,md_path,sepsets,neighborhood,verbose)){
                    if (verbose){
                      Rcout << "\nRule 4\nThere is a discriminating path between";
                      Rcout << md_path(0) << " and " << gamma << " for " << beta;
                      Rcout << " and " << beta << " is in the SepSet of " << gamma;
                      Rcout << " and " << md_path(0) << ". Orient: ";
                      Rcout << beta << " -> " << gamma << std::endl;
                    }
                    G(beta,gamma) = 2;
                    G(gamma,beta) = 3;
                  } else {
                    // b is not in sepset
                    if (verbose){
                      Rcout << "\nRule 4\nThere is a discriminating path between ";
                      Rcout << md_path(0) << " and " << gamma << " for " << beta;
                      Rcout << " and " << beta << " is NOT in the SepSet of ";
                      Rcout << gamma << " and " << md_path(0) << ". Orient: ";
                      Rcout << alpha << " <-> " << beta << " <-> " << gamma << std::endl;
                    }
                    G(beta,gamma)=2;
                    G(gamma,beta)=2;
                    if (G(alpha,beta)==3){
                      Rcout << "\nContradiction in Rule 4b\n";  
                    }
                    G(alpha,beta) = 2;
                  }
                  done = true;
                  track_changes = true;
                }
              }
            } 
          }  
        }
      }
    }  
  }
  return track_changes;
}

// [[Rcpp::export]]
bool rule8(NumericMatrix &G,bool &track_changes,bool verbose=false){
  int p = G.nrow();
  bool cond1;
  bool cond2;
  bool cond3;
  for (int alpha=0;alpha<p;++alpha){
    for (int gamma=0;gamma<p;++gamma){
      if (G(alpha,gamma)==2 && G(gamma,alpha)==1){ // alpha o-> gamma
        for (int beta=0;beta<p;++beta){
          cond1 = G(beta,alpha)==3 && G(alpha,beta)==2; // alpha -> beta
          cond2 = G(beta,alpha)==3 && G(alpha,beta)==1; // alpha -o beta
          if (cond1 || cond2){
            cond3 = G(beta,gamma)==2 && G(gamma,beta)==3; // beta -> gamma
            if (cond3){
              G(gamma,alpha) = 3; // alpha -> gamma
              if (cond1){
                if (verbose){
                  Rcout << "\nRule 8\nOrient: " << alpha << " -> " << beta << " -> " << gamma;
                  Rcout << " with " << alpha << " o-> " << gamma << " as ";
                  Rcout << alpha << " -> " << gamma << std::endl;
                }
              } else {
                if (verbose){
                  Rcout << "\nRule 8\nOrient: " << alpha << " o-> " << beta << " -> " << gamma;
                  Rcout << " with " << alpha << " o-> " << gamma << " as ";
                  Rcout << alpha << " -> " << gamma << std::endl;  
                }
              }
              track_changes = true;
            }
          }
        }
      }  
    }  
  }
  return track_changes;
}

// [[Rcpp::export]]
bool rule9(NumericMatrix &G,bool &track_changes,bool verbose=false){
  int p = G.nrow();
  bool cond1;
  bool cond2;
  bool cond3;
  bool cond4;
  bool cond_final;
  std::vector<int> beta_vals;
  int beta_current;
  NumericVector upd;
  
  for (int alpha=0;alpha<p;++alpha){
    for (int gamma=0;gamma<p;++gamma){
      if (G(alpha,gamma)==2 && G(gamma,alpha)==1){ // alpha o-> gamma
        //Rcout << "Potential alpha: " << alpha << " | Potential gamma: " << gamma << std::endl;
        beta_vals.clear();
        // Find all beta such that alpha (o-)-(o>) beta, and beta and gamma are not connected
        for (int beta=0;beta<p;++beta){
          cond1 = G(alpha,beta) == 2 || G(alpha,beta) == 1;
          cond2 = G(beta,alpha) == 1 || G(beta,alpha) == 3;
          cond3 = G(gamma,beta) == 0 && G(beta,gamma) == 0;
          cond4 = beta != gamma;
          cond_final = cond1 && cond2 && cond3 && cond4;
          if (cond_final){
            //Rcout << "Potential beta: " << beta << std::endl;
            beta_vals.push_back(beta);
          }
        }
        while (beta_vals.size() > 0 && G(gamma,alpha)==1){
          beta_current = beta_vals[beta_vals.size()-1];
          beta_vals.pop_back();
          upd = minUncovPdPath(p,G,alpha,beta_current,gamma,verbose);
          //Rcout << "Length of upd: " << upd.length() << std::endl;
          if (upd.length()>1){
            G(gamma,alpha) = 3;
            if (verbose){
              Rcout << "Rule 9: There exists an uncovered potentially directed ";
              Rcout << "path between " << alpha << " and " << gamma << std::endl;
              Rcout << "Orient: " << alpha << " -> " << gamma << std::endl;
            }
            track_changes = true;
          }
        }
      }  
    }
  }
  return track_changes;
}

// [[Rcpp::export]]
bool rule10(NumericMatrix &G,bool &track_changes,bool verbose=false){
  int p = G.nrow();
  bool cond1;
  bool cond2;
  bool cond3;
  bool cond4;
  bool cond5;
  
  NumericVector beta_vals;
  int counter_b=0;
  int beta;
  
  int counter_d=0;
  NumericVector rem;
  NumericVector d_vals;
  int d;
  
  NumericVector x_vals;
  NumericVector x2_vals;
  int counter_x1;
  int first_pos;
  
  int counter_x2;
  int second_pos;
  
  NumericVector t1;
  NumericVector t2;
  
  
  
  for (int alpha=0;alpha<p;++alpha){
    for (int gamma=0;gamma<p;++gamma){ // search for alpha o-> gamma
      cond1 = G(alpha,gamma)==2 && G(gamma,alpha)==1;
      if (cond1){
        //Rcout << "Potential alpha: " << alpha << " | Potential gamma: " << gamma << std::endl;
        for (int b=0;b<p;++b){ // search for beta -> gamma
          cond1 = G(gamma,b)==3 && G(b,gamma)==2;
          if (cond1){
            //Rcout << "Potential beta: " << b << std::endl;
            beta_vals.push_back(b);  
          }
        }
        if (beta_vals.length()>=2){
          counter_b=0;
          while (counter_b<beta_vals.length() && G(gamma,alpha)==1){
            beta = beta_vals(counter_b);
            ++counter_b;
            counter_d=0;
            rem = NumericVector::create(beta);
            //Rcout << "Current beta: " << beta << std::endl;
            d_vals = setdiff(beta_vals,rem);
            //print_vector_elements_nonames(d_vals,"d_vals: ","\n");
            counter_d = 0;
            while ((counter_d < d_vals.length()) && (G(gamma,alpha)==1)){
              d = d_vals(counter_d);
              //Rcout << "Current theta: " << d << std::endl;
              ++counter_d;
              // The following is the easiest
              cond1 = G(alpha,beta)==1 || G(alpha,beta)==2;
              cond2 = G(beta,alpha)==1 || G(beta,alpha)==3;
              cond3 = G(alpha,d)==1 || G(alpha,d)==2;
              cond4 = G(d,alpha)==1 || G(d,alpha)==3;
              cond5 = G(d,beta)==0 && G(beta,d)==0;
              if (cond1&cond2&cond3&cond4&cond5){
                G(gamma,alpha) = 3;
                if (verbose) Rcout << "\nRule 10 [easy]:\nOrient: " << alpha << " -> " << gamma << std::endl;
                track_changes = true;
              } else { // search for two minimal uncovered p.d. paths
                // Find all x s.t. a (-o)-(o>) x  
                x_vals = NumericVector(0); // Creates an empty vector
                for (int x=0;x<p;++x){
                  cond1 = G(alpha,x)==1 || G(alpha,x)==2;
                  cond2 = G(x,alpha)==1 || G(x,alpha)==3;
                  cond3 = x != gamma;
                  if (cond1 && cond2 && cond3){
                    x_vals.push_back(x);
                  }
                }
                if (x_vals.length()>=2){
                  counter_x1 = 0;
                  while ((counter_x1 < x_vals.length()) && G(gamma,alpha)==1){
                    first_pos = x_vals(counter_x1);
                    //Rcout << "Potential first node on uncovered p.d. path p1: " << first_pos << std::endl;
                    ++counter_x1;
                    rem = NumericVector::create(first_pos);
                    x2_vals = setdiff(x_vals,rem);
                    counter_x2 = 0;
                    while (counter_x2 < x2_vals.length() && G(gamma,alpha)==1){
                      second_pos = x2_vals(counter_x2);
                      //Rcout << "Potential first node on uncovered p.d. path p2: " << second_pos << std::endl;
                      ++counter_x2;
                      t1 = minUncovPdPath(p,G,alpha,first_pos,beta,verbose);
                      if (verbose) print_vector_elements_nonames(t1,"t1: ","\n");
                      if (t1.length()>1){
                        t2 = minUncovPdPath(p,G,alpha,second_pos,d,verbose);
                        if (t2.length()>1 && first_pos!=second_pos && G(first_pos,second_pos)==0){
                          G(gamma,alpha)=3;
                          if (verbose) Rcout << "\nRule 10\nOrient: " << alpha << " -> " << gamma << std::endl;
                          track_changes = true;
                        } 
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }  
  }
  return track_changes;
}

// [[Rcpp::export]]
void allRules(NumericMatrix &G,List sepsets,NumericVector neighborhood,bool verbose){
  bool track_changes = true;
  while (track_changes){
    track_changes = false;
    track_changes = rule1(G,track_changes,verbose);
    track_changes = rule2(G,track_changes,verbose);
    track_changes = rule3(G,track_changes,verbose);
    track_changes = rule4(G,sepsets,neighborhood,track_changes,verbose);
    track_changes = rule8(G,track_changes,verbose);
    track_changes = rule9(G,track_changes,verbose);
    track_changes = rule10(G,track_changes,verbose);
  }
}

/*
 * Because of the special circumstances of our algorithm,
 * we are able to reassign certain edges because of our knowledge of targets
 * <-> => - ([2,2] to [1,1]) DONE
 * o-> => -> (decrement both i and j by 1) DONE
 * -> => -> (no change, but adj. matrix has to account differently, [3,2] to [0,1]) DONE 
 * o-o => - (no change in adj. matrix) DONE
 * -o => -> ([3,1] to [0,1]) DONE
 */

// [[Rcpp::export]]
void convertMixedGraph(NumericMatrix &G){
  int p = G.ncol();
  for (int i=0;i<p;++i){
    for (int j=i+1;j<p;++j){
      if (G(i,j)==2 && G(j,i)==2){
        // Convert bidirected edge to undirected
        G(i,j)=1;
        G(i,j)=1;
      } else if ((G(i,j)==1 && G(j,i)==2) || (G(i,j)==2 && G(j,i)==1)){
        // Convert o-> to ->
        --G(i,j);
        --G(j,i);
      } else if (G(i,j)==2 && G(j,i)==3){
        // Convert -> [3,2] to -> [0,1]
        --G(i,j);
        G(j,i)=0;
      } else if (G(j,i)==2 && G(i,j)==3){
        // Convert <- [2,3] to <- [1,0]  
        --G(j,i);
        G(i,j)=0;
      } else if (G(i,j)==3 && G(j,i)==1){
        // Convert -o [3,1] to -> [0,1]
        G(i,j)=0;
      } else if (G(i,j)==1 && G(j,i)==3){
        // Convert o- [1,3] to <- [1,0]
        G(j,i)=0;  
      }
    }
  }
}
