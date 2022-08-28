// 1955. Count Number of Special Subsequences
/*
A sequence is special if it consists of a positive number of 0s, followed by a positive number
of 1s, then a positive number of 2s.

For example, [0,1,2] and [0,0,1,1,1,2] are special.
In contrast, [2,1,0], [1], and [0,1,2,0] are not special.
Given an array nums (consisting of only integers 0, 1, and 2), return the number of
different subsequences that are special. Since the answer may be very large, return
it modulo 109 + 7.

A subsequence of an array is a sequence that can be derived from the array by
deleting some or no elements without changing the order of the remaining elements.
Two subsequences are different if the set of indices chosen are different.

Example 3:

Input: nums = [0,1,2,0,1,2]
Output: 7
Explanation: The special subsequences are:
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
- [0,1,2,0,1,2]
*/

#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution
{
    int dp[100001][4] = {}, mod = 1000000007;
    int dfs(vector<int> &nums, int i, int last)
    {
        if (i >= nums.size())
            return last == 2;
        if (dp[i][last + 1] == 0)
        {
            dp[i][last + 1] = 1 + dfs(nums, i + 1, last);
            if (nums[i] == last || nums[i] == last + 1)
                dp[i][last + 1] = (dp[i][last + 1] + dfs(nums, i + 1, nums[i])) % mod;
        }
        return dp[i][last + 1] - 1;
    }
    int countSpecialSubsequences(vector<int> &nums)
    {
        return dfs(nums, 0, -1);
    }
};

// -------*******-------

class Solution2 {
public:
  int M = 1e9 + 7;

  int countSpecialSubsequences(vector<int>& nums) {
    int n = nums.size();
    vector<vector<long long>> dp(3, vector<long long>(n, 0));
    if (nums[0] == 0) dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
      dp[0][i] = dp[0][i - 1];
      dp[1][i] = dp[1][i - 1];
      dp[2][i] = dp[2][i - 1];
      if (nums[i] == 0) dp[0][i] = 2 * dp[0][i - 1] + 1;
      else if (nums[i] == 1) dp[1][i] = dp[0][i - 1] + 2 * dp[1][i - 1];
      else dp[2][i] = dp[1][i - 1] + 2 * dp[2][i - 1];
      dp[0][i] %= M;
      dp[1][i] %= M;
      dp[2][i] %= M;
    }
    return dp[2][n - 1];
  }
};