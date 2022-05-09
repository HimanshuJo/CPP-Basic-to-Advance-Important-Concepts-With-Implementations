/*
Is it possible to construct the target string given an array of strings
*/

#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;

// T: O((len(wordbank)^target)*target), S: O(target^2)
bool canConstruct(string target, vector<string>&wordBank){
	if(target=="") return true;
	for(auto &word: wordBank){
		size_t strIt=target.find(word);
		if(strIt!=string::npos&&strIt==0){
			string suffix=target.substr(word.length(), target.length()-word.length());
			if(canConstruct(suffix, wordBank)){
				return true;
			}
		}
	}
	return false;
}

// T: O(len(wordBank)*target^2), S: O(target^2)
bool canConstructDp(string target, vector<string>&wordBank, map<string, bool>&memo){
	if(target=="") return true;
	if(memo.find(target)!=memo.end()) return memo[target];
	for(auto &word: wordBank){
		size_t strIt=target.find(word);
		if(strIt!=string::npos&&strIt==0){
			string suffix=target.substr(word.length(), target.length()-word.length());
			if(canConstructDp(suffix, wordBank, memo)){
				return memo[target]=true;
			}
		}
	}
	return memo[target]=false;
}

// T: O(len(wordBank)*target^2), S: O(target^2)
bool canConstructTab(string target, vector<string>&wordBank){
	bool dp[target.length()+1];
	memset(dp, false, sizeof(dp));
	dp[0]=true;
	for(int i=0; i<=target.length(); ++i){
		if(dp[i]){
			for(auto &word: wordBank){
				string toChk=target.substr(i, word.length());
				if(toChk.compare(word)==0){
					dp[i+word.length()]=true;
				}
			}
		}
	}
	return dp[target.length()];
}


int main(){
	vector<string>wordBank{"ab", "abc", "abcd", "def"};
	string target="abcdef";
	vector<string>wordBank2={"e", "ee", "eee", "eeee", "eeeee", "eeeeee"};
	map<string, bool>memo;
	string target2="eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
	bool ans=canConstruct(target, wordBank);
	cout<<(ans==1?"true":"false")<<"\n";
	cout<<"-------\n";
	bool ans2=canConstructDp(target2, wordBank2, memo);
	cout<<(ans2==1?"true":"false")<<"\n";
	cout<<"-------\n";
	bool ans3=canConstructTab(target2, wordBank2);
	cout<<(ans3==1?"true":"false")<<"\n";
    
}
