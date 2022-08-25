#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin>>n>>m;  
    int grd[n][m];
    memset(grd, 0, sizeof(grd));
    string s;
    char ch;
    for(int i=0; i<n; ++i){
        cin>>s;
        for(int j=0; j<m; ++j){
            if(s[j]=='X'){
                grd[i][j]=1;
            } else grd[i][j]=0;
        }
    }
    int toChk[m+1];
    memset(toChk, 0, sizeof(toChk));
    int total=0;
    for(int j=0; j<m-1; ++j){
        for(int i=1; i<n; ++i){
            if(grd[i][j]==1&&grd[i-1][j+1]==1){
                total++;
            }
        }
        toChk[j+1]=total;
    }
    toChk[m]=total;
    int q;
    cin>>q;
    int a, b;
    vector<string>res;
    for(int i=0; i<q; ++i){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        if(toChk[b]-toChk[a]==0){
            res.push_back("Yes");
        } else res.push_back("No");
    }
    for(auto &vals: res)
        cout<<vals<<"\n";
}