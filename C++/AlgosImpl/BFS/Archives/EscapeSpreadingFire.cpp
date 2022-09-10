// 2258. Escape the Spreading Fire
/*
You are given a 0-indexed 2D integer array grid of size m x n which represents a field. 
Each cell has one of three values:

0 represents grass,
1 represents fire,
2 represents a wall that you and fire cannot pass through.
You are situated in the top-left cell, (0, 0), and you want to travel to the 
safehouse at the bottom-right cell, (m - 1, n - 1). 

Every minute, you may move to an adjacent grass cell. After your move, every fire cell 
will spread to all adjacent cells that are not walls.

Return the maximum number of minutes that you can stay in your initial position 
before moving while still safely reaching the safehouse. 

If this is impossible, return -1. If you can always reach the safehouse regardless 
of the minutes stayed, return 10^9.

Note that even if the fire spreads to the safehouse immediately after you 
have reached it, it will be counted as safely reaching the safehouse.

A cell is adjacent to another cell if the former is directly 
north, east, south, or west of the latter (i.e., their sides are touching).

Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
Output: 3
Explanation: The figure above shows the scenario where you stay in the initial position for 3 minutes.
You will still be able to safely reach the safehouse.
Staying for more than 3 minutes will not allow you to safely reach the safehouse.

Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
Output: -1
Explanation: The figure above shows the scenario where you immediately move towards the safehouse.
Fire will spread to any cell you move towards and it is impossible to safely reach the safehouse.
Thus, -1 is returned.

Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
Output: 1000000000
Explanation: The figure above shows the initial grid.
Notice that the fire is contained by walls and you will always be able to safely reach the safehouse.
Thus, 109 is returned.

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 300
4 <= m * n <= 2 * 10^4
grid[i][j] is either 0, 1, or 2.
grid[0][0] == grid[m - 1][n - 1] == 0
*/

#define INF 0x3f3f3f3f

int n, m;
int fireTime[300][300];
int dis[300][300];

int fx[4]={-1, 0, 1, 0};
int fy[4]={0, -1, 0, 1};

int inValid(int x, int y, vector<vector<int>>&grid){
    return (x<0||y<0||x>=n||y>=m||grid[x][y]==2);
}

void bfs2(vector<vector<int>>&grid){
    queue<pair<int, int>>q;
    memset(fireTime, INF, sizeof(fireTime));
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(grid[i][j]==1){
                q.push({i, j});
                fireTime[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        pair<int, int>cur=q.front();
        q.pop();
        int x=cur.first, y=cur.second;
        for(int i=0; i<4; ++i){
            int nx=x+fx[i], ny=y+fy[i];
            if(inValid(nx, ny, grid)) continue;
            if(fireTime[nx][ny]>fireTime[x][y]+1){
                fireTime[nx][ny]=fireTime[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
}

int bfs1(int wait, vector<vector<int>>&grid){
    memset(dis, INF, sizeof(dis));
    queue<pair<int, int>>q;
    q.push({0, 0});
    dis[0][0]=wait;
    while(!q.empty()){
        pair<int, int>cur=q.front();
        q.pop();
        int x=cur.first, y=cur.second;
        for(int i=0; i<4; ++i){
            int nx=x+fx[i], ny=y+fy[i];
            if(inValid(nx, ny, grid)) continue;
            int newMin=min(dis[nx][ny], dis[x][y]+1);
            if(nx==n-1&&ny==m-1&&newMin<=fireTime[nx][ny]) return newMin;
            if(newMin>=fireTime[nx][ny]) continue;
            if(dis[nx][ny]>dis[x][y]+1){
                dis[nx][ny]=dis[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    return INF+1;
}

int binarySearch(vector<vector<int>>&grid){
    if(fireTime[n-1][m-1]==INF) return bfs1(0, grid)<INF?1e9:-1;
    int maxPossb=(n*m)+1;
    int low=0, high=maxPossb, maxWait=-1;
    while(low<=high){
        int mid=(low+(high-low)/2);
        if(bfs1(mid, grid)<=fireTime[n-1][m-1]){
            low=mid+1;
            maxWait=mid;
        } else{
            high=mid-1;
        }
    }
    return (maxWait==maxPossb?1e9:maxWait);
}

class Solution {
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        bfs2(grid);
        return binarySearch(grid);
    }
};