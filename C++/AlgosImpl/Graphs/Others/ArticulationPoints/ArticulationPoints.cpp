/*
Given an undirected graph G, find all the articulation points in the graph.

For a connected undirected graph, an articulation point or a cut vertex is a vertex in the graph 
removing which disconnects the graph.

For a disconnected undirected graph, an articulation point or a cut vertex is a vertex removing which 
increases the number of connected components.
*/

/*
Approach 1:

Idea: A simple method is to remove all vertices one by one and see if it causes the graph to become disconnected.
 
Algorithm:

Loop around all the vertices.
Do the following for each vertex v

a) Remove v from the graph.

b) Check if the graph is still connected (we can use BFS or DFS to check that)

c) Add v to the graph again.


Time Complexity: 

	O(V*(V+E))
	
	For every v, BFS/DFS will take O(V+E) time to check for the graph's connectivity. 

	Therefore, O(V*(V+E)) is the time complexity.
*/

/*
Approach 2: 
 
Idea: The idea is to use DFS and find the articulation points simultaneously with some extra coding. 
As DFS takes O(V+E) time, therefore the time complexity of this approach will be O(V+E).
 
We will visit the vertices in the tree form known as the DFS tree. 

In the DFS tree, a vertex u in the graph is the parent of another vertex v 
if v is adjacent to u and discovered by u.

In the DFS tree, a vertex u is articulation point if any of the following conditions is true:

	1. u is the root of the DFS tree, and it has at least two children.

    2.  u is not the root of the DFS tree, and it has a child v such that no vertex in the 
        subtree rooted with v has a back edge to any of u's ancestors in the DFS tree.

Note: A leaf in a DFS Tree is never an articulation point.

-------

Algorithm: 

In DFS traversal, maintain a parent array where parent[i] stores the parent of vertex i and a visited array. 
 
For condition 1:

For every vertex u, count its children. If the currently visited vertex u is the root, 
i.e., parent[u] = NULL and has more than two children, it is an articulation point.

3. For condition 2:

	Maintain an array disc[] to store vertices discovery time.

	For each node u, we must determine the earliest visited vertex (the vertex with the shortest discovery time) 
	reached from the subtree rooted with u. 

	As a result, we keep an additional array low[] defined as follows.

	low[u] = min(disc[u], disc[k]), where k is an ancestor of node u, and 
	there is a back edge from some descendant of u to k.

	After determining the lowest discovery number for all vertices, the algorithm takes a pair of vertices to 
	determine articulation points. 

	Consider the vertices V1 and V2. 

		V1 is the parent vertex, while V2 is the child vertex.

	If the lowest discovery number of V1 is more than or equal to the lowest discovery number of V2, 
	then V1 is an articulation point.
*/

#include<vector>
#include<iostream>
#include<climits>
using namespace std;

void dfs(int node, vector<vector<int>>&adj, vector<int>&disc, vector<int>&low, 
	     int parent, vector<bool>&seen, int &timer, vector<int>&res){
	seen[node]=true;
	disc[node]=low[node]=timer++;
	int child=0;
	for(auto &nei: adj[node]){
		if(nei==parent) continue;
		if(seen[nei]==false){
			dfs(nei, adj, disc, low, node, seen, timer, res);
			low[node]=min(low[node], low[nei]);
			/*
				After returning from the current node, if the 'low' for any of it's neighbor>='discovery time'
				of the current node, that means removing the current node will make the graph disconnected,
				or if the graph is disconnected it will result in increase in connected components
			*/
			if(low[nei]>=disc[node]&&parent!=-1){
				/* the parent node is the articulation point
					removing that will result in more connected components
				*/
				res.push_back(node);
			}
			child++;
		} else{
			low[node]=min(low[node], disc[nei]);
		}
	}
	if(parent==-1&&child>1){
		res.push_back(node);
	}
}

vector<int> findArticulationPoints(const int vertices, vector<vector<int>>&edges){
	vector<vector<int>>adj(vertices);
	for(auto &vals: edges){
		adj[vals[0]].push_back(vals[1]);
	}
	vector<int>disc(vertices, -1);
	vector<int>low(vertices, -1);
	int parent=-1;
	vector<bool>seen(vertices, false);
	int timer=0;
	vector<int>res;
	for(int i=0; i<vertices; ++i){
		if(seen[i]==false){
			dfs(i, adj, disc, low, parent, seen, timer, res);
		}
	}
	return res;
}

int main(){
	int vertices=5;
	vector<vector<int>>edges{{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
	vector<int>ans=findArticulationPoints(vertices, edges);
	for(auto &vals: ans){
		cout<<vals<<" ";
	}
	cout<<"\n-------\n";
	int vertices2=4;
	vector<vector<int>>edges2{{0, 1}, {1, 2}, {2, 3}};
	vector<int>ans2=findArticulationPoints(vertices2, edges2);
	for(auto &vals: ans2){
		cout<<vals<<" ";
	}
}