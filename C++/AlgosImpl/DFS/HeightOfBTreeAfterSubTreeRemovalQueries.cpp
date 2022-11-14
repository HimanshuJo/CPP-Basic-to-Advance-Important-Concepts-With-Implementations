// 2458. Height of Binary Tree After Subtree Removal Queries
/*
You are given the root of a binary tree with n nodes. Each node is assigned a unique value 
from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. 
It is guaranteed that queries[i] will not be equal to the value of the root.

Return an array answer of size m where answer[i] is the height of the tree after 
performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the 
root to some node in the tree.

Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).

Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).

Constraints:

The number of nodes in the tree is n.
2 <= n <= 10^5
1 <= Node.val <= n
All the values in the tree are unique.
m == queries.length
1 <= m <= min(n, 10^4)
1 <= queries[i] <= n
queries[i] != root.val
*/

/*
Algo:

Each node has a depth and height. The longest path passing it has a length equals depth + height.

	E.g.

						A
					  /   \
					 B     C
					/ \   / \
				   D   E F   G
				  /         / \
				 H         I   J
				/ \
			   K   L

	    Example: 
	    	Node D has a depth of 2 and height of 2

	    	The longest path passing through it has a length of 4
				K->H->D->B->A or L->H->D->B->A

			Node G has a depth of 2 and height of 1

			The longest path passing through has a length of 3
				J->G->C->A or I->G->C->A

When a node (Let's say D) is removed, all of its children are removed as well. 
So every path that goes through D stops by here. 

However, if D has some cousins, then the paths through these cousins will certainly be longer.

We should look for the longest path among these paths through the cousins of D, 
which is equivalent to finding the cousin with the largest height.

Therefore, we store the nodes according to depth. 
For nodes having the same depth, we sort them by their heights and only keep the top 2 of 
them that having the maximum depth.

Once we 'remove' a node from queries, we locate all of its cousins, find the one with 
the maximum height and the job is done.

If the size of cousins[depth] is 1, which means that the removed node has no cousin, 
so the longest resting path equals depth - 1.
Otherwise, at least one of them is the cousin, we get its depth.

Time O(N)
Space O(N)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int dfs(TreeNode *root, map<int, int>&depths, map<int, int>&heights, int curDepth){
        if(root==nullptr) return -1;
        depths[root->val]=curDepth;
        int curHeight=max(1+dfs(root->left, depths, heights, curDepth+1), 1+dfs(root->right, depths, heights, curDepth+1));
        heights[root->val]=curHeight;
        return curHeight;
    }
    
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<int, int>depths, heights;
        map<int, vector<pair<int, int>>>cousins;
        dfs(root, depths, heights, 0);
        for(auto &entries: depths){
            cousins[entries.second].push_back({heights[entries.first]*-1, entries.first});
            sort(cousins[entries.second].begin(), cousins[entries.second].end());
            if(cousins[entries.second].size()>2){
                cousins[entries.second].pop_back();
            }
        }
        vector<int>ans;
        for(auto &vals: queries){
            int curDepth=depths[vals];
            if(cousins[curDepth].size()==1){
                ans.push_back(curDepth-1);
            } else if(cousins[curDepth][0].second==vals){
                ans.push_back(-cousins[curDepth][1].first+curDepth);
            } else{
                ans.push_back(-cousins[curDepth][0].first+curDepth);
            }
        }
        return ans;
    }
};