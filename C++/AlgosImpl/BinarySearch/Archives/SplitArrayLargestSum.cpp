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
Intuition

This approach is quite different from the previous approaches. 
The characteristics of this problem are a good fit for the 
dynamic programming solution hence, it's easy to overlook the idea of 
using binary search. 

This problem satisfies the property that we can guess the answer 
(the minimum largest sum subarray value) and check if that value was 
too high or too low, thus narrowing our search space. 

It requires a different perspective to think of this approach, 
but after realizing that this problem is a candidate for a binary search solution, 
it becomes easier to implement than the previous approaches.

The goal of this problem is to find the minimum largest subarray sum 
with m subarrays. Instead of finding the answer directly, what if 
we try to guess the answer (say X), and check whether this particular 
value could be the largest subarray sum with m subarrays. 

If this is possible, we can check all values for X≥0, and the first value 
that satisfies the condition will be the answer. 

Thus, by repeatedly solving the following problem, we can find the 
minimum largest subarray sum needed to split nums into m subarrays:

'Given an array of n integers and a value X, determine the minimum number 
of subarrays the array needs to be divided into such that no 
subarray sum is greater than X.'

-------

If the minimum number of subarrays required is less than or equal to m 
then the value X could be the largest subarray sum.

-------

The solution to this newly defined problem is as follows

First, make sure X is greater than or equal to the maximum element in the array. 
Otherwise, no solution would be possible because we cannot divide an element.

Start from 0th index and keep adding elements to sum only if adding the 
element does not make sum greater than X.

If adding the current element would make the sum greater than X 
then we have to split the subarray here. 
So we will increment the number of splits required (splitsRequired) 
and set sum to the value of current element (signifying that the 
current subarray only contains the current element).

Once we traversed the whole array, return splitsRequired + 1. 
This is the minimum number of subarrays required.

-------

Now the problem with the current solution is that the value of X 
can be as large as the sum of integers in the given array. 
Hence, checking for all values of X is not feasible.

The key observation here is that if we are able to split the array into 
m or fewer subarrays for a value X then we will also be able to do it 
for any value greater than X. This is because the number of subarrays 
would be even less in case of any value greater than X.

Similarly, if it's not possible for a value X it will not be possible 
to have m or fewer splits for any value less than X.

-------

Algorithm

Store the sum of elements in nums in the variable sum and the maximum 
element of the array in maxElement.

Initialize the boundary for binary search. The minimum value for the 
largest subarray sum is maxElement and the maximum value is equal to sum. 
Hence assign left and right to maxElement and sum respectively.

Then while the left is not greater than right:

	a. Find the mid-value in range [left, right], this is equal to the 
	maximum subarray sum allowed. Store it in maxSumAllowed.

	b. Find the minimum number of subarrays required to have the 
	largest subarray sum equal to maxSumAllowed.

If the number of subarrays is less than or equal to m then assign 
maxSumAllowed as the answer minimumLargestSplitSum and decrease the 
value of our right boundary.

If the number of subarrays is more than mm this can't be the answer 
hence, increase the value of our left boundary.

Return minimumLargestSplitSum.
*/

class Solution {
public:
    int minimumSubarraysRequired(vector<int>& nums, int maxSumAllowed) {
        int currentSum = 0;
        int splitsRequired = 0;
        
        for (int element : nums) {
            // Add element only if the sum doesn't exceed maxSumAllowed
            if (currentSum + element <= maxSumAllowed) {
                currentSum += element;
            } else {
                // If the element addition makes sum more than maxSumAllowed
                // Increment the splits required and reset sum
                currentSum = element;
                splitsRequired++;
            }
        }
        
        // Return the number of subarrays, which is the number of splits + 1
        return splitsRequired + 1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        // Find the sum of all elements and the maximum element
        int sum = 0;
        int maxElement = INT_MIN;
        for (int element : nums) {
            sum += element;
            maxElement = max(maxElement, element);
        }
        
        // Define the left and right boundary of binary search
        int left = maxElement;
        int right = sum;
        int minimumLargestSplitSum = 0;
        while (left <= right) {
            // Find the mid value
            int maxSumAllowed = left + (right - left) / 2;
            
            // Find the minimum splits. If splitsRequired is less than
            // or equal to m move towards left i.e., smaller values
            if (minimumSubarraysRequired(nums, maxSumAllowed) <= m) {
                right = maxSumAllowed - 1;
                minimumLargestSplitSum = maxSumAllowed;
            } else {
                // Move towards right if splitsRequired is more than m
                left = maxSumAllowed + 1;
            }
        }
        
        return minimumLargestSplitSum;
    }
};