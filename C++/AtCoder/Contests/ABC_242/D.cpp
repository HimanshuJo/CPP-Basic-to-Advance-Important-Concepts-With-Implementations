// D - ABC Transform
/*
Problem Statement
You are given a string S consisting of A, B, C.

Let S(0):=S. For i=1,2,3,…, let 

S(i) be the result of simultaneously replacing the characters of S(i−1) as follows: A → BC, B → CA, C → AB.

Answer Q queries. The i-th query is as follows.

Print the ki-th character from the beginning of S(ti)

Constraints
S is a string of length between 1 and 10^5 (inclusive) consisting of A, B, C.

1≤Q≤10^5
 
0≤ti≤10^18
 
1≤ki≤min(10^18, the length of S(ti))
Q,ti,ki are integers.

Input
Input is given from Standard Input in the following format:

S
Q
t1 k1

t2 k2
⋮
tQ kQ

Output
Process the Q queries in ascending order of index, that is, 
in the given order. Each answer should be followed by a newline.

Sample Input 1 
ABC
4
0 1
1 1
1 3
1 6

Sample Output 1 
A
B
C
B
We have S(0)=ABC, S(1)=BCCAAB.

Thus, the answers to the queries are A, B, C, B in the given order.

Sample Input 2 
CBBAACCCCC
5
57530144230160008 659279164847814847
29622990657296329 861239705300265164
509705228051901259 994708708957785197
176678501072691541 655134104344481648
827291290937314275 407121144297426665

Sample Output 2 
A
A
C
A
A
*/

/*
Solution:

we use 0-based index, instead of 1-based index, for S. In other words, when the length of N is 

S, S=S1S2…SN, not S=S0S1…SN−1

Let f(t,k) be “the function that returns the k-th character of S(t).”

First, for t=0, f(t,k) is the k-th character of S.

Next, we consider the case where k=0. Taking a closer look, 
we can see that the 0-th characters of S(0),S(1),S(2),S(3),S(4)… are either

A, B, C, A, B, …
B, C, A, B, C, …
C, A, B, C, A, …

which are periodic.

If the successor of A is defined to be B, B is C, and C is A, 
then the 0-th character of S(t) is the t-th successor of the first character of S(0).

Therefore, when k=0, f(t,k) is the k-th successor of S0.

Finally, let’s consider what f(t,k) returns when 0<t,k.

Taking a closer look again, we can see that

	when k is even, f(t,k) is the first successor of f(t−1, k/2);

	when k is odd, f(t,k) is the second successor of f(t−1, k/2).

Thus, for 0<t,k, we can recursively obtain f(t,k) based on the value of f(t−1,⌊k/2⌋). 
Here, ⌊k/2⌋ is k/2 rounded down.

Therefore, f(t,k) is

	the k-th character of S if t=0;
	the k-th successor of S0 if k=0;
	the (remainder of k by 2, plus 1)-th successor of f(t−1,⌊k/2⌋) if t=0.	
*/

#include<iostream>
#include<functional>
using namespace std;
using ll=long long;

int main(){
	string S;
	cin>>S;
	int Q;
	cin>>Q;

	auto g=[&](char ch, ll add){
		return (char('A'+(ch-'A'+add)%3)); 
	};

	std::function<char(ll, ll)>
	f=[&](ll t, ll k){
		if(t==0) return S[k];
		if(k==0) return g(S[0], t);
		return g(f(t-1, k/2), k%2+1);
	};

	while(Q--){
		ll t, k;
		cin>>t>>k;
		cout<<f(t, k-1)<<"\n";
	}
}