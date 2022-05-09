/*
Given a Binary Search Tree return the kth smallest and kth largest node in the tree

E.g:	Given the following Binary Search Tree, 
			the 3rd smallest node is 3
			the 3rd largest (or 6th smallest node) node is 6

              5
			/   \
		   3     7
		  / \   / \
		 1   4 6   8
		  \
		   2
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node{
	int val;
	struct Node *left, *right;
};

struct Node* newNode(int val){
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->val=val;
	node->left=node->right=NULL;
	return node;
}

int sizeBST(Node* root){
	int sz=0;
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node* currNode=q.front();
		sz++;
		q.pop();
		if(currNode->left!=NULL){
			q.push(currNode->left);
		}
		if(currNode->right!=NULL){
			q.push(currNode->right);
		}
	}
	return sz;
}

int KthSmallestNode(Node* root, int k){
	stack<Node*>stk;
	struct Node* node=root;
	int cnt=0;
	while(true){
		if(node!=NULL){
			stk.push(node);
			node=node->left;
		} else{
			if(stk.empty()) break;
			node=stk.top();
			stk.pop();
			cnt++;
			if(cnt==k){
				return node->val;
			}
			node=node->right;
		}
	}
	return -1;
}

int KthLargestNode(Node* root, int k){
	stack<Node*>stk;
	struct Node* node=root;
	int N=sizeBST(root);
	int cnt=0;
	while(true){
		if(node!=NULL){
			stk.push(node);
			node=node->left;
		} else{
			if(stk.empty()) break;
			node=stk.top();
			stk.pop();
			cnt++;
			if(cnt==(N-k)+1){
				return node->val;
			}
			node=node->right;
		}
	}
	return -1;
}

int main(){
	struct Node* head=newNode(5);
	head->left=newNode(3);
	head->right=newNode(7);
	head->left->left=newNode(1);
	head->left->right=newNode(4);
	head->left->left->right=newNode(2);
	head->right->left=newNode(6);
	head->right->right=newNode(8);
	int ans=KthSmallestNode(head, 3);
	int ans2=KthLargestNode(head, 3);
	cout<<ans;
	cout<<"\n-------\n";
	cout<<ans2;
}