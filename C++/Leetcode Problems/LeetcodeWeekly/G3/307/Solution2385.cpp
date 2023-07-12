// 2385. Amount of Time for Binary Tree to Be Infected
/*
You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.

Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.

Constraints:

The number of nodes in the tree is in the range [1, 10^5].
1 <= Node.val <= 10^5
Each node has a unique value.
A node with a value of start exists in the tree.
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
    
    void preOrder(TreeNode *root, vector<vector<int>>&gr){
        if(root->left!=nullptr){
            gr[root->val].push_back(root->left->val);
            gr[root->left->val].push_back(root->val);
            preOrder(root->left, gr);
        }
        if(root->right!=nullptr){
            gr[root->val].push_back(root->right->val);
            gr[root->right->val].push_back(root->val);
            preOrder(root->right, gr);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>>gr(1e5+1);
        vector<int>seen(1e5+1, -1);
        preOrder(root, gr);
        queue<int>q;
        q.push(start);
        seen[start]=1;
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                for(auto &nei: gr[curr]){
                    if(seen[nei]==-1){
                        q.push(nei);
                        seen[nei]=1;
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};

// -------*******-------

class Solution2 {
public:
    
    pair<bool, int> dfs(TreeNode *root, int start, int &res){
        if(!root) return {false, 0};
        /*
            return type pair states whether we came across start or not and maximum distance
            in this call
        */
        pair<bool, int>p1=dfs(root->left, start, res);
        pair<bool, int>p2=dfs(root->right, start, res);
        /*
            if we find the node then the maximum distance for now will be the maximum of 2 dfs
            calls and we will send the current distance as 0 to its parent(if exists)
        */
        if(root->val==start){
            int temp=max(p2.second, p1.second);
            res=max(res, temp);
            return {true, 0};
        }
        if(p1.first){
            int sum=p1.second+p2.second+1;
            res=max(res, sum);
            return {true, p1.second+1};
        } else if(p2.first){
            int sum=p1.second+p2.second+1;
            res=max(res, sum);
            return {true, p2.second+1};
        }
        int sum=max(p1.second, p2.second);
        return {false, 1+sum};
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int res=0;
        dfs(root, start, res);
        return res;
    }
};