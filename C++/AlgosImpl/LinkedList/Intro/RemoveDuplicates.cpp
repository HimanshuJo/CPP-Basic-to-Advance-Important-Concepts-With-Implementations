/*
Given a singly linked list remove all the duplicates from the list

E.g: list=[1, 2, 2, 3]
	 modified list=[1, 2, 3]
*/

#include<iostream>
#include<unordered_set>
using namespace std;

class Node{
public:
	int data;
	Node *next;
};

Node* appendToTail(Node *head, int newVal){
	Node *newNode=new Node();
	newNode->data=newVal;
	newNode->next=nullptr;
	while(head->next!=nullptr){
		head=head->next;
	}
	head->next=newNode;
	return head;
}

// Time: O(N), Space: O(N)
Node* removeDuplicates(Node *head){
	unordered_set<int>st;
	Node *prev=new Node();
	while(head!=nullptr){
		if(st.find(head->data)!=st.end()){
			prev->next=head->next;
		} else{
			st.insert(head->data);
			prev=head;
		}
		head=head->next;
	}
	return head;
}

// Time: O(N), Space: O(1)
Node* removeDuplicates2(Node *head){
	Node *curr=head;
	while(curr!=nullptr){
		Node *runner=curr;
		while(runner->next!=nullptr){
			if(runner->next->data==curr->data){
				runner->next=runner->next->next;
			} else{
				runner=runner->next;
			}
		}
		curr=curr->next;
	}
	return head;
}

void printLList(Node *head){
	while(head!=nullptr){
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main(){
	Node *head=new Node();
	head->data=1;
	/*Node *second=new Node();
	Node *third=new Node();
	Node *fourth=new Node();
	head->data=1;
	second->data=2;
	third->data=2;
	fourth->data=3;
	head->next=second, second->next=third, third->next=fourth;*/
	appendToTail(head, 1), appendToTail(head, 2), appendToTail(head, 2), appendToTail(head, 3);
	printLList(head);
	cout<<"\n-------\n";
	removeDuplicates2(head);
	printLList(head);
}