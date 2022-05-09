/*
Minimum number of given operations required to convert a permutation into an identity permutation

	Given a permutation P (P1, P2, P3, … Pn) of first n natural numbers.

	Find the minimum number of operations to convert it into an identity permutation i.e. 1, 2, 3, …, n
		where each operation is defined as:

		P[i] = P[P[P[i]]]
			for all i from 1 to n (1 based indexing).

		If there is no way to convert then print -1.

	-------

    Input: arr[] = {2, 3, 1}
    Output: 1
    After 1 operation:
    P[1] = P[P[P[1]]] = P[P[2]] = P[3] = 1
    P[2] = P[P[P[2]]] = P[P[3]] = P[1] = 2
    P[3] = P[P[P[3]]] = P[P[1]] = P[2] = 3

    Thus after 1 operation we obtain an identity permutation.

    Input: arr[] = {2, 1, 3}
    Output: -1
    There is no way to obtain identity permutation
    no matter how many operations we apply.

    -------

    Approach:

    	Firstly we have to find all the cycles in a given permutation

    	Here a cycle is a directed graph in which there is an edge from an

    		element e to the element on position e

    		Suppose our array is {4, 6, 5, 3, 2, 1, 8, 7}

    			can be represented as:

    				1 -> 4 -> 3 -> 5 -> 2 -> 6 -> 1 -> 4

    				8 -> 7 -> 8

				After 1 operation:

					4 -> 2 -> 4,
					1 -> 5 -> 1,
					6 -> 3 -> 6,

					8 -> 7 -> 8

		Now in one operation each cycle of length 3k breaks into 3 cycles each of length k
			while cycles of length 3k + 1 or 3k + 2 do not break

			Since in the end we need all the cycles of length 1, therefore all the cycles must be
				power of 3 otherwise answer doesn't exist

				The answer would then be the maximum of log(base3) of all the cycles lengths

*/

import java.util.*;

class CFG {

	static int calculateCycleOperation(int len) {

		int cycle_operation = 0;
		while (len > 0) {
			len /= 3;
			++cycle_operation;
		}

		return --cycle_operation;
	}

	static int minimumOperation(int p[], int n) {

		int[] visited = new int[n + 1];
		Arrays.fill(visited, 0);

		int ans = 0;

		for (int i = 0; i < n; ++i) {
			int ele = p[i];

			if (visited[ele] == 0) {
				visited[ele] = 1;

				int len = 1;
				ele = p[ele];

				//calculating cycle length
				while (visited[ele] == 0) {
					visited[ele] = 1;
					++len;
					ele = p[ele];
				}

				//operation needed for this cycle to reduce to length 1
				int operations = calculateCycleOperations(len);

				int num = (int) Math.pow(3, operations);

				if (num != len) return -1;

				ans = Math.max(ans, operations);
			}
		}

		return ans;
	}
}