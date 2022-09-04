#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

bool isValid(int currx, int curry, int n, set<pair<int, int>>&seen){
    auto it=seen.find({currx, curry});
    if(it!=seen.end()) return false;
    return currx>=0&&curry>=0&&currx<=n-1&&curry<=n-1;
}

void bfs(vector<vector<char>>&grd, set<pair<int, int>>&seen, int currx, int curry, int n, int k,
                set<int>&seenrws, set<int>&seencols){
    grd[currx][curry]='X';
    queue<pair<int, int>>q;
    q.push({currx, curry});
    seen.insert({currx, curry});
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pair<int, int>curr=q.front();
            q.pop();
            int frnwx=curr.first-k, frnwy=curr.second;
            if(isValid(frnwx, frnwy, n, seen)){
                auto it1=seenrws.find(frnwx);
                auto it2=seencols.find(frnwy);
                if(it1==seenrws.end()&&it2==seencols.end()){
                    grd[frnwx][frnwy]='X';
                    q.push({frnwx, frnwy});
                    seen.insert({frnwx, frnwy});
                }
            }
            int secnwx=curr.first+k, secnwy=curr.second;
            if(isValid(secnwx, secnwy, n, seen)){
                auto it1=seenrws.find(secnwx);
                auto it2=seencols.find(secnwy);
                if(it1==seenrws.end()&&it2==seencols.end()){
                    grd[secnwx][secnwy]='X';
                    q.push({secnwx, secnwy});
                    seen.insert({secnwx, secnwy});
                }
            }
            int thrdnwx=curr.first, thrdnwy=curr.second-k;
            if(isValid(thrdnwx, thrdnwy, n, seen)){
                auto it1=seenrws.find(thrdnwx);
                auto it2=seencols.find(thrdnwy);
                if(it1==seenrws.end()&&it2==seencols.end()){
                    grd[thrdnwx][thrdnwy]='X';
                    q.push({thrdnwx, thrdnwy});
                    seen.insert({thrdnwx, thrdnwy});
                }
            }
            int frthnwx=curr.first, frthnwy=curr.second+k;
            if(isValid(frthnwx, frthnwy, n, seen)){
                auto it1=seenrws.find(frthnwx);
                auto it2=seencols.find(frthnwy);
                if(it1==seenrws.end()&&it2==seencols.end()){
                    grd[frthnwx][frthnwy]='X';
                    q.push({frthnwx, frthnwy});
                    seen.insert({frthnwx, frthnwy});
                }
            }
            seenrws.insert(curr.first);
            seencols.insert(curr.second);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, k, r, c;
        cin>>n>>k>>r>>c;
        vector<vector<char>>grd(n, vector<char>(n, '.'));
        set<pair<int, int>>seen;
        set<int>seenrws, seencols;
        bfs(grd, seen, r-1, c-1, n, k, seenrws, seencols);
        bool flag=false;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(grd[i][j]=='.'){
                    bool flag=false, flag2=false;
                    int frnwx=i-k, frnwy=j;
                    if(frnwx>=0) flag2=true;
                    for(int x=i; x>=max(0, frnwx); --x){
                        for(int y=j; y<=frnwy; ++y){
                            if(grd[x][y]=='X'){
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(!flag){
                        int secnwx=i+k, secnwy=j; 
                        if(secnwx<=n-1) flag2=true;
                        for(int x=i; x<=min(secnwx, r-1); ++x){
                            for(int y=j; y<=secnwy; ++y){
                                if(grd[x][y]=='X'){
                                    flag=true;
                                    break;
                                }
                            }
                        }  
                    }
                    if(!flag){
                        int thrdnwx=i, thrdnwy=j-k;
                        if(thrdnwy>=0) flag2=true;
                        for(int x=i; x<=thrdnwx; ++x){
                            for(int y=j; y>=max(0, thrdnwy); --y){
                                if(grd[x][y]=='X'){
                                    flag=true;
                                    break;
                                }
                            }
                        }
                    }
                    if(!flag){
                        int frthnwx=i, frthnwy=j+k;
                        if(frthnwy<=n-1) flag2=true;
                        for(int x=i; x<=frthnwx; ++x){
                            for(int y=j; y<=min(frthnwy, c-1); ++y){
                                if(grd[x][y]=='X'){
                                    flag=true;
                                    break;
                                }
                            }
                        }
                    }
                    if(!flag&&flag2){
                        bfs(grd, seen, i, j, n, k, seenrws, seencols);
                    }
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cout<<grd[i][j];
            }
            cout<<endl;
        }
    }
}