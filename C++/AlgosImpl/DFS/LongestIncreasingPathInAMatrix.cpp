// 329. Longest Increasing Path in a Matrix
/*
Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. 
You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
*/

class Solution {
public:
   
    bool isNotValidBoundary(vector<vector<int>>&matrix, int row, int col, int preval){
        if(row<0||row>=matrix.size()||col<0||col>=matrix[0].size()||matrix[row][col]<=preval){
            return true;
        }
        return false;
    }
    
    int dfs(vector<vector<int>>&matrix, int row, int col, int preval, vector<vector<int>>&memo){
        if(isNotValidBoundary(matrix, row, col, preval)) return 0;
        if(memo[row][col]!=-1) return memo[row][col];
        int res=1;
        res=max(res, 1+dfs(matrix, row+1, col, matrix[row][col], memo));
        res=max(res, 1+dfs(matrix, row-1, col, matrix[row][col], memo));
        res=max(res, 1+dfs(matrix, row, col+1, matrix[row][col], memo));
        res=max(res, 1+dfs(matrix, row, col-1, matrix[row][col], memo));
        return memo[row][col]=res;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rw=matrix.size(), col=matrix[0].size();
        vector<vector<int>>memo(rw, vector<int>(col, -1));
        int res=INT_MIN;
        for(int i=0; i<rw; ++i){
            for(int j=0; j<col; ++j){
                res=max(res, dfs(matrix, i, j, -1, memo));
            }
        }
        return res;
    }
};