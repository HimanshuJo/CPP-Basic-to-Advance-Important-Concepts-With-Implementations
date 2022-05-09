/*
Number of ways to construct a target string given an array of strings
*/

#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;

// T: O((n^m)*m), S: O(m^2)
int countConstruct(string target, vector<string>&wordBank){
	if(target=="") return 1;
	int totalCnt=0;
	for(auto &word: wordBank){
		size_t strIt=target.find(word);
		if(strIt!=string::npos&&strIt==0){
			string suffix=target.substr(word.length(), target.length()-word.length());
			int numWaysForRest=countConstruct(suffix, wordBank);
			totalCnt+=numWaysForRest;
		}
	}
	return totalCnt;
}

// T: O(n*m^2), S: O(m^2)
int countConstructDp(string target, vector<string>&wordBank, map<string, int>&memo){
	if(target=="") return 1;
	if(memo.find(target)!=memo.end()) return memo[target];
	int totalCnt=0;
	for(auto &word: wordBank){
		size_t strIt=target.find(word);
		if(strIt!=string::npos&&strIt==0){
			string suffix=target.substr(word.length(), target.length()-word.length());
			totalCnt+=countConstructDp(suffix, wordBank, memo);
			//int numWaysForRest=countConstructDp(suffix, wordBank, memo);
			//totalCnt+=numWaysForRest;
		}
	}
	return memo[target]=totalCnt;
}

// T: O(n*m^2). S: O(m^2)
int countConstructTab(string target, vector<string>&wordBank){
	int dp[target.length()+1];
	memset(dp, 0, sizeof(dp));
	dp[0]=1;
	for(int i=0; i<=target.length(); ++i){
		for(auto &word: wordBank){
			string toChk=target.substr(i, word.length());
			if(toChk.compare(word)==0){
				dp[i+word.length()]+=dp[i];
			}
		}
	}
	return dp[target.length()];
}

int main(){
	vector<string>wordBank{"ab", "abc", "abcdef", "def"};
	string target="abcdef";
	int ans=countConstruct(target, wordBank);
	cout<<ans<<"\n";
	cout<<"-------\n";
	map<string, int>memo;
	vector<string>wordBank2{"ee", "eee", "eeee", "eeeee", "eeeeeee", "eeeeeeee"};
	string target2="eeeeeeeeeeeeeeeeeeeeee";
	int ans2=(countConstructDp(target2, wordBank2, memo));
	cout<<ans2<<"\n";
	int ans3=(countConstructTab(target2, wordBank2));
	cout<<ans3<<"\n";
}
