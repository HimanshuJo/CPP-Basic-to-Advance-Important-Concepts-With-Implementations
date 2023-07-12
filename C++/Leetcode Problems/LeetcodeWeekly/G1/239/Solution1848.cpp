// 1848. Minimum Distance to the Target Element
/*
Given an integer array nums (0-indexed) and two integers target and start, 
find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.

Return abs(i - start).

It is guaranteed that target exists in nums.


Example 1:

Input: nums = [1,2,3,4,5], target = 5, start = 3
Output: 1
Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
Example 2:

Input: nums = [1], target = 1, start = 0
Output: 0
Explanation: nums[0] = 1 is the only value equal to target, so the answer is abs(0 - 0) = 0.
Example 3:

Input: nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0
Output: 0
Explanation: Every value of nums is 1, but nums[0] minimizes abs(i - start), which is abs(0 - 0) = 0.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 10^4
0 <= start < nums.length
target is in nums.
*/

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int sz=nums.size();
        if(sz==1) return (abs(start-0));
        unordered_map<int, vector<int>>mp;
        for(int i=0; i<sz; ++i){
            if(nums[i]==target){
                mp[nums[i]].push_back(i);
            }
        }
        vector<int>tocheck=mp[target];
        int sz2=tocheck.size();
        if(sz2==1) return (abs(start-tocheck[0]));
        int ans1=INT_MAX, ans2=INT_MAX;
        auto it1=upper_bound(tocheck.begin(), tocheck.end(), start);
        if(it1!=tocheck.end()&&it1>=tocheck.begin())
            ans1=abs(*it1-start);
        it1--;
        if(it1-tocheck.begin()>=0)
            ans1=min(ans1, abs(*it1-start));
        auto it2=lower_bound(tocheck.begin(), tocheck.end(), start);
        if(it2!=tocheck.end()&&it2-tocheck.begin()>=0)
            ans2=abs(*it2-start);
        it2--;
        if(it2-tocheck.begin()>=0)
            ans2=min(ans2, abs(*it2-start));
        return min(ans1, ans2);
    }
};