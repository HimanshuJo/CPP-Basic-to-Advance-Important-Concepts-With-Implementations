// Find the Middle Index in Array
/*
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

Example 1:

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation:
The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }
        int n = nums.size();
        int preSm = 0;
        vector<int> pSm;
        vector<int> suffixSum(n);
        for (int i = 0; i < nums.size(); ++i)
        {
            preSm += nums[i];
            pSm.push_back(preSm);
        }
        for (auto &vals : pSm)
        {
            cout << vals << " ";
        }
        cout<<endl;
        suffixSum[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixSum[i] = suffixSum[i + 1] + nums[i];
        }
        for (auto &vals : suffixSum)
        {
            cout << vals << " ";
        }
        cout<<endl;
        for (int i = 0; i < n; ++i)
        {
            if (pSm[i] == suffixSum[i])
            {
                cout << i;
                return i;
            }
        }
        return -1;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {2,5};
    obj.findMiddleIndex(nums);
}