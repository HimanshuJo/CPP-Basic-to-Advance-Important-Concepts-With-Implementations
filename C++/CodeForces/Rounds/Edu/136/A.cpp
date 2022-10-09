// A. Immobile Knight
/*
There is a chess board of size n×m. The rows are numbered from 1 to n, the columns are numbered from 1 to m.

Let's call a cell isolated if a knight placed in that cell can't move to any other cell on 
the board. Recall that a chess knight moves two cells in one direction and one cell in a perpendicular direction:

Find any isolated cell on the board. If there are no such cells, print any cell on the board.

Input
The first line contains a single integer t (1≤t≤64) — the number of testcases.

The only line of each testcase contains two integers n and m (1≤n,m≤8) — the number of rows and columns of the board.

Output
For each testcase, print two integers — the row and the column of any isolated cell on the board. 
If there are no such cells, print any cell on the board.

Example
input
3
1 7
8 8
3 3

output
1 7
7 2
2 2

Note
In the first testcase, all cells are isolated. A knight can't move from any cell of the board to any other one. 
Thus, any cell on board is a correct answer.

In the second testcase, there are no isolated cells. On a normal chess board, a knight has at least two moves from any cell. 
Thus, again, any cell is a correct answer.

In the third testcase, only the middle cell of the board is isolated. 
The knight can move freely around the border of the board, but can't escape the middle.
*/

#include<iostream>
#include<vector>
using namespace std;

bool isIsolated(int currw, int curcol, int rws, int cols){
	bool checkdwnrght=false, checkdwnlft=false, checkuprght=false, checkuplft=false,
	     checkhorrghtdwn=false, checkhorrghtup=false, checkhorlftdwn=false, checkhorlftup=false;
	if(currw+2<rws&&curcol+1<cols){
		checkdwnrght=true;
	}
	if(currw+2<rws&&curcol-1>=0){
		checkdwnlft=true;
	}
	if(currw-2>=0&&curcol+1<cols){
		checkuprght=true;
	}
	if(currw-2>=0&&curcol-1>=0){
		checkuplft=true;
	}
	if(currw+1<rws&&curcol+2<cols){
		checkhorrghtdwn=true;
	}
	if(currw-1>=0&&curcol+2<cols){
		checkhorrghtup=true;
	}
	if(currw+1<rws&&curcol-2>=0){
		checkhorlftdwn=true;
	}
	if(currw-1>=0&&curcol-2>=0){
		checkhorlftup=true;
	}
	return checkdwnrght||checkdwnlft||checkuprght||checkuplft||checkhorrghtdwn||checkhorrghtup
	       ||checkhorlftdwn||checkhorlftup;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N, M;
		cin>>N>>M;
		int fnrw, fncol;
		bool flag=false;
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				if(!isIsolated(i, j, N, M)){
					fnrw=i, fncol=j;
					flag=true;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag){
			cout<<"1 1"<<endl;
		} else{
			cout<<fnrw+1<<" "<<fncol+1<<endl;
		}
	}
}