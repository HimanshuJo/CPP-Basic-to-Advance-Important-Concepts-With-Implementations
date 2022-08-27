// Maximum number of edges among all connected components of an undirected graph
/*
Given integers ‘N’ and ‘K’ where, N is the number of vertices of an undirected graph
and ‘K’ denotes the number of edges in the same graph (each edge is denoted by a pair of
integers where i, j means that the vertex ‘i’ is directly connected to the vertex ‘j’ in the graph).
The task is to find the maximum number of edges among all the connected components in
the given graph.

Examples:

Input: N = 6, K = 4,
Edges = {{1, 2}, {2, 3}, {3, 1}, {4, 5}}

Output: 3
Here, graph has 3 components
1st component 1-2-3-1 : 3 edges
2nd component 4-5 : 1 edges
3rd component 6 : 0 edges
max(3, 1, 0) = 3 edges

Input: N = 3, K = 2,
Edges = {{1, 2}, {2, 3}}

Output: 2
*/
/*
Approach:

Using Depth First Search, find the sum of the degrees of each of the edges in all
the connected components separately.
Now, according to Handshaking Lemma, the total number of edges in a connected
component of an undirected graph is equal to half of the total sum of the degrees
of all of its vertices.
Print the maximum number of edges among all the connected components.
*/

// C++ program to find the connected component
// with maximum number of edges
#include <bits/stdc++.h>
using namespace std;

// DFS function
int dfs(int s, vector<int> adj[], vector<bool> visited, int nodes) {
	// Adding all the edges connected to the vertex
	int adjListSize = adj[s].size();
	visited[s] = true;
	for (long int i = 0; i < adj[s].size(); i++) {
		if (visited[adj[s][i]] == false) {
			adjListSize += dfs(adj[s][i], adj, visited, nodes);
		}
	}
	return adjListSize;
}

int maxEdges(vector<int> adj[], int nodes)
{
	int res = INT_MIN;
	vector<bool> visited(nodes, false);
	for (long int i = 1; i <= nodes; i++) {
		if (visited[i] == false) {
			int adjListSize = dfs(i, adj, visited, nodes);
			res = max(res, adjListSize / 2);
		}
	}
	return res;
}

int main()
{
	int nodes = 3;
	vector<int> adj[nodes + 1];

	// Edge from vertex 1 to vertex 2
	adj[1].push_back(2);
	adj[2].push_back(1);

	// Edge from vertex 2 to vertex 3
	adj[2].push_back(3);
	adj[3].push_back(2);

	cout << maxEdges(adj, nodes);

	return 0;
}
