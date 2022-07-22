// Maximum Sum Subsequence of length k
/*
Given an array sequence [A1, A2 …An], the task is to find the maximum possible sum of 
increasing subsequence S of length k such that S1<=S2<=S3………<=Sk.

Input : 
n = 9 k = 4 
A=[2 5 3 9 15 33 6 18 20] 
Output : 62 
Possible Increasing subsequence of Length 4 with maximum possible sum is 9 15 18 20 

Input : 
n = 8 k = 3 
A=[8 5 9 10 5 6 21 8] 
Output : 40 
Possible Increasing subsequence of Length 3 with maximum possible sum is 9 10 21

*/

/*
Naive Approach: 
In the brute force approach, first we will try to find all the subsequences of length k and 
will check whether they are increasing or not. 

There could be nCk such sequences in the worst case when all elements are in increasing order. 
Now we will find the maximum possible sum for such sequences. 

Time Complexity would be O((nCk)*n).

-------

Efficient Approach:

We will be using a two-dimensional dp array in which dp[i][l] means that maximum 
sum subsequence of length l taking array values from 0 to i and the subsequence is 
ending at index ‘i’. 

Range of ‘l’ is from 0 to k-1. 

Using the approach of longer increasing subsequence on the inner loop when 
j<i we will check if arr[j] < arr[i] for checking if subsequence increasing. 

This problem can be divided into its subproblems: 

	dp[i][1]=arr[i] for length 1, maximum increasing subsequence is equal to the array value

	dp[i][l+1]= max(dp[i][l+1], dp[j][l]+arr[i]) for any length l between 1 to k-1

This means that if for i'th position and subsequence of length l+1, there exists some 
subsequence at j (j < i) of length l for which 
sum of dp[j][l] + arr[i] is more than its initial calculated value then update that value.

Then finally we will find the maximum value of dp[i][k] i.e for every ‘i’ 
if subsequence of k length is causing more sum than update the required ans.

Time complexity: O(n^2*k) 
Space complexity: O(n^2) 
*/

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int maxIncrSubseqSum(vector<int>&nums, int n, int k){
	int dp[n][k+1], ans=-1;
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<n; ++i){
		dp[i][1]=nums[i];
	}
	for(int i=1; i<n; ++i){
		for(int j=0; j<i; ++j){
			if(nums[i]>nums[j]){
				for(int x=1; x<=k-1; ++x){
					if(dp[j][x]!=-1){
						dp[i][x+1]=max(dp[i][x+1], dp[j][x]+nums[i]);
					}
				}
			}
		}
	}
	for(int i=0; i<n; ++i){
		if(ans<dp[i][k]){
			ans=dp[i][k];
		}
	}
	return (ans==-1)?0:ans;
}

int main(){
	vector<int>nums{8, 5, 9, 10, 5, 6, 21, 8};
	int n=nums.size();
	int k=3;
	int ans=maxIncrSubseqSum(nums, n, k);
	cout<<ans<<"\n";
}
