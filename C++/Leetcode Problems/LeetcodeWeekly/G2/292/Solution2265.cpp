// 2265. Count Nodes Equal to Average of Subtree
/*
Given the root of a binary tree, return the number of nodes 
where the value of the node is equal to the average of the values in its subtree.

Note:

The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.

Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.

Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.

Constraints:

The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000
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

//O(n)
class Solution {
public:
    
    pair<int, int> dfs(TreeNode *curroot, int &ans){
        if(curroot==nullptr) return{0, 0};
        auto left=dfs(curroot->left, ans);
        int l_sum=left.first, l_count=left.second;
        auto right=dfs(curroot->right, ans);
        int r_sum=right.first, r_count=right.second;
        int sum=curroot->val+l_sum+r_sum;
        int count=1+l_count+r_count;
        if(curroot->val==sum/count) ans++;
        return {sum, count};
    }
    
    void postOrder(TreeNode *root, int &ans){
        dfs(root, ans);
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        postOrder(root, ans);
        return ans;
    }
};

//O(n^2)
class Solution2 {
public:
    
    pair<int, int> bfs(TreeNode *curroot){
        queue<TreeNode*>que;
        int sm=curroot->val;
        int count=1;
        que.push(curroot);
        while(!que.empty()){
            int sz=que.size();
            while(sz--){
                TreeNode *curnode=que.front();
                que.pop();
                if(curnode->left!=nullptr){
                    count++;
                    sm+=curnode->left->val;
                    que.push(curnode->left);
                }
                if(curnode->right!=nullptr){
                    count++;
                     sm+=curnode->right->val;
                    que.push(curnode->right);
                }
            }
        }
        return {sm, count};
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode *curnode=q.front();
                q.pop();
                int val=curnode->val;
                pair<int, int> temp_=bfs(curnode);
                int tochk=temp_.first/temp_.second;
                if(tochk==val){
                    ans++;
                }
                if(curnode->left!=nullptr){
                    q.push(curnode->left);
                }
                if(curnode->right!=nullptr){
                    q.push(curnode->right);
                }   
            }
        }
        return ans;
    }
};

//-------*******-------

// O(n^2)
class Solution3 {
public:
    
    int dfs2(TreeNode *curroot, int &count){
        if(curroot==nullptr) return 0;
        count++;
        int left=dfs2(curroot->left, count);
        int right=dfs2(curroot->right, count);
        return (curroot->val+left+right);
    }
    
    int calSum(TreeNode *root, int &count){
        return dfs2(root, count);
    }
    
    void dfs1(TreeNode *curroot, int &ans){
        if(curroot==nullptr) return;
        int count=0;
        int avg=(calSum(curroot, count))/count;
        if(avg==curroot->val) ans++;
        dfs1(curroot->left, ans);
        dfs1(curroot->right, ans);
    }
    
    void preOrder(TreeNode *root, int &ans){
        dfs1(root, ans);
    }
    
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        preOrder(root, ans);
        return ans;
    }
};