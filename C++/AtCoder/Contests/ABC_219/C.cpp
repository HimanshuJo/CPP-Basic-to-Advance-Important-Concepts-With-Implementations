#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int>mp;

struct custComp
{
    bool operator()(const string& lhs, const string& rhs)
    {
        int sz=min(lhs.length(), rhs.length());
        for(int i=0; i<sz; ++i){
            if(mp[lhs[i]]!=mp[rhs[i]])
                return mp[lhs[i]]>mp[rhs[i]];
        }
        return lhs.length()>rhs.length();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string X;
    cin>>X;
    int N;
    cin>>N;
    for(int i=1; i<=26; ++i){
        mp[X[i]]=i;
    }
    priority_queue<string, vector<string>, custComp>pq;
    for(int i=0; i<N; ++i){
        string in;
        cin>>in;
        pq.push(in);
    }
    while(!pq.empty()){
        cout<<pq.top();
        cout<<"\n";
        pq.pop();
    }
    mp.clear();
}
