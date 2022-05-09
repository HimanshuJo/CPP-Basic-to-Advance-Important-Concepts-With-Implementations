#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

	ListNode* revLL(ListNode* head) {
		if (!head) return head;
		ListNode* prev = nullptr;
		while (head) {
			ListNode* temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		return prev;
	}

	ListNode* reverseEvenLengthGroups(ListNode* head) {
		ListNode* tmp = new ListNode();
		tmp->next = head;
		ListNode* prev = tmp;
		for (int i = 1; i <= 11 && head; ++i) {
			ListNode* currHead = head;
			ListNode* nextHead;
			int cnt = 1;
			while (cnt < i && currHead && currHead->next) {
				currHead = currHead->next;
				cnt++;
			}
			nextHead = currHead->next;
			if (cnt & 1) {
				prev = currHead;
				head = nextHead;
			} else {
				currHead->next = nullptr;
				prev->next = revLL(head);
				prev = head;
				//head is now just behind nextHead
				head->next = nextHead;
				head = nextHead;
			}
		}
		cout << tmp->next->val;
		return tmp->next;
	}
};

int main() {
	Solution obj;
	ListNode* head = new ListNode(5);
	ListNode* L2 = new ListNode(2);
	ListNode* L3 = new ListNode(6);
	ListNode* L4 = new ListNode(3);
	ListNode* L5 = new ListNode(9);
	ListNode* L6 = new ListNode(1);
	ListNode* L7 = new ListNode(7);
	ListNode* L8 = new ListNode(3);
	ListNode* L9 = new ListNode(8);
	ListNode* L10 = new ListNode(4);
	head->next = L2;
	head->next->next = L3;
	head->next->next->next = L4;
	head->next->next->next->next = L5;
	head->next->next->next->next->next = L6;
	head->next->next->next->next->next->next = L7;
	head->next->next->next->next->next->next->next = L8;
	head->next->next->next->next->next->next->next->next = L9;
	head->next->next->next->next->next->next->next->next->next = L10;
	obj.reverseEvenLengthGroups(head);
}