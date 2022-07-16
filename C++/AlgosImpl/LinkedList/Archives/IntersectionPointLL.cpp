/*
	Determine the intersection node for two linked lists (if present)

	Intersection is based on the reference, not by value

	-------

				3-->1-->5-->9-->7-->2-->1
								^
								|
				        4-->6---

    Intersecting node: 7
*/
/*
	Algo:

		1. Find lengths and tails for each linked list

		2. If tails are different there is no intersection

		3. Set pointers to the start of each linked list, and on the longer linked list
		   advance its pointer by the difference in lengths

	    4. Traverse each linked list until the pointers are at the same value
*/

#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

class Result{
	public:
	Node *tail;
	int sz;

	Result(){}

	Result(Node *tail, int sz){
		this->tail=tail;
		this->sz=sz;
	}
};

Node* createNewNode(char val){
	Node *nwNode=new Node();
	nwNode->data=val;
	nwNode->next=nullptr;
    return nwNode;
}

void appendToTail(Node *head, Node *nd){
	while(head->next!=nullptr){
		head=head->next;
	}
	head->next=nd;
}

void printLL(Node *head){
	while(head!=nullptr){
		cout<<head->data<<" ";
        head=head->next;
	}
}

Result* getTailAndSize(Node *l1){
	if(l1==nullptr){
		return nullptr;
	}
	int sz_=1;
	Node *current=l1;
	while(current->next!=nullptr){
		sz_++;
		current=current->next;
	}
	Result *res=new Result();
	res->sz=sz_, res->tail=current;
	return res;
}

Node* getKthNode(Node *head, int k){
	Node *curr=head;
	while(k>0&&curr!=nullptr){
		curr=curr->next;
		k--;
	}
	return curr;
}

Node* findIntersection(Node *l1, Node *l2){
	if(l1==nullptr||l2==nullptr) return nullptr;
	Result *res1=getTailAndSize(l1);
	Result *res2=getTailAndSize(l2);
	if(res1->tail!=res2->tail){
		return nullptr;
	}
	Node *shorter=res1->sz<res2->sz?l1:l2;
	Node *longer=res1->sz<res2->sz?l2:l1;
	longer=getKthNode(longer, abs(res1->sz-res2->sz));
	while(shorter!=longer){
		shorter=shorter->next;
		longer=longer->next;
	}
	return longer;
}

int main(){
	Node *head=createNewNode(3);
	Node *nd2=createNewNode(1);
	Node *nd3=createNewNode(5);
	Node *nd4=createNewNode(9);
	Node *nd5=createNewNode(7);
	Node *nd6=createNewNode(2);
	Node *nd7=createNewNode(1);
	appendToTail(head, nd2);
	appendToTail(head, nd3);
	appendToTail(head, nd4);
	appendToTail(head, nd5);
	appendToTail(head, nd6);
	appendToTail(head, nd7);
	Node *head2=createNewNode(4);
	Node *nd2_=createNewNode(6);
	appendToTail(head2, nd2_);
	appendToTail(head2, nd5);
	printLL(head);
	cout<<"\n-------\n";
	printLL(head2);
	cout<<"\n-------\n";
	Node *ans=findIntersection(head, head2);
	cout<<ans->data<<endl;
}