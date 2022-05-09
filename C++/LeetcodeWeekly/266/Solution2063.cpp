#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		long long countVowels(string word) {
			long long cnt=0;
			long long n=word.length();
			unordered_map<char, char>mp;
			mp['a']='a';
			mp['e']='e';
			mp['i']='i';
			mp['o']='o';
			mp['u']='u';
			for(int i=0; i<word.length(); ++i){
				auto it=mp.find(word[i]);
				if(it!=mp.end()){
					cnt+=(n-i)*(i+1);
				}
			}
			return cnt;
		}
};
