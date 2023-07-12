/*
Given an array [] and an integer X, the task is to find the longest subarray such that
	the sum of its elements isn't divisible by X

	Input: arr[] = {1, 2, 3} X = 3
	Output: 2 3

	Explanation:
		The subarray {2, 3} has a sum of elements 5, which isn’t divisible by 3.

	Input: arr[] = {2, 6} X = 2
	Output: -1

	Explanation:
		All possible subarrays {1}, {2}, {1, 2} have an even sum.
		Therefore, the answer is -1.
*/
/*
	Naive Approach:

		The simplest approach to solve the problem is to generate all the possible subarrays
			and keep calculating its sum

			If any subarray is found to have sum not divisible by X, compare the length
				with the maximum length obtained(maxm) and update the maxm accordingly

				and update the starting and ending index of the subarray

			Print the subarray having the stored starting and ending indices

		Time Complexity:

			O(n^2)

		Auxiliary Space:

			O(1)

	-------

	Efficient Approach:

		To optimize the above approach we will find the prefix and the suffix array sum

			1. Generate the prefix sum array and suffix sum array

			2. Iterate from [0, N - 1] using Two Pointers and choose the prefix and suffix
				sum of the element at each index which is not divisible by X

				Store the starting index and the ending index of the subarray

			3. After completing the above steps, if there exist a subarray with sum not
				divisible by X, then print the subarray having the stored starting and ending indices

			4. If there is no such sub-array then print -1
*/
/*

import java.util.*;

class CFG {

	static void max_length(int N, int x, int[] v) {

		int i, a;

		List<Integer> preff = new Vector<Integer>();
		List<Integer> suff = new Vector<Integer>();

		int ct = 0;

		for (int i = 0; i < N; ++i) {
			a = v[i];
			if (a % x == 0) {
				ct += 1;
			}
		}

		if (ct == N) {
			System.out.println(-1);
			return;
		}

		//reverse v to calculate the suffix sum
		v = reverse(v);

		suff.add(v[0]);

		//calculating the suffix sum
		for (int i = 1; i < N; ++i) {
			suff.add(v[i] + suff.get(i - 1));
		}

		//reverse the suffix sum array
		Collections.reverse(suff);

		//reverse to original form
		v = reverse(v);

		preff.add(v[0]);

		for (int i = 0; i < N; ++i) {
			preff.add(v[i] + pref.get(i - 1));
		}

		int ans = 0;

		//storing the starting index of the required subarray
		int lp = 0;

		//storing the ending index of the required subarray
		int rp = N - 1;

		for (int i = 0; i < N; ++i) {
			//if suffix sum till i-th index is not divisible by x
			if (suff.get(i) % x != 0 && (ans < (N - 1))) {
				lp = i;
				rp = N - 1;
				ans = Math.max(ans, N - i);
			}

			//if prefix sum till i-th index is not divisible by x
			if (pref.get(i) % x != 0 && (ans < (N - 1))) {
				lp = 0;
				rp = i;
				ans = Math.max(ans, i + 1);
			}
		}

		for (i = lp; i <= rp; ++i) {
			System.out.println(v[i] + " ");
		}
	}

	static int[] reverse (int a[]) {
		int i, n = a.length, t;
		for (int i = 0; i < n / 2; ++i) {
			t = a[i];
			a[i] = a[n - i - 1];
			a[n - i - 1] = t;
		}
		return a;
	}
}
*/

#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> lngstSubArrayNotDivByX(vector<int>&in, int N, int X) {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (in[i] % X == 0) cnt++;
	}
	if (cnt == N) return { -1 };
	vector<int>prefSum(N, 0);
	vector<int>suffSum(N, 0);
	prefSum[0] = in[0];
	for (int i = 1; i < N; ++i) {
		prefSum[i] = prefSum[i - 1] + in[i];
	}
	suffSum[N - 1] = in[N - 1];
	for (int i = N - 2; i >= 0; --i) {
		suffSum[i] = suffSum[i + 1] + in[i];
	}
	int bgnidx = 0, endidx = N - 1, ans = 0;
	for (int i = 0; i < N; ++i) {
		if (suffSum[i] % X != 0 && (ans < (N - 1))) {
			bgnidx = i, endidx = N - 1, ans = max(ans, N - i);
		}
		if (prefSum[i] % X != 0 && (ans < (N - 1))) {
			bgnidx = 0, endidx = i, ans = max(ans, i + 1);
		}
	}
	vector<int>fnres;
	for (int i = bgnidx; i <= endidx; ++i) {
		fnres.push_back(in[i]);
	}
	return fnres;
}

int main() {
	vector<int>in{2, 6};
	int N = 2, X = 2;
	vector<int>res = lngstSubArrayNotDivByX(in, N, X);
	for (auto &vals : res)
		cout << vals << " ";
}
