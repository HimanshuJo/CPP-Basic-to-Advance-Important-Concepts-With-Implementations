#include<bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    cin>>H>>W;
    vector<vector<int>>A(H+1, vector<int>(W+1));
    for(int i=1; i<=H; ++i){
        for(int j=1; j<=W; ++j){
            cin>>A[i][j];
        }
    }
    for(int i=1; i<=H; ++i){
        for(int i_=i+1; i_<=H; ++i_){
            for(int j=1; j<=W; ++j){
                for(int j_=j+1; j_<=W; ++j_){
                    if(A[i][j]+A[i_][j_]>A[i_][j]+A[i][j_]){
                        cout<<"No\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout<<"Yes\n";
}