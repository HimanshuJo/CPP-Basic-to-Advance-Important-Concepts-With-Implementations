#include<bits/stdc++.h>
using namespace std;

int f[100001];
const int mod=1000000007;

void calModFact(){
    f[1]=1;
    for(int i=2; i<=100001; ++i){
        f[i]=((i<<1)-1ll)*f[i-1]%mod*(i<<1)%mod;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calModFact();
    int n;
    cin>>n;
    while(n--){
        int in;
        cin>>in;
        cout<<f[in]<<"\n";
    }
}