// 1981. Minimize the Difference Between Target and Chosen Elements
/*
You are given an m x n integer matrix mat and an integer target.

Choose one integer from each row in the matrix such that the absolute
difference between target and the sum of the chosen elements is minimized.

Return the minimum absolute difference.

The absolute difference between two numbers a and b is the absolute value of a - b.

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], target = 13
Output: 0
Explanation: One possible choice is to:
- Choose 1 from the first row.
- Choose 5 from the second row.
- Choose 7 from the third row.
The sum of the chosen elements is 13, which equals the target, so the absolute difference is 0.

Example 2:

Input: mat = [[1],[2],[3]], target = 100
Output: 94
Explanation: The best possible choice is to:
- Choose 1 from the first row.
- Choose 2 from the second row.
- Choose 3 from the third row.
The sum of the chosen elements is 6, and the absolute difference is 94.

Example 3:

Input: mat = [[1,2,9,8,7]], target = 6
Output: 1
Explanation: The best choice is to choose 7 from the first row.
The absolute difference is 1.

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 70
1 <= mat[i][j] <= 70
1 <= target <= 800
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dfs(vector<set<int>>& m, int i, int sum, int target, int dp[71][70 * 70 + 1]) {
        if (i >= m.size())
            return abs(sum - target);
        if (dp[i][sum] == INT_MAX)
            for (auto it = begin(m[i]); it != end(m[i]); ++it) {
                dp[i][sum] = min(dp[i][sum], dfs(m, i + 1, sum + *it, target, dp));
                if (dp[i][sum] == 0 || sum + *it > target)
                    break;
            }
        return dp[i][sum];
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<set<int>>m;
        int dp[71][70 * 70 + 1];
        for (int i = 0; i < 70; ++i) {
            for (int j = 0; j < 70 * 70; ++j) {
                dp[i][j] = INT_MAX;
            }
        }
        for (auto &row : mat) {
            m.push_back(set<int>(begin(row), end(row)));
        }
        return dfs(m, 0, 0, target, dp);
    }
};