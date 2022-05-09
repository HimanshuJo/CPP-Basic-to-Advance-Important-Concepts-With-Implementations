#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int sm=0, n=nums.size(), res=0;
        int dp[1<<n];
        memset(dp, 0, sizeof(dp));
        for(int x: nums)
            sm|=x;
        for(int mask=1; mask<(1<<n); ++mask){
            int lbit=mask&-mask;
            dp[mask]=dp[mask-lbit]|nums[__builtin_ctz(lbit)];
            if(dp[mask]==sm) res++;
        }
        return res;
    }
};