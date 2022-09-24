// Prim's MST
/*
	Like Kruskal’s algorithm, Prim’s algorithm is also a Greedy algorithm. 
	Prim’s algorithm always starts with a single node and it moves through several adjacent nodes, 
	in order to explore all of the connected edges along the way.

	-------

	It starts with an empty spanning tree. 

	The idea is to maintain two sets of vertices. 

		The first set contains the vertices already included in the MST, 

		the other set contains the vertices not yet included. 

		At every step, it considers all the edges that connect the two sets and picks the minimum 
		weight edge from these edges. 

		After picking the edge, it moves the other endpoint of the edge to the set containing MST.

	-------

	A group of edges that connects two sets of vertices in a graph is called cut in graph theory. 

	So, at every step of Prim’s algorithm, find a cut (of two sets, one contains the vertices already 
	included in MST and the other contains the rest of the vertices), 

	pick the minimum weight edge from the cut, and include this vertex to MST Set 
	(the set that contains already included vertices). 

	-------

	How does Prim’s Algorithm Work?

		The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. 

		So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. 

			And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

	-------

	Follow the given steps to find MST using Prim’s Algorithm:

		Create a set mstSet that keeps track of vertices already included in MST.

		Assign a key value to all vertices in the input graph. 

			Initialize all key values as INFINITE. 

			Assign the key value as 0 for the first vertex so that it is picked first.

		While mstSet doesn’t include all vertices 
		
		Pick a vertex u which is not there in mstSet and has a minimum key value. 
		
		Include u in the mstSet. 
		
		Update the key value of all adjacent vertices of u. 

			To update the key values, iterate through all adjacent vertices. 

			For every adjacent vertex v, if the weight of edge u-v is less than the previous key value of v, 
			update the key value as the weight of u-v
*/
/*
Problem Statement

You are given an undirected connected weighted graph having ‘N’ nodes numbered from 1 to 'N'. 
A matrix ‘E’ of size M x 2 is given which represents the ‘M’ edges such that there is an edge directed from 
node E[i][0] to node E[i][1]. You are supposed to return the minimum spanning tree where you need to 
return weight for each edge in the MST.

Constraints :
1 ≤ T ≤ 5
2 <= N <= 100
1 <= M <= min(1000, N(N - 1) / 2)
1 <= E[i][0], E[i][1] <= N
*/

#include<climits>
using namespace std;

// TC: O(n log n)  n: number of nodes
// SC: O(n)
class Solution1{

	struct custComp{
	  bool operator()(pair<int, int>&A, pair<int, int>&B){
	      return A.first>B.first;
	  }  
	};

	vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
	{
	    vector<vector<pair<int, int>>>adj(n+1);
	    for(auto &entries: g){
	        adj[entries.first.first].push_back({entries.first.second, entries.second});
	        adj[entries.first.second].push_back({entries.first.first, entries.second});
	    }
	    vector<int>minn(n+1, INT_MAX);
	    vector<bool>mst(n+1, false);
	    vector<int>parent(n+1, -1);
	    minn[1]=0;
	    parent[1]=-1;
	    priority_queue<pair<int, int>, vector<pair<int, int>>, custComp>pq;
	    pq.push({minn[1], 1});
	    for(int i=1; i<=n; ++i){
	        pair<int, int>node;
	        while(true){
	           node=pq.top();
	           pq.pop();
	           if(mst[node.second]==false) break;
	        }
	        int minNode=node.second;
	        mst[minNode]=true;
	        for(auto &nei: adj[minNode]){
	            if(mst[nei.first]==false){
	                if(minn[nei.first]>nei.second){
	                    minn[nei.first]=nei.second;   
	                    parent[nei.first]=minNode;
	                    pq.push({minn[nei.first], nei.first});
	                } 
	            }
	        }
	    }
	    vector<pair<pair<int, int>, int>>ans;
	    for(int i=2; i<=n; ++i){
	        if(parent[i]!=-1){
	            ans.push_back({{parent[i], i}, minn[i]});
	        }
	    }
	    return ans;
	}
};

// -------*******-------
// TC: O(n*n)  n: number of nodes
// SC: O(n)
class Solution2{

	int findMinNode(vector<int>&minn, vector<bool>&mst, int n){
	    int minNodewt=INT_MAX;
	    int minNode;
	    for(int i=1; i<=n; ++i){
	        if(mst[i]==false){
	            if(minn[i]<minNodewt){
	                minNodewt=minn[i];
	                minNode=i;
	            }
	        }
	    }
	    return minNode;
	}

	vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
	{
	    vector<vector<pair<int, int>>>adj(n+1);
	    for(auto &entries: g){
	        adj[entries.first.first].push_back({entries.first.second, entries.second});
	        adj[entries.first.second].push_back({entries.first.first, entries.second});
	    }
	    vector<int>minn(n+1, INT_MAX);
	    vector<bool>mst(n+1, false);
	    vector<int>parent(n+1, -1);
	    minn[1]=0;
	    parent[1]=-1;
	    for(int i=1; i<=n; ++i){
	        int minNode=findMinNode(minn, mst, n);
	        mst[minNode]=true;
	        for(auto &nei: adj[minNode]){
	            if(mst[nei.first]==false){
	                if(minn[nei.first]>nei.second){
	                    minn[nei.first]=nei.second;   
	                    parent[nei.first]=minNode;  
	                } 
	            }
	        }
	    }
	    vector<pair<pair<int, int>, int>>ans;
	    for(int i=2; i<=n; ++i){
	        if(parent[i]!=-1){
	            ans.push_back({{parent[i], i}, minn[i]});
	        }
	    }
	    return ans;
	}
};
