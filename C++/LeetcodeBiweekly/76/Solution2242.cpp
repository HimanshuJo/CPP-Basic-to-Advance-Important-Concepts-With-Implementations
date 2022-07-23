// 2242. Maximum Score of a Node Sequence
/*
There is an undirected graph with n nodes, numbered from 0 to n - 1.

You are given a 0-indexed integer array scores of length n where scores[i] 
denotes the score of node i. 

You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes 
that there exists an undirected edge connecting nodes ai and bi.

A node sequence is valid if it meets the following conditions:

There is an edge connecting every pair of adjacent nodes in the sequence.
No node appears more than once in the sequence.
The score of a node sequence is defined as the sum of the scores of the nodes in the sequence.

Return the maximum score of a valid node sequence with a length of 4. If no such sequence exists, return -1.

Input: scores = [5,2,9,8,4], edges = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
Output: 24
Explanation: The figure above shows the graph and the chosen node sequence [0,1,2,3].
The score of the node sequence is 5 + 2 + 9 + 8 = 24.
It can be shown that no other node sequence has a score of more than 24.
Note that the sequences [3,1,2,0] and [1,0,2,3] are also valid and have a score of 24.
The sequence [0,3,2,4] is not valid since no edge connects nodes 0 and 3.

Input: scores = [9,20,6,4,11,12], edges = [[0,3],[5,3],[2,4],[1,3]]
Output: -1
Explanation: The figure above shows the graph.
There are no valid node sequences of length 4, so we return -1.

Constraints:

n == scores.length
4 <= n <= 5 * 10^4
1 <= scores[i] <= 10^8
0 <= edges.length <= 5 * 10^4
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no duplicate edges.
*/

/*
The idea: 

    Try every edge, and select one more adjacent node per each of the edge ends.
    
    The selected additional nodes must not be intersected with each other and with the other edge nodes.
    
    Also there must be effective way to select additional nodes, so they provide max result. 

    To achieve this - we can sort the adjacency list for each vertice (according to scores).

        We must try 3 best nodes for each of the edge side (because they are optimal, 
        and if we try just 1 or 2 best nodes - there could be intersections - which is not allowed) - 
        so try at most 9 combinations per each edge.

Optimization: as we need just 3 top scored neighbours per each edge side - 
instead of full adjacency list sorting we can utilize a PriorityQueue to find top 3 nodes - 
this will decrease our time complexity from O(E log(E)) to O(E)

-------

Create adjacency list
Sort adjacency list, so best adjacent nodes are in the beginning

2.1 Optimized: no need to sort the full list - we need just 3 top scored adjacent nodes - 
so use PriorityQueue, find top 3 adjacent nodes

Try each edge:

try <= 3 best adjacent nodes for each edge side. If no intersections - we have a sequence of 4 nodes (the current edge is in the middle), update result.
Time complexity:

O(E log(E)) for adjacency list sorting

O(E*9) = O(E) for iterating over edges

Total: O(E log(E))

E is edges count
*/

/*
TLE: 39 / 74

class Solution {
public:
    
    map<int, vector<vector<int>>>mp;
    vector<bool>seen;
    
    void dfs(vector<vector<pair<int, int>>>&gr, int curnode, vector<int>curr, vector<int>&scores, int curscore){
        seen[curnode]=true;
        for(auto &vals: gr[curnode]){
            if(!seen[vals.second]){
                if(curr.size()>=1){
                    int lstnode=curr[curr.size()-1];
                    auto it=find(gr[lstnode].begin(), gr[lstnode].end(), make_pair(scores[vals.second], vals.second));
                    if(it!=gr[lstnode].end()){
                        curscore+=scores[vals.second];
                        curr.push_back(vals.second);
                        dfs(gr, vals.second, curr, scores, curscore);
                        curscore-=scores[curr[curr.size()-1]];
                        curr.pop_back();
                        dfs(gr, vals.second, curr, scores, curscore);       
                    }
                } else{
                    curscore+=scores[vals.second];
                    curr.push_back(vals.second);
                    dfs(gr, vals.second, curr, scores, curscore);
                    curscore-=scores[curr[curr.size()-1]];
                    curr.pop_back();
                    dfs(gr, vals.second, curr, scores, curscore); 
                }
            }
        }
        seen[curnode]=false;
        if(curr.size()==4){
            mp[curscore].push_back(curr);
        }
        return;   
    }
    
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int sz=scores.size();
        vector<vector<pair<int, int>>>gr(sz);
        seen.resize(sz, false);
        for(auto &vals: edges){
            gr[vals[0]].push_back({scores[vals[1]], vals[1]});
            gr[vals[1]].push_back({scores[vals[0]], vals[0]});
        }
        for(int i=0; i<sz; ++i){
            vector<pair<int, int>>&entries=gr[i];
            sort(entries.begin(), entries.end(), greater<>());
            if(entries.size()>3){
                vector<pair<int, int>>temp;
                for(auto &vals: entries){
                    temp.push_back(vals);
                    if(temp.size()==3) break;
                }
                gr[i]=temp;
            }
        }
        for(int i=0; i<sz; ++i){
            if(!seen[i]){
                vector<int>curr;
                curr.push_back(i);
                int curscore=scores[i];
                dfs(gr, i, curr, scores, curscore);
            }
        }
        if(mp.size()>=1){
            auto it=mp.rbegin();
            return it->first;
        }
        return -1;
    }
};
*/

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int n=scores.size();
        vector<vector<int>>adj(n);
        for(const vector<int>&edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(vector<int>&a: adj){
            sort(a.begin(), a.end(), [&scores](const int l, const int r){
                return scores[l]>scores[r];
            });
        }
        int res=-1;
        for(const vector<int>&edge: edges){
            int u=edge[0], v=edge[1];
            int base=scores[u]+scores[v];
            for(int i=0; i<min(3, (int)adj[u].size()); ++i){
                int x=adj[u][i];
                if(x==v) continue;
                for(int j=0; j<min(3, (int)adj[v].size()); ++j){
                    int y=adj[v][j];
                    if(y==u||x==y) continue;
                    res=max(res, base+scores[x]+scores[y]);
                }
            }
        }
        return res;
    }
};

// Solution2

class Solution2 {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int n=scores.size();
        vector<vector<int>>adj(n);
        for(const vector<int>&edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for(vector<int>&a: adj){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
            for(int v: a){
                int score=scores[v];
                if(pq.size()<3||pq.top().first<score){
                    pq.push({score, v});
                    if(pq.size()>3){
                        pq.pop();
                    }
                }
            }
            a.resize(pq.size());
            for(int i=a.size()-1; i>=0; --i){
                a[i]=pq.top().second;
                pq.pop();
            }
        }
        int res=-1;
        for(const vector<int>&edge: edges){
            int u=edge[0], v=edge[1];
            int base=scores[u]+scores[v];
            for(int x: adj[u]){
                if(x==v) continue;
                for(int y: adj[v]){
                    if(y==u||x==y) continue;
                    res=max(res, base+scores[x]+scores[y]);
                }
            }
        }
        return res;
    }
};