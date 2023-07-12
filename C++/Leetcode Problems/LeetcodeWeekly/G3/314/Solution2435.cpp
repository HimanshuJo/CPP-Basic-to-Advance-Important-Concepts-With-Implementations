// 2435. Paths in Matrix Whose Sum Is Divisible by K
/*
You are given a 0-indexed m x n integer matrix grid and an integer k. 
You are currently at position (0, 0) and you want to reach position (m - 1, n - 1)
moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. 
Since the answer may be very large, return it modulo 10^9 + 7.

Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
Output: 2
Explanation: There are two paths where the sum of the elements on the path is divisible by k.
The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.

Input: grid = [[0,0]], k = 5
Output: 1
Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.

Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
Output: 10
Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 5 * 10^4
1 <= m * n <= 5 * 10^4
0 <= grid[i][j] <= 100
1 <= k <= 50
*/

class Solution {
public:
    
    int mod=1e9+7;
    
    int dfs(vector<vector<int>>&grid, int rws, int cols, int currw, int curcol, int cursm, int k, vector<vector<vector<int>>>&memo){
        if(currw>=rws||curcol>=cols) return 0;
        if(currw==rws-1&&curcol==cols-1){
            if((cursm%k)==0){
                return 1;
            }
            return 0;
        }
        if(memo[currw][curcol][cursm%k]!=-1) return memo[currw][curcol][cursm%k];
        int right=0, down=0;
        if(curcol+1<=cols-1&&currw<=rws-1){
            int temp=cursm;
            right=dfs(grid, rws, cols, currw, curcol+1, temp+grid[currw][curcol+1], k, memo);   
        }
        if(currw+1<=rws-1&&curcol<=cols-1){
            int temp=cursm;
            down=dfs(grid, rws, cols, currw+1, curcol, temp+grid[currw+1][curcol], k, memo);   
        }
        return memo[currw][curcol][cursm%k]=(right+down)%mod;
    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int rws=grid.size(), cols=grid[0].size();
        int cursm=grid[0][0], currw=0, curcol=0;
        vector<vector<vector<int>>>memo(rws+1, vector<vector<int>>(cols+1, vector<int>(k+1, -1)));
        int ans=dfs(grid, rws, cols, currw, curcol, cursm, k, memo);
        return ans;
    }
};