/*
	Given a sorted(increasing order) array with unique integer elements, write an algo
	to create a binary search tree with minimal height
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Node{
public:
	int val;
	Node *left, *right;
};

Node* createNode(int value){
	Node *nwNode=new Node();
	nwNode->val=value;
	nwNode->left=nwNode->right=nullptr;
	return nwNode; 
}

void dispInOrder(Node *head){
	if(head->left!=nullptr) dispInOrder(head->left);
	cout<<head->val<<" ";
	if(head->right!=nullptr) dispInOrder(head->right);
}

void dispPreOrder(Node *head){
	cout<<head->val<<" ";
	if(head->left!=nullptr) dispPreOrder(head->left);
	if(head->right!=nullptr) dispPreOrder(head->right);
}

void dispPostOrder(Node *head){
	if(head->left!=nullptr) dispPostOrder(head->left);
	if(head->right!=nullptr) dispPostOrder(head->right);
	cout<<head->val<<" ";
}

Node* dfs(vector<int>&arr, int start, int end){
	if(start>end) return nullptr;
	int mid=start+(end-start)/2;
	Node *head=createNode(arr[mid]);
	head->left=dfs(arr, start, mid-1);
	head->right=dfs(arr, mid+1, end);
	return head;
}

Node* createMinimalBST(vector<int>&arr){
	int end=arr.size();
	return dfs(arr, 0, end-1);
}

int main(){
	vector<int>arr{1, 3, 2, 10, 11, 12, 13};
	sort(arr.begin(), arr.end());
	/*
		 10
	   /    \
	  2     12
	 / \   /  \
	1   3 11   13
	*/
	Node *head=createMinimalBST(arr);
	dispInOrder(head);
	cout<<"\n-------\n";
	dispPreOrder(head);
	cout<<"\n-------\n";
	dispPostOrder(head);
}