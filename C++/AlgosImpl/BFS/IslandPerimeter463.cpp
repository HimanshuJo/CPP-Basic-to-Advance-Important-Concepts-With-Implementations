// 463. Island Perimeter
/*
You are given row x col grid representing a map where grid[i][j] = 1 
represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally).
The grid is completely surrounded by water, and there is exactly one island 
(i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the 
water around the island. One cell is a square with side length 1.
The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
*/

class Solution {
public:
    
    bool isValid(const int newx, const int newy, const int rw, const int col, vector<vector<int>>&grid){
        return (newx>=0&&newx<rw&&newy>=0&&newy<col&&grid[newx][newy]==1);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int rw=grid.size(), col=grid[0].size();
        int seen[101][101];
        for(int i=0; i<rw; ++i)
            for(int j=0; j<col; ++j)
                seen[i][j]=-1;
        int dirs[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>>q;
        int ans=0;
        for(int i=0; i<rw; ++i)
            for(int j=0; j<col; ++j){
                if(grid[i][j]==1){
                    q.push({i, j});
                    seen[i][j]=1;
                    while(!q.empty()){
                        int sz=q.size();
                        while(sz--){
                            ans+=4;
                            pair<int, int>curr=q.front();
                            q.pop();
                            for(int x=0; x<4; ++x){
                                int newx=curr.first+dirs[x][0];
                                int newy=curr.second+dirs[x][1];
                                if(isValid(newx, newy, rw, col, grid)){
                                    ans-=1;
                                    if(!seen[newx][newy]){
                                        q.push({newx, newy});
                                        seen[newx][newy]=1;   
                                    }
                                }
                            }
                        }
                    }
                }
            }
        return ans;
    }
};