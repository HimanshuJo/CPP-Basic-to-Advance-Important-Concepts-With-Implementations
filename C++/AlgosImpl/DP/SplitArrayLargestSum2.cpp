// 410. Split Array Largest Sum
/*
Given an array nums which consists of non-negative integers and an integer m, you can
split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
*/

/*
Intuition:

While dividing the array, we can observe that for each integer, there are two options: 
either add it to the current subarray or start a new subarray with it 
(as long as the number of subarrays does not exceed m). 
The maximum number of possible combinations is {n - 1} \choose {m - 1}
(because we must split the array at m - 1 positions to obtain m subarrays, and 
there are n - 1 positions where the array can be split). 

The brute force approach is to enumerate every possible combination and select the combination 
with the smallest maximum sum subarray. 

However, given the problem constraints, the worst-case scenario will have {999} \choose {49}
combinations, which is extraordinarily large. So let's try to find a better-optimized approach.

There are two characteristics of this problem that we should take note of at this time. 
First, as we iterate over each element, we must decide whether to add the element to 
the current subarray or to start a new subarray. This decision will depend on the number of 
subarrays we have already made. In other words, each decision we make is affected by the 
previous decisions we have made. 

Second, the problem is asking to minimize the largest sum of subarrays. 
These are two common characteristics of dynamic programming problems, and as 
such we will first approach this problem using dynamic programming.
*/
/*
Bottom Up Dp:

Intuition:

	In this approach, we will use the same recurrence relation and the base case as 
	we used in the previous approach. 
	So the code will remain largely the same as in the previous approach. 
	The difference lies in the way of filling the memoization table memo. 

	In the top-down implementation, we visited each subproblem by making recursive 
	calls until we reached a base case. Whereas in the bottom-up implementation, 
	we will use two for loops to iterate over every subproblem (currIndex, subarrayCount), 
	starting from the base case (subarrayCount = 1). 

	We will iterate subarrayCount from 1 to m, and for each value, we will find the 
	largest minimum subarray sum for every range [currIndex, n - 1], where 
	currIndex varies from 0 to n - 1.

-------

Algorithm

Fill the array prefixSum. The i'th index of prefixSum will have the sum of integers 
in nums in the range [0, i - 1] with prefix[0] = 0.

Initialize an array memo where memo[currIndex][subarrayCount] will store the result 
for the subproblem (currIndex, subarrayCount).

We need to find the value of memo[0][m] which represents the minimum largest subarray 
sum starting at index 0 with m subarrays. But we only know what the result will be for 
the base cases. To fill the memo array, we will iterate subarrayCount over the range 
[1, m] (starting at 1 because that is our base case) and iterate currIndex over the range [0, n - 1].

For each value of subarrayCount and currIndex, we will update memo[subarrayCount][currIndex]:
	
	As the sum of the elements between currIndex and the end of the array if we 
	are at a base case (subarrayCount equals 1).

	Otherwise, we will use the recurrence relation and the results from previously 
	solved subproblems to calculate memo[subarrayCount][currIndex].

	Return the value stored at memo[0][m].
*/
/*
Complexity Analysis

	Here N is the length of the array and M is the number of subarrays allowed.

Time complexity: O(N^2*M)
	
	Each state is defined by the values currIndex and subarrayCount. 
	As such, there are N⋅M possible states, and we must visit almost every state 
	in order to solve the original problem. 

	Each state (subproblem) requires O(N) time because we have a for loop from 
	currIndex to N - subarrayCount; because we have stored the result in the table memo, 
	any repeated calls will only require constant time. 

	Thus the total time complexity is equal to O(N^2)

Space complexity: O(N⋅M)

	The results are stored in the table memo with size N⋅M. 
	Hence, the space complexity is equal to O(N⋅M).
*/

class Solution {
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];
    
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        // Store the prefix sum of nums array
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        for (int subarrayCount = 1; subarrayCount <= m; subarrayCount++) {
            for (int currIndex = 0; currIndex < n; currIndex++) {
               // Base Case: If there is only one subarray left, then all of the remaining numbers
               // must go in the current subarray. So return the sum of the remaining numbers.
                if (subarrayCount == 1) {
                    memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
                    continue;
                }

                // Otherwise, use the recurrence relation to determine the minimum largest subarray
                // sum between currIndex and the end of the array with subarrayCount subarray remaining.
                int minimumLargestSplitSum = INT_MAX;
                for (int i = currIndex; i <= n - subarrayCount; i++) {
                    // Store the sum of the first subarray.
                    int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];

                    // Find the maximum subarray sum for the current first split.
                    int largestSplitSum = max(firstSplitSum, memo[i + 1][subarrayCount - 1]);

                    // Find the minimum among all possible combinations.
                    minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);

                    if (firstSplitSum >= minimumLargestSplitSum) {
                        break;
                    }
                }

                memo[currIndex][subarrayCount] = minimumLargestSplitSum;
            }
        }
        return memo[0][m];
    }
};