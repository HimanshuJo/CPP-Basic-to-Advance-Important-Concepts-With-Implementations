// Different ways to sum n using numbers greater than or equal to m
/*
Given two natural number n and m. The task is to find the number of ways in which the numbers 
that are greater than or equal to m can be added to get the sum n.
Examples: 
 

Input : n = 3, m = 1
Output : 3
Following are three different ways
to get sum n such that each term is
greater than or equal to m
1 + 1 + 1, 1 + 2, 3 

Input : n = 2, m = 1
Output : 2
Two ways are 1 + 1 and 2
*/
/*
Bottom up dp:

The idea is to use Dynamic Programming by define 2D matrix, say dp[][]. dp[i][j] define 
the number of ways to get sum i using the numbers greater than or equal to j. 

So dp[i][j] can be defined as:
 

    If i < j, dp[i][j] = 0, because we cannot achieve smaller sum of i using numbers greater than or equal to j.
    If i = j, dp[i][j] = 1, because there is only one way to show sum i using number i which is equal to j.
    Else dp[i][j] = dp[i][j+1] + dp[i-j][j], because obtaining a sum i using numbers greater than 
    or equal to j is equal to the sum of obtaining a sum of i using numbers greater than or equal to 
    j+1 and obtaining the sum of i-j using numbers greater than or equal to j.
*/
/*
Solution2:

#include<iostream>
#include<vector>
using namespace std;

int diffWaysSumGrEqM(int n, int m){
	vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
	dp[0][n+1]=1;
	for(int num=n; num>=m; --num){
		for(int sum=0; sum<=n; ++sum){
			dp[sum][num]=dp[sum][num+1];
			if(sum-num>=0){
				dp[sum][num]+=dp[sum-num][num];
			}
		}
	}
	return dp[n][m];
}

int main(){
	int n=30, m=1;
	int ans=diffWaysSumGrEqM(n, m);
	cout<<ans<<endl;
}
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>res;

int dfs(int n, int m, int runN, int currSum, vector<int>temp){
	if(runN<m) return 0;
	if(currSum>n) return 0;
	if(currSum==n){
		res.push_back(temp);
		return 1;
	}
	currSum+=runN;
	temp.push_back(runN);
	int lft=dfs(n, m, runN, currSum, temp);
	currSum-=runN;
	temp.pop_back();
	int rght=dfs(n, m, runN-1, currSum, temp);
	return lft+rght;
}

int diffWaysSumGrEqM(int n, int m){
	int bgn=n;
	int currSum=0;
	vector<int>temp;
	return dfs(n, m, bgn, currSum, temp);
}

int main(){
	int n=1, m=10;
	int ans=diffWaysSumGrEqM(n, m);
	cout<<ans<<endl;
	cout<<"-------\n";
	for(auto &entries: res){
		for(auto &vals: entries){
			cout<<vals<<" ";
		}
		cout<<endl;
	}
}