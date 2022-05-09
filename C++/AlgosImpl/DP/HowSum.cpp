#include<vector>
#include<iostream>
#include<map>
using namespace std;

// T: O(len(in)^targetSum), S: O(len(in))
int howSum(int targetSum, vector<int>&in, vector<int>&res){
	if(targetSum==0) return 1;
	if(targetSum<0) return INT_MAX;
	for(auto &vals: in){
		int remain=targetSum-vals;
		int currRes=howSum(remain, in, res);
		if(currRes!=INT_MAX){
			res.push_back(vals);
			return 1;
		}
	}
	return INT_MAX;
}

// O(len(in)*targetSum^2), S: O(targetSum*targetSum)
vector<int> howSumDp(int targetSum, vector<int>&in, vector<int>&res, map<int, vector<int>>&memo){
	if(targetSum==0) return res;
	if(targetSum<0) return {INT_MAX};
	auto it=memo.find(targetSum);
	if(it!=memo.end()){
		return memo[targetSum];
	}
	for(auto &vals: in){
		int remain=targetSum-vals;
		vector<int>currRes=howSumDp(remain, in, res, memo);
		if(currRes.size()>0&&currRes[0]==INT_MAX) continue;
		res.push_back(vals);
		return memo[targetSum]=res;
	}
	return memo[targetSum]={INT_MAX};
}

// O(len(in)*targetSum^2), S: O(targetSum*targetSum)
vector<int> howSumTab(int targetSum, vector<int>&in, vector<int>&res){
	vector<vector<int>>dp(targetSum+targetSum);
	for(int i=0; i<dp.size(); ++i)
		dp[i].push_back({INT_MAX});
	vector<int>toChk={INT_MAX};
	dp[0]={};
	for(int i=0; i<in.size(); ++i){
		if(dp[i]!=toChk){
			dp[i].push_back(in[i]);
			vector<int>curr=dp[i];
			for(int j=i; j<in.size(); ++j){
				for(auto &vals: curr)
					dp[i+in[j]].push_back(vals);
			}
		}
	}
	return dp[targetSum];
}

int main(){
	vector<int>in{2, 14};
	int targetSum=100;
	vector<int>res;
	map<int, vector<int>>memo;
	//howSum(targetSum, in, res);
	howSumDp(targetSum, in, res, memo);
	if(res.size()==0) cout<<"null\n";
	for(auto &nums: res){
		cout<<nums<<" ";
	}
	cout<<"\n-------\n";
	howSumTab(targetSum, in, res);
	if(res.size()==0) cout<<"null\n";
	for(auto &nums: res)
		cout<<nums<<" ";
}

/*
Output:

2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
-------
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
*/