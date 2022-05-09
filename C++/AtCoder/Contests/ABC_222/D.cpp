#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxx=3001;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    int A[maxx];
    int B[maxx];
    vector<vector<int>>dp(maxx, vector<int>(maxx, 0));
    vector<vector<int>>sum(maxx, vector<int>(maxx, 0));
    for(int i=0; i<N; ++i){
        cin>>A[i];
    }
    for(int i=0; i<N; ++i){
        cin>>B[i];
    }
    for(int i=A[0]; i<=B[0]; ++i){
        dp[0][i]=1;
    }
    sum[0][0]=dp[0][0];
    for(int j=1; j<maxx; ++j){
        sum[0][j]=sum[0][j-1]+dp[0][j];
    }
    for(int i=1; i<N; ++i){
        for(int j=A[i]; j<=B[i]; ++j){
            dp[i][j]=sum[i-1][j];
        }
        sum[i][0]=dp[i][0];
        for(int j=1; j<maxx; ++j){
            sum[i][j]=sum[i][j-1]+dp[i][j];
            sum[i][j]%=mod;
        }
    }
    cout<<(sum[N-1][maxx-1])<<endl;
}