// B - Frog 2
/*
There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.

There is a frog who is initially on Stone 1. 
He will repeat the following action some number of times to reach Stone N:

If the frog is currently on Stone i, jump to Stone i+1 or Stone i+2, ... i+K
Here, a cost of ∣hi−hj∣ is incurred, where j is the stone to land on.

Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints

All values in input are integers.

2<=N<=10^5
1≤K≤100
1<=hi<=10^4

Sample Input 2
3 1
10 20 10

Output
20
*/

#include<iostream>
#include<vector>
#include<climits>
#define INF INT_MAX
using namespace std;

const int MAXN=100001;
int dp[MAXN];

class Solution1{
    public:
    int minPossibleCost(vector<int>&heights, int N, int K){
        for(int i=2; i<=N; ++i){
            dp[i]=INF;
            for(int j=i-1; j>=max(i-K, 1); --j){
                dp[i]=min(dp[i], dp[j]+abs(heights[i]-heights[j]));
            }
        }
        return dp[N];
    }
};

class Solution2{
    public:
    int dfs(vector<int>&heights, int N, int K, int idx, vector<int>&memo){
        if(idx==N) return 0;
        if(memo[idx]!=-1) return memo[idx];
        int curans=INT_MAX;
        for(int i=1; i<=K; ++i){
            int curjmp=idx+i<=N?abs(heights[idx]-heights[idx+i])+dfs(heights, N, K, idx+i, memo):INT_MAX;
            curans=min(curans, curjmp);
        } 
        return (memo[idx]=curans);
    }
};

int main(){
	int N;
	cin>>N;
	int K;
	cin>>K;
	vector<int>heights(N+1, 0);
    vector<int>memo(N+1, -1);
    Solution1 obj1;
    Solution2 obj2;
	for(int i=1; i<=N; ++i){
		cin>>heights[i];
	}	
    int ans1=obj1.minPossibleCost(heights, N, K);
	int ans2=obj2.dfs(heights, N, K, 1, memo);
	cout<<ans1<<" "<<ans2<<endl;
}