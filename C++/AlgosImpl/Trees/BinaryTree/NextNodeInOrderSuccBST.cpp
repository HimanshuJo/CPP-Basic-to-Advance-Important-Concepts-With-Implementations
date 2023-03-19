/*
	Find the next node i.e in-order successor of a given node in a binary search tree.
	
	We may assume that each node has a link to its parent
*/

#include<iostream>
using namespace std;

struct Node{
	int val;
	struct Node *left, *right, *parent;
};

struct Node* createNewNode(int val){
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->val=val;
	node->left=node->right=node->parent=nullptr;
	return node;
}

struct Node* leftMostChild(struct Node* node){
	if(node==nullptr){
		return nullptr;
	}
	while(node->left!=nullptr){
		node=node->left;
	}
	return node;
}

/*
	If a node 'n' doesn't have a right sub-tree, then we're done traversing n's subtree.
	We need to retract back to the n's parent. Suppose it is 'q'

	If 'n' was to the left of 'q' then the next node we should traverse should be 'q' (left->curr->right)

	If 'n' was to the right of 'q', then we've fully traversed q's subtree as well
		In this case, we need to traverse upwards from 'q' until we find a node 'x' that we've not fully traversed

		How to tell if we've not fully traversed a node 'x'

			We'll know we have encountered this case, when we move from a left node to its parent.

			In this case the left node is fully traversed but its parent is not

*/

struct Node* inorderSucc(struct Node* root){
	if(root==nullptr) return nullptr;
	if(root->right!=nullptr){
		return leftMostChild(root->right);
	} else{
		struct Node* tempRoot=root;
		struct Node* tempRootParent=tempRoot->parent;
		while(tempRootParent!=nullptr&&tempRootParent->left!=tempRoot){
			tempRoot=tempRootParent;
			tempRootParent=tempRootParent->parent;
		}
		return tempRootParent;
	}
}

int main(){
	struct Node* head=createNewNode(4);
	head->left=createNewNode(2);
	head->right=createNewNode(5);
	head->left->left=createNewNode(1);
	head->left->right=createNewNode(3);
	head->right->left=createNewNode(6);
	head->right->left->right=createNewNode(9);
}
