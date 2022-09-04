#include<iostream>
#include<vector>
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n+1, 0);
        for(int i=1; i<=n; ++i){
            cin>>A[i];
        }
        ll ans=0;
        for(int i=1; i<=n; ++i){
            ll temp=min(A[i], max(A[i-1], A[i+1]));
            ans+=A[i]-temp+abs(temp-A[i-1]);
            cout<<"A[i]: "<<A[i]<<" Temp: "<<temp<<" Ans: "<<ans<<endl;
            A[i]=temp;
        }
        cout<<"\n-------\n";
        cout<<ans+A[n]<<endl;
    }
}