#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll l, r, k;
		cin>>l>>r>>k;
		vector<ll>a(n);
		for(int i=0; i<n; ++i){
			cin>>a[i];
		}
		int ans=0;
		sort(a.begin(), a.end());
		auto it=lower_bound(a.begin(), a.end(), l);
		if(it==a.end()||a[0]>r){
			cout<<"0\n";
		} else{
			while(k>=0&&it!=a.end()){
				if((*it)>r) break;
				if(k<(*it)) break;
				k-=(*it);
				ans++;
				it++;
			}
			cout<<ans<<"\n";
		}
	}
}

