#include<iostream>
#include<vector>
#include<map>
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
		vector<int>in(n);
		multimap<int, int, greater<int>>mp;
		for(int i=0; i<n; ++i){
			cin>>in[i];
			mp.insert(make_pair(in[i], i));
		}
		ll ans=0;
		vector<int>res(n+1);
		res[0]=0;
		ll x=-1;
		ll y=1;
		ll counter=0;
		for(auto &entry: mp){
			int coord=entry.second;
			int val=entry.first;
			coord++;
			if(counter%2==0){
				res[coord]=x;
				ans+=(2*(abs(0-x))*val);
				x-=1;
			} else{
				res[coord]=y;
				ans+=(2*(abs(0-y))*val);
				y+=1;
			}
			counter++;
		}
		cout<<ans<<"\n";
		for(auto &vals: res){
			cout<<vals<<" ";
		}
		cout<<"\n";
	}
}

