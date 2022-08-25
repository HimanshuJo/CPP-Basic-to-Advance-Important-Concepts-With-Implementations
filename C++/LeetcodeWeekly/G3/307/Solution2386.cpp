// 2386. Find the K-Sum of an Array
/*
You are given an integer array nums and a positive integer k. You can choose any 
subsequence of the array and sum all of its elements together.

We define the K-Sum of the array as the kth largest subsequence sum that can be obtained (not necessarily distinct).

Return the K-Sum of the array.

A subsequence is an array that can be derived from another array by deleting some or no elements 
without changing the order of the remaining elements.

Note that the empty subsequence is considered to have a sum of 0.

Example 1:

Input: nums = [2,4,-2], k = 5
Output: 2
Explanation: All the possible subsequence sums that we can obtain are the following sorted in decreasing order:
- 6, 4, 4, 2, 2, 0, 0, -2.
The 5-Sum of the array is 2.
Example 2:

Input: nums = [1,-2,3,4,-10,12], k = 16
Output: 10
Explanation: The 16-Sum of the array is 10.
 

Constraints:

n == nums.length
1 <= n <= 10^5
-10^9 <= nums[i] <= 10^9
1 <= k <= min(2000, 2n)
*/

/*
MLE, TLE: 34 / 111

class Solution {
public:
    
    void dfs(vector<int>&nums, int sz, vector<long long>&ans, int idx, long long sm){
        if(idx>=sz) return;
        dfs(nums, sz, ans, idx+1, sm);
        sm+=nums[idx];
        ans.push_back(sm);
        dfs(nums, sz, ans, idx+1, sm);
    }
    
    long long kSum(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<long long>ans;
        ans.push_back(0);
        dfs(nums, sz, ans, 0, 0);
        sort(ans.begin(), ans.end());
        int idx=ans.size()-k;
        return ans[idx];
    }
};
*/

class Solution {
public:
    
    long long kSum(vector<int>& nums, int k) {
        int sz=nums.size();
        long long maxsm=0;
        for(auto &vals: nums){
            if(vals>0){
                maxsm+=vals;
            } else{
                vals=abs(vals);
            }
        }
        sort(nums.begin(), nums.end());
        vector<long long>subtr;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.push({nums[0], 0});
        while(!pq.empty()&&subtr.size()<k){
            long long cursm=pq.top().first, curidx=pq.top().second;
            pq.pop();
            subtr.push_back(cursm);
            if(curidx+1<=sz-1){
                pq.push({cursm+nums[curidx+1], curidx+1});
                /*
                    Not only the curr num getting it's current index but a sum associated with
                    it is also getting the same index
                */
                pq.push({nums[curidx+1]+(cursm-nums[curidx]), curidx+1});
            }
        }
        vector<long long>ans;
        ans.push_back(maxsm);
        for(auto &vals: subtr){
            ans.push_back(maxsm-vals);
        }
        return ans[k-1];
    }
};