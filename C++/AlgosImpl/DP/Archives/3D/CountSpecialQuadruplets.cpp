// 1995. Count Special Quadruplets
/*
Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:

nums[a] + nums[b] + nums[c] == nums[d], and
a < b < c < d

Example 3:

Input: nums = [1,1,1,3,5]
Output: 4
Explanation: The 4 quadruplets that satisfy the requirement are:
- (0, 1, 2, 3): 1 + 1 + 1 == 3
- (0, 1, 3, 4): 1 + 1 + 3 == 5
- (0, 2, 3, 4): 1 + 1 + 3 == 5
- (1, 2, 3, 4): 1 + 1 + 3 == 5

Constraints:

4 <= nums.length <= 50
1 <= nums[i] <= 100
*/

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans=0;
        int sz=nums.size();
        for(int i=sz-1; i>=0; --i){
            if(i-1>=0){
                for(int j=i-1; j>=0; --j){
                    if(j-1>=0){
                        for(int k=j-1; k>=0; --k){
                            if(k-1>=0){
                                for(int l=k-1; l>=0; --l){
                                    if(nums[l]+nums[k]+nums[j]==nums[i]){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }   
            }
        }
        return ans;
    }
};;

// -------*******-------

class Solution2 {
public:
    
    int dfs(vector<int>&nums, int sz, int cursm, int curvaldidx, int count, vector<vector<vector<int>>>&memo){
        if(count==0&&cursm==0) return 1;
        if(cursm<0||curvaldidx<0||count<0) return 0;
        if(memo[cursm][curvaldidx][count]!=-1) return memo[cursm][curvaldidx][count];
        int ans=0, pk=0, ntpk=0;
        ntpk=dfs(nums, sz, cursm, curvaldidx-1, count, memo);
        pk=dfs(nums, sz, cursm-nums[curvaldidx], curvaldidx-1, count-1, memo);
        ans=pk+ntpk;
        return memo[cursm][curvaldidx][count]=ans;
    }
    
    int countQuadruplets(vector<int>& nums) {
        int sz=nums.size();
        int ans=0;
        vector<vector<vector<int>>>memo(101, vector<vector<int>>(51, vector<int>(4, -1)));
        for(int cursmidx=3; cursmidx<sz; ++cursmidx){
            int cursm=nums[cursmidx], curvaldidx=cursmidx-1;
            ans+=dfs(nums, sz, cursm, curvaldidx, 3, memo);
        }
        return ans;
    }
};