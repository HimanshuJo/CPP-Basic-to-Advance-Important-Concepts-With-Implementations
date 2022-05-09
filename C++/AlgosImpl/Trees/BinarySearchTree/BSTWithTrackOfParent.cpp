/*
Given a binary search tree return the parent of a given node

e.g.

			10
		   /  \
		  2    12
		 / \   / \
		1   3 11  13

	parent of node 1 is 2
	parent of node 11 is 12
*/

#include<iostream>
using namespace std;

struct TreeNode{
	public:
	int data;
	struct TreeNode *left, *right;

};

struct TreeNode* createNewNode(int val){
	struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->data=val;
	node->left=node->right=nullptr;
	return node;
}

struct TreeNode* searchForParent(struct TreeNode* root, int val){
	if(root==nullptr) return nullptr;
	if(root->left==nullptr&&root->right==nullptr) return nullptr;
	if((root->left!=nullptr&&root->left->data==val)||(root->right!=nullptr&&root->right->data==val)) return root;
	if(root->data>val){
		return searchForParent(root->left, val);
	}
	if(root->data<val){
		return searchForParent(root->right, val);
	}
	return nullptr;
}

int main(){
	struct TreeNode* head=createNewNode(10);
	head->left=createNewNode(2);
	head->right=createNewNode(12);
	head->left->left=createNewNode(1);
	head->left->right=createNewNode(3);
	head->right->left=createNewNode(11);
	head->right->right=createNewNode(13);
	struct TreeNode* parentN=searchForParent(head, 11);
	if(parentN!=nullptr) cout<<parentN->data;
	else cout<<"NULL\n";
}