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
    for(int i=0; i<M; ++i){
        int ui, vi, wi;
        cin>>ui>>vi>>wi;
        mpgr[ui].push_back(make_pair(vi, wi));
        mpgr[vi].push_back(make_pair(ui, wi));
    }
    int setSz, k;
    cin>>setSz>>k;
    for(int i=0; i<setSz; ++i){
        int nodeId;
        cin>>nodeId;
    }
    vector<vector<int>>res;
    vector<int>seen(N+1, -1);
    vector<int>dist(N+1, INT_MAX);
    for(auto &vals: mpgr){
        if(seen[vals.first]==-1){
            vector<int>temp;
            temp.push_back(vals.first);
            seen[vals.first]=1;
            dist[vals.first]=0;
            for(auto &entries: vals.second){
                if(seen[entries.first]==-1){
                    priority_queue<int, vector<int>>pq;
                    pq.push(entries.first);
                    temp.push_back(entries.first);
                    seen[entries.first]=1;
                    dist[entries.first]=1+entries.second;
                    while(!pq.empty()){
                        int sz=pq.size();
                        int count=k;
                        while(sz--){
                            int curvert=pq.top();
                            pq.pop();
                            for(auto &nei: mpgr[curvert]){
                                if(seen[nei.first]==-1&&count>0){
                                    if(1+dist[curvert]+nei.second<dist[nei.first]){
                                        pq.push(nei.first);
                                        temp.push_back(nei.first);
                                        seen[nei.first]=1;
                                        dist[nei.first]=1+dist[curvert]+nei.second;
                                        count--;
                                    }
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