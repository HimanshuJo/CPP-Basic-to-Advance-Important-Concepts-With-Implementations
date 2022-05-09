// 2196. Create Binary Tree From Descriptions
/*
You are given a 2D integer array descriptions where 
descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi 
in a binary tree of unique values. Furthermore,

If isLefti == 1, then childi is the left child of parenti.
If isLefti == 0, then childi is the right child of parenti.
Construct the binary tree described by descriptions and return its root.

The test cases will be generated such that the binary tree is valid

Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
Output: [50,20,80,15,17,19]
Explanation: The root node is the node with value 50 since it has no parent.
The resulting binary tree is shown in the diagram.

Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
Output: [1,2,null,null,3,4]
Explanation: The root node is the node with value 1 since it has no parent.
The resulting binary tree is shown in the diagram.

Constraints:

1 <= descriptions.length <= 10^4
descriptions[i].length == 3
1 <= parenti, childi <= 10^5
0 <= isLefti <= 1
The binary tree described by descriptions is valid.
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
    
    void bfs(TreeNode *root, map<int, pair<int, int>>&mp1){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp=q.front();
            q.pop();
            int topr=temp->val;
            pair<int, int>entries=mp1[topr];
            if(entries.first!=0){
                TreeNode *lftN=new TreeNode();
                lftN->val=entries.first;
                lftN->left=lftN->right=nullptr;
                temp->left=lftN;
                q.push(lftN);
            }
            if(entries.second!=0){
                TreeNode *rghtN=new TreeNode();
                rghtN->val=entries.second;
                rghtN->left=rghtN->right=nullptr;
                temp->right=rghtN;
                q.push(rghtN);
            }
        }
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, pair<int, int>>mp1;
        map<int, int>mp2;
        int root_;
        for(auto &vals: descriptions){
            if(vals[2]==1){
                mp1[vals[0]].first=vals[1];
                mp2[vals[1]]=vals[0];
            } else{
                mp1[vals[0]].second=vals[1];
                mp2[vals[1]]=vals[0];
            }
        }
        for(auto &entries: mp1){
            if(mp2.find(entries.first)==mp2.end()){
                root_=entries.first;
                break;
            }
        }
        TreeNode *root=new TreeNode();
        root->val=root_;
        root->left=root->right=nullptr;
        bfs(root, mp1);
        return root;
    }
};