// Minimum Weighted Subgraph With the Required Paths
/*
You are given an integer n denoting the number of nodes of a weighted directed graph. 
The nodes are numbered from 0 to n - 1.

You are also given a 2D integer array edges where edges[i] = [fromi, toi, weighti] 
denotes that there exists a directed edge from fromi to toi with weight weighti.

Lastly, you are given three distinct integers src1, src2, and dest denoting three distinct nodes of the graph.

Return the minimum weight of a subgraph of the graph such that it is possible 
to reach dest from both src1 and src2 via a set of edges of this subgraph. 

In case such a subgraph does not exist, return -1.

A subgraph is a graph whose vertices and edges are subsets of the original graph. 
The weight of a subgraph is the sum of weights of its constituent edges.

Input: n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], 
src1 = 0, src2 = 1, dest = 5
Output: 9
Explanation:
The above figure represents the input graph.
The blue edges represent one of the subgraphs that yield the optimal answer.
Note that the subgraph [[1,0,3],[0,5,6]] also yields the optimal answer. 
It is not possible to get a subgraph with less weight satisfying all the constraints.

Input: n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
Output: -1
Explanation:
The above figure represents the input graph.
It can be seen that there does not exist any path from node 1 to node 2, 
hence there are no subgraphs satisfying all the constraints.

Constraints:

3 <= n <= 10^5
0 <= edges.length <= 10^5
edges[i].length == 3
0 <= fromi, toi, src1, src2, dest <= n - 1
fromi != toi
src1, src2, and dest are pairwise distinct.
1 <= weight[i] <= 10^5
*/

#define INF LONG_MAX
using ll=long long;

class Solution {
public:
    
    void djikstra(vector<vector<pair<ll, ll>>>&gr, vector<ll>&dist, int curSource){
        dist[curSource]=0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
        pq.push({0, curSource});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                pair<ll, ll>cur=pq.top();
                pq.pop();
                int curVert=cur.second;
                int curwt=cur.first;
                if(curwt>dist[curVert]) continue;
                for(auto &nei: gr[curVert]){
                    pair<ll, ll>curpair=nei;
                    int nwV=curpair.first, nwW=curpair.second;
                    if(dist[curVert]+nwW<dist[nwV]){
                        dist[nwV]=dist[curVert]+nwW;
                        pq.push({dist[nwV], nwV});
                    }
                }
            }
        }
    }
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<ll, ll>>>gr(n+1), revGr(n+1);
        for(auto &entries: edges){
		    gr[entries[0]].push_back({entries[1], entries[2]});
            revGr[entries[1]].push_back({entries[0], entries[2]});
	    }
        vector<ll>dista(n+1, INF), distb(n+1, INF), distd(n+1, INF);
        djikstra(gr, dista, src1);
        djikstra(gr, distb, src2);
        djikstra(revGr, distd, dest);
        ll ans=INF;
        for(int i=0; i<n; ++i){
            if(dista[i]==INF||distb[i]==INF||distd[i]==INF) continue;
            ans=min(ans, dista[i]+distb[i]+distd[i]);
        }
        return ans==INF?-1:ans;
    }
};