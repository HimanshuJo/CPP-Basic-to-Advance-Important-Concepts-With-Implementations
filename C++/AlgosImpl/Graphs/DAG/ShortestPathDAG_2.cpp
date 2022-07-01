// Finding shortest distances from a source to all other vertices 
// using topological sorting (DFS based)
/*
Time Complexity: O(|V| + |E|)

Since we are computing the topological ordering of the nodes 
in the graph.

Space complexity: O(|V|) at the worst case, as the 
maximum nodes stored in the stack are O(|V|). 

Also, the distances being stored in the list of distances 
is of length |V|. Hence it takes O(|V|) space.
*/

/*
What is topological Sorting?

Answer) Topological Sorting is defined as a linear ordering of 
vertices of a graph G(V, E) such that for every directed 
edge e = (u, v), vertex u comes before the vertex v. 

It can be found only if the graph is a DAG. 
*/

#include<vector>
#include<stack>
#include<iostream>
using namespace std;

void dfs(int curnode, vector<vector<pair<int, int>>>&adj, vector<bool>&seen, stack<int>&stk){
  seen[curnode]=true;
  for(auto &nei: adj[curnode]){
    if(seen[nei.first]==false){
      dfs(nei.first, adj, seen, stk);
    }
  }
  stk.push(curnode);
}

void shortestDistances(vector<vector<pair<int, int>>>&adj, stack<int>&stk, vector<int>&shortestPath){
  while(!stk.empty()){
    int curr=stk.top();
    stk.pop();
    if(shortestPath[curr]!=INT_MAX){
      for(auto &nei: adj[curr]){
          if(shortestPath[curr]+nei.second<shortestPath[nei.first]){
            shortestPath[nei.first]=shortestPath[curr]+nei.second;
        }
      }
    }
  }
}

void findTopoSort(int vertices, vector<vector<pair<int, int>>>&adj,  vector<int>&shortestPath,
                  vector<bool>&seen, stack<int>&stk){
  for(int i=0; i<vertices; ++i){
    if(seen[i]==false){
      dfs(i, adj, seen, stk);
    }
  }
  shortestDistances(adj, stk, shortestPath);
}

void findShortestPathDAG(const int vertices, const int numEdges, const vector<vector<int>>&edges,
                         vector<int>&shortestPath, int src){
  vector<vector<pair<int, int>>>adj(vertices);
  for(auto &vals: edges){
    adj[vals[0]].push_back({vals[1], vals[2]});    
  }
  vector<bool>seen(vertices, false);
  stack<int>stk;
  findTopoSort(vertices, adj, shortestPath, seen, stk);
}


int main(){
  int vertices=6, numEdges=9;
  vector<vector<int>>edges{{1, 3, 6}, {1, 2, 2}, {0, 1, 5}, {0, 2, 3}, {3, 4, -1},
                           {2, 4, 4}, {2, 5, 2}, {2, 3, 7}, {4, 5, -2}};
  int src=1;
  vector<int>shortestPath(vertices, INT_MAX);
  shortestPath[src]=0;
  findShortestPathDAG(vertices, numEdges, edges, shortestPath, src);
  for(int i=0; i<vertices; ++i){
    cout<<shortestPath[i]<<" ";
  }
}