#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A, B, C;
    cin>>A>>B>>C;
    int ans=-1;
    for(int i=B; i>=A; --i){
        if(i%C==0){
            ans=i;
            break;
        }
    }
    cout<<ans;
}