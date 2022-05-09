#include<bits/stdc++.h>
using namespace std;

int longestPalSubstr(string str){
	int n=str.size();
	int maxLen=1, start=0;
	for(int i=0; i<str.length(); ++i){
		for(int j=i; j<str.length(); ++j){
			int flag=1;
			for(int k=0; k<(j-i+1)/2; ++k){
				if(str[i+k]!=str[j-k]){
					flag=0;
				}
				if(flag&&(j-i+1)>maxLen){
					start=i;
					maxLen=j-i+1;
				}
			}
		}
	}
	return maxLen;
}

int main(){
	string s="MADAM";
	int len=longestPalSubstr(s);
	cout<<len<<endl;
}