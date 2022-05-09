// Find the smallest missing number, duplicates are allowed
/*
Given a sorted array of n distinct integers where each integer is in the range from 0 to m-1 
and m > n. Find the smallest number that is missing from the array. 

Examples 

Input: {0, 1, 2, 6, 9}, n = 5, m = 10 
Output: 3

Input: {4, 5, 10, 11}, n = 4, m = 12 
Output: 0

Input: {0, 1, 2, 3}, n = 4, m = 5 
Output: 4

Input: {0, 1, 2, 3, 4, 5, 6, 7, 10}, n = 9, m = 11 
Output: 8
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int binarySearch(vector<int>&in, int n){
	int left=0, right=n-1;
	int ans=-1;
	while(left<=right){
		int mid=left+(right-left)/2;
		if(in[mid]!=mid){
			ans=mid;
			right=mid-1;
		} else{
			left=mid+1;
		}
	}
	return (ans==-1?n:ans);
}

int smallestMissingNumber(vector<int>&in, int n){
	return (binarySearch(in, n));
}

int main(){
	vector<int>in{0, 1, 1, 1, 1, 1, 1, 2, 4};
	set<int>st;
	for(auto &vals: in)
		st.insert(vals);
	vector<int>inct;
	for(auto &vals: st)
		inct.push_back(vals);
	int n=inct.size();
	int ans=smallestMissingNumber(inct, n);
	cout<<ans<<endl;
}