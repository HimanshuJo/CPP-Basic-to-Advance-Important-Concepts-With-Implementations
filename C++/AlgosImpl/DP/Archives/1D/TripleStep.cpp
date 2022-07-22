// Count number of ways to reach the last step if at a time you can 
// perform 1 jump, 2 jump and 3 jumps

#include<iostream>
#include<cstring>
using namespace std;

int countWays(int n, int memo[]){
	if(n<0) return 0;
	else if(n==0) return 1;
	else if(memo[n]!=-1) return memo[n];
	memo[n]=countWays(n-1, memo)+countWays(n-2, memo)+countWays(n-3, memo);
	return memo[n];
}

int countWays(int n){
	int memo[n+1];
	memset(memo, -1, sizeof(memo));
	return countWays(n, memo);
}

int main(){
	int N=10;
	cout<<countWays(N);
}
