// Maximum sum of non-adjacent elements
/*
Problem Statement:

	You are given an array/list of ‘N’ integers. 

	You are supposed to return the maximum sum of the subsequence with the 
	constraint that no two elements are adjacent in the given array/list.

Note:

	A subsequence of an array/list is obtained by deleting some number of elements 
	(can be zero) from the array/list, leaving the remaining elements in their original order.
*/

#include<climits>

// TC: O(N)
// SC: O(N) + auxiliary space
int dfs(vector<int>&nums, const int sz, int idx, vector<int>&memo){
    if(idx>=sz) return 0;
    if(memo[idx]!=0) return memo[idx];
    int ans=INT_MIN;
    int pk=nums[idx]+dfs(nums, sz, idx+2, memo);
    int ntpk=dfs(nums, sz, idx+1, memo);
    ans=max(ans, max(pk, ntpk));
    return memo[idx]=ans;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int sz=nums.size();
    vector<int>memo(sz, 0);
    int ans=dfs(nums, sz, 0, memo);
    return ans;
}

// TC: O(N)
// SC: O(N)
int maximumNonAdjacentSum2(vector<int> &nums){
    int sz=nums.size();
    vector<int>dp(sz, 0);
    for(int idx=0; idx<sz; ++idx){
        int pk=nums[idx], ntpk=0;
        if(idx>=2){
            pk+=dp[idx-2];
        }
        if(idx-1>=0)
            ntpk=dp[idx-1];
        dp[idx]=max(pk, ntpk);
    }
    return dp[sz-1];
}

// TC: O(N)
// SC: O(1)
int maximumNonAdjacentSum3(vector<int> &nums){
    int sz=nums.size();
    int prev1=0, prev2=0;
    int curr=INT_MIN;
    for(int idx=0; idx<sz; ++idx){
        int pk=nums[idx], ntpk=0;
        if(idx>=2){
            pk+=prev2;
        }
        if(idx-1>=0)
            ntpk=prev1;
        curr=max(pk, ntpk);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}