#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};

struct Node* reverse(struct Node *head){
	struct Node *prev=NULL;
	struct Node *curr=head;
	while(curr){
		struct Node *next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

Node* reverseBetween(Node *head, int bgn, int end){
	if(bgn==end) return head;
	Node *revs=NULL, *revs_prev=NULL;
	Node *revend=NULL, *revend_next=NULL;
	int i=1;
	Node *curr=head;
	while(curr&&i<=end){
		if(i<bgn) revs_prev=curr;
		if(i==bgn) revs=curr;
		if(i==end){
			revend=curr, revend_next=curr->next;
		}
		curr=curr->next;
		++i;
	}
	revend->next=NULL;
	revend=reverse(revs);
	if(revs_prev) revs_prev->next=revend;
	else head=revend;
	revs->next=revend_next;
	return head;
}

void printLL(struct Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void pushInBegin(struct Node **head_ref, int new_data){
	struct Node *new_node=new Node;
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}

int main(){
	struct Node *head=NULL;
	pushInBegin(&head, 70);
	pushInBegin(&head, 60);
	pushInBegin(&head, 50);
	pushInBegin(&head, 40);
	pushInBegin(&head, 30);
	pushInBegin(&head, 20);
	pushInBegin(&head, 10);
	reverseBetween(head, 3, 6);
	printLL(head);
	return 0;
}