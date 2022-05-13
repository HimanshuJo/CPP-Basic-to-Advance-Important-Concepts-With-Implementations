#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using ll=long long;

#define V_MAX 1e3
#define W_MAX 1e9

int dfs(vector<vector<int>>&in, int N, int idx, int curval,
       vector<vector<int>>&memo, vector<vector<int>>&seen){
	if(idx>N) return W_MAX;
	if(curval<=0) return 0;
	if(seen[idx][curval]==1) return memo[idx][curval];
	seen[idx][curval]=1;
	return (memo[idx][curval]=min(dfs(in, N, idx+1, curval, memo, seen),
	                              in[idx][0]+
								 dfs(in, N, idx+1, curval-in[idx][1], memo, seen)));
}

int main(){
	int N, W;
	cin>>N>>W;
	vector<vector<int>>memo(N+1, vector<int>(1e3+1, -1));
	vector<vector<int>>seen(N+1, vector<int>(1e3+1, -1));
	vector<vector<int>>in(N, vector<int>(2, 0));
	for(int i=0; i<N; ++i){
		for(int j=0; j<2; ++j){
			cin>>in[i][j];
		}
	}
	bool flag=false;
	for(int val=V_MAX; val>=0; --val){
		if(dfs(in, N, 0, val, memo, seen)<=W){
			flag=true;
			cout<<val;
			break;
		}
	}
	if(!flag)
		cout<<0;
}