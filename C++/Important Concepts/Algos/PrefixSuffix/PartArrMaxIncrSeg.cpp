/*
Partition an array such into maximum increasing segments

We are given an array of N integers, we need to partition the array into segments such
that every element of a segment is greater than every element of previous segment.

In other words, if we sort these individual segments, the whole array becomes sorted.
We need to find a valid partition with maximum number of subarrays.

Examples:


    arr[] = {3 1 2 4 100 7 9}
    Output : 3
    You should partition the array into the following subarrays: (3, 1, 2), (4) and (100, 7, 9).
    Input : arr[] = {2 1 2 3 3 4 3}
    Output : 5

    arr[] = {4, 5, 6, 7, 8, 9}
    Output: 6 (4, 5, 6, 7, 8, 9)

    arr[] = {10, 9, 8, 7, 6, 5}
    Output: 1
    Explanation: {(5), (10, 9, 8, 7, 6)}
*/
/*
Approach:

	A greedy approach works really well as it leads to the following algorithm.
	Find the shortest prefix such that all the elements in the prefix are less than or equal to
	the elements in the rest of the array.

	Consider this prefix as the first subarray of the partition.

	Recursively call the same algorithm on the rest of the array.

	Implementation wise, we can preprocess an array of 'max values' for each prefix and
	another array of 'min values' for each suffix.

	This way we can easily perform a check to see if a given prefix is a viable candidate for a partition subarray.

*/

#include <iostream>
using namespace std;

// Returns the maximum number of sorted subarrays
// in a valid partition
int sorted_partitions(int arr[], int n)
{

	int right_min[n + 1];
	right_min[n] = INT8_MAX;
	for (int i = n - 1; i >= 0; i--) {
		right_min[i] = min(right_min[i + 1], arr[i]);
	}

	// Finding the shortest prefix such that all the elements
	// in the prefix are less than or equal to the elements
	// in the rest of the array.
	int partitions = 0;
	for (int current_max = arr[0], i = 0; i < n; i++) {
		current_max = max(current_max, arr[i]);

		// if current max is less than the right prefix min,
		// we increase number of partitions.
		if (current_max <= right_min[i + 1])
			partitions++;
	}

	return partitions;
}

int main()
{
	int arr[] = { 3, 1, 2, 4, 100, 7, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	// Find minimum value from right for every index
	int ans = sorted_partitions(arr, n);
	cout << ans << endl;
	return 0;
}
