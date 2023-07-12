/*
You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

	Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
	Output: 4

-------

*/

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        vector<int> dir = {-1, 0, 1, 0, -1};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0; //To keep track of all fresh oranges left
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                if (grid[i][j] == 1)
                    fresh++;
            }
        //initialized to -1 since after each step we increment
        //the time by 1 and initially all rotten oranges started at 0.
        int ans = -1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int r = p.first + dir[i];
                    int c = p.second + dir[i + 1];
                    if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        q.push({r, c});
                        //decrement by 1 for each fresh orange that now is rotten
                        fresh--;
                    }
                }
            }
            ans++; //incremented after each minute passes
        }
        if (fresh > 0)
            return -1; //if fresh>0 that means there are fresh oranges left
        if (ans == -1)
            //we initialized with -1, so if there were no oranges 
            //it'd take 0 mins.
            return 0;
        return ans;
    }
};

/*

-------

class Solution:
	def orangesRotting(self, grid: List[List[int]]) -> int:
		m = len(grid)
		n = len(grid[0])
		# since m and n both starts from 1 we don't need to do a sanity check at the beginning
		ans = 0
		directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
		queue = collections.deque()
		# we will start with all the rotten oranges here
		# we also have to take into account that there can be multiple rotten oranges at the beginning
		# in the grid, we have to get all those oranges and put them in the queue
		for i in range(m):
			for j in range(n):
				if grid[i][j] == 2:
					queue.append((i, j))  # append this orange to the queue
		while queue:
			for _ in range(len(queue)):
				curri, currj = queue.popleft()  # for the BFS search we always pop from left/front and push at the end/tail
				for d in directions:
					newi = curri + d[0]
					newj = currj + d[1]
					if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == 1:
						queue.append((newi, newj))
						grid[newi][newj] = 2
			if queue:  # here we know that there will be some other fresh oranges that will become rotten
				ans += 1
		for i in range(m):
			for j in range(n):
				if grid[i][j] == 1:
					return -1  # at this point we have already infected all the fresh oranges
		return ans

-------

Time:

	The initial for loop is O(m*n)

	The while loop is O(m*n) * 4 (4 for the directions)

		we won't be reprocessing any node more than once, but in the worst case scenario
			we have to travel the whole grid to make all the oranges rotten 

Space:

	O(m*n)

-------

public class Solution {
	public int orangesRotting(int[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int ans = 0;
		int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		LinkedList<int[]> queue = new LinkedList<>();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 2) {
					queue.offer(new int[] { i, j });
				}
			}
		}
		while (!queue.isEmpty()) {
			int queueLen = queue.size();
			for (int i = 0; i < queueLen; ++i) {
				int[] currCoord = queue.pop();
				int curri = currCoord[0];
				int currj = currCoord[1];
				for (int[] d : directions) {
					int newi = curri + d[0];
					int newj = currj + d[1];
					if (0 <= newi && newi < m && 0 <= newj && newj < n && grid[newi][newj] == 1) {
						queue.offer(new int[] { newi, newj });
						grid[newi][newj] = 2;
					}
				}
			}
			if (!queue.isEmpty()) {
				ans += 1;
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					return -1;
				}
			}
		}
		return ans;
	}
}
*/