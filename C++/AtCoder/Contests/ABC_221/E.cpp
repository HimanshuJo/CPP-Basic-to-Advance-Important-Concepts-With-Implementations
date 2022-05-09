#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

struct binary_indexed_tree{
    int N;
    vector<ll> bit;
    binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    ll addition(ll x, ll y){
        return (x+y)%mod;
    }
    void add(int x,ll a){
        x++;
        for(x; x<=N; x+=(x&-x)) bit[x] = addition(bit[x],a);
    }
    ll sum(int x){
        x++;
        ll ret=0;
        for(x; x>0; x-=(x&-x)) ret = addition(ret,bit[x]);
        return ret;
    }
};

ll modpow(ll x, ll y){
    ll ret = 1;
    while(0 < y){
        if(y & 1){
            ret *= x;
            ret %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ret;
}

int comp(vector<int> &A){
    std::map<int,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

int main(){
    const ll div = modpow(2,mod-2);
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int n = comp(A);
    binary_indexed_tree bit(n);
    ll ans = 0;
    for(int i=0; i<N; i++){
        ans += bit.sum(A[i])*modpow(2,i);
        ans %= mod;
        bit.add(A[i],modpow(div,i+1));
    }
    cout << ans << endl;
}
