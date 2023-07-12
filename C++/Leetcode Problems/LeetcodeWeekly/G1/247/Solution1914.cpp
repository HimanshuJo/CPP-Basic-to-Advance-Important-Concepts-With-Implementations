// 1914. Cyclically Rotating a Grid

/*
You are given an m x n integer matrix grid, where m and n are both even integers, and an integer k.

A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. 
To cyclically rotate a layer once, each element in the layer will take the place of the 
adjacent element in the counter-clockwise direction.

Return the matrix after applying k cyclic rotations to it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        int x = 0, y = 0;
        while (m > 0 && n > 0)
        {
            vector<int> arr = createArray(grid, x, y, m, n);
            int temp = k % (2 * (m + n - 2));
            vector<int> rtArray = rotateArray(arr, temp);
            putIntheGrid(grid, x, y, m, n, rtArray);
            m -= 2;
            n -= 2;
            x += 1;
            y += 1;
        }
        return grid;
    }

    vector<int> createArray(vector<vector<int>> &grid, int x, int y, int m, int n)
    {
        int len = 2 * (m + n - 2);
        vector<int> arr(len);
        int count = 0, startX = x, startY = y;
        for (; x < startX + m; ++x)
        {
            arr[count++] = grid[x][y];
        }
        --x;
        ++y;
        for (; y < startY + n; ++y)
        {
            arr[count++] = grid[x][y];
        }
        --y;
        --x;
        for (; x >= startX; --x)
        {
            arr[count++] = grid[x][y];
        }
        return arr;
    }

    vector<int> rotateArray(vector<int> &arr, int k)
    {
        if (k < 0)
        {
            return arr;
        }
        queue<int> elements;
        for (int i = arr.size() - k; i < arr.size(); ++i)
        {
            elements.push(arr[i]);
        }
        for (int i = arr.size() - k - 1; i >= 0; --i)
        {
            arr[i + k] = arr[i];
        }
        for (int i = 0; i <= k - 1; ++i)
        {
            arr[i] = elements.front();
            elements.pop();
        }
        return arr;
    }

    void putIntheGrid(vector<vector<int>> &grid, int x, int y, int m, int n, vector<int> &arr)
    {
        int count = 0, startX = x, startY = y;
        for (; x < startX + m; ++x)
        {
            grid[x][y] = arr[count++];
        }
        --x;
        ++y;
        for (; y < startY + n; ++y)
        {
            grid[x][y] = arr[count++];
        }
        --y;
        --x;
        for (; x >= startX; --x)
        {
            grid[x][y] = arr[count++];
        }
        ++x;
        --y;
        for (; y > startY; --y)
        {
            grid[x][y] = arr[count++];
        }
    }
};