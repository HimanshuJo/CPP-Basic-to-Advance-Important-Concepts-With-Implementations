// 2289. Steps to Make Array Non-decreasing
/*
You are given a 0-indexed integer array nums. 

In one step, remove all elements nums[i] where nums[i - 1] > nums[i] for all 0 < i < nums.length.

Return the number of steps performed until nums becomes a non-decreasing array.

Example 1:

Input: nums = [5,3,4,4,7,3,6,11,8,5,11]
Output: 3
Explanation: The following are the steps performed:
- Step 1: [5,3,4,4,7,3,6,11,8,5,11] becomes [5,4,4,7,6,11,11]
- Step 2: [5,4,4,7,6,11,11] becomes [5,4,7,11,11]
- Step 3: [5,4,7,11,11] becomes [5,7,11,11]
[5,7,11,11] is a non-decreasing array. Therefore, we return 3.
Example 2:

Input: nums = [4,5,7,7,13]
Output: 0
Explanation: nums is already a non-decreasing array. Therefore, we return 0.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/

/*
TLE: 79 / 86

TC: O(n*n*n)
class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int sz=nums.size();
        int ans=0;
        for(int i=0; i<sz; ++i){
            bool flag=false;
            vector<int>idxes;
            for(int j=i; j<sz; ++j){
                if(j-1>=0){
                    if(nums[j]!=-1&&nums[j-1]>nums[j]){
                        flag=true;
                        idxes.push_back(j);
                    }
                }
            }
            for(auto &vals: idxes){
                nums[vals]=-1;
            }
            if(flag){
                ans++;
                nums.erase(remove(nums.begin(), nums.end(), -1), nums.end());
                sz=nums.size();
                i=-1;
            }
        }
        return ans;
    }
};
*/

// TC O(n)  n: size of nums
// SC O(n)
class Solution1 {
public:
    int totalSteps(vector<int>& nums) {
        int sz=nums.size(), res=0;
        stack<int>stk;
        vector<int>dp(sz, 0);
        for(int i=sz-1; i>=0; --i){
            while(!stk.empty()&&nums[i]>nums[stk.top()]){
                dp[i]=max(++dp[i], dp[stk.top()]);
                stk.pop();
                res=max(res, dp[i]);
            }
            stk.push(i);
        }
        return res;
    }
};

// TC O(n)  n: size of nums
// SC O(n)
class Solution2 {
public:
    int totalSteps(vector<int>& nums) {
        int sz=nums.size();
        vector<int>dp(sz, 0);
        stack<int>stk;
        for(int i=0; i<sz; ++i){
            int curr=0;
            while(!stk.empty()&&nums[i]>=nums[stk.top()]){
                curr=max(curr, dp[stk.top()]);
                stk.pop();
            }
            if(!stk.empty())
                dp[i]=curr+1;
            stk.push(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};