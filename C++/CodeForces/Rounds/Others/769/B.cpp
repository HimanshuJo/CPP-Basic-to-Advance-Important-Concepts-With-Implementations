// B. Roof Construction
/*
It has finally been decided to build a roof over the football field in School 179. 
Its construction will require placing n consecutive vertical pillars. 
Furthermore, the headmaster wants the heights of all the pillars to form a permutation p of 
integers from 0 to n−1, where pi is the height of the i-th pillar from the left (1≤i≤n).

As the chief, you know that the cost of construction of consecutive pillars is equal to the maximum 
value of the bitwise XOR of heights of all pairs of adjacent pillars. 

In other words, the cost of construction is equal to max1≤i≤n−1pi⊕pi+1, where ⊕ denotes the bitwise XOR operation.

Find any sequence of pillar heights p of length n with the smallest construction cost.

In this problem, a permutation is an array consisting of n distinct integers from 0 to n−1 in arbitrary order. 
For example, [2,3,1,0,4] is a permutation, but [1,0,1] is not a permutation 
(1 appears twice in the array) and [1,0,3] is also not a permutation (n=3, but 3 is in the array).

Input
Each test contains multiple test cases. The first line contains the number of test cases t 
(1≤t≤10^4). Description of the test cases follows.

The only line for each test case contains a single integer n (2≤n≤2⋅10^5) — the number of pillars for the construction of the roof.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case print n integers p1, p2, …, pn — the sequence of pillar heights with the smallest construction cost.

If there are multiple answers, print any of them.

Example
input
4
2
3
5
10

output
0 1
2 0 1
3 2 1 0 4
4 6 3 2 0 8 9 1 7 5

Note
For n=2 there are 2 sequences of pillar heights:

[0,1] — cost of construction is 0⊕1=1.
[1,0] — cost of construction is 1⊕0=1.
For n=3 there are 6 sequences of pillar heights:

[0,1,2] — cost of construction is max(0⊕1,1⊕2)=max(1,3)=3.
[0,2,1] — cost of construction is max(0⊕2,2⊕1)=max(2,3)=3.
[1,0,2] — cost of construction is max(1⊕0,0⊕2)=max(1,2)=2.
[1,2,0] — cost of construction is max(1⊕2,2⊕0)=max(3,2)=3.
[2,0,1] — cost of construction is max(2⊕0,0⊕1)=max(2,1)=2.
[2,1,0] — cost of construction is max(2⊕1,1⊕0)=max(3,1)=3.
*/
/*
Let k be the highest set bit in n−1. 
There will always be a pair of adjacent elements where one of them has the k-th bit set and the other one doesn't, 
so the cost is at least 2^k. A simple construction that reaches it is 
2^k−1, 2^k−2, …, 0, 2^k, 2^k+1, …, n−1.

Time complexity: O(n)
Bonus: count the number of permutations with the minimum cost.
*/

#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int k=0;
		while((1<<(k+1))<=n-1){
			k++;
		}
		for(int i=(1<<k)-1; i>=0; --i){
			cout<<i<<" ";
		}
		for(int i=(1<<k); i<n; ++i){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
}
