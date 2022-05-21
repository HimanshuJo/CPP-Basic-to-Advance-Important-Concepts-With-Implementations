// 2060. Check if an Original String Exists Given Two Encoded Strings
/*
An original string, consisting of lowercase English letters, can be encoded by the following steps:

Arbitrarily split it into a sequence of some number of non-empty substrings.
Arbitrarily choose some elements (possibly none) of the sequence, and 
replace each with its length (as a numeric string).
Concatenate the sequence as the encoded string.
For example, one way to encode an original string "abcdefghijklmnop" might be:

Split it as a sequence: ["ab", "cdefghijklmn", "o", "p"].
Choose the second and third elements to be replaced by their lengths, respectively. 
The sequence becomes ["ab", "12", "1", "p"].
Concatenate the elements of the sequence to get the encoded string: "ab121p".

Given two encoded strings s1 and s2, consisting of lowercase English letters 
and digits 1-9 (inclusive), return true if there exists an original string 
that could be encoded as both s1 and s2. Otherwise, return false.

Note: The test cases are generated such that the number of consecutive digits in s1 and s2 does not exceed 3.

Example 1:

Input: s1 = "internationalization", s2 = "i18n"
Output: true
Explanation: It is possible that "internationalization" was the original string.
- "internationalization" 
  -> Split:       ["internationalization"]
  -> Do not replace any element
  -> Concatenate:  "internationalization", which is s1.
- "internationalization"
  -> Split:       ["i", "nternationalizatio", "n"]
  -> Replace:     ["i", "18",                 "n"]
  -> Concatenate:  "i18n", which is s2
Example 2:

Input: s1 = "l123e", s2 = "44"
Output: true
Explanation: It is possible that "leetcode" was the original string.
- "leetcode" 
  -> Split:      ["l", "e", "et", "cod", "e"]
  -> Replace:    ["l", "1", "2",  "3",   "e"]
  -> Concatenate: "l123e", which is s1.
- "leetcode" 
  -> Split:      ["leet", "code"]
  -> Replace:    ["4",    "4"]
  -> Concatenate: "44", which is s2.
Example 3:

Input: s1 = "a5b", s2 = "c5b"
Output: false
Explanation: It is impossible.
- The original string encoded as s1 must start with the letter 'a'.
- The original string encoded as s2 must start with the letter 'c'.
 

Constraints:

1 <= s1.length, s2.length <= 40
s1 and s2 consist of digits 1-9 (inclusive), and lowercase English letters only.
The number of consecutive digits in s1 and s2 does not exceed 3.
*/

/*
The thinking solution is straight forward we have 2 pointer in each string

consider the easy case, they all character, we compare s1.charAt(i) == s2.charAt(j)

digit case, we get a number from s1, we can calculate the number s1 has, 
(description said less than 1000), we can pass this value compare with number from s2 name it diff
character case if we still has remaining diff to spend passed from our parents, 
so we can use one dollar a day, one diff one position dfs(i + 1, j, diff - 1
terminating condition, if both reach the end and diff == 0

*/

//387 ms
class Solution {
    String s1;
    String s2;
    Boolean[][][] memo = new Boolean[41][41][2000];
    public boolean possiblyEquals(String s1, String s2) {
        this.s1 = s1;
        this.s2 = s2;
        return dfs(0, 0, 0); //s1 pointer, s1 pointer, digit difference
    }
    
    private boolean dfs(int i, int j, int diff) {
        if (i >= s1.length() && j >= s2.length() && diff == 0) return true;
        if (memo[i][j][diff + 1000] != null) return memo[i][j][diff + 1000];
        boolean res = false;
        if (i < s1.length()) {
            if (Character.isDigit(s1.charAt(i))) {
                int count = 0, value = 0; //be careful we can not change i cause s2 will use i again
                while (i + count < s1.length() && count < 3 && Character.isDigit(s1.charAt(i + count))) {
                    value = value * 10 + (s1.charAt(i + count) - '0');
                    count++;
                    if (dfs(i + count, j, diff - value)) res = true;
                }
            } else {
                if (diff > 0) {
                    if (dfs(i + 1, j, diff - 1)) res = true;
                } else if (diff == 0 && j < s2.length() && s1.charAt(i) == s2.charAt(j)) {
                    if (dfs(i + 1, j + 1, diff)) res = true;
                }
            }
        }
        if (j < s2.length()) {
            if (Character.isDigit(s2.charAt(j))) {
                int count = 0, value = 0;
                while (j + count < s2.length() && count < 3 && Character.isDigit(s2.charAt(j + count))) {
                    value = value * 10 + (s2.charAt(j + count) - '0');
                    count++;
                    if (dfs(i, j + count, diff + value)) res = true;
                }
            } else if (diff < 0 && dfs(i, j + 1, diff + 1)) res = true;
        }
        return memo[i][j][diff + 1000] = res;
    }
}

// -------*******-------

class Solution2 {
    //112ms
    public boolean possiblyEquals(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        // dp[i][j][diff] means if s1[i:] truncated by <diff> characters if diff > 0 
        // and s2[j:] truncated by <-diff> characters if diff < 0 are equal
        Boolean[][][] dp = new Boolean[l1 + 1][l2 + 1][2000]; 
        return dfs(0, 0, 0, s1.toCharArray(), s2.toCharArray(), dp);
    }
    
    private boolean dfs(int i, int j, int diff, char[] s1, char[] s2, Boolean[][][] dp) {
        if (i == s1.length && j == s2.length) {
            return diff == 0;
        }
        
        if (dp[i][j][diff + 1000] != null) return dp[i][j][diff + 1000];
        
        // Literal matching on s1[i] and s2[j]
        if (i < s1.length && j < s2.length && diff == 0 && s1[i] == s2[j]) {
            if (dfs(i + 1, j + 1, 0, s1, s2, dp)) {
                return dp[i][j][1000] = true;
            }
        }
        
        // Literal matching on s1[i]
        if (i < s1.length && !isDigit(s1[i]) && diff > 0 && dfs(i + 1, j, diff - 1, s1, s2, dp)) {
            return dp[i][j][diff + 1000] = true;
        }
        
        // Literal matching on s2[j]
        if (j < s2.length && !isDigit(s2[j]) && diff < 0 && dfs(i, j + 1, diff + 1, s1, s2, dp)) {
            return dp[i][j][diff + 1000] = true;
        }
        
        // Wildcard matching on s1[i]
        for (int k = i, val = 0; k < s1.length && isDigit(s1[k]); ++k) {
            val = val * 10 + (s1[k] - '0');
            if (dfs(k + 1, j, diff - val, s1, s2, dp)) {
                return dp[i][j][diff + 1000] = true;
            }
        }
        
        // Wildcard matching on s2[j]
        for (int k = j, val = 0; k < s2.length && isDigit(s2[k]); ++k) {
            val = val * 10 + (s2[k] - '0');
            if (dfs(i, k + 1, diff + val, s1, s2, dp)) {
                return dp[i][j][diff + 1000] = true;
            }
        }
        
        return dp[i][j][diff + 1000] = false;
    }
    
    private boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }
}