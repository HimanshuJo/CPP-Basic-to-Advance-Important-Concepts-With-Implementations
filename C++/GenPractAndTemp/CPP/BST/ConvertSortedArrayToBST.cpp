// 108. Convert Sorted Array to Binary Search Tree
/*
    Given an integer array nums where the elements are sorted in ascending order, 
    convert it to a height-balanced binary search tree.

    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of 
    every node never differs by more than one.

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
*/

#include<vector>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    TreeNode* dfs(vector<int>&nums, int bgn, int end){
        if(bgn>end) return nullptr;
        int mid=bgn+(end-bgn)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=dfs(nums, bgn, mid-1);
        root->right=dfs(nums, mid+1, end);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz=nums.size();
        return dfs(nums, 0, sz-1);
    }
};