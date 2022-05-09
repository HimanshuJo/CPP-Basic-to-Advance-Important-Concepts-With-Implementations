#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    unordered_map<string, int>mp;
    for (int i=0; i<N; ++i){
        string S, T;
        cin>>S>>T;
        mp[S+" "+T]++;
    }
    bool flag=false;
    for (auto &entry: mp){
        if (entry.second>1){
            cout<<"Yes"<<"\n";
            flag=true;
            break;
        }
    }
    if (!flag)
        cout<<"No";
}

/*
4
tanaka taro
sato hanako
tanaka taro
sato hanako
*/