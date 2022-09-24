#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
        vector<ll>in(N);
        for(int i=0; i<N; ++i){
            cin>>in[i];
        }
        ll ans=LONG_MIN;
        for(int xx=0; xx<N; ++xx){
            if(xx+K-1>=N) break;
            ll cursm=0;
            for(int yy=xx; yy<=xx+K-1; ++yy){
                cursm+=in[yy];
            }
            ans=max(ans, cursm);
        }
        vector<int>temp1, temp2;
        for(int i=0; i<N; ++i){
            if(i+K<N){
                temp1.push_back(i);
                temp2.push_back(i+K);
            }
        }
        sort(temp1.begin(), temp1.end(), greater<>());
        sort(temp2.begin(), temp2.end(), greater<>());
        int sz=temp1.size();
        ll nwsm=0;
        for(int i=0; i<sz; ++i){
            if(K<=0) break;
            nwsm+=temp1[i]+temp2[i];
            K-=2;
        }
        ans=max(ans, nwsm);
        cout<<ans<<endl;
    }
}