// 2074. Reverse Nodes in Even Length Groups
/*
You are given the head of a linked list.

The nodes in the linked list are sequentially assigned to non-empty groups whose 
lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). 

The length of a group is the number of nodes assigned to it. In other words,

The 1st node is assigned to the first group.
The 2nd and the 3rd nodes are assigned to the second group.
The 4th, 5th, and 6th nodes are assigned to the third group, and so on.
Note that the length of the last group may be less than or equal to 1 + the length of the second to last group.

Reverse the nodes in each group with an even length, and return the head of the modified linked list.

Input: head = [5,2,6,3,9,1,7,3,8,4]
Output: [5,6,2,3,9,1,4,8,3,7]
Explanation:
- The length of the first group is 1, which is odd, hence no reversal occurs.
- The length of the second group is 2, which is even, hence the nodes are reversed.
- The length of the third group is 3, which is odd, hence no reversal occurs.
- The length of the last group is 4, which is even, hence the nodes are reversed.

Input: head = [1,1,0,6]
Output: [1,0,1,6]
Explanation:
- The length of the first group is 1. No reversal occurs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 1. No reversal occurs.

Input: head = [1,1,0,6,5]
Output: [1,0,1,5,6]
Explanation:
- The length of the first group is 1. No reversal occurs.
- The length of the second group is 2. The nodes are reversed.
- The length of the last group is 2. The nodes are reversed.

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 10^5
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
class Solution {
public:

	ListNode* reverse(ListNode* head)
	{
		ListNode* prev = NULL;
		ListNode* curr = head;

		while (curr) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}

	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		if (m == n)
			return head;
		ListNode* revs = NULL, *revs_prev = NULL;
		ListNode* revend = NULL, *revend_next = NULL;
		int i = 1;
		ListNode* curr = head;
		while (curr && i <= n) {
			if (i < m)
				revs_prev = curr;

			if (i == m)
				revs = curr;

			if (i == n) {
				revend = curr;
				revend_next = curr->next;
			}

			curr = curr->next;
			i++;
		}
		revend->next = NULL;
		revend = reverse(revs);
		if (revs_prev)
			revs_prev->next = revend;
		else
			head = revend;

		revs->next = revend_next;
		return head;
	}


	ListNode* reverseEvenLengthGroups(ListNode* head) {
		ListNode* tmp = head;
		vector<int>nums;
		while (tmp->next != nullptr) {
			nums.push_back(tmp->val);
			tmp = tmp->next;
		}
		nums.push_back(tmp->val);
		vector<pair<int, int>>tmp_;
		int i = 0;
		int ii = 1;
		int idx = 2;
		tmp_.push_back({i, i});
		while (i != nums.size() - 1) {
			i += idx;
			if (i >= nums.size()) {
				tmp_.push_back({i - ii, nums.size() - 1});
				break;
			}
			tmp_.push_back({i - ii, i});
			idx++;
			ii++;
		}
		for (auto &vals : tmp_) {
			if (abs(vals.first - vals.second) & 1) {
				reverseBetween(head, vals.first + 1, vals.second + 1);
			}
			//cout<<vals.first<<" "<<vals.second<<endl;
		}
		return head;
	}
};