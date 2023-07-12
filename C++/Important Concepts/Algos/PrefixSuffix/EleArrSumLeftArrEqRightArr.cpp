/*
Find an element in array such that sum of left array is equal to sum of right array

Given, an array of size n. Find an element that divides the array into two sub-arrays with equal sums.
Examples:

Input: 1 4 2 5
Output: 2
Explanation: If 2 is the partition, subarrays are : {1, 4} and {5}

Input: 2 3 4 1 4 5
Output: 1
Explanation: If 1 is the partition, Subarrays are : {2, 3, 4} and {4, 5}

Input: 1 2 3 4 5
Output: -1
Explanation: No partition exists

*/
/*
Method 2 (Using Prefix and Suffix Arrays :

We form a prefix and suffix sum arrays

Given array: 1 4 2 5
Prefix Sum:  1 5 7 12
Suffix Sum:  12 11 7 5

Now, we will traverse both prefix arrays.
The index at which they yield equal result,
is the index where the array is partitioned
with equal sum.
*/

/*
Method 3 (Space efficient)

	We can calculate the sum of the whole array 'except' the first element in right_sum,
	considering it to be the partitioning element.

	Now, we can traverse the array from left to right, subtracting an element from
	right_sum and adding an element to left_sum.

	At the point where right_sum equals left_sum, we get the partition.
*/

/*
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int size)
{
	int right_sum = 0, left_sum = 0;

	// Computing right_sum
	for (int i = 1; i < size; i++)
		right_sum += arr[i];

	// Checking the point of partition
	// i.e. left_Sum == right_sum
	for (int i = 0, j = 1; j < size; i++, j++) {
		right_sum -= arr[j];
		left_sum += arr[i];

		if (left_sum == right_sum)
			return arr[i + 1];
	}

	return -1;
}

int main()
{
	int arr[] = { 2, 3, 4, 1, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << findElement(arr, size);
	return 0;
}

Output

1

Time: O(n)
Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n)
{
	int prefixSum[n];
	prefixSum[0] = arr[0];
	for (int i = 1; i < n; i++)
		prefixSum[i] = prefixSum[i - 1] + arr[i];
	int suffixSum[n];
	suffixSum[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
		suffixSum[i] = suffixSum[i + 1] + arr[i];
	for (int i = 1; i < n - 1; i++)
		if (prefixSum[i] == suffixSum[i])
			return arr[i];
	return -1;
}

int main()
{
	int arr[] = { 1, 4, 2, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << findElement(arr, n);
	return 0;
}

/*
Output

2

Time: O(n)
Space: O(n)
*/
