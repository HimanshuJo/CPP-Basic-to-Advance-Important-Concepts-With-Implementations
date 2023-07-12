// 2415. Reverse Odd Levels of Binary Tree
/*
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.

Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.

Input: root = [7,13,11]
Output: [7,11,13]
Explanation: 
The nodes at level 1 are 13, 11, which are reversed and become 11, 13.
Example 3:

Input: root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
Output: [0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
Explanation: 
The odd levels have non-zero values.
The nodes at level 1 were 1, 2, and are 2, 1 after the reversal.
The nodes at level 3 were 1, 1, 1, 1, 2, 2, 2, 2, and are 2, 2, 2, 2, 1, 1, 1, 1 after the reversal.
 

Constraints:

The number of nodes in the tree is in the range [1, 2^14].
0 <= Node.val <= 10^5
root is a perfect binary tree.
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
    
    TreeNode* createBTree(vector<int>&vec){
        TreeNode *fnroot=new TreeNode();
        fnroot->val=vec[0];
        queue<TreeNode*>q;
        q.push(fnroot);
        int idx=1;
        int sz=vec.size();
        while(!q.empty()){
            int sz_=q.size();
            while(sz_--){
                TreeNode *curr=q.front();
                q.pop();
                curr->left=new TreeNode(vec[idx]);
                idx++;
                curr->right=new TreeNode(vec[idx]);
                idx++;
                q.push(curr->left);
                q.push(curr->right);
                if(idx>=sz) break;
            }
            if(idx>=sz) break;
        }
        return fnroot;
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root->left==root->right&&root->left==nullptr) return root;
        queue<TreeNode*>q;
        int count=1;
        q.push(root);
        vector<int>temp;
        temp.push_back(root->val);
        while(!q.empty()){
            int sz=q.size();
            vector<int>antemp;
            while(sz--){
                TreeNode *curr=q.front();
                q.pop();
                if(curr->left!=nullptr&&curr->right!=nullptr){
                    q.push(curr->left);
                    antemp.push_back(curr->left->val);
                    q.push(curr->right);
                    antemp.push_back(curr->right->val);
                }
            }
            if(count%2!=0){
                reverse(antemp.begin(), antemp.end());
                for(auto &vals: antemp){
                    temp.push_back(vals);
                }
            } else{
                for(auto &vals: antemp){
                    temp.push_back(vals);
                }
            }
            count++;
        }
        return createBTree(temp);
    }
};