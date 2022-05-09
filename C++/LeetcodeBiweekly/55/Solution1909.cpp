// Remove One Element to Make the Array Strictly Increasing

/*
 * Given a 0-indexed integer array nums, return true if it can be made strictly increasing
 * after removing exactly one element, or false otherwise.
 * If the array is already strictly increasing, return true.

	The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

	Example 1:

	Input: nums = [1,2,10,5,7]
	Output: true
	Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
	[1,2,5,7] is strictly increasing, so return true.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        if (isGood(nums))
        {
            return true;
        }
        else
        {
            int numArr[nums.size()];
            for (int i = 0; i < nums.size(); ++i)
            {
                numArr[i] = nums[i];
            }
            int size = nums.size();
            for (int i = 0; i < size; ++i)
            {
                nums.erase(nums.begin() + i);
                if (isGood(nums))
                {
                    return true;
                }
                auto it = nums.begin() + i;
                nums.insert(it, numArr[i]);
            }
            return false;
        }
    }

    bool isGood(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] < nums[i + 1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};