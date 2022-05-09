//2245. Maximum Trailing Zeros in a Cornered Path
/*
You are given a 2D integer array grid of size m x n, where each cell contains a positive integer.

A cornered path is defined as a set of adjacent cells with at most one turn. 
More specifically, the path should exclusively move either horizontally or 
vertically up to the turn (if there is one), without returning to a previously visited cell. 
After the turn, the path will then move exclusively in the alternate direction: 
move vertically if it moved horizontally, and vice versa, also without returning to a previously visited cell.

The product of a path is defined as the product of all the values in the path.

Return the maximum number of trailing zeros in the product of a cornered path found in grid.

Note:

Horizontal movement means moving in either the left or right direction.
Vertical movement means moving in either the up or down direction.

Input: grid = [[23,17,15,3,20],[8,1,20,27,11],[9,4,6,2,21],[40,9,1,10,6],[22,7,4,5,3]]
Output: 3
Explanation: The grid on the left shows a valid cornered path.
It has a product of 15 * 20 * 6 * 1 * 10 = 18000 which has 3 trailing zeros.
It can be shown that this is the maximum trailing zeros in the product of a cornered path.

The grid in the middle is not a cornered path as it has more than one turn.
The grid on the right is not a cornered path as it requires a return to a previously visited cell.

Input: grid = [[4,3,2],[7,6,1],[8,8,8]]
Output: 0
Explanation: The grid is shown in the figure above.
There are no cornered paths in the grid that result in a product with a trailing zero.

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10^5
1 <= m * n <= 10^5
1 <= grid[i][j] <= 1000
*/

class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int rws=grid.size(), cols=grid[0].size(), res=0;
        vector<vector<int>>vec2(rws, vector<int>(cols, 0));
        vector<vector<int>>vec5(rws, vector<int>(cols, 0));
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                int temp=grid[i][j];
                while(temp%2==0){
                    temp/=2;
                    vec2[i][j]++;
                }
                while(temp%5==0){
                    temp/=5;
                    vec5[i][j]++;
                }
            }
        }
        vector<vector<int>>vec2HorizontalSm(rws, vector<int>(cols, 0));
        vector<vector<int>>vec5HorizontalSm(rws, vector<int>(cols, 0));
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(j==0){
                    vec2HorizontalSm[i][j]=vec2[i][j];
                    vec5HorizontalSm[i][j]=vec5[i][j];
                } else{
                    vec2HorizontalSm[i][j]=vec2HorizontalSm[i][j-1]+vec2[i][j];
                    vec5HorizontalSm[i][j]=vec5HorizontalSm[i][j-1]+vec5[i][j];
                }
            }
        }
        vector<vector<int>>vec2VerticalSm(rws, vector<int>(cols, 0));
        vector<vector<int>>vec5VerticalSm(rws, vector<int>(cols, 0));
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                if(i==0){
                    vec2VerticalSm[i][j]=vec2[i][j];
                    vec5VerticalSm[i][j]=vec5[i][j];
                } else{
                    vec2VerticalSm[i][j]=vec2VerticalSm[i-1][j]+vec2[i][j];
                    vec5VerticalSm[i][j]=vec5VerticalSm[i-1][j]+vec5[i][j];
                }
            }
        }
        for(int i=0; i<rws; ++i){
            for(int j=0; j<cols; ++j){
                int vec2H1=vec2HorizontalSm[i][j];
                int vec2H2=vec2HorizontalSm[i][vec2[0].size()-1]-vec2HorizontalSm[i][j]+vec2[i][j];
                int vec2V1=vec2VerticalSm[i][j];
                int vec2V2=vec2VerticalSm[vec2.size()-1][j]-vec2VerticalSm[i][j]+vec2[i][j];
                int vec5H1=vec5HorizontalSm[i][j];
                int vec5H2=vec5HorizontalSm[i][vec5[0].size()-1]-vec5HorizontalSm[i][j]+vec5[i][j];
                int vec5V1=vec5VerticalSm[i][j];
                int vec5V2=vec5VerticalSm[vec5.size()-1][j]-vec5VerticalSm[i][j]+vec5[i][j];
                int temp=max(min(vec2H1+vec2V1-vec2[i][j], vec5H1+vec5V1-vec5[i][j]),
                             min(vec2H1+vec2V2-vec2[i][j], vec5H1+vec5V2-vec5[i][j]));
                temp=max(temp, min(vec2H2+vec2V1-vec2[i][j], vec5H2+vec5V1-vec5[i][j]));
                temp=max(temp, min(vec2H2+vec2V2-vec2[i][j], vec5H2+vec5V2-vec5[i][j]));
                res=max(res, temp);
            }
        }
        return res;
    }
};