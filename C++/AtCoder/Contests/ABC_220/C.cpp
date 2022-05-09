#include<bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<ll>A(N);
    ll currSm=0;
    for(int i=0; i<N; ++i){
        cin>>A[i];
        currSm+=A[i];
    }
    ll X;
    cin>>X;
    ll ans=0;
    if(currSm>X){
        cout<<1;
    } else{
        ll rem=X%currSm;
        ll quo=X/currSm;
        ans+=(quo*A.size());
        currSm*=quo;
        int strt_=0;
        while(currSm<=X){
            if(strt_==A.size()){
                strt_=0;
            }
            currSm+=A[strt_++];
            ans++;
        }
        cout<<ans;
    }
}