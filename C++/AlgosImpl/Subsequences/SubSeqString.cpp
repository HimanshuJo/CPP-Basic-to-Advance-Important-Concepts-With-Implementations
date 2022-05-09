/* Generate all distinct subsequences of a string
	
	E.g. string input="abba"
		 
		 Output:
			{}
			a
			aa
			ab
			aba
			abb
			abba
			b
			ba
			bb
			bba
*/

#include <bits/stdc++.h>
using namespace std;

/*
Solution 2:

set<string> st;

void subsequence(string str)
{
	for (int i = 0; i < str.length(); i++) {
		for (int j = str.length(); j > i; j--) {
			string sub_str = str.substr(i, j);
			st.insert(sub_str);
			for (int k = 1; k < sub_str.length(); k++) {
				string sb = sub_str;
				sb.erase(sb.begin() + k);
				subsequence(sb);
			}
		}
	}
}

int main()
{
	string s = "ababccccc";
	subsequence(s);
	for (auto i : st)
		cout << i <<endl;
	cout << endl;
	return 0;
}

*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void genAllSubSeq(string&str, int n, int idx, set<string>&allSubseq, string&subseq){
	if(idx==n){
		allSubseq.insert(subseq);
		if(subseq.size()==0){
			allSubseq.insert({});
		}
		return;
	}
	subseq.push_back(str[idx]);
	genAllSubSeq(str, n, idx+1, allSubseq, subseq);
	subseq.pop_back();
	genAllSubSeq(str, n, idx+1, allSubseq, subseq);
}

int main(){
	string str="abba";
	int n=str.size();
	int idx=0;
	set<string>allSubseq;
	string subseq="";
	genAllSubSeq(str, n, idx, allSubseq, subseq);
	for(auto &vals: allSubseq){
		cout<<vals;
		cout<<endl;
	}
}