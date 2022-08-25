// 1995. Count Special Quadruplets
/*
Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:

nums[a] + nums[b] + nums[c] == nums[d], and
a < b < c < d

Example 3:

Input: nums = [1,1,1,3,5]
Output: 4
Explanation: The 4 quadruplets that satisfy the requirement are:
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5
*/
#include <bits/stdc++.h>
using namespace std;
/*
class Solution
{
public:
    int countQuadruplets(vector<int> &nums)
    {
        const auto n = nums.size();
        unordered_map<int, int> freq;

        freq[nums[n - 1]] = 1;
        size_t answ = 0;
        for (int i = n - 2; i > 1; --i)
        {
            for (int j = i - 1; j > 0; --j)
            {
                for (int k = j - 1; k >= 0; --k)
                {
                    if (freq.count(nums[i] + nums[j] + nums[k]))
                    {
                        answ += freq[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
            freq[nums[i]] += 1;
        }
        return answ;
    }
};
*/

class Solution
{
public:
    int dp[51][50001][4];
    int solve(vector<int> &nums, int sum, int n, int k)
    {
        if (k == 0 and sum == 0)
        {
            return 1;
        }
        if (n < 0 or k < 0 or sum < 0)
        {
            return 0;
        }
        if (dp[n][sum][k] != -1)
        {
            return dp[n][sum][k];
        }
        return dp[n][sum][k] = (solve(nums, sum - nums[n], n - 1, k - 1) + solve(nums, sum, n - 1, k));
    }
    int countQuadruplets(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 3; i < n; i++)
        {
            count += solve(nums, nums[i], i - 1, 3);
        }
        return count;
    }
};