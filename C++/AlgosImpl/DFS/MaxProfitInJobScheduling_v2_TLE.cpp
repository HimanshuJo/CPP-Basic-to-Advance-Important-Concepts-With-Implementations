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

int N = 5e+7;

class Solution {
public:

	int dfs(vector<vector<int>>&nums, int idx, vector<int>&memo){
		if(idx<nums.size()&&memo[idx]!=-1){
			return memo[idx];
		}
		vector<int>curr=nums[idx];
		int maxProf=0;
		for(int i=idx+1; i<nums.size(); ++i){
			vector<int>nxt=nums[i];
			if(nxt[0]>=curr[1]){
				int prof=dfs(nums, i, memo);
				maxProf=max(maxProf, prof);
			}
		}
		maxProf+=curr[2];
		return memo[idx]=maxProf;;
	}

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
		int n=startTime.size();
		vector<vector<int>>nums;
		for(int i=0; i<n; ++i){
			nums.push_back({startTime[i], endTime[i], profit[i]});
		}
		vector<int>memo(n+1, -1);
		sort(nums.begin(), nums.end());
		int fnProf=0;
		for(int i=0; i<n; ++i){
			int prof=dfs(nums, i, memo); 
			fnProf=max(fnProf, prof);
		}
		return fnProf;
    }
};

int main(){
    Solution obj;
    vector<int>startTime{6,24,45,27,13,43,47,36,14,11,11,12};
    vector<int>endTime{31,27,48,46,44,46,50,49,24,42,13,27};
    vector<int>profit{14,4,16,12,20,3,18,6,9,1,2,8};
    int ans=obj.jobScheduling(startTime, endTime, profit);
    cout<<ans<<endl;
}