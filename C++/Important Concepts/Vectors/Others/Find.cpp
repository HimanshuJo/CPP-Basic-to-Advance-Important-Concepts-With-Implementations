/*
std::find:

	Finds the element in the given range of numbers.

	Returns an iterator to the first element in the range [first,last) that compares equal to val.

	If no such element is found, the function returns last.

	-------

	InputIterator find (InputIterator first, InputIterator last, const T& val)

	first, last :

		Input iterators to the initial and final positions in a sequence. The range
		searched is [first,last), which contains all the elements between first and
		last, including the element pointed by first but not the element pointed by last.

	val :

		Value to be search in the range

	Return Value :

		An iterator to the first element in the range that compares equal to val.

		If no elements match, the function returns last.
*/

/*
Find index of a given element

Given a vector V consisting of N integers and an element K, the task is to find the index of
element K in the vector V. If the element does not exist in vector then print -1.

Examples:

Input: V = {1, 45, 54, 71, 76, 17}, K = 54
Output: 2
Explanation :
The index of 54 is 2, hence output is 2.

Input: V = {3, 7, 9, 11, 13}, K = 12
Output: -1
*/

#include <bits/stdc++.h>
using namespace std;

void getIndex(vector<int> v, int K)
{
	auto it = find(v.begin(), v.end(), K);

	// If element was found
	if (it != v.end())
	{

		// calculating the index
		// of K
		int index = it - v.begin();
		cout << index << endl;
	}
	else {
		// If the element is not
		// present in the vector
		cout << "-1" << endl;
	}
}

int main()
{
	vector<int> v = { 1, 45, 54, 71, 76, 17 };
	int K = 54;
	getIndex(v, K);
	return 0;
}

/*
Output:
2
*/

// Time Complexity: O(N)
// Auxiliary Space: O(1)