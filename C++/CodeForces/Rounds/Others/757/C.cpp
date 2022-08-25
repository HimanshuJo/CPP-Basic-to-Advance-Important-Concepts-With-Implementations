/*
// C. Divan and bitwise operations
Once Divan analyzed a sequence a1,a2,…,an consisting of n non-negative integers as follows. He considered each non-empty subsequence of the sequence a, 
computed the bitwise XOR of its elements and added up all the XORs, obtaining the coziness of the sequence a.

A sequence c is a subsequence of a sequence d if c can be obtained from d by deletion of several (possibly, zero or all) elements. 
For example, [1,2,3,4], [2,4], and [2] are subsequences of [1,2,3,4], but [4,3] and [0] are not.

Divan was very proud of his analysis, but now he lost the sequence a, and also the coziness value! However, Divan remembers the value of
bitwise OR on m contiguous subsegments of the sequence a. It turns out that each element of the original sequence is contained in at least one of these m segments.

Divan asks you to help find the coziness of the sequence a using the information he remembers. If several coziness values are possible, print any.

As the result can be very large, print the value modulo 109+7.

Example
input
3
2 1
1 2 2
3 2
1 3 5
2 3 5
5 4
1 2 7
3 3 7
4 4 0
4 5 2
output
4
20
112
Note
In first example, one of the sequences that fits the constraints is [0,2]. Consider all its non-empty subsequences:

[0]: the bitwise XOR of this subsequence is 0;
[2]: the bitwise XOR of this subsequence is 2;
[0,2]: the bitwise XOR of this subsequence is 2.
The sum of all results is 4, so it is the answer.

In second example, one of the sequences that fits the constraints is [0,5,5].
*/

#include<iostream>
#include<cmath>
#include<vector>
#include<cassert>
using namespace std;
using ll=long long;

ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		ll bits=0;
		ll ans=0;
		for(int i=0; i<m; ++i){
			ll l, r, x;
			cin>>l>>r>>x;
			bits |= x;
		}
		bits%=mod;
		n--;
		while(n--){
			bits=(bits*2)%mod;
		}
		cout<<bits<<"\n";
	}
}

