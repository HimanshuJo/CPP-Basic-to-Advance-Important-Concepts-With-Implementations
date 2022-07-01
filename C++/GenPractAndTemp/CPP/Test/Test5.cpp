#include<vector>
#include<iostream>
#include<queue>
using namespace std;

void findTopoSort(const int vertices, vector<vector<pair<int, int>>>&adj, vector<int>&indeg, vector<int>&shortestPath, vector<int>&topoSort, queue<int>&q){
	for(int i=0; i<vertices; ++i){
		if(indeg[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int curr=q.front();
    topoSort.push_back(curr);
		q.pop();
    for(auto &nei: adj[curr]){
      if(--indeg[nei.first]==0){
        q.push(nei.first);
      }
    }
	}
  for(auto &vals: topoSort){
    if(shortestPath[vals]!=INT_MAX){
      for(auto &nei: adj[vals]){
        if(shortestPath[nei.first]>shortestPath[vals]+nei.second){
          shortestPath[nei.first]=shortestPath[vals]+nei.second;
        }
      }
    }
  }
}

void findShortestPathDAG(const int vertices, const int numEdges, const vector<vector<int>>&edges, vector<int>&shortestPath, int src){
	vector<vector<pair<int, int>>>adj(vertices);
	vector<int>indeg(vertices, 0);
	for(auto &vals: edges){
		adj[vals[0]].push_back({vals[1], vals[2]});
		indeg[vals[1]]++;
	}
	vector<int>topoSort;
	queue<int>q;
	findTopoSort(vertices, adj, indeg, shortestPath, topoSort, q);
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

