/*
Given weights and values of n items, put these items in a knapsack of capacity W
to get the maximum total value in the knapsack.
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which
represent values and weights associated with n items respectively.

Also given an integer W which represents knapsack capacity, find out the maximum value
subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).
*/

#include <bits/stdc++.h>
using namespace std;

int dfs(int W, int wt[], int val[], int i, int** memo)
{
	if (i < 0)
		return 0;
	if (memo[i][W] != -1)
		return memo[i][W];
	if (wt[i] > W) {
		return memo[i][W] = dfs(W, wt, val, i - 1, memo);
	}
	else {
		return memo[i][W] = max(val[i] + dfs(W - wt[i], wt, val, i - 1, memo), dfs(W, wt, val, i - 1, memo));
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	int** memo;
	memo = new int*[n];
	for (int i = 0; i < n; i++)
		memo[i] = new int[W + 1];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			memo[i][j] = -1;
	return dfs(W, wt, val, n - 1, memo);
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}
