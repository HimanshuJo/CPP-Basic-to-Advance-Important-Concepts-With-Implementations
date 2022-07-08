#include<climits>
#include<vector>
#include<iostream>
using namespace std;

int dfs(vector<int>&nums, const int sz, int idx, vector<int>&memo){
    if(idx>=sz) return 0;
    if(memo[idx]!=0) return memo[idx];
    int ans=INT_MIN;
    int pk=nums[idx]+dfs(nums, sz, idx+2, memo);
    int ntpk=0+dfs(nums, sz, idx+1, memo);
    ans=max(ans, max(pk, ntpk));
    return memo[idx]=ans;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int sz=nums.size();
    vector<int>dp(sz, 0);
    for(int idx=0; idx<sz; ++idx){
        int pk=nums[idx], ntpk=0;
        if(idx>=2){
            pk+=dp[idx-2];
        }
        if(idx-1>=0)
            ntpk=dp[idx-1];
        dp[idx]=max(pk, ntpk);
    }
    for(auto &vals: dp)
       cout<<vals<<" ";
    return 0;
}

int main(){
    vector<int>nums{2, 1, 4, 9};
    int ans=maximumNonAdjacentSum(nums);
    cout<<ans<<endl;
}