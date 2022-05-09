// 2008. Maximum Earnings From Taxi
/*
There are n points on a road you are driving your taxi on. The n points on the road are labeled from 1 to n
in the direction you are going, and you want to drive from point 1 to point n to make money by picking up passengers.
You cannot change the direction of the taxi.

The passengers are represented by a 0-indexed 2D integer array rides, where rides[i] = [starti, endi, tipi] denotes
the ith passenger requesting a ride from point starti to point endi who is willing to give a tipi dollar tip.

For each passenger i you pick up, you earn endi - starti + tipi dollars. You may only drive at most one passenger at a time.

Given n and rides, return the maximum number of dollars you can earn by picking up the passengers optimally.

Note: You may drop off a passenger and pick up a different passenger at the same point.

Example 1:

Input: n = 5, rides = [[2,5,4],[1,5,1]]
Output: 7
Explanation: We can pick up passenger 0 to earn 5 - 2 + 4 = 7 dollars.

Example 2:

Input: n = 20, rides = [[1,6,1],[3,10,2],[10,12,3],[11,12,2],[12,15,2],[13,18,1]]
Output: 20
Explanation: We will pick up the following passengers:
- Drive passenger 1 from point 3 to point 10 for a profit of 10 - 3 + 2 = 9 dollars.
- Drive passenger 2 from point 10 to point 12 for a profit of 12 - 10 + 3 = 5 dollars.
- Drive passenger 5 from point 13 to point 18 for a profit of 18 - 13 + 1 = 6 dollars.
We earn 9 + 5 + 6 = 20 dollars in total.
*/

/*
Solution 2:

class Solution {
public:
    long long dp[(int)1e5];
    long long recur(vector<vector<int>>&rides, int nn, int idx)
    {
        if(idx>=nn) return 0;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx+1; i<nn; i++)
        {
            if(rides[i][0]>=rides[idx][1])
                break;
        }
        long long op1=recur(rides, nn, idx+1);
        long long op2=rides[idx][1]-rides[idx][0]+rides[idx][2]+recur(rides,nn,i);
        return dp[idx]=max(op1, op2);
    }
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        sort(rides.begin(),rides.end());
        int nn=rides.size();
        memset(dp,-1, sizeof dp);
        return recur(rides, nn, 0);
    }
};
*/

/*
Solution 3:

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:

    long long dfs(vector<vector<int>>&rides, int idx, vector<int>&memo) {
        if (idx < rides.size() && memo[idx] != -1) {
            return memo[idx];
        }
        vector<int>curr = rides[idx];
        long long maxProf = 0;
        for (int i = idx + 1; i < rides.size(); ++i) {
            vector<int>nxt = rides[i];
            if (nxt[0] >= curr[1]) {
                long long prof = dfs(rides, i, memo);
                maxProf = max(maxProf, prof);
            }
        }
        maxProf += (curr[1] - curr[0] + curr[2]);
        return memo[idx] = maxProf;;
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<int>memo(n + 1, -1);
        sort(rides.begin(), rides.end());
        long long fnprof = 0;
        for (int i = 0; i < rides.size(); ++i) {
            long long prof = dfs(rides, i, memo);
            fnprof = max(fnprof, prof);
        }
        return fnprof;
    }
};

int main() {
    int n = 5;
    vector<vector<int>>rides = {{2, 5, 4}, {1, 5, 1}};
    Solution obj;
    cout << obj.maxTaxiEarnings(n, rides);
}
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    long long dp[100005];

    int binarySearch(vector<vector<int>> &rides, int val)
    {
        int s = 0, e = rides.size() - 1;
        int ans = rides.size();
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (rides[mid][0] >= val)
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }

    long long helper(int i, vector<vector<int>> &rides)
    {
        if (i == rides.size())
        {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        long long op1 = helper(i + 1, rides);
        int idx = binarySearch(rides, rides[i][1]);
        long long op2 = rides[i][1] - rides[i][0] + rides[i][2] + helper(idx, rides);
        return dp[i] = max(op1, op2);
    }

public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides)
    {
        memset(dp, -1, sizeof dp);
        sort(rides.begin(), rides.end());
        return helper(0, rides);
    }
};