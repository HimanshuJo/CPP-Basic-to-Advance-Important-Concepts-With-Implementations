/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. 

All houses at this place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent houses were broken into on 
the same night.

Given an integer array nums representing the amount of money of each house, return the 
maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), 
because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

class Solution {
public:
    
    int dfs(vector<int>&nums, int idx, int start, int memo[][2]){
        if(idx<start) return 0;
        if(memo[idx][start]!=-1) return memo[idx][start];
        int maxx=max(dfs(nums, idx-1, start, memo), dfs(nums, idx-2, start, memo)+nums[idx]);
        return memo[idx][start]=maxx;
    }
    
    int rob(vector<int>& nums) {
        int sz=nums.size();
        int memo[101][2];
        for(int i=0; i<101; ++i)
            for(int j=0; j<2; ++j)
                memo[i][j]=-1;
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        int ans1=dfs(nums, n-2, 0, memo);
        for(int i=0; i<101; ++i)
            for(int j=0; j<2; ++j)
                memo[i][j]=-1;
        int ans2=dfs(nums, n-1, 1, memo);
        return max(ans1, ans2);
    }
};