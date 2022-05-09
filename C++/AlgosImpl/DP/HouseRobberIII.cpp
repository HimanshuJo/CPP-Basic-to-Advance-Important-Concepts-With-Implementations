/*
The thief has found himself a new place for his thievery again. 
There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that all houses in this place form a binary tree. 

It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without 
alerting the police.

Input: root = [3,2,3,null,3,null,1]
Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Input: root = [3,4,5,1,3,null,1]
Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
0 <= Node.val <= 10^4
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
    
    int dfs(TreeNode *root, int &ans, int curans, map<TreeNode*, int>&memo){
        if(root==nullptr) return 0;
        if(memo.find(root)!=memo.end()) return memo[root];
        
        curans=max((root->val)+
                  (root->left!=nullptr&&root->left->left!=nullptr?dfs(root->left->left, ans, curans, memo):0)+
                  (root->left!=nullptr&&root->left->right!=nullptr?dfs(root->left->right, ans, curans, memo):0)+
                  (root->right!=nullptr&&root->right->left!=nullptr?dfs(root->right->left, ans, curans, memo):0)+
                  (root->right!=nullptr&&root->right->right!=nullptr?dfs(root->right->right, ans, curans, memo):0),
                  
                  (root->left!=nullptr?dfs(root->left, ans, curans, memo):0)+
                  (root->right!=nullptr?dfs(root->right, ans, curans, memo):0)
                  );
        
        ans=max(ans, curans);
        return memo[root]=curans;
    }
    
    int rob(TreeNode* root) {
        map<TreeNode*, int>memo;
        int ans=0, curans=0;
        dfs(root, ans, curans, memo);
        return ans;
   