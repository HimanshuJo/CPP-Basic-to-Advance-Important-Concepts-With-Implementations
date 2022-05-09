#include <bits/stdc++.h>
using namespace std;

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