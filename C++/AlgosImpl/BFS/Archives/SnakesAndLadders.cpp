// 909. Snakes and Ladders
/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style
starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n^2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations,
regardless of the size of the board.

If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n^2.

A board square on row r and column c has a snake or ladder if board[r][c] != -1.
The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have a snake or ladder.

Note that you only take a snake or ladder at most once per move.
If the destination to a snake or ladder is the start of another snake or ladder,
you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move,
your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.

Input: board = [[-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,35,-1,-1,13,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
*/

/*
The trick is to find the coordinate of the square with number s.
If you can find the coordinate of given square with number s then it's just a plain vanilla bfs.
Since rows are starting from bottom, just dividing 's' by 'n' won't work. So, to get actual rows from bottom,
we need to subtract it from 'n-1' (-1 because of '0' based indexing). Hence,

row_from_top = (s-1)/n;
row_from_bottom = n-1-row_from_top
				= n-1-(s-1)/n;
(s-1) because of '0' based indexing and take care of corner cases when s%n == 0;
to understand it better, please dry run following case.
e.g n=6,s=24
	row_from_top = (24-1)/6 = 3
	row_from_bottom = 6-1-3 = 2;

	n=6,s=18
	row_from_top = (18-1)/6 = 2
	row_from_bottom = 6-1-2 = 3;

	n=5,s=17
	row_from_top = (17-1)/5 = 3
	row_from_bottom = 5-1-3 = 1;

-------

Getting column is bit tricky here because of boustrophedonically ordering.
In normal ordering: col = (s-1)%n
But because of boustrophedonically ordering, the column number alternates from
left to right and from right to left.
If you observe carefully
when (n and row_from_bottom are even) or (n and row_from_bottom are odd),
the column number starts from right to left;

Hence, to get actual column number we need to subtract it from n-1. i.e

col = (s-1)%n;
if((n%2==0 && row_from_bottom%2==0)||(n%2==1 && row_from_bottom%2==1))
	col = n-1-col;
e.g n=6,s=24
	col = (24-1)%6 = 5
	row_from_top = (24-1)/6 = 3
	row_from_bottom = 6-1-3 = 2;
	since, n & row_from_bottom both are even,
	col = 6-1-col
		= 0

	n=6,s=18
	row_from_top = (18-1)/6 = 2
	row_from_bottom = 6-1-2 = 3;
	col = (18-1)%6 = 5;

	n=5,s=17
	row_from_top = (17-1)/5 = 3
	row_from_bottom, = 5-1-3 = 1;
	col = (17-1)%5 = 1
	since n & row_from_bottom are odd,
	col = n-1-col
		= 5-1-1
		= 3
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void getNwCoordinates(int n, int s, int &rw, int &col){
    /*
        Standard row is (s-1)/n which is the row from the top
        However, in the Boustrophedon style rows are starting from the bottom
        Therefore, to get the row from the bottom:

            (n-1)-(s-1)/n
    */
    rw=(n-1)-(s-1)/n;
    col=(s-1)%n;
    /*
        If board size is even and curr row is also even
                OR
        If board size is odd and curr row is also odd
        then col is (n-1) - (standardCol from earlier calculation)
    */
    if((n%2==0&&rw%2==0)||(n%2==1&&rw%2==1)){
        col=n-1-col;
    }
}

class Solution{
    public:
    int snakesAndLadders(vector<vector<int>>&board){
        int n=board.size();
        vector<bool>seen(n*n+1, false);
        seen[1]=true;
        queue<pair<int, int>>q;
        q.push({1, 0});
        while(!q.empty()){
            pair<int, int>curr=q.front();
            q.pop();
            int rw, col;
            int s=curr.first, dist=curr.second;
            if(s==n*n){
                return dist;
            }
            for(int i=1; s+i<=n*n&&i<=6; ++i){
                getNwCoordinates(n, s+i, rw, col);
                int snw=board[rw][col]==-1?s+i:board[rw][col];
                if(seen[snw]==false){
                    seen[snw]=true;
                    q.push({snw, dist+1});
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>>board{{-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,35,-1,-1,13,-1},
                             {-1,-1,-1,-1,-1,-1},
                             {-1,15,-1,-1,-1,-1}};
    Solution obj;
    int ans=obj.snakesAndLadders(board);
    cout<<ans<<endl;
}