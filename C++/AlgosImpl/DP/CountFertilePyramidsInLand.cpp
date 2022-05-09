// 2088. Count Fertile Pyramids in a Land
/*
A farmer has a rectangular grid of land with m rows and n columns that can be divided into unit cells. 
Each cell is either fertile (represented by a 1) or barren (represented by a 0). 

All cells outside the grid are considered barren.

A pyramidal plot of land can be defined as a set of cells with the following criteria:

The number of cells in the set has to be greater than 1 and all cells must be fertile.
The apex of a pyramid is the topmost cell of the pyramid. The height of a pyramid is the number of rows it covers. 
Let (r, c) be the apex of the pyramid, and its height be h. 
Then, the plot comprises of cells (i, j) where r <= i <= r + h - 1 and c - (i - r) <= j <= c + (i - r).
An inverse pyramidal plot of land can be defined as a set of cells with similar criteria:

The number of cells in the set has to be greater than 1 and all cells must be fertile.
The apex of an inverse pyramid is the bottommost cell of the inverse pyramid. The height of an 
inverse pyramid is the number of rows it covers. Let (r, c) be the apex of the pyramid, and its height be h. 
Then, the plot comprises of cells (i, j) where r - h + 1 <= i <= r and c - (r - i) <= j <= c + (r - i).
Some examples of valid and invalid pyramidal (and inverse pyramidal) plots are shown below. Black cells indicate fertile cells.

Input: grid = [[1,1,1,1,0],[1,1,1,1,1],[1,1,1,1,1],[0,1,0,0,1]]
Output: 13
Explanation:
There are 7 pyramidal plots, 3 of which are shown in the 2nd and 3rd figures.
There are 6 inverse pyramidal plots, 2 of which are shown in the last figure.
The total number of plots is 7 + 6 = 13.
*/

class Solution {
	public:
    int dfs(vector<vector<int>>&grid, int i, int j, map<pair<int, int>, int>&memo){
        if(j<0||j>=grid[0].size()||!grid[i][j]) return -1;
        else if(memo.find(make_pair(i, j))!=memo.end()) return memo[make_pair(i, j)];
        if(i+1>=grid.size()||!grid[i+1][j]) return memo[{i, j}]=0;
        return memo[{i, j}]= 1+min(dfs(grid, i+1, j-1, memo), dfs(grid, i+1, j+1, memo));
        }
    
		int countPyramids(vector<vector<int>>& grid) {
			int m=grid.size(), n=grid[0].size();
			int ans=0;
			map<pair<int, int>, int>memo;
			for(int i=0; i<m; ++i){
				for(int j=0; j<n; ++j){
					if(grid[i][j]){
						ans+=dfs(grid, i, j, memo);
					}
				}
			}
			memo.clear();
			reverse(grid.begin(), grid.end());
			for(int i=0; i<m; ++i){
				for(int j=0; j<n; ++j){
					if(grid[i][j]){
						ans+=dfs(grid, i, j, memo);
					}
				}
			}
			return ans;
		}
};
