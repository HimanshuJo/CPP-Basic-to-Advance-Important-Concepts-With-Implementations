// 2466. Count Ways To Build Good Strings
/*
Given the integers zero, one, low, and high, we can construct a string by 
starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length 
between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying 
these properties. Since the answer can be large, return it modulo 10^9 + 7.

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.
Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
 

Constraints:

1 <= low <= high <= 10^5
1 <= zero, one <= low
*/

class Solution {
public:

    int mod=1e9+7;

    int dfs(int curval, int zero, int one, vector<int>&memo){
        if(curval<0) return 0;
        if(curval==0) return 1;
        if(memo[curval]!=-1) return memo[curval];
        return memo[curval]=(dfs(curval-zero, zero, one, memo)%mod)+(dfs(curval-one, zero, one, memo)%mod);
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int>memo(high+1, -1);
        for(int i=low; i<=high; ++i){
            ans=((ans%mod)+(dfs(i, zero, one, memo)%mod))%mod;
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
public:

    int mod=1e9+7;

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0;
        vector<int>dp(high+1, 0);
        dp[0]=1;
        for(int j=1; j<=high; ++j){
            if(j-zero>=0){
                dp[j]+=dp[j-zero];
                dp[j]%=mod;
            }
            if(j-one>=0){
                dp[j]+=dp[j-one];
                dp[j]%=mod;
            }
        }
        for(int i=low; i<=high; ++i){
            ans+=(dp[i]%mod);
            ans%=mod;
        }
        return ans;
    }
};