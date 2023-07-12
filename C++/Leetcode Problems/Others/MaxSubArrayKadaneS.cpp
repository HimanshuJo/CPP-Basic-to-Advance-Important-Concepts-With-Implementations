/*
Given an integer array nums, find the contiguous sub-array (containing at least one number)
    which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

-------

Kadane’s Algorithm:

Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_so_far < max_ending_here)
        max_so_far = max_ending_here
  (c) if(max_ending_here < 0)
        max_ending_here = 0
    return max_so_far
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> nums)
    {
        int size = nums.size();
        int maxSofar = nums[0];
        int maxEndingHere = nums[0];
        for (int i = 1; i < size; ++i)
        {
            maxEndingHere = maxEndingHere + nums[i];
            if (maxSofar < maxEndingHere)
            {
                maxSofar = maxEndingHere;
            }
            if (maxEndingHere < 0)
            {
                maxEndingHere = 0;
            }
        }
        return maxSofar;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    obj.maxSubArray(nums);
}