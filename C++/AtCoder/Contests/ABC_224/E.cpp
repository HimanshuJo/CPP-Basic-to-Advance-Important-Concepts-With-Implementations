#include<bits/stdc++.h>
using namespace std;

int rw[200005], cl[200005], a[200005];
int rmax[200005], cmax[200005];
int dp[200005];
map<int, vector<int>>mp;

 int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W, N;
    cin>>H>>W>>N;
    for(int i=1; i<=N; ++i){
        cin>>rw[i]>>cl[i]>>a[i];
        mp[a[i]].push_back(i);
    }
    for(auto it=mp.rbegin(); it!=mp.rend(); ++it){
        for(auto i: it->second){
            dp[i]=max(rmax[rw[i]], cmax[cl[i]]);
        }
        for(auto i: it->second){
            rmax[rw[i]]=max(rmax[rw[i]], dp[i]+1);
            cmax[cl[i]]=max(cmax[cl[i]], dp[i]+1);
        }
    }
    for(int i=1; i<=N; ++i){
        cout<<dp[i]<<endl;
    }
}