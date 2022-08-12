// 2304. Minimum Path Cost in a Grid
/*
You are given a 0-indexed m x n integer matrix grid consisting of distinct integers from 0 to m * n - 1. 
You can move in this matrix from a cell to any other cell in the next row. 

That is, if you are in cell (x, y) such that x < m - 1, 
you can move to any of the cells (x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1). 

Note that it is not possible to move from cells in the last row.

Each possible move has a cost given by a 0-indexed 2D array moveCost of size (m * n) x n, 
where moveCost[i][j] is the cost of moving from a cell with value i to a cell in column j of the next row. 

The cost of moving from cells in the last row of grid can be ignored.

The cost of a path in grid is the sum of all values of cells visited plus the sum of costs 
of all the moves made. Return the minimum cost of a path that starts from any cell in the first 
row and ends at any cell in the last row.

Input: grid = [[5,3],[4,0],[2,1]], moveCost = [[9,8],[1,5],[10,12],[18,6],[2,4],[14,3]]
Output: 17
Explanation: The path with the minimum possible cost is the path 5 -> 0 -> 1.
- The sum of the values of cells visited is 5 + 0 + 1 = 6.
- The cost of moving from 5 to 0 is 3.
- The cost of moving from 0 to 1 is 8.
So the total cost of the path is 6 + 3 + 8 = 17.
Example 2:

Input: grid = [[5,1,2],[4,0,3]], moveCost = [[12,10,15],[20,23,8],[21,7,1],[8,1,13],[9,10,25],[5,3,2]]
Output: 6
Explanation: The path with the minimum possible cost is the path 2 -> 3.
- The sum of the values of cells visited is 2 + 3 = 5.
- The cost of moving from 2 to 3 is 1.
So the total cost of this path is 5 + 1 = 6.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 50
grid consists of distinct integers from 0 to m * n - 1.
moveCost.length == m * n
moveCost[i].length == n
1 <= moveCost[i][j] <= 100
*/

// TC: O(n*n^m)  n: number of cols, m: number of rows (without memo)
//     O(m*n^2)  (with memo)
// SC: O(n*m)
class Solution {
public:
    
    int dfs(int currw, int curcol, const int rws, const int cols, 
            const vector<vector<int>>&grid, const vector<vector<int>>&moveCost,
            map<tuple<int, int>, int>&memo){
        if(currw==rws-1){
            return grid[currw][curcol];
        }
        tuple<int, int> tuple1(currw, curcol);
        if(memo.find(tuple1)!=memo.end()) return memo[tuple1];
        int fncost=INT_MAX;
        for(int j=0; j<cols; ++j){
            int curcost=0;
            curcost+=grid[currw][curcol];
            int nwrw=currw+1, nwcol=j;
            curcost+=moveCost[grid[currw][curcol]][nwcol];
            curcost+=dfs(nwrw, nwcol, rws, cols, grid, moveCost, memo);
            fncost=min(fncost, curcost);
        }
        return memo[tuple1]=fncost;
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        int rws=grid.size(), cols=grid[0].size();
        map<tuple<int, int>, int>memo;
        for(int j=0; j<cols; ++j){
            ans=min(ans, dfs(0, j, rws, cols, grid, moveCost, memo));
        }
        return ans;
    }
};

// TC: O(log(m*n)*m*n^2)  n: number of cols, m: number of rows
// SC: O(n*m)
class Solution2 {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int rws=grid.size(), cols=grid[0].size();
        vector<vector<int>>visitedCost(rws, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        for(int j=0; j<cols; ++j){
            pq.push({grid[0][j], 0, j});
        }
        while(!pq.empty()){
            int costTillHere=pq.top()[0];
            int currw=pq.top()[1], curcol=pq.top()[2];
            pq.pop();
            if(currw==rws-1) return costTillHere;
            for(int cl=0; currw+1<rws&&cl<cols; ++cl){
                int newCost=costTillHere+moveCost[grid[currw][curcol]][cl]+grid[currw+1][cl];
                if(newCost<visitedCost[currw+1][cl]){
                    visitedCost[currw+1][cl]=newCost;
                    pq.push({newCost, currw+1, cl});
                }
            }
        }
        return -1;
    }
};

// Bottom up dp
// TC: O(n*n*m)  n: number of cols, m: number of rows
// SC: O(n*m)
class Solution3 {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int rws=grid.size(), cols=grid[0].size();
        vector<vector<int>>dp(rws, vector<int>(cols, INT_MAX));
        dp[rws-1]=grid[rws-1];
        for(int i=rws-2; i>=0; --i){
            for(int j=0; j<cols; ++j){
                for(int k=0; k<cols; ++k){
                    int cost=dp[i+1][k]+moveCost[grid[i][j]][k]+grid[i][j];
                    dp[i][j]=min(dp[i][j], cost);
                }
            }
        }
        return *min_element(dp[0].begin(), dp[0].end());
    }
};

// Top down dp
// TC: O(n*n*m)  n: number of cols, m: number of rows
// SC: O(n*m)
class Solution4 {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int rws=grid.size(), cols=grid[0].size();
        vector<vector<int>>dp(rws, vector<int>(cols, INT_MAX));
        dp[0]=grid[0];
        for(int i=1; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                for(int k=0; k<cols; ++k){
                    int cost=dp[i-1][j]+grid[i][k]+moveCost[grid[i-1][j]][k];
                    dp[i][k]=min(dp[i][k], cost);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};

// Top down dp
// TC: O(n*n*m)  n: number of cols, m: number of rows
// SC: O(n)
class Solution5 {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int rws=grid.size(), cols=grid[0].size();
        vector<int>prev=grid[0];
        for(int i=1; i<rws; ++i){
            vector<int>curr(cols, INT_MAX);
            for(int j=0; j<cols; ++j){
                for(int k=0; k<cols; ++k){
                    int cost=prev[j]+grid[i][k]+moveCost[grid[i-1][j]][k];
                    curr[k]=min(curr[k], cost);   
                }
            }
            prev=curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
