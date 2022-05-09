/*
Find the number of sub arrays in the permutation of first N natural numbers
such that their median is M

Given an array arr[] containing the permutation of first N natural numbers and an
integer M ≤ N. The task is to find the number of sub-arrays such that the median of the sequence is M.

The median of a sequence is the value of the element which is in the middle of
the sequence after sorting it in non-decreasing order.
If the length of the sequence is even, the left of two middle elements is used.

Examples:

    Input: a[] = { 2, 4, 5, 3, 1}, M = 4
    Output: 4
    The required sub-arrays are {2, 4, 5}, {4}, {4, 5} and {4, 5, 3}.


    Input: a[] = { 1, 2, 3, 4, 5}, M = 5
    Output: 1

*/
/*
Approach:

	The segment p[l..r] has a median equals M if and only if M belongs to it and
	less = greater or less = greater – 1, where less is the number of elements in p[l..r]
	that are strictly less than M and greater is a number of elements in p[l..r]
	that are strictly greater than M.

	Here we’ve used a fact that p is a permutation (on p[l..r] there is exactly one occurrence of M).

	In other words, M belongs to p[l..r], and the value greater – less equals 0 or 1

	Calculate prefix sums sum[0..n], where sum[i] the value greater-less on the prefix of the
	length i (i.e., on the subarray p[0..i-1]).

	For the fixed value r it is easy to calculate the number of l so that p[l..r] is suitable.
	First, check that M met on [0..r].

	Valid values l are such indices that: no M on [0..l-1] and sum[l]=sum[r] or sum[r]=sum[l]+1.

	Let’s keep a number of prefix sums sum[i] to the left of M for each value.
	We can just use a map c, where c[s] is a number of indices l that sum[l]=s
	and l are to the left of m.

	So, for each r that p[0..r] contains m do ans += c[sum] + c[sum – 1],
	where sum is the current value greater-less.

*/
/*

import java.util.HashMap;

class GFG
{

	// Function to return the count of sub-arrays
	// in the given permutation of first n natural
	// numbers such that their median is m
	public static int segments(int n, int[] p, int m)
	{
		HashMap<Integer, Integer> c = new HashMap<>();
		c.put(0, 1);
		boolean has = false;
		int sum = 0;
		int ans = 0;
		for (int r = 0; r < n; r++)
		{

			// If element is less than m
			if (p[r] < m)
				sum--;

			// If element greater than m
			else if (p[r] > m)
				sum++;

			// If m is found
			if (p[r] == m)
				has = true;

			// Count the answer
			if (has)
				ans += (c.get(sum) == null ? 0 : c.get(sum)) + (c.get(sum - 1) == null ? 0 : c.get(sum - 1));

			// Increment sum
			else
				c.put(sum, c.get(sum) == null ? 1 : c.get(sum) + 1);
		}
		return ans;
	}

	public static void main(String[] args)
	{
		int[] a = { 2, 4, 5, 3, 1 };
		int n = a.length;
		int m = 4;
		System.out.println(segments(n, a, m));
	}
}
*/

#include <bits/stdc++.h>
using namespace std;

// Function to return the count of sub-arrays
// in the given permutation of first n natural
// numbers such that their median is m
int segments(int n, int p[], int m)
{
	map<int, int> c;
	c[0] = 1;
	bool has = false;
	int sum = 0;
	long long ans = 0;
	for (int r = 0; r < n; r++) {

		// If element is less than m
		if (p[r] < m)
			sum--;

		// If element greater than m
		else if (p[r] > m)
			sum++;

		// If m is found
		if (p[r] == m)
			has = true;

		// Count the answer
		if (has)
			ans += c[sum] + c[sum - 1];

		// Increment sum
		else
			c[sum]++;
	}

	return ans;
}

int main()
{
	int a[] = { 2, 4, 5, 3, 1 };
	int n = sizeof(a) / sizeof(a[0]);
	int m = 4;
	cout << segments(n, a, m);

	return 0;
}
