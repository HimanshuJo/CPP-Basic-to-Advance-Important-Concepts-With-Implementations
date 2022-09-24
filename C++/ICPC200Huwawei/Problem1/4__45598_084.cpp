#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin>>N>>M;
    unordered_map<int, vector<pair<int, int>>>mpgr;
    map<int, vector<int>, greater<>>mpwt;
    for(int i=0; i<M; ++i){
        int ui, vi, wi;
        cin>>ui>>vi>>wi;
        mpgr[ui].push_back(make_pair(vi, wi));
        mpgr[vi].push_back(make_pair(ui, wi));
        mpwt[wi].push_back(ui);
    }
    int wtcount=mpwt.size()/4;
    int tmpwtcount=wtcount;
    vector<int>ntincl;
    for(auto &entries: mpwt){
        if(wtcount==0) break;
        ntincl.push_back(entries.first);
        wtcount--;
    }
    vector<vector<int>>res;
    vector<int>seen(N+1, -1);
    for(auto &vals: ntincl){
        if(tmpwtcount==0) break;
        vector<int>curr=mpwt[vals];
        int sz=curr.size();
        int idx=0;
        while(idx<sz){
            vector<int>temp;
            if(seen[curr[idx]]==-1){
                seen[curr[idx]]=1;
                res.push_back({curr[idx]});
            }
            idx++;
            if(idx>=sz) break;
            if(seen[curr[idx]]==-1){
                seen[curr[idx]]=1;
                res.push_back({curr[idx]});
            }
            idx++;
            tmpwtcount--;
        }
    }
    for(auto &vals: mpgr){
        if(seen[vals.first]==-1){
            vector<int>temp;
            temp.push_back(vals.first);
            seen[vals.first]=1;
            for(auto &entries: vals.second){
                if(seen[entries.first]==-1){
                    queue<int>q;
                    q.push(entries.first);
                    temp.push_back(entries.first);
                    seen[entries.first]=1;
                    while(!q.empty()){
                        int sz=q.size();
                        int count=3;
                        while(sz--){
                            int curvert=q.front();
                            q.pop();
                            for(auto &nei: mpgr[curvert]){
                                if(seen[nei.first]==-1&&count>0){
                                    q.push(nei.first);
                                    temp.push_back(nei.first);
                                    seen[nei.first]=1;
                                    count--;
                                }
                            }
                        }
                    }
                }
            }
            res.push_back(temp);
        }
    }
    cout<<res.size()<<endl;
    for(auto &entries: res){
        cout<<entries.size()<<" ";
        for(auto &vals: entries){
            cout<<vals<<" ";
        }
        cout<<endl;
    }
}