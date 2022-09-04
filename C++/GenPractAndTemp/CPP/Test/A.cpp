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
                        seen.insert({currx, curry-1});
                        q.push({currx, curry-1});
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
        grd[0][0]='W';
        bfs(grd, 0, 0, n, m, seen, flag);
        if(!flag){
            cout<<"YES\n";
            for(int i=0; i<n; ++i){
                for(int j=0; j<m; ++j){
                    cout<<grd[i][j];
                }
                cout<<"\n";
            }
        } else{
            cout<<"NO\n";
        }
    }
}