/*
Given a string, find the count of distinct subsequences of it.

Examples:

Input  : str = "gfg"
Output : 7
The seven distinct subsequences are "", "g", "f",
"gf", "fg", "gg" and "gfg"

Input  : str = "ggg"
Output : 4
The four distinct subsequences are "", "g", "gg"
and "ggg"

The problem of counting distinct subsequences is easy if all characters of input string are distinct.
	The count is equal to nC0 + nC1 + nC2 + … nCn = 2n.

How to count distinct subsequences when there can be repetition in input string?

	A Simple Solution to count distinct subsequences in a string with duplicates is to generate all subsequences.

	For every subsequence, store it in a hash table if it doesn’t exist already.
		The time complexity of this solution is exponential and it requires exponential extra space.

-------

Using DP:

	Let countSub(n) be count of subsequences of first n characters in input string. We can
		recursively write it as below.

		countSub(n) = 2*Count(n-1) - Repetition

	If current character, i.e., str[n-1] of str has not appeared before, then
	   Repetition = 0

	Else:

	   Repetition  =  Count(m)
	   Here m is index of previous occurrence of
	   current character. We basically remove all
	   counts ending with previous occurrence of
	   current character.

-------

How does this work?

	If there are no repetitions, then count becomes double of count for n-1 because we get count(n-1)
		more subsequences by adding current character at the end of all subsequences possible with n-1 length.

	If there are repetitions, then we find a count of all distinct subsequences ending with the previous occurrence.
		This count can be obtained by recursively calling for an index of the previous occurrence.
		Since the above recurrence has overlapping subproblems, we can solve it using Dynamic Programming.

*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;

int countSub(string str)
{
	vector<int> last(MAX_CHAR, -1);

	int n = str.length();

	// dp[i] is going to store count of distinct
	// subsequences of length i.
	int dp[n + 1];

	// Empty substring has only one subsequence
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		// Number of subsequences with substring
		// str[0..i-1]
		dp[i] = 2 * dp[i - 1];

		// If current character has appeared
		// before, then remove all subsequences
		// ending with previous occurrence.
		if (last[str[i - 1]] != -1)
			dp[i] = dp[i] - dp[last[str[i - 1]]];

		// Mark occurrence of current character
		last[str[i - 1]] = (i - 1);
	}

	return dp[n];
}

int main()
{
	cout << countSub("gfg");
	return 0;
}

/*
Output:

7

Time Complexity: O(n)
Auxiliary Space: O(n)
*/