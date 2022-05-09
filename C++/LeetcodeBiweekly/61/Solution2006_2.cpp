/*
Given an integer array nums and an integer k, 
return the number of pairs (i, j) where i < j such that 
|nums[i] - nums[j]| == k.

Example 1:

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countKDifference(vector<int>& nums, int k) {
		int res = 0;
        // need to build map as we go
		unordered_map<int, int> m; 
		for(int i = 0; i < nums.size(); i++){
			res += (m[nums[i] - k] + m[nums[i] + k]);
			m[nums[i]]++;
		}
		return res;
	}
};