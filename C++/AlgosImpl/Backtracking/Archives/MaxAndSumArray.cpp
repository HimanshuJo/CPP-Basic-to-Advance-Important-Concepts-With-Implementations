// 2172. Maximum AND Sum of Array
/*
You are given an integer array nums of length n and an integer numSlots such that 
2 * numSlots >= n. There are numSlots slots numbered from 1 to numSlots.

You have to place all n integers into the slots such that each slot contains at most two numbers. 
The AND sum of a given placement is the sum of the bitwise AND of every number with its 
respective slot number.

For example, the AND sum of placing the numbers [1, 3] into slot 1 and [4, 6] 
into slot 2 is equal to (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4.
Return the maximum possible AND sum of nums given numSlots slots.

Example 1:

Input: nums = [1,2,3,4,5,6], numSlots = 3
Output: 9
Explanation: One possible placement is [1, 4] into slot 1, [2, 6] into slot 2, and [3, 5] into slot 3. 
This gives the maximum AND sum of (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 
1 + 0 + 2 + 2 + 3 + 1 = 9.
Example 2:

Input: nums = [1,3,10,4,7,1], numSlots = 9
Output: 24
Explanation: One possible placement is [1, 1] into slot 1, [3] into slot 3, [4] into slot 4, [7] into slot 7, 
and [10] into slot 9.
This gives the maximum AND sum of (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4) + (7 AND 7) + (10 AND 9) = 
1 + 1 + 3 + 4 + 7 + 8 = 24.
Note that slots 2, 5, 6, and 8 are empty which is permitted.
 

Constraints:

n == nums.length
1 <= numSlots <= 9
1 <= n <= 2 * numSlots
1 <= nums[i] <= 15
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution1{
    public:

    int dfs(vector<int>&nums, int numSlots, vector<int>&vecSlots, int sz, int idx){
        if(idx>=sz) return 0;
        int res=INT_MIN;
        for(int curSlot=1; curSlot<=numSlots; ++curSlot){
            if(vecSlots[curSlot]!=2){
                vecSlots[curSlot]++;
                int curres=(nums[idx]&curSlot)+dfs(nums, numSlots, vecSlots, sz, idx+1);
                res=max(res, curres);
                vecSlots[curSlot]--;
            }
        }
        return res;
    }

    int maximumAndSum(vector<int>&nums, int numSlots){
        vector<int>vecSlots(numSlots+1, 0);
        int sz=nums.size();
        return dfs(nums, numSlots, vecSlots, sz, 0);
    }
};

// -------*******-------

class Solution2{
    public:
    int maximumAndSum(vector<int>&nums, int numSlots){
        int sz=nums.size();
        auto solve=[&](int idx, int mask1, int mask2, auto &self)-> int{
            if(idx>=sz) return 0;
            int res=0;
            for(int j=0; j<numSlots; ++j){
                if((mask1>>j)&1) continue;
                res=max(res, (nums[idx]&(j+1))+self(idx+1, mask1|(1LL<<j), mask2, self));
            }
            for(int j=0; j<numSlots; ++j){
                if((mask2>>j)&1) continue;
                res=max(res, (nums[idx]&(j+1))+self(idx+1, mask1, mask2|(1LL<<j), self));
            }
            return res;
        };
        return solve(0, 0, 0, solve);
    }
};

// -------*******-------

class Solution3{
    public:
    int dfs(vector<int>&nums, int numSlots, int sz, int idx, int mask1, int mask2){
        if(idx>=sz) return 0;
        int res=0;
        for(int j=0; j<numSlots; ++j){
            /*
                If current bit is set continue;
                
                Using right shift:
                    
                    if((mask1>>j)&1) continue;
            */
            if((1<<mask1)&j) continue;
            // else cal res and set the bit
            res=max(res, ((nums[idx]&(j+1))+dfs(nums, numSlots, sz, idx+1, mask1|(1LL<<j), mask2)));
        }
        for(int j=0; j<numSlots; ++j){
            //if((mask2>>j)&1) continue;
            if((1<<mask2)&j) continue;
            res=max(res, ((nums[idx]&(j+1))+dfs(nums, numSlots, sz, idx+1, mask1, mask2|(1LL<<j))));
        }
        return res;
    }

    int maximumAndSum(vector<int>&nums, int numSlots){
        int sz=nums.size();
        int idx=0, mask1=0, mask2=0;
        return dfs(nums, numSlots, sz, idx, mask1, mask2);
    }
};

int main(){
    Solution1 obj1;
    Solution2 obj2;
    Solution3 obj3;
    vector<int>nums{1, 2, 3, 4, 5, 6};
    int numSlots=3;
    int ans1=obj1.maximumAndSum(nums, numSlots);
    int ans2=obj2.maximumAndSum(nums, numSlots);
    int ans3=obj3.maximumAndSum(nums, numSlots);
    cout<<ans1<<endl;
    cout<<ans2<<endl;
    cout<<ans3<<endl;
}
