/*
A Tree is a generalization of connected graph where it has N nodes that will have exactly N-1 edges,
    i.e one edge between every pair of vertices. Find the Euler tour of tree represented by adjacency list.

Example:

                1
               /
              2
             / \
            3   4

Output : 1 2 3 2 4 2 1

Euler tour is defined as a way of traversing tree such that each vertex is added to the tour
    when we visit it (either moving down from parent vertex or returning from child vertex).

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

#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

// We need an Adjacency list representation of the tree
vector<int>adj[MAX];

// We need a visited array to keep track of all the visited nodes on the tour
int vis[MAX];

// We need an array to store the Euler Tour
int euler[2 * MAX];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void eulerTour(int u, int &indx) {
    vis[u] = 1;
    euler[indx++] = u;
    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTour(it, indx);
            euler[indx++] = u;
        }
    }
}

void printEulerTour(int root, int N) {
    int index = 0;
    eulerTour(root, index);
    for (int i = 0; i < (2 * N - 1); ++i) {
        cout << euler[i] << " ";
    }
}

int main() {
    int N = 4;
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(2, 4);
    printEulerTour(1, N);
    return 0;
}