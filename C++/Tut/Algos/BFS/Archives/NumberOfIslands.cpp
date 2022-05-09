/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands.

An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. 

You may assume all four edges of the grid are all surrounded by water.

-------
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int numIslands(vector<vector<char>>grid){
        int n=grid.size();
        int wd=grid[0].size();
        vector<vector<int>>dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int vis[n+1][wd+1];
        for (int i=0; i<=n; ++i){
            for (int j=0; j<=wd; ++j){
                vis[i][j]=false;
            }
        }
        vector<int>res;
        queue<vector<int>>q;
        int ans=0;
        for (int i=0; i<n; ++i){
            for (int j=0; j<wd; ++j){
                if (grid[i][j]=='1'){
                    vector<int>start={i, j};
                    q.push(start);
                    vis[i][j]=1;
                    while (!q.empty()){
                        ans++;
                        int qLen=q.size();
                        for (int i=0; i<qLen; ++i){
                            vector<int>curr=q.front();
                            q.pop();
                            for (vector<int> d: dir){
                                int newX= curr[0]+d[0];
                                int newY=curr[1]+d[1];
                                if (newX>=0&&newX<n&&newY>=0&&newY<wd&&vis[newX][newY]!=1&&grid[newX][newY]=='1'){
                                    vector<int>next={newX, newY};
                                    q.push(next);
                                    vis[newX][newY]=1;
                                    grid[newX][newY]='0';
                                }
                            }
                        }
                    }
                    res.push_back(ans);
                }
            }
        }
        cout<<res.size();
        return res.size();
    }
};

int main(){
    Solution obj;
    vector<vector<char>>grid={{'0', '0' ,'0', '0'}, {'1', '1' ,'0', '0'}, {'1', '1' ,'0', '0'}, {'0', '0' ,'1', '1'}};
    obj.numIslands(grid);
}

/*

-------

class Solution_PriorityQueue {
	public int numIslands(char[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
		Set<ArrayList<Integer>> set = new HashSet<>();
		List<Integer> res = new ArrayList<>();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					PriorityQueue<List<Integer>> queue = new PriorityQueue<>((a, b) -> (a.get(0) - b.get(0)));
					ArrayList<Integer> list = new ArrayList<>();
					list.add(i);
					list.add(j);
					queue.offer(list);
					set.add(list);
					int count = 0;
					while (!queue.isEmpty()) {
						count++;
						List<Integer> temp = queue.poll();
						int curri = temp.get(0);
						int currj = temp.get(1);
						for (int[] d : directions) {
							int newi = curri + d[0];
							int newj = currj + d[1];
							if (0 <= newi && newi < m && 0 <= newj && newj < n) {
								if (grid[newi][newj] == '1') {
									grid[newi][newj] = '0';
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
					res.add(count);
				}
			}
		}
		return res.size();
	}
}

-------

// Linked List

public class Solution {
	public int numIslands(char[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		Set<int[]> seen = new HashSet<>();
		List<Integer> res = new ArrayList<>();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					LinkedList<int[]> queue = new LinkedList<>();
					queue.offer(new int[] { i, j });
					seen.add(new int[] { i, j });
					int count = 0;
					while (!queue.isEmpty()) {
						count++;
						int curri = queue.peek()[0];
						int currj = queue.peek()[1];
                        queue.pop();
						for (int[] d : directions) {
							int newi = curri + d[0];
							int newj = currj + d[1];
							if (0 <= newi && newi < m && 0 <= newj && newj < n) {
								if (grid[newi][newj] == '1') {
									grid[newi][newj] = '0';
									if (!seen.contains(new int[] { newi, newj })) {
										queue.offer(new int[] { newi, newj });
										seen.add(new int[] { newi, newj });
									}
								}
							}
						}
					}
					res.add(count);
				}
			}
		}
		return res.size();
	}
}

-------

// 12 ms
class Solution_NoHashSet {
	public int numIslands(char[][] grid) {
		int m = grid.length;
		int n = grid[0].length;
		int[][] directions = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		boolean[][] visited = new boolean[m][n];
		for (boolean[] arr : visited) {
			Arrays.fill(arr, false);
		}
		List<Integer> res = new ArrayList<>();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i][j])
					continue;
				if (grid[i][j] == '1') {
					LinkedList<int[]> queue = new LinkedList<>();
					queue.offer(new int[] { i, j });
					visited[i][j] = true;
					int count = 0;
					while (!queue.isEmpty()) {
						count++;
						int curri = queue.peek()[0];
						int currj = queue.peek()[1];
						queue.pop();
						for (int[] d : directions) {
							int newi = curri + d[0];
							int newj = currj + d[1];
							if (0 <= newi && newi < m && 0 <= newj && newj < n) {
								if (grid[newi][newj] == '1') {
									grid[newi][newj] = '0';
									if (!visited[newi][newj]) {
										queue.offer(new int[] { newi, newj });
										visited[newi][newj] = true;
									}
								}
							}
						}
					}
					res.add(count);
				}
			}
		}
		return res.size();
	}
}
*/