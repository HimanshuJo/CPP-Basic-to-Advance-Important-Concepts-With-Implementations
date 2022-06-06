// 316. Remove Duplicate Letters
/*
Given a string s, remove duplicate letters so that every letter appears 
once and only once. 

You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
 

Constraints:

1 <= s.length <= 10^4
s consists of lowercase English letters.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
       int len=s.length();
        string res="";
        unordered_map<char, int>mp;
        unordered_map<char, bool>seen;
        stack<int>stk;
        for(auto &ch: s){
            mp[ch]++;
        }
        for(unordered_map<char, int>::iterator itr=mp.begin(); itr!=mp.end(); ++itr){
            seen[itr->first]=false;
        }
        for(int i=0; i<len; ++i){
            mp[s[i]]--;
            if(seen[s[i]]) continue;
            while(!stk.empty()&&s[i]<s[stk.top()]&&mp[s[stk.top()]]>0){
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