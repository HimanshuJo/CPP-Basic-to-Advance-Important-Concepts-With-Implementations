// 2049. Count Nodes With the Highest Score
/*
There is a binary tree rooted at 0 consisting of n nodes. 
The nodes are labeled from 0 to n - 1. You are given a 0-indexed integer array parents representing the tree, 
where parents[i] is the parent of node i. Since node 0 is the root, parents[0] == -1.

Each node has a score. To find the score of a node, consider if the node and the edges connected to it 
were removed. 
The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. 
The score of the node is the product of the sizes of all those subtrees.

Return the number of nodes that have the highest score.

Input: parents = [-1,2,0,2,0]
Output: 3 
Explanation:
- The score of node 0 is: 3 * 1 = 3
- The score of node 1 is: 4 = 4
- The score of node 2 is: 1 * 1 * 2 = 2
- The score of node 3 is: 4 = 4
- The score of node 4 is: 4 = 4
The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int src, vector<vector<int>>&gr, vector<int>&sizes){
        int ans=1;
        for(auto &child: gr[src]){
            ans+=dfs(child, gr, sizes);
        }
        return sizes[src]=ans;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<int>sizes(n, 0);
        vector<vector<int>>gr(n);
        for(int i=1; i<n; ++i){
            gr[parents[i]].push_back(i);
        }
        dfs(0, gr, sizes);
        long long cnt=0, maxx=0;
        for(int i=0; i<n; ++i){
            long long prod=1;
            prod=max(prod, (long long) n-sizes[i]);
            for(auto &node: gr[i]){
                prod=prod*sizes[node];
            }
            if(prod>maxx){
                maxx=prod;
                cnt=1;
            } else if(prod==maxx){
                cnt++;
            }
        }
        return cnt;
    }
};