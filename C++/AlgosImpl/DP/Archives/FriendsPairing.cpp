// Friends Pairing Problem
/*
Given n friends, each one can remain single or can be paired up with some other friend. 
Each friend can be paired only once. Find out the total number of ways in which friends can 
remain single or can be paired up. 

Examples: 

Input  : n = 3
Output : 4
Explanation:
{1}, {2}, {3} : all single
{1}, {2, 3} : 2 and 3 paired but 1 is single.
{1, 2}, {3} : 1 and 2 are paired but 3 is single.
{1, 3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1, 2} and {2, 1} are considered same.

Mathematical Explanation:
The problem is simplified version of how many ways we can divide n elements into multiple groups.
(here group size will be max of 2 elements).
In case of n = 3, we have only 2 ways to make a group: 
    1) all elements are individual(1,1,1)
    2) a pair and individual (2,1)
In case of n = 4, we have 3 ways to form a group:
    1) all elements are individual (1,1,1,1)
    2) 2 individuals and one pair (2,1,1)
    3) 2 separate pairs (2,2)

For n-th person there are two choices:
1) n-th person remains single, we recur
for f(n – 1)
2) n-th person pairs up with any of the
remaining n – 1 persons. We get (n – 1) * f(n – 2)

Therefore we can recursively write f(n) as:
f(n) = f(n – 1) + (n – 1) * f(n – 2)
*/

#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<int>&memo, int N){
	if(memo[N]!=-1) return memo[N];
	if(N<=2) return memo[N]=N;
	return dfs(memo, N-1)+(N-1)*dfs(memo, N-2);
}

int friendsPairing(int N){
	vector<int>memo(N+1, -1);
	return dfs(memo, N);
}

int friendsPairing2(int N){
	vector<int>dp(N+1, 0);
	dp[0]=0, dp[1]=1, dp[2]=2;
	for(int i=3; i<=N; ++i){
		dp[i]=dp[i-1]+(i-1)*dp[i-2];
	}
	return dp[N];
}

int friendsPairing3(int N){
	int a=1, b=2, c=0;
	if(N<=2) return N;
	for(int i=3; i<=N; ++i){
		c=b+(i-1)*a;
		a=b;
		b=c;
	}
	return c;
}

int main(){
	int N=14;
	int res=friendsPairing(N);
	int res2=friendsPairing2(N);
	int res3=friendsPairing3(N);
	cout<<res3<<endl;
	cout<<res2<<endl;
	cout<<res<<endl;
}