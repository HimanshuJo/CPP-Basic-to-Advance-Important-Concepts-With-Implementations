#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		int ans=0;
		int mx=0;
		for(int i=n-1; i>=0; --i){
			if(in[i]>mx) ans++;
			mx=max(mx, in[i]);
		}
		cout<<ans-1<<"\n";
	}
}

