/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have 
security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the 
maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

/*

Dp

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rob(vector<int> &nums) {
            if (nums.size() == 0) {
                return 0;
            }
            int n = nums.size();
            vector<int> dp(n+1, 0);
            dp[1] = nums[0];
            for (int i=2; i<=n; ++i) {
                dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
            }
            cout << dp[n];
            return dp[n];
        }
};

*/

class Solution {
public:
    
    int dfs(vector<int>&nums, int idx, int start,  int memo[]){
        if(idx<start) return 0;
        if(memo[idx]!=-1) return memo[idx];
        int maxx=max(dfs(nums, idx-1, start, memo), dfs(nums, idx-2, start, memo)+nums[idx]);
        return memo[idx]=maxx;
    }
    
    int rob(vector<int>& nums) {
        int memo[101];
        for(int i=0; i<101; ++i)
            memo[i]=-1;
        int n=nums.size();
        int ans=dfs(nums, n-1, 0, memo);
        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> nums={2,7,9,3,1};
    obj.rob(nums);
}