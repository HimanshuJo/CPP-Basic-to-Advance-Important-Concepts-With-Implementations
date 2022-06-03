// Best Time to Buy and Sell Stock II
/*
Problem Statement:

You have been given stock values/prices for N number of days. 
Every i-th day signifies the price of a stock on that day. 
Your task is to find the maximum profit which you can make by buying and selling the stocks.

Note :

	You may make as many transactions as you want but can not have more than one transaction at a 
	time i.e, if you have the stock, you need to sell it first, and then only you can buy it again.
*/

#include<vector>
using namespace std;

long dfs(long *values, int sz, int idx, bool canBuy, vector<vector<long>>&memo){
    if(idx>=sz) return 0;
    if(memo[idx][canBuy]!=-1) return memo[idx][canBuy];
    long prof=0;
    if(canBuy){
        long curprof=max(dfs(values, sz, idx+1, true, memo), -values[idx]+dfs(values, sz, idx+1, false, memo));
        prof=max(prof, curprof);
    } else{
        long curprof=max(dfs(values, sz, idx+1, false, memo), values[idx]+dfs(values, sz, idx+1, true, memo));
        prof=max(prof, curprof);
    }
    return memo[idx][canBuy]=prof;
}

long getMaximumProfit(long *values, int n)
{
    int sz=n;
    vector<vector<long>>memo(sz+1, vector<long>(2, -1));
    return dfs(values, sz, 0, true, memo);    
}

// -------*******-------

long getMaximumProfit2(long *values, int n)
{
    vector<vector<long>>dp(n+1, vector<long>(2, 0));
    dp[n][0]=dp[n][1]=0;
    for(int ind=n-1; ind>=0; --ind){
        for(int buy=0; buy<=1; ++buy){
            long profit=0;
            if(buy){
            	profit=max(dp[ind+1][1], -values[ind]+dp[ind+1][0]);
            } else{
             	profit=max(dp[ind+1][0], values[ind]+dp[ind+1][1]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}

// -------*******-------

long getMaximumProfit3(long *values, int n)
{
    vector<long>ahead(2, 0), curr(2, 0);
    ahead[0]=ahead[1]=0;
    for(int ind=n-1; ind>=0; --ind){
        for(int buy=0; buy<=1; ++buy){
            long profit=0;
            if(buy){
            	profit=max(ahead[1], -values[ind]+ahead[0]);
            } else{
                profit=max(ahead[0], values[ind]+ahead[1]);
            }
            curr[buy]=profit;
        }
        ahead=curr;
    }
    return ahead[1];
}

// -------*******-------

long getMaximumProfit(long *values, int n)
{
    long aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy=0, aheadBuy=0;
    for(int ind=n-1; ind>=0; --ind){
        curBuy=max(aheadBuy, -values[ind]+aheadNotBuy);
        curNotBuy=max(aheadNotBuy, values[ind]+aheadBuy);
        aheadBuy=curBuy, aheadNotBuy=curNotBuy;
    }
    return aheadBuy;
}