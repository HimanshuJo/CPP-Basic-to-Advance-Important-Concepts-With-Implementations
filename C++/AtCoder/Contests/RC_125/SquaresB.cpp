/*
Problem Statement
You are given an integer N. Find the number of pairs of integers (x,y) 
that satisfy the following conditions, modulo 998244353.

1≤x,y≤N.

x^2−y is a square number. (Assume 0 is also a square number.)

Sample Input 3 

10000000000

Sample Output 3 

52583544
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod=998244353;

ll calcK(ll n){
    ll x=0;
    while ((x+1)*(x+1)<=n){
        ++x;
    }
    ll v=0;
    for (ll i=1; i<=x; ++i){
        v+=n/i;
    }
    ll res=(v+v)-(x*x);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while (t--){
        long long N;
        cin>>N;
        ll ans=calcK(N)-2*calcK(N/2)+2*calcK(N/4);
        ll x=0;
        while ((x+1)*(x+1)<=N){
            ++x;
        }
        ans=(ans+x)/2;
        ans%=mod;
        cout<<ans;
    }
}