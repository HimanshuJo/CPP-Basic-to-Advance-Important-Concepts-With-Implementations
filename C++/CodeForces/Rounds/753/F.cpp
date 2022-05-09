#include<bits/stdc++.h>
using namespace std;

bool check_Boundary(int row, int col, int n, int m){
	return (row>-1&&row<n&&col>-1&&col<m);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		vector<string>dir(n);
		for(int i=0; i<n; ++i){
			cin>>dir[i];
		}
		vector<vector<int>> res(n, vector<int>(m, 0));
		int opt=0, optr=0, optc=0;
		for(int r=0; r<n; ++r){
			for(int c=0; c<m; ++c){
				if(res[r][c]>0)
					continue;
				int nr=r, nc=c;
				int depth=0;
				vector<pair<int, int>>path;
				do{
					res[nr][nc]=--depth;
					path.emplace_back(nr, nc);
					if(dir[nr][nc]=='L')
						nc--;
					else if(dir[nr][nc]=='R')
						nc++;
					else if(dir[nr][nc]=='U')
						nr--;
					else nr++;
				} while(check_Boundary(nr, nc, n, m)&&res[nr][nc]==0);
				int strt=1;
				if(check_Boundary(nr, nc, n, m)){
					if(res[nr][nc]<0){
						int cycle=res[nr][nc]-depth+1;
						for(int i=0; i<cycle; ++i){
							auto p=path.back();
							path.pop_back();
							res[p.first][p.second]=cycle;
						}
					}
					strt=res[nr][nc]+1;
				}
				while(!path.empty()){
					auto p=path.back();
					path.pop_back();
					res[p.first][p.second]=strt++;
				}
				if(res[r][c]>opt){
					opt=res[r][c];
					optr=r;
					optc=c;
				}
			}
		}
		cout<<optr+1<<" "<<optc+1<<" "<<opt<<"\n";
	}
}
