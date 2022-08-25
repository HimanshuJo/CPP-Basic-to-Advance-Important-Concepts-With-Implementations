// Count Sub Islands

/*
 * You are given two m x n binary matrices grid1 and grid2 containing only 0's
 * (representing water) and 1's (representing land). An island is a group of 1's
 * connected 4-directionally (horizontal or vertical).
 *
 * Any cells outside of the grid are considered water cells.

   An island in grid2 is considered a sub-island if there is an island in grid1 that
   contains all the cells that make up this island in grid2.

   Return the number of islands in grid2 that are considered sub-islands.

Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]],
	   grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island.
There are three sub-islands.
 */

/*
 *  We can perform a DFS/BFS on grid2 matrix, similar to 'Number of islands task'
 *
 *  For a current island in gird2, check for every cell in that island if they are present in grid1
 *  	This will ensure that if this is a sub-island of grid1
 *
 *  Maintain a flag and mark it false, if we encounter any cell which is a part of island in grid2
 *  	and not a part of island in grid1
 *
 *  Increase the count for each of the island of grid2, when the flag is true
 *
 *  Return the count, as this will be the number of islands in grid2 that are considered sub-islands
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int M = grid2.size();
        int N = grid2[0].size();
        int subIslandCount = 0;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (grid2[i][j] == 1)
                {
                    bool hasSubIslandFound = bfs(i, j, M, N, grid1, grid2);
                    subIslandCount += hasSubIslandFound;
                }
            }
        }
        return subIslandCount;
    }
    
    bool bfs(int i, int j, int &M, int &N, vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        queue<vector<int>> queue;
        queue.push({i, j});
        grid2[i][j] = 0;
        bool hasSubIslandFound = true;
        while (!queue.empty())
        {
            vector<int> cur = queue.front();
            queue.pop();
            if (grid1[cur[0]][cur[1]] != 1)
            {
                hasSubIslandFound = false;
            }
            for (vector<int> &dir : directions)
            {
                int newi = dir[0] + cur[0];
                int newj = dir[1] + cur[1];
                if (inside(newi, newj, M, N) && grid2[newi][newj] == 1)
                {
                    queue.push({newi, newj});
                    grid2[newi][newj] = 0;
                }
            }
        }
        return hasSubIslandFound;
    }

    bool inside(int i, int j, int &M, int &N)
    {
        if (i < 0 || i >= M || j < 0 || j >= N)
        {
            return false;
        }
        return true;
    }
};