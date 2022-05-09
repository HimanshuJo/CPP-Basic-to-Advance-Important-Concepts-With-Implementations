// C. Ice Cave
/*
You play a computer game. Your character stands on some level of a multilevel ice cave. 
In order to move on forward, you need to descend one level lower and the only way to do this is to fall through the ice.

The level of the cave where you are is a rectangular square grid of n rows and m columns. Each cell consists either from intact or from cracked ice.
From each cell you can move to cells that are side-adjacent with yours (due to some limitations of the game engine you cannot 
make jumps on the same place,
i.e. jump from a cell to itself). If you move to the cell with cracked ice, then your character falls down through it 
and if you move to the cell with intact ice, then the ice on this cell becomes cracked.

Let's number the rows with integers from 1 to n from top to bottom and the columns with integers from 1 to m from left to right. 
Let's denote a cell on the intersection of the r-th row and the c-th column as (r, c).

You are staying in the cell (r1, c1) and this cell is cracked because you've just fallen here from a higher level. 
You need to fall down through the cell (r2, c2) since the exit to the next level is there. Can you do this?

Examples
input
4 6
X...XX
...XX.
.X..X.
......
1 6
2 2
output
YES

input
5 4
.X..
...X
X.X.
....
.XX.
5 3
1 1
output
NO

input
4 7
..X.XX.
.XX..X.
X...X..
X......
2 2
1 6
output
YES

Note
In the first sample test one possible path is:

After the first visit of cell (2, 2) the ice on it cracks and when you step there for the second time, 
your character falls through the ice as intended.
*/

#include<vector>
#include<iostream>
#include<queue>
#include<set>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	char grd[505][505];
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j)
			cin>>grd[i][j];
	}
	pair<int, int>src;
	pair<int, int>dest;
	int r1, c1;
	cin>>r1>>c1;
	src.first=r1, src.second=c1;
	int r2, c2;
	cin>>r2>>c2;
	dest.first=r2, dest.second=c2;
	queue<pair<int, int>>q;
	set<pair<int, int>>seen;
	vector<pair<int, int>>dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	q.push(src);
	seen.insert({src.first, src.second});
	bool flag=false;
	if(grd[r2][c2]=='X'){
		while(!q.empty()&&!flag){
			pair<int, int>curr=q.front();
			q.pop();	
			for(auto &vals: dir){
				int nwi=vals.first+curr.first;
				int nwj=vals.second+curr.second;
				if(nwi>=1&&nwi<=n&&nwj>=1&&nwj<=m&&grd[nwi][nwj]!='X'&&seen.find({nwi, nwj})==seen.end()){
					q.push({nwi, nwj});
					seen.insert({nwi, nwj});
				} else if(nwi==dest.first&&nwj==dest.second){
					flag=true;
					break;
				}
			}
		}
	} else{
		while(!q.empty()&&!flag){
			pair<int, int>curr=q.front();
			q.pop();	
			for(auto &vals: dir){
				int nwi=vals.first+curr.first;
				int nwj=vals.second+curr.second;
				if(nwi>=1&&nwi<=n&&nwj>=1&&nwj<=m&&grd[nwi][nwj]!='X'&&seen.find({nwi, nwj})==seen.end()){
					q.push({nwi, nwj});
					seen.insert({nwi, nwj});
					grd[nwi][nwj]='X';
				} else if(nwi==dest.first&&nwj==dest.second&&grd[nwi][nwj]=='X'){
					if(grd[nwi][nwj]=='X'){
						flag=true;
						break;
					}
				}
			}
		}
	}
	if(flag) cout<<"YES\n";
	else cout<<"NO\n";
}

