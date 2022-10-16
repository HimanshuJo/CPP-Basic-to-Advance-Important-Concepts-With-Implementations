#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#include<unordered_map>
#define endl "\n"
using ll=long long;
using namespace std;

int calGCD(int A, int B){
    if(B==0) return A;
    return calGCD(B, A%B);
}

bool areCoprime(int A, int B){
    return calGCD(A, B)==1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n);
        unordered_map<int, int>mp;
        for(int i=0; i<n; ++i){
            cin>>in[i];
            mp[in[i]]=i;
        }
        vector<int>all;
        for(auto &entries: mp){
            all.push_back(entries.second);
        }
        sort(all.begin(), all.end());
        int sz=all.size();
        int curmaxx=0;
        for(int i=sz-1; i>=0; --i){
            for(int j=i; j>=0; --j){
                if(areCoprime(in[all[i]], in[all[j]])){
                    curmaxx=max(curmaxx, all[i]+1+all[j]+1);
                    break;
                }
            }
        }
        cout<<(curmaxx==0?-1:curmaxx)<<endl;
    }
}