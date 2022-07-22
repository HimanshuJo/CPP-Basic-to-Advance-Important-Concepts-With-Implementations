#include<iostream>
#include<vector>
#include<map>
using namespace std;

// T: O(2^(n+m)), S: O(n+m)
int gridTravelerSp(int m, int n){
	if(m==0||n==0) return 0;
	if(m==1&&n==1) return 1;
	return (gridTravelerSp(m-1, n)+gridTravelerSp(m, n-1));
}

// T: O(m*n), S: O(n+m)
int gridTravelerDp(int m, int n, map<pair<int, int>, int>&memo){
	if(m==0||n==0) return 0;
	if(m==1&&n==1) return 1;
	if(memo.find({m, n})!=memo.end()) return memo[{m, n}];
	return memo[{m, n}]=gridTravelerDp(m-1, n, memo)+gridTravelerDp(m, n-1, memo);
}

// T: O(m*n), S: O(n+m)
int gridTravelerTab(int m, int n){
	int dp[m+1][n+1];
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j){
			dp[i][j]=0;
		}
	}
	dp[1][1]=1;
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j){
			if(j+1<=n) dp[i][j+1]+=dp[i][j];
			if(i+1<=m) dp[i+1][j]+=dp[i][j];
		}
	}
	return dp[m][n];
}

int main(){
	map<pair<int, int>, int>memo;
	//int ans1=gridTravelerSp(2, 3);
	int ans2=gridTravelerDp(20, 30, memo);
	int ans3=gridTravelerTab(20, 30);
	//cout<<ans1<<"\n";
	cout<<ans2<<"\n";
	cout<<ans3<<"\n";
}
