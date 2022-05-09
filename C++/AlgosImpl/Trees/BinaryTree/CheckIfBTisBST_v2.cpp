// check if a Binary Tree is a Binary Search Tree
/*
	e.g.1 The given Binary trees are not a valid Binary search Tree

				4
			  /   \
			 2     5
			/ \   /  \
		   1   3 6    7

		   		8
			  /    \
			 4      10
			/ \       \
		   2   12      20

	e.g.2 The given Binary tree is a valid Binary search Tree

			8
		  /    \
		 4      10
		/ \       \
	   2   6      20
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int val;
	struct Node *left, *right;
};

struct Node* createNewNode(int val){
	struct Node* node=(struct Node*) malloc(sizeof(struct Node));
	node->val=val;
	node->left=node->right=nullptr;
	return node;
}

int currVal=0;

bool checkBST(struct Node* root){
	if(root==nullptr) return true;
	if(!checkBST(root->left)) return false;
	if(currVal!=0&&root->val<=currVal){
		return false;
	}
	currVal=root->val;
	if(!checkBST(root->right)) return false;
	return true;
}

int main(){
	struct Node* head=createNewNode(4);
	head->left=createNewNode(2);
	head->right=createNewNode(5);
	head->left->left=createNewNode(1);
	head->left->right=createNewNode(3);
	head->right->left=createNewNode(6);
	head->right->right=createNewNode(7);
	// ---***---
	struct Node* head2=createNewNode(8);
	head2->left=createNewNode(4);
	head2->right=createNewNode(10);
	head2->left->left=createNewNode(2);
	head2->left->right=createNewNode(6);
	head2->right->right=createNewNode(20);
	// ---***---
	bool res=checkBST(head2);
	if(res==false) cout<<"NO\n";
	else cout<<"YES\n";
}