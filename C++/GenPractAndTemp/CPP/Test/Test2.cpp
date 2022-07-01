#include<vector>
#include<iostream>
using namespace std;

class Node{
	public:
	int val;
	Node *left, *right;	
};

Node* createNode(int data){
    Node *nwNode=new Node();
    nwNode->val=data;
    nwNode->left=nwNode->right=nullptr;
    return nwNode;
}

void displayBTree(Node *root){
	cout<<root->val<<" ";
	if(root->left!=nullptr){
		displayBTree(root->left);
	}
	if(root->right!=nullptr){
		displayBTree(root->right);
	}
}

bool findPath(Node *head, Node *n1, vector<int>&vec){
	if(head==nullptr) return false;
	vec.push_back(head->val);
	if(head->val==n1->val){
		return true;
	}
	if((head->left&&findPath(head->left, n1, vec))||(head->right&&(findPath(head->right, n1, vec))))
		return true;
	vec.pop_back();
	return false;
}

int findCommonAncestor(Node *head, Node *n1, Node *n2){
	vector<int>frst, sec;
	int tochk=findPath(head, n1, frst);
	int tochk2=findPath(head, n2, sec);
	if(tochk==0||tochk2==0){
		return -1;
	}
	for(auto &vals: frst){
		cout<<vals<<" ";
	}
	cout<<endl;
	for(auto &vals: sec){
		cout<<vals<<" ";
	}
	cout<<"\n-------\n";
	int ans;
	int sz1=frst.size(), sz2=sec.size();
	int mnsz=min(sz1, sz2);
	vector<int>lrg, sm;
	if(sz1>sz2){
		lrg=frst;
		sm=sec;
	} else{
		lrg=sec;
		sm=frst;
	}
	int i;
	for(i=0; i<mnsz; ++i){
		if(lrg[i]!=sm[i]){
			break;
		}
	}
	return lrg[i-1];
}

int main(){

	/*
					20
				   /   \
				  21    22
				 /  \   / \
				23  24 12  16
				    / \
				   4   8


	*/



    Node *head=createNode(20);
    Node *hl=createNode(21);
    Node *hr=createNode(22);
    Node *hll=createNode(23);
    Node *hlr=createNode(24);
    Node *hlrl=createNode(4);
    Node *hlrr=createNode(8);
    Node *hrl=createNode(12);
    Node *hrr=createNode(16);
    head->left=hl;
    head->right=hr;
    hl->left=hll;
    hl->right=hlr;
    hlr->left=hlrl;
    hlr->right=hlrr;
    hr->left=hrl;
    hr->right=hrr;
	displayBTree(head); // 20 21 23 24 4 8 22 12 16
	cout<<"\n-------\n";
    int commonAncestor=findCommonAncestor(head, hlrl, hlrr);
	cout<<commonAncestor;
}
