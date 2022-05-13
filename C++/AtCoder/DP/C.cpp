// C - Vacation
/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1≤i≤N), 
Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
	
	1≤N≤10^5
 
	1≤ai,bi,ci≤10^4
*/

/*
Solution2: // 131ms

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
*/

#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;

int dfs(vector<vector<int>>&in, int N, int idx, bool smflag, bool mnflag, bool hmflag,
		map<tuple<int, bool, bool, bool>, int>&memo){
	if(idx>=N) return 0;
	tuple<int, bool, bool, bool>tmp(idx, smflag, mnflag, hmflag);
	if(memo.find(tmp)!=memo.end()) return memo[tmp];
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
	return memo[tmp]=curans;
}

int main(){
	int N;
	cin>>N;
	map<tuple<int, bool, bool, bool>, int>memo;
	vector<vector<int>>in(N, vector<int>(3, 0));
	for(int i=0; i<N; ++i){
		for(int j=0; j<3; ++j){
			cin>>in[i][j];
		}
	}
	int ans=dfs(in, N, 0, false, false, false, memo);
	cout<<ans;
}