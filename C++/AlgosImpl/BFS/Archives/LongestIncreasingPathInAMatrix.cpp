// 329. Longest Increasing Path in a Matrix
/*
Given an m x n integers matrix, return the length of the longest increasing path
in matrix.

From each cell, you can either move in four directions: left, right, up, or
down. You may not move diagonally or move outside the boundary (i.e.,
wrap-around is not allowed).

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
*/

class Solution {
 public:
  bool isNotValidBoundary(vector<vector<int>> &matrix, int row, int col) {
    return (row < 0 || col < 0 || row >= matrix.size() ||
            col >= matrix[0].size());
  }

  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int rws = matrix.size(), cols = matrix[0].size();
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> indegrees(rws, vector<int>(cols));
    queue<pair<int, int>> q;
    for (int i = 0; i < rws; ++i) {
      for (int j = 0; j < cols; ++j) {
        for (auto &dir : directions) {
          int nwrw = i + dir[0], nwcol = j + dir[1];
          if (!isNotValidBoundary(matrix, nwrw, nwcol)) {
            if (matrix[i][j] > matrix[nwrw][nwcol]) {
              indegrees[i][j]++;
            }
          }
        }
        if (indegrees[i][j] == 0) {
          q.push({i, j});
        }
      }
    }
    int len(0);
    while (!q.empty()) {
      int qsz = q.size();
      while (qsz--) {
        pair<int, int> currCord = q.front();
        q.pop();
        for (auto &vals : directions) {
          int nwrw = vals[0] + currCord.first,
              nwcol = vals[1] + currCord.second;
          if (!isNotValidBoundary(matrix, nwrw, nwcol) &&
              matrix[nwrw][nwcol] > matrix[currCord.first][currCord.second] &&
              !--indegrees[nwrw][nwcol]) {
            q.push({nwrw, nwcol});
          }
        }
      }
      len++;
    }
    return len;
  }
};