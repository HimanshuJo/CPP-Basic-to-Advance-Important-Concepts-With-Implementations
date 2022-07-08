/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/

/*
Bottom up dp

// Time: O(m*n), Space: O(m*n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1, vector<int>(n+1, 1));
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                if(i+1<m&&j+1<n) dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

-------

// Time: O(m*n), Space: O(n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n, 1), cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] = pre[j] + cur[j - 1];
            }
            swap(pre, cur);
        }
        return pre[n - 1];
    }
};
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

    int getPath(int rw, int col,  vector<vector<int>>&memo, int &ans) {
        if (col < 0 || rw < 0) return ans;
        bool isAtOrigin = (rw == 0) && (col == 0);
        if (isAtOrigin) {
            return 1;
        }
        if (memo[rw][col] > 0) {
            return memo[rw][col];
        }
        return memo[rw][col] = getPath(rw, col - 1, memo, ans) + getPath(rw - 1, col, memo, ans);
    }

    int uniquePaths(int m, int n) {
        int ans = 0;
        vector<vector<int>>memo(101, vector<int>(101, -1));
        if (m == 0 && n == 0) return 1;
        return getPath(m - 1, n - 1, memo, ans);
    }
};

int main(){
    Solution obj;
    int m=23, n=12;
    cout<<obj.uniquePaths(m, n);
}