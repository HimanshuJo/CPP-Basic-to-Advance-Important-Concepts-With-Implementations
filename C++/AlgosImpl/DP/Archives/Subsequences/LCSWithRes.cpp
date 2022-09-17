/*
Given two sequences, print the longest subsequence present in both of them. 
Examples: 
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3. 
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
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
	string str1="GXTXAYB";
	string str2="AGGTAB";
	int M=str1.size();
	int N=str2.size();
	vector<vector<int>>dp(M+1, vector<int>(N+1, 0));
	for(int i=1; i<=M; ++i){
		for(int j=1; j<=N; ++j){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			} else{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	for(int i=0; i<=M; ++i){
		for(int j=0; j<=N; ++j){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"-------\n";
	int res1=dp[M][N];
	cout<<res1<<endl;
	char *res=returnLngCmnSubseq(str1, str2, M, N, dp);
	int len=dp[M][N];
	for(int i=0; i<len; ++i)
		cout<<res[i];
}