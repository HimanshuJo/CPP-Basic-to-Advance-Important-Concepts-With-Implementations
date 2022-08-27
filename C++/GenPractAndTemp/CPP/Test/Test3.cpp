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