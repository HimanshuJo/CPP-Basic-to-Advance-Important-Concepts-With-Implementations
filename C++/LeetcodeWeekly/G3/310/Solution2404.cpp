// 2404. Most Frequent Even Element
/*
Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.

Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.
Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.
Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.
 

Constraints:

1 <= nums.length <= 2000
0 <= nums[i] <= 10^5
*/

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int>mp;
        map<int, set<int>>fnmp;
        for(auto &vals: nums){
            if((vals&1)==0){
                mp[vals]++;
            }
        }
        for(auto &entries: mp){
            fnmp[entries.second].insert(entries.first);
        }
        if(fnmp.size()==0) return -1;
        auto it=fnmp.rbegin();
        set<int>st=it->second;
        auto stit=st.begin();
        return *stit;
    }
};