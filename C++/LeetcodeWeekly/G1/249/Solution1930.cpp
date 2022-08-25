// Unique Length-3 Palindromic Subsequences

/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

    For example, "ace" is a subsequence of "abcde".

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
*/

/*
Brute Force:

class Solution {
public:
    
    bool isPalindrome(string str){
        int len=str.length();
        for(int i=0; i<len/2; ++i){
            if(str[i]!=str[len-1-i]) return false;
        }
        return true;
    }
    
    void dfs(string &s, string curr, int sz, int idx, int &res, unordered_set<string>&st){
        if(idx==sz){
            if(curr.size()==3){
                if(isPalindrome(curr)){
                    if(st.find(curr)==st.end()){
                        res++;   
                        st.insert(curr);
                    }
                }
            }
            return;
        }
        curr.push_back(s[idx]);
        dfs(s, curr, sz, idx+1, res, st);
        curr.pop_back();
        dfs(s, curr, sz, idx+1, res, st);
    }
    
    int countPalindromicSubsequence(string s) {
        string curr="";
        unordered_set<string>st;
        int sz=s.size(), idx=0, res=0;
        dfs(s, curr, sz, idx, res, st);
        return res;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        vector<pair<int, int>> v(26, {-1, -1});
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (v[s[i] - 'a'].first == -1)
            {
                // storing when alphabet appear for the first time
                v[s[i] - 'a'].first = i;
            }
            else
            {
                // Last storing at second when it re-appears again
                v[s[i] - 'a'].second = i;
            }
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
        {
            // Only when the alphabet occur for the second time
            if (v[i].second != -1)
            {
                // we need to keep the unique elements in the set
                unordered_set<char> st;
                for (int x = v[i].first + 1; x < v[i].second; ++x)
                {
                    st.insert(s[x]);
                }
                ans += ((int)st.size());
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    string s = "bbcbaba";
    cout<<obj.countPalindromicSubsequence(s);
}