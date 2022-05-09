/*
Best way to generate a target sum from an array of numbers. 
Numbers of an array can be used any number of times
*/

#include<vector>
#include<map>
#include<iostream>
using namespace std;

// T: O((n^m)*m), S: O(m*m)
vector<int> bestSum(vector<int>&numbers, int targetSum){
	if(targetSum==0) return {};
	if(targetSum<0) return {INT_MAX};
	vector<int>shortestCombo;
	for(auto &vals: numbers){
		int remain=targetSum-vals;
		vector<int>remainCombo=bestSum(numbers, remain);
		if(remainCombo.size()>0&&remainCombo[0]==INT_MAX) continue;
		vector<int>currCombo;
		for(auto &nums: remainCombo){
			currCombo.push_back(nums);
		}
		currCombo.push_back(vals);
		if(shortestCombo.size()==0||currCombo.size()<shortestCombo.size()){
			shortestCombo=currCombo;
		}
	}
	return shortestCombo;
}

// T: O((m*n)*m), S: O(m*m)
vector<int> bestSumDp(vector<int>&numbers, int targetSum, map<int, vector<int>>&memo){
	if(targetSum==0) return {};
	if(targetSum<0) return {INT_MAX};
	if(memo.find(targetSum)!=memo.end()) return memo[targetSum];
	vector<int>shortestCombo;
	for(auto &vals: numbers){
		int remain=targetSum-vals;
		vector<int>remainCombo=bestSumDp(numbers, remain, memo);
		if(remainCombo.size()>0&&remainCombo[0]==INT_MAX) continue;
		vector<int>currCombo;
		for(auto &nums: remainCombo){
			currCombo.push_back(nums);
		}
		currCombo.push_back(vals);
		if(shortestCombo.size()==0||currCombo.size()<shortestCombo.size()){
			shortestCombo=currCombo;
		}
	}
	return memo[targetSum]=shortestCombo;
}

// T: O((m*n)*m), S: O(m*m)
vector<int> bestSumTab(vector<int>&numbers, int targetSum){
	vector<vector<int>>dp(targetSum+targetSum);
	for(int i=0; i<dp.size(); ++i)
		dp[i].push_back({INT_MAX});
	vector<int>toChk={INT_MAX};
	dp[0]={};
	for(int i=0; i<=targetSum; ++i){
		if(dp[i]!=toChk){
			vector<int>currComb=dp[i];
			for(auto &num: numbers){
				vector<int>newCombo;
				newCombo.push_back(num);
				for(auto &num: currComb)
					newCombo.push_back(num);
				if(dp[i+num].size()>newCombo.size()||dp[i+num]==toChk){
					dp[i+num]=newCombo;
				}
			}
		}
	}
	return dp[targetSum];
}

int main(){
	vector<int>numbers{1, 3, 4, 5};
	vector<int>numbers2{1, 3, 4, 5};
	map<int, vector<int>>memo;
	int targetSum=10;
	int targetSum2=7;
	vector<int>ans1=bestSum(numbers, targetSum);
	vector<int>ans2=bestSumDp(numbers2, targetSum2, memo);
	vector<int>ans3=bestSumTab(numbers2, targetSum2);
	for(auto &vals: ans1){
		cout<<vals<<" ";
	}
	cout<<"\n-------\n";
	for(auto &vals: ans2){
		cout<<vals<<" ";
	}
	cout<<"\n-------\n";
	for(auto &vals: ans3){
		cout<<vals<<" ";
	}
}

/*
Output:

4 4 2
-------
25 25 25 25
-------
25 25 25 25
*/