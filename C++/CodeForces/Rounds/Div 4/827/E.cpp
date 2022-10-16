// E. Scuza
/*
Timur has a stairway with n steps. The i-th step is ai meters higher than its predecessor. 
The first step is a1 meters higher than the ground, and the ground starts at 0 meters.

Timur has q questions, each denoted by an integer k1,…,kq. For each question ki, you have to print the 
maximum possible height Timur can achieve by climbing the steps if his legs are of length ki. 
Timur can only climb the j-th step if his legs are of length at least aj. In other words, ki≥aj for each step j climbed.

Note that you should answer each question independently.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains two integers n,q (1≤n,q≤2⋅10^5) — the number of steps 
and the number of questions, respectively.

The second line of each test case contains n integers (1≤ai≤10^9) — the height of the steps.

The third line of each test case contains q integers (0≤ki≤10^9) — the numbers for each question.

It is guaranteed that the sum of n does not exceed 2⋅10^5, and the sum of q does not exceed 2⋅105.

Output
For each test case, output a single line containing q integers, the answer for each question.

Please note, that the answer for some questions won't fit into 32-bit integer type, so you should use 
at least 64-bit integer type in your programming language (like long long for C++).

Example
input
3
4 5
1 2 1 5
1 2 4 9 10
2 2
1 1
0 1
3 1
1000000000 1000000000 1000000000
1000000000

output
1 4 4 9 9 
0 2 
3000000000

Note
Consider the first test case, pictured in the statement.

If Timur's legs have length 1, then he can only climb stair 1, so the highest he can reach is 1 meter.
If Timur's legs have length 2 or 4, then he can only climb stairs 1, 2, and 3, so the highest he can reach is 1+2+1=4 meters.
If Timur's legs have length 9 or 10, then he can climb the whole staircase, so the highest he can reach is 1+2+1+5=9 meters.
In the first question of the second test case, Timur has no legs, so he cannot go up even a single step. :(
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll=long long;
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, q;
		cin>>n>>q;
		vector<int>ai(n), ki(q);
		for(int i=0; i<n; ++i){
			cin>>ai[i];
		}
		for(int i=0; i<q; ++i){
			cin>>ki[i];
		}
		vector<ll>aicmb;
		aicmb.push_back(0);
		for(int i=0; i<n; ++i){
			aicmb.push_back(aicmb.back()+ai[i]);
		}
		vector<ll>prefmaxx;
		for(int i=0; i<n; ++i){
			if(i==0){
				prefmaxx.push_back(ai[i]);
			} else{
				prefmaxx.push_back(max((ll)ai[i], prefmaxx.back()));
			}
		}
		vector<ll>ans(q);
		for(int i=0; i<q; ++i){
			auto it=upper_bound(prefmaxx.begin(), prefmaxx.end(), ki[i]);
			int idx=it-prefmaxx.begin();
			ans[i]=aicmb[idx];
		}
		for(auto &vals: ans){
			cout<<vals<<" ";
		}
		cout<<endl;
	}
}