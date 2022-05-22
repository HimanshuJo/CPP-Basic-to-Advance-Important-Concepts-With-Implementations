/*
Problem Statement

Given a string ‘str’. Find the minimum number of partitions to make in the string such that 
every partition of the string is a palindrome.

Given a string, make cuts in that string to make partitions containing substrings with size 
at least 1, and also each partition is a palindrome. For example, consider “AACCB” we can 
make a valid partition like A | A | CC | B. Among all such valid partitions, 
return the minimum number of cuts to be made such that the resulting substrings in the partitions are palindromes.

The minimum number of cuts for the above example will be AA | CC | B. i.e 2 cuts

Note :

1) We can partition the string after the first index and before the last index.

2) Each substring after partition must be a palindrome.

3) For a string of length ‘n’, if the string is a palindrome, then a minimum 0 cuts are needed.  

4) If the string contains all different characters, then ‘n-1’ cuts are needed.

5) The string consists of upper case English alphabets only with no spaces.
*/

#include<vector>
using namespace std;

bool isPalindrome(int idx, int j, const string &str){
	int l=idx, r=j;
	int hflen=(r-l)/2;
	for(int x=idx; x<=idx+hflen; ++x){
		if(str[x]!=str[r--]) return false;
	}
	return true;
}

int dfs(string &str, const int sz, int idx, vector<int>&memo){
	if(idx>=sz) return 0;
	if(memo[idx]!=-1) return memo[idx];
	int minCost=INT_MAX;
	for(int j=idx; j<sz; ++j){
		if(isPalindrome(idx, j, str)){
			int currCost=1+dfs(str, sz, j+1, memo);
			minCost=min(minCost, currCost);
		}
	}
	return memo[idx]=minCost;
}

int palindromePartitioning(string str) {
    int sz=str.size();
	vector<int>memo(sz+1, -1);
	return (dfs(str, sz, 0, memo)-1);
}
