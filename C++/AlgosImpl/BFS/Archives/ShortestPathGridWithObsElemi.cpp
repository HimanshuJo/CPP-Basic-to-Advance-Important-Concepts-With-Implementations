/*
Given a m * n grid, where each cell is either 0 (empty) or 1 (obstacle). 
In one step, you can move up, down, left or right from and to an empty cell.

Return the minimum number of steps to walk from the upper left corner (0, 0) to the 
lower right corner (m-1, n-1) given that you can eliminate at most k obstacles. 
If it is not possible to find such walk return -1.

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