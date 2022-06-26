/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water),
return the number of islands.

An island is surrounded by water and is formed by connecting
adjacent lands horizontally or vertically.

You may assume all four edges of the grid are all surrounded by water.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>&grid) {
        int n = grid.size();
        int wd = grid[0].size();
        vector<vector<int>>dir = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>>vis(n + 1, vector<bool>(wd + 1, 0));
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= wd; ++j) {
                vis[i][j] = false;
            }
        }
        vector<int>res;
        queue<vector<int>>q;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < wd; ++j) {
                if (grid[i][j] == '1') {
                    vector<int>start = {i, j};
                    q.push(start);
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        ans++;
                        int qLen = q.size();
                        for (int i = 0; i < qLen; ++i) {
                            vector<int>curr = q.front();
                            q.pop();
                            for (vector<int> d : dir) {
                                int newX = curr[0] + d[0];
                                int newY = curr[1] + d[1];
                                if (newX >= 0 && newX < n && newY >= 0 && newY < wd &&
                                        vis[newX][newY] != true &&
                                        grid[newX][newY] == '1') {
                                    vector<int>next = {newX, newY};
                                    q.push(next);
                                    vis[newX][newY] = true;
                                    grid[newX][newY] = '0';
                                }
                            }
                        }
                    }
                    res.push_back(ans);
                }
            }
        }
        cout << res.size();
        return res.size();
    }
};

int main() {
    Solution obj;
    vector<vector<char>>grid = {{'0', '0' , '0', '0'}, {'1', '1' , '0', '0'}, {'1', '1' , '0', '0'}, {'0', '0' , '1', '1'}};
    obj.numIslands(grid);
}