// 2148. Count Elements With Strictly Smaller and Greater Elements
/*
Given an integer array nums, return the number of elements that have both a strictly smaller and a strictly 
greater element appear in nums.

Example 1:

Input: nums = [11,7,2,15]
Output: 2
Explanation: The element 7 has the element 2 strictly smaller than it and the element 11 strictly greater than it.
Element 11 has element 7 strictly smaller than it and element 15 strictly greater than it.
In total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
Example 2:

Input: nums = [-3,3,3,90]
Output: 2
Explanation: The element 3 has the element -3 strictly smaller than it and the element 90 strictly greater than it.
Since there are two elements with the value 3, in total there are 2 elements having both a strictly smaller and a strictly greater element appear in nums.
 

Constraints:

1 <= nums.length <= 100
-10^5 <= nums[i] <= 10^5
*/

/*
Brute Force:

class Solution {
public:
    int countElements(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            bool sm=false, lg=false;
            int curr=nums[i];
            for(int j=0; j<n; ++j){
                if(curr<nums[j]){
                    sm=true;
                }
                if(curr>nums[j]){
                    lg=true;
                }
                if(sm&&lg){
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int countElements(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; ++i){
            auto it1=lower_bound(nums.begin(), nums.end(), nums[i]);
            auto it2=upper_bound(nums.begin(), nums.end(), nums[i]);
            int sm=it1-nums.begin();
            int bg=n-(it2-nums.begin());
            if(sm!=0&&bg!=0){
                res++;
            }
        }
        return res;
    }
};