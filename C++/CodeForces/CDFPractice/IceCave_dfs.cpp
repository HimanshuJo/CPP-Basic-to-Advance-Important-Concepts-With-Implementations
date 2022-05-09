/*
// C. Ice Cave
You play a computer game. Your character stands on some level of a multilevel ice cave. 
In order to move on forward, you need to descend one level lower and the only way to do this is to fall through the ice.

The level of the cave where you are is a rectangular square grid of n rows and m columns. Each cell consists either from intact or from cracked ice.
From each cell you can move to cells that are side-adjacent with yours (due to some limitations of the game engine you cannot make jumps on the same place,
i.e. jump from a cell to itself). If you move to the cell with cracked ice, then your character falls down through it 
and if you move to the cell with intact ice, then the ice on this cell becomes cracked.

Let's number the rows with integers from 1 to n from top to bottom and the columns with integers from 1 to m from left to right. 
Let's denote a cell on the intersection of the r-th row and the c-th column as (r, c).

You are staying in the cell (r1, c1) and this cell is cracked because you've just fallen here from a higher level. 
You need to fall down through the cell (r2, c2) since the exit to the next level is there. Can you do this?
*/

#include<iostream>
#include<vector>
using namespace std;

char grd[501][501];
vector<pair<int, int>>dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(int r1, int c1, const int r2, const int c2){
	if(grd[r1][c1]!='.') return (r1==r2&&c1==c2);
	grd[r1][c1]='X';
	for(auto &vals: dir)
		if(dfs(r1+vals.first, c1+vals.second, r2, c2))
			return 1;
	return 0;
}

int main(){
	int n, m;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			cin>>grd[i][j];
	int r1, c1, r2, c2;
	cin>>r1>>c1>>r2>>c2;
	grd[r1][c1]='.';
	if(dfs(r1, c1, r2, c2))
		cout<<"YES\n";
	else cout<<"NO\n";
}
