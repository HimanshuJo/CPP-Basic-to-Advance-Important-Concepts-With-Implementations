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
Top Down DP:

Let's start with the first subarray, which can have a range like [0, i]. 
We need to decide the value of index i. 

Once we have decided the value of i, we can find the sum for the first 
subarray sum[0, i]. 

Then the problem simplifies to finding the maximum value out of sum[0, i] 
and the largest sum subarray for the array in the range [i + 1, n - 1] with 
m−1 subarrays. This way we are able to divide the problem into smaller subproblems.

How do we find the optimal value of i? Let's try with every possible value of i. 
We can try every possible first subarray and then recursively solve the problem 
for the remaining array. 

Let's define our recurrence relation 
	F[currIndex, subarrayCount] to be the

	minimum largest subarray sum for the array [currIndex, n - 1] with subarrayCount subarrays, 

we can write it in the following way:

F[currIndex, subarrayCount] = min(max(sum[currIndex, i], F[i + 1, subarrayCount - 1])), 
For all i in range [currIndex, n - subarrayCount]

Note that the function F shown here, represents getMinimumLargestSplitSum in the code provided below.

Let's break down the expression:

max(sum[currIndex, i], F[i + 1, subarrayCount - 1]) so that we understand it better.

	F[i + 1, subarrayCount - 1] represents the smallest possible largest sum subarray in the 
	range [i + 1, n - 1] with subarrayCount - 1 subarrays.

	sum[currIndex, i] represents the sum of the current subarray spanning the range of [currIndex, i].

	We take the max of these two values, the expression as a whole represents the 
	largest sum subarray in the range [currIndex, n - 1] with subarrayCount subarrays, 
	when we make the first split at index i.

	To find the optimal place to split the array, we calculate this for all i in the range 
	[currIndex, n - subarrayCount] and take the minimum value as the result.

-------

Also, it's worth noting a small optimization that we just did here by deciding the range 
for i as [currIndex, n - subarrayCount] instead of 
[currIndex, n - 1] this is because we need to divide the array into exactly m subarrays. 

Hence, if i goes beyond n - subarrayCount we won't be able to make m subarrays even 
if we only place a single element in each of the remaining subarrays.

If we can calculate the result for the subproblem without using the above recurrence 
relation (a base case) then we can simply return the result instead of making further recursive calls. 

In this problem, when there is only one subarray remaining, all of the numbers remaining must 
go in that subarray, so when subarrayCount is 1, we can simply return the sum of the numbers 
between currIndex and the end of the array.

-------

To avoid spending time recalculating the results for previously seen subproblems, 
the first time we calculate the minimum largest sum for a certain range and number of subarrays, 
we will store the value in an array. 

Then, the next time we need to calculate the result for this same range and subarray count 
we can look up the result in constant time. This technique is known as memoization and it 
helps us avoid recalculating repeated subproblems

-------

Algorithm

Fill the array prefixSum. The i^{th} index of prefixSum will have the sum of integers 
in nums in the range [0, i - 1] with prefix[0] = 0. (We need prefixSum because each time we 
reach a base case, we must return the sum of the remaining elements, and a prefix sum array 
allows us to do this in constant time.)

Start with index currIndex as 0 and the number of subarrays subarrayCount as m, 
this represents the subarray with range [0, n - 1] and m subarrays.

Select which elements will go in the current subarray by traversing over the indices 
starting from currIndex to N - subarrayCount. At each index:

	Use prefixSum to find the sum of the elements in the current subarray (firstSplitSum).

	Recursively call getMinimumLargestSplitSum to find the minimum largest subarray that can be 
	obtained from the remaining elements.

	The maximum of these two values (largestSplitSum) will be the largest subarray sum if 
	the first subarray is [currIndex, i].

	Repeat this process for all i up to n - subarrayCount, then store the minimum 
	possible largestSplitSum in minimumLargestSplitSum.

Return minimumLargestSplitSum; to avoid repeat calculations, also store it in the 
memoization table memo corresponding to currIndex and subarrayCount.

Base case: If subarrayCount is 1, then we know that all of the remaining numbers must 
go in the current subarray. So instead of making recursive calls according to step 3, 
when subarrayCount is 1, we can simply return the sum of numbers between currIndex and 
the end of the array.

-------

Note: In the for loop for traversing i, once firstSplitSum is larger than minimumLargestSplitSum 
it is impossible for us to find a better minimumLargestSplitSum because firstSplitSum will 
only continue to increase (because all numbers are non-negative) and so does the largestSplitSum. 

So we can prune our search by breaking when firstSplitSum becomes greater than or equal to the 
minimumLargestSplitSum.

-------

Complexity Analysis:

Here N is the length of the array and M is the number of subarrays allowed.

Time complexity: O(N^2*M)

    Each state is defined by the values currIndex and subarrayCount. 
    As such, there are N⋅M possible states, and we must visit almost every state in 
    order to solve the original problem. 

    Each state (subproblem) requires O(N) time because we have a for loop from 
    currIndex to N - subarrayCount. 
    Thus the total time complexity is equal to O(N^2*M)

Space complexity: O(N⋅M)

    The memoization results are stored in the table memo with size 
    N⋅M. Also, stack space in the recursion is equal to the maximum number of 
    active functions. 

    The maximum number of active functions can be equal to M as we only make a 
    recursive call when splitting the array and we do not make a recursive call 
    when there is only 1 subarray remaining. 
    Hence, the space complexity is equal to O(N⋅M).
*/

#include<iostream>  
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    // Defined it as per the maximum size of array and split count
    // But can be defined with the input size as well
    int memo[1001][51];
    
    int getMinimumLargestSplitSum(vector<int>& prefixSum, int currIndex, int subarrayCount) {
        int n = prefixSum.size() - 1;
        
        // We have already calculated the answer so no need to go into recursion
        if (memo[currIndex][subarrayCount] != -1) {
            return memo[currIndex][subarrayCount];
        }
        
        // Base Case: If there is only one subarray left, then all of the remaining numbers
        // must go in the current subarray. So return the sum of the remaining numbers.
        if (subarrayCount == 1) {
            return memo[currIndex][subarrayCount] = prefixSum[n] - prefixSum[currIndex];
        }
        
        // Otherwise, use the recurrence relation to determine the minimum largest subarray
        // sum between currIndex and the end of the array with subarrayCount subarrays remaining.
        int minimumLargestSplitSum = INT_MAX;
        for (int i = currIndex; i <= n - subarrayCount; i++) {
            // Store the sum of the first subarray.
            int firstSplitSum = prefixSum[i + 1] - prefixSum[currIndex];
            
            // Find the maximum subarray sum for the current first split.
            int largestSplitSum = max(firstSplitSum, 
                                      getMinimumLargestSplitSum(prefixSum, i + 1, subarrayCount - 1));
            
            // Find the minimum among all possible combinations.
            minimumLargestSplitSum = min(minimumLargestSplitSum, largestSplitSum);
             
            if (firstSplitSum >= minimumLargestSplitSum) {
                break;
            }
        }
        
        return memo[currIndex][subarrayCount] = minimumLargestSplitSum;
    }
                       
    int splitArray(vector<int>& nums, int m) {
        // Marking all values to -1 so that we can differentiate 
        // If we have already calculated the answer or not
        memset(memo, -1, sizeof(memo));
        
        // Store the prefix sum of nums array.
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        
        return getMinimumLargestSplitSum(prefixSum, 0, m);
    }
};


int main(){
	vector<int>nums{7,2,5,10,8};
	int m=2;
	Solution obj;
	int ans=obj.splitArray(nums, m);
	cout<<ans<<endl;
}