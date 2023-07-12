/*
Maximize the bitwise OR of an array

Given an array of N integers. 
The bitwise OR of all the elements of the array has to be maximized by performing one task. 
The task is to multiply any element of the array at-most k times with a given integer x.

Examples : 

Input: a = {1, 1, 1}, k = 1, x = 2 
Output: 3 

Explanation: Any possible choice of doing one element 
of the array will result the same three numbers 1, 1, 2. 

So, the result is 1 | 1 | 2 = 3.

Input: a = {1, 2, 4, 8}, k = 2, x = 3 
Output: 79

*/
/*
Approach:

	Precompute the prefix and suffix OR arrays

	In one iteration, multiply an element with x^k and do Bitwise OR it with 

	prefix OR, i.e Bitwise OR of all the previous elements and 
	
	suffix OR i.e Bitwise OR of all the next elements and 

	return the maximum value after all the iterations

*/

#include<bits/stdc++.h>
using namespace std;

int maxOR(long long arr[], int n, int k, int x) {
	long long preSum[n + 1], suffSum[n + 1];
	long long res, pow = -1;
	for (int i = 0; i < k ; ++k) {
		pow *= x;
	}
	preSum[0] = 0;
	for (int i = 0; i < n; ++i) {
		preSum[i + 1] = preSum[i] | arr[i];
	}
	suffSum[n] = 0;
	for (int i = n - 2; i >= 0; --i) {
		suffSum[i] = suffSum[i + 1] | arr[i];
	}
	res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, preSum[i] | (arr[i] * pow) | suffSum[i + 1]);
	}
	return res;
}

int main() {
	long long arr[] = {1, 2, 4, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2, x = 3;
	cout << maxOr(arr, n, k, x) << "\n";
	return 0;
}

/*
Output:

	79
*/