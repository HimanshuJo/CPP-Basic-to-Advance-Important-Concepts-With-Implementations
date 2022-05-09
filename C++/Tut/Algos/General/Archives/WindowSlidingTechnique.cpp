/*
Window sliding technique shows how a nested loop in some problems can be converted to a single for loop
	to reduce the time complexity

	E.g.

		Suppose we have an array of size 4

			arr = {100, 200, 300, 400}

			k = 2

		Our task is to calculate the maximum sum of 'k' consecutive elements in the array

		In this case the answer will be 700 -> (300, 400)

		-------

			arr = {1, 4, 2, 10, 23, 3, 1, 0, 20}

			k = 4

			Output = 39

			We get a maximum sum by adding subarray {4, 2, 10, 23}

	-------

	let's analyze the problem with the Brute Force technique

	We can start with the first index and sum till k-th element

	We do it for all possible consecutive blocks or groups of size k elements

	This method requires nested loops, the outer loop starts with the starting element of the block
		of k elements and the inner or the nested loop will add up till the k-th element

	-------

	O(n * k) solution for finding maximum sum of a subarray of size k

		#include <bits/stdc++.h>
		using namespace std;

		// Returns maximum sum in a subarray of size k.
		int maxSum(int arr[], int n, int k)
		{
			// Initialize result
			int max_sum = INT_MIN;

			// Consider all blocks starting with i.
			for (int i = 0; i <= n - k; i++) {
				int current_sum = 0;
				for (int j = 0; j < k; j++)
					current_sum = current_sum + arr[i + j];

				// Update result if required.
				max_sum = max(current_sum, max_sum);
			}

			return max_sum;
		}

		int main()
		{
			int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
			int k = 4;
			int n = sizeof(arr) / sizeof(arr[0]);
			cout << maxSum(arr, n, k);
			return 0;
		}

	Output
	24

	It can be observed that the above code has the time complexity O(k * n) as it contains two nested loops
*/
/*
Window sliding technique:

	The technique can be best understood with the window pane in a bus,

		let's consider a window of length 'n' and the plane which is fixed in it of length 'k'

		Consider initially the plane is at extreme left i.e at 0 units from the left

		Now we co-relate the window with the array[] of size n and the plane with the size k elements

		Now if we apply force on the window such that it moves a unit distance ahead

			The pane will cover next k consecutive elements

		Consider an array arr[] = {5, 2, -1, 0, 3} and the value of k = 3 and n = 5

	-------

	Applying sliding window technique:

		1. We can compute the sum of first k elements out of n terms using a linear loop and store the sum
			in a variable 'window_sum'

		2. Then we will graze linearly over the array till it reaches the end and simultaneously keep track
			of the maximum sum

		3. To get the current sum of block of k elements just

			subtract the first element from the previous block and

			add the last element of the current block

			e.g. let's suppose initially our array is {5, 2, -1, 0, 3} and k = 3

					current_sum = window_sum (that is 6)

				Now we slide our window by a unit index

				Therefore, now it discards 5 from the window and adds 0 to the window

					Hence, we will get our new window sum by subtracting 5 and then adding 0 to it

					So, our window_sum will be {2 + (-1) + 0}

					current_sum becomes (window_sum - 5)

		we follow the same procedure until the sliding window reaches the end of the array
*/

//O(n) solution for finding maximum sum of a sub-array of size k

#include <iostream>
using namespace std;

int maxSum(int arr[], int n, int k)
{
	// n must be greater
	if (n < k) {
		cout << "Invalid";
		return -1;
	}

	// Compute sum of first window of size k
	int max_sum = 0;
	for (int i = 0; i < k; i++)
		max_sum += arr[i];

	// Compute sums of remaining windows by
	// removing first element of previous
	// window and adding last element of
	// current window.
	int window_sum = max_sum;
	for (int i = k; i < n; i++) {
		window_sum += arr[i] - arr[i - k];
		max_sum = max(max_sum, window_sum);
	}

	return max_sum;
}

int main()
{
	int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 };
	int k = 4;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << maxSum(arr, n, k);
	return 0;
}

/*
Output
24

-------

Illustration:

	Suppose our array is:

		{1, 4, 2, 10, 2, 3, 1, 0, 20} and k = 4

		Initially max_sum = (1 + 4 + 2 + 10) = 17

		window_sum = max_sum

		Next we will start at i = 4 or arr[4] = 2
			window_sum = 17 + 2 - arr[i - k]
					   = 17 + 2 - arr[0]
					   = 19 - 1 = 18

		   max_sum = Math.max(max_sum, window_sum)
		   		   = Math.max(17, 18) = 18

	   	Next we will continue at i = 5 or arr[5] = 3
	   		window_sum = 18 + 3 - arr[5 - 4]
	   				   = 21 - 4 = 17

		   	max_sum = Math.max(18, 17) = 18

	   	...

	   	17 + 1 - 2 = 16, 18
	   	16 + 0 - 10 = 6, 18
	   	6 + 20 - 2 = 24, 18
*/