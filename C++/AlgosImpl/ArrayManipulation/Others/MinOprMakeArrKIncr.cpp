// 2111. Minimum Operations to Make the Array K-Increasing
/*
You are given a 0-indexed array arr consisting of n positive integers, and a positive integer k.

The array arr is called K-increasing if arr[i-k] <= arr[i] holds for every index i, 
where k <= i <= n-1.

For example, arr = [4, 1, 5, 2, 6, 2] is K-increasing for k = 2 because:
arr[0] <= arr[2] (4 <= 5)
arr[1] <= arr[3] (1 <= 2)
arr[2] <= arr[4] (5 <= 6)
arr[3] <= arr[5] (2 <= 2)

However, the same arr is not K-increasing for k = 1 (because arr[0] > arr[1]) or k = 3 
(because arr[0] > arr[3]).
In one operation, you can choose an index i and change arr[i] into any positive integer.

Return the minimum number of operations required to make the array K-increasing for the given k.

Example 1:

Input: arr = [5,4,3,2,1], k = 1
Output: 4
Explanation:
For k = 1, the resultant array has to be non-decreasing.
Some of the K-increasing arrays that can be formed are [5,6,7,8,9], [1,1,1,1,1], [2,2,3,4,4]. 
All of them require 4 operations.
It is sub-optimal to change the array to, for example, [6,7,8,9,10] because it would take 5 operations.
It can be shown that we cannot make the array K-increasing in less than 4 operations.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	int longestIncreasingSubsequence(const vector<int>&arr){
		vector<int>sub;
		for(int i=0; i<arr.size(); ++i){
			int x=arr[i];
			if(sub.empty()||sub[sub.size()-1]<=x){
				sub.push_back(x);
			} else{
				int idx=upper_bound(sub.begin(), sub.end(), x)-sub.begin();
				sub[idx]=x;
			}
		}
		return sub.size();
	}

    int kIncreasing(vector<int>& arr, int k) {
        int n=arr.size();
		int ans=0;
		for(int i=0; i<k; ++i){
			vector<int>nwArr;
			for(int j=i; j<n; j+=k){
				nwArr.push_back(arr[j]);
			}
			ans+=nwArr.size()-longestIncreasingSubsequence(nwArr);
		}
		return ans;
    }
};