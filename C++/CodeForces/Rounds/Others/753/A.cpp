#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		unordered_map<char, int>mp;
		for(int i=1; i<=26; ++i){
			mp[s[i-1]]=i;
		}
		string in;
		cin>>in;
		int ans=0;
		for(int i=0; i<in.length()-1; ++i){
			ans+=abs(mp[in[i]]-mp[in[i+1]]);
		}
		cout<<ans<<"\n";
	}
}
