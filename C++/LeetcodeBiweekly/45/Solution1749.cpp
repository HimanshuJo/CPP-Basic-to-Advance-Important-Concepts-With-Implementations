// 1749. Maximum Absolute Sum of Any Subarray
/*
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] 
is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
 

Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/
/*
Approach :

    Apply Kadane's Algorithm to find 
    Maximum Sum Subarray (i.e maxm_sum) and Minimum Sum Subarray (i.e minm_sum)
    
    Solution : return max(abs(maxm_sum) , abs(minm_sum ));

-------

int maxAbsoluteSum(vector<int>& a) {
    int maxm_sum = INT_MIN, max_ending_here = 0; 
    int size = a.size();
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here += a[i]; 
        maxm_sum = max(maxm_sum, max_ending_here); 
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    }  

    int min_ending_here = 0, minm_sum = INT_MAX; 

    for (int i=0; i<size; i++) 
    { 
        min_ending_here += a[i]; 
        minm_sum = min(minm_sum, min_ending_here);  
        if(min_ending_here > 0)
            min_ending_here = 0;
    } 

    return max(abs(maxm_sum), abs(minm_sum)); 
}
*/

/*
TLE: 54 / 66

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            int currSm=0;
            for(int j=i; j<n; ++j){
                currSm+=nums[j];
                ans=max(ans, abs(currSm));
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    int maxAbsoluteSum(vector<int>& arr) {
        int sm=0, minn=0, maxx=0, res=0;
        for(auto &vals: arr){
            minn=min(0, vals+minn);
            maxx=max(0, vals+maxx);
            res=max({res, maxx, -minn});
        }
        return res;
    }
};