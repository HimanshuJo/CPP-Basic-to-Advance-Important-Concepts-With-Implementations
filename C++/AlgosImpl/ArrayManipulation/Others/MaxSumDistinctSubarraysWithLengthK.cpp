// 2461. Maximum Sum of Distinct Subarrays With Length K
/*
You are given an integer array nums and an integer k. 
Find the maximum subarray sum of all the subarrays of nums that meet the 
following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. 
If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that 
meet the conditions

Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 10^5
1 <= nums[i] <= 10^5
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int sz=nums.size();
        int idx=0, bgnidx=0;
        unordered_map<int, int>mp;
        long long sm=0, ans=0;
        int count=k, count3=k;
        for(int i=0; i<sz; ++i){
            if(count==0) break;
            if(mp.find(nums[i])==mp.end()){
                mp[nums[i]]=nums[i];
                sm+=nums[i];
            }
            count--;
            idx=i;
        }
        idx++;
        bool flag3=false;
        if(mp.size()==k)
            ans=max(ans, sm);
        else{
            sm=0;
            flag3=true;
        }
        if(flag3){
            int tmpcount=k;
            long long tmsm=0;
            int tmpidx=idx-1;
            unordered_map<int, int>tmpmp;
            while(tmpidx<=sz-1){
                auto itr=tmpmp.find(nums[tmpidx]);
                if(itr!=tmpmp.end()) break;
                tmsm+=nums[tmpidx];
                tmpmp[nums[tmpidx]]=nums[tmpidx];
                tmpidx++;
                tmpcount--;
                if(tmpcount==0) break;
            }
            if(tmpcount==0)
                ans=max(ans, tmsm);
        }
        if(flag3){
            int tmpcount=k;
            long long tmsm=0;
            int tmpidx=idx-2;
            unordered_map<int, int>tmpmp;
            while(tmpidx<=sz-1){
                auto itr=tmpmp.find(nums[tmpidx]);
                if(itr!=tmpmp.end()) break;
                tmsm+=nums[tmpidx];
                tmpmp[nums[tmpidx]]=nums[tmpidx];
                tmpidx++;
                tmpcount--;
                if(tmpcount==0) break;
            }
            if(tmpcount==0)
                ans=max(ans, tmsm);
        }
        for(int i=idx; i<sz; ++i){
            auto itr=mp.find(nums[bgnidx]);
            if(bgnidx!=i-1){
                if(itr!=mp.end()&&nums[bgnidx]!=nums[i-1])
                    mp.erase(itr);
            } else mp.erase(itr);
            if(flag3){
                if(count3==0){
                    sm-=nums[bgnidx];
                } else{
                    count3--;
                }
            } else{
                sm-=nums[bgnidx];
            }
            sm+=nums[i];
            auto itr2=mp.find(nums[i]);
            if(itr2==mp.end()&&mp.size()==k-1){
                ans=max(ans, sm);
            }
            mp[nums[i]]=nums[i];
            bgnidx++;
        }
        return ans;
    }
};