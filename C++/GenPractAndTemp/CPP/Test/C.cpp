#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

void bfs(vector<vector<char>>&grd, int currx, int curry, int n, int m,
         set<pair<int, int>>&seen, bool &flag){
    queue<pair<int, int>>q;
    q.push({currx, curry});
    seen.insert({currx, curry});
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pair<int, int>curfrnt=q.front();
            q.pop();
            if(curfrnt.first+1<=n-1){
                auto it=seen.find({curfrnt.first+1, curfrnt.second});
                if(it==seen.end()){
                    if(grd[curfrnt.first+1][curfrnt.second]=='.'){
                        grd[curfrnt.first+1][curfrnt.second]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first+1, curfrnt.second});
                        q.push({curfrnt.first+1, curfrnt.second});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first+1][curfrnt.second]=='R')||(grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first+1][curfrnt.second]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first+1, curfrnt.second});
                            q.push({curfrnt.first+1, curfrnt.second});
                        }
                    }
                }
            }
            if(curfrnt.first-1>=0){
                auto it=seen.find({curfrnt.first-1, curfrnt.second});
                if(it==seen.end()){
                    if(grd[curfrnt.first-1][curfrnt.second]=='.'){
                        grd[curfrnt.first-1][curfrnt.second]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first-1, curfrnt.second});
                        q.push({curfrnt.first-1, curfrnt.second});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first-1][curfrnt.second]=='R')||(grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first-1][curfrnt.second]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first-1, curfrnt.second});
                            q.push({curfrnt.first-1, curfrnt.second});
                        }
                    }
                }
            }
            if(curfrnt.second+1<=m-1){
                auto it=seen.find({curfrnt.first, curfrnt.second+1});
                if(it==seen.end()){
                    if(grd[curfrnt.first][curfrnt.second+1]=='.'){
                        grd[curfrnt.first][curfrnt.second+1]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first, curfrnt.second+1});
                        q.push({curfrnt.first, curfrnt.second+1});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first][curfrnt.second+1]=='R')||(grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first][curfrnt.second+1]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first, curfrnt.second+1});
                            q.push({curfrnt.first, curfrnt.second+1});
                        }
                    }
                }
            }
            if(curfrnt.second-1>=0){
                auto it=seen.find({curfrnt.first, curfrnt.second-1});
                if(it==seen.end()){
                    if(grd[curfrnt.first][curfrnt.second-1]=='.'){
                        grd[curfrnt.first][curfrnt.second-1]=grd[curfrnt.first][curfrnt.second]=='R'?'W':'R';
                        seen.insert({curfrnt.first, curfrnt.second-1});
                        q.push({curfrnt.first, curfrnt.second-1});
                    } else{
                        if((grd[curfrnt.first][curfrnt.second]=='R'&&grd[curfrnt.first][curfrnt.second-1]=='R')||(grd[curfrnt.first][curfrnt.second]=='W'&&grd[curfrnt.first][curfrnt.second-1]=='W')){
                            flag=true;
                            break;
                        } else{
                            seen.insert({curfrnt.first, curfrnt.second-1});
                            q.push({curfrnt.first, curfrnt.second-1});
                        }
                    }
                }
            }
        }
        if(flag) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>>grd(n, vector<char>(m));
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                cin>>grd[i][j];
            }
        }
        set<pair<int, int>>seen;
        bool flag=false;
		vector<vector<char>>grd_=grd;
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(grd_[i][j]!='.'){
                    bfs(grd_, i, j, n, m, seen, flag);
                    if(flag) break;
                }
            }
            if(flag) break;
        }
        if(!flag){
			vector<vector<char>>tmp=grd;
			if(tmp[0][0]=='.'){
				char curr_='R';
				tmp[0][0]=curr_;
				seen.clear();
				bfs(tmp, 0, 0, n, m, seen, flag);
				if(!flag){
					cout<<"YES\n";
					for(int i=0; i<n; ++i){
						for(int j=0; j<m; ++j){
							cout<<tmp[i][j];
						}
						cout<<"\n";
					}
				} else{
					flag=false;
					char curr__='W';
					vector<vector<char>>tmp2=grd;
					tmp2[0][0]=curr__;
					seen.clear();
					bfs(tmp2, 0, 0, n, m, seen, flag);
					if(!flag){
						cout<<"YES\n";
						for(int i=0; i<n; ++i){
							for(int j=0; j<m; ++j){
								cout<<tmp2[i][j];
							}
							cout<<"\n";
						}
					} else{
						cout<<"NO\n";
					}
				}
			} else{
				seen.clear();
				bfs(tmp, 0, 0, n, m, seen, flag);
				if(!flag){
					cout<<"YES\n";
					for(int i=0; i<n; ++i){
						for(int j=0; j<m; ++j){
							cout<<tmp[i][j];
						}
						cout<<"\n";
					}
				} else{
					cout<<"NO\n";
				}
			}
        } else{
			cout<<"NO\n";
		}
    }
}