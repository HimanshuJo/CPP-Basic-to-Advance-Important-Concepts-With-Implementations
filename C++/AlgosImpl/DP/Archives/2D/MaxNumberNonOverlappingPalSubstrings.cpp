// 2472. Maximum Number of Non-overlapping Palindrome Substrings
/*
You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy 
the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "abaccdbbd", k = 3
Output: 2
Explanation: We can select the substrings underlined in s = "abaccdbbd". 
Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
It can be shown that we cannot find a selection with more than two valid substrings.
Example 2:

Input: s = "adbcda", k = 2
Output: 0
Explanation: There is no palindrome substring of length at least 2 in the string.

Constraints:

1 <= k <= s.length <= 2000
s consists of lowercase English letters.
*/

class Solution {
public:

    bool isPalindrome(string &s, int left, int right){
        while(left<right){
            if(s[left]!=s[right]) return false;
            left++, right--;
        }
        return true;
    }

    int dfs(string &s, int k, int i, int j, int sz, vector<vector<int>>&memo){
        if(i>=sz||j>=sz) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(isPalindrome(s, i, j)){
            return memo[i][j]=max(1+dfs(s, k, j+1, j+k, sz, memo), dfs(s, k, i+1, j+1, sz, memo));
        }
        return memo[i][j]=max(dfs(s, k, i, j+1, sz, memo), dfs(s, k, i+1, j+1, sz, memo));
    }

    int maxPalindromes(string s, int k) {
        int sz=s.size();
        if(k==1) return sz;
        vector<vector<int>>memo(sz+1, vector<int>(sz+1, -1));
        return dfs(s, k, 0, k-1, sz, memo);
    }
};