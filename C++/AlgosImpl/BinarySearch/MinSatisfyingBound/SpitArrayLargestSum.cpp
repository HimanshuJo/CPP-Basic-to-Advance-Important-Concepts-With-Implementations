// 410. Split Array Largest Sum
/*
Given an array nums which consists of non-negative integers and an integer m, you can 
split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.

If we can split the array into several subarrays such that every subarray-sum is less than or equal to threshold. 
In this way, we discover the monotonicity of the problem: 
if feasible(m) is True, then all inputs larger than m can satisfy feasible function

def splitArray(nums: List[int], m: int) -> int:        
    def feasible(threshold) -> bool:
        count = 1
        total = 0
        for num in nums:
            total += num
            if total > threshold:
                total = num
                count += 1
                if count > m:
                    return False
        return True

    left, right = max(nums), sum(nums)
    while left < right:
        mid = left + (right - left) // 2
        if feasible(mid):
            right = mid     
        else:
            left = mid + 1
    return left
*/

/*
DP

Step 1: construct a prefix sum

Step 2: the dp[i][j] means the min of the max sum among j splits in arr[0 to i], 0 and i are inclusive

Step 3: init dp, init all dp[i][1] to prefix sum, since it does not split (only one group together)

Step 4: iterating all the dp[i][j]
for i in [0, n - 1]:
for j in [2, m]:
for k in all possible splitting point in (this time we split only once, since the subproblem has been solved)
[ 0 <- k -> (splitted with j - 1times)| (altogether, so not split) ]
max(dp[k][j - 1], |prefix_sum[i] - prefix_sum[k]))

Analysis:

Time complexity: O(m * n * n)
Space complexoty: O(m * n)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();

        vector<unsigned int> prefix_sum(n, 0);
        vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, INT_MAX));
        prefix_sum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        for (int i = 0; i < n; i++) {
            dp[i][1] = prefix_sum[i];
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 2; j <= m; j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefix_sum[i] - prefix_sum[k]));
                }
            }
        }
        return dp[n - 1][m];
    }
};
*/

/*
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> memo(nums.size(), vector<int>(m, INT_MIN));
        return DFS_split(nums, 0, m, memo);
    }
    int DFS_split(vector<int>& nums, int istart, int m, vector<vector<int>>& memo) {
        if (m == 0 && istart < nums.size()) return -1;
        if (istart == nums.size()) {
            return m == 0? 0 : -1;
        }
        if (memo[istart][m-1] != INT_MIN) return memo[istart][m-1];
        int curr_sum = 0;
        int ans = INT_MAX;
        for (int i = istart; i < nums.size(); ++i) {
            curr_sum += nums[i];
            int rest_max_splits = nums.size()-(i+1);
            if (rest_max_splits < m-1) break;
            int rest_max_sum = DFS_split(nums, i+1, m-1, memo);
            if (rest_max_sum == -1) continue;
            int curr_split_max_sum = std::max(curr_sum, rest_max_sum);
            ans = std::min(ans, curr_split_max_sum);
        }
        memo[istart][m-1] = ans;
        return ans;
    }
};
*/

class Solution {
public:

    bool isValid(vector<int>&nums, int m, int val){
        int count=1;
        int total=0;
        for(auto &num: nums){
            if(total+num>val){
                total=num;
                count++;
                if(count>m) return false;
            } else{
                total+=num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int m) {
        int left=*max_element(nums.begin(), nums.end());
        int maxSm=0;
        for(auto &vals: nums)
            maxSm+=vals;
        int right=maxSm;
        int ans=0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(nums, m, mid)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};