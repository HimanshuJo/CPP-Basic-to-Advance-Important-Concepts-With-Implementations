/*
	Generate all possible subsequences of an array
	e.g. int arr[1, 2, 1]
	Output:
		1 2 1
		1 2
		1 1
		1
		2 1
		2
		1
		{}
*/

#include<iostream>
#include<vector>
using namespace std;

void genAllSubSeq(vector<int>&arr, int n, int idx, vector<vector<int>>&allSubseq, vector<int>&subseq){
	if(idx==n){
		allSubseq.push_back(subseq);
		if(subseq.size()==0){
			allSubseq.push_back({});
		}
		return;
	}
	subseq.push_back(arr[idx]);
	genAllSubSeq(arr, n, idx+1, allSubseq, subseq);
	subseq.pop_back();
	genAllSubSeq(arr, n, idx+1, allSubseq, subseq);
}

int main(){
	vector<int>arr{2, 0, 1};
	int n=arr.size();
	int idx=0;
	vector<vector<int>>allSubseq;
	vector<int>subseq;
	genAllSubSeq(arr, n, idx, allSubseq, subseq);
	for(auto &vals: allSubseq){
		for(auto &nums: vals){
			cout<<nums<<" ";
		}
		cout<<endl;
	}
}
