// Minimum Absolute Difference Queries

/*
 * The minimum absolute difference of an array a is defined as the minimum value of
 * |a[i] - a[j]|, where 0 <= i < j < a.length and a[i] != a[j].
 *
 * If all elements of a are the same, the minimum absolute difference is -1.
 *
 * For example, the minimum absolute difference of the array [5,2,3,7,2] is |2 - 3| = 1.
 * Note that it is not 0 because a[i] and a[j] must be different.
 *
 * You are given an integer array nums and the array queries where queries[i] = [li, ri].
 * For each query i, compute the minimum absolute difference of the subarray
 * 	nums[li...ri] containing the elements of nums between the 0-based indices
 * 	li and ri (inclusive).
 *
 * Return an array ans where ans[i] is the answer to the ith query.

	A subarray is a contiguous sequence of elements in an array.

	The value of |x| is defined as:

	    x if x >= 0.
	    -x if x < 0.

	Example 1:

	Input: nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
	Output: [2,1,4,1]
	Explanation: The queries are processed as follows:
	- queries[0] = [0,1]: The subarray is [1,3] and the minimum absolute difference is |1-3| = 2.
	- queries[1] = [1,2]: The subarray is [3,4] and the minimum absolute difference is |3-4| = 1.
	- queries[2] = [2,3]: The subarray is [4,8] and the minimum absolute difference is |4-8| = 4.
	- queries[3] = [0,3]: The subarray is [1,3,4,8] and the minimum absolute difference is |3-4| = 1.

 */

/*
 * Naive Approach:
 * 	For each of the query, we have to traverse the array between the range {l, r}
 * 		, then probably we can sort the array to get the minimum of the numbers in the range
 *
 * 	As in the worst case the size of the nums array could be 10^5,
 * 		this approach won't work, as complexity will be O(n^2)
 *
 * 	However, the other constraint is helpful for our approach:
 * 		1 <= nums[i] <= 100
 *
 * 	class Solution:
 * 		def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
 * 			maxNum = max(nums)
 * 			n = len(nums)
 * 			preSum = [[0] * (maxNum + 1)]
 * 			for num in nums:
 * 				curSum =  preSum[-1][:]
 * 				curSum[num] += 1
 * 				preSum.append(curSum)
 * 			ans = []
 * 			for l, r in queries:
 * 				mmin = sys.maxsize
 * 				pre = -1
 * 				for num in range(1, maxNum + 1):
 * 					cnt = preSum[r + 1][num] - preSum[l][num]
 * 					if cnt > 0:
 * 						if pre != -1:
 * 							mmin = min(min, num - pre)
 * 						pre = num
 * 				ans.append(mmin if mmin < sys.maxsize else -1)
 * 			return ans
 *
 * Time: O(n*100)
 *
 * -------
 *
 * In essence, we can use 100 prefix sum arrays to count each number, so we can determine in O(1)
 * 		time, if a number appears in [l, r] interval
 *
 * We can iterate through [1, 100] and check that number appears in the query range
 *
 * 	Then we can track the minimum difference between consecutive numbers
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> minDifference(vector<int> &nums, vector<vector<int>> &qs)
	{
		vector<int> res, idx[101];
		for (int i = 0; i < nums.size(); ++i)
		{
			idx[nums[i]].push_back(i);
		}
		for (int i = 0; i < qs.size(); ++i)
		{
			int prev = 0, delta = INT_MAX;
			for (int j = 1; j <= 100; ++j)
			{
				auto it = lower_bound(begin(idx[j]), end(idx[j]), qs[i][0]);
				if (it != end(idx[j]) && *it <= qs[i][1])
				{
					delta = min(delta, prev == 0 ? INT_MAX : j - prev);
					prev = j;
				}
			}
			res.push_back(delta == INT_MAX ? -1 : delta);
		}
		return res;
	}
};

/*
	For prefix sum we can keep a prefix count array and get the numbers in between range by subtracting
		prefix[right+1] - prefix[left] and then checking consecutive numbers for the difference
*/

class Solution_PrefixSum
{
public:
	vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
	{
		int n = nums.size();
		vector<vector<int>> prefix(100001);
		vector<int> present(101, 0);
		prefix[0] = present;
		// here we have to store prefix elements counts for each index
		for (int i = 0; i < n; ++i)
		{
			present[nums[i]]++;
			prefix[i + 1] = present;
		}
		vector<int> ans;
		for (auto &q : queries)
		{
			int l = q[0], r = q[1];
			vector<int> curr(101, 0);
			// subtract the left with right+1 for each num to get the count for curr range
			for (int i = 0; i <= 100; ++i)
			{
				curr[i] = prefix[r + 1][i] - prefix[l][i];
			}
			int count = 0;
			for (int i = 0; i <= 100; ++i)
			{
				if (curr[i] > 0)
				{
					count++;
				}
			}
			if (count <= 1)
			{
				ans.push_back(-1);
			}
			else
			{
				// here we have to find the min difference with all the values present in this range
				int diff = INT_MAX, prev = -1;
				// we will take the consecutive numbers difference which are present in the range
				// as consecutive numbers will be the most optimal way to get the min difference
				for (int i = 0; i <= 100; ++i)
				{
					if (curr[i] > 0)
					{
						// if prev was -1, it is the first number
						if (prev == -1)
						{
							prev = i;
						}
						else
						{
							// it is not the first number prev was something, take the difference
							diff = min(diff, i - prev);
							prev = i;
						}
						// if we encounter 1, we can't go any further lower, we can just break the loop
						if (diff == 1)
						{
							break;
						}
					}
				}
				ans.push_back(diff);
			}
		}
		return ans;
	}
};
