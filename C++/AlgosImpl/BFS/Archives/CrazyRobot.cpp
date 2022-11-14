// E. Crazy Robot
/*
There is a grid, consisting of n rows and m columns. Each cell of the grid is either free or blocked. 
One of the free cells contains a lab. All the cells beyond the borders of the grid are also blocked.

A crazy robot has escaped from this lab. It is currently in some free cell of the grid. 
You can send one of the following commands to the robot: "move right", "move down", "move left" or "move up". 
Each command means moving to a neighboring cell in the corresponding direction.

However, as the robot is crazy, it will do anything except following the command. Upon receiving a command, 
it will choose a direction such that it differs from the one in command and the cell in that direction is not blocked. 
If there is such a direction, then it will move to a neighboring cell in that direction. Otherwise, it will do nothing.

We want to get the robot to the lab to get it fixed. For each free cell, determine if the robot can be forced to reach the 
lab starting in this cell. That is, after each step of the robot a command can be sent to a robot such that no matter 
what different directions the robot chooses, it will end up in a lab.

Input
The first line contains a single integer t (1≤t≤1000) — the number of testcases.

The first line of each testcase contains two integers n and m (1≤n,m≤10^6; n⋅m≤10^6) — 
the number of rows and the number of columns in the grid.

The i-th of the next n lines provides a description of the i-th row of the grid. It consists of m elements of one of three types:

'.' — the cell is free;
'#' — the cell is blocked;
'L' — the cell contains a lab.
The grid contains exactly one lab. The sum of n⋅m over all testcases doesn't exceed 10^6.

Output
For each testcase find the free cells that the robot can be forced to reach the lab from. 
Given the grid, replace the free cells (marked with a dot) with a plus sign ('+') for the 
cells that the robot can be forced to reach the lab from. Print the resulting grid.

Example
input
4
3 3
...
.L.
...
4 5
#....
..##L
...#.
.....
1 1
L
1 9
....L..#.

output
...
.L.
...
#++++
..##L
...#+
...++
L
++++L++#.

Note
In the first testcase there is no free cell that the robot can be forced to reach the lab from. 
Consider a corner cell. Given any direction, it will move to a neighboring border grid that's not a corner. 
Now consider a non-corner free cell. No matter what direction you send to the robot, 
it can choose a different direction such that it ends up in a corner.

In the last testcase, you can keep sending the command that is opposite to the direction to the 
lab and the robot will have no choice other than move towards the lab.
*/

/*
Solution:

One way to think about this problem is in game theory terms.

Imagine a following game. Two players alternate moves. 
The first players chooses a direction. 
The second player chooses a different direction and moves a robot there. 
The game ends when the robot reaches the lab, and the first player wins. 

Otherwise, it's a draw. What's the outcome of the game if both players play optimally 
(as in the first player tries to win, the second player tries to draw)?

Does it sound easier? Well, it sure does if you ever dealt with solving games on arbitrary graphs. 
The state of the game is a pair (cell,direction). 
If a direction is not chosen (denote it with −1), it's the first player's move. Otherwise, it's the second player's move.

You can even implement it as is. Or you can adjust a part of this algorithm for this particular problem.

Initially, all the states are drawing, only the state (lab,−1) is winning. 

What we basically need is a way to determine:

	if a state is winning or not. 

	From game theory, we can tell that the state is winning if there's a transition from it to a losing state. 

	The state is losing if all the transitions from it lead to winning states. 

	So (cell,−1) is winning if any of (cell,direction≠−1) are losing.

Promote that one step further. The state is winning if there exists such a direction that all 
neighboring free cells except in this direction are winning states. 

Rephrase it. The state is winning if it has at least one winning state neighbor and no more than 
one non-winning state neighbor.

Let's store the number of non-winning neighboring states for each cell. 
Initially, it's the number of neighboring free cells. 

If some state becomes marked as winning, decrease the value for each of its neighbors by 1. 
If some state's value reaches 0 or 1 after this operation, mark it as winning.

Since what this does is basically a traversal of a grid, this can be done with a DFS/BFS, starting from the lab.

Overall complexity: O(n*m) per testcase.
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Cell{
	int x, y;
};

int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<string>s(n);
		int lx=-1, ly=-1;
		for(int i=0; i<n; ++i){
			cin>>s[i];
			for(int j=0; j<m; ++j){
				if(s[i][j]=='L'){
					lx=i, ly=j;
				}
			}
		}
		auto in=[&](int x, int y){
			return 0<=x&&x<n&&0<=y&&y<m;
		};
		vector<vector<int>>d(n, vector<int>(m, 0));
		for(int x=0; x<n; ++x){
			for(int y=0; y<m; ++y){
				if(s[x][y]=='.'){
					for(int i=0; i<4; ++i){
						int nx=x+dx[i];
						int ny=y+dy[i];
						d[x][y]+=in(nx, ny)&&s[nx][ny]!='#';
					}
				}
			}
		}
		queue<Cell>q;
		vector<vector<char>>seen(n, vector<char>(m, 0));
		q.push({lx, ly});
		seen[lx][ly]=true;
		while(!q.empty()){
			int x=q.front().x;
			int y=q.front().y;
			q.pop();
			for(int i=0; i<4; ++i){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(!in(nx, ny)||s[nx][ny]=='#'||seen[nx][ny]) continue;
				--d[nx][ny];
				if(d[nx][ny]<=1){
					seen[nx][ny]=true;
					q.push({nx, ny});
				}
			}
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(s[i][j]=='.'&&seen[i][j]){
					s[i][j]='+';
				}
			}
			cout<<s[i]<<"\n";
		}
	}
}
