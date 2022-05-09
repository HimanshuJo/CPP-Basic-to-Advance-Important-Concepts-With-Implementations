// Given an array sequence arr[] i.e [A1, A2 …An] and an integer k, 
// the task is to find the maximum possible sum of
// increasing subsequence S of length k such that S1<=S2<=S3………<=Sk.
/*
Input: arr[] = {-1, 3, 4, 2, 5}, K = 3
Output: 3 4 5
Explanation: Subsequece 3 4 5 with sum 12 is the subsequence with maximum possible sum.

Approach: The task can be solved using Greedy Approach.
The idea is to take the maximum possible elements from arr[] in the subsequence. 

Follow the steps below to solve the problem.

Declare a vector of pairs container say, use[] to store elements with their indices.
Traverse arr[] and push all the elements in use[] with their indices.
Sort use[] in non-decreasing order.
Declare a vector ans[] to store the final subsequence.
Traverse use[] with i and Take the last K element from use and push their 
indices(use[i].second) into ans[].
Sort ans[] in non-decreasing order so that indices should be in increasing order.
Now Traverse ans[] with i and replace each element with arr[ans[i]].
Return ans[] as the final maximum sum subsequence.
*/

// C++ program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find the subsequence
// with maximum sum of length K
vector<int> maxSumSubsequence(vector<int>& arr, int N, int K)
{

	// Use an extra array to keep
	// track of indices while sorting
	vector<pair<int, int>> use;

	for (int i = 0; i < N; i++) {
		use.push_back({ arr[i], i });
	}

	// Sorting in non-decreasing order
	sort(use.begin(), use.end());

	// To store the final subsequence
	vector<int> ans;

	// Pushing last K elements in ans
	for (int i = N - 1; i >= N - K; i--) {

		// Pushing indices of elements
		// which are part of final subsequence
		ans.push_back(use[i].second);
	}

	// Sorting the indices
	sort(ans.begin(), ans.end());

	// Storing elements corresponding to each indices
	for (int i = 0; i < int(ans.size()); i++)
		ans[i] = arr[ans[i]];

	// Return ans as the final result
	return ans;
}

// Driver Code
int main()
{

	int N = 9;
	vector<int> arr = { 6, 3, 4, 1, 1, 8, 7, -4, 2 };

	int K = 5;

	// Storing answer in res
	vector<int> res = maxSumSubsequence(arr, N, K);

	// Printing the result
	for (auto i : res)
		cout << i << ' ';

	return 0;
}
