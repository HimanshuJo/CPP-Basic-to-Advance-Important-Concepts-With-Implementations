/*
There is an integer array perm that is a permutation of the first n positive integers,
	where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that
	encoded[i] = perm[i] XOR perm[i + 1].

	For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

Example 1:

Input: encoded = [3,1]
Output: [1,2,3]
Explanation: If perm = [1,2,3], then encoded = [1 XOR 2,2 XOR 3] = [3,1]

*/
/*
Intuition:

	Suppose we have a permutation array: [a, b, c, d, e]

		XOR of this permutation array is:

			xorAll = a^b^c^d^e

	Suppose our encoded array is: [a^b, b^c, c^d, d^e]

		XOR of the adjacent elements of this array is:

			xorAdj = a^b^c^d

	Suppose we want to find what could be our last element, so we can perform:

		(xorAll) xor (xorAdj)

		=> lastElement = (a^b^c^d^e) ^ (a^b^c^d)

			since XOR has the property that:

						a ^ a = 0

				Also, 	a ^ 0 = a

			hence lastElement = e

*/

class Solution {
	public int[] decode(int[] encoded) {
		Vector<Integer> arr = new Vector<>();
		int n = encoded.length - 1;
		int xorAll = xorAllElements(n);
		int xorAdj = 0;
		for (int i = 0; i < n - 1; ++i) {
			xorAdj = xorAdj ^ encoded[i];
		}
		int lastElement = xorAll ^ xorAdj;
		arr.add(lastElement);
		for (int i = n - 2; i >= 0; --i) {
			lastElement = encoded[i] ^ lastElement;
			arr.add(lastElement);
		}
		int[] res = new int[encoded.length - 1];
		for (int i = 0; i < arr.size(); ++i) {
			res[i] = arr.get(i);
		}
		return res;
	}

	public static int xorAllElements(int n) {
		switch (n & 3) {
		case 0:
			return n;
		case 1:
			return 1;
		case 2:
			return n + 1;
		}
		return 0;
	}
}
