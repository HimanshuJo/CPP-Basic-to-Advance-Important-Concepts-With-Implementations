// D. Palindromes Coloring
/*
You have a string s consisting of lowercase Latin alphabet letters.

You can color some letters in colors from 1 to k. It is not necessary to paint all the letters. 
But for each color, there must be a letter painted in that color.

Then you can swap any two symbols painted in the same color as many times as you want.

After that, k strings will be created, i-th of them will contain all the characters colored in the color i, 
written in the order of their sequence in the string s.

Your task is to color the characters of the string so that all the resulting k strings are palindromes, and the length of the 
shortest of these k strings is as large as possible.

Read the note for the first test case of the example if you need a clarification.

Recall that a string is a palindrome if it reads the same way both from left to right and from right to left. 
For example, the strings abacaba, cccc, z and dxd are palindromes, but the strings abab and aaabaa — are not.

Example
input
10
8 2
bxyaxzay
6 3
aaaaaa
6 1
abcdef
6 6
abcdef
3 2
dxd
11 2
abcabcabcac
6 6
sipkic
7 2
eatoohd
3 1
llw
6 2
bfvfbv

output
3
2
1
1
1
5
1
1
3
3
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
using ll=long long;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		unordered_map<char, int>mp;
		for(char ch: s){
			mp[ch]++;
		}
		ll curr=0, unpaired=0;
		for(auto &entry: mp){
			ll cnt=entry.second;
			if(cnt&1) unpaired++;
			ll d=(cnt/2);
			curr+=d;
		}
		ll ans=(curr/k)*2;
		ll rem=(curr%k);
		unpaired+=(rem*2);
		if(unpaired>=k){
			ans++;
		}
		cout<<ans<<"\n";
	}
}
