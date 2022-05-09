// B. GCD Arrays
/*
Consider the array a composed of all the integers in the range [l,r]. For example, if l=3 and r=7, then a=[3,4,5,6,7].

Given l, r, and k, is it possible for gcd(a) to be greater than 1 after doing the following operation at most k times?

Choose 2 numbers from a.
Permanently remove one occurrence of each of them from the array.
Insert their product back into a.
gcd(b) denotes the greatest common divisor (GCD) of the integers in b.

Input
The first line of the input contains a single integer t (1<=t<=10^5) — the number of test cases. The description of test cases follows.

The input for each test case consists of a single line containing 3 non-negative integers l, r, and k (1<=l<=r<=10^9,0<=k<=r−l).

Output
For each test case, print "YES" if it is possible to have the GCD of the corresponding array greater than 1 by performing at most k operations, and "NO" otherwise (case insensitive).

Example
input
9
1 1 0
3 5 1
13 13 0
4 4 0
3 7 4
4 10 3
2 4 0
1 7 3
1 5 3

output
NO
NO
YES
YES
YES
YES
NO
NO
YES

Note
For the first test case, a=[1], so the answer is "NO", since the only element in the array is 1.

For the second test case the array is a=[3,4,5] and we have 1 operation. After the first operation the array can change to: 
[3,20], [4,15] or [5,12] all of which having their greatest common divisor equal to 1 so the answer is "NO".

For the third test case, a=[13], so the answer is "YES", since the only element in the array is 13.

For the fourth test case, a=[4], so the answer is "YES", since the only element in the array is 4
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int l, r, k;
		cin>>l>>r>>k;
		if((l==r)&&(r==1)){
			cout<<"NO\n";
			continue;
		} else if(l==r){
			cout<<"YES\n";
			continue;
		}
		int ll=(r-l+1); 
		int rr=(r/2-(l-1)/2);
		if(ll-rr<=k) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
