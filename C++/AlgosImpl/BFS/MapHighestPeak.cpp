// 1765. Map of Highest Peak
/*
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. 

A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. 
If there are multiple solutions, return any of them.

Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.

Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.
*/

class Solution {
public:
    
    bool isValid(const int x, const int y, const int rws, const int cols, const vector<vector<int>>&height){
        return (x>=0&&y>=0&&x<rws&&y<cols&&height[x][y]==-1);
    }
    
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rws=isWater.size();
        int cols=isWater[0].size();
        vector<vector<int>>res(rws, vector<int>(cols, 0));
        vector<vector<int>>dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>>q;
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(isWater[i][j]==1){
                    res[i][j]=0;
                    q.push({i, j});
                } else{
                    res[i][j]=-1;
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int, int>curcord=q.front();
                q.pop();
                for(auto &vals: dir){
                    int nwx=vals[0]+curcord.first, nwy=vals[1]+curcord.second;
                    if(isValid(nwx, nwy, rws, cols, res)){
                        res[nwx][nwy]=res[curcord.first][curcord.second]+1;
                        q.push({nwx, nwy});
                    }
                }
            }
        }
        return res;
    }
};