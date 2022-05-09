#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
};

Node* appendToTail(Node* head, int newVal){
	Node *newNode=new Node();
	newNode->data=newVal;
	newNode->next=nullptr;
	while(head->next!=nullptr){
		head=head->next;
	}
	head->next=newNode;
	return head;
}

Node* deleteNode(Node *head, int valToDel){
	if(head==nullptr) return nullptr;
	Node *tempNode=head;
	if(tempNode->data==valToDel){
		return head->next;
	}
	while(tempNode->next!=nullptr){
		if(tempNode->next->data==valToDel){
			tempNode->next=tempNode->next->next;
			return head;
		}
		tempNode=tempNode->next;
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
	head->next=nullptr;
	int bgn=2; 
	while(bgn!=5){
		appendToTail(head, bgn++);
	}
	printLList(head);
	cout<<"\n-------\n";
	deleteNode(head, 3);
	cout<<"\n Node deleted\n";
	printLList(head);
}