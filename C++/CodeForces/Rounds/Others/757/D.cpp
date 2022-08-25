// D1. Divan and Kostomuksha (easy version)
/*
This is the easy version of the problem. The only difference is maximum value of ai.

Once in Kostomuksha Divan found an array a consisting of positive integers. 
Now he wants to reorder the elements of a to maximize the value of the following function:
∑i=1ngcd(a1,a2,…,ai),
where gcd(x1,x2,…,xk) denotes the greatest common divisor of integers x1,x2,…,xk, 
and gcd(x)=x for any integer x.

Reordering elements of an array means changing the order of elements in the array arbitrary, 
or leaving the initial order.

Of course, Divan can solve this problem. However, he found it interesting, so he decided to share it with you.

Examples
input
6
2 3 1 2 6 2
output
14

gcd(a1)+gcd(a1,a2)+gcd(a1,a2,a3)+gcd(a1,a2,a3,a4)+gcd(a1,a2,a3,a4,a5)+gcd(a1,a2,a3,a4,a5,a6)=6+2+2+2+1+1=14.
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
using ll=long long;

int maxxn=5e6;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vector<int>in(n);
	ll cnt[maxxn+1];
	memset(cnt, 0, sizeof(cnt));
	ll dp[maxxn+1];
	memset(dp, 0, sizeof(dp));
	for(int i=0; i<n; ++i){
		cin>>in[i];
		cnt[in[i]]++;
	}
	for(int i=1; i<=maxxn; ++i){
		for(int j=2*i; j<=maxxn; j+=i){
			cnt[i]+=cnt[j];
		}
	}
	ll ans=0;
	dp[1]=cnt[1];
	for(int i=1; i<=maxxn; ++i){
		ans=max(ans, dp[i]);
		for(int j=2*i; j<=maxxn; j+=i){
			dp[j]=max(dp[j], dp[i]+(j-i)*cnt[j]);
		}
	}
	cout<<ans<<"\n";
}
