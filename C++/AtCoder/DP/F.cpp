// F - LCS
/*
You are given strings s and t. Find one longest string that is a sub-sequence of both s and t.

A sub-sequence of a string x is the string obtained by removing zero or more characters from x and
concatenating the remaining characters without changing the order.

Constraints
s and t are strings consisting of lowercase English letters.
1<=|s|,|t|<=3000

Sample Input 1
axyb
abyxb

Sample Output 1 
axb
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

class Solution1{
	public:
	char* returnLngCmnSubseq(string str1, string str2, int i, int j, vector<vector<int>>&dp){
		int len=dp[i][j];
		char *res=new char[len+1];
		res[len]='\0';
		while(i>0&&j>0){
			if(str1[i-1]==str2[j-1]){
				res[len-1]=str1[i-1];
				--i, --j, --len;
			} else if(dp[i-1][j]>dp[i][j-1]){
				--i;
			} else --j;
		}
		return res;
	}

	pair<char*, int> longestCommonSubsequence(string s_tmp, string t_tmp){
		string str1=s_tmp.length()>t_tmp.length()?s_tmp:t_tmp;
		string str2=t_tmp.length()<s_tmp.length()?t_tmp:s_tmp;
		int M=str1.size();
		int N=str2.size();
		vector<vector<int>>dp(M+1, vector<int>(N+1, 0));
		for(int i=1; i<=M; ++i){
			for(int j=1; j<=N; ++j){
				if(str1[i-1]==str2[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				} else{
					dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		char *res=returnLngCmnSubseq(str1, str2, M, N, dp);
		int len=dp[M][N];
		return {res, len};
	}
};

class Solution2{
	public:

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
};

int main(){
	string s_tmp, t_tmp;
	cin>>s_tmp>>t_tmp;
	Solution1 obj1;
	Solution2 obj2;
	auto anspair=obj1.longestCommonSubsequence(s_tmp, t_tmp);
	char *res=anspair.first;
	int len=anspair.second;
	for(int i=0; i<len; ++i)
		cout<<res[i];
	cout<<endl;
	int M=s_tmp.size(), N=t_tmp.size();
	vector<vector<int>>memo(M+1, vector<int>(N+1, -1));
	stack<char>stk;
	obj2.build(M-1, N-1, s_tmp, t_tmp, stk, memo);
	while(!stk.empty()){
		cout<<stk.top();
		stk.pop();
	}
}
