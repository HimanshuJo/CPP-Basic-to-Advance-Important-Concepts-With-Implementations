/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the 
answer must be a reference to a node in the cloned tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({original, cloned});
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr.first == target)
                return curr.second;
            if (curr.first->left)
                q.push({curr.first->left, curr.second->left});
            if (curr.first->right)
                q.push({curr.first->right, curr.second->right});
        }
        return NULL;
    }
};

// -------*******-------

class Solution2
{

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        queue<TreeNode *> q;
        q.push(cloned);
        int val = target->val;
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->val == val)
                return curr;
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
        return NULL;
    }
};