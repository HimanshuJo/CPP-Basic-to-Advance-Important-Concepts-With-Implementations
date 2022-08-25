// 2131. Longest Palindrome by Concatenating Two Letter Words
/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. 
Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string, int>mp;
        for(auto &word: words){
            mp[word]++;
        }
        int res=0;
        bool flag=false;
        for(auto &word: words){
            string curr=word;
            reverse(word.begin(), word.end());
            string tmp=word;
            if(tmp!=curr&&mp[tmp]>0&&mp[curr]>0){
                res+=4;
                mp[tmp]--;
                mp[curr]--;
            } else if(tmp==curr&&mp[tmp]>1){
                res+=4;
                mp[tmp]-=2;
            } else if(tmp==curr&&!flag&&mp[tmp]>0){
                res+=2;
                mp[tmp]--;
                flag=true;
            }
        }
        return res;
    }
};