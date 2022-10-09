// C. Phase Shift
/*
There was a string s which was supposed to be encrypted. For this reason, all 26 lowercase English 
letters were arranged in a circle in some order, afterwards, each letter in s was replaced with the one 
that follows in clockwise order, in that way the string t was obtained.

You are given a string t. Determine the lexicographically smallest string s that could be a prototype 
of the given string t.

A string a is lexicographically smaller than a string b of the same length if and only if:

in the first position where a and b differ, the string a has a letter, that appears earlier in the 
alphabet than the corresponding letter in b.
Input
The first line of the input contains a single integer t (1≤t≤3⋅10^4) — the number of test cases. 
The description of test cases follows.

The first line of each test case contains one integer n (1≤n≤10^5) — the length of the string t.

The next line contains the string t of the length n, containing lowercase English letters.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅10^5.

Output
For each test case, output a single line containing the lexicographically smallest string s which could be a prototype of t.

Example
input
5
1
a
2
ba
10
codeforces
26
abcdefghijklmnopqrstuvwxyz
26
abcdefghijklmnopqrstuvwxzy

output
b
ac
abcdebfadg
bcdefghijklmnopqrstuvwxyza
bcdefghijklmnopqrstuvwxyaz

Note
In the first test case, we couldn't have the string "a", since the letter a would transit to itself. 
Lexicographically the second string "b" is suitable as an answer.

In the second test case, the string "aa" is not suitable, since a would transit to itself. 
"ab" is not suitable, since the circle would be closed with 2 letters, but it must 
contain all 26. The next string "ac" is suitable.

Below you can see the schemes for the first three test cases. 
The non-involved letters are skipped, they can be arbitrary placed in the gaps.
*/

/*
First of all, the encryption process is reversible. If we obtained t from s using the circle c, we 
can obtain s from t using the same cycle c, but reversed.
So, let's think in terms of encryption of t.

Lexicographical order itself is a greedy thing. So, we can create a greedy algorithm.

Let's go from left to right and generate the result letter by letter. We have to choose the best possible 
option at each step. Let's describe the options we have.

If the current letter was used earlier, we already know the replacement we need to choose.

Otherwise, we would like to choose the minimum possible option. We need to maintain some structure to know what is acceptable.

Let's keep the circle that is already generated(it's a graph). For each letter we have one incoming edge and one 
outgoing edge in the end. Let's keep them for every letter: arrays in[26], out[26].

When we want to generate an outgoing edge at some step(let's define the letter on this step as x), we 
have to choose the minimum letter that doesn't have an incoming edge yet. With one exception: 
if creating the edge using this rule creates a circle of size less than 26. It would mean that we 
wouldn't have a full circle in the end. It's easy to see that there is no more than one such letter, as 
this letter is just the end of a chain starting in x.

To check that a small circle wasn't generated, we can go along an outgoing edge 26 times, starting at x. 
If we end up in x or there was no edge at some step then everything is ok, we can create this edge.

Complexity is O(26⋅26+n), that is, O(n).
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#define endl "\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		string t;
		cin>>t;
		vector<int>edge(26, -1), redge(26, -1);
		vector<int>vec;
		for(auto &ch: t){
			vec.push_back(ch-'a');
		}
		auto get_path_end=[&](int c){
			int len=0;
			int curr=c;
			while(edge[curr]!=-1){
				len++; 
				curr=edge[curr];
			}
			return make_pair(curr, len);
		};
		for(int i=0; i<N; ++i){
			if(edge[vec[i]]==-1){
				for(int c=0; c<26; ++c){
					if(redge[c]==-1){
						auto [clast, len]=get_path_end(c);
						if(clast!=vec[i]||len==25){
							edge[vec[i]]=c;
							redge[c]=vec[i];
							break;
						}
					}
				}
			}
			vec[i]=edge[vec[i]];
		}
		for(int i=0; i<N; ++i){
			t[i]=vec[i]+'a';
		}
		cout<<t<<endl;
	}
}