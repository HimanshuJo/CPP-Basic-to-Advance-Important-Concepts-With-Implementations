/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.
*/

#include<vector>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    
    int dfs(int idx, vector<int>&nums, map<int, int>&memo){
        int n=nums.size();
        if(idx>=n-1) return memo[idx]=0;
        if(memo.find(idx)!=memo.end()) return memo[idx];
        int minSteps=n;
        for(int i=1; i<=nums[idx]; ++i){
            minSteps=min(minSteps, 1+dfs(idx+i, nums, memo));
        }
        return memo[idx]=minSteps;
    }
    
    int jump(vector<int>& nums) {
        map<int, int>memo;
        return dfs(0, nums, memo);
    }
};

class Solution2 {
public:

    int jump(vector<int>&nums){
        vector<int>dp(nums.size()+1, nums.size()+1);
        int len=nums.size()-1;
        dp[0]=0;
        for(int i=0; i<nums.size(); ++i){
            for(int j=i; j<=(min(i+nums[i], len)); ++j){
                dp[j]=min(dp[j], 1+dp[i]);
            }
        }
        for(auto &vals: dp){
            cout<<vals<<" ";
        }
        return dp[nums.size()-1]==len+1?-1:dp[nums.size()-1]; 
    }
};

int main(){
    Solution2 obj;
    vector<int>nums{2,3,1,1,4};
    obj.jump(nums);
}
