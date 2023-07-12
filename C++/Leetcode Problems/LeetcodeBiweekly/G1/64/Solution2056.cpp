// 2056. Number of Valid Move Combinations On Chessboard
/*
There is an 8 x 8 chessboard containing n pieces (rooks, queens, or bishops). 
You are given a string array pieces of length n, where pieces[i] describes the 
type (rook, queen, or bishop) of the ith piece. 

In addition, you are given a 2D integer array positions also of length n, where 
positions[i] = [ri, ci] indicates that the ith piece is currently at the 1-based coordinate 
(ri, ci) on the chessboard.

When making a move for a piece, you choose a destination square that the piece will 
travel toward and stop on.

A rook can only travel horizontally or vertically from (r, c) to the direction of 
(r+1, c), (r-1, c), (r, c+1), or (r, c-1).

A queen can only travel horizontally, vertically, or diagonally from (r, c) to 
the direction of (r+1, c), (r-1, c), (r, c+1), (r, c-1), (r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).

A bishop can only travel diagonally from (r, c) to the direction of 
(r+1, c+1), (r+1, c-1), (r-1, c+1), (r-1, c-1).

You must make a move for every piece on the board simultaneously. 
A move combination consists of all the moves performed on all the given pieces. 
Every second, each piece will instantaneously travel one square towards their destination if 
they are not already at it. All pieces start traveling at the 0th second. 

A move combination is invalid if, at a given time, two or more pieces occupy the same square.

Return the number of valid move combinations.

Notes:

No two pieces will start in the same square.

You may choose the square a piece is already on as its destination.

If two pieces are directly adjacent to each other, it is valid for them to move 
past each other and swap positions in one second.

Input: pieces = ["rook"], positions = [[1,1]]
Output: 15
Explanation: The image above shows the possible squares the piece can move to.

Input: pieces = ["queen"], positions = [[1,1]]
Output: 22
Explanation: The image above shows the possible squares the piece can move to.

Input: pieces = ["bishop"], positions = [[4,3]]
Output: 12
Explanation: The image above shows the possible squares the piece can move to.

Constraints:

n == pieces.length
n == positions.length
1 <= n <= 4
pieces only contains the strings "rook", "queen", and "bishop".
There will be at most one queen on the chessboard.
1 <= xi, yi <= 8
Each positions[i] is distinct.
*/

class Solution {
public:
    
    int dfs2(vector<vector<int>>&positions, int move){
        int chessBoard[8][8];
        memset(chessBoard, 0, sizeof(chessBoard));
        bool isVal=false;
        for(auto &pos: positions){
            int x=pos[0]+pos[4]*pos[2], y=pos[1]+pos[4]*pos[3];
            if(pos[4]>move){
                isVal=true;
                x=pos[0]+move*pos[2], y=pos[1]+move*pos[3];
            }
            if(x<0||x>7||y<0||y>7) return 0;
            chessBoard[x][y]++;
        }
        for(int i=0; i<8; ++i){
            for(int j=0; j<8; ++j){
                if(chessBoard[i][j]>1){
                    return 0;
                }
            }
        }
        int ret=0;
        if(!isVal) ret=1;
        else ret=dfs2(positions, move+1);
        return ret;
    }
    
    int dfs(int idx, vector<string>&pieces, vector<vector<int>>&positions){
        if(idx>=pieces.size()) return dfs2(positions, 0);
        int ret=0;
        positions[idx].push_back(0); positions[idx].push_back(0); positions[idx].push_back(0);
        ret+=dfs(idx+1, pieces, positions);
        positions[idx].pop_back(), positions[idx].pop_back(), positions[idx].pop_back();
        if(pieces[idx]=="rook"||pieces[idx]=="queen"){
            for(int x=-1; x<=1; ++x){
                if(x!=0){
                    for(int moves=1; moves<8; ++moves){
                        int dx=positions[idx][0]+moves*x;
                        if(dx>=0&&dx<8){
                            positions[idx].push_back(x);
                            positions[idx].push_back(0);
                            positions[idx].push_back(moves);
                            ret+=dfs(idx+1, pieces, positions);
                            positions[idx].pop_back(), positions[idx].pop_back(), positions[idx].pop_back();
                        }
                    }
                }
            }
            for(int y=-1; y<=1; ++y){
                if(y!=0){
                    for(int moves=1; moves<8; ++moves){
                        int dy=positions[idx][1]+moves*y;
                        if(dy>=0&&dy<8){
                            positions[idx].push_back(0);
                            positions[idx].push_back(y);
                            positions[idx].push_back(moves);
                            ret+=dfs(idx+1, pieces, positions);
                            positions[idx].pop_back(), positions[idx].pop_back(), positions[idx].pop_back();
                        }
                    }
                }
            } 
        }
        if(pieces[idx]=="bishop"||pieces[idx]=="queen"){
            for(int x=-1; x<=1; ++x){
                if(x!=0){
                    for(int y=-1; y<=1; ++y){
                        if(y!=0){
                            for(int moves=1; moves<8; ++moves){
                                int dx=positions[idx][0]+moves*x;
                                int dy=positions[idx][1]+moves*y;
                                if(dx>=0&&dx<8&&dy>=0&&dy<8){
                                    positions[idx].push_back(x);
                                    positions[idx].push_back(y);
                                    positions[idx].push_back(moves);
                                    ret+=dfs(idx+1, pieces, positions);
                                    positions[idx].pop_back(), positions[idx].pop_back(), positions[idx].pop_back();
                                }
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        for(auto &pos: positions){
            pos[0]--, pos[1]--;
        }
        return dfs(0, pieces, positions);
    }
};