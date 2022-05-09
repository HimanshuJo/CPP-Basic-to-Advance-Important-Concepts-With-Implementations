// Remove All Occurrences of a Substring

/*
Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

    Find the leftmost occurrence of the substring part and remove it from s.

Return s after removing all occurrences of part.

A substring is a contiguous sequence of characters in a string.

Example 1:

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".

Example 2:

Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".

Constraints:

    1 <= s.length <= 1000
    1 <= part.length <= 1000
    's' and 'part' consists of lowercase English letters.

*/

/*
Approach:

    Initialize a stack to store the characters of the main string (let's say S1)

    Traverse the string S1 and perform the following operations:

        a. Push the current character in the stack

        b. If the size of the stack is at least M, then check if the top M characters of the stack form the string s2 or not

            If found to be true, then remove those characters

*/

#include <bits/stdc++.h>
#include <strings.h>
using namespace std;

class Solution
{
public:
    string res;
    string removeOccurrences(string s, string part)
    {
        int n = s.length();
        int m = part.length();
        minLength(s, n, part, m);
        reverse(res.begin(), res.end());
        return res;
    }

    void minLength(string str, int N,
                   string K, int M)
    {
        // Initialize stack of characters
        stack<char> stackOfChar;
        for (int i = 0; i < N; i++)
        {
            // Push character into the stack
            stackOfChar.push(str[i]);
            // If stack size >= K.size()
            if (stackOfChar.size() >= M)
            {
                // Create empty string to
                // store characters of stack
                string l = "";
                // Traverse the string K in reverse
                for (int j = M - 1; j >= 0; j--)
                {
                    // If any of the characters
                    // differ, it means that K
                    // is not present in the stack
                    if (K[j] != stackOfChar.top())
                    {
                        // Push the elements
                        // back into the stack
                        int f = 0;
                        while (f != l.size())
                        {
                            stackOfChar.push(l[f]);
                            f++;
                        }
                        break;
                    }
                    // Store the string
                    else
                    {
                        l = stackOfChar.top() + l;
                        // Remove top element
                        stackOfChar.pop();
                    }
                }
            }
        }
        while (!stackOfChar.empty())
        {
            res.push_back(stackOfChar.top());
            stackOfChar.pop();
        }
    }
};