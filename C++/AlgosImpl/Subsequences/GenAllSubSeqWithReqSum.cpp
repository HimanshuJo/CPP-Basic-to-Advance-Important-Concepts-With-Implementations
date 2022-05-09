/*
	Gen all Subsequences which upon adding produce the required sum

	e.g. int arr[]={1, 2, 1}, int sum=2
		 Output: 1 1
		         2
		
*/

#include<iostream>
#include<vector>
using namespace std;

void genSubseqWithSum(vector<int>&arr, int n, int sum, int currSum, int idx, vector<vector<int>>&allSubseq, vector<int>&subseq){
	if(idx==n){
		if(currSum==sum){
			allSubseq.push_back(subseq);
		} return;
	}
	subseq.push_back(arr[idx]);
	currSum+=arr[idx];
	genSubseqWithSum(arr, n, sum, currSum, idx+1, allSubseq, subseq);
	subseq.pop_back();
	currSum-=arr[idx];
	genSubseqWithSum(arr, n, sum, currSum, idx+1, allSubseq, subseq);
}

int main(){
	vector<int>arr{1, 2, 3, 4, 5, 6, 7};
	int n=arr.size();
	int sum=5;
	int currSum=0;
	int idx=0;
	vector<vector<int>>allSubseq;
	vector<int>subseq;
	genSubseqWithSum(arr, n, sum, currSum, idx, allSubseq, subseq);
	for(auto &it: allSubseq){
		for(auto &nums: it){
			cout<<nums<<" ";
		}
		cout<<endl;
	}
}
