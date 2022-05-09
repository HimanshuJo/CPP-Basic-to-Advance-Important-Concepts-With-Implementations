#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void printSubStr(string str, int low, int high){
	for(int i=low; i<=high; ++i){
		cout<<str[i];
	}
}

int longestPalSubstr(string str){
	int n=str.size();
	bool dp[n][n];
	memset(dp, 0, sizeof(dp));
	int maxLen=1;
	for(int i=0; i<n; ++i){
		dp[i][i]=true;
	}
	int start=0;
	for(int i=0; i<n-1; ++i){
		if(str[i]==str[i+1]){
			dp[i][i+1]=true;
			start=i;
			maxLen=2;
		}
	}
	for(int k=3; k<=n; ++k){
		for(int i=0; i<n-k+1; ++i){
			int j=i+k-1;
			if(dp[i+1][j-1]&&(str[i]==str[j])){
				dp[i][j]=true;
				if(k>maxLen){
					start=i;
					maxLen=k;
				}
			}
		}
	}
	printSubStr(str, start, start+maxLen-1);
	cout<<endl;
	return maxLen;
}

int main(){
	string s="dasdasMADAMasdasda";
	int maxxLen=longestPalSubstr(s);
	cout<<maxxLen<<"\n";
}