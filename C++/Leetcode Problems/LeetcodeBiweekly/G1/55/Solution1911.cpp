// 1911. Maximum Alternating Subsequence Sum
/*
The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the 
sum of the elements at odd indices.

    For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.

Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the 
elements of the subsequence).

A subsequence of an array is a new array generated from the original array by deleting some elements 
(possibly none) without changing the remaining elements' relative order. 

For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

Example 1:

Input: nums = [4,2,5,3]
Output: 7
Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.

Example 2:

Input: nums = [5,6,7,8]
Output: 8
Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.

Example 3:

Input: nums = [6,2,1,2,4,5]
Output: 10
Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.

Constraints:

    1 <= nums.length <= 10^5
    1 <= nums[i] <= 10^5
*/

/*
TLE: 13 / 65

class Solution {
public:
    
    long long dfs(vector<int>&nums, int sz, int evnsm, int oddsm, int cursz, int idx){
        if(idx>=sz){
            return evnsm-oddsm;
        }
        long long ans=INT_MIN;
        long long ntpk=0, pk=0;
        ntpk=dfs(nums, sz, evnsm, oddsm, cursz, idx+1);
        if(cursz%2==0){
            int oddsmcpy=oddsm;
            oddsmcpy+=nums[idx];
            pk=dfs(nums, sz, evnsm, oddsmcpy, cursz+1, idx+1);
        } else{
            int evnsmcpy=evnsm;
            evnsmcpy+=nums[idx];
            pk=dfs(nums, sz, evnsmcpy, oddsm, cursz+1, idx+1);
        }
        ans=max(ans, max(ntpk, pk));
        return ans;
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int sz=nums.size();
        vector<int>subseq;
        int cursz=-1;
        return dfs(nums, sz, 0, 0, cursz, 0);
    }
};
*/

// -------*******-------

/*
TLE: 13 / 65

class Solution {
public:
    
    long long dfs(vector<int>&nums, vector<int>&subseq, int sz, int idx){
        if(idx>=sz){
            int smevn=0, smodd=0;
            int sz_=subseq.size();
            for(int i=0; i<sz_; ++i){
                if(i%2==0){
                    smevn+=subseq[i];
                } else{
                    smodd+=subseq[i];
                }
            }
            return smevn-smodd;
        }
        long long ans=INT_MIN;
        long long ntpk=0, pk=0;
        ntpk=dfs(nums, subseq, sz, idx+1);
        vector<int>subseqcpy=subseq;
        subseqcpy.push_back(nums[idx]);
        pk=dfs(nums, subseqcpy, sz, idx+1);
        ans=max(ans, max(ntpk, pk));
        return ans;
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int sz=nums.size();
        vector<int>subseq;
        return dfs(nums, subseq, sz, 0);
    }
};
*/

class Solution {
public:
    
    long long dfs(vector<int>&nums, int sz, bool flag, int idx, vector<vector<long long>>&memo){
        if(idx>=sz){
            return 0;
        }
        if(memo[idx][flag]!=-1) return memo[idx][flag];
        long long ans=0;
        long long ntpk=0, pk=0;
        ntpk=dfs(nums, sz, flag, idx+1, memo);
        if(flag){
            pk+=nums[idx];
            pk+=dfs(nums, sz, false, idx+1, memo);
        } else{
            pk-=nums[idx];
            pk+=dfs(nums, sz, true, idx+1, memo);
        }
        return memo[idx][flag]=max(pk, ntpk);
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        int sz=nums.size();
        vector<vector<long long>>memo(sz+1, vector<long long>(2, -1));
        return dfs(nums, sz, 1, 0, memo);
    }
};