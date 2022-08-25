#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0; i<n-1; ++i){
            int maxDiff=INT_MIN;
            for(int j=i+1; j<n; ++j){
                if(nums[j]-nums[i]>maxDiff){
                    maxDiff=nums[j]-nums[i];
                }
            }
            res=max(maxDiff, res);
        }
        return res==0?-1:res;
    }
};