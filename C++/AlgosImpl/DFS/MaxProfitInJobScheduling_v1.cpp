// 1235. Maximum Profit in Job Scheduling
/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i],
obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such
that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	vector<int>dp;
	int find(vector<vector<int>>& events, int idx, int end) {
		// We reach final index, return 0
		if (idx == events.size())
			return 0;
		// If the current start time is less than previous end time then we can't attend this event, 
		// we move forward.
		if (events[idx][0] < end)
			return find(events, idx + 1, end);
		// Return pre stored value if we have
		if (dp[idx] != -1)
			return dp[idx];
		int res = max(events[idx][2] + find(events, idx + 1, events[idx][1]),
			                           find(events, idx + 1, end));
		return dp[idx] = res;
	}
	int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
	{
		//putting startTime,endTimeand profit in an array so that we can sort it
		vector<vector<int>>events(startTime.size(), vector<int>(3, 0));
		for (int i = 0; i < startTime.size(); i++)
		{
			events[i][0] = startTime[i];
			events[i][1] = endTime[i];
			events[i][2] = profit[i];
		}
		sort(events.begin() , events.end());
		int n = events.size();
		//Intialising DP and assigning value -1
		dp.resize(n, -1);
		return find(events , 0 , 0);
	}
};