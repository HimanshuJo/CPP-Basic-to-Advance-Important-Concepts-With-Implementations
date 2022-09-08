#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n, 0);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        int res=0;
        for(int i=1; i<n; ++i){
            res=max(res, in[i-1]-in[i]);
        }
        for(int i=1; i<n; ++i){
            res=max(res, in[i]-in[0]);
        }
        for(int i=0; i<n-1; ++i){
            res=max(res, in[n-1]-in[i]);
        }
        cout<<res<<"\n";
    }
}