// 1766. Tree of Coprimes
/*
There is a tree (i.e., a connected, undirected graph that has no cycles) consisting of n nodes numbered 
from 0 to n - 1 and exactly n - 1 edges. 

Each node has a value associated with it, and the root of the tree is node 0.

To represent this tree, you are given an integer array nums and a 2D array edges. 

Each nums[i] represents the ith node's value, and each edges[j] = [uj, vj] 
represents an edge between nodes uj and vj in the tree.

Two values x and y are coprime if gcd(x, y) == 1 where gcd(x, y) is the 
greatest common divisor of x and y.

An ancestor of a node i is any other node on the shortest path from node i to the root. 
A node is not considered an ancestor of itself.

Return an array ans of size n, where ans[i] is the closest ancestor to node i such that 
nums[i] and nums[ans[i]] are coprime, or -1 if there is no such ancestor.

Input: nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
Output: [-1,0,0,1]
Explanation: In the above figure, each node's value is in parentheses.
- Node 0 has no coprime ancestors.
- Node 1 has only one ancestor, node 0. Their values are coprime (gcd(2,3) == 1).
- Node 2 has two ancestors, nodes 1 and 0. Node 1's value is not coprime (gcd(3,3) == 3), but node 0's
  value is (gcd(2,3) == 1), so node 0 is the closest valid ancestor.
- Node 3 has two ancestors, nodes 1 and 0. It is coprime with node 1 (gcd(3,2) == 1), so node 1 is its
  closest valid ancestor.

Input: nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
Output: [-1,0,-1,0,0,0,-1]

Constraints:

nums.length == n
1 <= nums[i] <= 50
1 <= n <= 10^5
edges.length == n - 1
edges[j].length == 2
0 <= uj, vj < n
uj != vj
*/

/*
Algorithm:

Please notice in the constraints that all node values is in range 1..50.

We create an array of 51 elements path[51] where path[x] contains list of nodes from root to 
current node which their node's value are equal to x.

While traversing nodes using DFS, for current node we can check all paths path[x] 
(up to 50) where x and current node are co-prime then we try to pick the node which is close to current node as our ancestor.

A node is close to current node if its depth is largest.

Complexity:

Time: O(50 * N)
Space: O(N)
*/

class Pair{
    public:
    int index, depth;
    
    Pair(int idx, int dpth): index{idx}, depth{dpth}{}
};


class Solution {
public:
    
    vector<int>res;
    
    int gcd(int a, int b){
        if(b==0) return a;
        return (gcd(b, a%b));
    }
    
    void dfs(vector<int>gr[], vector<Pair>path[], vector<int>&nums, int src, int pre, int curDepth){
        int closestIdx=-1, maxDepth=-1;
        for(int i=1; i<=50; ++i){
            if(gcd(nums[src], i)==1&&path[i].size()>0&&path[i][path[i].size()-1].depth>maxDepth){
                closestIdx=path[i][path[i].size()-1].index;
                maxDepth=path[i][path[i].size()-1].depth;
            }
        }
        res[src]=closestIdx;
        path[nums[src]].push_back({src, curDepth});
        for(int nei: gr[src]){
            if(nei==pre) continue;
            dfs(gr, path, nums, nei, src, curDepth+1);
        }
        path[nums[src]].pop_back();
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        res.resize(n);
        vector<Pair>path[51];
        vector<int>gr[n];
        for(auto &edge: edges){
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        dfs(gr, path, nums, 0, -1, 0);
        return res;
    }
};