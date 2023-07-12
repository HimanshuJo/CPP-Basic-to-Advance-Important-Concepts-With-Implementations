'''

Given an integer array instructions, you are asked to create a sorted array from the elements 
in instructions. 

You start with an empty container nums. For each element from left to right in instructions, 
insert it into nums. 

The cost of each insertion is the minimum of the following:

    The number of elements currently in nums that are strictly less than instructions[i].
    The number of elements currently in nums that are strictly greater than instructions[i].

For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) 
(elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may 
be large, return it modulo 10^9 + 7

Example 1:

Input: instructions = [1,5,6,2]
Output: 1
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 5 with cost min(1, 0) = 0, now nums = [1,5].
Insert 6 with cost min(2, 0) = 0, now nums = [1,5,6].
Insert 2 with cost min(1, 2) = 1, now nums = [1,2,5,6].
The total cost is 0 + 0 + 0 + 1 = 1.

Example 2:

Input: instructions = [1,2,3,6,5,4]
Output: 3
Explanation: Begin with nums = [].
Insert 1 with cost min(0, 0) = 0, now nums = [1].
Insert 2 with cost min(1, 0) = 0, now nums = [1,2].
Insert 3 with cost min(2, 0) = 0, now nums = [1,2,3].
Insert 6 with cost min(3, 0) = 0, now nums = [1,2,3,6].
Insert 5 with cost min(3, 1) = 1, now nums = [1,2,3,5,6].
Insert 4 with cost min(3, 2) = 2, now nums = [1,2,3,4,5,6].
The total cost is 0 + 0 + 0 + 0 + 1 + 2 = 3.

'''

'''

Performing standard Binary Search:

	First naive approach we can apply is to use the binary search

		Create an empty array to store the numbers from instruction into it in a sorted manner,

		while adding a number from instructions to this array, we have to search for its appropriate 
		position and then calculate the cost according to the process described above

	-------

	class Solution:
		def createSortedArray(self, instructions: List[int]) -> int:
			# for maintaining a sorted array
			nums = []
			ans = 0
			for ins in instructions:
				# index1 will tell how many numbers are strictly smaller than the 'ins' provided
				index1 = bisect.bisect_left(nums, ins)
				left = index1
				# index2 will tell how many numbers are strictly greater than the 'ins' provided
				index2 = bisect.bisect_right(nums, ins)
				right = len(nums) - index2
				ans += min(left, right)
				bisect.insort(nums, ins)
			return ans % 10**9 + 7

-------

Note: Whenever we have the questions like, what is going to be the total numbers on the left and 
	what is going to be total numbers on the right, while maintaining a sorted list

	we should always go for a faster and efficient approach 'Segment Trees' or in some cases 
	like here 'Binary Indexed Tree'

-------

Binary Indexed Trees:

	Motivation: is to efficiently maintain an array while at the same time efficiently get the 
	preSum of that particular array

	-------

	Suppose we are storing some sorted numbers in an array, and the time to update an element 
	we take O(1) time

		but to update the preSum we have to perform a linear scan

		because by updating one of the element, we could affect all the remaining prefixes

		However, if we are storing the preSum then to update the preSum, it will now take O(1) time,
			but now updating an element will now take O(n) time

		Binary Indexed Tree solves this delema

	-------

	In the Binary Indexed Tree we create a tree structure, where the node is the number itself, starting from 0 (the root)


									 0
							     / / | \   \ 
							    1 2  3  4   8
							           / \ / \
							           5 6 9 10
							             |
							             7

        How are in-fact we are getting this tree structure here
        	every-time when we have a number here, we're converting it into it's binary format

        		e.g. for 1 -> 0001
        			 for 2 -> 0010 and so on

	 	-------

	 	The way we are constructing this tree is that, every-time we find a parent for a particular node
	 		by removing the least significant bit

	 		for example for 3 -> 0011, it will be changed to 0010

 		Each of the number in the node represents the sum, from the parent to the current number

 			for example the node 1 it stores the preSum from 0 to 1

 					    the node 5 stores the preSum from 4 to 5 and so on

	    -------

	    Each node is storing a segment of the sum or more like the range of the sum

    	-------

    	With this kind of structure we will need two kind of operations

    		a. To add a number to the tree

    		b. how to query the sum given a particular index

		-------

		Suppose we are at node 7, how can we get the sum from 0 till 7

			since we have a path in the tree from root till this node, we just need to find the parent,
				then parent of that particular parent and so on until we reach the root

				finally we sum the values from all the segments

					e.g. for the node 7 here:

							first range 6 to 7 + 
							second range 4 to 6 +
							third range 0 to 4

							* parent is not inclusive => (6 - 7] + (4 - 6] + (0 - 4]

		-------

		How can we find the parents:

			Suppose we have 6 -> 0110, which is a parent for 7 in this case

			so what we do is just to revert the least significant 1 in 7 -> 0111 become 0110

			-------

			Suppose the current number has the index 'i'

				we perform:

					i -= i & (-i)  -> formula to revert the least significant 1's in any number

						i & (-i) is basically performing 2's compliment

					and keep doing that until we reach the 0

		-------

		How to perform the update:

			Suppose we want to add some value to the index 2, so in essence firstly we'll be 
			updating that particular value

				so we perform:

					(value at index 2) + k

				then we'll just try to double the range

					because currently we're in the range 0-2, but the range 0-4 can also include 0-2

					therefore the next node we need to update is 4, then 8 and so on

						so we perform:

							(value at index 4) + k

							(value at index 8) + k

			-------

			Therefore while doing the update, we need to find the next node we need to update after the current node, until we
				reach the end (or the biggest number in the tree)


			for the update we have the formula:

				i += i & (-i)

'''


class Solution:
	def createSortedArray(self, instructions: List[int]) -> int:
		# the way binary index tree works while implementation is that
		# firstly we need to find the range of the numbers first
		# in this particular case our range will be the max element in the instructions array
		m = max(instructions)
		# we need 1D array to store the preSum of each of the node
		tree = [0] * (m + 1)

		# function to update values to a particular index
		def update(i, k):
			while i <= m:
				tree[i] += k
				# here we need to find the next node we need to update
				i += i & (-i)

		# function to get all the sums until i
		def getSum():
			ans = 0
			while i > 0:
				ans += tree[i]
				# finding the parents of the current i, so that we can find the next segment to
				# summarize
				i -= i & (-i)

			return ans

		ans = 0

		# Right now the value we are storing in each of the node in the binary-indexed tree
		# is how many numbers is equal or smaller than the current number

		for i, num in enumerate(instructions):
			# since the numbers we are storing on each of the nodes in the binary-index tree
			# is the number of nodes on my left, therefore when I query the left one
			# I need to exclude myself
			# as we need to find the strictly smaller numbers
			left = getSum(num - 1)

			# for right, the 'i' is the current length of the numbers
			right = i - getSum(num)
			ans += min(left, right)
			# while doing update, we pass num and 1, that means I am adding 1 to num
			# and all the numbers that include that number
			# suppose we are updating node 3 here, so we'll perform
			# 3 + 1, 4 + 1, 8 + 1 for the above described tree
			update(num, 1)
		return ans % 10**9 + 7