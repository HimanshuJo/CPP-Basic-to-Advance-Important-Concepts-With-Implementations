// 2419. Longest Subarray With Maximum Bitwise AND
/*
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. 
Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.
 

Constraints:

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
*/

/*
TLE: 39 / 51

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long long maxAnd=nums[0];
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            maxAnd=max(maxAnd, (long long)nums[i]);
        }
        int fnres=1;
        for(int i=0; i<sz; ++i){
            if(nums[i]==maxAnd){
                long long tempAnd=maxAnd;
                int cures=1;
                if(i+1<=sz-1){
                    for(int j=i+1; j<sz; ++j){
                        tempAnd&=nums[j];
                        if(tempAnd<maxAnd) break;
                        cures++;
                    }   
                }
                fnres=max(fnres, cures);
            }
        }
        return fnres;
    }
};
*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long long maxAnd=nums[0];
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            maxAnd=max(maxAnd, (long long)nums[i]);
        }
        int res=0;
        int curlen=0;
        for(auto &vals: nums){
            if(vals==maxAnd){
                curlen++;
                res=max(res, curlen);
            } else{
                curlen=0;
            }
        }
        return res;
    }
};