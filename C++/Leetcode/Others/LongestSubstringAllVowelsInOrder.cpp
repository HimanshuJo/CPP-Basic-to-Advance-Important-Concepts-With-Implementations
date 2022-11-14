/*
A string is considered beautiful if it satisfies the following conditions:

    Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
    The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).

For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu",
    and "aaaeeeooo" are not beautiful.

Given a string word consisting of English vowels, return the length of the longest beautiful
    substring of word. If no such substring exists, return 0.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
Output: 13
Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        const auto n = word.size();
        int unique_count = 1;
        int len = 1;
        int max_len = 0;
        for (int i = 1; i != n; ++i)
        {
            if (word[i - 1] == word[i])
            {
                ++len;
            }
            else if (word[i - 1] < word[i])
            {
                ++len;
                ++unique_count;
            }
            else
            {
                unique_count = 1;
                len = 1;
            }
            if (unique_count == 5)
            {
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};