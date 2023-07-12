/*
Given an array Arr of non-negative integers of size N.
The task is to find the maximum possible xor between two numbers present in the array.

Example:

Input: Arr = {25, 10, 2, 8, 5, 3}
Output: 28
The maximum result is 5 ^ 25 = 28
Input: Arr = {1, 2, 3, 4, 5, 6, 7}
Output: 7
The maximum result is 1 ^ 6 = 7

-------

Efficient Approach:

	The task here is very similar to find maximum AND value pair

	The idea is to change the problem statement from finding maximum xor of two numbers in an array to
		find two numbers in an array, such that xor of which equals to a numbers X.

	In this case, X will be the maximum number we want to achieve till the i'th bit

	To find the largest value of an XOR operation, the value of XOR should have every bit to be a
	set bit, i.e 1.

		In a 32 bit number, the goal is to get the most 1 set starting left to right

	To evaluate each bit, there is a mask needed for that bit. A mask defines which bit should be present in the answer, and which bit is not.

	Here we will use the mask to keep the prefix for every number (means by taking the ans with the mask how many bit are remaining from the number)

	in the input till the i'th bit then with the list of possible numbers in our set, after inserting the number we will evaluate if we can update the mas for that bit position to be 1

*/

#include<bits/stdc++.h>
using namespace std;

int max_xor(int arr[], int n) {
	int maxx = 0, mask = 0;
	set<int> se;
	for (int i = 30; i >= 0; --i) {
		// setting the i'th bit in mask like 100000, 110000, 111000, ...
		mask |= (1 << i); // mask |= 00000010
		for (int i = 0; i < n; ++i) {
			// keeping the prefix till the i'th bit neglecting all the bit's after i'th bit
			se.insert(arr[i] & mask)
		}
		int newMaxx = maxx | (1 << i);
		for (int prefix : se) {
			// Finding two pair in a set such that a^b = newMaxx which is the highest possible bit that can be obtained
			if (se.count(newMaxx ^ prefix)) {
				maxx = newMaxx;
				break;
			}
		}
		se.clear();
	}
	return maxx;
}

int main() {
	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << max_xor(arr, n) << endl;
	return 0;
}

/*
Output:

	28

Time Complexity:

O(Nlog(M)), where N is the size of the array and
M is the maximum number present in the array.
*/