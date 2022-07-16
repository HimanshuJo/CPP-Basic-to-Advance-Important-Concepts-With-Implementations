// 2290. Minimum Obstacle Removal to Reach Corner
/*
You are given a 0-indexed 2D integer array grid of size m x n. 
Each cell has one of two values:

0 represents an empty cell,
1 represents an obstacle that may be removed.
You can move up, down, left, or right from and to an empty cell.

Return the minimum number of obstacles to remove so you can move from the upper left corner 
(0, 0) to the lower right corner (m - 1, n - 1).

Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
Output: 2
Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
It can be shown that we need to remove at least 2 obstacles, so we return 2.
Note that there may be other ways to remove 2 obstacles to create a path.

Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]]
Output: 0
Explanation: We can move from (0, 0) to (2, 4) without removing any obstacles, so we return 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10^5
2 <= m * n <= 10^5
grid[i][j] is either 0 or 1.
grid[0][0] == grid[m - 1][n - 1] == 0
*/

/*
TLE: 54 / 54 test cases passed, but took too long.

class Solution {
public:
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        vector<vector<int>>dist(rws, vector<int>(cols, 0));
        int totObs;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]==1) totObs++;
                dist[i][j]=INT_MAX;
            }
        }
        vector<vector<int>>dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        pq.push({0, 0, 0});
        dist[0][0]=1;
        int ans=0;
        bool flag=false;
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                int nwd=pq.top()[0], currx=pq.top()[1], curry=pq.top()[2];
                if(currx==rws-1&&curry==cols-1){
                    flag=true;
                    break;
                }
                pq.pop();
                for(auto &vals: dir){
                    int nwx=vals[0]+currx, nwy=vals[1]+curry;
                    if(nwx<=rws-1&&nwy<=cols-1&&nwx>=0&&nwy>=0){
                        int nwobs=nwd+grid[nwx][nwy];
                        if(nwobs>totObs) continue;
                        if(dist[nwx][nwy]<=nwobs) continue;
                        dist[nwx][nwy]=nwobs;
                        pq.push({nwobs, nwx, nwy});
                    }
                }
            }
            if(flag) break;
        }
        return dist[rws-1][cols-1];
    }
};
*/

// TC: (O(V+E)logN)

class Solution {
public:
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size();
        vector<vector<int>>dist(rws, vector<int>(cols, INT_MAX));
        int totObs;
        vector<vector<int>>dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        pq.push({0, 0, 0});
        dist[0][0]=1;
        int ans=0;
        bool flag=false;
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                int nwd=pq.top()[0], currx=pq.top()[1], curry=pq.top()[2];
                if(currx==rws-1&&curry==cols-1){
                    flag=true;
                    break;
                }
                pq.pop();
                for(auto &vals: dir){
                    int nwx=vals[0]+currx, nwy=vals[1]+curry;
                    if(nwx<=rws-1&&nwy<=cols-1&&nwx>=0&&nwy>=0){
                        int wt=0;
                        if(grid[nwx][nwy]==1){
                            wt=1;
                        }
                        if(nwd+wt<dist[nwx][nwy]){
                            dist[nwx][nwy]=nwd+wt;
                            pq.push({dist[nwx][nwy], nwx, nwy});
                        }
                    }
                }
            }
            if(flag) break;
        }
        return dist[rws-1][cols-1];
    }
};