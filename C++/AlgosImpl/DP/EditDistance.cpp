/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

/*
Algo:

base case: word1 = "" or word2 = "" => return length of other string
recursive case: word1[0] == word2[0] => recurse on word1[1:] and word2[1:]
recursive case: word1[0] != word2[0] => recurse by inserting, deleting, or replacing

class Solution:
    def minDistance(self, word1, word2):
        """Naive recursive solution"""
        if not word1 and not word2:
            return 0
        if not word1:
            return len(word2)
        if not word2:
            return len(word1)
        if word1[0] == word2[0]:
            return self.minDistance(word1[1:], word2[1:])
        insert = 1 + self.minDistance(word1, word2[1:])
        delete = 1 + self.minDistance(word1[1:], word2)
        replace = 1 + self.minDistance(word1[1:], word2[1:])
        return min(insert, replace, delete)

-------

word1 = "horse"
word2 = "hello"

The tree of recursive calls, 3 levels deep, looks like the following. 
The runtime of this solution, but it's exponential.

md("horse", "hello")
    md("orse", "ello")
        md("orse", "llo")

            md("orse", "lo")

                md("orse", "o")
                ...

            md("rse", "llo") <-

                md("rse", "lo")
                ...

            md("rse", "lo")

                md("rse", "o")
                ...

        md("rse", "ello")

            md("rse", "llo") <-

                md("rse", "lo")
                ...

            md("se", "ello")

                md("se", "llo")
                ...

            md("se", "llo") <<-

                md("se", "lo")
                ...

        md("rse", "llo")

            md("rse", "llo") <-

                md("rse", "lo")
                ...

            md("se", "llo") <<-

                md("se", "lo")
                ...

            md("se", "lo")

                md("se", "o")
                ...

-------

class Solution:
    def minDistance(self, word1, word2, i, j, memo):
        """Memoized solution"""
        if i == len(word1) and j == len(word2):
            return 0
        if i == len(word1):
            return len(word2) - j
        if j == len(word2):
            return len(word1) - i

        if (i, j) not in memo:
            if word1[i] == word2[j]:
                ans = self.minDistance2(word1, word2, i + 1, j + 1, memo)
            else: 
                insert = 1 + self.minDistance2(word1, word2, i, j + 1, memo)
                delete = 1 + self.minDistance2(word1, word2, i + 1, j, memo)
                replace = 1 + self.minDistance2(word1, word2, i + 1, j + 1, memo)
                ans = min(insert, delete, replace)
            memo[(i, j)] = ans
        return memo[(i, j)]
*/

/*
class Solution {
public:
    
    int dfs(string word1, string word2, int i, int j, const int sz1, const int sz2, int memo[][501]){
        if(i==sz1&&j==sz2) return 0;
        if(i==sz1) return sz2-j;
        if(j==sz2) return sz1-i;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=0;
        if(word1[i]==word2[j]){
            ans=dfs(word1, word2, i+1, j+1, sz1, sz2, memo);
        } else{
            // "hemn", "oval" -> "ohemn", "oval" -> i same, inc j
            int insert=1+dfs(word1, word2, i, j+1, sz1, sz2, memo);
            int del=1+dfs(word1, word2, i+1, j, sz1, sz2, memo);
            int replace=1+dfs(word1, word2, i+1, j+1, sz1, sz2, memo);
            ans=min({insert, del, replace});
        }
        return memo[i][j]=ans;
    }
    
    int minDistance(string word1, string word2) {
        int i=0, j=0;
        int sz1=word1.length(), sz2=word2.length();
        int memo[501][501];
        for(int i=0; i<=sz1; ++i)
            for(int j=0; j<=sz2; ++j)
                memo[i][j]=-1;
        int ans=dfs(word1, word2, 0, 0, sz1, sz2, memo);
        return ans;
    }
};
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(), n=word2.length();
        if(m==0) return n;
        if(n==0) return m;
        word1.insert(0, " ");
        word2.insert(0, " ");
        m++, n++;
        int dp[m+1][n+1];
        for(int i=0; i<=m; ++i){
             for(int j=0; j<=n; ++j)
                dp[i][j]=0;
        }
        memset(dp, 0, sizeof(dp)/sizeof(int));
        for(int i=1; i<=m; ++i){
            dp[i][0]=dp[i-1][0]+1;
        }
        for(int j=1; j<=n; ++j){
            dp[0][j]=dp[0][j-1]+1;
        }
        for(int i=1; i<=m; ++i)
            for(int j=1; j<=n; ++j){
                if(word1[i-1]!=word2[j-1])
                    dp[i][j]=min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;
                else{
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        return dp[m][n];
    }
};