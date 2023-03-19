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

int idx=0;

int getSize(struct Node* root){
	if(root==nullptr) return 0;
	int size=0;
	queue<struct Node*>q;
	q.push(root);
	while(!q.empty()){
		size++;
		struct Node* curr=q.front();
		q.pop();
		if(curr->left!=nullptr){
			q.push(curr->left);
		}
		if(curr->right!=nullptr){
			q.push(curr->right);
		}
	}
	return size;
}

// Inorder Traversal
void copyBST(struct Node* root, vector<int>&arr){
	if(root==nullptr) return;
	copyBST(root->left, arr);
	arr[idx]=root->val;
	idx++;
	copyBST(root->right, arr);
}

bool checkBST(struct Node* root){
	int sz=getSize(root);
	cout<<"size is "<<sz<<endl;
	vector<int>arr(sz);
	copyBST(root, arr);
	for(int i=1; i<sz; ++i){
		if(arr[i]<=arr[i-1]) return false;
	}
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
	bool res=checkBST(head2);
	if(res==false) cout<<"NO\n";
	else cout<<"YES\n";
}
