#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    vector<vector<int>>gr(N);
    vector<int>indeg(N);
    for(int i=0; i<M; ++i){
        int a, b;
        cin>>a>>b;
        a-=1, b-=1;
        gr[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int, vector<int>, greater<>>mnPq;
    for(int i=0; i<N; ++i){
        if(indeg[i]==0){
            mnPq.push(i);
        }
    }
    vector<int>ans;
    while(!mnPq.empty()){
        int curr=mnPq.top();
        mnPq.pop();
        ans.push_back(curr);
        for(int nei: gr[curr]){
            indeg[nei]-=1;
            if(indeg[nei]==0){
                mnPq.push(nei);
            }
        }
    }
    if(ans.size()!=N) cout<<-1<<"\n";
    else{
        for(int i=0; i<N; ++i){
            cout<<ans[i]+1<<" ";
        }
    }
}