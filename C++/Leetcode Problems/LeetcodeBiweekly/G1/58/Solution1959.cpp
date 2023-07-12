// 1959. Minimum Total Space Wasted With K Resizing Operations
/*
You are currently designing a dynamic array. You are given a 0-indexed integer array nums, 
where nums[i] is the number of elements that will be in the array at time i. 

In addition, you are given an integer k, the maximum number of times you can resize the array (to any size).

The size of the array at time t, sizet, must be at least nums[t] because there needs to be 
enough space in the array to hold all the elements. The space wasted at time t is defined as 
sizet - nums[t], and the total space wasted is the sum of the space wasted across every time t where 0 <= t < nums.length.

Return the minimum total space wasted if you can resize the array at most k times.

Note: The array can have any size at the start and does not count towards the number of resizing operations.

Example 1:

Input: nums = [10,20], k = 0
Output: 10
Explanation: size = [20,20].
We can set the initial size to be 20.
The total wasted space is (20 - 10) + (20 - 20) = 10.
Example 2:

Input: nums = [10,20,30], k = 1
Output: 10
Explanation: size = [20,20,30].
We can set the initial size to be 20 and resize to 30 at time 2. 
The total wasted space is (20 - 10) + (20 - 20) + (30 - 30) = 10.
Example 3:

Input: nums = [10,20,15,30,20], k = 2
Output: 15
Explanation: size = [10,20,20,30,30].
We can set the initial size to 10, resize to 20 at time 1, and resize to 30 at time 3.
The total wasted space is (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 10^6
0 <= k <= nums.length - 1
*/

/*
n = size of the array
max_element = maximum element of the array.
S = sum of all the element in array

If you are not allowed to resize (i.e k = 0) then the total wastage of memory = 

        n * max_element -  Sum of all elements

For Example:

    nums[] = 10, 20, 15, 30, 20 and k = 0
    n = 5, max_element = 30, S = 95
    Waste = 5 * 30 - 95 = 55

Idea:

The idea is to split the array into k+1 subarray (splitting the array k times). 
Now use the lemma for each subarray. 
The Sum of wastage from each k+1 subarray is the required answer. 
Now, the question is how to split the array to minimize space wasted (you can imagine this as the little 
sister of the knapsack problem).

Sub-problem:

    OPT(j,k) = minimum waste from  nums[0] to nums[j] using k resize operation.

Recurrence Relation:

    OPT(j,k) = min(OPT(j,k), OPT(l,k-1) + wastage among nums[l+1] to nums[j]) for l in range(0,j)

    for(int l=0; l<j; l++)

        OPT(j,k) = min (OPT(j,k), OPT(l,k-1) + wastage among nums[l+1] to nums[j])
*/

class Solution {
public:
    
    int dfs(vector<int>&nums, int sz, int k, int idx, vector<vector<int>>&memo){
        if(idx==sz) return 0;
        if(k<0) return INT_MAX;
        if(memo[idx][k]!=-1) return memo[idx][k];
        long long ans=INT_MAX, curmax=0, cursm=0;
        for(int i=idx; i<sz; ++i){
            curmax=max(curmax, (long long)nums[i]);
            cursm+=nums[i];
            long long curans=curmax*(i-idx+1)-cursm+dfs(nums, sz, k-1, i+1, memo);
            ans=min(ans, curans);
        }
        return memo[idx][k]=ans;
    }
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<vector<int>>memo(sz, vector<int>(sz+1, -1));
        int ans=dfs(nums, sz, k, 0, memo);
        return ans==INT_MAX?0:ans;
    }
};

// -------*******-------

class Solution2 {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<vector<long long>>dp(sz+1, vector<long long>(sz+1, INT_MAX));
        long long curmax_=0, cursm_=0;
        for(int i=0; i<sz; ++i){
            curmax_=max(curmax_, (long long)nums[i]);
            cursm_+=nums[i];
            dp[i][0] = curmax_ * (i + 1) - cursm_;
            for(int j=1; j<=k; ++j){
                dp[0][j]=0;
                long long ans=INT_MAX, curmax=0, cursm=0;
                for(int x=i; x>0; --x){
                    curmax=max(curmax, (long long)nums[x]);
                    cursm+=nums[x];
                    long long wst=curmax*(i-x+1)-cursm;
                    dp[i][j]=min(dp[i][j], dp[x-1][j-1]+wst);
                }
            }
        }
        return dp[sz-1][k];
    }
};

// -------*******-------

class Solution3 {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<int>prefixSum(sz+1, 0);
        vector<vector<int>>dp(sz, vector<int>(k+1, -1));
        vector<vector<int>>maxElement(sz, vector<int>(sz, -1));
        for(int i=0; i<sz; ++i){
            int maxi=nums[i];
            prefixSum[i+1]=prefixSum[i]+nums[i];
            for(int j=i; j<sz; ++j){
                maxi=max(maxi, nums[j]);
                maxElement[i][j]=maxi;
            }
        }
        // for each index, if we have 0 resize operations
        for(int i=0; i<sz; ++i){
            dp[i][0]=(i+1)*maxElement[0][i]-prefixSum[i+1];
        }
        for(int j=0; j<=k; ++j){
            dp[0][j]=0;
        }
        for(int i=1; i<sz; ++i){
            for(int j=1; j<=i&&j<=k; ++j){
                dp[i][j]=INT_MAX;
                for(int l=0; l<i; ++l){
                    if(dp[l][j-1]==-1) continue;
                    int temp=dp[l][j-1]+maxElement[l+1][i]*(i-l)-(prefixSum[i+1]-prefixSum[l+1]);
                    dp[i][j]=min(dp[i][j], temp);
                }
                if(dp[i][j]==INT_MAX) dp[i][j]=-1;
            }
        }
        return dp[sz-1][k];
    }
};