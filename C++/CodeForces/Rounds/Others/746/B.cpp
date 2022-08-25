#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int>A(n);
        for(int i=0; i<n; ++i){
            cin>>A[i];
        }
        vector<int>tmp=A;
        sort(tmp.begin(), tmp.end());
        if(tmp==A){
            cout<<"YES\n";
        } else{
            if(2*x<=n){
                cout<<"YES\n";
            } else{
                bool flag=false;
                for(int i=0; i<n; ++i){
                    if((i-x)>=0||(i+x)<n||A[i]==tmp[i]) continue;
                    else{
                        cout<<"NO\n";
                        flag=true;
                        break;
                    }
                }
                if(!flag)
                    cout<<"YES\n";
            }
        }
    }
}