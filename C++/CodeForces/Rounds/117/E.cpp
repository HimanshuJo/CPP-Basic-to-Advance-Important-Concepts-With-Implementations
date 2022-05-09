/*
Monocarp is a tutor of a group of n students. He communicates with them using a conference in a popular messenger.

Today was a busy day for Monocarp — he was asked to forward a lot of posts and announcements to his group, that's why he had to 
write a very large number of messages in the conference. Monocarp knows the students in the group he is tutoring quite well, so he understands 
which message should each student read: Monocarp wants the student i to read the message mi.

Of course, no one's going to read all the messages in the conference. That's why Monocarp decided to pin some of them. 
Monocarp can pin any number of messages, 
and if he wants anyone to read some message, he should pin it — otherwise it will definitely be skipped by everyone.

Unfortunately, even if a message is pinned, some students may skip it anyway. 
For each student i, Monocarp knows that they will read at most ki messages. 
Suppose Monocarp pins t messages; if t<=ki, then the i-th student will read all the pinned messages; 
but if t>ki, the i-th student will choose exactly ki
random pinned messages (all possible subsets of pinned messages of size ki are equiprobable) and read only the chosen messages.

Monocarp wants to maximize the expected number of students that read their respective messages 
(i.e. the number of such indices i that student i reads the message mi). 
Help him to choose how many (and which) messages should he pin!

Input
The first line contains one integer n (1≤n≤2⋅10^5) — the number of students in the conference.

Then n lines follow. The i-th line contains two integers mi and ki (1≤mi≤2⋅10^5; 1≤ki≤20) — 
the index of the message which Monocarp wants the i-th student to read and the maximum number of messages the i-th 
student will read, respectively.

Output
In the first line, print one integer t (1≤t≤2⋅10^5) — the number of messages Monocarp should pin. 
In the second line, print t distinct integers c1, c2, ..., ct (1≤ci≤2⋅10^5) — the indices of the messages Monocarp should pin. 
The messages can be listed in any order.

If there are multiple answers, print any of them.

Examples
input
3
10 1
10 2
5 2

output
2
5 10 

input
3
10 1
5 2
10 1

output
1
10 

input
4
1 1
2 2
3 3
4 4

output
3
2 3 4 

input
3
13 2
42 2
37 2

output
3
42 13 37

Note
Let's consider the examples from the statement.

In the first example, Monocarp pins the messages 5 and 10.
if the first student reads the message 5, the second student reads the messages 5 and 10, and 
the third student reads the messages 5 and 10, the number of students which have read their respective messages will be 2;
if the first student reads the message 10, the second student reads the messages 5 and 10, and 
the third student reads the messages 5 and 10, the number of students which have read their respective messages will be 3.
So, the expected number of students which will read their respective messages is 52.

In the second example, Monocarp pins the message 10.
if the first student reads the message 10, the second student reads the message 10, and the third student 
reads the message 10, the number of students which have read their respective messages will be 2.
So, the expected number of students which will read their respective messages is 2. 
If Monocarp had pinned both messages 5 and 10, the expected number of students which read their respective 
messages would have been 2 as well.

In the third example, the expected number of students which will read their respective messages is 83.
In the fourth example, the expected number of students which will read their respective messages is 2.
*/
/*
Solution:

First of all, let's rewrite the answer using expectation linearity. 
The expected number of students who read their respective messages is equal to F1+F2+⋯+Fn, 
where Fi is a random value which is 1 if the i-th student reads the message mi, and 0 if the i-th student doesn't do it.

Let's analyze the expected value of Fi. Suppose Monocarp pins the messages c1,c2,…,ct. There are three cases:

if mi∉[c1,c2,…,ct], then the i-th student won't read the message mi, so Fi=0;
if mi∈[c1,c2,…,ct] and t≤ki, then the i-th student will definitely read the message mi, so Fi=1;
if mi∈[c1,c2,…,ct] and t>ki, then Fi=kit.
If we iterate on the number of messages we pin t, we can calculate the sum of Fi for each message 
(considering that we pin it), sort all of the messages and pick t best of them. So, we have a solution working in O(n^2logn).

The only thing we need to improve this solution sufficiently is the fact that we 
don't have to consider the case t>20. Since every ki is not greater than 20, 
the sum of Fi for a message in the case t=20 is the same as this sum of Fi in the case t=21, 
but multiplied by the coefficient 20/21 — and we pick 21 best values, their sum multiplied by 20/21 
is not greater than the sum of 20 best values. The same holds for t=22 and greater.
*/

#include<vector>
#include<algorithm>
#include<iostream>
#include<random>
using namespace std;

const int N=200001;
const int K=20;
vector<int>idx[N];
int msg[N], k[N];

bool frac_greater(pair<int, int>A, pair<int, int>B){
	return A.first*B.second>A.second*B.first;
}

int main(){
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>msg[i]>>k[i];
		idx[msg[i]].push_back(i);
	}
	vector<int>cert;
	pair<int, int>ans={0, 1};
	for(int i=1; i<=K; ++i){
		vector<int>score(N);
		for(int j=0; j<n; ++j){
			score[msg[j]]+=min(i, k[j]);
		}
		vector<pair<int, int>>aux;
		for(int j=0; j<N; ++j){
			aux.push_back({score[j], j});
		}
		sort(aux.rbegin(), aux.rend());
		pair<int, int>curr_ans={0, i};
		vector<int>curr_cert;
		for(int j=0; j<i; ++j){
			curr_ans.first+=aux[j].first;
			curr_cert.push_back(aux[j].second);
		}
		if(frac_greater(curr_ans, ans)){
			ans=curr_ans;
			cert=curr_cert;
		}
	}
	cout<<cert.size()<<"\n";
	for(auto &vals: cert){
		cout<<vals<<" ";
	}
}
