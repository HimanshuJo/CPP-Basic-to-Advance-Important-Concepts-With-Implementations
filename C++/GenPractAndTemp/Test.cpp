#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;

int dfs(vector<vector<int>>&in, int N, int idx, bool smflag, bool mnflag, bool hmflag,
		vector<vector<vector<vector<int>>>>&memo){
	if(idx>=N) return 0;
	if(memo[idx][smflag][mnflag][hmflag]!=-1) return memo[idx][smflag][mnflag][hmflag];
	int curans=INT_MIN;
	int sm=0, mn=0, hm=0;
	if(!smflag){
		sm+=in[idx][0]+dfs(in, N, idx+1, true, false, false, memo);
	} 
	if(!mnflag){
		mn+=in[idx][1]+dfs(in, N, idx+1, false, true, false, memo);
	}
	if(!hmflag){
		hm+=in[idx][2]+dfs(in, N, idx+1, false, false, true, memo);
	}
	curans=max(curans, max(sm, max(mn, hm)));
	return (memo[idx][smflag][mnflag][hmflag]=curans);
}

int main(){
	int N;
	cin>>N;
	vector<vector<vector<vector<int>>>>memo(N, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
	vector<vector<int>>in(N, vector<int>(3, 0));
	for(int i=0; i<N; ++i){
		for(int j=0; j<3; ++j){
			cin>>in[i][j];
		}
	}
	int ans=dfs(in, N, 0, false, false, false, memo);
	cout<<ans;
}