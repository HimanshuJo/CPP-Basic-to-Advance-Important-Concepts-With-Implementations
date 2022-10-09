// 2420. Find All Good Indices
/*
You are given a 0-indexed integer array nums of size n and a positive integer k.

We call an index i in the range k <= i < n - k good if the following conditions are satisfied:

The k elements that are just before the index i are in non-increasing order.
The k elements that are just after the index i are in non-decreasing order.
Return an array of all good indices sorted in increasing order.


Example 1:

Input: nums = [2,1,1,1,3,4,1], k = 2
Output: [2,3]
Explanation: There are two good indices in the array:
- Index 2. The subarray [2,1] is in non-increasing order, and the subarray [1,3] is in non-decreasing order.
- Index 3. The subarray [1,1] is in non-increasing order, and the subarray [3,4] is in non-decreasing order.
Note that the index 4 is not good because [4,1] is not non-decreasing.
Example 2:

Input: nums = [2,1,1,2], k = 2
Output: []
Explanation: There are no good indices in this array.
 

Constraints:

n == nums.length
3 <= n <= 10^5
1 <= nums[i] <= 10^6
1 <= k <= n / 2
*/

/*
TLE: 58 / 68

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<int>ans;
        for(int i=0; i<sz; ++i){
            if(i+k<=sz-1&&i-k>=0){
                bool flag=false;
                int lft=i-k, rght=i+k;
                int currlft=nums[lft];
                int currgtmd=nums[i+1];
                for(int x=lft; x<i; ++x){
                    if(nums[x]>currlft){
                        flag=true;
                        break;
                    } else{
                        currlft=nums[x];
                    }
                }
                if(!flag){
                    for(int x=i+1; x<=rght; ++x){
                        if(nums[x]<currgtmd){
                            flag=true;
                            break;
                        } else{
                            currgtmd=nums[x];
                        }
                    }
                }
                if(!flag){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
*/

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<int>prefCount1(sz+1, 1), prefCount2(sz+1, 1);
        for(int i=1; i<sz; ++i){
            if(nums[i-1]>=nums[i]){
                prefCount1[i]=prefCount1[i-1]+1;
            }
        }
        for(int i=sz-2; i>=0; --i){
            if(nums[i]<=nums[i+1]){
                prefCount2[i]=prefCount2[i+1]+1;
            }
        }
        vector<int>ans;
        for(int i=k; i<sz-k; ++i){
            if(prefCount1[i-1]>=k&&prefCount2[i+1]>=k){
                ans.push_back(i);
            }
        }
        return ans;
    }
};