// 1220. Count Vowels Permutation
/*
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
 

Constraints:

1 <= n <= 2 * 10^4
*/

class Solution {
public:
    
    int mod=1e9+7;
    
    int dfs(int n, int curr, char ch, vector<vector<long long>>&memo){
        if(curr==n) return 1;
        if(memo[curr][(int)ch]!=-1) return memo[curr][(int)ch];
        long long res=0;
        if(ch=='a'){
            res+=(dfs(n, curr+1, 'e', memo)%mod);
            res%=mod;
        }
        if(ch=='e'){
            res+=dfs(n, curr+1, 'a', memo)%mod;
            res+=dfs(n, curr+1, 'i', memo)%mod;
        }
        if(ch=='i'){
            res+=dfs(n, curr+1, 'a', memo)%mod;
            res+=dfs(n, curr+1, 'e', memo)%mod;
            res+=dfs(n, curr+1, 'o', memo)%mod;
            res+=dfs(n, curr+1, 'u', memo)%mod;
        }
        if(ch=='o'){
            res+=dfs(n, curr+1, 'i', memo)%mod;
            res+=dfs(n, curr+1, 'u', memo)%mod;
        }
        if(ch=='u'){
            res+=(dfs(n, curr+1, 'a', memo)%mod);
        }
        return memo[curr][(int)ch]=res%mod;
    }
    
    int countVowelPermutation(int n) {
        vector<vector<long long>>memo(2e4+1, vector<long long>(200, -1));
        long long frst=dfs(n, 1, 'a', memo);
        frst%=mod;
        long long sec=dfs(n, 1, 'e', memo);
        sec%=mod;
        long long thrd=dfs(n, 1, 'i', memo);
        thrd%=mod;
        long long frth=dfs(n, 1, 'o', memo);
        frth%=mod;
        long long ffth=dfs(n, 1, 'u', memo);
        ffth%=mod;
        return (frst+sec+thrd+frth+ffth)%mod;
    }
};