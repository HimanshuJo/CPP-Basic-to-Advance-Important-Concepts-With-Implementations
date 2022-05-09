// 2095. Delete the Middle Node of a Linked List
/*
You are given the head of a linked list. Delete the middle node, 
and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 
0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node.

Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.

Constraints:

The number of nodes in the list is in the range [1, 105].
1 <= Node.val <= 10^5
*/

/*
TLE:

//
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp2=head;
        vector<int>szVec;
        while(temp2){
            szVec.push_back(temp2->val);
            temp2=temp2->next;
        }
        if(szVec.size()==1)
            return nullptr;
        vector<int>temp;
        int sz=szVec.size()/2;
        int cnt=0;
        ListNode* dummy1=new ListNode();
        while(cnt!=sz){
            temp.push_back(head->val);
            head=head->next;
            cnt++;
        }
        head=head->next;
        while(head){
            temp.push_back(head->val);
            head=head->next;
        }
        int n=temp.size();
        cnt=0;
        ListNode* dummy2=dummy1;
        dummy1->val=temp[0];
        for(int i=1; i<n; ++i){
            dummy1->next=new ListNode();
            dummy1->next->val=temp[i];
            dummy1=dummy1->next;
        }

        return dummy2;
    }
};
*/

class Solution {
public:
    
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp1=head;
        ListNode* temp2=head;
        vector<int>szVec;
        while(temp2){
            szVec.push_back(temp2->val);
            temp2=temp2->next;
        }
        if(szVec.size()==1)
            return nullptr;
        if(szVec.size()==2){
            head->next=nullptr;
            return head;
        }
        int sz=szVec.size()/2;
        int cnt=0;
        while(cnt!=sz-1){
            head=head->next;
            cnt++;
        }
        ListNode* temp_=head->next->next;
        head->next->next=nullptr;
        head->next=temp_;
        return temp1;
    }
};