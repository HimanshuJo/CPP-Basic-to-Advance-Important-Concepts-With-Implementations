// Count Strongly Connected Components (Kosaraju’s Algorithm)
/*
Problem Statement

You are given an unweighted directed graph having 'V' vertices and 'E' edges.
Your task is to count the number of strongly connected components (SCCs) present in the graph.

A directed graph is said to be strongly connected if every vertex is reachable from every other vertex. 
The strongly connected components of a graph are the subgraphs which are themselves strongly connected.

Note :
Use zero-based indexing for the vertices.

The given graph doesn’t contain any self-loops.

Constraints :
1 <= T <= 10
1 <= V <= 10^4
0 <= E <= 10^4
0 <= a, b < V

Time Limit: 1 sec
*/

#include<stack>
#include<vector>
using namespace std;

void dfs(int curnode, vector<vector<int>>&gr, vector<int>&seen, stack<int>&stk){
    seen[curnode]=1;
    for(auto &nei: gr[curnode]){
        if(seen[nei]==0){
            dfs(nei, gr, seen, stk);
        }
    }
    stk.push(curnode);
}

void dfs2(int curnode, vector<vector<int>>&transposeGr, vector<int>&seen){
    seen[curnode]=1;
    for(auto &nei: transposeGr[curnode]){
        if(seen[nei]==0){
            dfs2(nei, transposeGr, seen);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>>gr(v);
    for(auto &vals: edges){
        gr[vals[0]].push_back(vals[1]);
    }
    stack<int>stk;
    vector<int>seen(v+1, 0);
    for(int i=0; i<v; ++i){
        if(seen[i]==0){
            dfs(i, gr, seen, stk);
        }
    }
    vector<vector<int>>transposeGr(v+1);
    for(int i=0; i<v; ++i){
        seen[i]=0;
        for(auto &nei: gr[i]){
            transposeGr[nei].push_back(i);
        }
    }
    int ans=0;
    while(!stk.empty()){
        int i=stk.top();
        stk.pop();
        if(seen[i]==0){
            ans++;
            dfs2(i, transposeGr, seen);
        }
    }
    return ans;
}