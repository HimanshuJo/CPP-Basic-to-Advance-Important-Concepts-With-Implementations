/*
Type1:

#include<bits/stdc++.h>
using namespace std;

template<class T>
void printQueue(T& q)
{
    while (!q.empty())
    {
        cout << q.top() << endl;
        q.pop();
    }
}

struct CustomCompare
{
    bool operator()(const int& lhs, const int& rhs)
    {
        return lhs > rhs;
    }
};

int main()
{
    std::priority_queue<int, std::vector<int>, CustomCompare> q;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    printQueue(q);
}
*/
/*
Type2:

#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct custComp{
    const bool operator()(const pair<int, int>A, const pair<int, int>B) {
        return A.second==B.second?A.first>B.first:A.second>B.second;
    }
};

int main(){
    vector<vector<int>>vec{{1, 1}, {2, 4},  {5, 2}, {8, 3}, {7, 1}};
    priority_queue<pair<int, int>, vector<pair<int, int>>, custComp>pq;

    for(auto &vals: vec){
        pq.push({vals[0], vals[1]});
    }
    while(!pq.empty()){
        pair<int, int>curr=pq.top();
        cout<<curr.first<<" "<<curr.second<<endl;
        pq.pop();
    }
}
*/

/*
1 1
7 1
5 2
8 3
2 4
*/

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
