// 35. Search Insert Position
/*
Given a sorted array of distinct integers and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
*/

/*
We are looking for the minimal k value satisfying nums[k] >= target,
Notice that our solution is correct regardless of whether the input array nums has duplicates.
Also notice that the input target might be larger than all elements in nums and therefore needs
to placed at the end of the array.

That's why we should initialize right = len(nums) instead of right = len(nums) - 1.

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left
*/

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int N = nums.size();
		int left = 0, right = nums.size();
		if (target > nums[N - 1]) return N;
		int ans = 0;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] >= target) {
				ans = mid;
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return ans;
	}
};