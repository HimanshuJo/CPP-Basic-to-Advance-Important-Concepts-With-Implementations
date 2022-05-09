/*Top-Down
It's easier to solve this problem using a top-down approach first.

We track the last element we picked, starting from -1.
We can include the current element if it's the same as last, or larger by 1. So, 
we can pick 1 after 0, but we cannot pick 2 after 0.
We can always skip the current element.
If we reach the end and the last element is 2 - then we find a subsequence.
To speed things up, we will memoise computations for each position and last value. 
It requires O(n) memory, which we will improve to O(1) in the bottom-up solution below. 
Note that we add (and then subtract) 1 to our memoisation to mark the current state as computed. 
Otherwise we will get TLE for cases like [0,0,0, ... 0].
*/
#include<bits/stdc++.h>
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