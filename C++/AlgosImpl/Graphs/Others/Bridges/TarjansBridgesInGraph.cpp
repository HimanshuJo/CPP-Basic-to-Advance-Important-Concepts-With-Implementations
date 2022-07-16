// Bridges In A Graph
/*
Problem Statement

Given an undirected graph of V vertices and E edges. Your task is to find all the bridges in the given 
undirected graph. 

A bridge in any graph is defined as an edge which, when removed, makes the graph disconnected 
(or more precisely, increases the number of connected components in the graph).
*/

void dfs(int node, int &timer, int parent, vector<int>&low, vector<int>&disc,
         vector<vector<int>>&adj, vector<bool>&seen, vector<vector<int>>&res){
         seen[node]=true;
         low[node]=disc[node]=timer++;
         for(auto &nei: adj[node]){
             if(nei==parent) continue;
             if(seen[nei]==false){
                 dfs(nei, timer, node, low, disc, adj, seen, res);
                 /*
                 	the child's low could have been updated to a new min via a back edge,
                 	so on returning parent's low should also be updated accordingly
                 */
                 low[node]=min(low[node], low[nei]);
                 // check for a bridge edge
                 if(low[nei]>disc[node]){
                     vector<int>temp;
                     temp.push_back(node);
                     temp.push_back(nei);
                     res.push_back(temp);
                 }
             } else{
             	/*
             		to reach this child from the parent, there was another way, that way might have taken
             		less time
             	*/
                 low[node]=min(low[node], disc[nei]);
             }
         }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    vector<vector<int>>adj(v);
    for(auto &entries: edges){
        adj[entries[0]].push_back(entries[1]);
        adj[entries[1]].push_back(entries[0]);
    }
    vector<int>disc(v, -1);
    vector<int>low(v, -1);
    vector<bool>seen(v, false);
    int parent=-1;
    int timer=0;
    vector<vector<int>>res;
    for(int i=0; i<v; ++i){
        if(seen[i]==false){
            dfs(i, timer, parent, low, disc, adj, seen, res);
        }
    }
    return res;
}