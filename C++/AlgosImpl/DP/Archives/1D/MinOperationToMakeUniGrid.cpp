// 2033. Minimum Operations to Make a Uni-Value Grid
/*
You are given a 2D integer grid of size m x n and an integer x.
In one operation, you can add x to or subtract x from any element in the grid.

A uni-value grid is a grid where all the elements of it are equal.

Return the minimum number of operations to make the grid uni-value.
If it is not possible, return -1.

Input: grid = [[2,4],[6,8]], x = 2
Output: 4
Explanation: We can make every element equal to 4 by doing the following:
- Add x to 2 once.
- Subtract x from 6 once.
- Subtract x from 8 twice.
A total of 4 operations were used.

Input: grid = [[1,5],[2,3]], x = 1
Output: 5
Explanation: We can make every element equal to 3.

Input: grid = [[1,2],[3,4]], x = 2
Output: -1
Explanation: It is impossible to make every element equal.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10^5
1 <= m * n <= 10^5
1 <= x, grid[i][j] <= 10^4
*/

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> tmp;
        int mod = grid[0][0] % x;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                tmp.push_back(grid[i][j]);
                if (grid[i][j] % x != mod) {
                    return -1;
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        int median = tmp[(n * m) / 2];
        int minOperations = 0;
        for (int i = 0; i < n * m; ++i)
            minOperations += abs(tmp[i] - median) / x;
        if ((n * m) % 2 == 0)
        {
            int median2 = tmp[((n * m) / 2) - 1];
            int minOperations2 = 0;
            for (int i = 0; i < n * m; ++i)
                minOperations2 += abs(tmp[i] - median2) / x;

            minOperations = min(minOperations, minOperations2);
        }
        return minOperations;
    }
};

// -------*******-------

class Solution2 {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int res = INT_MAX, ops = 0;
        vector<int>vec;
        // number of operations required to convert all the previous numbers to the current number
        vector<int>dp(grid.size()*grid[0].size());
        for (auto &row : grid) {
            vec.insert(end(vec), begin(row), end(row));
        }
        sort(begin(vec), end(vec));
        for (int i = 0; i < vec.size() - 1; ++i) {
            if ((vec[i + 1] - vec[i]) % x) return -1;
            // current stores:
            // previous required operations for individual numbers + ((current required operations)*(currIdx+1))
            // (*currIdx+1): all previous numbers has to first reach the current number then get the current req. operations
            dp[i + 1] = dp[i] + ((i + 1) * ((vec[i + 1] - vec[i]) / x));
        }
        for (int i = vec.size() - 1; i > 0; --i) {
            ops += (vec.size() - i) * ((vec[i] - vec[i - 1]) / x);
            res = min(res, ops + dp[i - 1]);
        }
        return res == INT_MAX ? 0 : res;
    }
};