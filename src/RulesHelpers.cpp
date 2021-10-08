#include "RulesHelpers.h"
#include <string.h>

/*
 * Minimum Discriminating Path
 * Purpose: find a minimal discriminating path for a,b,c.
 */

// Obtain values "d" that haven't been visited and d*->a
NumericVector get_d_vals(NumericMatrix &pag,int &a,LogicalVector &visited,bool verbose=false){
  int p = pag.nrow();
  NumericVector d_vals;
  for (int i=0;i<p;++i){
    // We need d *-> a
    if (pag(a,i)!=0 && pag(i,a)==2 && !visited(i)){
      d_vals.push_back(i);
    }
  }
  if (verbose) print_vector_elements_nonames(d_vals,"\nPotential values: ","\n");
  return d_vals;
}

NumericVector get_r_vals(NumericMatrix &pag,int d,LogicalVector &visited,bool verbose=false){
  int p = pag.nrow();
  NumericVector r_vals;
  for (int i=0;i<p;++i){
    // We need r *-> d
    if (pag(d,i)!=0 && pag(i,d)==2 && !visited(i)){
      r_vals.push_back(i);  
    }
  }
  if (verbose) print_vector_elements_nonames(r_vals,"Potential values for the path: ","\n");
  return r_vals;
}

List createPathList(int a,NumericVector set,bool verbose=false){
  if (verbose) Rcout << "Creating path list\n";
  int num_paths = set.length();
  NumericVector path = {0};
  path[0] = a;

  List paths_to_try(num_paths);

  NumericVector new_path;
  
  for (int i = 0;i<num_paths;++i){
    new_path = clone(path);
    new_path.push_back(set(i));
    paths_to_try[i] = new_path;
    if (verbose) print_vector_elements_nonames(paths_to_try[i],"New Path: ","\n");
  }
  
  return paths_to_try;
}

List updatePathList(NumericVector mpath,NumericVector &set,List &old_paths,bool verbose=false){
  int old_size = old_paths.length();
  if (verbose) Rcout << "Size of old path list: " << old_size << std::endl;
  int num_paths = set.length();
  //mpath.erase(0); // we don't need to go over this point again
  List new_paths(old_size+num_paths);
  if (verbose) Rcout << "Size of new path list: " << new_paths.length() << std::endl;
  
  NumericVector new_path;
  String starter1 = String("Path ");
  String starter2;
  for (int i=0;i<old_size+num_paths;++i){
    if (i < old_size){
      new_paths[i] = old_paths[i]; 
    } else {
      new_path = clone(mpath);
      new_path.push_back(set(i-old_size));
      new_paths[i] = new_path;
    }
    starter2 = starter1;
    starter2 += std::to_string(i);
    starter2 += ": ";
    if (verbose) print_vector_elements_nonames(new_paths[i],starter2,"\n");
  }
  return new_paths;
}

