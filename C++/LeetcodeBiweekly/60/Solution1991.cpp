// 1991. Find the Middle Index in Array
/*
Given a 0-indexed integer array nums, find the leftmost middleIndex (i.e., the smallest amongst all the possible ones).

A middleIndex is an index where nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1].

If middleIndex == 0, the left side sum is considered to be 0. Similarly, if middleIndex == nums.length - 1, the right side sum is considered to be 0.

Return the leftmost middleIndex that satisfies the condition, or -1 if there is no such index.

Example 1:

Input: nums = [2,3,-1,8,4]
Output: 3
Explanation:
The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
*/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sz=nums.size();
        vector<int>prefSm(sz, 0), suffSm(sz, 0);
        int ans=-1;
        prefSm[0]=nums[0];
        for(int i=1; i<sz; ++i){
            prefSm[i]=nums[i]+prefSm[i-1];
        }
        suffSm[sz-1]=nums[sz-1];
        for(int i=sz-2; i>=0; --i){
            suffSm[i]=nums[i]+suffSm[i+1];
        }
        for(int i=0; i<sz; ++i){
            int reqprefsm=0;
            if(i>0){
                reqprefsm=prefSm[i-1];   
            }
            int reqsuffsm=0;
            if(i<sz-1){
                reqsuffsm=suffSm[i+1];
            }
            if(reqprefsm==reqsuffsm){
                ans=i;
                break;
            }
        }
        return ans;
    }
};

// -------*******-------

class Solution2 {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sz=nums.size();
        int ans=-1;
        for(int i=0; i<sz; ++i){
            int curcenter=i;
            int lftsm=0, rghtsm=0;
            if(i>0){
                for(int x=i-1; x>=0; --x){
                    lftsm+=nums[x];
                }   
            }
            if(i<sz-1){
                for(int x=i+1; x<sz; ++x){
                    rghtsm+=nums[x];
                }   
            }
            if(lftsm==rghtsm){
                ans=i;
                break;
            }
        }
        return ans;
    }
};
