// 2334. Subarray With Elements Greater Than Varying Threshold
/*
You are given an integer array nums and an integer threshold.

Find any subarray of nums of length k such that every element in the subarray is greater than threshold / k.

Return the size of any such subarray. If there is no such subarray, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,4,3,1], threshold = 6
Output: 3
Explanation: The subarray [3,4,3] has a size of 3, and every element is greater than 6 / 3 = 2.
Note that this is the only valid subarray.
Example 2:

Input: nums = [6,5,6,5,8], threshold = 7
Output: 1
Explanation: The subarray [8] has a size of 1, and 8 > 7 / 1 = 7. So 1 is returned.
Note that the subarray [6,5] has a size of 2, and every element is greater than 7 / 2 = 3.5. 
Similarly, the subarrays [6,5,6], [6,5,6,5], [6,5,6,5,8] also satisfy the given conditions.
Therefore, 2, 3, 4, or 5 may also be returned.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i], threshold <= 10^9
*/

/*
TLE: 39 / 68

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int sz=nums.size();
        for(int i=0; i<sz-1; ++i){
            if(nums[i]>threshold) return 1;
            priority_queue<int, vector<int>, greater<>>pq;
            pq.push(nums[i]);
            for(int j=i+1; j<sz; ++j){
                pq.push(nums[j]);
                int sz_=pq.size();
                int tp=pq.top();
                if(tp>threshold/sz_) return pq.size();
            }
        }
        return -1;
    }
};

// *******-------*******

TLE: 67 / 68

class Solution {
public:
    
    int dfs(vector<int>&nums, int threshold, int left, int right){
        if(left>right) return 0;
        if((right-left+1)!=0){
            int minval=threshold/(right-left+1);
            for(int i=left; i<=right; ++i){
                if(nums[i]<=minval){
                    int subres=dfs(nums, threshold, left, i-1);
                    if(subres) return subres;
                    subres=dfs(nums, threshold, i+1, right);
                    if(subres) return subres;
                    return 0;
                }
            }
            return right-left+1;
        }
        return 0;
    }
    
    int validSubarraySize(vector<int>& nums, int threshold) {
        int res=dfs(nums, threshold, 0, nums.size()-1);
        return res==0?-1:res;
    }
};
*/

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int sz=nums.size();
        stack<int>stk;
        vector<int>left(sz, -1), right(sz, sz);
        for(int i=0; i<sz; ++i){
            while(!stk.empty()&&nums[stk.top()]>=nums[i]){
                stk.pop();
            }
            left[i]=stk.empty()?-1:stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=sz-1; i>=0; --i){
            while(!stk.empty()&&nums[stk.top()]>nums[i]){
                stk.pop();
            }
            right[i]=stk.empty()?sz:stk.top();
            stk.push(i);
        }
        for(int i=0; i<sz; ++i){
            int len=abs(right[i]-left[i]-1);
            if(nums[i]>(threshold/len)){
                return len;
            }
        }
        return -1;
    }
};