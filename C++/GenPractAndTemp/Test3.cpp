#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int dfs(vector<vector<int>>&gr, unordered_map<int, int>&mp, int curvert){
	if(mp.find(curvert)!=mp.end()) return mp[curvert];
	int count=0;
	for(auto &child: gr[curvert]){
		count=max(count, 1+dfs(gr, mp, child));
	}
	return mp[curvert]=count;
}

int main(){
	int N, M;
	cin>>N>>M;
	vector<vector<int>>gr(N+1);
	unordered_map<int, int>mp;
	for(int i=0; i<M; ++i){
		int src, dest;
		cin>>src>>dest;
		gr[src].push_back(dest);
	}
	int ans=INT_MIN;
	for(int i=1; i<=N; ++i){
		if(mp.find(i)==mp.end()){
			dfs(gr, mp, i);
			ans=max(ans, mp[i]);
		}
	}
	cout<<ans;
}
