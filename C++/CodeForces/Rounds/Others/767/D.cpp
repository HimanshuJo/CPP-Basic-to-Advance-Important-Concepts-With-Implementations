// D. Peculiar Movie Preferences
/*
Mihai plans to watch a movie. He only likes palindromic movies, so he wants to skip some 
(possibly zero) scenes to make the remaining parts of the movie palindromic.

You are given a list s of n non-empty strings of length at most 3, representing the scenes of Mihai's movie.

A subsequence of s is called awesome if it is non-empty and the concatenation of the
strings in the subsequence, in order, is a palindrome.

Can you help Mihai check if there is at least one awesome subsequence of s?

A palindrome is a string that reads the same backward as forward, for example strings "z", "aaa", "aba", "abccba" are palindromes,
but strings "codeforces", "reality", "ab" are not.

A sequence a is a non-empty subsequence of a non-empty sequence b if a can be obtained from b by deletion of several (possibly zero, but not all) elements.

Input
The first line of the input contains a single integer t (1<=t<=100) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n (1<=n<=10^5) — the number of scenes in the movie.

Then follows n lines, the i-th of which containing a single non-empty string si of length at most 3, consisting of lowercase Latin letters.

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, print "YES" if there is an awesome subsequence of s, or "NO" otherwise (case insensitive).

Example
input
6
5
zx
ab
cc
zx
ba
2
ab
bad
4
co
def
orc
es
3
a
b
c
3
ab
cd
cba
2
ab
ab

output
YES
NO
NO
YES
YES
NO
Note
In the first test case, an awesome subsequence of s is [ab,cc,ba]
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

bool isPalin(string str){
	int len=str.length();
	for(int i=0; i<len/2; ++i){
		if(str[i]!=str[len-i-1]){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<string>s1, s2;
		bool flag=false;
		for(int i=0; i<n; ++i){
			string s;
			cin>>s;
			if(flag){
				continue;
			}
			if(isPalin(s)){
				flag=true;
				continue;
			}
			string scpy=s;
			reverse(scpy.begin(), scpy.end());
			if(s.length()==2){
				if(s1.find(scpy)!=s1.end()){
				    flag=true;
					continue;
				}
				if(s2.find(scpy)!=s2.end()){
				    flag=true;
					continue;
				}
				s1.insert(s);
			} else if(s.length()==3){
				if(s2.find(scpy)!=s2.end()){
				    flag=true;
					continue;
				}
				if(s1.find(scpy.substr(0, 2))!=s1.end()){
					flag=true;
					continue;
				}
				s2.insert(s.substr(0, 2));
				s2.insert(s);
			}
		}
		if(!flag) cout<<"NO\n";
		else cout<<"YES\n";
	}
}

