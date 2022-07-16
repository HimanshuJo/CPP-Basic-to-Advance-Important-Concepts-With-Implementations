// Bellman Ford
/*
Problem Statement
You have been given a directed weighted graph of ‘N’ vertices labeled from 1 to 'N' and ‘M’ edges. 
Each edge connecting two nodes 'u' and 'v' has a weight 'w' denoting the distance between them.

Your task is to find the length of the shortest path between the ‘src’ and ‘dest’ vertex given to you 
in the graph. The graph may contain negatively weighted edges.

Example:

3 3 1 3
1 2 2
1 3 2
2 3 -1

In the above graph, the length of the shortest path between vertex 1 and vertex 3 is 1->2->3 
with a cost of 2 - 1 = 1.

Constraints :
1 <= T <= 10
1 <= N <= 50
1 <= M <= 300
1 <= src, dest <= N
1 <= u,v <= N
-10^5 <= w <= 10^5

Time Limit: 1 sec
*/

#include<climits>
#include<vector>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1, 1e9);
    dist[src]=0;
    int sz=edges.size();
    for(int i=1; i<=n-1; ++i){
        for(int j=0; j<m; ++j){
            int cursrc=edges[j][0], curdest=edges[j][1], curweight=edges[j][2];
            if(dist[cursrc]!=1e9&&(dist[cursrc]+curweight<dist[curdest])){
                dist[curdest]=dist[cursrc]+curweight;
            }
        }
    }
    bool flag=false;
    for(int j=0; j<m; ++j){
        int cursrc=edges[j][0], curdest=edges[j][1], curweight=edges[j][2];
        if(dist[cursrc]!=1e9&&(dist[cursrc]+curweight<dist[curdest])){
            flag=true;
            break;
        }
    }
    if(flag) return 1e9;
    return dist[dest];
}
