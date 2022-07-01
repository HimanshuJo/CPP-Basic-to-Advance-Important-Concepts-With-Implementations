// Lowest Common Ancestor in a Binary Search Tree.
/*
	Given values of two values n1 and n2 in a Binary Search Tree, find the Lowest Common Ancestor (LCA). 
	You may assume that both the values exist in the tree.

			20
		   /  \
		  8    22
		 / \   
		4   12
		    / \
		   10  14 

-------

Input: LCA of 10 and 14
Output:  12
Explanation: 12 is the closest node to both 10 and 14 
which is a ancestor of both the nodes.

Input: LCA of 8 and 14
Output:  8
Explanation: 8 is the closest node to both 8 and 14 
which is a ancestor of both the nodes.

Input: LCA of 10 and 22
Output:  20
Explanation: 20 is the closest node to both 10 and 22 
which is a ancestor of both the nodes. 
*/

/*
	
	Let T be a rooted tree. 

	The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in 
	T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

	The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root.

	Computation of lowest common ancestors may be useful, for instance, as part of a procedure for 
	determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed 
	as the distance from the root to n1, plus the distance from the root to n2, minus twice the 
	distance from the root to their lowest common ancestor
*/

/*
Approach:

For Binary search tree, while traversing the tree from top to bottom the first 
node which lies in between the two numbers n1 and n2 is the LCA of the nodes, 
i.e. the first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) n1 < n2. 

So just recursively traverse the BST in, if node’s value is greater than both n1 and n2 then our 
LCA lies in the left side of the node, if it’s is smaller than both n1 and n2, then LCA 
lies on the right side. 

Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).

Algorithm:  

Create a recursive function that takes a node and the two values n1 and n2.

If the value of the current node is less than both n1 and n2, then LCA lies in the right subtree.
Call the recursive function for the right subtree.

If the value of the current node is greater than both n1 and n2, then LCA lies in the left subtree. 
Call the recursive function for the left subtree.

If both the above cases are false then return the current node as LCA.
*/

#include<iostream>
#include<vector>
using namespace std;

class Node{
	public:
	int val;
	Node *left;
	Node *right;
};

Node* createNode(int data){
	Node *nwNode=new Node();
	nwNode->val=data;
	nwNode->left=nwNode->right=nullptr;
	return nwNode;
}

Node* findCommonAncestor(Node *head, Node *fst, Node *sec){
	if(head==nullptr) return nullptr;
	if(head->val>fst->val&&head->val>sec->val){
		return findCommonAncestor(head->left, fst, sec);
	} else if(head->val<fst->val&&head->val<sec->val){
		return findCommonAncestor(head->right, fst, sec);
	}
	return head;
}

int main(){

	/*
			20
		   /  \
		  8    22
		 / \   
		4   12
		    / \
		   10  14 
	*/

	Node *head=createNode(20);
	Node *l1=createNode(8);
	Node *r1=createNode(22);
	Node *l1l1=createNode(4);
	Node *l1r1=createNode(12);
	Node *l1r1l1=createNode(10);
	Node *l1r1r1=createNode(14);
	head->left=l1;
	head->right=r1; 
	l1->left=l1l1;
	l1->right=l1r1;
	l1r1->left=l1r1l1;
	l1r1->right=l1r1r1;
	Node *commonAncestor=findCommonAncestor(head, l1r1l1, l1r1r1);
	cout<<commonAncestor->val<<endl;
}