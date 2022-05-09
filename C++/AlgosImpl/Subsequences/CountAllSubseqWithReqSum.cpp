/*
	Count number of subsequences which upon adding produces the required sum
	e.g. int arr[]{1, 2, 1}, sum=2;
		 Output: 2 (1 1 and 2)
*/

#include<iostream>
#include<vector>
using namespace std;

int countAllSubseqWithReqSum(vector<int>&arr, int n, int sum, int currSum, int idx){
	if(currSum>sum) return 0;
	if(idx==n){
		if(currSum==sum){
			return 1;
		} else return 0;
	}
	currSum+=arr[idx];
	int l=countAllSubseqWithReqSum(arr, n, sum, currSum, idx+1);
	currSum-=arr[idx];
	int r=countAllSubseqWithReqSum(arr, n, sum, currSum, idx+1);
	return l+r;
}

int main(){
	vector<int>arr{1, 2, 1};
	int n=arr.size();
	int sum=2;
	int currSum=0;
	int idx=0;
	int ans=countAllSubseqWithReqSum(arr, n, sum, currSum, idx);
	cout<<ans;
}
