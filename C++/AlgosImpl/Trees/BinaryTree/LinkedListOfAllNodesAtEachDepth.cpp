/*
	Given a binary tree create a linked list of all the nodes at each depth (e.g. if we have a tree with depth D, then we'll
	have D linked lists)

	e.g.

					4
				  /   \
				 2     5
				/ \   /  \
			   1   3 6    7

	Output: 4
	        2 5
	        1 3 5 7
*/

#include<iostream>
#include<vector>
#include<list>
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

vector<list<struct Node*>> createLevelLinkedListBFS(struct Node* root){
	vector<list<struct Node*>>res;
	list<struct Node*>lst;
	if(root!=nullptr){
		lst.push_back(root);
	}
	while(lst.size()>0){
		res.push_back(lst);
		list<struct Node*>parents=lst;
		lst.clear();
		for(struct Node* nodes: parents){
			if(nodes->left!=nullptr){
				lst.push_back(nodes->left);
			}
			if(nodes->right!=nullptr){
				lst.push_back(nodes->right);
			}
		}
	}
	return res;
}

int main(){
	struct Node* head=createNewNode(4);
	head->left=createNewNode(2);
	head->right=createNewNode(5);
	head->left->left=createNewNode(1);
	head->left->right=createNewNode(3);
	head->right->left=createNewNode(6);
	head->right->right=createNewNode(7);
	vector<list<struct Node*>>lists=createLevelLinkedListBFS(head);
	for(auto &vals: lists){
		for(auto &entries: vals){
			cout<<entries->val<<" ";
		}
		cout<<endl;
	}
}