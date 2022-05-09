#include<iostream>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;

const int MAXN=100001;
int dp[MAXN];

int minPossibleCost(vector<int>&heights, int N, int K){
	for(int i=2; i<=N; ++i){
		dp[i]=INF;
		for(int j=i-1; j>=max(i-K, 1); --j){
			dp[i]=min(dp[i], dp[j]+abs(heights[i]-heights[j]));
		}
	}
	return dp[N];
}

int dfs(vector<int>&heights, int N, int K, int idx, vector<int>&memo){
    if(idx>N) return 0;
    if(memo[idx]!=-1) return memo[idx];
	int curans=INT_MAX;
	for(int i=1; i<=K; ++i){
    	int curjmp=idx+i<=N?abs(heights[idx]-heights[idx+i])+dfs(heights, N, K, idx+i, memo):INT_MAX;
		curans=min(curans, curjmp);
	} 
	return (memo[idx]=curans);
}

int main(){
	int N;
	cin>>N;
	int K;
	cin>>K;
	vector<int>heights(N+1, 0);
    vector<int>memo(N+1, -1);
	for(int i=1; i<=N; ++i){
		cin>>heights[i];
	}
	int ans=dfs(heights, N, K, 1, memo);
	//int ans=minPossibleCost(heights, N, K);
	cout<<ans<<endl;
}