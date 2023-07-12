// 2328. Number of Increasing Paths in a Grid
/*
You are given an m x n integer matrix grid, where you can move from a cell to any 
adjacent cell in all 4 directions.

Return the number of strictly increasing paths in the grid such that you can start 
from any cell and end at any cell. Since the answer may be very large, return it modulo 10^9 + 7.

Two paths are considered different if they do not have exactly the same sequence of visited cells.

Input: grid = [[1,1],[3,4]]
Output: 8
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [1], [3], [4].
- Paths with length 2: [1 -> 3], [1 -> 4], [3 -> 4].
- Paths with length 3: [1 -> 3 -> 4].
The total number of paths is 4 + 3 + 1 = 8.
Example 2:

Input: grid = [[1],[2]]
Output: 3
Explanation: The strictly increasing paths are:
- Paths with length 1: [1], [2].
- Paths with length 2: [1 -> 2].
The total number of paths is 2 + 1 = 3.
*/

class Solution {
public:
    
    int mod=1e9+7;
    
    bool isValid(vector<vector<int>>&grid, int rws, int cols, int currx, int curry){
        return currx>=0&&curry>=0&&currx<=rws-1&&curry<=cols-1;
    }
    
    int dfs(vector<vector<int>>&grid, int rws, int cols, int currx, int curry, vector<vector<int>>&memo){
        if(currx>=rws||curry>=cols||currx<0||curry<0) return 0;
        if(memo[currx][curry]!=-1) return memo[currx][curry];
        int ans=0, up=0, down=0, left=0, right=0;
        if(isValid(grid, rws, cols, currx-1, curry)&&grid[currx][curry]<grid[currx-1][curry]){
            up=1+dfs(grid, rws, cols, currx-1, curry, memo);
        }
        if(isValid(grid, rws, cols, currx+1, curry)&&grid[currx][curry]<grid[currx+1][curry]){
            down=1+dfs(grid, rws, cols, currx+1, curry, memo);
        }
        if(isValid(grid, rws, cols, currx, curry-1)&&grid[currx][curry]<grid[currx][curry-1]){
            left=1+dfs(grid, rws, cols, currx, curry-1, memo);
        }
        if(isValid(grid, rws, cols, currx, curry+1)&&grid[currx][curry]<grid[currx][curry+1]){
            right=1+dfs(grid, rws, cols, currx, curry+1, memo);
        }
        ans=(up+down+left+right)%mod;
        return memo[currx][curry]=ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        int ans=0;
        vector<vector<int>>memo(rws, vector<int>(cols, -1));
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                ans+=dfs(grid, rws, cols, i, j, memo);
                ans%=mod;
            }
        }
        return (ans+(rws*cols)%mod)%mod;
    }
};