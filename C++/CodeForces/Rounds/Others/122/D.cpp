// D. Make Them Equal
/*
You have an array of integers a of size n. Initially, all elements of the array are equal to 1. 
You can perform the following operation: choose two integers i (1≤i≤n) and x (x>0), 
and then increase the value of ai by ⌊ai/x⌋ (i.e. make ai=ai+⌊ai/x⌋).

After performing all operations, you will receive ci coins for all such i that ai=bi.

Your task is to determine the maximum number of coins that you can receive by performing no more than k operations.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains two integers n and k (1≤n≤10^3;0≤k≤10^6) — the size of the array 
and the maximum number of operations, respectively.

The second line contains n integers b1,b2,…,bn (1≤bi≤10^3).

The third line contains n integers c1,c2,…,cn (1≤ci≤10^6).

The sum of n over all test cases does not exceed 10^3.

Output
For each test case, print one integer — the maximum number of coins that you can get by performing no more than k operations.

Example
input
4
4 4
1 7 5 2
2 6 5 2
3 0
3 5 2
5 4 7
5 9
5 2 5 6 3
5 9 1 9 7
6 14
11 4 6 2 8 16
43 45 9 41 15 38

output
9
0
30
167
*/

#include<iostream>
#include<vector>
using ll=long long;
using namespace std;

const int N=1001;

vector<ll>cost(N, N);

void makeCost(){
	cost[1]=0;
	for(int i=1; i<N; ++i){
		for(int j=1; j<=i; ++j){
			ll val=i+i/j;
			if(val<N)
				cost[val]=min(cost[val], cost[i]+1);
		}
	}
}

ll dfs(int k, vector<int>&b, vector<int>&c, int idx, vector<vector<int>>&memo){
	if(idx<0) return 0;
	if(k<0) return 0;
	if(memo[idx][k]!=-1) return memo[idx][k];
	if(cost[b[idx]]>k){
		return memo[idx][k]=dfs(k, b, c, idx-1, memo);
	} else{
		return memo[idx][k]=max(c[idx]+dfs(k-cost[b[idx]], b, c, idx-1, memo), dfs(k, b, c, idx-1, memo));
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	makeCost();
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int>b(n), c(n);
		for(int i=0; i<n; ++i){
			cin>>b[i];
		}
		for(int i=0; i<n; ++i){
			cin>>c[i];
		}
		int sum=0;
		for(int num: b)
			sum+=cost[num];
		k=min(k, sum);
		vector<vector<int>>memo(N, vector<int>(k+1, -1));
		ll ans=dfs(k, b, c, n-1, memo);
		cout<<ans<<"\n";
	}
}
