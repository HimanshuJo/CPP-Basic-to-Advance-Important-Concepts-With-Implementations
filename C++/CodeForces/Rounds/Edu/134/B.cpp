// B. Deadly Laser
/*
The robot is placed in the top left corner of a grid, consisting of n rows and m columns, in a cell (1,1).

In one step, it can move into a cell, adjacent by a side to the current one:

(x,y)→(x,y+1);
(x,y)→(x+1,y);
(x,y)→(x,y−1);
(x,y)→(x−1,y).

The robot can't move outside the grid.

The cell (sx,sy) contains a deadly laser. If the robot comes into some cell that has distance less 
than or equal to d to the laser, it gets evaporated. The distance between two cells (x1,y1) and (x2,y2) 
is |x1−x2|+|y1−y2|.

Print the smallest number of steps that the robot can take to reach the cell (n,m) without getting 
evaporated or moving outside the grid. If it's not possible to reach the cell (n,m), print -1.

The laser is neither in the starting cell, nor in the ending cell. The starting cell always has distance 
greater than d to the laser.

Example
input
3
2 3 1 3 0
2 3 1 3 1
5 5 3 4 1

output
3
-1
8
1
*/

/*
TLE:

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int calDist(int currx, int curry, int nxtx, int nxty){
	return abs(nxtx-currx)+abs(nxty-curry);
}

bool isValid(int n, int m, int sx, int sy, int d, int currx, int curry){
	if(currx>=n||curry>=m||currx<0||curry<0) return false;
	int curdist=calDist(currx, curry, sx-1, sy-1);
	return curdist>d;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m, sx, sy, d;
		cin>>n>>m>>sx>>sy>>d;
		vector<vector<int>>dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>q;
		vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
		dist[0][0]=1;
		q.push({1, {0, 0}});
		while(!q.empty()){
			int sz=q.size();
			while(sz--){
				pair<int, pair<int, int>>curr=q.top();
				q.pop();
				if(curr.second.first==n-1&&curr.second.second==m-1){
					break;
				}
				if(curr.first>dist[curr.second.first][curr.second.second]) continue;
				for(auto &vals: dir){
					int nwx=curr.second.first+vals[0], nwy=curr.second.second+vals[1];
					if(isValid(n, m, sx, sy, d, nwx, nwy)){
						vector<int>temp(3);
						temp[0]=nwx, temp[1]=nwy, temp[2]=curr.first+1;
						if(dist[curr.second.first][curr.second.second]+1<dist[nwx][nwy]){
							dist[nwx][nwy]=dist[curr.second.first][curr.second.second]+1;
							temp[2]=dist[curr.second.first][curr.second.second]+1;
							q.push({temp[2], {temp[0], temp[1]}});
						}
					}
				}
			}
		}
		cout<<(dist[n-1][m-1]==INT_MAX?-1:(dist[n-1][m-1])-1)<<endl;
	}
}
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int calDist(int currx, int curry, int nxtx, int nxty){
	return abs(nxtx-currx)+abs(nxty-curry);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m, sx, sy, d;
		cin>>n>>m>>sx>>sy>>d;
		int val1=calDist(1, 1, sx, sy);
		int val2=sy-1, val3=n-sx, val4=m-sy, val5=sx-1;
		int val6=calDist(n, m, sx, sy);
		if(val1<=d||val6<=d){
			cout<<-1<<endl;
		} else if((val2>d&&val3>d)||(val4>d&&val5>d)){
			cout<<calDist(1, 1, n, m)<<endl;
		} else{
			cout<<-1<<endl;
		}
	}
}