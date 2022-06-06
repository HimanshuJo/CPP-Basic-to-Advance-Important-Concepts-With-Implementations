// 1081. Smallest Subsequence of Distinct Characters
/*
Given a string s, return the lexicographically smallest subsequence of s that
contains all the distinct characters of s exactly once.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 1000
s consists of lowercase English letters.
*/

class Solution {
public:
    string smallestSubsequence(string s) {
        int len=s.length();
        string res="";
        unordered_map<char, int>mp;
        unordered_map<char, bool>seen;
        for(auto &ch: s){
            mp[ch]++;
        }
        stack<int>stk;
        for(int i=0; i<len; ++i){
            mp[s[i]]--;
            if(seen[s[i]]) continue;
            while(!stk.empty()&&s[stk.top()]>s[i]&&mp[s[stk.top()]]>0){
                seen[s[stk.top()]]=false;
                stk.pop();
            }
            stk.push(i);
            seen[s[i]]=true;
        }
        while(!stk.empty()){
            res+=s[stk.top()];
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};