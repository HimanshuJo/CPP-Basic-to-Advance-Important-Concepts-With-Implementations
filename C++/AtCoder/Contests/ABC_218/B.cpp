// Qwerty
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int, char>mp;
    char strt='a';
    for(int i=1; i<=26; ++i){
        mp[i]=strt;
        strt++;
    }
    string s="";
    for(int i=0; i<26; ++i){
        int temp;
        cin>>temp;
        s+=mp[temp];
    }
    cout<<s;
}