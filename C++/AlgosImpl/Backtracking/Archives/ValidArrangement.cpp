// 2097. Valid Arrangement of Pairs
/*
You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. 
An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.

Return any valid arrangement of pairs.

Example 1:

Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3

Example 2:

Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.

Example 3:

Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2
*/

/*
TLE:

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    void dfs(vector<vector<int>>&pairs, vector<vector<int>>&res, int n, int idx, vector<bool>&seen){
        if(idx>=n) return;
        if(res.size()==n) return;
        vector<int>curr=pairs[idx];
        for(int i=0; i<n; ++i){
            if(seen[i]!=true){
                vector<int>next=pairs[i];
                if(next[0]==curr[1]){
                    res.push_back(next);
                    seen[i]=true;
                    dfs(pairs, res, n, i, seen);
                }
            }
        }
		if(res.size()!=n){
            res.pop_back();
            seen[idx]=false;
        }
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>>res;
        int n=pairs.size();
        vector<bool>seen(n+1);
        for(int i=0; i<n; ++i){
            for(int i=0; i<n; ++i)
                seen[i]=false;
            res.push_back(pairs[i]);
            seen[i]=true;
            dfs(pairs, res, n, i, seen);
            if(res.size()==n) return res;
            res.clear();
            seen.clear();
        }
        return res;
    }
};
*/
/*
Solution:

Idea

if we view each start_i and end_i as nodes in a graph, elements in pairs as 
(directed) edges in the graph, then the problem is asking us to find a path in the corresponding directed graph.

the problem ask us to use up all edges, so we are basically asked to find a Eulerian Path, 
which is a path that walks through each edge exactly once.

Some properties of Eulerian path

Existence:

A graph has an Eulerian Path if and only if
    we have out[i] == in[i] for each node i. Or
    we have out[i] == in[i] for all nodes i except exactly two nodes x and y, 
    with out[x] = in[x] + 1, out[y] = in[y] - 1.

this problem guarantees that an Eulerian Path exists. So we don't need to check for its existence here.

In the first case (out[i] == in[i] for each node i), all Eulerian Paths are also Eulerian Circuits 
(Eulerian Path with starting point == ending point).

a node with out[i] == in[i] + 1 must be the starting point of an Eulerian Path (if there exists one)

Algorithm

find the starting point of an Eulerian Path.
if we have out[i] == in[i] for all i, we can start at an arbitrary node.
perform postorder DFS on the graph, as we "walk" through an edge, we erase (or mark it visited) the walked edge.
we may reach the same node many times, but we have to pass each edge exactly once.


*/

class Solution {
public:
    
    void euler(unordered_map<int, stack<int>>&adj, vector<vector<int>>&ans, int curr){
        auto &stk=adj[curr];
        while(!stk.empty()){
            int nei=stk.top();
            stk.pop();
            euler(adj, ans, nei);
            ans.push_back({curr, nei});
        }
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int m=pairs.size();
        unordered_map<int, stack<int>>adj;
        unordered_map<int, int>in, out;
        adj.reserve(m);
        in.reserve(m), out.reserve(m);
        for(int i=0; i<m; ++i){
            int u=pairs[i][0], v=pairs[i][1];
            in[v]++, out[u]++;
            adj[u].push(v);
        }
        int start=-1;
        for(auto &p: adj){
            int i=p.first;
            if(out[i]-in[i]==1) start=i;
        }
        if(start==-1){
            start=adj.begin()->first;
        }
        vector<vector<int>>ans;
        euler(adj, ans, start);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};