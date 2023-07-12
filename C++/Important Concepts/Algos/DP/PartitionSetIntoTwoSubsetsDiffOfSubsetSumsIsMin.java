/*
Given a set of integers, the task is to divide it into two sets S1 and S2 such that the absolute
	difference between their sums is minimum

	If there is a set S with n elements,

		then if we assume Subset1 has m elements

		Subset2 must have n - m elements and the

		value of abs(sum(Subset1) - sum(Subset2)) should be minimum

	-------

	Example:

		arr[] = {1, 6, 11, 5}
		Output = 1

		Subset1 = {1, 5, 6}, sum of Subset1 = 12

		Subset2 = {11}, sum of Subset2 = 11

*/
/*
Recursive Solution:

	The recursive approach is to generate all possible sums from all the values of the array and to check
		which solution is the most optimal one

		To generate sums we either include the i'th item in set 1 or don't include, i.e include in set 2

*/
/*
Dynamic Programming:

	The problem can be solved using DP when the sum of the elements is not too big

	We can create a DP array dp[n + 1][sum + 1] where n is a number of elements in a given set
		and sum is the sum of all the elements

		We can construct the solution in a bottom up manner

	-------

	The task is to divide the set into two parts

	We will consider the following factors for dividing it

		Let dp[n + 1][sum + 1] = {1 if some subset from 1st to i'th has a sum equal to j

								  0 otherwise
								}

		    i ranges from {1 .. n}

		    j ranges from {0 .. (sum of all the elements)}

	    So

	    	dp[n + 1][sum + 1] will be 1 if

	    		a. The sum j is achieved including i'th item

	    		b. The sum j is achieved excluding i'th item

		Let the sum of all the elements be S

		To find the minimum sum difference, we have to find j such that

			Min{sum - j * 2 : dp[n][j] == 1}

				where j varies from 0 to sum / 2

		The idea is sum of S1 is j and it should be closest to sum / 2

			i.e. 2 * j should be the closest

*/
/*
import java.io.*;

class CFG {

	// Returns the minimum value of the difference of the two sets

	static int findMin(int arr[], int n) {

		// calculate the sum of all the elements
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			sum += arr[i];
		}

		// create an array to store the results of the subproblems
		boolean [][]dp = new boolean[n + 1][sum + 1];

		// initialize first column as true
		// 0 sum is possible with all the elements
		for (int i = 0; i <= n; ++i)
			dp[i][0] = true;

		// initialize top row, except dp[0][0], as false
		// with 0 elements, no other sum except 0 is possible
		for (int i = 1; i <= sum; ++i)
			dp[0][i] = false;

		// fill the partition table in bottom up manner
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= sum; ++j) {

				// if i'th element is excluded
				if (dp[i][j] = dp[i - 1][j])

				// if i'th element is included
				if (arr[i - 1] <= j)
					dp[i][j] |= dp[i - 1][j - arr[i - 1]];
			}
		}

		// initialize the difference of two sums
		int diff = Integer.MAX_VALUE

		// find the largest j such that dp[n][j] is true
		// where j loops from sum / 2 to 0

		for (int j = sum / 2; j >= 0; --j) {
			if (dp[n][j] == true) {
				diff = sum - 2 * j;
				break;
			}
		}

		return diff;
	}
}

-------

Time Complexity:

	O(n * sum) where n is the number of elements and sum is the sum of all the elements
*/

//Recursive Solution:

import java.util.*;

class CFG {

	public static int findMinRec(int arr[], int n, int sumCalculated, int sumTotal) {

		// if we have reached the last element, sum of one subset is sumCalculated
		// sum of other subset is sumTotal - sumCalculated
		// finally we return the absolute difference of two sums

		if (n == 0)
			return Math.abs((sumTotal - sumCalculated) - sumCalculated);

		// for every item arr[i], we have two choices
		// 1. Either we do not include it in the first set
		// 2. Or we include it in the first set
		// we can return the minimum of two choices

		return Math.min(findMinRec(arr, n - 1, sumCalculated + arr[n - 1], sumTotal),
		                findMinRec(arr, n - 1, sumCalculated, sumTotal));
	}

	public static int findMin(int arr[], int n) {

		// compute total sum of elements
		int sumTotal = 0;
		for (int i = 0; i < n; ++i) {
			sumTotal += arr[i];
		}

		return findMinRec(arr, n, 0, sumTotal);
	}
}

/*

Time Complexity:

	All the sums can be generated by either
		a. including that element in set 1

		b. without including that element in set 1

		So the possible combinations are:

			arr[0] (1 or 2) -> 2 values
			arr[1] (1 or 2) -> 2 values
			...

			arr[n] (2 or 2) -> 2 values

			So the time complexity will be 2 * 2 ... * 2 (for n times)

				that is O(2^n)

*/