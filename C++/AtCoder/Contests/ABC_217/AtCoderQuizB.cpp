#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S1, S2, S3;
    unordered_map<string, string>mp;
    mp.insert(pair<string, string>("ABC", "ABC"));
    mp.insert(pair<string, string>("ARC", "ARC"));
    mp.insert(pair<string, string>("AGC", "AGC"));
    mp.insert(pair<string, string>("AHC", "AHC"));
    cin>>S1>>S2>>S3;
    vector<string>tmp;
    tmp.push_back(S1);
    tmp.push_back(S2);
    tmp.push_back(S3);
    for (auto &entry: mp){
        auto it=find(tmp.begin(), tmp.end(), entry.first);
        if (it==tmp.end()){
            cout<<entry.first;
        }
    }
}