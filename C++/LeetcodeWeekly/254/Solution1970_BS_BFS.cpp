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
        int lday = 0;
        int rday = cells.size() - 1;
        while (lday <= rday)
        {
            int mid = (lday + rday) / 2;
            for (int j = 0; j < mid; j++)
            {
                a[cells[j][0] - 1][cells[j][1] - 1] = 1;
            }
            if (bfs(a, n, m))
            {
                lday = mid + 1;
                x = mid;
            }
            else
            {
                rday = mid - 1;
            }
            for (int j = 0; j < mid; j++)
            {
                a[cells[j][0] - 1][cells[j][1] - 1] = 0;
            }
        }
        return x;
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
                // if we get last row means we are able to reach return true
                if (ii == n - 1)
                    return true;
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
        return false;
    }
};