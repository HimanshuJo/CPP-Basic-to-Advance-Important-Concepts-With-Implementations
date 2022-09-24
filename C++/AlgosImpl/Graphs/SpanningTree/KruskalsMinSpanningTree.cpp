// Kruskals Minimum Spanning Tree
/*
What is a Spanning Tree?

    A Spanning tree is a subset to a connected graph G, where all the edges are connected, 
    i.e, one can traverse to any edge from a particular edge with or without intermediates. 

    Also, a spanning tree must not have any cycle in it. 

    Thus we can say that if there are N vertices in a connected graph then the no. of edges that a 
    spanning tree may have is N-1.

-------

What is a Minimum Spanning Tree?

    Given a connected and undirected graph, a spanning tree of that graph is a subgraph that is a 
    tree and connects all the vertices together. 

    A single graph can have many different spanning trees. 

    A minimum spanning tree (MST) or minimum weight spanning tree for a weighted, connected, undirected graph 
    is a spanning tree with a weight less than or equal to the weight of every other spanning tree. 

    The weight of a spanning tree is the sum of weights given to each edge of the spanning tree.

-------

How many edges does a minimum spanning tree has? 
    
    A minimum spanning tree has (V – 1) edges where V is the number of vertices in the given graph.

-------

How to find MST using Kruskal’s algorithm?

    Sort all the edges in non-decreasing order of their weight. 

    Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. 

    If cycle is not formed, include this edge. Else, discard it. 
    
    Repeat step#2 until there are (V-1) edges in the spanning tree.

-------

Kruskal’s algorithm to find the minimum cost spanning tree uses the greedy approach. 

The Greedy Choice is to pick the smallest weight edge that does not cause a cycle in the MST constructed so far
*/
/*
Problem Statement

You are given an undirected, connected and weighted graph G(V, E), consisting of V number of vertices 
(numbered from 0 to V-1) and E number of edges.

Find and print the total weight of the Minimum Spanning Tree (MST) using Kruskal's algorithm.

By definition, a minimum weight spanning tree is a subset of the edges of a connected, edge-weighted undirected 
graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

Constraints :
2 <= V <= 10^5
1 <= E <= 3 * 10^5
0 <= X < N
0 <= Y < N
1 <= W <= 10^4

where V and E represent the number of vertices and edges respectively.
X and Y represent the vertices between which there is an edge.
W is the weight of the edge.
*/

#include<algorithm>
using namespace std;

struct custComp{
  bool operator()(vector<int>&A, vector<int>&B){
      return A[2]<B[2];
  }  
};

void initialize(int n, vector<int>&parent, vector<int>&rank){
    for(int i=0; i<n; ++i){
        parent[i]=i;
        rank[i]=0;
    }
}

int findParent(int node, vector<int>&parent){
    if(parent[node]==node) return node;
    return parent[node]=findParent(parent[node], parent);
}

int doUnion(int u, int v, vector<int>&parent, vector<int>&rank){
    int parentu=findParent(u, parent);
    int parentv=findParent(v, parent);
    if(parentu!=parentv){
        int rankpu=rank[parentu], rankpv=rank[parentv];
        if(rankpu<rankpv){
            parent[parentu]=parentv;
        } else if(rankpv<rankpu){
            parent[parentv]=parentu;
        } else{
            parent[parentu]=parentv;
            rank[parentv]++;
        }
    }
}

void dsu(int n, vector<int>&parent, vector<int>&rank){
    initialize(n, parent, rank);
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    vector<int>parent(n), rank(n);
    dsu(n, parent, rank);
    sort(edges.begin(), edges.end(), custComp());
    int minWeight=0;
    for(auto &vals: edges){
        int pu=findParent(vals[0], parent);
        int pv=findParent(vals[1], parent);
        if(pu!=pv){
            minWeight+=vals[2];
            doUnion(vals[0], vals[1], parent, rank);
        }
    }
    return minWeight;
}