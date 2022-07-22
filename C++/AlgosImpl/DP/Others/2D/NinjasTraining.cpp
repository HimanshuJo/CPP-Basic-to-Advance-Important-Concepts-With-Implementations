// Ninja’s Training
/*
Problem Statement:

Ninja is planing this ‘N’ days-long training schedule. 
Each day, he can perform any one of these three activities. 
(Running, Fighting Practice or Learning New Moves). 

Each activity has some merit points on each day. 
As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
Can you help Ninja find out the maximum merit points Ninja can earn?

You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each 
day and activity. 

Your task is to calculate the maximum number of merit points that Ninja can earn.

For Example

If the given ‘POINTS’ array is [[1,2,5], [3,1,1] ,[3,3,3]], the answer will be 11 as 5 + 3 + 3.
*/

#include<climits>
#include<vector>

int dfs(int n, vector<vector<int>>&points, int idx, int prev, vector<vector<int>>&memo){
    if(idx>=n) return 0;
    if(idx==n-1){
        int temp=INT_MIN;
        for(int i=0; i<3; ++i){
            if(i!=prev){
                temp=max(temp, points[idx][i]);
            }
        }
        return temp;
    }
    if(memo[idx][prev]!=-1) return memo[idx][prev];
    int temp=0;
    for(int i=0; i<3; ++i){
        if(i!=prev){
            temp=max(temp, points[idx][i]+dfs(n, points, idx+1, i, memo));
        }
    }
    return memo[idx][prev]=temp;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>memo(n+1, vector<int>(3, -1));
    int fnans=INT_MIN;
    for(int i=0; i<3; ++i){
        int ans=points[0][i];
        int curans=dfs(n, points, 1, i, memo);
        ans+=curans;
        fnans=max(fnans, ans); 
    }
    return fnans;
}

// -------*******-------

int ninjaTraining2(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n+1, vector<int>(4, 0));
    dp[n-1][0]=max(points[n-1][1], points[n-1][2]);
    dp[n-1][1]=max(points[n-1][0], points[n-1][2]);
    dp[n-1][2]=max(points[n-1][0], points[n-1][1]);
    dp[n-1][3]=max(points[n-1][0], max(points[n-1][1], points[n-1][2]));
    for(int idx=n-2; idx>=0; --idx){
        for(int prev=0; prev<4; ++prev){
            for(int i=0; i<3; ++i){
                if(i!=prev){
                    int temp=points[idx][i]+dp[idx+1][i];
                    dp[idx][prev]=max(dp[idx][prev], temp);
                }
            }
        }
    }
    int ans=INT_MIN;
    for(auto &vals: dp[0]){
        ans=max(ans, vals);
    }
    return ans;
}