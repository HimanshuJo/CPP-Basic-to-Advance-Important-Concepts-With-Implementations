// Maximum Product of the Length of Two Palindromic Substrings
/*
You are given a 0-indexed string s and are tasked with finding two non-intersecting palindromic substrings of odd 
length such that the product of their lengths is maximized.

More formally, you want to choose four integers i, j, k, l such that 0 <= i <= j < k <= l < s.length and 
both the substrings s[i...j] and s[k...l] are palindromes and have odd lengths. s[i...j] denotes 
a substring from index i to index j inclusive.

Return the maximum possible product of the lengths of the two non-intersecting palindromic substrings.

A palindrome is a string that is the same forward and backward. A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "ababbb"
Output: 9
Explanation: Substrings "aba" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
Example 2:

Input: s = "zaaaxbbby"
Output: 9
Explanation: Substrings "aaa" and "bbb" are palindromes with odd length. product = 3 * 3 = 9.
*/
/*
Finding the longest palindrome in [i, j] is trivial using quadratic DP. 
Then, we can just find the biggest product of [0, i] * [i + 1, n), moving the split point i left-to-right. 
However, quadratic would be too slow for n = 100,000.

Manacher's algorithm (easy to find online) can identify all palindromes in O(n). 
It has two flavors for finding odd and even palindromes. 
Fortunately, we only care about odd palindromes here, which is the simpler case.

For each position as the center of the palindrome, the algorithm finds how far the palindrome extends 
left and right. For example, for string "aaabaaaba", the result will be [1, 2, 1, 4, 1, 2, 2]. 
And true - from position 3, the palindrome extends 4 characters (the initial character is included) 
left and right, giving us "aaabaaa".

This output needs additional massaging to tell the longest palindrome in 
[0, i] and [i + 1, n). Re-using the above example, we are looking for something like this:

Left-to-right ([0, i]): [1, 1, 3, 3, 3, 5, 7, 7, 7]
Right-to-left ([i, n]): [7, 7, 7, 5, 3, 3, 3, 1, 1]
For this example, the maximum product is 15, with parts being [0, 2] and [3, 8]: 3 * 5.

This transformation was the hardest part for me. I tried a few simpler approaches, 
which work for some test cases but not for the others. I had to brush up a bit on 
how Manacher's algorithm works to figure out the transformation using a queue 
(the front of the queue is the center of the engulfing palindrome).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxProduct(string s)
    {
        long long res = 0, l = 0, n = s.size();
        vector<int> m(n), r(n);
        // Manacher's Algorithm (https://cp-algorithms.com/string/manacher.html)
        for (int i = 0, l = 0, r = -1; i < n; ++i)
        {
            int k = (i > r) ? 1 : min(m[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
                k++;
            m[i] = k--;
            if (i + k > r)
            {
                l = i - k;
                r = i + k;
            }
        }
        queue<array<int, 2>> q, q1;
        // Right-to-left to track max palindrome in [i, n).
        for (int i = n - 1; i >= 0; --i)
        {
            while (!q.empty() && q.front()[0] - q.front()[1] > i - 1)
                q.pop();
            r[i] = 1 + (q.empty() ? 0 : (q.front()[0] - i) * 2);
            q.push({i, m[i]});
        }
        // Left-to-right to track max palindrome in [0, i].
        for (int i = 0; i < n - 1; i += 1)
        {
            while (!q1.empty() && q1.front()[0] + q1.front()[1] < i + 1)
                q1.pop();
            l = max(l, 1ll + (q1.empty() ? 0 : (i - q1.front()[0]) * 2));
            res = max(res, l * r[i + 1]);
            q1.push({i, m[i]});
        }
        return res;
    }
};