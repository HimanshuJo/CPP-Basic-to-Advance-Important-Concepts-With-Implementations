// 2261. K Divisible Elements Subarrays
/*
Given an integer array nums and two integers k and p, 
return the number of distinct subarrays which have at most k elements divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
A subarray is defined as a non-empty contiguous sequence of elements in an array.

 

Example 1:

Input: nums = [2,3,3,2,2], k = 2, p = 2
Output: 11
Explanation:
The elements at indices 0, 3, and 4 are divisible by p = 2.
The 11 distinct subarrays which have at most k = 2 elements divisible by 2 are:
[2], [2,3], [2,3,3], [2,3,3,2], [3], [3,3], [3,3,2], [3,3,2,2], [3,2], [3,2,2], and [2,2].
Note that the subarrays [2] and [3] occur more than once in nums, but they should each be counted only once.
The subarray [2,3,3,2,2] should not be counted because it has 3 elements that are divisible by 2.
Example 2:

Input: nums = [1,2,3,4], k = 4, p = 1
Output: 10
Explanation:
All element of nums are divisible by p = 1.
Also, every subarray of nums will have at most 4 elements that are divisible by 1.
Since all subarrays are distinct, the total number of subarrays satisfying all the constraints is 10.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i], p <= 200
1 <= k <= nums.length
*/

struct hashFunction 
{
  size_t operator()(const vector<int> 
                    &myVector) const 
  {
    std::hash<int> hasher;
    size_t answer = 0;
      
    for (int i : myVector) 
    {
      answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
  }
};

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<vector<int>, hashFunction>st;
        int sz=nums.size();
        for(int i=0; i<sz; ++i){
            vector<int>temp;
            temp.push_back(nums[i]);
            st.insert(temp);
            if(i+1<=sz-1){
                for(int j=i+1; j<sz; ++j){
                    temp.push_back(nums[j]);
                    st.insert(temp);
                }
            }
        }
        int res=0;
        for(auto &vals: st){
            int count=0;
            for(auto &nums: vals){
                if(nums%p==0){
                    count++;
                }
            }
            if(count<=k) res++;
        }
        return res;
    }
};