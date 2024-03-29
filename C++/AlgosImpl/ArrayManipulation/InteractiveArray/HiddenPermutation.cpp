/*
This is an interactive problem!

Nastia has a hidden permutation p of length n consisting of integers from 1 to n. 
You, for some reason, want to figure out the permutation. To do that, you can give her an integer t (1≤t≤2), 
two different indices i and j (1≤i,j≤n, i≠j), and an integer x (1≤x≤n−1).

Depending on t, she will answer:

t=1: max(min(x,pi),min(x+1,pj));
t=2: min(max(x,pi),max(x+1,pj)).
You can ask Nastia at most ⌊3⋅n/2⌋+30 times. It is guaranteed that she will not change her 
permutation depending on your queries. Can you guess the permutation?

Input
The input consists of several test cases. In the beginning, you receive the integer T (1≤T≤10000) — 
the number of test cases.

At the beginning of each test case, you receive an integer n (3≤n≤10^4) — the length of the permutation p.

It's guaranteed that the permutation is fixed beforehand and that the sum of n in one test doesn't exceed 2⋅10^4.

Interaction
To ask a question, print "? t i j x" (t=1 or t=2, 1≤i,j≤n, i≠j, 1≤x≤n−1) Then, you should read the answer.

If we answer with −1 instead of a valid answer, that means you exceeded the number of queries or made an invalid query. 
Exit immediately after receiving −1 and you will see the Wrong Answer verdict. 
Otherwise, you can get an arbitrary verdict because your solution will continue to read from a closed stream.

To print the answer, print "! p1 p2 … pn (without quotes). 
Note that answering doesn't count as one of the ⌊3⋅n/2⌋+30 queries.

After printing a query or printing the answer, do not forget to output end of line and flush the output. 
Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
See the documentation for other languages.
Hacks

To hack the solution, use the following test format.

The first line should contain a single integer T (1≤T≤10000) — the number of test cases.

For each test case in the first line print a single integer n (3≤n≤10^4) — the length of the hidden permutation p.

In the second line print n space-separated integers p1,p2,…,pn (1≤pi≤n), where p is permutation.

Note that the sum of n over all test cases should not exceed 2⋅10^4.

Example
input
2
4

3

2

5

3

output
? 2 4 1 3

? 1 2 4 2

! 3 1 4 2

? 2 3 4 2

! 2 5 3 4 1
Note
Consider the first test case.

The hidden permutation is [3,1,4,2].

We print: "? 2 4 1 3" and get back min(max(3,p4),max(4,p1))=3.

We print: "? 1 2 4 2" and get back max(min(2,p2),min(3,p4))=2.

Consider the second test case.

The hidden permutation is [2,5,3,4,1].

We print: "? 2 3 4 2" and get back min(max(2,p3),max(3,p4))=3.

*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<cstring>
using namespace std;

int query(vector<int>&temp, int N){
	vector<int>curr={3, 2, 1, 5, 4};
	for(int i=0; i<N; ++i){
		temp[i]+=curr[i];
	}
	int res=INT_MAX;
	unordered_map<int, int>mp;
	for(int i=0; i<N; ++i){
		mp[temp[i]]++;
	}
	vector<int>dups;
	for(auto &entry: mp){
		if(entry.second>1){
			dups.push_back(entry.first);
		}
	}
	for(auto &vals: dups){
		for(int i=0; i<N; ++i){
			if(temp[i]==vals){
				res=min(res, i);
			}
		}
	}
	return res==INT_MAX?-1:res;
}


int main(){
	int N;
	cin>>N;
	int res[N];
	memset(res, 0, sizeof(res));
	res[N-1]=N;
	for(int i=1; i<N; ++i){
		vector<int>temp(N, i+1);
		temp[N-1]=1;
		if(query(temp, N)==-1){
			res[N-1]=i;
			break;
		}
	}
	for(int i=1; i<res[N-1]; ++i){
		vector<int>temp(N, i+1);
		temp[N-1]=1;
		int loc=query(temp, N);
		res[loc]=res[N-1]-i;
	}
	for(int i=1; i<=N-res[N-1]; ++i){
		vector<int>temp(N, i);
		temp[N-1]+=i;
		int loc=query(temp, N);
		res[loc]=res[N-1]+i;
	}
	for(int x: res){
		cout<<x<<" ";
	}
}
