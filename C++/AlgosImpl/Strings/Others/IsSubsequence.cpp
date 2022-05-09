/*
Check is a smaller string is a subsequence of a longer string
*/

#include<string>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

int is_subsequence(char smallerStr[], char longerStr[], int smsz, int lngsz, vector<vector<int>>&memo){
	if(smsz==0) return 1;
	if(lngsz==0) return 0;
	if(memo[smsz][lngsz]!=-1) return memo[smsz][lngsz];
	if(smallerStr[smsz-1]==longerStr[lngsz]) return memo[smsz][lngsz]=is_subsequence(smallerStr, longerStr, smsz-1, lngsz-1, memo);
	return memo[smsz][lngsz]=is_subsequence(smallerStr, longerStr, smsz, lngsz-1, memo);
}


int main(){
	char smallerStr[]="egks";
	char longerStr[]="geeksforgeeks";
	int smsz=strlen(smallerStr);
	int lngsz=strlen(longerStr);
	vector<vector<int>>memo(smsz+1, vector<int>(lngsz+1, -1));
	is_subsequence(smallerStr, longerStr, smsz, lngsz, memo)?cout<<"YES\n":cout<<"NO\n";
}