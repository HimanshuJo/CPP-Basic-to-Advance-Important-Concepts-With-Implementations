#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, h;
        cin>>n>>h;
        vector<int>A(n);
        for(int i=0; i<n; ++i){
            cin>>A[i];
        }
        int ans=0;
        sort(A.begin(), A.end(), greater<>());
        if(A[0]>h){
            cout<<1<<"\n";
            continue;
        } else{
            int sm=A[0]+A[1];
            int quo=h/sm;
            int nwH=h-(sm*quo);
            int rem=h%sm;
            ans+=(quo*2);
            int counter=0;
            while(nwH>0){
                ans++;
                if(counter%2==0)
                    nwH-=A[0];
                else
                    nwH-=A[1];
                counter++;
            }   
        }
        cout<<ans<<"\n";
    }
}