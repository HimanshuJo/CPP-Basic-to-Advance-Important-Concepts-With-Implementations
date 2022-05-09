// E. Chaotic Merge
/*
You are given two strings x and y, both consist only of lowercase Latin letters. Let |s| be the length of string s.

Let's call a sequence a a merging sequence if it consists of exactly |x| zeros and exactly |y| ones in some order.

A merge z is produced from a sequence a by the following rules:

if ai=0, then remove a letter from the beginning of x and append it to the end of z;
if ai=1, then remove a letter from the beginning of y and append it to the end of z.
Two merging sequences a and b are different if there is some position i such that ai!=bi.

Let's call a string z chaotic if for all i from 2 to |z| zi−1≠zi.

Let s[l,r] for some 1<=l<=r<=|s| be a substring of consecutive letters of s, starting from position l and ending at position r inclusive.

Let f(l1,r1,l2,r2) be the number of different merging sequences of x[l1,r1] and y[l2,r2] that produce chaotic merges. Note that only non-empty substrings of x and y are considered.

Calculate summation(1<=l_1<=r_1<=|x| 1<=l_2<=r_2<=|y|)
f(l1,r1,l2,r2). 

Output the answer modulo 998244353.

Input
The first line contains a string x (1<=|x|<=1000).

The second line contains a string y (1<=|y|<=1000).

Both strings consist only of lowercase Latin letters.

Output
Print a single integer — the sum of f(l1,r1,l2,r2) over 1<=l_1<=r_1<=|x| and 1<=l_2<=r_2<=|y| modulo 998244353.

Examples
input
aaa
bb

output
24

input
code
forces

output
1574

input
aaaaa
aaa

output
0

input
justamassivetesttocheck
howwellyouhandlemodulooperations

output
667387032

Note
In the first example there are:

6 pairs of substrings "a" and "b", each with valid merging sequences "01" and "10";
3 pairs of substrings "a" and "bb", each with a valid merging sequence "101";
4 pairs of substrings "aa" and "b", each with a valid merging sequence "010";
2 pairs of substrings "aa" and "bb", each with valid merging sequences "0101" and "1010";
2 pairs of substrings "aaa" and "b", each with no valid merging sequences;
1 pair of substrings "aaa" and "bb" with a valid merging sequence "01010";
Thus, the answer is 6*2+3*1+4*1+2*2+2*0+1*1=24.
*/

#include<vector>
#include<iostream>
using namespace std;
using ll=long long;

const int mod=998244353;
ll dp[1005][1005][2];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string x, y;
	cin>>x>>y;
	int n=x.length(), m=y.length();
	x.push_back('#'), y.push_back('#');
	vector<ll>suff1(n+1);
	suff1[n-1]=1;
	for(int i=n-2; i>=0; --i){
		int j;
		for(j=i; j<n-1; ++j){
			if(x[j]==x[j+1]) break;
		}
		suff1[i]=j-i+1;
	}
	vector<ll>suff2(m+1);
	suff2[m-1]=1;
	for(int i=m-2; i>=0; --i){
		int j;
		for(j=i; j<m-1; ++j){
			if(y[j]==y[j+1]) break;
		}
		suff2[i]=j-i+1;
	}
	for(int i=0; i<1005; ++i){
		for(int j=0; j<1005; ++j){
			dp[i][j][0]=dp[i][j][1]=0;
		}
	}
	for(int i=n-1; i>=0; --i){
		for(int j=m-1; j>=0; --j){
			dp[i][j][0]=(x[i]==x[i+1]?0:dp[i+1][j][0])+(x[i]==y[j]?0:dp[i+1][j][1])+(x[i]==y[j]?0:suff2[j]);
			dp[i][j][0]%=mod;
			dp[i][j][1]=(y[j]==y[j+1]?0:dp[i][j+1][1])+(x[i]==y[j]?0:dp[i][j+1][0])+(x[i]==y[j]?0:suff1[i]);
			dp[i][j][1]%=mod;
		}
	}
	ll ans=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			ans=(ans+dp[i][j][0]+dp[i][j][1])%mod;
		}
	}
	cout<<ans;
}

