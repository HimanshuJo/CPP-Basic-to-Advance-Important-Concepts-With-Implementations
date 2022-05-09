#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

struct Node{
	int val;
	struct Node *left, *right;
};

struct Node* newNode(int val){
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
	node->val=val;
	node->left=node->right=NULL;
	return node;
}

int maxInBtreeBFS(struct Node* head){
	int maxx=INT_MIN;
	if(head==NULL) return maxx;
	queue<struct Node*>q;
	q.push(head);
	while(!q.empty()){
		struct Node* currHead=q.front();
		maxx=max(currHead->val, maxx);
		q.pop();
		if(currHead->left!=NULL){
			q.push(currHead->left);
		}
		if(currHead->right!=NULL){
			q.push(currHead->right);
		}
	}
	return maxx;
}

int maxInBtreeDFS(struct Node* head){
	int maxx=INT_MIN;
	if(head==NULL) return maxx;
	maxx=max(maxx, head->val);
	maxx=max(maxx, maxInBtreeDFS(head->left));
	maxx=max(maxx, maxInBtreeDFS(head->right));
	return maxx;
}

int maxInBtreeDFS2(struct Node* head){
	int maxx=INT_MIN;
	if(head==NULL) return maxx;
	stack<struct Node*>stk;
	stk.push(head);
	while(!stk.empty()){
		struct Node* currHead=stk.top();
		maxx=max(currHead->val, maxx);
		stk.pop();
		if(currHead->left!=NULL){
			stk.push(currHead->left);
		}
		if(currHead->right!=NULL){
			stk.push(currHead->right);
		}
	}
	return maxx;
}

int minInBtreeBFS(struct Node* head){
	int minn=INT_MAX;
	if(head==NULL) return minn;
	queue<struct Node*>q;
	q.push(head);
	while(!q.empty()){
		struct Node* currHead=q.front();
		minn=min(currHead->val, minn);
		q.pop();
		if(currHead->left!=NULL){
			q.push(currHead->left);
		}
		if(currHead->right!=NULL){
			q.push(currHead->right);
		}
	}
	return minn;
}

int minInBtreeDFS(struct Node* head){
	int minn=INT_MAX;
	if(head==NULL) return minn;
	minn=min(minn, head->val);
	minn=min(minn, minInBtreeDFS(head->left));
	minn=min(minn, minInBtreeDFS(head->right));
	return minn;
}

int minInBtreeDFS2(struct Node* head){
	int minn=INT_MAX;
	if(head==NULL) return minn;
	stack<struct Node*>stk;
	stk.push(head);
	while(!stk.empty()){
		struct Node* currHead=stk.top();
		minn=min(minn, currHead->val);
		stk.pop();
		if(currHead->left!=NULL){
			stk.push(currHead->left);
		}
		if(currHead->right!=NULL){
			stk.push(currHead->right);
		}
	}
	return minn;
}

int sumBtreeBFS(struct Node* head){
	int sum=0;
	if(head==NULL) return sum;
	queue<struct Node*>q;
	q.push(head);
	while(!q.empty()){
		struct Node* currHead=q.front();
		sum+=currHead->val;
		q.pop();
		if(currHead->left!=NULL){
			q.push(currHead->left);
		}
		if(currHead->right!=NULL){
			q.push(currHead->right);
		}
	}
	return sum;
}

int sumSubTreesBtreeDFS(struct Node* head, multimap<struct Node*, int>&mp){
	int sum=0;
	if(head==NULL) return sum;
	sum+=head->val;
	sum+=sumSubTreesBtreeDFS(head->left, mp);
	sum+=sumSubTreesBtreeDFS(head->right, mp);
	mp.insert(make_pair(head, sum));
	return sum;
}


int sumBtreeDFS(struct Node* head){
	int sum=0;
	if(head==NULL) return sum;
	sum+=head->val;
	sum+=sumBtreeDFS(head->left);
	sum+=sumBtreeDFS(head->right);
	return sum;
}

int sumBtreeDFS2(struct Node* head){
	int sum=0;
	if(head==NULL) return sum;
	stack<struct Node*>stk;
	stk.push(head);
	while(!stk.empty()){
		struct Node* currHead=stk.top();
		sum+=currHead->val;
		stk.pop();
		if(currHead->left!=NULL){
			stk.push(currHead->left);
		}
		if(currHead->right!=NULL){
			stk.push(currHead->right);
		}
	}
	return sum;
}

