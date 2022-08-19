// 2009. Minimum Number of Operations to Make Array Continuous
/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.

 

Example 1:

Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.
Example 2:

Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.
Example 3:

Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
*/
/*
TLE: 49 / 62

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz=nums.size();
        int curmin=nums[0];
        int ans=INT_MAX;
        for(int i=0; i<sz; ++i){
            int curans=0;
            int curnm=nums[i];
            for(int j=0; j<sz; ++j){
                auto it=find(nums.begin(), nums.end(), curnm);
                if(it==nums.end()){
                    curans++;
                }
                curnm++;
            }
            ans=min(ans, curans);
        }
        return ans;
    }
};
*/

class Solution {
public:
    
    int minOperations(vector<int>& nums) {
        int sz=nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int curmin=nums[0];
        int ans=INT_MAX;
        int sz_=nums.size();
        for(int i=0; i<sz_; ++i){
            int curnm=nums[i];
            int lastnum=curnm+sz-1;
            int curans=upper_bound(nums.begin(), nums.end(), lastnum)-nums.begin();
            ans=min(ans, sz-(curans-i));
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
public:
    int minOperations(vector<int>& nums) {
        int sz=nums.size();
        int ans=sz, j=0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int sz_=nums.size();
        for(int i=0; i<sz_; ++i){
            while(j<sz_&&nums[j]<nums[i]+sz) ++j;
            ans=min(ans, sz-j+i);
        }
        return ans;
    }
};