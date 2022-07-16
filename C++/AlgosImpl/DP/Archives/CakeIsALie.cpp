// B. The Cake Is a Lie
/*
There is a n×m grid. You are standing at cell (1,1) and your goal is to finish at cell (n,m).

You can move to the neighboring cells to the right or down. 
In other words, suppose you are standing at cell (x,y). You can:

move right to the cell (x,y+1) — it costs x burles;
move down to the cell (x+1,y) — it costs y burles.
Can you reach cell (n,m) spending exactly k burles?

Input
The first line contains the single integer t (1≤t≤100) — the number of test cases.

The first and only line of each test case contains three integers n, m, and k 
(1≤n,m≤100; 0≤k≤104) — the sizes of grid and the exact amount of money you need to spend.

Output
For each test case, if you can reach cell (n,m) spending exactly k burles, print YES. Otherwise, print NO.

You may print every letter in any case you want 
(so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
input
6
1 1 0
2 2 2
2 2 3
2 2 4
1 4 3
100 100 10000

output
YES
NO
YES
NO
YES
NO

Note
In the first test case, you are already in the final cell, so you spend 0 burles.

In the second, third and fourth test cases, there are two paths from (1,1) to (2,2): 
(1,1) → (1,2) → (2,2) or (1,1) → (2,1) → (2,2). Both costs 1+2=3 burles, so it's the only amount of money you can spend.

In the fifth test case, there is the only way from (1,1) to (1,4) and it costs 1+1+1=3 burles.
*/
/*
Solution:

Note that whichever path you choose, the total cost will be the same. 
If you know that the cost is the same, then it's not hard to calculate it. 
It's equal to n⋅m−1. So the task is to check: is k equal to n⋅m−1 or not.

The constant cost may be proved by induction on n+m: for n=m=1 cost is 1⋅1−1=0. 
For a fixed (n,m), there are only two last steps you can make:

either from (n,m−1) with cost n: the total cost is n⋅(m−1)−1+n = n⋅m−1
or from (n−1,m) with cost m: the total cost is (n−1)⋅m−1+m = n⋅m−1.
So, whichever path you choose, the total cost is the same.
*/

#include<iostream>
using namespace std;

int memo[101][101];

int dfs(int n, int m){
	if(n==1&&m==1) return 0;
	if(memo[n][m]!=-1) return memo[n][m];
	if(n==1) return m-1;
	if(m==1) return n-1;
	return (memo[n][m]=min(n+dfs(n, m-1), m+dfs(n-1, m)));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		for(int i=0; i<=100; ++i){
			for(int j=0; j<=100; ++j){
				memo[i][j]=-1;
			}
		}
		int res=dfs(n, m);
		if(res==k) cout<<"YES\n";
		else cout<<"NO\n";
	}
}