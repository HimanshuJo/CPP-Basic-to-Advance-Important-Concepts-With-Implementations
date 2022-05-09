#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int P[N];
    int res[N];
    for (int i=0; i<N; ++i){
        cin>>P[i];
    }
    for (int i=0; i<N; ++i){
        res[P[i]-1]=i+1;
    }
    for (int x: res){
        cout<<x<<" ";
    }
}