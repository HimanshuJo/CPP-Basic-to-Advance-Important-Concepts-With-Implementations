// Minimum Spanning Tree
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