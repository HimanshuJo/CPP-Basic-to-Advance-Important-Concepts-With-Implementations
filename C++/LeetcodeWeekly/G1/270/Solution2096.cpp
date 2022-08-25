// 2096. Step-By-Step Directions From a Binary Tree Node to Another
/*
You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. 
You are also given an integer startValue representing the value of the start node s, and a different integer 
destValue representing the value of the destination node t.

Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such 
path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

'L' means to go from a node to its left child node.
'R' means to go from a node to its right child node.
'U' means to go from a node to its parent node.
Return the step-by-step directions of the shortest path from node s to node t.

Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
Output: "UURL"
Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
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
    
    struct TreeNode *findLCA(struct TreeNode* root, int n1, int n2)
    {
        if (root == NULL) return NULL;
        if (root->val == n1 || root->val == n2)
            return root;
        TreeNode *left_lca  = findLCA(root->left, n1, n2);
        TreeNode *right_lca = findLCA(root->right, n1, n2);
        if (left_lca && right_lca)  return root;
        return (left_lca != NULL)? left_lca: right_lca;
    }
    
    int dfs(TreeNode* root, int target){
        if(root==nullptr) return -1;
        int dist = -1;
        if ((root->val==target)||(dist=dfs(root->left, target))>=0||(dist=dfs(root->right, target))>=0)
            return dist + 1;
        return dist;
    }
    
    bool dfs2(TreeNode *root, vector<int>&arr, int x)
    {
        if (!root)
            return false;
        arr.push_back(root->val);   
        if (root->val == x)   
            return true;
        if (dfs2(root->left, arr, x) ||
            dfs2(root->right, arr, x))
            return true;  
        arr.pop_back();
        return false;           
    }
    
    void bfs(TreeNode* root, vector<int>&arr, string &ans){
        queue<TreeNode*>q;
        q.push(root);
        int cnt=1;
        int currVal=arr[cnt];
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left!=nullptr&&curr->left->val==currVal){
                ans+='L';
                q.push(curr->left);
                cnt++;
                if(cnt>=arr.size()) break;
                currVal=arr[cnt];
            } else if(curr->right!=nullptr&&curr->right->val==currVal){
                ans+='R';
                q.push(curr->right);
                cnt++;
                if(cnt>=arr.size()) break;
                currVal=arr[cnt];
            }
        }
    }
    
    bool lftDfs(TreeNode* root, int target){
        if(root==nullptr) return false;
        if(root->val==target) return true;
        return lftDfs(root->left, target);
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lcaNode=findLCA(root, startValue, destValue);
        int cnt=0;
        if(lcaNode->val==startValue){
            cnt=dfs(lcaNode, destValue);
            bool chkLeft=lftDfs(lcaNode, destValue);
            if(chkLeft){
                string ans="";
                for(int i=0; i<cnt; ++i){
                    ans+='L';
                }
                return ans;   
            } else{
                string ans="";
                for(int i=0; i<cnt; ++i){
                    ans+='R';
                }
            }
        }
        if(lcaNode->val==destValue){
            cnt=dfs(lcaNode, startValue);
            string ans="";
            for(int i=0; i<cnt; ++i){
                ans+='U';
            }
            return ans;
        }
        int strtNodeDpth=0;
        string ans="";
        strtNodeDpth=dfs(lcaNode, startValue);
        for(int i=0; i<strtNodeDpth; ++i){
            ans+='U';
        }
        vector<int>path;
        dfs2(lcaNode, path, destValue);
        bfs(lcaNode, path, ans);
        return ans;
    }
};