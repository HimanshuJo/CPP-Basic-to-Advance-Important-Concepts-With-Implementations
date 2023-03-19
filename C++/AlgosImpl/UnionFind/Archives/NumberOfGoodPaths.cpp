// 2421. Number of Good Paths
/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered 
from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the 
ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that 
there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the 
starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the 
same as 1 -> 0. A single node is also considered as a valid path.

Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].

Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.

Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.

Constraints:

n == vals.length
1 <= n <= 3 * 10^4
0 <= vals[i] <= 10^5
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.
*/

/*
TLE: 123 / 133

class Solution {
public:
    
    void bfs(vector<vector<int>>&gr, vector<int>&vals, int sz, int curnode, int &nwpath){
        vector<int>seen(sz, -1);
        queue<int>q;
        q.push(curnode);
        int cursz=1;
        seen[curnode]=1;
        int valtochk=vals[curnode];
        while(!q.empty()){
            int szz=q.size();
            while(szz--){
                int curr=q.front();
                if(curr!=curnode&&vals[curr]==valtochk){
                    nwpath++;
                }
                q.pop();
                for(auto &nei: gr[curr]){
                    if(vals[nei]<=valtochk&&seen[nei]==-1){
                        q.push(nei);
                        seen[nei]=1;
                    }
                }
            }
        }
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int sz=vals.size();
        vector<vector<int>>gr(sz+1);
        for(auto &vals: edges){
            gr[vals[0]].push_back(vals[1]);
            gr[vals[1]].push_back(vals[0]);
        }
        int ans=0;
        ans+=sz;
        int nwpath=0;
        for(int i=0; i<sz; ++i){
            bfs(gr, vals, sz, i, nwpath);
        }
        if(nwpath!=0)
            nwpath/=2;
        return ans+nwpath;
    }
};
*/

class Solution {
public:

    void initialize(int N, vector<int>&parent, vector<int>&sz){
        for(int i=0; i<N; ++i){
            parent[i]=i;
            sz[i]=1;
        }
    }

    int root(vector<int>&parent, vector<int>&sz, int node){
        if(parent[node]==node) return node;
        return (parent[node]=root(parent, sz, parent[node]));
    }

    void connect(vector<int>&parent, vector<int>&sz, int a, int b){
        a=root(parent, sz, a), b=root(parent, sz, b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a, b);
            }
            sz[a]+=sz[b];
            parent[b]=a;
        }
    }
    
    bool connected(vector<int>&parent, vector<int>&sz, int A, int B){
        return root(parent, sz, A)==root(parent, sz, B);
    }
    
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int N=vals.size();
        vector<int> parent(N+1), sz(N+1);
        int goodPaths=0;
        map<int, vector<int>>smVals;
        vector<vector<int>>adj(N+2);
        for(int i=0; i<N; ++i){
            smVals[vals[i]].push_back(i);
        }
        for(auto &e: edges){
            int u=e[0], v=e[1];
            if(vals[u]>=vals[v]){
                adj[u].push_back(v);
            } else if(vals[v]>=vals[u]){
                adj[v].push_back(u);
            }
        }
        initialize(N+1, parent, sz);
        for(auto &[_, allNodes]: smVals){
            for(auto u: allNodes){
                for(auto v: adj[u]){
                    connect(parent, sz, u, v);
                }
            }
            unordered_map<int, int>grp;
            for(auto u: allNodes){
                grp[root(parent, sz, u)]++;
            }
            goodPaths+=allNodes.size();
            for(auto &[_, size]: grp){
                goodPaths+=(size*(size-1)/2);
            }
        }
        return goodPaths;
    }
};
