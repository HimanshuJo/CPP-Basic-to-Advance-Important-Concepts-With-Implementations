/*
Given a string S and an integer K. The task is to find lexicographically largest subsequence of S,
	say T, such that every character in T must occur at least K times

	Example: S = "banana" K = 2

	Output: nn

	-------

	The idea is to solve the above problem greedily

		If we want to make the subsequence lexicographically largest, we must give priority to lexicographically
			largest character

		'z' is the largest character, let us suppose z occurs fz times in S

			if fz >= K, append 'z'z k times in the string T and keep removing characters from the left
				of S until all the z's are removed

			Apply the strategy with 'y', 'w', .... 'a'

				in the end we will find the answer

	-------

	Suppose S = "zzwzawa" and K = 2.

		Start with the largest character 'z'

		Here fz = 3 >= K

			So it will become "zzz", and we will remove letters from the left of S until all the z's are removed

		So now S will become "awa"

		Next largest is 'y' but that occurs 0 times in k, so we will skip it

		We will also skip 'w', 'v' etc, also until we go to 'a' which occurs 2 times.

		Now it will become "zzzaa" and S will become a empty string

*/

#include>bits/stdc++.h>
using namespace std;

// Find lexicographically largest subsequence of s[0..n-1] such that every character
// appears at least k times. The result is filled in t[]
void subsequence(char[] s, char[] t, int n, int k) {
	int last = 0, cnt = 0, newLast = 0, size = 0;
	// Starting from the largest character 'z' to 'a'
	for (char ch = 'z'; ch >= 'a'; --ch) {
		cnt = 0;
		// Counting the frequency of each character
		for (int i = last; i < n; ++i) {
			if (s[i] == ch) {
				cnt++;
			}
		}
		// If frequency is greater than k
		if (cnt >= k) {
			// From the last point we leave
			for (int i = last; i < n; ++i) {
				// check if the string contain ch
				if (s[i] == ch) {
					// If yes, append to output string
					t[size++] = ch;
					newLast = i;
				}
			}
			last = newLast;
		}
	}
	t[size] = '\0';
}

int main() {
	char[] s = "banana";
	int n = sizeof(s);
	int k = 2;
	char t[n];
	subsequence(s, t, n - 1, k);
	cout << t << "\n";
	return 0;
}

/*
Output:

	nn
*/