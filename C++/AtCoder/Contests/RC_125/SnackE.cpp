/*
Problem Statement
There are N kinds of snacks numbered 1 through N. We have Ai pieces of Snack i.

There are M children numbered 1 through M. We will distribute the pieces of snacks 
to these children. Here, all of the following conditions must be satisfied.

For every kind of snack, Child i gets at most Bi pieces of that kind.

Child i gets at most Ci pieces of snacks in total.

Find the maximum total number of pieces of snacks that can be distributed to the
 children under these conditions.

Sample Input 2 

10 6
3 54 62 64 25 89 1 47 77 4
1 17 10 29 95 17
32 40 90 27 50 9

Sample Output 2 

211
*/

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int max=200001;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<ll>A(N);
    for (int i=0; i<N; ++i){
        cin>>A[i];
    }
    vector<int>B(M);
    for (int i=0; i<M; ++i){
        cin>>B[i];
    }
    vector<ll>C(M);
    for (int i=0; i<M; ++i){
        cin>>C[i];
    }
    vector<vector<int>>tmp(N+1);
    vector<ll>cost(N+1, 0);
    ll ans=LONG_MAX;
    ll aSm=0;
    ll bSm=0;
    ll cSm=0;
    sort(A.begin(), A.end());
    for (int x: B){
        bSm+=x;
    }
    for (int i=0; i<M; ++i){
        ll qoCB=C[i]/B[i];
        if (qoCB<=N){
            tmp[qoCB].push_back(i);
        }
    }
    for (int i=0; i<=N; ++i){
        cost[i]=bSm*i+cSm;
        for (int x: tmp[i]){
            bSm-=B[x];
            cSm+=C[x];
        }
    }
    for (int i=0; i<=N; ++i){
        ans=min(ans, aSm+cost[N-i]);
        if (i<N){
            aSm+=A[i];
        }
    }
    cout<<ans<<endl;
}