/*
You are given row x col grid representing a map where grid[i][j] = 1
represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island
(i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island.
One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100.
Determine the perimeter of the island.

-------

How can we get the total perimeter of the island

	one of the observations we need to think about is that

		suppose we have just one square, if there is just one square, then obviously
			the perimeter is 4

		and every time if we find an another square which is its neighbor
			no matter what direction is the neighbor in

			to calculate the total perimeter, we have to subtract one from the perimeter
				of the current square (4 - 1)

			similarly we loop through all the 1's which denotes the land
				if that 1 has any neighbor in any four directions

				for each neighbor we subtract one from the perimeter of that particular square

	In essence if two ones are connected to each other, the total edges we need to decrease is 2
		so we have to decrease 1 from the perimeter of one square

		and 1 from the perimeter of the other square

-------

Without BFS:

	class Solution:
		def islandPerimeter(self, grid: List[List[int]]) -> int:
			m = len(grid)
			n = len(grid[0])

			# we will initialize the directions so that we don't have to re-write the
			# same logic 4 times
			directions = {(-1, 0), (1, 0), (0, -1), (0, 1)}  # up, down, left, right
			ans = 0
			for i in range(m):
				for j in range(n):
					if grid[i][j] == 1:
						ans += 4
						# check how many neighbor does this 1 has
						for d in directions:
							newi = i + d[0]
							newj = j + d[1]

							# important is to do the boundary check first
							if 0 <= newi < m and 0 <= newj < n and grid[newi][newj] == 1:
								ans -= 1
			return ans

-------

Why to go for BFS, suppose our grid is huge
	m = 1_000_000_000
	n = 1_000_000_000

	however, the resultant island is very small
		in that case with the above approach, we will still be traversing the entire m and n

		so one of the small improvement we can do here is

			as long as we find the first one in the Grid
				we can just start from there

				we can just use the DFS or BFS

-------

class Solution:

	def islandPerimeter(Self, grid: List[List[int]]) -> int:
		m = len(grid)
		n = len(grid[0])
		direction = [(-1, 0), (1, 0), (0, 1), (0, -1)]
		ans = 0
		seen = set()
		for i in range(m):
			for j in range(n):
				if grid[i][j] == 1:
					queue = collections.deque([(i, j)])  # inside the queue we will have the tuple
					seen.add((i, j))

					# here is the entire BFS logic without level control
					while queue:
						# as long as we are looping through all the 1's it's fine
						# to either pop left or pop right
						curri, currj = queue.popleft()
						ans += 4
						for d in directions:
							newi = curri + d[0]
							newj = currj + d[1]

							if 0 <= newi < m and 0 <= newj < n:
								if grid[newi][newj]:
									ans -= 1
									if (newi, newj) not in seen:
										queue.append((newi, newj))
										seen.add((newi, newj))
					# at this point we don't need to travel further we would have already found
					# all the connected 1's
					return ans

-------

class Solution {

	public int islandPerimeter(int[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
		Set<ArrayList<Integer>> set = new HashSet<>();
		int ans = 0;
		boolean flag = false;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					flag = true;
					PriorityQueue<List<Integer>> queue = new PriorityQueue<>
						((a, b) -> (a.get(0) - b.get(0)));
					ArrayList<Integer> list = new ArrayList<>();
					list.add(i);
					list.add(j);
					queue.offer(list);
					set.add(list);
					while (!queue.isEmpty()) {
						List<Integer> temp = queue.poll();
						int curri = temp.get(0);
						int currj = temp.get(1);
						ans += 4;
						for (int[] d : directions) {
							int newi = curri + d[0];
							int newj = currj + d[1];
							if (0 <= newi && newi < m && 0 <= newj && newj < n) {
								if (grid[newi][newj] == 1) {
									ans -= 1;
									ArrayList<Integer> temp_ = new ArrayList<>();
									temp_.add(newi);
									temp_.add(newj);
									if (!set.contains(temp_)) {
										queue.offer(temp_);
										set.add(temp_);
									}
								}
							}
						}
					}
				}
				if (flag) break;
			}
            if (flag) break;
		}
		return ans;
	}
}

-------

// 20 ms
class Solution_LinkedList {

	public int islandPerimeter(int[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
		boolean[][] visited = new boolean[m][n];
		for (boolean[] arr : visited) {
			Arrays.fill(arr, false);
		}
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1) {
					LinkedList<int[]> queue = new LinkedList<>();
					queue.offer(new int[] { i, j });
					visited[i][j] = true;
					while (!queue.isEmpty()) {
						int[] temp = queue.poll();
						int curri = temp[0];
						int currj = temp[1];
						ans += 4;
						for (int[] d : directions) {
							int newi = curri + d[0];
							int newj = currj + d[1];
							if (0 <= newi && newi < m && 0 <= newj && newj < n) {
								if (grid[newi][newj] == 1) {
									ans -= 1;
									if (!visited[newi][newj]) {
										queue.offer(new int[] { newi, newj });
										visited[newi][newj] = true;
									}
								}
							}
						}
					}
					return ans;
				}
			}
		}
		return -1;
	}
}

-------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int dir[4][2] = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};

	int islandPerimeter(vector<vector<int>> &grid)
	{
		int i, j, ans = 0, l, n = grid.size(), m = grid[0].size(), pos_i, pos_j, temp;
		vector<vector<bool>> vis(n, vector<bool>(m, false));
		queue<pair<int, int>> q;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (grid[i][j] && !vis[i][j])
				{
					q.push({i, j});
					vis[i][j] = true;
					while (!q.empty())
					{
						auto t = q.front();
						q.pop();
						temp = 4;
						for (l = 0; l < 4; l++)
						{
							pos_i = t.first + dir[l][0];
							pos_j = t.second + dir[l][1];
							if (pos_i >= 0 && pos_i < n && pos_j >= 0 && pos_j < m && grid[pos_i][pos_j])
							{
								temp--;
								if (!vis[pos_i][pos_j])
								{
									vis[pos_i][pos_j] = true;
									q.push({pos_i, pos_j});
								}
							}
						}
						ans += temp;
					}
					break;
				}
			}
		}
		return ans;
	}
};