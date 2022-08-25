// Find the Kth Largest Integer in the Array
/*
You are given an array of strings nums and an integer k. 
Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. 
For example, if nums is ["1","2","2"], "2" is the first largest 
integer, "2" is the second-largest integer, and "1" is the third-largest integer.

Example 2:

Input: nums = ["2","21","12","1"], k = 3
Output: "2"
Explanation:
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".

Constraints:

1 <= k <= nums.length <= 104
1 <= nums[i].length <= 100
nums[i] consists of only digits.
nums[i] will not have any leading zeros.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), []
        (const auto &a, const auto &b){
            return a.size()>b.size()?true:a.size()<b.size()?false:a>b;
        });
        cout<<nums[k-1];
        return nums[k-1];
    }
};

int main(){
    Solution obj;
    vector<string>nums={"233","97"};
    int k=1;
    obj.kthLargestNumber(nums, k);
}