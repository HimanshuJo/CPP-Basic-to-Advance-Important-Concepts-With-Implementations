// 2430. Maximum Deletions on a String
/*
You are given a string s consisting of only lowercase English letters. In one operation, you can:

Delete the entire string s, or
Delete the first i letters of s if the first i letters of s are equal to the following i letters in s, 
for any i in the range 1 <= i <= s.length / 2.

For example, if s = "ababc", then in one operation, you could delete the first two letters of s to get "abc", 
since the first two letters of s and the following two letters of s are both equal to "ab".

Return the maximum number of operations needed to delete all of s.


Example 1:

Input: s = "abcabcdabc"
Output: 2
Explanation:
- Delete the first 3 letters ("abc") since the next 3 letters are equal. Now, s = "abcdabc".
- Delete all the letters.
We used 2 operations so return 2. It can be proven that 2 is the maximum number of operations needed.
Note that in the second operation we cannot delete "abc" again because the next occurrence of "abc" 
does not happen in the next 3 letters.
Example 2:

Input: s = "aaabaab"
Output: 4
Explanation:
- Delete the first letter ("a") since the next letter is equal. Now, s = "aabaab".
- Delete the first 3 letters ("aab") since the next 3 letters are equal. Now, s = "aab".
- Delete the first letter ("a") since the next letter is equal. Now, s = "ab".
- Delete all the letters.
We used 4 operations so return 4. It can be proven that 4 is the maximum number of operations needed.
Example 3:

Input: s = "aaaaa"
Output: 5
Explanation: In each operation, we can delete the first letter of s.
 

Constraints:

1 <= s.length <= 4000
s consists only of lowercase English letters.
*/

/*
TLE: 99 / 118

class Solution {
public:
    int deleteString(string s) {
        int sz=s.length();
        vector<int>dp(sz+1);
        dp[sz-1]=1;
        for(int i=sz-2; i>=0; --i){
            dp[i]=1;
            for(int j=1; j<=(sz-i)/2; ++j){
                int endcord1=i+j, endcord2=i+j+j;
                string frst=s.substr(i, abs(i-endcord1));
                string sec=s.substr(i+j, abs(i+j-endcord2));
                if(frst==sec){
                    dp[i]=max(dp[i], dp[i+j]+1);
                }
            }
        }
        return dp[0];
    }
};
*/

/*
Naive DP
dp[i] represents maximum deletion on a substring starting from ith character.
e.g. if s = "abcabcdabc"
dp[3] represents maximum deletion on substring "abcdabc".

Recurrence relation:
dp[i] = canBeDeleted(str[i ... j-1]) + dp[i + j]
where str[i ... j-1] represents substring from ith to j-1th index.

-------

Runtime: O(N ^ 3)

It is not fast enough and will TLE. Notice that checkingfirst i letters equal to following i 
letters takes O(N ^ 2) time and can be drastically improved.

Longest Prefix Suffix DP
Therefore, you need to check first i letters equal to following i letters in O(N) time. 
Total runtime of O(N ^ 2) is needed to pass cases.

You will need to precompute the longest prefix suffix array that is commonly used in Knuth-Morris Pratt algorithm. 
It calculates the longest prefix that is equal to suffix for each substring [0 ... i].

Example Format:
For examples, I will be showing them in the following format, index followed by character followed 
by longest prefix suffix value.
e.g.
1 2 3 4 5 6 7 8
a b c d e a b c
0 0 0 0 0 1 2 3

Explanation:
To use the longest prefix suffix array for this question, you will have to check that the 
prefix and suffix are right besides each other, which would satisfy first i letters equal to following i letters.

Check that j / 2 == prefix[j], where j is index and prefix[j] is longest prefix suffix value.
e.g.
1 2 3 4 5 6
a b c a b c
0 0 0 1 2 3

Check that j is even, as previous conditional alone does not account for following edge case.
e.g.
1 2 3 4 5 6 7
a b c d a b c
0 0 0 0 1 2 3
*/

class Solution {
public:
    
    vector<int> calPrefixLen(string pattern){
        int patternLen=pattern.length();
        vector<int>arr(patternLen+1);
        arr[0]=-1, arr[1]=0;
        int prefixLen=0, i=1;
        while(i<patternLen){
            if(pattern[prefixLen]==pattern[i]){
                prefixLen++, ++i;
                arr[i]=prefixLen;
            } else if(prefixLen>0){
                prefixLen=arr[prefixLen];
            } else{
                ++i, arr[i]=0;
            }
        }
        return arr;
    }
    
    int deleteString(string s) {
        int sz=s.length();
        vector<int>dp(sz);
        dp[sz-1]=1;
        for(int i=sz-2; i>=0; --i){
            dp[i]=1;
            vector<int>prefix=calPrefixLen(s.substr(i, sz));
            for(int j=1; j<prefix.size(); ++j){
                if(j%2==0&&j/2==prefix[j]){
                    dp[i]=max(dp[i], 1+dp[i+prefix[j]]);
                }
            }
        }
        return dp[0];
    }
};