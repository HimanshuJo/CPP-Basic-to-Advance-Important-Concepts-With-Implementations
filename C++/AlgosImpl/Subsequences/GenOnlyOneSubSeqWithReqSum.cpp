/*
	Generate only one subsequence which upon adding its elements produce the required sum
	e.g. int arr[]={1, 2, 1}
		  Output: 1 1 or 2
*/

#include<iostream>
#include<vector>
using namespace std;

bool genOneSubseqWithReqSum(vector<int>&arr, int n, int sum, int currSum, int idx, vector<vector<int>>&fnSubseq, vector<int>&subseq){
	if(idx==n){
		if(currSum==sum){
			fnSubseq.push_back(subseq);
			return true;
		} else return false;
	}
	subseq.push_back(arr[idx]);
	currSum+=arr[idx];
	if(genOneSubseqWithReqSum(arr, n, sum, currSum, idx+1, fnSubseq, subseq)) return true;
	currSum-=arr[idx];
	subseq.pop_back();
	if(genOneSubseqWithReqSum(arr, n, sum, currSum, idx+1, fnSubseq, subseq)) return true;
	return false;
}

int main(){
	vector<int>arr{1, 2, 1};
	int n=arr.size();
	int sum=2;
	int currSum=0;
	int idx=0;
	vector<vector<int>>fnSubseq;
	vector<int>subseq;
	genOneSubseqWithReqSum(arr, n, sum, currSum, idx, fnSubseq, subseq);
	for(auto &vals: fnSubseq){
		for(auto &nums: vals){
			cout<<nums<<" ";
		}
		cout<<endl;
	}
}
