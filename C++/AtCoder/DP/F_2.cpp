// F - LCS
/*
You are given strings s and t. Find one longest string that is a subsequence of both s and t.

A subsequence of a string x is the string obtained by removing zero or more characters from x and
concatenating the remaining characters without changing the order.

Constraints
s and t are strings consisting of lowercase English letters.
1<=|s|,|t|<=3000
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

int dfs(int M, int N, string &S, string &T, vector<vector<int>>&memo){
	if(M<0||N<0) return 0;
	if(memo[M][N]!=-1) return memo[M][N];
	if(S[M]==T[N]) return memo[M][N]=1+dfs(M-1, N-1, S, T, memo);
	return memo[M][N]=max(dfs(M-1, N, S, T, memo), dfs(M, N-1, S, T, memo));
}

void build(int M, int N, string S, string T, stack<char>&stk, vector<vector<int>>&memo){
	if(M<0||N<0) return;
	if(S[M]==T[N]){
		stk.push(S[M]);
		build(M-1, N-1, S, T, stk, memo);
		return;
	}
	if(dfs(M-1, N, S, T, memo)>dfs(M, N-1, S, T, memo)){
		build(M-1, N, S, T, stk, memo);
	} else{
		build(M, N-1, S, T, stk, memo);
	}
}

int main(){
	string S, T;
	cin>>S>>T;
	int M=S.size();
	int N=T.size();
	vector<vector<int>>memo(M+1, vector<int>(N+1, -1));
	stack<char>stk;
	build(M-1, N-1, S, T, stk, memo);
	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}
}