#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S, T;
    cin>>S>>T;
    vector<string>in;
    in.push_back(S);
    in.push_back(T);
    sort(in.begin(), in.end());
    if (S.compare(in[0])==0){
        cout<<"Yes";
    } else{
        cout<<"No";
    }
}