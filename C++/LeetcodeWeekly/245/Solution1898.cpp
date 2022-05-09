// Maximum Number of Removable Characters

/*
    You are given two strings s and p where p is a subsequence of s. 
    You are also given a distinct 0-indexed integer array removable containing a subset of 
        indices of s (s is also 0-indexed).

    You want to choose an integer k (0 <= k <= removable.length) such that, after removing k characters from s using 
    the first k indices in removable, p is still a subsequence of s

    More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, then remove all marked 
    characters and check if p is still a subsequence.

    Return the maximum k you can choose such that p is still a subsequence of s after the removals.

    A subsequence of a string is a new string generated from the original string with some characters (can be none) 
    deleted without changing the relative order of the remaining characters.

    Example 1:

    Input: s = "abcacb", p = "ab", removable = [3,1,0]
    Output: 2
    Explanation: After removing the characters at indices 3 and 1, "abcacb" becomes "accb".
    "ab" is a subsequence of "accb".
    If we remove the characters at indices 3, 1, and 0, "abcacb" becomes "ccb", and "ab" is no longer a subsequence.
    Hence, the maximum k is 2.

*/

#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution
{
public:
    int maximumRemovals(string s, string p, vector<int> &removable)
    {
        int l = -1, r = removable.size();
        while (r > l + 1)
        {
            int m = l + (r - l) / 2;
            if (ok(s, p, m, removable))
            {
                l = m;
            }
            else
            {
                r = m;
            }
        }
        return r;
    }

public:
    bool ok(string s, string &p, int m, vector<int> &removable)
    {
        int i = 0, j = 0;
        for (int k = 0; k <= m; k++)
        {
            s[removable[k]] = '#';
        }
        while (i < s.length() and j < p.length())
        {
            if (s[i] == p[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        if (j == p.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};