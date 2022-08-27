#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int calDist(int currx, int curry, int nxtx, int nxty){
	return abs(nxtx-currx)+abs(nxty-curry);
}

bool isValid(int n, int m, int sx, int sy, int d, int currx, int curry, vector<vector<int>>&seen){
	if(currx>=n||curry>=m||currx<0||curry<0||seen[currx][curry]!=-1) return false;
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
		queue<vector<int>>q;
		vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
		vector<vector<int>>seen(n, vector<int>(m, -1));
		dist[0][0]=1;
		seen[0][0]=1;
		q.push({0, 0, 1});
		while(!q.empty()){
			int sz=q.size();
			while(sz--){
				vector<int>curr=q.front();
				q.pop();
				if(curr[0]==n-1&&curr[1]==m-1){
					break;
				}
				for(auto &vals: dir){
					int nwx=curr[0]+vals[0], nwy=curr[1]+vals[1];
					if(isValid(n, m, sx, sy, d, nwx, nwy, seen)){
						vector<int>temp(3);
						temp[0]=nwx, temp[1]=nwy, temp[2]=curr[2]+1;
						if(dist[nwx][nwy]>curr[2]+1){
							dist[nwx][nwy]=curr[2]+1;
							temp[2]=curr[2]+1;
						} else{
							temp[2]=dist[nwx][nwy];
						}
						q.push(temp);
						seen[nwx][nwy]=1;
					}
				}
			}
		}
		cout<<(dist[n-1][m-1]==INT_MAX?-1:(dist[n-1][m-1])-1)<<endl;
	}
}