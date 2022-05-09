// 2054. Two Best Non-Overlapping Events
/*
You are given a 0-indexed 2D integer array of events where 
events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, 
and if you attend this event, you will receive a value of valuei. 
You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where 
one of them starts and the other ends at the same time. More specifically, if you attend an event 
with end time t, the next event must start at or after t + 1.

Examples:

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	int maxTwoEvents(vector<vector<int>>&events){
		int n=events.size();
		vector<vector<int>>memo(n, vector<int>(2, -1));
		sort(events.begin(), events.end());
		return dfs(events, 0, 0, memo);
	}

	int dfs(vector<vector<int>>&nums, int idx, int k, vector<vector<int>>&memo){
		if(k==2||idx>=nums.size()) return 0;
		if(memo[idx][k]!=-1) return memo[idx][k];
		vector<int>ans={nums[idx][1], INT_MAX, INT_MAX};
		int nextIndex=upper_bound(begin(nums), end(nums), ans)-begin(nums);
		return memo[idx][k]=max(dfs(nums, idx+1, k, memo), nums[idx][2]+dfs(nums, nextIndex, k+1, memo));
	}

};

int main(){}