/*
    Find the lowest common ancestor of two nodes in a binary search tree
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || root -> val == p -> val || root -> val == q -> val) {
            return root;
        }
        else if (root -> val > q -> val && root -> val > p -> val) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        else if (root -> val < p -> val && root -> val < q -> val) {
            return lowestCommonAncestor(root -> right, p , q);
        }
        else return root;
    }
};