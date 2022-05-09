#include<iostream>
#include<vector>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n=10;
	vector<int>in(n);
	for(int i=0; i<n; ++i){
		cin>>in[i];
	}
	ll ans=INT_MAX;
	int fnIdx=0;
	for(int i=0; i<n; ++i){
		int curr=in[i];
		ll currans=0;
		for(int x=0; x<n; ++x){
			currans+=abs(in[x]-curr);
		}
		//cout<<currans<<"\n";
		//cout<<"-------\n";
		if(currans<ans){
			ans=currans;
			fnIdx=i;
		}
	}
	cout<<ans<<"\n";
}
