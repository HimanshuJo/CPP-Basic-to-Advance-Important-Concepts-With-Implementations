#include<vector>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

class Node{
    public:
    int val;
    Node *left, *right;
};

Node* createNode(int data){
    Node *nwNode=new Node();
    nwNode->val=data;
    nwNode->left=nwNode->right=nullptr;
    return nwNode;
}

class Solution {
public:
    
    int ans=0;
    
    void insert(Node ** pRoot, int val)
    {
        if(*pRoot==NULL)
            *pRoot=createNode(val);
        else if((*pRoot)->val<=val)
            insert(&((*pRoot)->right), val);
        else if((*pRoot)->val>val)
            insert(&((*pRoot)->left), val);
    }
    
    Node* arrayToBST(vector<int>&arr, int sz)
    {
        Node * pRoot = NULL;
        for(int i=0; i<sz; i++)
            insert(&pRoot, arr[i]);
        return pRoot;
    }
    
    void dfs(Node *head, vector<int>&postOrder){
        postOrder.push_back(head->val);
        if(head->left!=nullptr){
            dfs(head->left, postOrder);
        }
        if(head->right!=nullptr){
            dfs(head->right, postOrder);
        }
    }
    
    vector<int> findPostOrder(vector<int>&vec){
        int sz=vec.size();
        Node *head=arrayToBST(vec, sz);
        vector<int>postOrder;
        dfs(head, postOrder);
        return postOrder;
    }
    
    bool isValidBST(vector<int>&vec, vector<int>&postOrder){
        vector<int>tochk=findPostOrder(vec);
        return tochk==postOrder;
    }
    
    void permu(vector<int>&nums, vector<vector<int>>&res, int sz){
        res.push_back(nums);
    }
    
    vector<vector<int>> findValidPermus(vector<int>&nums, int mid){
        vector<vector<int>>res;
        int sz=nums.size();
        sort(nums.begin(), nums.end());
        do {
            permu(nums, res, sz);
        } while (next_permutation(nums.begin(), nums.end()));
        return res;
    }
    
    int numOfWays(vector<int>& nums) {
        vector<int>temp__=nums;
        vector<int>postOrder=findPostOrder(nums);
        vector<vector<int>>validpermus=findValidPermus(nums, nums[nums.size()/2]);
        for(auto &entries: validpermus){
            if(entries!=temp__){
                if(entries[0]==temp__[0]){
                    if(isValidBST(entries, postOrder)){
                        ans++;
                    }
                }   
            }
        }
        return ans;
    }
};