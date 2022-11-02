/*
	Given an array sequence arr[] i.e [A1, A2 …An] and an integer k, the task is to find the 
	maximum possible sum of increasing sub-sequence S of length k such that S1<=S2<=S3………<=Sk.
*/
/*
Input: arr[] = {-1, 3, 4, 2, 5}, K = 3
Output: 3 4 5
Explanation: Subsequece 3 4 5 with sum 12 is the subsequence with maximum possible sum.

Approach: The task can be solved using Greedy Approach.
	      
	      The idea is to take the maximum possible elements from arr[] in the subsequence. 

Algo:

	Declare a vector of pairs container say, use[] to store elements with their indices.

	Traverse arr[] and push all the elements in use[] with their indices.

	Sort use[] in ascending order.

	Declare a vector ans[] to store the final subsequence.

	Traverse use[] with i and Take the last K element from use and push their 
	indices(use[i].second) into ans[].

	Sort ans[] in non-decreasing order so that indices should be in increasing order.

	Now Traverse ans[] with i and replace each element with arr[ans[i]].

	Return ans[] as the final maximum sum subsequence.
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> maxSumSubsequence(vector<int>&arr, int K){
    vector<pair<int, int>>arrcomb;
    int sz=arr.size();
    for(int i=0; i<sz; ++i){
        arrcomb.push_back({arr[i], i});
    }
    sort(arrcomb.begin(), arrcomb.end());
    vector<int>ans;
    for(int i=sz-1; i>=sz-K; --i){
        ans.push_back(arrcomb[i].second);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int>arr{6, 3, 4, 1, 1, 8, 7, -4, 2};
    int K=5;
    vector<int>res=maxSumSubsequence(arr, K);
    for(auto &vals: res){
        cout<<arr[vals]<<" ";
    }
}