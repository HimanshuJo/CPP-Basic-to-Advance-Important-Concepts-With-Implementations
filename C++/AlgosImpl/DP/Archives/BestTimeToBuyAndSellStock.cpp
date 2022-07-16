/*
Problem Statement:

You are given an array/list 'prices' where the elements of the array represent the prices of 
the stock as they were yesterday and indices of the array represent minutes. 

Your task is to find and return the maximum profit you can make by buying and selling the stock. 
You can buy and sell the stock only once.

Note:
You can’t sell without buying first.

For Example:
For the given array [ 2, 100, 150, 120],
The maximum profit can be achieved by buying the stock at minute 0 when its price is Rs. 2 and 
selling it at minute 2 when its price is Rs. 150.

So, the output will be 148.
*/
/*
TLE: 72/80

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int profit=0;
    int sz=prices.size();
    for(int i=0; i<sz; ++i){
        if(i+1<=sz-1){
            for(int j=i+1; j<sz; ++j){
                int curprof=prices[j]-prices[i];
                profit=max(profit, curprof);
            }
        }
    }
    return profit;
}
*/

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    int profit=0, curmin=INT_MAX;
    int sz=prices.size();
    for(int i=0; i<sz; ++i){
        int curprof=prices[i]-curmin;
        profit=max(profit, curprof);
        curmin=min(curmin, prices[i]);
    }
    return profit;
}