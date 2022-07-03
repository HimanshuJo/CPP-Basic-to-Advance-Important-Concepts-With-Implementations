// 230. Kth Smallest Element in a BST
/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) 
of all the values of the nodes in the tree.

Input: root = [3,1,4,null,2], k = 1
Output: 1

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 10^4
0 <= Node.val <= 10^4

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you 
need to find the kth smallest frequently, how would you optimize?
*/

#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(H+k)
/*
    where H is a tree height. 
    This complexity is defined by the stack, which contains at least H + k elements, 
    since before starting to pop out one has to go down to a leaf. 
    
    This results in O(logN+k) for the balanced tree and O(N+k) for completely unbalanced tree 
    with all the nodes in the left subtree.
*/
// SC: O(H)
/*
    O(H) to keep the stack, where H is a tree height. 
    That makes O(N) in the worst case of the skewed tree, 
    and O(logN) in the average case of the balanced tree.
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        deque<TreeNode*>dq;
        while(true){
            while(root!=nullptr){
                dq.push_back(root);
                root=root->left;
            }
            root=dq.back();
            dq.pop_back();
            if(--k==0) return root->val;
            root=root->right;
        }
        return root->val;
    }
};

// TC: O(N)  N: number of nodes in the tree
// SC: O(N)
class Solution1 {
public:
    
    void dfs(TreeNode* root, vector<int>&inorder){
        if(root==nullptr) return;
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorder;
        dfs(root, inorder);
        return inorder[k-1];
    }
};

// TC: O(NlogN)  N: number of nodes in the tree
// SC: O(N)
class Solution2 {
public:
    
    void dfs(TreeNode *root, vector<int>&preOrder){
        if(root==nullptr) return;
        preOrder.push_back(root->val);
        if(root->left) dfs(root->left, preOrder);
        if(root->right) dfs(root->right, preOrder);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int>preOrder;
        dfs(root, preOrder);
        sort(preOrder.begin(), preOrder.end());
        return preOrder[k-1];
    }
};

// TC: O(NlogN)  N: number of nodes in the tree
// SC: O(N)
class Solution3 {
public:
    
    void dfs(TreeNode *root, priority_queue<int, vector<int>, greater<>>&pq){
        if(root==nullptr) return;
        pq.push(root->val);
        dfs(root->left, pq);
        dfs(root->right, pq);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<>>pq;
        dfs(root, pq);
        int count=0, ans=0;
        while(!pq.empty()){
            ans=pq.top();
            count++;
            if(count==k) break;
            pq.pop();
        }
        return ans;
    }
};