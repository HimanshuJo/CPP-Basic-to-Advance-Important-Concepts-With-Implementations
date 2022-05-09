// Blocked Roads
/*
You are given a directed graph with N vertices and M edges. The vertices are numbered 1 through N, 
and the edges are numbered 1 through M. Edge i (1≤i≤M) goes from Vertex si to Vertex ti and has a
length of 1.

For each i (1≤i≤M), find the shortest distance from Vertex 1 to Vertex N when all edges 
except Edge i are passable, or print -1 if Vertex N is unreachable from Vertex 1.

Sample Input 1 
3 3
1 2
1 3
2 3
Sample Output 1 
1
2
1

Sample Input 4 
4 1
1 2
Sample Output 4 
-1
*/
/*
Assume that we can reach from Vertex 1 to Vertex N on the original graph.

First, we find one shortest path from Vertex 1 to Vertex N on the original graph. 
The edges not included in this shortest path is not affected by being blocked.

Also, the shortest path has at most N−1 edges. 
Therefore, if one of the edges in the shortest path is blocked, 
we can naively compute the shortest distance in an O(N+M) time, as it requires only O(N(N+M)) 
time in total, which is fast enough.

Make sure to handle the exception where we cannot reach from 
Vertex 1 to Vertex N on the original graph.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> G(n, vector<int>(n, -1));
    vector<pair<int,int>> edge(m);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b; a--; b--;
        G[a][b] = i;
        edge[i] = make_pair(a,b);
    }
    vector<int> dis(n,-1); dis[0] = 0;
    vector<pair<int,int>> memo(n);
    queue<int> que; que.push(0);
    while(!que.empty()){
        int i = que.front(); que.pop();
        for(int j = 0; j < n; j++) if(dis[j] == -1 && G[i][j] != -1){
            dis[j] = dis[i] + 1;
            memo[j] = make_pair(i,G[i][j]);
            que.push(j);
        }
    }
    if(dis[n-1] == -1){
        for(int i = 0; i < m; i++) cout << -1 << endl;
        return 0;
    }
    vector<int> shortest_path;
    int cur = n-1;
    while(cur != 0){
        shortest_path.push_back(memo[cur].second);
        cur = memo[cur].first;
    }
    vector<int> ans(m, dis[n-1]);
    for(int e : shortest_path){
        G[edge[e].first][edge[e].second] = -1;
        queue<int> que; que.push(0);  
        vector<int> dis(n, -1); dis[0] = 0;
        while(!que.empty()){
            int i = que.front(); que.pop();
            for(int j = 0; j < n; j++) if(dis[j] == -1 && G[i][j] != -1){
                dis[j] = dis[i] + 1;
                que.push(j);
            }
        }
        ans[e] = dis[n-1];
        G[edge[e].first][edge[e].second] = e;
    }
    for(int x:ans)cout << x << endl;
}
