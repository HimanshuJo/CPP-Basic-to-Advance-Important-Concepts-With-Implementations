/*
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). In one step, you can move 
	up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the lower right corner (m-1, n-1) 
given that you can eliminate at most k obstacles. If it is not possible to find such walk return -1.

Example 1:

Input: 
grid = 
[[0,0,0],
 [1,1,0],
 [0,0,0],
 [0,1,1],
 [0,0,0]],

k = 1

Output: 6

Explanation: 
	
	The shortest path without eliminating any obstacle is 10. 
	
	The shortest path with one obstacle elimination at position (3,2) is 6. 

	Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).

-------

Intuition:

	Since we have to find the minimum path, so BFS can be used here, however we also have to handle 'k' here

	In a general BFS search we normally have a visited or a seen set
		so that we do not fall into an infinite loop

		however in the current scenario, one node can be visited multiple times

			suppose we have the nodes like this:
				0 0
				1 0

				we start our search with the first 0 in the left hand side and we add it's immediate left and immediate
					node below in the frontier for the next search

					we will next visit the node with value 1, so every time we hit a 1 we've to check
						
						if in the current search we can remove this obstacle,

						if the remaining k > 0, then we know that we can remove this particular one

						and we also know that from this 1 and the the right node of 1's parent node
							can both visit the last node

				If we only use the normal BFS search

					we first process the node with the value 1, and we mark it immediate right node as visited

					but in this particular case, we have a better solution from the other node

						because taking the other route there is no need to reduce any k

				Hence, instead of adding just two coordinates 'i' and 'j' in the seen set,
					we also have to add one other coordinate which is 'k'

	Some thought process:

		At the beginning we just thought the seen only store the coordinates (i, j) for a particular node

		However, if we look more closely, the seen set actually stores the state of a particular node

			Using a normal BFS search, just the two coordinates (i, j) can uniquely identify a particular node

			However, here in this particular case,
				the state of reaching the last node from the node having the value 1, and
				the state of reaching the last node from the second node having the value 0 is different

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int shortestPath(vector<vector<int>>&grid, int k){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int vis[m+1][n+1];
        for (int i=0; i<=m; ++i){
            for (int j=0; j<=n; ++j){
                vis[i][j]=INT_MAX;
            }
        }
        queue<vector<int>>q;
        q.push({0, 0, 0});
        vis[0][0]=true;
        int dist=0;
        while (!q.empty()){
            int qSz=q.size();
            while (qSz--){
                vector<int>curr=q.front();
                if (curr[0]==m-1&&curr[1]==n-1){
                    cout<<dist;
                    return dist;
                }
                q.pop();
                for (auto d: dir){
                    int newX=curr[0]+d[0];
                    int newY=curr[1]+d[1];
                    if (newX>=0&&newX<m&&newY>=0&&newY<n){
                        int newK=curr[2]+grid[newX][newY];
                        if (newK>k){
                            continue;
                        }
                        if (vis[newX][newY]<=newK){
                            continue;
                        }
                        vis[newX][newY]=newK;
                        q.push({newX, newY, newK});
                    }
                }
            }
            dist++;
        }
        return 1;
    }
};

int main(){
    Solution obj;
    vector<vector<int>>grid={{0,0,0}, {1,1,0}, {0,0,0}, {0,1,1}, {0,0,0}};
    obj.shortestPath(grid, 1);
}

/*

-------

class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        queue = collections.deque([(0, 0, k)])
        seen = set()
        seen.add((0, 0, k))
        ans = 0
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while queue:
            queueLen = len(queue)
            for _ in range(queueLen):
                i, j, k = queue.popleft()
                if i == m - 1 and j == n - 1:
                    return ans
                for d in directions:
                    newi = i + d[0]
                    newj = j + d[1]
                    if 0 <= newi < m and 0 <= newj < n:
                        if grid[newi][newj] == 1:
                            if k > 0 and (newi, newj, k - 1) not in seen:
                                queue.append((newi, newj, k - 1))
                                seen.add((newi, newj, k - 1))
                        else:
                            if (newi, newj, k) not in seen:
                                queue.append((newi, newj, k))
                                seen.add((newi, newj, k))
            ans += 1
        return -1

-------

class Solution {
	private static final int[][] DIRECTIONS = { { 1, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } };
	public int shortestPath(int[][] grid, int k) {
		int m = grid.length, n = grid[0].length;
		Deque<int[]> queue = new LinkedList<>();
		queue.offerLast(new int[] { 0, 0, 0 });
		int[][] visited = new int[m][n];
		for (int[] i : visited)
			Arrays.fill(i, Integer.MAX_VALUE);
		visited[0][0] = 0;
		int dist = 0;
		while (!queue.isEmpty()) {
			int size = queue.size();
			while (size-- > 0) {
				int[] curr = queue.poll();
				if (curr[0] == m - 1 && curr[1] == n - 1)
					return dist;
				for (int[] dir : DIRECTIONS) {
					int newX = curr[0] + dir[0];
					int newY = curr[1] + dir[1];
					// 1) continue if out of bound
					if (newX < 0 || newY < 0 || newX >= m || newY >= n)
						continue;
					// 2) continue if out of elimination
					int newK = curr[2] + grid[newX][newY];
					if (newK > k)
						continue;
					// 3) continue if we have more optimal result
					if (visited[newX][newY] <= newK)
						continue;
					visited[newX][newY] = newK;
					queue.offerLast(new int[] { newX, newY, newK });
				}
			}
			dist++;
		}
		return -1;
	}
}

-------

The number of steps to the target is rows+cols-2

The number of obstacles is 1 less, since the last cell must be empty

0 0 0 0
1 0 0 0
1 1 1 0

rows=3, cols=4, steps = (2 down + 3 right) = 5
which is equal to rows-cols-2 = 5 steps
Number of obstacles: steps-1 = 4 obstacles 

We can take a shortcut anytime when we know that k can cover all possible obstacles:

	if(obstacles<=k) return minSteps;                   // on start

	if(stepsToTarget-1<=kk) return steps+stepsToTarget; // on each step

-------

On the optimal way, we might use up some k so we can jump only from the point closest to the target. 

	Otherwise, we might stop on sub-optimal solution without used k. 

	Example:

		[[0,1,1,1,1,1,0,0,0,0,0,1,1,0],[0,0,0,0,0,0,0,1,1,1,0,0,0,0]]
		4

		0 1 2 3 4 5 6 7 8 9 10 11 12 13
		-------------------------------
		0 1 1 1 1 1 0 0 0 0 *  1  1  0  <-- at * we are at suboptimal path, steps=11, k=4,
		0 0 0 0 0 0 0 1 1 1 0  0  0  0      stepToTarget=4, so we would take a jump with 16
		                                 	while optimal is 14

		// To avoid this, jump only from the point closest to the target

			if(stepsToTarget-1<=kk && stepsToTarget==minSteps-1) 
				return steps+stepsToTarget; // on each step

-------

Since we need the minimal number of steps, we should use BFS.

Note, that we need to track k when maintaining visited since we might use up all k too early. 

E.g. the shortest path to (0,5) will eat up all k's:

0 1 0 0 0 1
0 0 0 1 1 0

Test:
[[0,1,0,0,0,1],[0,0,0,1,1,0]]
1

On the other hand, there is no point in checking the same cell with less (and worse) k than previously.

	Otherwise, we would go from (0,0,k=1) to (1,0,k=0) and then back to (0,0,k=0).

	Optimization: track k for each cell and never reduce it. Start with negative:

		vector<int> visited(rows*cols, -1); // position -> k remaining

-------

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int k)
    {
        int rows = grid.size(), cols = grid[0].size();
        int minSteps = max(0, rows + cols - 2), obstacles = minSteps - 1, minStepsNextRound = minSteps;
        if (obstacles <= k)
            return minSteps; // take a shortcut if we can afford it

        vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        list<vector<int>> togo;
        togo.push_back({0, 0, k});            // BFS: {row, col, remaining k}
        vector<int> visited(rows * cols, -1); // position -> k remaining
        visited[0] = k;
        int steps = 0;

        while (togo.size())
        {
            steps++;
            minSteps = minStepsNextRound;
            for (int sz = togo.size(); sz > 0; sz--)
            {
                int r = togo.front()[0], c = togo.front()[1], k = togo.front()[2];
                togo.pop_front();
                for (auto &d : dirs)
                {
                    int rr = r + d[0], cc = c + d[1];
                    if (rr < 0 || rr >= rows || cc < 0 || cc >= cols)
                        continue;
                    int kk = k - grid[rr][cc];
                    if (visited[rr * cols + cc] >= kk)
                        continue; // have been here passing less obstacles

                    // maybe we can take a shortcut and go straight to the goal
                    // but jump only from the point closest to the target
                    int stepsToTarget = rows - rr - 1 + cols - cc - 1;
                    if (stepsToTarget - 1 <= kk && stepsToTarget == minSteps - 1)
                        return steps + stepsToTarget;
                    togo.push_back({rr, cc, kk});
                    visited[rr * cols + cc] = kk;
                    minStepsNextRound = min(minStepsNextRound, stepsToTarget);
                }
            }
        }
        return -1;
    }
};
*/