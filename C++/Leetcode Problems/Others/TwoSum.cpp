// 1. Two Sum
/*
Given an array of integers nums and an integer target, return indices of the two
numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not
use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
Only one valid answer exists.

Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
*/

#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>>mp;
        if (target < 0) {
            target *= -1;
            for (auto &vals : nums)
                vals *= -1;
        }
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > target) continue;
            int nmtofnd = target - nums[i];
            if (mp.find(nmtofnd) != mp.end()) {
                vector<int>tochk = mp[nmtofnd];
                for (auto &vals : tochk) {
                    if (vals != i) {
                        ans.push_back(vals);
                        ans.push_back(i);
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            map[i] = nums[i];
        }
        vector<int> res;
        int otherIndex = 0;
        bool haveFound = false;
        for (int i = 0; i < nums.size(); ++i) {
            for (auto x : map) {
                if (x.second == target - nums[i] && x.first != i) {
                    otherIndex = x.first;
                    haveFound = true;
                }
            }
            if (haveFound) {
                res.push_back(i);
                res.push_back(otherIndex);
                break;
            }
        }
        return res;
    }
};