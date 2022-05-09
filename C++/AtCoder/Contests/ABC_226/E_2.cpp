#include<bits/stdc++.h>
using namespace std;

int mod=998244353;
int x, y;

int dfs(int idx, vector<vector<int>>&gr, set<int>&seen){
	x++;
	int currSz=gr[idx].size();
	y+=currSz;
	seen.insert(idx);
	for(int i=0; i<gr[idx].size(); ++i){
		auto it=seen.find(gr[idx][i]);
		if(it==seen.end()){
			dfs(gr[idx][i], gr, seen);
		}
	}
	return currSz;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin>>N>>M;
	vector<vector<int>>gr(N+1);
	for(int i=0; i<M; ++i){
		int u, v; 
		cin>>u>>v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	set<int>seen;
	if(N<=2) cout<<0<<"\n";
	else{
		long long ans=1;
		for(int i=0; i<N; ++i){
			auto it=seen.find(i+1);
			if(it==seen.end()){
				x=0, y=0;
				dfs(i+1, gr, seen);
				if(y==2*x){
					ans*=2;
					ans%=mod;
				} else ans=0;
			}
		}
		cout<<(ans%mod)<<"\n";
	}
}