// [[Rcpp::export]]
NumericVector minDiscPath(NumericMatrix pag, int a,int b,int c,bool verbose=false){
  int p = pag.nrow();
  LogicalVector visited(p);
  visited(a) = true;
  visited(b) = true;
  visited(c) = true;
  
  NumericVector d_vals = get_d_vals(pag,a,visited,verbose); // Obtain values that are colliders on a path from the nodes to c
  if (d_vals.length()>0){
    List path_list = createPathList(a,d_vals,verbose);
    int counter = 0; // ensures that we go through each vector in the list
    int list_length = path_list.length();
    NumericVector mpath; // tracks the potential minimum discriminating path
    int m; // tracks the current length of the minimum discriminating path
    int d; // gives the last value in the path
    int pred;
    while (counter < list_length){
      mpath = path_list[counter];
      if (verbose) print_vector_elements_nonames(mpath,"mpath: ","\n");
      m = mpath.length();
      d = mpath(m-1);
      if (pag(c,d)==0 && pag(d,c)==0){
        NumericVector minDiscPath;
        for (int i=m-1;i>=0;--i){
          minDiscPath.push_back(mpath(i));
        }
        minDiscPath.push_back(b);
        minDiscPath.push_back(c);
        if (verbose) print_vector_elements_nonames(minDiscPath,"Minimum Discriminating Path: ","\n");
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
          path_list = updatePathList(mpath,r_vals,path_list,verbose);
        }
      }
      list_length = path_list.length();
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

// [[Rcpp::export]]
NumericVector minUncovPdPath(int p,NumericMatrix G, int alpha,int beta,int gamma,bool verbose){
  NumericVector path;
  NumericVector mpath;
  NumericVector final_path(0);
  NumericVector theta_vals(0);
  List path_list;
  int counter;
  int m;
  int d;
  int n;
  bool uncov;
  bool done = false;
  NumericVector r_vals(0);
  
  
  bool cond1 = G(beta,gamma)==1 || G(beta,gamma)==2;
  bool cond2 = G(gamma,beta)==1 || G(gamma,beta)==3;
  bool cond3 = G(gamma,alpha)==0 && G(alpha,gamma)==0;
  std::vector<bool> visited;
  if (cond1 && cond2 && cond3){
    final_path = NumericVector::create(alpha,beta,gamma);
    done = true;
    // TODO: Add print statement here
  }
  
  // Check for paths of 4 or more (what we are interested in for rule 9)
  if (verbose) Rcout << "Checking for paths of 4 or more\n";
  if (!done){
    visited.assign(p,false);
    visited[alpha]=true;
    visited[beta]=true;
    visited[gamma]=true;
    for (int theta=0;theta<p;++theta){
      cond1 = G(beta,theta)==1 || G(beta,theta)==2;
      cond2 = G(theta,beta)==1 || G(theta,beta)==3;
      cond3 = G(theta,alpha) == 0 && G(alpha,theta)== 0 && !visited[theta];
      if (cond1 && cond2 && cond3){
        if (verbose) Rcout << "Potential theta: " << theta << std::endl;
        theta_vals.push_back(theta);
      }
    }
    if (theta_vals.length()>0){
      path_list = createPathList(beta,theta_vals,verbose);
      counter = 0;
      while ((counter<path_list.length()) && (!done)){
        mpath = path_list[counter];
        if (verbose) print_vector_elements_nonames(mpath,"mpath: ","\n");
        m = mpath.length();
        d = mpath(m-1);
        visited[d]=true;
        cond1 = G(d,gamma)==1 || G(d,gamma)==2;
        cond2 = G(gamma,d)==1 || G(gamma,d)==3;
        if (cond1 && cond2){
          if (verbose) Rcout << "Found a final node on the uncovered p.d. path: " << d << std::endl;
          path = NumericVector::create(alpha);
          for (int i=0;i<m;++i){
            path.push_back(mpath(i));  
          }
          path.push_back(gamma);
          if (verbose) print_vector_elements_nonames(path,"Path: ","\n");
          n = path.length();
          uncov=true;
          for (int i=0;i<n-2;++i){
            cond1 = (G(path(i),path(i+2))==0) && (G(path(i+2),path(i))==0);
            if (!cond1){
              uncov = false;
              break;
            }
          }
          // TODO: add a print statement here
          if (uncov){
            final_path = path;
            if (verbose) print_vector_elements_nonames(final_path,"Final Path: ","\n");
            done = true;
          }
        } else {
          // d and c are not connected or connected with a "wrong" edge
          // iteratively search for neighbors of d not yet visited
          // and add them to potential members of the path
          for (int i=0;i<p;++i){
            cond1 = G(d,i) == 1 || G(d,i)==2;
            cond2 = G(i,d) == 1 || G(i,d)==3;
            cond3 = !visited[i];
            if (cond1 && cond2 && cond3){
              if (verbose) Rcout << "Potential New Value in Path: " << i << std::endl;
              r_vals.push_back(i);  
            }
          }
          if (r_vals.length()>0){
            path_list = updatePathList(mpath,r_vals,path_list,verbose);
          }
        }
        ++counter;
        r_vals = NumericVector(0);
        if (verbose) Rcout << "Counter: " << counter << " | Number of paths: " << path_list.length() << std::endl;
      } // End while
    }
  }
  if (final_path.length()==0){
    return NumericVector(0);  
  } else {
    return final_path;  
  }
}
