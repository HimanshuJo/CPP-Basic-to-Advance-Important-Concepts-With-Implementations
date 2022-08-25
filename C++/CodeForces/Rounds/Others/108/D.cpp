// D. Maximum Sum of Products
/*
You are given two integer arrays a and b of length n.

You can reverse at most one subarray (continuous subsegment) of the array a.

Your task is to reverse such a subarray that the sum ∑i=1nai⋅bi is maximized.

Input
The first line contains one integer n (1≤n≤5000).

The second line contains n integers a1,a2,…,an (1≤ai≤10^7).

The third line contains n integers b1,b2,…,bn (1≤bi≤10^7).

Output
Print single integer — maximum possible sum after reversing at most one subarray (continuous subsegment) of a.

Examples
input
5
2 3 2 1 3
1 3 2 4 2

output
29

input
2
13 37
2 4

output
174

input
6
1 8 7 6 3 6
5 9 6 8 8 6

output
235

Note
In the first example, you can reverse the subarray [4,5]. Then a=[2,3,2,3,1] and 2⋅1+3⋅3+2⋅2+3⋅4+1⋅2=29.

In the second example, you don't need to use the reverse operation. 13⋅2+37⋅4=174.

In the third example, you can reverse the subarray [3,5]. Then a=[1,8,3,6,7,6] and 1⋅5+8⋅9+3⋅6+6⋅8+7⋅8+6⋅6=235.

*/
/*
Solution:

The naive approach is to iterate over l and r, reverse the subsegment of the array [l,r]
and calculate the answer. But this solution is too slow and works in O(n3).

Instead, we can iterate over the center of the reversed segment and its length.
If the current segment is [l,r], and we want to go to [l−1,r+1],
then the answer for the subsegment will increase by al−1∗br+1+ar+1∗bl−1.

It remains to add the answer for [1,l) and (r,n], but without reversion,
this is easy to do if you pre-calculate the prefix sums of the values ai∗bi.
*/

/*
Brute Force:

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
using ll=long long;
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>in1(n);
	vector<int>in2(n);
	for(int i=0; i<n; ++i){
		cin>>in1[i];
	}
	for(int i=0; i<n; ++i){
		cin>>in2[i];
	}
	ll res=LONG_MIN;
	map<tuple<int, int, int>, ll>memo;
	for(int i=0; i<n; ++i){
		for(int j=i; j<n; ++j){
			bool flag=false;
			for(int x=0; x<n; ++x){
				if(memo.find(make_tuple(i, j, x))!=memo.end()){
					ll val= memo[make_tuple(i, j, x)];
					res=max(res, val);
					flag=true;
				}
				if(flag) break;
				vector<int>tmp=in1;
				if(n-x<=j) break;
				reverse(tmp.begin()+j, tmp.end()-x);
				ll currval=0;
				for(int jj=0; jj<n; ++jj){
					currval+=(in2[jj]*tmp[jj]);
				}
				res=max(res, currval);
				tuple<int, int, int>curr;
				curr= make_tuple(i, j, x);
				memo[curr]=res;
			}
		}
	}
	cout<<res<<"\n";
}
*/

#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
	int n;
	cin >> n;
	vector<li> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	vector<li> pr(n + 1, 0);
	for (int i = 0; i < n; ++i)
		pr[i + 1] = pr[i] + a[i] * b[i];
	li ans = pr[n];
	for (int c = 0; c < n; ++c) {
		li cur = a[c] * b[c];
		for (int l = c - 1, r = c + 1; l >= 0 && r < n; --l, ++r) {
			cur += a[l] * b[r];
			cur += a[r] * b[l];
			ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
		}
		cur = 0;
		for (int l = c, r = c + 1; l >= 0 && r < n; --l, ++r) {
			cur += a[l] * b[r];
			cur += a[r] * b[l];
			ans = max(ans, cur + pr[l] + (pr[n] - pr[r + 1]));
		}
	}
	cout << ans << endl;
}