#include<bits/stdc++.h>
using namespace std;

const int N=2005;
int dist[N][N];
char in[N][N];
bool seen[N][N];
pair<int, int>path[N*N];
int cnt;

int dfs(int x, int y, int n, int m){
	path[++cnt]={x, y};
	if(x<1||x>n||y<1||y>m||seen[x][y])
		return dist[x][y];
	seen[x][y]=true;
	if(in[x][y]=='U'){
		dist[x][y]=1+dfs(x-1, y, n, m);
	}
	if(in[x][y]=='D'){
		dist[x][y]=1+dfs(x+1, y, n, m);
	}
	if(in[x][y]=='L'){
		dist[x][y]=1+dfs(x, y-1, n, m);
	}
	if(in[x][y]=='R'){
		dist[x][y]=1+dfs(x, y+1, n, m);
	}
	return dist[x][y];
}

//int bfs(int x, int y, int n, int m){
//	path[++cnt]={x, y};
//	queue<pair<int, int>>q;
//	if(x<1||x>n||y<1||y>m||seen[x][y])
//		return dist[x][y];
//	q.push({x, y});
//	seen[x][y]=true;
//	int counter=0;
//	while(!q.empty()){
//		int len=q.size();
//		while(len--){
//			pair<int, int>curr=q.front();
//			q.pop();
//			int nwx=curr.first;
//			int nwy=curr.second;
//			if(in[nwx][nwy]=='U')
//				nwx-=1;
//			if(in[nwx][nwy]=='D')
//				nwx+=1;
//			if(in[nwx][nwy]=='L')
//				nwy-=1;
//			if(in[nwx][nwy]=='R')
//				nwy+=1;
//			if(nwx<1||nwx>n||nwy<1||nwy>m||seen[nwx][nwy])
//				continue;
//			seen[nwx][nwy]=true;
//			q.push(make_pair(nwx, nwy));
//			path[++cnt]=make_pair(nwx, nwy);
//			counter++;
//		}
//	}
//	dist[x][y]=counter;
//	return dist[x][y];
//}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				cin>>in[i][j];
			}
		}
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				if(!seen[i][j]){
					cnt=0;
					dfs(i, j, n, m);
					pair<int, int>curr=path[cnt];
					for(int x=1; x<cnt; ++x){
						if(path[x]==curr){
							for(int y=x; y<=cnt; ++y){
								dist[path[y].first][path[y].second]=cnt-x;
							}
							break;
						}
					}
				}
			}
		}
		int x=1, y=1, res=dist[x][y];
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				if(dist[i][j]>res){
					x=i, y=j, res=dist[i][j];
				}
			}
		}
		cout<<x<<" "<<y<<" "<<res<<"\n";
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=m; ++j){
				seen[i][j]=false;
				dist[i][j]=0;
			}
		}
	}
}

