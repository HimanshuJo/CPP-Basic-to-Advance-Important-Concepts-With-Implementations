#include<bits/stdc++.h>
using ll=long long;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll x0, n;
		cin>>x0>>n;
		ll ans=0;
		ll curr=x0;
		int rem=n%4;
		if(x0%2==0){
			if(rem==1){
				ans=curr-n;
			}
			else if(rem==2){
				ans=curr+1;
			}
			else if(rem==3){
				ans=curr+(n+1);
			}
			else if(rem==0){
				ans=curr;
			}
			cout<<ans<<"\n";
		} else{
			if(rem==1){
				ans=curr+n;
			}
			else if(rem==2){
				ans=curr-1;
			}
			else if(rem==3){
				ans=curr-(n+1);
			}
			else if(rem==0){
				ans=curr;
			}
			cout<<ans<<"\n";
		}
	}
}
