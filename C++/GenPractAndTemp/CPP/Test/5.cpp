#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using ll=long long;
using namespace std;

ll query(ll vertA, ll vertB){
    cout<<"? "<<vertA<<" "<<vertB<<endl;
    ll x;
    cin>>x;
    return x;
}

bool isValid(ll mid, int bgn){
    ll pth1=query(bgn, mid);
    ll pth2=query(mid, bgn);
    return pth1==pth2;
}

int main(){
    int max_queries=50;
    int bgn=1;
    ll ans=0;
    ll l=2, r=max_queries/2;
    ll pth1=0, pth2=0;
    bool flag=false;
    while(l<=r){
        ll mid=l+(r-l)/2;
        pth1=query(bgn, mid);
        if(pth1==-1){
            flag=true;
            ans=mid-1;
            break;
        }
        if(isValid(mid, bgn)){
            pth1=query(bgn, mid);
            pth2=query(mid, bgn);
            l=mid+1;
        } else{
            r=mid-1;
        }
    }
    if(!flag) ans=pth1+pth2;
    cout<<"! "<<ans<<endl;
}