#include<bits/stdc++.h>
using namespace std;

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

    int getMaxDiff(vector<int>&arr, int n)
    {
        int diff = INT_MIN;
        if (n == 0) {
            return diff;
        }
        int max_so_far = arr[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] >= max_so_far) {
                max_so_far = arr[i];
            }
            else {
                diff = max (diff, max_so_far - arr[i]);
            }
        }
        return diff;
    }

    int getMinDiff(vector<int>&arr, int n)
    {
        int diff = INT_MAX;
        for (int i=0; i<n-1; i++)
          if (arr[i+1] - arr[i] < diff)
            diff = arr[i+1] - arr[i];
        return diff;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>curr;
		while(head->next!=nullptr){
			int val_=head->val;
			curr.push_back(val_);
			head=head->next;
		}
		curr.push_back(head->val);
		if(curr.size()==2){
			return {-1, -1};
		}
		vector<int>tmp;
		for(int i=1; i<=curr.size()-2; ++i){
			if(curr[i]>curr[i-1]&&curr[i]>curr[i+1]){
				tmp.push_back(i+1);
			} else if(curr[i]<curr[i-1]&&curr[i]<curr[i+1]){
				tmp.push_back(i+1);
			}
		}
        if(tmp.size()==0 || tmp.size()==1) return {-1, -1};
		int maxx=INT_MIN;
		int minn=INT_MAX;
		sort(tmp.begin(), tmp.end());
		maxx=getMaxDiff(tmp, tmp.size());
		minn=getMinDiff(tmp, tmp.size());
		return {minn, maxx};
	}
};
