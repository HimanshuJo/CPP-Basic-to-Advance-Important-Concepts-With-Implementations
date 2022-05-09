// D. MEX Sequences
/*
Let's call a sequence of integers x1,x2,…,xk MEX-correct if for all i (1≤i≤k) |xi−MEX(x1,x2,…,xi)|≤1 holds. 
Where MEX(x1,…,xk) is the minimum non-negative integer that doesn't belong to the set x1,…,xk. 
For example, MEX(1,0,1,3)=2 and MEX(2,1,5)=0.

You are given an array a consisting of n non-negative integers. 
Calculate the number of non-empty MEX-correct subsequences of a given array. 
The number of subsequences can be very large, so print it modulo 998244353.

Note: a subsequence of an array a is a sequence [ai1,ai2,…,aim] meeting the constraints 1≤i1<i2<⋯<im≤n. 
If two different ways to choose the sequence of indices [i1,i2,…,im] yield the same subsequence, 
the resulting subsequence should be counted twice (i.e. two subsequences are different 
if their sequences of indices [i1,i2,…,im] are not the same).

Input
The first line contains a single integer t (1≤t≤10^5) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤5⋅10^5).

The second line contains n integers a1,a2,…,an (0≤ai≤n).

The sum of n over all test cases doesn't exceed 5⋅10^5.

Output
For each test case, print a single integer — the number of non-empty MEX-correct subsequences of a given array, taken modulo 998244353.

Example
input
4
3
0 2 1
2
1 0
5
0 0 0 0 0
4
0 1 2 3

output
4
2
31
7
Note
In the first example, the valid subsequences are [0], [1], [0,1] and [0,2].

In the second example, the valid subsequences are [0] and [1].

In the third example, any non-empty subsequence is valid.
*/
/*
Solution

Let's understand what MEX-correct sequences look like. 
It turns out there are only two types: 
[0,…,0––––––––,1,…,1––––––––,…,x−1,…,x−1––––––––––––––––,x,…,x––––––––] and 
[0,…,0––––––––,1,…,1––––––––,…,x−1,…,x−1––––––––––––––––,x+1,…,x+1––––––––––––––––,x−1,…,x−1––––––––––––––––,x+1,…–––––––––]. 

For example, the sequences [0,0,1,1,1,2,3,3] and the empty sequence are MEX-correct sequences of the first type, 
and [1,1,1,1] and [0,0,1,2,4,4,2,4,2,2] of the second one.

Let's calculate the dynamic programming dp1i,j — the number of MEX-correct subsequences of the first type on the 
prefix of length i with MEX equal to j and similarly dp2i,j — the number of MEX-correct subsequences of the second type on 
the prefix of length i with MEX equal to j.

Let's look at the transitions in these dps, and show that there are no other MEX-correct sequences at the same time.

Let the current state be dp1i,j, and we are trying to add an element equal to x:

if x<j−1, then such an element cannot be added;
if x=j−1, then the value of MEX will not change and the sequence is still of the first type, which means we have a transition to dp1i+1,j;
if x=j, then the value of MEX will increase by 1, but it will still be of the first type, which means we have a transition to dp1i+1,j+1
if x=j+1, then the value of MEX will not change, but the sequence will become of the second type, which means we have a transition to dp2i+1,j;
if x>j+1, then such an element cannot be added.

Let the current state be dp2i,j, and we are trying to add an element equal to x:

if x<j−1, then such an element cannot be added;
if x=j−1, then the value of MEX will not change and the sequence is still of the second type, which means we have a transition to dp2i+1,j;
if x=j, then such an element cannot be added, because MEX will increase by 2, which means the absolute difference between MEX and x is greater than 1;
if x=j+1, then the value of MEX will not change and the sequence is still of the second type, which means we have a transition to dp2i+1,j;
if x>j+1, then such an element cannot be added.

Thus, we considered all possible transitions (adding a new element to the already MEX-correct sequences) 
and made sure that there are only two types.

While the solution itself works in O(n) time 
(because each element x has O(1) possible transitions in the dps), it uses O(n^2) memory, 
which does not allow us to write that solution as is. However, note that dp1i and dp1i+1

(similarly for dp2) differ in only a few positions (in those that the element ai allowed us to make), 
which means we can store only one-dimensional arrays, dp1j and dp2j. Thus, the final complexity of the solution is O(n).
*/

#include<iostream>
#include<vector>
using namespace std;
const int mod=998244353;

int add(int x, int y){
	x+=y;
	if(x>=mod) x-=mod;
	return x;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>dp1(n+2), dp2(n+2);
		dp1[0]=1;
		while(n--){
			int x;
			cin>>x;
			dp1[x+1]=add(dp1[x+1], dp1[x+1]);
			dp1[x+1]=add(dp1[x+1], dp1[x]);
			if(x>0) dp2[x-1]=add(dp2[x-1], dp2[x-1]);
			if(x>0) dp2[x-1]=add(dp2[x-1], dp1[x-1]);
			dp2[x+1]=add(dp2[x+1], dp2[x+1]);	
		}
		int ans=0;
		for(auto &vals: dp1){
			ans=add(ans, vals);
		}
		for(auto &vals: dp2){
			ans=add(ans, vals);
		}
		cout<<(add(ans, mod-1))<<"\n";
	}
}
