#include<iostream>
#include<unordered_map>
#include<stack>
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

void dispTreeTopToBottom(unordered_map<struct Node*, struct Node*>&parent, struct Node* node){
	cout<<"Parents of individual nodes "<<endl;
	for(auto &entries: parent){
		if(entries.second!=nullptr) cout<<entries.first->val<<" : "<<entries.second->val<<endl;
	}
	cout<<"-------\n";
	cout<<"Ancestors of node "<<node->val<<endl;
	while(parent[node]){
		cout<<parent[node]->val<<" ";
		node=parent[node];
	}
	/*while(node=parent[node]){
		cout<<node->val<<" ";
	}*/
	cout<<"\n";
}

void setParent(unordered_map<struct Node*, struct Node*>&parent, struct Node* root){
	stack<struct Node*>stk;
	stk.push(root);
	while(!stk.empty()){
		struct Node* curr=stk.top();
		stk.pop();
		if(curr->right){
			// curr is the parent of curr->right
			parent[curr->right]=curr;
			stk.push(curr->right);
		}
		if(curr->left){
			// curr is the parent of curr->left
			parent[curr->left]=curr;
			stk.push(curr->left);
		}
	}
}

void findAncestors1(struct Node* root, struct Node* node){
	if(root==nullptr) return;
	unordered_map<struct Node*, struct Node*>parent;
	parent[root]=nullptr;
	setParent(parent, root);
	dispTreeTopToBottom(parent, node);
}

bool findAncestors2(struct Node* root, struct Node* node){
	if(root==nullptr) return false;
	if(root==node) return true;
	bool left=findAncestors2(root->left, node);
	bool right=false;
	if(!left){
		right=findAncestors2(root->right, node);
	}
	if(left||right){
		cout<<root->val<<" ";
	}
	return left||right;
}

int main(){
	struct Node* head=createNewNode(10);
	head->left=createNewNode(2);
	head->right=createNewNode(12);
	head->left->left=createNewNode(1);
	head->left->right=createNewNode(3);
	head->right->left=createNewNode(11);
	head->right->right=createNewNode(13);
	/*
		 10
	   /    \
	  2     12
	 / \   /  \
	1   3 11   13

	*/
	findAncestors1(head, head->left->right);
	cout<<"***---***\n";
	findAncestors2(head, head->left->right);
}

/*
Parents of individual nodes
11 : 12
13 : 12
1 : 2
3 : 2
2 : 10
12 : 10
-------
Ancestors of node 3
2 10
***---***
2 10
*/