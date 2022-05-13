// D - Knapsack 1
/*
There are N items, numbered 1,2,...,N. For each i (1<=i<=N), Item i has a weight of wi and a value of vi

Taro has decided to choose some of the N items and carry them home in a knapsack. 
The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.

1<=N<=100
1<=W<=10^5
 
1<=wi<=W
1<=vi<=10^9
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
using ll=long long;

ll dfs(vector<vector<int>>&in, int N, int W, int idx, vector<vector<ll>>&memo){
	if(idx==N) return 0;
	if(memo[idx][W]!=-1) return memo[idx][W];
	ll excl=dfs(in, N, W, idx+1, memo);
	ll incl=0;
	ll curans=INT_MIN;
	if(W>0&&in[idx][0]<=W){
		incl+=in[idx][1]+dfs(in, N, W-in[idx][0], idx+1, memo);
	}
	curans=max(curans, max(excl, incl));
	return (memo[idx][W]=curans);
}

int main(){
	int N, W;
	cin>>N>>W;
	vector<vector<ll>>memo(N+1, vector<ll>(W+1, -1));
	vector<vector<int>>in(N, vector<int>(2, 0));
	for(int i=0; i<N; ++i){
		for(int j=0; j<2; ++j){
			cin>>in[i][j];
		}
	}
	ll ans=dfs(in, N, W, 0, memo);
	cout<<ans;
}

