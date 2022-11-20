// E - Knapsack 2
/*
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi

Taro has decided to choose some of the N items and carry them home in a knapsack.

The capacity of the knapsack is W, which means that the sum of the weights of items taken must be at most W

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^9
 
1≤wi≤W
1≤vi≤10^3

Sample Input 1 
3 8
3 30
4 50
5 60

Sample Output 1
90
*/

#include<iostream>
#define ll long long
using namespace std;

const int MAXV=1e5+10;
const int MAXN=1e3+10;
const ll INF=1e13;

ll dp[MAXV];
int N, W, V, wi[MAXN], val[MAXN];

int main(){
	cin>>N>>W;
	for(int i=1; i<=N; ++i){
		cin>>wi[i]>>val[i];
		V+=val[i];
	}
	for(int i=1; i<=V; ++i){
		dp[i]=INF;
	}
	dp[0]=0;
	for(int item=1; item<=N; ++item){
		int w=wi[item], v=val[item];
		for(int i=V; i>=v; --i){
			dp[i]=min(dp[i], dp[i-v]+w);
		}
	}
	for(int i=V; i>=0; --i){
		if(dp[i]<=W){
			cout<<i<<endl;
			break;
		}
	}
	return 0;
}
