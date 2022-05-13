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
using namespace std;

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

int main(){
	string s_tmp, t_tmp;
	cin>>s_tmp>>t_tmp;
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
	for(int i=0; i<len; ++i)
		cout<<res[i];
}
