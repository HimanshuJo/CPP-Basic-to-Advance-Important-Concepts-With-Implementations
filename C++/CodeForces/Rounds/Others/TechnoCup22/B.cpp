#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        unordered_set<int>st;
        for(int i=0; i<m; ++i){
            int a, b, c;
            cin>>a>>b>>c;
            st.insert(b);
        }
        int mssNum;
        for(int i=0; i<n; ++i){
            auto it=st.find(i+1);
            if(it==st.end()){
                mssNum=i+1;
            }
        }
        for(int i=1; i<=n; ++i){
            if(i!=mssNum){
                cout<<mssNum<<" "<<i<<"\n";
            }
        } 
    }  
}