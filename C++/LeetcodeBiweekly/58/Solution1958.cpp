// 1958. Check if Move is Legal
/*
You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) 
on a game board. On the board, free cells are represented by '.', white cells are represented by 'W', 
and black cells are represented by 'B'.

Each move in this game consists of choosing a free cell and changing it to the color you are playing as 
(either white or black). However, a move is only legal if, after changing it, the cell becomes the endpoint 
of a good line (horizontal, vertical, or diagonal).

A good line is a line of three or more cells (including the endpoints) where the endpoints of the line 
are one color, and the remaining cells in the middle are the opposite color (no cells in the line are free). 
You can find examples for good lines in the figure below:

Given two integers rMove and cMove and a character color representing the color you are playing as (white or black), 
return true if changing cell (rMove, cMove) to color color is a legal move, or false if it is not legal.

Input: board = [[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."],
[".",".",".","W",".",".",".","."],[".",".",".","W",".",".",".","."],["W","B","B",".","W","W","W","B"],
[".",".",".","B",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","W",".",".",".","."]], 
rMove = 4, cMove = 3, color = "B"
Output: true
Explanation: '.', 'W', and 'B' are represented by the colors blue, white, and black respectively, and cell 
(rMove, cMove) is marked with an 'X'.
The two good lines with the chosen cell as an endpoint are annotated above with the red rectangles.
*/

class Solution {
public:
    
    bool isValid(vector<vector<char>>&board, int nwx, int nwy){
        int rws=board.size(), cols=board[0].size();
        return nwx>=0&&nwy>=0&&nwx<=rws-1&&nwy<=cols-1;
    }
    
    bool isLegal(vector<vector<char>>&board, int nwx, int nwy, char color){
        if(color=='W') return board[nwx][nwy]=='B';
        return board[nwx][nwy]=='W';
    }
    
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        vector<vector<int>>dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
        for(auto &vals: dir){
            int nwx=rMove+vals[0], nwy=cMove+vals[1];
            int count=0;
            while(isValid(board, nwx, nwy)&&isLegal(board, nwx, nwy, color)){
                nwx+=vals[0], nwy+=vals[1];
                count++;
            }
            if(isValid(board, nwx, nwy)&&count>0&&board[nwx][nwy]==color) return true;
        }
        return false;
    }
};