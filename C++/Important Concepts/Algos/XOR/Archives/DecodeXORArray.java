/*
There is a hidden integer array arr that consists of n non-negative integers.

It was encoded into another integer array encoded of length n - 1, such that

	encoded[i] = arr[i] XOR arr[i + 1].

	For example, if arr = [1,0,2,1], then encoded = [1,2,3].

You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

Return the original array arr. It can be proved that the answer exists and is unique.

Example 1:

Input: encoded = [1,2,3], first = 1
Output: [1,0,2,1]
Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
*/
/*
Intuition:

	We are given that:

		encoded[i] = arr[i] xor arr[i + 1]  --> eq. 1

			We know according to the xor property:

				a ^ b = b ^ a

			to get arr[i + 1], we can xor arr[i] on both the sides so eq. 1 becomes

				encoded[i] xor arr[i] = arr[i] xor arr[i + 1] xor arr[i]  --> eq. 2

			-------

			We also know one other property of xor that:

				a ^ a = 0

			also

				a ^ 0 = a

			hence eq. 2 becomes

			=> encoded[i] ^ arr[i] = 0 ^ arr[i + 1]

			=> encoded[i] ^ arr[i] = arr[i + 1]

		-------

		In essence we already have our first element, therefore we can easily find out next elements

			for the following steps arr[i + 1] will take the position of arr[i]
*/

class Solution {
	public int[] decode(int[] encoded, int first) {
		int length = encoded.length;
		int[] arr = new int[length + 1];
		arr[0] = first;
		for (int i = 0; i < length; ++i) {
			arr[i + 1] = encoded[i] ^ arr[i];
		}
		return arr;
	}
}
