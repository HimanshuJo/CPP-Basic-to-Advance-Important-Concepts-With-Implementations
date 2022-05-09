#include<bits/stdc++.h>
using ll=long long;
using namespace std;

bool rect2(ll X, ll Y, ll frst, ll sec){
    for(int i=0; i<2; ++i){
        const ll len=(frst+X-1)/X;
        if(len<Y and X*(Y-len)>=sec){
            return true;
        }
        swap(X, Y);
    }
    return false;
}

bool rect3(int X, int Y, ll A, ll B, ll C){
    for(int i=0; i<2; ++i){
        for(int j=0; j<3; ++j){
            const ll len=(A+X-1)/X;
            if(len<Y and rect2(X, Y-len, B, C)){
                return true;
            }
            swap(A, B);
            swap(B, C);
        }
        swap(X, Y);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int X, Y;
    cin>>X>>Y;
    ll A, B, C;
    cin>>A>>B>>C;
    bool res=rect3(X, Y, A, B, C);
    if(res) cout<<"Yes\n";
    else cout<<"No\n";
}   