bool isFoundBFS(struct Node* head, int val){
	if(head==NULL) return false;
	queue<struct Node*>q;
	q.push(head);
	while(!q.empty()){
		struct Node* currHead=q.front();
		if(currHead->val==val) return true;
		q.pop();
		if(currHead->left!=NULL){
			q.push(currHead->left);
		}
		if(currHead->right!=NULL){
			q.push(currHead->right);
		}
	}
	return false;
}

bool isFoundDFS(struct Node* head, int val){
	if(head==NULL) return false;
	if(head->val==val) return true;
	return isFoundDFS(head->left, val)||isFoundDFS(head->right, val);
}

bool isFoundDFS2(struct Node* head, int val){
	if(head==NULL) return false;
	stack<struct Node*>stk;
	stk.push(head);
	while(!stk.empty()){
		struct Node* currHead=stk.top();
		if(currHead->val==val) return true;
		stk.pop();
		if(currHead->left!=NULL){
			stk.push(currHead->left);
		}
		if(currHead->right!=NULL){
			stk.push(currHead->right);
		}
	}
	return false;
}


void dispTreeBFS(struct Node* head){
	if(head==NULL) cout<<"NULL\n";
	queue<struct Node*>q;
	q.push(head);
	while(!q.empty()){
		struct Node* currHead=q.front();
		cout<<currHead->val<<" ";
		q.pop();
		if(currHead->left!=NULL){
			q.push(currHead->left);
		}
		if(currHead->right!=NULL){
			q.push(currHead->right);
		}
	}
}

void dispTreeDFS(struct Node* head){
	if(head==NULL) return;
	cout<<head->val<<" ";
	dispTreeDFS(head->left);
	dispTreeDFS(head->right);
}

void dispTreeDFS2(struct Node* head){
	if(head==NULL) cout<<"NULL\n";
	st1ack<struct Node*>stk;
	stk.push(head);
	while(!stk.empty()){
		struct Node* currHead=stk.top();
		cout<<currHead->val<<" ";
		stk.pop();
		if(currHead->right!=NULL){
			stk.push(currHead->right);
		}
		if(currHead->left!=NULL){
			stk.push(currHead->left);
		}
	}
}


int main(){
	struct Node* head=newNode(1123);
	head->left=newNode(245);
	head->right=newNode(3235);
	head->left->left=newNode(478);
	head->right->right=newNode(556);
	head->left->right=newNode(623);
	head->right->left=newNode(712);
	cout<<"max BFS: "<<maxInBtreeBFS(head)<<"\n";
	cout<<"max DFS: "<<maxInBtreeDFS(head)<<"\n";
	cout<<"max DFS stack: "<<maxInBtreeDFS2(head)<<"\n";
	cout<<"-------\n";
	cout<<"min BFS: "<<minInBtreeBFS(head)<<"\n";
	cout<<"min DFS: "<<minInBtreeDFS(head)<<"\n";
	cout<<"min DFS stack: "<<minInBtreeDFS2(head)<<"\n";
	cout<<"-------\n";
	cout<<"sum BFS: "<<sumBtreeBFS(head)<<"\n";
	cout<<"sum DFS: "<<sumBtreeDFS(head)<<"\n";
	cout<<"sum DFS stack: "<<sumBtreeDFS2(head)<<"\n";
	cout<<"-------\n";
	cout<<"BFS search: "<<((isFoundBFS(head, 7))==1?"Yes":"NO")<<"\n";
	cout<<"DFS search: "<<((isFoundDFS(head, 7))==1?"Yes":"NO")<<"\n";
	cout<<"DFS search stack: "<<((isFoundDFS2(head, 7))==1?"Yes":"NO")<<"\n";
	cout<<"\n****----****\n";
	cout<<"DFS: ";
	dispTreeDFS(head);
	cout<<"\n-------\n";
	cout<<"DFS stack: ";
	dispTreeDFS2(head);
	cout<<"\n-------\n";
	cout<<"BFS: ";
	dispTreeBFS(head);
	cout<<"\n-------\n";
	multimap<struct Node*, int>mp;
	sumSubTreesBtreeDFS(head, mp);
	int rootSum=0;
	int leftSubTreeSum=0;
	int rightSubTreeSum=0;
	int cnt=1;
	for(auto it=mp.begin(); it!=mp.end(); ++it){
		if(cnt==1)
			rootSum=(*it).second;
		if(cnt==2)
			leftSubTreeSum=(*it).second;
		if(cnt==3)
			rightSubTreeSum=(*it).second;
		cnt++;
		if(cnt==4) break;
	}
	cout<<"Root Sum: "<<rootSum<<endl;
	cout<<"Left SubTree Sum: "<<leftSubTreeSum<<endl;
	cout<<"Right SubTree Sum: "<<rightSubTreeSum<<endl;
}	
