// Maximum sum such that no two elements are adjacent
/*
Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 
2 numbers in the sequence should be adjacent in the array. So 3 2 7 10 should return 13 
(sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).Answer the question in most efficient way.

Input : arr[] = {5, 5, 10, 100, 10, 5}
Output : 110

Input : arr[] = {1, 2, 3}
Output : 4

Input : arr[] = {1, 20, 3}
Output : 20
*/
/*
Solution2:

#include <bits/stdc++.h>
using namespace std;

int FindMaxSum(vector<int> arr, int n)
{
	int incl = arr[0];
	int excl = 0;
	int prev_incl=incl;
	int i;

	for (i = 1; i < n; i++)
	{
		incl = excl + arr[i];
		excl = max(excl, prev_incl);
		prev_incl=incl;
	}
	return (max(incl, excl));
}

int main()
{
	vector<int> arr = {1, 20, 3};
	cout<<FindMaxSum(arr, arr.size());
}
*/

#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<int>&in, vector<int>&memo, int idx, int sz){
	if(idx>=sz){
		return 0;
	}
	if(memo[idx]!=-1) return memo[idx];
	int res=INT_MIN;
	res=max(dfs(in, memo, idx+1, sz), in[idx]+dfs(in, memo, idx+2, sz));
	return memo[idx]=res;
}

int maxSumNoTwoAdjEleSame(vector<int>&in, int sz){
	int idx=0;
	vector<int>memo(sz+1, -1);
	int ans=dfs(in, memo, idx, sz);
	return ans;
}

int main(){
	vector<int>in{5,  5, 10, 40, 50, 35};
	int sz=in.size();
	int ans=maxSumNoTwoAdjEleSame(in, sz);
	cout<<ans<<endl;
}