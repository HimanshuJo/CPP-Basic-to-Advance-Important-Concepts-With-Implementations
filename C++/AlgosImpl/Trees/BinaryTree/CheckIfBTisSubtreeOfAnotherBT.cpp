/*
Given two binary trees, check if the first tree is subtree of the second one. 

A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T. 

The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.

For example, in the following case, tree S is a subtree of tree T. 
 
        Tree 2

          10  
        /    \ 
      4       6
       \
        30
 
        Tree 1

              26
            /   \
          10     3
        /    \    \
      4       6    3
       \
        30
*/
/*
Solution:

	Traverse the tree T in preorder fashion. For every visited node in the traversal, see if the subtree rooted with this node is identical to S. 
*/

#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *left, *right;
};

Node* createNewNode(int val){
	Node *node=new Node();
	node->data=val;
	node->left=node->right=NULL;
	return node;
}

bool areIdentical(Node* root1, Node* root2){
	if(root1==NULL&&root2==NULL)
		return true;
	if(root1==NULL||root2==NULL)
		return false;
	return ((root1->data==root2->data)&&(areIdentical(root1->left, root2->left))&&(areIdentical(root1->right, root2->right)));
}

bool isSubtree(Node *source, Node *target){
	if(source==NULL) return true;
	if(target==NULL) return false;
	if(areIdentical(source, target)) return true;
	/*
		If the tree with root as current node doesn't match than we'll try
		left and right subtrees one by one
	*/
	return (isSubtree(source, target->left)||(isSubtree(source, target->right)));
}

int main(){
	Node *head1=createNewNode(10);
	head1->left=createNewNode(4);
	head1->right=createNewNode(6);
	head1->left->right=createNewNode(30);
	// -------*******-------
	Node *head2=createNewNode(26);
	head2->left=createNewNode(10);
	head2->right=createNewNode(3);
	head2->right->right=createNewNode(3);
	head2->left->left=createNewNode(4);
	head2->left->right=createNewNode(6);
	head2->left->left->right=createNewNode(30);
	bool res=isSubtree(head1, head2);
	cout<<(res==true?"YES":"NO");
}
