// 2134. Minimum Swaps to Group All 1's Together II
/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the 
last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group 
all 1's present in the array together at any location.

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
*/

/*
Solution2:

Intuition:
Whenever you are faced with a circular array question, you can just append the 
array to itself to get rid of the circular array part of the problem

Explanation:

Count number of ones in nums, let the number of ones be stored in the variable ones
Append nums to nums because we have to look at it as a circular array
Find the maximum number of ones in a window of size ones in the new array
Number of swaps = ones - maximum number of ones in a window of size ones

int minSwaps(vector<int>& nums) {
    int ones = 0, x = 0, onesInWindow = 0, i = 0, n = nums.size();
    ones = count(begin(nums), end(nums), 1);
    vector<int> nums2(n * 2);
    for (i = 0; i < n * 2; i++)
        nums2[i] = nums[i % n];
    for (i = 0; i < n * 2; i++) {
        if (i >= ones && nums2[i - ones] == 1) x--;
        if (nums2[i] == 1) x++;
        onesInWindow = max(x, onesInWindow);
    }
    return ones - onesInWindow;
}
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int countOnes=0;
        int n=nums.size();
        for(int i=0; i<n; ++i){
            if(nums[i]==1){
                countOnes++;
            }
        }
        int x=countOnes;
        countOnes=0;
        for(int i=0; i<x; ++i){
            if(nums[i]==1) countOnes++;
        }
        int maxOneCount=countOnes;
        for(int i=x; i<n+x; ++i){
            if(nums[i%n]==1){
                countOnes++;
            }
            if(nums[(i-x)%n]==1) countOnes--;
            maxOneCount=max(maxOneCount, countOnes);
        }
        return (x-maxOneCount);
    }
};