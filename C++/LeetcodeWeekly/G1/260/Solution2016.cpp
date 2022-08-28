// 2016. Maximum Difference Between Increasing Elements
/*
Given a 0-indexed integer array nums of size n, find the maximum difference between
nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.

Example 1:

Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.
Example 2:

Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].
Example 3:

Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.


Constraints:

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 10^9
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int maxDiff = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] - nums[i] > maxDiff) {
                    maxDiff = nums[j] - nums[i];
                }
            }
            res = max(maxDiff, res);
        }
        return res == 0 ? -1 : res;
    }
};

// -------*******-------

class Solution2
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int mn = nums[0], res = -1;
        for (int i = 1; i < nums.size(); ++i)
        {
            res = max(res, nums[i] - mn);
            mn = min(mn, nums[i]);
        }
        return res == 0 ? -1 : res;
    }
};