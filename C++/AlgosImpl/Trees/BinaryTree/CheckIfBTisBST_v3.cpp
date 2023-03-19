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

/* Valid Condition for a Binary Search Tree

	For all the nodes lying on the left side of the current node must be less than or equal to the current node, and
	all the nodes lying on the right side of the current node must be greater than the current node

	We'll use min/max criteria

	e.g.           20
	              /  \
	             10   30
	            /  \
	           5    15
	          / \     \
	         3   7     17

	starting with a range of (min=NULL, max=NULL) which root meets the criteria
	Branching left
		checking that these nodes are within the range (min=NULL, max=20)
	Branching right
		checking that these nodes are within the range (min=20, max=NULL)

	When we branch left, max gets updated
	When we branch right, min gets updated

	If any criteria fails, ans is false

Time: O(n)
Space: O(log n) -> upto log n recursive calls on the stack which may recurse upto the depth of the tree
*/

#include<iostream>
#include<vector>
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

bool checkBST(struct Node* root, int minn, int maxx){
	if(root==nullptr) return true;
	if((minn!=INT_MIN&&root->val<=minn)||(maxx!=INT_MAX&&root->val>maxx)){
		return false;
	}
	if(!checkBST(root->left, minn, root->val)||!checkBST(root->right, root->val, maxx)){
		return false;
	}
	return true;
}

bool checkBST(struct Node* root){
	return checkBST(root, INT_MIN, INT_MAX);
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
