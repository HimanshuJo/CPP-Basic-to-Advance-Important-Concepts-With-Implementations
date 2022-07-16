/*
	Given a linked list which might contain a loop, implement an algorithm that return the node at the beginning
	of the loop (if one exist)

	Example:

	Input: A->B->C->D->E->C
	Output: C
*/

/*
	Claim: If for every p steps that SR takes, FR has taken 2p steps, then FR will never "hop over" SR without ever colliding

		   Let suppose FR did hop over SR, such that SR is at spot i, and FR is at spot i+1,
		   in the previous step, SR would be at spot i-1 and FR would be at spot ((i+1)-2), i.e i-1

		   That is they would have collided
*/
/*
	Point of collision:

		Suppose the list has a "non-looped" part of size k

		For every p steps that SR takes, FR has taken 2p steps, therefore when SR enters the looped portion 
		after k steps, FR has taken 2k steps in total and must be 2k-k steps or k steps in the loop

		Since k might be much larger then the loop length, it can be denoted as mod(k, LoopSize)

		-------

		At each subsequent step, FR and SR get wither one step farther away or one step closer

			SR is 0 steps into the loop

			FR is k steps into the loop

			SR is k steps behind the FR

			FR is LoopSize-k steps behind the SR

			FR catches up to SR at a rate of 1 step per unit of time

		-------

		If FR is LoopSize-k steps behind SR and FR catches up at a rate of 1 step per unit, then they will meet
		after LoopSize-k steps.

		* At this point they will be k steps before the head of the loop
*/
/*
	Finding start of the loop

		CollisionSpot is k nodes before the start of the loop

			as k=mod(k, loopSize)

		It is safe to say both the collisionSpot and LinkedList head are k nodes from the start of the loop

		If we keep one pointer at CollisionSpot and move the other one to LinkedList head, they will each be
		k nodes from loop start

		Moving the two pointers at the same speed will cause them to collide again after k steps
		at this point they will both be at loopStart
*/

#include<iostream>
using namespace std;

class Node{
public:
	char data;
	Node *next;
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

Node* findBeginning(Node *head){
    Node *SR=head;
    Node *FR=head;
    while(FR!=nullptr&&SR->next!=nullptr){
        SR=SR->next;
        FR=FR->next->next;
        if(SR==FR) break;
    }
    if(FR==nullptr||FR->next==nullptr) return nullptr;
    SR=head;
    while(SR!=FR){
        SR=SR->next;
        FR=FR->next;
    }
    return SR;
}

int main(){
	Node *head=createNewNode('A');
	Node *n1=createNewNode('B');
	Node *n2=createNewNode('C');
	Node *n3=createNewNode('D');
	Node *n4=createNewNode('E');
	appendToTail(head, n1);
	appendToTail(head, n2);
	appendToTail(head, n3);
	appendToTail(head, n4);
    appendToTail(head, n2);
	//printLL(head);
    Node *ans=findBeginning(head);
    cout<<ans->data<<endl;
}