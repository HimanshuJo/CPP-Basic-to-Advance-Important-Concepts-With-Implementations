/*
Is it possible to generate a target sum, given an array of number
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<map>
using namespace std;

// O(len(Numbers)^targetSum)
bool canSumSp(int targetSum, vector<int>&numbers){
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	for(auto &num: numbers){
		int remain=targetSum-num;
		if(canSumSp(remain, numbers)) return true;
	}
	return false;
}

// O(targetSum*len(Numbers))
bool canSumDp(int targetSum, vector<int>&numbers, map<int, bool>&memo){
	if(targetSum==0) return true;
	if(targetSum<0) return false;
	if(memo.find(targetSum)!=memo.end()) return memo[targetSum];
	for(auto &num: numbers){
		int remain=targetSum-num;
		if(canSumDp(remain, numbers, memo)) return memo[targetSum]=true;
	}
	return memo[targetSum]=false;
}

// O(targetSum*len(Numbers))
bool canSumTab(int targetSum, vector<int>&numbers){
	vector<bool> dp(targetSum+10, false);
	dp[0]=true;
	for(int i=0; i<=targetSum; ++i){
		if(dp[i]==true){
			for(auto &vals: numbers){
				dp[i+vals]=true;
			}
		}
	}
	return dp[targetSum];
}

int main(){
	int targetSum=5000;
	vector<int>numbers{5, 3, 9, 17};
	map<int, bool>memo;
	//bool ans1=canSumSp(targetSum, numbers);
	bool ans2=canSumDp(targetSum, numbers, memo);
	bool ans3=canSumTab(targetSum, numbers);
	//cout<<(ans1==1?"true":"false")<<"\n";
	cout<<(ans2==1?"true":"false")<<"\n";
	cout<<(ans3==1?"true":"false")<<"\n";
}
