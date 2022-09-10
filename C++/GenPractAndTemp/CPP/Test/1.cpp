#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        vector<pair<int, int>>allcombs;
        for(int i=0; i<n; ++i){
            allcombs.push_back({in[i], i});
        }
        sort(allcombs.begin(), allcombs.end());
        auto it=allcombs.rbegin();
        int ans=(it->second)+1;
        cout<<ans<<"\n";
    }
}