//312. Burst Balloons
/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it 
represented by an array nums.
You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
If i - 1 or i + 1 goes out of bounds of the array,
then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

/*
for (int k = left; k <= right; ++k)
	dp[left][right] = max(dp[left][right], 
	                      nums[left-1] * nums[k] * nums[right+1] + 
	                      dp[left][k-1] + dp[k+1][right])**

First of all, dp[i][j] in here means, the maximum coins we get after we burst all 
the balloons between i and j in the original array.

For example with input [3,1,5,8] :

dp[0][0] means we burst ballons between [0,0], which means we only burst the first balloon 
in original array. 
So dp[0][0] is 1 * 3 * 1 = 3.

dp[1][1] means we burst balloons between [1][1], which means we only burst the second ballon in 
the original array. 
So dp[1][1] is 3 * 1 * 5 = 15.

So in the end for this problem we want to find out dp[0][ arr.length - 1 ], which is the 
maximum value we can get 
when we burst all the balloon between [0, length -1]

To get that we need the transition function :

for (int k = left; k <= right; ++k)
dp[left][right] = max(dp[left][right], 
                      nums[left-1] * nums[k] * nums[right+1] + dp[left][k-1] + dp[k+1][right])

This transition function basically says in order to get the maximum value we can get for 
bursting all the balloons 
between [i , j] , we just loop through each balloon between these two indexes and make them to 
be the last balloon to be burst,

why we pick it as the last balloon to burst ?

For example when calculating dp[0,3] and picking index 2 as the last balloon to burst,

[3 , 1 , 5 , 8] , that means 5 is the last balloon to burst between [0,3] , to get 
the maximum value when picking 
5 as the last balloon to burst :

max = maximum value of bursting all the balloon on the left side of 5 + maximum value of 
bursting all the balloon 
on the right side of 5 + bursting balloon 5 when left side and right side are gone.

That is dp[0, 1] + nums[0 - 1] * nums[2] * nums[3 + 1] + dp[3,3];

That is dp[left, k - 1] + nums[left - 1] * nums[k] * nums[right + 1] + dp[k+1, right] ;
*/

class Solution1 {
public:
    
    int dfs(vector<int>&nums, int i, int j, vector<vector<int>>&memo){
        if(i>j) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=INT_MIN;
        for(int ind=i; ind<=j; ++ind){
            ans=max(ans, nums[i-1]*nums[ind]*nums[j+1]+dfs(nums, i, ind-1, memo)+dfs(nums, ind+1, j, memo));
        }
        return memo[i][j]=ans;
    }
    
    int maxCoins(vector<int>& nums) {
       auto it=nums.begin();
       nums.insert(it, 1);
       nums.push_back(1);
       int sz=nums.size();
       vector<vector<int>>memo(sz+1, vector<int>(sz+1, -1));
       return dfs(nums, 1, sz-2, memo);
    }
};

// -------*******-------

class Solution2 {
public:

	int N = 510;

	int dfs(int begn, int end, vector<int>&nums, vector<vector<int>>&memo) {
		if (begn > end) return 0;
		if (memo[begn][end] != -1) return memo[begn][end];
		int coins = 0;
		for (int i = begn; i <= end; ++i) {
			coins = max(coins, nums[begn - 1] * nums[i] * nums[end + 1] + 
				    dfs(i + 1, end, nums, memo) + 
				    dfs(begn, i - 1, nums, memo));
		}
		return memo[begn][end] = coins;
	}

	int maxCoins(vector<int>& nums) {
		vector<int>tmp = nums;
		vector<vector<int>>memo(N, vector<int>(N, -1));
		tmp.insert(tmp.begin(), 1);
		tmp.push_back(1);
		int sz = tmp.size() - 1;
		int ans = dfs(1, sz - 1, tmp, memo);
		return ans;
	}

	int maxCoinsDP(vector<int> &iNums) {
		int nums[iNums.size() + 2];
		int n = 1;
		for (int x : iNums) if (x > 0) nums[n++] = x;
		nums[0] = nums[n++] = 1;
		int dp[n][n] = {};
		for (int k = 2; k < n; ++k) {
			for (int left = 0; left < n - k; ++left)
				int right = left + k;
			for (int i = left + 1; i < right; ++i)
				dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
		}

		return dp[0][n - 1];
	}
};
