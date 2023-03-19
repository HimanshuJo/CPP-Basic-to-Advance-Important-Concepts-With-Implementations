/*
	Check if a binary tree is balanced. A balanced binary tree is a tree where the heights of the two subtrees of
	any node does not differ by more than one

	e.g.1 The given Binary trees are Balanced

				4
			  /   \
			 2     5
			/ \   /  \
		   1   3 6    7

		   	    4
			  /   \
			 2     5
			/ \   /
		   1   3 6

   	e.g.2 The given Binary tree is not Balanced

				4
			  /   \
			 2     5
			/ \   /
		   1   3 6
		          \
		           9
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

struct Node{
	int val;
	struct Node *left, *right;
};

struct Node* createNewNode(int val){
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->val=val;
	node->left=node->right=nullptr;
	return node;
}

/* O(N log N) */
int getHeight(struct Node* root){
	if(root==nullptr) return -1;
	return max(getHeight(root->left), getHeight(root->right))+1;
}

bool isBalanced(struct Node* root){
	if(root==nullptr) return true;
	int heightDiff=getHeight(root->left)-getHeight(root->right);
	if(abs(heightDiff)>1) return false;
	return isBalanced(root->left)&&isBalanced(root->right);
}
/* ------- */

/* O(N) */
int checkHeight(struct Node* root){
	if(root==nullptr) return -1;
	int leftHeight=checkHeight(root->left);
	if(leftHeight==INT_MIN) return INT_MIN;
	int rightHeight=checkHeight(root->right);
	if(rightHeight==INT_MIN) return INT_MIN;
	int heightDiff=leftHeight-rightHeight;
	if(abs(heightDiff)>1){
		return INT_MIN;
	} else{
		return max(leftHeight, rightHeight)+1;
	}
}

bool checkBalanced(struct Node* root){
	return checkHeight(root)!=INT_MIN;
}
/* ------- */

int main(){
	struct Node* head=createNewNode(4);
	head->left=createNewNode(2);
	head->right=createNewNode(5);
	head->left->left=createNewNode(1);
	head->left->right=createNewNode(3);
	head->right->left=createNewNode(6);
	head->right->left->right=createNewNode(9);
	bool res=isBalanced(head);
	cout<<(res==1?"true":"false");
	cout<<"\n-------\n";
	bool res2=checkBalanced(head);
	cout<<(res2==1?"true":"false");
}
