// 2110. Number of Smooth Descent Periods of a Stock
/*
You are given an integer array prices representing the daily price history of a stock, 
where prices[i] is the stock price on the i'th day.

A smooth descent period of a stock consists of one or more contiguous days such that the price on each day is 
lower than the price on the preceding day by exactly 1. The first day of the period is exempted from this rule.

Return the number of smooth descent periods.

Example 1:

Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
*/

using ll=long long;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        ll ans=0;
        vector<ll>dp(n, 1);
        for(int i=0; i<n; ++i){
            if(i>0){
                if(prices[i]<prices[i-1]&&(abs(prices[i]-prices[i-1])==1)){
                    dp[i]=dp[i-1]+1;
                }
            }
        }
        for(auto &vals: dp)
            ans+=vals;
        return ans;
    }
};