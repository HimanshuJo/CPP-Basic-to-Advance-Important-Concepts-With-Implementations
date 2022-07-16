/*
Given a target string and a vector of string as WordBank. Construct all ways to form the
target string from the strings in the wordBank.

Space between the letters of the constructed target string is allowed

E.g: target="homantak" wordBank=["homan", "ho", "man", "hom", "homant", "homantak", "tak"]

Output:

homan tak
ho man tak
homantak

*/
#include<vector>
#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

// T: O(n^m), S: O(n^m)
vector<vector<string>> allConstruct(string target, vector<string>&wordBank, map<string, vector<vector<string>>>&memo){
	if(target=="") return {{}};
	if(memo.find(target)!=memo.end()) return memo[target];
	vector<vector<string>>res;
	for(int i=0; i<wordBank.size(); ++i){
		string word=wordBank[i];
		size_t strIt=target.find(word);
		if(strIt!=string::npos&&strIt==0){
			string suffix=target.substr(word.length(), target.length()-word.length());
			vector<vector<string>>curres=allConstruct(suffix, wordBank, memo);
			for(auto &vecEntries: curres)
				vecEntries.push_back(word);	
			for(auto &vecEntries: curres)
				res.push_back(vecEntries);
		}
	}
	return memo[target]=res;
}

// T: O(n^m), S: O(n^m)
vector<vector<string>> allConstructTab(string target, vector<string>&wordBank){
	vector<vector<vector<string>>>dp(target.length()+1);
	dp[0].insert(dp[0].end(), {{}});
	for(int i=0; i<=target.length(); ++i){
		for(auto &word: wordBank){
			string toChk=target.substr(i, word.length());
			if(toChk.compare(word)==0){
				vector<vector<string>>currComb=dp[i];
				for(auto &entries: currComb){
					entries.push_back(word);
				}
				for(auto &entries: currComb){
					dp[i+word.length()].push_back(entries);
				}
				//dp[i+word.length()].insert(dp[i+word.length()].end(), currComb.begin(), currComb.end());
			}
		}
	}
	return dp[target.length()];
}

int main(){
	vector<string>wordBank{"purp", "p", "ur", "le", "purpl"};
	vector<string>wordBank2={"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa"};
	vector<string>wordBank3{"homan", "ho", "man", "hom", "homant", "homantak", "tak"};
	string target2="aaaaaaaaaaaaaaaaaaay";
	string target="purple";
	string target3="homantak";
	vector<string>res;
	map<string, vector<vector<string>>>memo;
	vector<vector<string>>ans=allConstruct(target3, wordBank3, memo);
	vector<vector<string>>ans2=allConstructTab(target3, wordBank3);
	for(auto &vals: ans){
		reverse(vals.begin(), vals.end());
		for(auto &entries: vals){
			cout<<entries<<" ";
		}
		cout<<endl;
	}
	cout<<"-------\n";
	for(auto &vals: ans2){
		for(auto &entries: vals){
			cout<<entries<<" ";
		}
		cout<<endl;
	}
}

/*
Output:

homan tak
ho man tak
homantak
-------
homantak
homan tak
ho man tak

*/