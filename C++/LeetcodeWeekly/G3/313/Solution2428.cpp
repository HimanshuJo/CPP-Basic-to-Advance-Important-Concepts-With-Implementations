// 2428. Maximum Sum of an Hourglass
/*
You are given an m x n integer matrix grid.

We define an hourglass as a part of the matrix with the following form:

Return the maximum sum of the elements of an hourglass.

Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
Output: 30
Explanation: The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.

Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: 35
Explanation: There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.
 

Constraints:

m == grid.length
n == grid[i].length
3 <= m, n <= 150
0 <= grid[i][j] <= 10^6
*/

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        long long ans=LONG_MIN;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(j-1>=0&&j+1<=cols-1&&i+2<=rws-1){
                    long long cursm=0;
                    cursm+=grid[i][j], cursm+=grid[i][j-1], cursm+=grid[i][j+1],
                    cursm+=grid[i+1][j], cursm+=grid[i+2][j], cursm+=grid[i+2][j-1], cursm+=grid[i+2][j+1];
                    ans=max(ans, cursm);
                }
            }
        }
        return ans;
    }
};