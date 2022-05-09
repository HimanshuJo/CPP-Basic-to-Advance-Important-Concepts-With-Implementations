#include<bits/stdc++.h>
using namespace std;
class Solution {
	public:
		vector<long long>dp;
		vector<int>visited;
		int checkGoal(vector<int>&nums, int start, int goal){
			int curr=start;
			if(curr==goal) return 0;
			if(curr>1000) return 2*1e9;
			if(curr<0) return 2*1e9;
			if(dp[curr]!=-1) return dp[curr];
			if(visited[curr]) return 2*1e9;
			visited[curr]++;
			int minn=2*1e9;
			for(int i=0; i<nums.size(); ++i){
				int a= 1+checkGoal(nums, curr+nums[i], goal);
				int b= 1+checkGoal(nums, curr-nums[i], goal);
				int c= 1+checkGoal(nums, curr^nums[i], goal);
				minn=min(minn, a);
				minn=min(minn, b);
				minn=min(minn, c);
			}
			visited[curr]--;
			return dp[curr]=minn;
		}

		int minimumOperations(vector<int>& nums, int start, int goal) {
			sort(nums.begin(), nums.end());
			visited.resize(1001,0);
			dp.resize(1001,-1);
			int res=checkGoal(nums, start, goal);
			return res>=1e9?-1:res;
		}
};
