// 235. Lowest Common Ancestor of a Binary Search Tree
/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between 
two nodes p and q as the lowest node in T that has both p and q as descendants 
(where we allow a node to be a descendant of itself).”

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.

Input: root = [2,1], p = 2, q = 1
Output: 2

Constraints:

The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the BST.
*/

#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    
    bool dfs(TreeNode *root, vector<TreeNode*>&path, int tochk){
        if(root==nullptr) return false;
        path.push_back(root);
        if(root->val==tochk){
            return true;
        }
        if(root->left&&dfs(root->left, path, tochk)){
            return true;
        } else if(root->right&&dfs(root->right, path, tochk)){
            return true;
        }
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *temp1=root;
        TreeNode *temp2=root;
        vector<TreeNode*>path1, path2;
        dfs(temp1, path1, p->val);
        dfs(temp2, path2, q->val);
        TreeNode *ans=nullptr;
        int i, j;
        for(i=0, j=0; i<path1.size()&&j<path2.size(); ++i, ++j){
            if(path1[i]->val!=path2[j]->val){
                break;
            }
            ans=path1[i];
        }
        return ans;
    }
};

// -------*******-------

class Solution {
public:
    
    TreeNode* dfs(TreeNode *root, TreeNode *p, TreeNode *q){
        if(root==nullptr) return nullptr;
        if(root->val>p->val&&root->val>q->val){
            return dfs(root->left, p, q);   
        }
        if(root->val<p->val&&root->val<q->val){
            return dfs(root->right, p, q);   
        }
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans=dfs(root, p, q);
        return ans;
    }
};