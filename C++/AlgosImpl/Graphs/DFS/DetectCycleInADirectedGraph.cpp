// Detect Cycle In A Directed Graph
/*
Problem Statement:

	You are given a directed graph having ‘N’ nodes. 

	A matrix ‘EDGES’ of size M x 2 is given which represents the ‘M’ edges such that there is an 
	edge directed from node EDGES[i][0] to node EDGES[i][1].

	Find whether the graph contains a cycle or not, return true if a cycle is present in the given 
	directed graph else return false.
*/

#include<vector>
#include<iostream>
using namespace std;

bool dfs(int n, vector<vector<int>>&adj, vector<int>&seen, vector<int>&seenInClStk, int i, bool &ans){
    seen[i]=1;
    seenInClStk[i]=1;
    for(auto &nei: adj[i]){
        if(seen[nei]==0){
            dfs(n, adj, seen, seenInClStk, nei, ans);
        } else{
            if(seenInClStk[nei]){
                ans=true;
                return ans;
            }
        }
    }
    seenInClStk[i]=0;
    return ans;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>>adj(n+1);
    for(auto &vals: edges){
        adj[vals.first].push_back(vals.second);
    }
    vector<int>seen(n+1, 0);
    vector<int>seenInClStk(n+1, 0);
    for(int i=1; i<=n; ++i){
        if(!seen[i]){
            bool ans=false;
            dfs(n, adj, seen, seenInClStk, i, ans);
            if(ans) return 1;
        }
    }
    return 0;
}