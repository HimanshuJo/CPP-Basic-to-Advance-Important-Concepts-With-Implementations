// 2218. Maximum Value of K Coins From Piles
/*
There are n piles of coins on a table. Each pile consists of a positive number of coins 
of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the 
i'th pile from top to bottom, and a positive integer k, return the maximum total value 
of coins you can have in your wallet if you choose exactly k coins optimally.

Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
Example 2:

Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.
 

Constraints:

n == piles.length
1 <= n <= 1000
1 <= piles[i][j] <= 10^5
1 <= k <= sum(piles[i].length) <= 2000
*/

/*
Solution2:

Either pick all k from previous piles or choose j from current piles & pick k-j from previous piles

Recurrence relation:

	f(n, k) represents the max sum of coins collected from first n piles and choosing k top coins

	f(n, k)=max(f(n-1, k) // pick k from previous n-1 piles,
			max(f(n-1, k-j-1)+sum(0, j) for j=0 to min(k, p[n-1].size())) // pick j+1 from current piles
																		  // and k-j-1 from previous n-1 piles

			)

if k==0, we can't pick any coin, ans=0
if n==0, we don't pick any piles then ans=0

Base cases:

	f(0, k)=0, f(n, 0)=0

-------


class Solution {
public:
    
    int dp[1010][2010];
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int pilessz=piles.size();
        for(int i=0; i<=pilessz; ++i){
            for(int j=0; j<=k; ++j){
                dp[i][j]=0;
            }
        }
        for(int i=1; i<=pilessz; ++i){
            for(int j=1; j<=k; ++j){
                dp[i][j]=dp[i-1][j];
                int sum=0, picked=1;
                for(auto &vals: piles[i-1]){
                    if(j-picked<0) break;
                    sum+=vals;
                    dp[i][j]=max(dp[i][j], sum+dp[i-1][j-picked]);
                    picked++;
                }
            }
        }
        return dp[pilessz][k];
    }
};
*/

class Solution {
public:
    
    int memo[1010][2010];
    
    int dfs(vector<vector<int>>&piles, int k, const int pilessz, int idx){
        if(k==0) return 0;
        if(idx>=pilessz) return 0;
        if(memo[idx][k]!=-1) return memo[idx][k];
        int ans=INT_MIN;
        int npk=INT_MIN;
        npk=max(npk, dfs(piles, k, pilessz, idx+1));
        int sz=piles[idx].size();
        sz--;
        int pk=INT_MIN;
        int tempans=0;
        for(int i=0; i<=min(sz, k-1); ++i){
            tempans+=piles[idx][i];
            pk=max(pk, tempans+dfs(piles, k-i-1, pilessz, idx+1));    
        }
        ans=max(npk, pk);
        return memo[idx][k]=ans;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int pilessz=piles.size();
        int idx=0;
        for(int i=0; i<=1000; ++i){
            for(int j=0; j<=2000; ++j){
                memo[i][j]=-1;
            }
        }
        return (dfs(piles, k, pilessz, idx));
    }
};