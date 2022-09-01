// D1. Xor-Subsequence (easy version)
/*
It is the easy version of the problem. The only difference is that in this version ai≤200.

You are given an array of n integers a0,a1,a2,…an−1. Bryap wants to find the longest 
beautiful subsequence in the array.

An array b=[b0,b1,…,bm−1], where 0≤b0<b1<…<bm−1<n, is a subsequence of length m of the array a.

Subsequence b=[b0,b1,…,bm−1] of length m is called beautiful, if the following condition holds:

For any p (0≤p<m−1) holds: abp⊕bp+1<abp+1⊕bp.

Here a⊕b denotes the bitwise XOR of a and b. For example, 2⊕4=6 and 3⊕1=2.

Bryap is a simple person so he only wants to know the length of the longest such subsequence.

Help Bryap and find the answer to his question.

Example
input
3
2
1 2
5
5 2 4 3 1
10
3 8 8 2 9 1 6 2 8 3

output
2
3
6
Note

In the first test case, we can pick the whole array as a beautiful subsequence because 1⊕1<2⊕0.

In the second test case, we can pick elements with indexes 1, 2 and 4 (in 0-indexation). 
For this elements holds: 2⊕2<4⊕1 and 4⊕4<1⊕2.
*/

#include<vector>
#include<iostream>
using namespace std;

bool isCond(vector<int>&in, int i, int j){
	return ((in[i]^j)>(in[j]^i));
}

void dfs(vector<int>&in, int n, int i, int &ans, vector<int>&memo){
	if(i>=in.size()) return;
	memo.push_back(1);
	for(int j=i-1; j>=max(0, i-512); --j){
		if(isCond(in, i, j)){
			memo.back()=max(memo.back(), 1+memo[j+1]);
		}
	}
	ans=max(ans, memo.back());
	dfs(in, n, i+1, ans, memo);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n);
		for(int i=0; i<n; ++i){
			cin>>in[i];
		}
		int ans=INT_MIN;
		vector<int>memo(1);
		dfs(in, n, 0, ans, memo);
		cout<<ans<<endl;
	}
}