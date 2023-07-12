/*
Minimum number of working days required to achieve each of the given scores

Given an array arr[] consisting of N integers and an array P[] consisting of M
integers such that P[i] represents the score obtained by working on the ith day.
The task is to find the minimum number of days needed to work to achieve a score of at
least arr[i], for each array element arr[i].

Examples:

    Input: arr[] = {400, 200, 700}, P[] = {100, 300, 400, 500, 600}
    Output: 2 2 3 4 5
    Explanation:
    Following are the number of days required for each array elements:

        arr[0](= 400):
        To earn 400 points one has to work for first 2 days making the total points equal to
        100 + 300 = 400(>= arr[0]).

        arr[1](= 200):
        To earn 200 points one has to work for first 2 days making the total points =
        100 + 300 = 400(>= arr[1]).

        arr[2](= 700):
        To earn 700 points one has to work for first 3 days making the total points =
        100 + 300 + 400 = 800(>= arr[2]).

    Input: arr[] = {1400}, P[] = {100, 300}
    Output: -1

*/
/*
Efficient Approach:

	Finding the prefix sum array of P[] and then using binary search to find the sum whose value is at least arr[i]:

    Find the prefix sum array of the array P[].
    Traverse the given array arr[] and perform the following steps:

        Find the index of the first element greater than the current element arr[i] in the
        array P[] and store it in a variable, say index.

        If the value of the index is -1, then print -1. Otherwise, print the value of the
        (index + 1) as the result for the current index.

*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the lower bound
// of N using binary search
int binarySeach(vector<int> P, int N)
{

	// Stores the lower bound
	int i = 0;

	// Stores the upper bound
	int j = P.size() - 1;

	// Stores the minimum index
	// having value is at least N
	int index = -1;

	// Iterater while i<=j
	while (i <= j)
	{
		// Stores the mid index
		// of the range [i, j]
		int mid = i + (j - i) / 2;

		// If P[mid] is at least N
		if (P[mid] >= N)
		{

			// Update the value of
			// mid to index
			index = mid;

			// Update the value of j
			j = mid - 1;
		}

		// Update the value of i
		else
		{
			i = mid + 1;
		}
	}
	return index;
}

// Function to find the minimum number
// of days required to work to at least
// arr[i] points for every array element
void minDays(vector<int> P, vector<int> arr)
{

	// Traverse the array P[]
	for (int i = 1; i < P.size(); i++)
	{

		// Find the prefix sum
		P[i] += P[i] + P[i - 1];
	}

	// Traverse the array arr[]
	for (int i = 0; i < arr.size(); i++)
	{

		// Find the minimum index of
		// the array having value
		// at least arr[i]
		int index = binarySeach(P, arr[i]);

		// If the index is not -1
		if (index != -1)
		{
			cout << index + 1 << " ";
		}

		// Otherwise
		else
		{
			cout << -1 << " ";
		}
	}
}

int main()
{
	vector<int> arr = { 400, 200, 700, 900, 1400 };
	vector<int> P = { 100, 300, 400, 500, 600 };
	minDays(P, arr);

	return 0;
}

/*
Output:

2 2 2 3 3
*/