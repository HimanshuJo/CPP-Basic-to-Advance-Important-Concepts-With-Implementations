#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<int, string>mp;
    string s1, s2, s3;
    cin>>s1>>s2>>s3;
    mp[1]=s1;
    mp[2]=s2;
    mp[3]=s3;
    string T;
    cin>>T;
    string res="";
    for(int i=0; i<T.length(); ++i){
        int curr=T[i]-'0';
        res+=mp[curr];
    }
    cout<<res;
}
