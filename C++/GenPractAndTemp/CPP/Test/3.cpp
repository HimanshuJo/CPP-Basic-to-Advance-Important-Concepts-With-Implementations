#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define endl "\n"
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        if(n==1){
            cout<<"YES\n";
            cout<<m<<endl;
        } else if(n>m||((m&1)==1&&(n&1)==0)){
            cout<<"NO\n";
        } else if(n==m){
            cout<<"YES\n";
            for(int i=0; i<n; ++i){
                cout<<1<<" ";
            }
            cout<<endl;
        } else if((m&1)==0&&m/2==n){
            cout<<"YES\n";
            for(int i=0; i<n; ++i){
                cout<<2<<" ";
            }
            cout<<endl;
        } else if((m&1)==0&&(n&1)==0){
            cout<<"YES\n";
            for(int i=2; i<n; ++i){
                cout<<1<<" ";
            }
            cout<<(m-n+2)/2<<" "<<(m-n+2)/2;
            cout<<endl;
        } else if((n&1)==1){
            cout<<"YES\n";
            for(int i=1; i<n; ++i){
                cout<<1<<" ";
            }
            cout<<(m-n+1)<<endl;
        } else{
            cout<<"NO\n";
        }
    }
}