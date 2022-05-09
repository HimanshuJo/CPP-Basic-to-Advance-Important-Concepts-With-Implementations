#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n, m, k;
        cin>>n>>m>>k;
        if(m>(n*(n-1)/2)||m<n-1){
            cout<<"NO\n";
            continue;
        }
        if(m<(n*(n-1)/2)){
            if(k>3){
                cout<<"YES\n";
            } else{
                cout<<"NO\n";
            }
        } else if(n==1){
            if(k>1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        } else if(k>2) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}