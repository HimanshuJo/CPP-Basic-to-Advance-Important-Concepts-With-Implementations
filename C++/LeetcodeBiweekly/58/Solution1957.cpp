// Delete Characters to Make Fancy String
/*
A fancy string is a string where no three consecutive characters are equal.

Given a string s, delete the minimum possible number of characters from s to make it fancy.

Return the final string after the deletion. It can be shown that the answer will always be unique.

 

Example 1:

Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
Example 2:

Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
*/

// using stack
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string makeFancyString(string s)
    {
        int n = s.size();
        stack<pair<char, int>> st;
        for (int i = 0; i < n; i++)
        {
            if (st.size() && s[i] == st.top().first)
            {
                st.top().second++;
            }
            else
            {
                st.push({s[i], 1});
            }
            if (st.size() && st.top().second == 3)
            {
                st.top().second--;
            }
        }
        string str;
        while (st.size())
        {
            str += string(st.top().second, st.top().first);
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};