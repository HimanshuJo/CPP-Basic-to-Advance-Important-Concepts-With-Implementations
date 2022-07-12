#include<iostream>
#include<vector>
#include<queue>
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

void bfs(Node *head, vector<vector<int>>&res, vector<int>&curr){
	queue<Node*>q;
	if(head!=nullptr)
		q.push(head);
	res.push_back({head->val});
	while(!q.empty()){
		int sz=q.size();
		vector<int>temp;
		while(sz--){
			Node *curr=q.front();
            q.pop();
			if(curr->left!=nullptr){
				q.push(curr->left);
				temp.push_back(curr->left->val);
			}
			if(curr->right!=nullptr){
				q.push(curr->right);
				temp.push_back(curr->right->val);
			}
		}
		if(temp.size()!=0){
			res.push_back(temp);
		}
	}
}

vector<vector<int>> createLevelList1(Node *head){
	vector<vector<int>>res;
	vector<int>curr;
	bfs(head, res, curr);
	return res;
}

void dfs(Node *head, vector<vector<int>>&res, int level){
	if(head==nullptr) return;
    res[level].push_back(head->val);
    if(head->left!=nullptr){
        dfs(head->left, res, level+1);
    }
    if(head->right!=nullptr){
        dfs(head->right, res, level+1);
    }
}

int findLevels(Node *head){
    if(head==nullptr) return 0;
    if(head->left) return 1+findLevels(head->left);
    return 0;
}

vector<vector<int>> createLevelList2(Node *head){
	vector<vector<int>>res;
    int totLevel=findLevels(head);
    res.resize(totLevel+1);
	dfs(head, res, 0);
	return res;
}

int main(){

	/*
				    4
			    /       \
			   2         5
			 /  \      /   \
			1    3    6     7
           / \  / \  / \   / \
          12 9 8  13 15 16 17 18
	*/

	Node* head=createNode(4);
	head->left=createNode(2);
	head->right=createNode(5);
	head->left->left=createNode(1);
	head->left->right=createNode(3);
	head->right->left=createNode(6);
	head->right->right=createNode(7);
    head->left->left->left=createNode(12);
    head->left->left->right=createNode(9);
    head->left->right->left=createNode(8);
    head->left->right->right=createNode(13);
    head->right->left->left=createNode(15);
    head->right->left->right=createNode(16);
    head->right->right->left=createNode(17);
    head->right->right->right=createNode(18);
	vector<vector<int>>lists=createLevelList1(head);
	vector<vector<int>>lists_=createLevelList2(head);
	for(auto &entries: lists){
		for(auto &nums: entries){
			cout<<nums<<" ";
		}
		cout<<endl;
	}
	cout<<"\n-------\n";
	for(auto &entries: lists_){
		for(auto &nums: entries){
			cout<<nums<<" ";
		}
		cout<<endl;
	}
}