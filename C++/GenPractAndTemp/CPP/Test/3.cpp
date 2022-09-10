#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n), B(n);
        for(int i=0; i<n; ++i){
            cin>>A[i];
        }
        for(int i=0; i<n; ++i){
            cin>>B[i];
        }
        priority_queue<int, vector<int>>pq1, pq2;
        for(auto &vals: A){
            pq1.push(vals);
        }
        for(auto &vals: B){
            pq2.push(vals);
        }
        int ans=0;
        while(!pq1.empty()&&!pq2.empty()){
            int curAtp=pq1.top(), curBtp=pq2.top();
            if(curAtp==curBtp){
                pq1.pop();
                pq2.pop();
                continue;
            }
            ans++;
            if(curAtp<curBtp){
                int nwnm=(to_string(curBtp)).length();
                pq2.pop();
                pq2.push(nwnm);
            } else{
                int nwnum=(to_string(curAtp)).length();
                pq1.pop();
                pq1.push(nwnum);
            }
        }
        cout<<ans<<"\n";
    }
}