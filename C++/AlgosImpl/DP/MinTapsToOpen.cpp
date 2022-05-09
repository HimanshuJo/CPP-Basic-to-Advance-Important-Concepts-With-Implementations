// 1326. Minimum Number of Taps to Open to Water a Garden
/*
There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and 
ends at the point n. (i.e The length of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) 
means the i-th tap can water the area [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, 
If the garden cannot be watered return -1.

Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
Explanation: The tap at point 0 can cover the interval [-3,3]
The tap at point 1 can cover the interval [-3,5]
The tap at point 2 can cover the interval [1,3]
The tap at point 3 can cover the interval [2,4]
The tap at point 4 can cover the interval [4,4]
The tap at point 5 can cover the interval [5,5]
Opening Only the second tap will water the whole garden [0,5]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int dfs(int n,  vector<int>&mp, vector<int>&memo){
        if(n==0) return 0;
        if(memo[n]!=-1) return memo[n];
        memo[n]=INT_MAX;
        if(mp[n]==INT_MAX) return memo[n];
        for(int i=n-1; i>=mp[n]; --i){
            int currans=dfs(i, mp, memo);
            if(currans!=INT_MAX)
                memo[n]=min(memo[n], currans+1);
        }
        return memo[n];
    }

    int minTaps(int n, vector<int>&ranges){
        vector<int>mp(n+1, INT_MAX);
        for(int i=0; i<ranges.size(); ++i){
            int begin=max(i-ranges[i], 0);
            int end=min(i+ranges[i], n);
            mp[end]=min(mp[end], begin);
        }
        vector<int>memo(n+1, -1);
        int ans=dfs(n, mp, memo);
        return ans==INT_MAX?-1:ans;
    }
};

class Solution2 {
public:
    int minTaps(int n, vector<int>& ranges) {
        int len=ranges.size();
        vector<int>dp(len+1, len+1);
        dp[0]=0;
        for(int i=0; i<len; ++i){
            int start=max(i-ranges[i], 0);
            int end=min(i+ranges[i], len-1);
            for(int j=start; j<=end; ++j){
                dp[j]=min(dp[j], dp[start]+1);
            }
        }
        return dp[len-1]==len+1?-1:dp[len-1];
    }
};

int main(){}
