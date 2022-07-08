// 300. Longest Increasing Subsequence
/*
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements 
without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence 
of the array [0,3,1,6,2,2,7].

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int lengthOfLIS(vector<int>&nums){
		int n=nums.size();
		vector<int>dp(n, 1);
		for(int i=0; i<n; ++i){
			for(int j=0; j<i; ++j){
				if(nums[i]>nums[j]&&dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
				}
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};

int main(){

}