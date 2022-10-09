// B. Prefix Sum Addicts
/*
Suppose a1,a2,…,an is a sorted integer sequence of length n such that a1≤a2≤⋯≤an.

For every 1≤i≤n, the prefix sum si of the first i terms a1,a2,…,ai is defined by
si=∑k=1iak=a1+a2+⋯+ai.

Now you are given the last k terms of the prefix sums, which are sn−k+1,…,sn−1,sn. 
Your task is to determine whether this is possible.

Formally, given k integers sn−k+1,…,sn−1,sn, the task is to check whether there is a sequence a1,a2,…,an such that

	a1≤a2≤⋯≤an, and
	
	si=a1+a2+⋯+ai for all n−k+1≤i≤n.

Input
Each test contains multiple test cases. The first line contains an integer t (1≤t≤10^5) — the number of test cases. 
The following lines contain the description of each test case.

The first line of each test case contains two integers n (1≤n≤10^5) and k (1≤k≤n), 
indicating the length of the sequence a and the number of terms of prefix sums, respectively.

The second line of each test case contains k integers sn−k+1,…,sn−1,sn (−10^9≤si≤10^9 for every n−k+1≤i≤n).

It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case, output "YES" (without quotes) if it is possible and "NO" (without quotes) otherwise.

You can output "YES" and "NO" in any case (for example, strings "yEs", "yes" and "Yes" will be recognized as a positive response).

Example
input
4
5 5
1 2 3 4 5
7 4
-6 -5 -3 0
3 3
2 3 4
3 2
3 4

output
Yes
Yes
No
No

Note
In the first test case, we have the only sequence a=[1,1,1,1,1].

In the second test case, we can choose, for example, a=[−3,−2,−1,0,1,2,3].

In the third test case, the prefix sums define the only sequence a=[2,1,1], but it is not sorted.

In the fourth test case, it can be shown that there is no sequence with the given prefix sums.
*/

/*

*/

#include<vector>
#include<iostream>
#include<unordered_map>
#include<map>
#include<queue>
#include<algorithm>
#define endl "\n"
using ll=long long;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int N, K;
        cin>>N>>K;
		vector<int>in(N+1);
		for(int i=N-K+1; i<=N; ++i){
			cin>>in[i];
		}
		if(K==1) cout<<"Yes"<<endl;
		else{
			vector<long long>seq(N+1);
			for(int i=N-K+2; i<=N; ++i){
				seq[i]=in[i]-in[i-1];
			}
			if(!is_sorted(seq.begin()+N-K+2, seq.end())){
				cout<<"No"<<endl;
			} else{
				if(in[N-K+1]>seq[N-K+2]*(N-K+1)){
					cout<<"No"<<endl;
				} else{
					cout<<"Yes"<<endl;
				}
			}
		}
    }
}