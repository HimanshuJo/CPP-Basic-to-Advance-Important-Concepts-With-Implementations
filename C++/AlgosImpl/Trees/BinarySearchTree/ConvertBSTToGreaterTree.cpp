// 538. Convert BST to Greater Tree
/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such 
that every key of the original BST is changed to the original key plus the sum of all 
keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.

Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
Example 2:

Input: root = [0,null,1]
Output: [1,null,1]

Constraints:

The number of nodes in the tree is in the range [0, 10^4].
-104 <= Node.val <= 10^4
All the values in the tree are unique.
root is guaranteed to be a valid binary search tree.
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

/*
Solution2:

class Solution {
public:
    
    int sum=0;
    
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *temp=root;
        stack<TreeNode*>st;
        while(!st.empty()||temp!=nullptr){
            while(temp!=nullptr){
                st.push(temp);
                temp=temp->right;
            }
            temp=st.top();
            st.pop();
            sum+=temp->val;
            temp->val=sum;
            temp=temp->left;
        }
        return root;
    }
};
*/

/*
Algorithm

	For the recursive approach, we maintain some minor "global" state so each recursive call 
	can access and modify the current total sum. 

	Essentially, we ensure that the current node exists, recurse on the right subtree, 
	visit the current node by updating its value and the total sum, and finally recurse on the left subtree. 

	If we know that recursing on root.right properly updates the right subtree and that recursing on root.left 
	properly updates the left subtree, then we are guaranteed to update all nodes with larger values before the 
	current node and all nodes with smaller values after.

-------

Complexity Analysis

Time complexity : O(n)

A binary tree has no cycles by definition, so convertBST gets called on each node no more than once.
 Other than the recursive calls, convertBST does a constant amount of work, so a linear number of calls to 
 convertBST will run in linear time.

Space complexity : O(n)

Using the prior assertion that convertBST is called a linear number of times, we can also show that the 
entire algorithm has linear space complexity.

Consider the worst case, a tree with only right (or only left) subtrees. 
The call stack will grow until the end of the longest path is reached, which in this case includes all n nodes.
*/

class Solution {
public:
    
    int sum=0;
    
    void dfs(TreeNode *root){
        if(root!=nullptr){
            dfs(root->right);
            sum+=root->val;
            root->val=sum;
            dfs(root->left);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
};
