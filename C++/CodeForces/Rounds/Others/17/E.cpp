#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;

const int sz=2e5+10;
int qq, n, ans, res, ptr;
vector<ll>in(sz);

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		for(int i=1; i<=n; ++i){
			cin>>in[i];
		}
		for(int i=1; i<=n; ++i){
			if(in[i]==in[i-1]) continue;
			res=0, ptr=i;
			while(ptr<=n){
				ptr=lower_bound(in.begin()+ptr+1, in.begin()+n+1, 2*in[ptr]-in[i])-in.begin();
				res++;
			}
			ans=max(ans, res);
		}
		cout<<n-ans<<"\n";
	}
}

