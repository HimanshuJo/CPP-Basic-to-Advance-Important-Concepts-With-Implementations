/*
A Tree is a generalization of connected graph where it has N nodes that will have exactly N-1 edges,
i.e one edge between every pair of vertices. Find the Euler tour of tree represented by adjacency list.

Euler tour is defined as a way of traversing tree such that each vertex is added to the 
tour when we visit it
(either moving down from parent vertex or returning from child vertex). 
We start from root and reach back to root after visiting all vertices.
It requires exactly 2*N-1 vertices to store Euler tour.

Approach: We will run DFS(Depth first search) algorithm on Tree as:

(1) Visit root node, i.e 1
vis[1]=1, Euler[0]=1
run dfs() for all unvisited adjacent nodes(2)
(2) Visit node 2
vis[2]=1, Euler[1]=2
run dfs() for all unvisited adjacent nodes(3, 4)
(3) Visit node 3
vis[3]=1, Euler[2]=3
All adjacent nodes are already visited, return to parent node
and add parent to Euler tour Euler[3]=2
(4) Visit node 4
vis[4]=1, Euler[4]=4
All adjacent nodes are already visited, return to parent node
and add parent to Euler tour, Euler[5]=2
(5) Visit node 2
All adjacent nodes are already visited, return to parent node
and add parent to Euler tour, Euler[6]=1
(6) Visit node 1
All adjacent nodes are already visited, and node 1 is root node
so, we stop our recursion here.
*/

// Auxiliary Space: O(N) 
// Time Complexity: O(N)
// C++ program to print Euler tour of a
// tree.
#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

// Adjacency list representation of tree
vector<int> adj[MAX];

// Visited array to keep track visited
// nodes on tour
int vis[MAX];

// Array to store Euler Tour
int Euler[2 * MAX];

// Function to add edges to tree
void add_edge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Function to store Euler Tour of tree
void eulerTree(int u, int &indx)
{
	vis[u] = 1;
	Euler[indx++] = u;
	for (auto it : adj[u]) {
		if (!vis[it]) {
			eulerTree(it, indx);
			Euler[indx++] = u;
		}
	}
}

// Function to print Euler Tour of tree
void printEulerTour(int root, int N)
{
	int index = 0;
	eulerTree(root, index);
	for (int i = 0; i < (2 * N - 1); i++)
		cout << Euler[i] << " ";
}

int main()
{
	int N = 4;

	add_edge(1, 2);
	add_edge(2, 3);
	add_edge(2, 4);

	// Consider 1 as root and print
	// Euler tour
	printEulerTour(1, N);

	return 0;
}
