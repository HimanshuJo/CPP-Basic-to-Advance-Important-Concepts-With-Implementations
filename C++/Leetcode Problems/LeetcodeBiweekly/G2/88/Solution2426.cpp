// 2426. Number of Pairs Satisfying Inequality
/*
You are given two 0-indexed integer arrays nums1 and nums2, each of size n, and an integer diff. 
Find the number of pairs (i, j) such that:

0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff.
Return the number of pairs that satisfy the conditions.

 

Example 1:

Input: nums1 = [3,2,5], nums2 = [2,2,1], diff = 1
Output: 3
Explanation:
There are 3 pairs that satisfy the conditions:
1. i = 0, j = 1: 3 - 2 <= 2 - 2 + 1. Since i < j and 1 <= 1, this pair satisfies the conditions.
2. i = 0, j = 2: 3 - 5 <= 2 - 1 + 1. Since i < j and -2 <= 2, this pair satisfies the conditions.
3. i = 1, j = 2: 2 - 5 <= 2 - 1 + 1. Since i < j and -3 <= 2, this pair satisfies the conditions.
Therefore, we return 3.
Example 2:

Input: nums1 = [3,-1], nums2 = [-2,2], diff = -1
Output: 0
Explanation:
Since there does not exist any pair that satisfies the conditions, we return 0.
 

Constraints:

n == nums1.length == nums2.length
2 <= n <= 10^5
-10^4 <= nums1[i], nums2[i] <= 10^4
-10^4 <= diff <= 10^4
*/

/*
TLE: 46 / 61

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int sz=nums1.size();
        int res=0;
        for(int i=0; i<sz-1; ++i){
            for(int j=i+1; j<sz; ++j){
                if(nums1[i]-nums1[j]<=nums2[i]-nums2[j]+diff){
                    res++;
                }
            }
        }
        return res;
    }
};
*/

/*
Given that we have to find i , j such that 0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff

Step 1::
Rewriting the inequality--
(nums1[i] - nums2[i]) <= (nums1[j] - nums2[j]) + diff

Step 2::
Make a new array/vector c which stores nums1[i]-nums2[i].
or c[i] = nums1[i]-nums2[i] for 0 <= i <= n - 1.

Step 3::
Problem reduces to find i , j such that 0 <= i < j <= n - 1 and
c[i] <= c[j] + diff

Now, This can be solved by using merge sort (Similar to inversion counting)
*/

class Solution {
public:
    
    long long count;
    
    void checkCount(vector<int>&nums, int start, int mid, int end, int diff){
        int left=start, right=mid+1;
        while(left<=mid&&right<=end){
            if(nums[left]<=nums[right]+diff){
                count+=(end-right+1);
                left++;
            } else{
                right++;
            }
        }
        sort(nums.begin()+start, nums.begin()+end+1);
        return;
    }
    
    void mergeSort(vector<int>&nums, int start, int end, int diff){
        if(start==end) return;
        int mid=(start+end)/2;
        mergeSort(nums, start, mid, diff);
        mergeSort(nums, mid+1, end, diff);
        checkCount(nums, start, mid, end, diff);
        return;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        count=0;
        int sz=nums1.size();
        vector<int>vec(sz);
        for(int i=0; i<sz; ++i){
            vec[i]=nums1[i]-nums2[i];
        }
        mergeSort(vec, 0, sz-1, diff);
        return count;
    }
};