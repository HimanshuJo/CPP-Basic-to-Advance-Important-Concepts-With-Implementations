#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int sz=s.size();
        unordered_map<char, vector<int>>mp;
        for(int i=0; i<sz; ++i){
            mp[s[i]].push_back(i);
        }
        int dir=s[0]<s[sz-1]?1:-1;
        vector<int>ans;
        for(char ch=s[0]; ch!=s[sz-1]+dir; ch+=dir){
            for(auto &vals: mp[ch]){
                ans.push_back(vals);
            }
        }
        int fncost=0;
        int anssz=ans.size();
        for(int i=1; i<anssz; ++i){
            fncost+=abs(s[ans[i]]-s[ans[i-1]]);
        }
        cout<<fncost<<" "<<ans.size()<<endl;
        for(int i=0; i<anssz; ++i){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
}