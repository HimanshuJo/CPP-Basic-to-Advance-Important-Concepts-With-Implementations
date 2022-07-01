#include<vector>
#include<iostream>
using namespace std;

class Node{
	public:
	int val;
	Node *left;
	Node *right;
};

Node* createNewNode(int data){
	Node *nwNode=new Node();
	nwNode->val=data;
	nwNode->left=nwNode->right=nullptr;
	return nwNode;
}

void printBST(Node *head){
	cout<<head->val<<" ";
	if(head->left!=nullptr) printBST(head->left);
	if(head->right!=nullptr) printBST(head->right);
}

Node* findCommonAncestor(Node *head, Node *first, Node *second){
	if(head==nullptr) return nullptr;
	if(head->val>=first->val&&head->val>=second->val){
		return findCommonAncestor(head->left, first, second);
	} else if(head->val<first->val&&head->val<second->val){
		return findCommonAncestor(head->right, first, second);
	}
	return head;
}

int main(){

	/*
				 20
			   /    \
			  8     22
			 / \
			4   12
			   /  \
			  10  14
	*/
	Node *head=createNewNode(20);
	Node *lft1=createNewNode(8);
	Node *rght1=createNewNode(22);
	head->left=lft1;
	head->right=rght1;
	Node *lft1l1=createNewNode(4);
	Node *lft1r1=createNewNode(12);
	lft1->left=lft1l1;
	lft1->right=lft1r1;
	Node *lft1r1l1=createNewNode(10);
	Node *lft1r1r1=createNewNode(14);
	lft1r1->left=lft1r1l1;
	lft1r1->right=lft1r1r1;
	printBST(head); // 20 8 4 12 10 14 22
	cout<<endl;
	Node *commonAncestor=findCommonAncestor(head, lft1r1l1, lft1r1r1);
	cout<<"Common Ancestor "<<lft1r1l1->val<<" "<<lft1r1r1->val<<" : "<<commonAncestor->val;
	cout<<endl;
	Node *commonAncestor2=findCommonAncestor(head, lft1r1l1, rght1);
	cout<<"Common Ancestor "<<lft1r1l1->val<<" "<<rght1->val<<" : "<<commonAncestor2->val;
	cout<<endl;
	Node *commonAncestor3=findCommonAncestor(head, lft1r1r1, lft1);
	cout<<"Common Ancestor "<<lft1r1r1->val<<" "<<lft1->val<<" : "<<commonAncestor3->val;
	cout<<endl;
}