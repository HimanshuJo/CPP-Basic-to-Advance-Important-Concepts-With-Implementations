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
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>spnd(n), has(n);
        for(int i=0; i<n; ++i){
            cin>>spnd[i];
        }
        for(int i=0; i<n; ++i){
            cin>>has[i];
        }
        vector<ll>diff;
        for(int i=0; i<n; ++i){
            diff.push_back(has[i]-spnd[i]);
        }
        sort(diff.begin(), diff.end(), greater<int>());
        int j=n-1, count=0;
        for(int i=0; i<n; ++i){
            while(j>i&&diff[i]+diff[j]<0){
                --j;
            }
            if(j<=i) break;
            count++, --j;
        }
        cout<<count<<endl;
    }
}