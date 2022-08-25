// Last Day Where You Can Still Cross
/*
There is a 1-based binary matrix where 0 represents land and 1 represents water. 
You are given integers row and col representing the number of rows and columns in the matrix, 
respectively.

Initially on day 0, the entire matrix is land. However, each day a new cell becomes 
flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] 
represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) 
will be covered with water (i.e., changed to 1).

You want to find the last day that it is possible to walk from the top to the bottom 
by only walking on land cells. You can start from any cell in the top row and end at 
any cell in the bottom row. You can only travel in the four cardinal directions 
(left, right, up, and down).

Return the last day where it is possible to walk from the top to the bottom by 
only walking on land cells.

Example:
Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
Output: 3
Explanation: The above image depicts how the matrix changes each day starting from day 0.
The last day where it is possible to cross from top to bottom is on day 3.

Constraints:

2 <= row, col <= 2 * 104
4 <= row * col <= 2 * 104
cells.length == row * col
1 <= ri <= row
1 <= ci <= col
All the values of cells are unique.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int X[4] = {0, 0, -1, 1};
    int Y[4] = {-1, 1, 0, 0};
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int n = row;
        int m = col;
        vector<vector<int>> a(n, vector<int>(m, 0));
        int x = 0;
        for (auto xt : cells)
        {
            int rr = xt[0];
            int cc = xt[1];
            rr--;
            cc--;
            if (!bfs(a, n, m))
                break;
            a[rr][cc] = 1;
            x++;
        }
        if (x == 0)
            return x;
        return x - 1;
    }
    bool bfs(vector<vector<int>> a, int n, int m)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            if (a[0][i] == 0)
            {
                q.push({0, i});
                a[0][i] = 1;
            }
        }

        while (!q.empty())
        {
            int ss = q.size();
            while (ss--)
            {
                pair<int, int> pr = q.front();
                q.pop();
                int ii = pr.first;
                int jj = pr.second;
                if (ii == n - 1)
                    return 1;
                for (int i = 0; i < 4; i++)
                {
                    int nx = ii + X[i];
                    int ny = jj + Y[i];
                    if (nx >= 0 and nx < n and ny >= 0 and ny < m and a[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        a[nx][ny] = 1;
                    }
                }
            }
        }
        return 0;
    }
};