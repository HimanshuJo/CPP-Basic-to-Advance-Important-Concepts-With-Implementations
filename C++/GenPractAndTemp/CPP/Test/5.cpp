#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>in(n, 0);
        for(int i=0; i<n; ++i){
            cin>>in[i];
        }
        vector<int>temp=in;
        sort(temp.begin(), temp.end());
        int res=INT_MIN;
        int maxx=temp[n-1];
        int maxidx=0;
        for(int i=0; i<n; ++i){
            if(in[i]==maxx){
                maxidx=i;
            }
        }
        for(int i=0; i<=maxidx; ++i){
            res=max(res, maxx-in[i]);
        }
        for(int i=maxidx; i<n; ++i){
            res=max(res, maxx-in[i]);
        }
        cout<<res<<"\n";
    }
}