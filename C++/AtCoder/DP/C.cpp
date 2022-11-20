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

Sample Input1:

3
10 40 70
20 50 80
30 60 90

Sample Output1:
210
*/

#include<iostream>
#include<vector>
#include<climits>
#include<map>
using namespace std;

const int MAXN=100010;

class Solution1{
public:
	int dfs(vector<vector<int>>&in, int N, int idx, bool smflag, bool mnflag, bool hmflag,
			vector<vector<vector<vector<int>>>>&memo){
		if(idx>=N) return 0;
		if(memo[idx][smflag][mnflag][hmflag]!=-1) return memo[idx][smflag][mnflag][hmflag];
		int curans=INT_MIN;
		int sm=0, mn=0, hm=0;
		if(!smflag){
			sm+=in[idx][0]+dfs(in, N, idx+1, true, false, false, memo);
		} 
		if(!mnflag){
			mn+=in[idx][1]+dfs(in, N, idx+1, false, true, false, memo);
		}
		if(!hmflag){
			hm+=in[idx][2]+dfs(in, N, idx+1, false, false, true, memo);
		}
		curans=max(curans, max(sm, max(mn, hm)));
		return (memo[idx][smflag][mnflag][hmflag]=curans);
	}
};

class Solution2{
public:
	int dfs(vector<vector<int>>&in, int N, int idx, bool smflag, bool mnflag, bool hmflag,
			map<tuple<int, bool, bool, bool>, int>&memo){
		if(idx>=N) return 0;
		tuple<int, bool, bool, bool>tmp(idx, smflag, mnflag, hmflag);
		if(memo.find(tmp)!=memo.end()) return memo[tmp];
		int curans=INT_MIN;
		int sm=0, mn=0, hm=0;
		if(!smflag){
			sm+=in[idx][0]+dfs(in, N, idx+1, true, false, false, memo);
		} 
		if(!mnflag){
			mn+=in[idx][1]+dfs(in, N, idx+1, false, true, false, memo);
		}
		if(!hmflag){
			hm+=in[idx][2]+dfs(in, N, idx+1, false, false, true, memo);
		}
		curans=max(curans, max(sm, max(mn, hm)));
		return memo[tmp]=curans;
	}
};

class Solution3{
    public:
    int dfs(vector<vector<int>>&in, int idx, int curRoutine, int N, int memo[MAXN][3]){
        if(idx>=N) return 0;
        if(memo[idx][curRoutine]!=-1) return memo[idx][curRoutine];
        int curans=INT_MIN;
        for(int routine=0; routine<3; ++routine){
            if(routine!=curRoutine){
                curans=max(curans, in[idx][routine]+dfs(in, idx+1, routine, N, memo));
            }
        }
        return (memo[idx][curRoutine]=curans);
    }
};

int main(){
	int N;
	cin>>N;
	Solution1 obj1;
	Solution2 obj2;
    Solution3 obj3;
    vector<vector<vector<vector<int>>>>memo1(N+1, vector<vector<vector<int>>>(N+1, vector<vector<int>>(N+1, vector<int>(N+1, -1))));
	map<tuple<int, bool, bool, bool>, int>memo2;
    int memo3[MAXN][3];
	vector<vector<int>>in(N, vector<int>(3, 0));
	for(int i=0; i<N; ++i){
		for(int j=0; j<3; ++j){
			cin>>in[i][j];
		}
	}
    for(int i=0; i<MAXN; ++i){
		for(int j=0; j<3; ++j){
			memo3[i][j]=-1;
		}
	}
	int ans1=obj1.dfs(in, N, 0, false, false, false, memo1);
	cout<<ans1<<endl;
	int ans2=obj2.dfs(in, N, 0, false, false, false, memo2);
	cout<<ans2<<endl;
    int ans3=max(obj3.dfs(in, 0, 0, N, memo3), max(obj3.dfs(in, 0, 1, N, memo3), obj3.dfs(in, 0, 2, N, memo3)));
    cout<<ans3<<endl;
}