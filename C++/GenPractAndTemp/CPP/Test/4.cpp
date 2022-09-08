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
        string s;
        cin>>s;
        int ans=1;
        for(int i=1; i<2*n; ++i){
            if(s[i]=='('&&s[i-1]=='('){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}