/*
We have N (where N > 2) stones of various heights laid out in a row

	Task is to make a pyramid from a given arrays of stones

	In a pyramid, height of the stones start from 1, increase by 1, until it reaches some value x

		then decreases by 1 until it reaches 1 again
			i.e. stones should be 1, 2, 3, 4, ... x - 1, x, x-1, x-2, ... 1

	All other stones not part of the pyramid should have a height of 0

		We cannot move any of the stones from their current position, however by paying a fee of 1
			we can reduce the heights of the stones

		We wish to minimize the cost of building a pyramid

	Output the minimum cost to build this pyramid

-------

Examples:

	Input: 1 2 3 4 2 1

	Output: 4

	The best pyramid that can be formed in this case is:

		1 2 3 2 1 0

		The cost is thus:

			(4-2) + (2-1) + (1-1) = 4

	-------

	Input: 1 5 2

	Output: 4

	The best pyramid that we can be formed in this case is

		1 2 1

		The cost is thus:

			(5-3) + (2-1) = 4

	-------

	Input: 1 2 1

	Output: 0

	We already have a pyramid, we do not need to do anything

-------

By using a simple logic we can prove that the pyramid with the least cost of construction would be that
	of the maximum height

	Also two temples of same height would cost the same to construct

	This can be shown as follows:

		Assume the cost of demolishing all the stones to height 0 is x

		Assume the cost of demolishing a temple of height h to height 0 is y

	Then, if it is possible to construct a temple of height h from the given stones, it would cost x-y

	-------

		By using this intuition we can simplify our approach to main two steps

		1. Identify the pyramid of maximum height that can be formed

		2. Calculate the cost of constructing such a pyramid

		Step 2 can be completed in O(N) time complexity assuming we know where our pyramid is placed

		Thus, our focus should be on decreasing the time complexity of step 1

-------

Naive Approach:

	For each position in the array we can assume the pyramid starts at that point.

	We can then find the cost of constructing a temple of maximum height from 1 onwards
		until a higher height is not possible, that is assume a pyramid of height 1 is the maximum,
		then assume 2 is maximum and so on

	Out of each of these costs, we can then choose the minimum

	This approach uses a time complexity of O(N^3)

-------

Improved Approach:

	For each position, assume that it is the center of a temple.

	Move to the left and right of this point and attempt to find the maximum height of the temple

	This can be done by setting the maximum height of a temple at position i to be H(i)
		where H(i) is the height of the stone at that point

	We then move to the left

		If the height of the stone at this point is less than H(i)-1, we set the maximum height
			to now be H(i-1) + 1

		In this way we can identify the maximum height of each position

	This approach uses the time complexity of O(N^2)

-------

Dynamic Programming Approach:

	By modifying the above algorithm slightly, we can attempt to get an O(N) approach

	Start at the left, and moving right, find the maximum possible height of the pyramid that can be
		created at that position

	Assume that the part of the array to the right of that position is a mirror image of the left

	If H(i) is the height of the stone at position i, then
		maxHeight(i) = Minimum(H(i), i, maxHeight(i - 1))

	-------

	This can be explained as follows:

		The maximum possible height cannot exceed H(i) as we can only decrease the height of the stone,
			not increase

		The maximum possible height cannot exceed i, as the pyramid has to start from a height i

		The maximum possible height cannot exceed the maximum possible height of the stone before
			(i - 1) as the stones have to increase by 1 for each step

	We can calculate the similar value moving from right to left

	We can then take the minimum of these values for each position

		Then by identifying the maximum, we can calculate the minimum cost of constructing a pyramid

*/

import java.util.*;

class CFG {

	static int minPyramidCost(int[] arr, int N) {
		int left[] = new int[N];
		int right[] = new int[N];
		// maximum height at start is 1
		left[0] = Math.min(arr[0], 1);
		// for each position calculate maximum height
		for (int i = 0; i < N; ++i) {
			left[i] = Math.min(arr[i], Math.min(left[i - 1] + 1, i + 1));
		}
		// maximum height at the end is 1
		right[N - 1] = Math.min(arr[N - 1], 1);
		// for each position calculate maximum height
		for (int i = N - 2; i >= 0; --i) {
			right[i] = Math.min(arr[i], Math.min(right[i + 1] + 1, N - i));
		}
		// finding minimum possible among the calculated values
		int tot[] = new int[N];
		for (int i = 0; i < N; ++i) {
			tot[i] = Math.min(right[i], left[i]);
		}
		// finding maximum height of the pyramid
		int max_ind = 0;
		for (int i = 0; i < N; ++i) {
			if (tot[i] > tot[max_ind]) {
				max_ind = i;
			}
		}
		// calculating the cost of this pyramid
		int cost = 0;
		int height = tot[max_ind];

		// calculate cost of left half
		for (int x = max_ind; x >= 0; --x) {
			cost += arr[x] - height;
			if (height > 0) --height;
		}
		// calculate cost of the right half
		height = tot[max_ind] - 1;
		for (int x = max_ind + 1; x < N; ++x) {
			cost += arr[x] - height;
			if (height > 0) --height;
		}
		return cost;
	}
}