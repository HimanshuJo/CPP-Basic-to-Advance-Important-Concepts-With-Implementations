/*
Given a set of positive integers, find all its subsets

Input: array = {1, 2, 3}
Output: // this space denotes null element.
         1
         1 2
         1 2 3
         1 3
         2
         2 3
         3
Explanation: These are all the subsets that
can be formed using the array.

Input: 1 2
Output:
         1
         2
         1 2
Explanation: These are all the subsets that
can be formed using the array.

-------

Backtracking Approach:

	The idea is simple, that is there are n number of elements inside an array, there are two choices
		for every element.

		Either we can include that element in the subset or do not include it

	Using this idea, we can form a recursive approach to solve the problem

	-------

	Algorithm:

		1. Create a recursive function that takes the following parameters,
				an input array,
				the current index,
				the output array or the current subset

				if all the subsets needs to be stored then a vector of array is needed

		2. If the current index is equal to the size of the array, then print the subset or the output array
			or insert the output array into the vector of arrays (or vectors) and return

		3. There are exactly two choices for every index

		4. Ignore the current element and call the recursive function with the current subset and next index,
			i.e: i + 1

		5. Insert the current element in the subset and call the recursive function with the current subset and next
			index, i.e: i + 1

*/

#include<bits/stdc++.h>
using namespace std;

// In the array A at every step we have two choices for each element either, we can ignore
// the element or we can include the element in our subset
void subsetsUtil(vector<int>& A, vector<vector<int>>& res, vector<int>& subset, int index) {
	res.push_back(subset);
	for (int i = index; i < A.size(); ++i) {
		// include the A[i] in subset
		subset.push_back(A[i]);
		// move onto the next element
		subsetsUtil(A, res, subset, i + 1);
		// exclude the A[i] from subset and triggers
		// backtracking
		subset.pop_back();
	}
	return;
}

// function that will call the subsetsUtil and returns the subsets of vector A
vector<vector<int>> subsets(vector<int>& A) {
	vector<int> subset;
	vector<vector<int>> res;
	// keeps track of the current element in vector A
	int index = 0;
	subsetsUtil(A, res, subset, index);
	return res;
}

int main() {
	// find the subsets of the below vector
	vector<int> array = {1, 2, 3};
	// res will store all the subsets
	// O(2^(number of elements inside the array))
	// because at every step we have two choices
	// either include or ignore
	vector<vector<int>> res = subsets(array);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

/*
Output:

1
1 2
1 2 3
1 3
2
2 3
3

-------

Complexity:

	Time: O(2^n)

		For every index two recursive cases originates.

		So time is O(2^n)

	Space:

		O(n)

-------

Sample Question:

	The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.

	Given an array nums, return the sum of all XOR totals for every subset of nums.

	Note: Subsets with the same elements should be counted multiple times.

	An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

	Input: nums = [1,3]
	Output: 6
	Explanation: The 4 subsets of [1,3] are:
	- The empty subset has an XOR total of 0.
	- [1] has an XOR total of 1.
	- [3] has an XOR total of 3.
	- [1,3] has an XOR total of 1 XOR 3 = 2.
	0 + 1 + 3 + 2 = 6

	-------

	public class Solution {

		public int subsetXORSum(int[] nums) {
			List<List<Integer>> res = new ArrayList<>();
			List<Integer> curr = new ArrayList<>();
			backtrack(res, curr, nums, 0);
			int ans = 0;
			for (List<Integer> list : res) {
				int currXOR = 0;
				for (int val : list) {
					currXOR ^= val;
				}
				ans += currXOR;
			}
			return ans;
		}

		public void backtrack(List<List<Integer>> res, List<Integer> curr, int[] nums, int pos) {
			res.add(new ArrayList<>(curr));
			for (int i = pos; i < nums.length; ++i) {
				curr.add(nums[i]);
				backtrack(res, curr, nums, i + 1);
				curr.remove(curr.size() - 1);
			}
		}
	}
*/