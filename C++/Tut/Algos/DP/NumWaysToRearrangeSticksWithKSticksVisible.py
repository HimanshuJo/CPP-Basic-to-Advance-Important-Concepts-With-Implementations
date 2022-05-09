'''

Number of ways to Rearrange sticks with K sticks visible:

	There are n uniquely-sized sticks whose lengths are integers from 1 to n.

	We want to arrange the sticks such that exactly k sticks are visible from the left.
		A stick is visible from the left if there are no longer sticks to the left of it

			For example:
				if the sticks are arranged [1, 3, 2, 5, 4], then the sticks with length 1, 3, and 5 are visible
					from the left

	Given n and k, return the number of such arrangements. Since the answer may be large, return it
		modulo 10^9 + 7

-------

Classic DP Problem

	n == k can be our base case

		there is only one possible arrangement, we have to arrange the numbers from smallest to the biggest

-------

For the problems like -> No. of ways most likely we're gonna need a DP to solve it + some
	combinatorics idea on top of that

Easiest way to solve it is to try some examples

	suppose we have n = 6 and k = 4

		here we just need to find a way to break this problem into sub-problems

		To break it down into sub-problems we can try two ways:

			1. we try to place the first stick

			2. or we can try to place the last stick

		If we try to place a stick in the first place, it will not give us the correct answer
			because, if we place a stick let's say in the first place depending on what's the stick after that
		 	we will have a different answer

		 		e.g. let's say n = 6 and we place a stick number 3 in the first place

		 			Now the only thing that we can guarantee is that, this stick will definitely be seen

		 			and now if we try to use this stick and try to break it down into further sub-problems
		 				so, we can say now we have n-1 number and k-1 sticks to be seen

 					However, the way dp works is that the previous state should never affect the next state

 						so if we try to place a stick at the first place, based on the stick number we place here
 							it could affect the next state

		Instead, if we can fix the rightmost stick, then we can break down the problem into sub-problems
			as we are seeing from the left

			To put a stick at the last place, there are only two scenarios:
				We just need to distinguish if we put the biggest number on the last place or not
					and the reason being is that
				
			Case1:
				
				Putting a larger stick at the last place

				suppose we put n=6 at the last place, no matter what stick we have before 6, 6 will always be visible

				In this case we can guarantee that, if we put a largest number here, the problems can be 
				break down into smaller subproblems
					
					The sub-problem becomes, given now 5 sticks we need to see k-1 sticks from the left
						dp(n-1, k-1)

			Case2:

				If we don't put the largest stick at the last place

				suppose we put 4 at the last place
					that basically means that, this stick will definitely not be visible,
						because the larger stick will somewhere be in the left

				the sub-problems for this case would be
					dp(n-1, k)  --> we still has to figure out k sticks

				So in essence, it doesn't really matter which stick do we actually fix at the last place
					other than the biggest stick, all the sub-problems will be same
						so how many scenarios we have for this case:

							dp(n-1, k) * (n-1)

		Edge Cases:

			1. if n==k return 1 (this is only one arrangement for that)

			2. when k==0, because n is always greater than k
				we have a case that we always put the largest in the end
				so if we keep doing this way, there will be time when k==0 while n!=0

				so that will be a invalid case

'''
'''

Steps:

	1. Rearrange sticks from the right most position

	2. If assign the tallest stick at this position then
			dp[n][k] += dp[n - 1][k - 1]

	3. If assign not the tallest stick at this position then
			dp[n][k] += (n - 1) * dp[n - 1][k]

	4. Base Case:

			if k > n || k == 0 then 0 or n <= 1 then 1

-------

class Solution {
	public static int MOD = (int) 1e9 + 7;

	public int rearrangeSticks(int n, int k) {
        long[][] memo = new long[n + 1][k + 1];
        memo[0][0] = 1L;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= Math.min(i, k); ++j) {
                memo[i][j] = (memo[i - 1][j] * (long) (i - 1) + memo[i - 1][j - 1]) % MOD;
            }
        }
        return (int) (memo[n][k] % MOD);
	}	
}

'''

class Solution:
	def rearrangeSticks(self, n: int, k: int) -> int:
		def dp(n, k):
			if n == k:
				return 1
			if k == 0:
				return 0
			ans = 0
			
			# case 1: put the largest stick in the end
			ans += dp(n - 1, k - 1)

			# case 2: put non largest stick in the end
			ans += (n - 1) * dp(n - 1, k)

			return ans % mod

		mod = 10**9 + 7 

		return dp(n, k)
