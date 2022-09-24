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
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;
    for(int i=0; i<M; ++i){
        int ui, vi, wi;
        cin>>ui>>vi>>wi;
        mpgr[ui].push_back(make_pair(vi, wi));
        mpgr[vi].push_back(make_pair(ui, wi));
        mpwt[wi].push_back(ui);
        mpwt[wi].push_back(vi);
        pq.push({wi, make_pair(ui, vi)});
        pq.push({wi, make_pair(vi, ui)});
    }
    int wtcount=mpwt.size()/N;
    int tmpwtcount=wtcount;
    vector<int>ntincl;
    for(auto &entries: mpwt){
        if(wtcount==0) break;
        ntincl.push_back(entries.first);
        wtcount--;
    }
    vector<vector<int>>res;
    vector<int>seen(N+1, -1);
    while(!pq.empty()){
        int sz=pq.size();
        while(sz--){
            pair<int, pair<int, int>>curr=pq.top();
            pq.pop();
            int frstvert=curr.second.first, secvert=curr.second.second;
            if(seen[frstvert]==-1){
                vector<int>temp;
                temp.push_back(frstvert);
                seen[frstvert]=1;
                if(seen[secvert]==-1){
                    queue<int>q;
                    q.push(secvert);
                    temp.push_back(secvert);
                    seen[secvert]=1;
                    for(auto &vals: ntincl){
                        if(tmpwtcount==0) break;
                        vector<int>curr=mpwt[vals];
                        int sz=curr.size();
                        int idx=0;
                        bool flag=false;
                        while(idx<sz){
                            vector<int>temp;
                            if(seen[curr[idx]]==-1){
                                seen[curr[idx]]=1;
                                res.push_back({curr[idx]});
                                flag=true;
                            }
                            idx++;
                            if(idx>=sz) break;
                            if(seen[curr[idx]]==-1){
                                seen[curr[idx]]=1;
                                res.push_back({curr[idx]});
                                flag=true;
                            }
                            if(flag) break;
                            idx++;
                            tmpwtcount--;
                        }
                        if(flag) break;
                    }
                    if(temp.size()>=N/2){
                        res.push_back(temp);
                        continue;
                    }
                    while(!q.empty()){
                        int qsz=q.size();
                        int count=4;
                        while(qsz--){
                            int nxtvert=q.front();
                            q.pop();
                            for(auto &nei: mpgr[nxtvert]){
                                if(seen[nei.first]==-1&&count>0){
                                    q.push(nei.first);
                                    temp.push_back(nei.first);
                                    seen[nei.first]=1;
                                    count--;
                                }
                            }
                        }
                    }
                } else{
                    res.push_back(temp);
                }
            }
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