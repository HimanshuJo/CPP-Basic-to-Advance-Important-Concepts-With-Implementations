// 2044. Count Number of Maximum Bitwise-OR Subsets
/*
Given an integer array nums, find the maximum possible bitwise OR of a subset of 
nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting 
some (possibly zero) elements of b. Two subsets are considered different 
if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

Example 1:

Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
Example 2:

Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
Example 3:

Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
 

Constraints:

1 <= nums.length <= 16
1 <= nums[i] <= 10^5
*/

class Solution {
public:

    void subsetsUtil(vector<int>&A, vector<vector<int>>&res, vector<int>&subset, int index){
        res.push_back(subset);
        for(int i=index; i<A.size(); ++i){
            subset.push_back(A[i]);
            subsetsUtil(A, res, subset, i+1);
            subset.pop_back();
        }
        return;
    }

    vector<vector<int>> subsets(vector<int>&A){
        vector<int>subset;
        vector<vector<int>>res;
        int index=0;
        subsetsUtil(A, res, subset, index);
        return res;
    }

    int countMaxOrSubsets(vector<int>&nums){
        vector<vector<int>>res=subsets(nums);
        vector<int>mp(1e6+1, -1);
        for(int i=0; i<res.size(); ++i){
            int currXor=0;
            for(int j=0; j<res[i].size(); ++j){
                currXor|=res[i][j];
            }
            mp[currXor]++;
        }
        for(int i=1e6; i>=0; --i){
            if(mp[i]!=-1) return mp[i]+1;
        }
        return 1;
    }
};