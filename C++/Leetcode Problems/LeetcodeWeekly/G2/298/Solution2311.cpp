// 2311. Longest Binary Subsequence Less Than or Equal to K
/*
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters 
without changing the order of the remaining characters.

Example 1:

Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", 
as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.

Example 2:

Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, 
as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 10^9
*/

class Solution {
public:
    
    long long dfs(string &s, int k, int cursz, int idx, vector<vector<long long>>&memo){
        if(idx<0) return 0;
        if(memo[idx][cursz]!=-1) return memo[idx][cursz];
        long long ntpk=dfs(s, k, cursz, idx-1, memo);
        long long pk=0;
        if((k-(s[idx]-'0')*pow(2, cursz))>=0){
            pk=1+dfs(s, (k-(s[idx]-'0')*pow(2, cursz)), cursz+1, idx-1, memo);
        }
        return memo[idx][cursz]=max(pk, ntpk);
    }
    
    int longestSubsequence(string s, int k) {
        int sz=s.size();
        vector<vector<long long>>memo(sz+1, vector<long long>(sz+1, -1));
        return dfs(s, k, 0, sz-1, memo);
    }
};