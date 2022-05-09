'''

You are given an integer array nums and an integer goal.

You want to choose a subsequence of nums such that the sum of its elements is 
the closest possible to goal. That is, if the sum of the subsequence's elements is sum, 
then you want to minimize the absolute difference abs(sum - goal).

Return the minimum possible value of abs(sum - goal).

Note that a subsequence of an array is an array formed by removing some elements 
(possibly all or none) of the original array.

Example 1:

Input: nums = [5,-7,3,5], goal = 6
Output: 0
Explanation: Choose the whole array as a subsequence, with a sum of 6.
This is equal to the goal, so the absolute difference is 0.

'''

'''

Brute Forces:

	DFS or Backtracking can be used to calculate all the possible sums
		for all the subsequence of the nums here

		How many total combinations or total different sums we can calculate given a nums array

			2^n where n is the length of the nums

			The reason being for each number, we have either pick or not pick

				that's why the total combinations for this kind of array is 2^n

-------

Technique:

	Meet in the middle

	Since we can't handle 2^40, but we can handle 2^20

	We split the array into two parts
		then we can brute force to calculate all the possible sums on each side

		suppose we have sum1 in the left side

		sum2 on the right side

		-------

		Then we can basically loop through the total value of the sums on the left side

		and then we try to find the closest one on the right side

			so that we can meet right in the middle

			suppose we have s1 from the left side, and s2 from the right side

			and we primarily want s1 + s2 as close to the goal as possible

	-------

	So to loop through everything from the sum1 here is basically
		2^n/2  --> these are the total number of sums we can get

		on the right side for each of 2^n/2 if we perform another brute force
			to search on the right one

			it will lead to the complexity of 2^n/2 so the resultant is again 2^n  --> TLE

		However, what we can do is that we can sort the second part
			and then we can perform the binary search

			Since we have s1 on the left side, our target element to search on the right side will be

				target = goal - s1

			We can use this target to perform a binary search on the sorted part

		However there is again an issue here
			for example suppose we have an array arr = [1, 2, 3] and goal = -7

			so here what happens if the best solution
				for the sum in the left side (s1) is not selecting anything in the right side (s2)

			If that the case, how to perform a binary search in that scenario

		-------

		Suppose we have an array arr = [-2, -3, | 4, 5] and the goal is -7
			Let's suppose we pick -2 from the left side and the target is to get -7

			so here we shouldn't be adding any number from the right side

		-------

		Hence when we calculate the sum on each side we always add 0 as an element on both the sides
			so that if we are performing let's say a binary search on the right side to search for a
			number -5,

			we will get the closest element as 0

		-------

		Suppose our sum2 is [-20, -10, 0, 1, 4, 6, 10, 12]

			let's say our target is 7

			if we perform a binary search on the right side
				which index the search will return

				it will return the index where 10 is located

				and basically we are assuming that we will use that element to calculate the final absolute
					difference

					but can we only take that element (probably not)

					because other than 10, there might be some other good candidate available
						in this case 6

				So once we get the index of an element in the sum2 here
					after calculating the result using the current index
					we will also check it's neighbor on the left side only

				Why not right?

					Binary Search is here performing the 'bisect_left'
						that guarantees that we will find basically the first number that is greater than
						the target

'''

class Solution:
	def minAbsDifference(self, nums: List[int], goal: int) -> int:
		
		def dfs(i, curr, nums, res):
			if i == len(nums):
				res.append(curr)
				return
			# otherwise we have just two case, either we pick it or not
			dfs(i + 1, curr, nums, res)
			dfs(i + 1, curr + nums[i], nums, res)

		sum1 = []
		sum2 = []
		n = len(nums)
		dfs(0, 0, nums[:n//2], sum1)
		dfs(0, 0, nums[n//2:], sum2)

		# until here we have already calculate all the possible sums for the two halves

		sum2.sort()
		ans = sys.maxsize
		for s1 in sum1:
			t = goal - s1
			i = bisect_left(sum2, t)

			# if the index is within the length of sum2
			if i < len(sum2):

				# the difference between the target and the element in sum2 will be our min diff
				# for the current s1
				ans = min(ans, abs(t - sum2[i]))

			# the next if will cover two scenarios
			# 1. if i == 0 we can't to i - 1
			# 2. this will again cover two cases
			# let's suppose our array is [0, 1, 2, 4] and target is 3
			# we will get i = 3 and element is 4
			# so not only we need to check 4 but it's left neighbor also
			# and if suppose t = 5, which is greater than the biggest element in the array
			# i - 1 will still give us the left most element
			if i > 0:
				ans = min(ans, abs(t - sum2[i - 1]))

		return ans