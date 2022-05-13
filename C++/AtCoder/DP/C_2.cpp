// C - Vacation
/*
Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1≤i≤N), 
Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain ai points of happiness.
B: Catch bugs in the mountains. Gain bi points of happiness.
C: Do homework at home. Gain ci points of happiness.

As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.

Constraints
All values in input are integers.
	
	1≤N≤10^5
 
	1≤ai,bi,ci≤10^4
*/

#include<iostream>
#include<climits>
using namespace std;

const int MAXN=100010;

int memo[MAXN][3], in[3][MAXN], N;

int dfs(int idx, int curRoutine){
	if(idx==N+1) return 0;
	if(memo[idx][curRoutine]!=-1) return memo[idx][curRoutine];
	int curans=INT_MIN;
	for(int routine=0; routine<3; ++routine){
		if(routine!=curRoutine){
			curans=max(curans, in[routine][idx]+dfs(idx+1, routine));
		}
	}
	return (memo[idx][curRoutine]=curans);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<MAXN; ++i){
		for(int j=0; j<3; ++j){
			memo[i][j]=-1;
		}
	}
	for(int i=1; i<=N; ++i){
		scanf("%d %d %d", &in[0][i], &in[1][i], &in[2][i]);
	}
	printf("%d\n", max(dfs(1, 0), max(dfs(1, 1), dfs(1, 2))));
	return 0;
}