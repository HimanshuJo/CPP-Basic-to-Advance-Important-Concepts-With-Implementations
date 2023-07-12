// 2414. Length of the Longest Alphabetical Continuous Substring
/*
An alphabetical continuous string is a string consisting of consecutive letters in the alphabet. 

In other words, it is any substring of the string "abcdefghijklmnopqrstuvwxyz".

For example, "abc" is an alphabetical continuous string, while "acb" and "za" are not.
Given a string s consisting of lowercase letters only, return the length of the longest alphabetical continuous substring.

Example 1:

Input: s = "abacaba"
Output: 2
Explanation: There are 4 distinct continuous substrings: "a", "b", "c" and "ab".
"ab" is the longest continuous substring.
Example 2:

Input: s = "abcde"
Output: 5
Explanation: "abcde" is the longest continuous substring.
 

Constraints:

1 <= s.length <= 10^5
s consists of only English lowercase letters.
*/

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int sz=s.size();
        int len=INT_MIN;
        int idx=0;
        for(int i=0; i<sz-1; ++i){
            int j=i+1;
            if(s[j]-s[i]==1){
                int curidx=i, nextidx=j;
                set<char>temp;
                while(true){
                    if(s[nextidx]-s[curidx]!=1) break;
                    temp.insert(s[curidx]);
                    temp.insert(s[nextidx]);
                    curidx++, nextidx++;
                    if(curidx>=sz||nextidx>=sz) break;
                }
                int cursz=temp.size();
                len=max(len, cursz);
            }
        }
        return len==INT_MIN?1:len;
    }
};