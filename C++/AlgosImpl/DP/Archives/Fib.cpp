#include<vector>
#include<iostream>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;
using ll=long long;

// T: O(2^N), S: O(N)
ll fibSp(int N){
	if(N<=2) return 1;
	return fibSp(N-1)+fibSp(N-2);
}

// T: O(N), S: O(N)
ll fibDp(int N, map<int, ll>&memo){
	if(N<=2) return 1;
	if(memo.find(N)!=memo.end()) return memo[N];
	return memo[N]=fibDp(N-1, memo)+fibDp(N-2, memo);
}

// Tabulation
// T: O(N), S: O(N)
ll fibTab(int N){
	ll dp[N+1];
	memset(dp, 0, sizeof(dp));
	dp[1]=1;
	for(int i=0; i<=N; ++i){
		dp[i+1]+=dp[i];
		dp[i+2]+=dp[i];
	}
	return dp[N];
}

// T: O(log N), S: O(1)
double fib(int N){
	double phi=(1+sqrt(5))/2;
	return round(pow(phi, N)/sqrt(5));
}


int main(){
	int N=50;
	map<int, long long>memo;
	//ll ans1=fibSp(N);
	ll ans2=fibDp(N, memo);
	ll ans3=fibTab(N);
	double ans4=fib(N);
	//cout<<ans1<<"\n";
	cout<<ans2<<"\n";
	cout<<ans3<<"\n";
	cout<<ans4<<"\n";
}
