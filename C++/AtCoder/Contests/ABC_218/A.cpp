// Weather Forecast
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string s;
    cin>>N;
    cin>>s;
    if(s[N-1]=='o'){
        cout<<"Yes";
    } else{
        cout<<"No";
    }
}