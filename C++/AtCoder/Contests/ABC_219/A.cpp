#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int, string>mp;
    for(int i=0; i<40; ++i){
        mp[i]="Novice";
    }
    for(int i=40; i<70; ++i){
        mp[i]="Intermediate";
    }
    for(int i=70; i<90; ++i){
        mp[i]="Advance";
    }
    for(int i=90; i<=100; ++i){
        mp[i]="Expert";
    }
    int X;
    cin>>X;
    if(X>=90&&X<=100){
        cout<<"expert";
    } else{
        string tmp=mp[X];
        int ans=0;
        while(true){
            if(mp[X++]!=tmp){
                break;
            }
            ans++;
        }
        cout<<ans;
    }
}