/*
	Given a sorted(increasing order) array with unique integer elements, create a binary search tree with minimal height
*/

#include<iostream>
#include<vector>
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

struct Node* createMinimalBST(vector<int>&arr, int start, int end){
	if(start>end) return nullptr;
	int mid=start+(end-start)/2;
	struct Node* newNode=createNewNode(arr[mid]);
	newNode->left=createMinimalBST(arr, start, mid-1);
	newNode->right=createMinimalBST(arr, mid+1, end);
	return newNode;
}

struct Node* createMinimalBST(vector<int>&arr){
	return createMinimalBST(arr, 0, arr.size()-1);
}

void inorderTraversal(struct Node* root){
	if(root!=nullptr){
		inorderTraversal(root->left);
		cout<<root->val<<endl;
		inorderTraversal(root->right);
	}
}


int main(){
	vector<int>arr{1, 2, 3, 4, 5, 6, 7};
	struct Node* res=createMinimalBST(arr);
	inorderTraversal(res);
}