// 1931. Painting a Grid With Three Different Colors
/*
You are given two integers m and n. Consider an m x n grid where each cell is initially white.
You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color.
Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:

Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.

Example 3:

Input: m = 5, n = 5
Output: 580986
*/

/*
Use DP to calcuate number of ways.
Since M <= 5, we can fill colors of matrix column by column. To store previous column state in DP, we can use BitMask,
each 2 bits store a color (1=Red, 2=Green, 3=Blue, 0=White), so there is total 4^M column states.
Complexity

    Time: O(N * 3^M * 2^M), where N <= 1000 is number of columns, M <= 5 is number of columns.
          
          There is total: N * 3^M states in dp params, each state has up to (2^M) neighbors to calculate.
        
          Why up to 2^M neighbors each state? Because choose color of cell (0, c) has up to 2 ways
         (different color from cell(0, c-1)),
         choose color of cell (1, c) has up to ways (different color from both cell(1, c-1) and cell(0, c))... until M rows.

    Space:
        C++: O(N * 4^M + 4^M * 2^M), because in C++ we use memory 4^M=1024 to store colors of states.

        Python: O(N * 3^M + 3^M * 2^M), because in Python @lru_cache up to 3^M colors of column states (red, green, blue).

*/

#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    int memo[1000][1024] = {};
    vector<int> neiMemo[1024] = {};
    int MOD = 1e9 + 7;

    int colorTheGrid(int m, int n)
    {
        return dp(0, 0, m, n);
    }

    int dp(int c, int prevColMask, int m, int n)
    {
        if (c == n)
        {
            return 1;
        }
        if (memo[c][prevColMask])
        {
            return memo[c][prevColMask];
        }
        int ans = 0;
        for (int nei : neighbors(prevColMask, m, n))
        {
            ans = (ans + dp(c + 1, nei, m, n)) % MOD;
        }
        return memo[c][prevColMask] = ans;
    }

    vector<int> neighbors(int prevColMask, int m, int n)
    {
        // Generating all the possible columns we can draw if the previous
        // col is prevColMask
        if (!neiMemo[prevColMask].empty())
        {
            return neiMemo[prevColMask];
        }
        dfs(0, prevColMask, 0, neiMemo[prevColMask], m, n);
        return neiMemo[prevColMask];
    }

    void dfs(int r, int prevColMask, int curColMask, vector<int> &out, int m, int n)
    {
        if (r == m)
        {
            out.push_back(curColMask);
            return;
        }
        for (int i = 1; i <= 3; ++i)
        {
            if (getColor(prevColMask, r) != i && (r == 0 || getColor(curColMask, r - 1) != i))
            {
                dfs(r + 1, prevColMask, setColor(curColMask, r, i), out, m, n);
            }
        }
    }

    int getColor(int mask, int pos)
    {
        return (mask >> (2 * pos)) & 3;
    }

    int setColor(int mask, int pos, int color)
    {
        return mask | (color << (2 * pos));
    }
};