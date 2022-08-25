// 2132. Stamping the Grid
/*
You are given an m x n binary matrix grid where each cell is either 0 (empty) or 1 (occupied).

You are then given stamps of size stampHeight x stampWidth. We want to fit the stamps such that they follow the given restrictions and requirements:

Cover all the empty cells.
Do not cover any of the occupied cells.
We can put as many stamps as we want.
Stamps can overlap with each other.
Stamps are not allowed to be rotated.
Stamps must stay completely inside the grid.
Return true if it is possible to fit the stamps while following the given restrictions and requirements. Otherwise, return false.

Input: grid = [[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0],[1,0,0,0]], stampHeight = 4, stampWidth = 3
Output: true
Explanation: We have two overlapping stamps (labeled 1 and 2 in the image) that are able to cover all the empty cells.
*/

class Solution {
public:

	void calBlckVec(vector<vector<int>>&rngBlckPrefSum, int rws, int cols){
		for(int i=0; i<rws; ++i){
			for(int j=0; j<cols; ++j){
				rngBlckPrefSum[i+1][j+1]+=rngBlckPrefSum[i+1][j]+rngBlckPrefSum[i][j+1]-rngBlckPrefSum[i][j];
			}
		}
	}

	void calDpVec(vector<vector<int>>&rngDpPrefSum, int rws, int cols){
		for(int i=0; i<rws; ++i){
			for(int j=0; j<cols; ++j){
				rngDpPrefSum[i+1][j+1]+=rngDpPrefSum[i+1][j]+rngDpPrefSum[i][j+1]-rngDpPrefSum[i][j];
			}
		}
	}

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int rws=grid.size(), cols=grid[0].size();
        vector<vector<int>>rngBlckPrefSum(rws+1, vector<int>(cols+1, 0));
        vector<vector<int>>rngDpPrefSum(rws+1, vector<int>(cols+1, 0));
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(grid[i][j]){
                    rngBlckPrefSum[i+1][j+1]=1;
                }
            }
        }
        calBlckVec(rngBlckPrefSum, rws, cols);
        for(int i=0; i<rws; ++i){
			for(int j=0; j<cols; ++j){
				if(grid[i][j]==0&&(i+stampHeight<=rws)&&(j+stampWidth<=cols)){
					int x=i+stampHeight, y=j+stampWidth;
					int sum=rngBlckPrefSum[x][y]-rngBlckPrefSum[i][y]-rngBlckPrefSum[x][j]+rngBlckPrefSum[i][j];
					if(sum==0){
						rngDpPrefSum[i+1][j+1]=1;
					}
				}
			}
		}
		calDpVec(rngDpPrefSum, rws, cols);
		for(int i=0; i<rws; ++i){
			for(int j=0; j<cols; ++j){
				if(grid[i][j]==0){
					int x=i+1, y=j+1;
					int nextI=max(1, x-stampHeight+1), nextJ=max(1, y-stampWidth+1);
					int sum=rngDpPrefSum[x][y]-rngDpPrefSum[nextI-1][y]-rngDpPrefSum[x][nextJ-1]+rngDpPrefSum[nextI-1][nextJ-1];
					if(sum==0) return false;
				}
			}
		}
		return true;
    }
};

