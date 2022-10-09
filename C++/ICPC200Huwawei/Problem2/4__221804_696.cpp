#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

struct custComp{
    bool operator()(const pair<int, int>&A, const pair<int, int>&B){
        return A.second>B.second;
    }
};

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
    vector<int>dist(N+1, INT_MIN);
    for(auto &vals: mpgr){
        if(seen[vals.first]==-1){
            vector<int>temp;
            temp.push_back(vals.first);
            seen[vals.first]=1;
            dist[vals.first]=0;
            sort(vals.second.begin(), vals.second.end(), custComp());
            for(auto &entries: vals.second){
                bool flag=false;
                if(seen[entries.first]==-1){
                    priority_queue<pair<int, int>, vector<pair<int, int>>>pq;
                    temp.push_back(entries.first);
                    seen[entries.first]=1;
                    dist[entries.first]=1+entries.second;
                    pq.push({dist[entries.first], entries.first});
                    if(temp.size()>=8){
                        break;
                    }
                    while(!pq.empty()){
                        int sz=pq.size();
                        int count=8;
                        while(sz--){
                            int curvert=pq.top().second;
                            int curdist=pq.top().first;
                            pq.pop();
                            for(auto &nei: mpgr[curvert]){
                                if(seen[nei.first]==-1&&count>0){
                                    if(1+curdist+nei.second>dist[nei.first]){
                                        temp.push_back(nei.first);
                                        seen[nei.first]=1;
                                        dist[nei.first]=1+curdist+nei.second;
                                        pq.push({dist[nei.first], nei.first});
                                        count--;
                                    }
                                }
                                if(temp.size()>=8){
                                    flag=true;
                                    break;
                                }
                            }
                        }
                        if(flag) break;
                    }
                    if(flag) break;
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