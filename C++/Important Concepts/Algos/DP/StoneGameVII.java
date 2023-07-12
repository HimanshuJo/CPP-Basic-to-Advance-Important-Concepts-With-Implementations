/*
Alice and Bob take turns playing a game, with Alice starting first.

There are n stones arranged in a row. On each player's turn, while the number of stones 
is more than one, they will do the following:

    Choose an integer x > 1, and remove the leftmost x stones from the row.
    Add the sum of the removed stones' values to the player's score.
    Place a new stone, whose value is equal to that sum, on the left side of the row.

The game stops when only one stone is left in the row.

The score difference between Alice and Bob is (Alice's score - Bob's score). 
Alice's goal is to maximize the score difference, and Bob's goal is the minimize the score difference.

Given an integer array stones of length n where stones[i] represents the value of 
the ith stone from the left, return the score difference between Alice and Bob if 
they both play optimally.

Example 1:

Input: stones = [-1,2,-3,4,-5]
Output: 5
Explanation:
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
  value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
  the left. stones = [-3].
The difference between their scores is 2 - (-3) = 5.

*/
/*
Let Prefix sum:
	
	prefix[i] = A[0] + ..... + A[i]

	Let dp[i] be the minimum score difference the current player can get when the game starts at i,
		0 ... i are already merged as a new stone i whose value is prefix[i]

	Consider dp[i]:
		assume the current player chooses to merge stone 0..j (i < j < N), according to the dp definition
		the maximum score difference the next player can get using the remaining stones is dp[j]

		So the score difference the current player gets is prefix[j] - dp[j]

	The current player will need to try all i < j < N and use the maximum prefix[j] - dp[j] as dp[i]

	-------

	Thus we have:
		dp[i] = max(prefix[j] - dp[j] | i < j <= N - 2)

	When there are only two stones left, the current player must take them all
		dp[N - 2] = prefix[N - 1]

	The answer is dp[0]

-------

Some key points to note here:

	1. The move with the last stone as stones[i], no matter by alice or bob, will actually add the sum[i]
		to his score

		For the first move, if takes stone 0 and 1, the stone array will become

			[stone[0] + stone[1], stone[2], .... stone[i]]

	Later if the other player takes the first 3 stones, the score he'll get will be:
		(stone[0] + stone[1]) + stone[2] + stone[3]

		no matter how you try, the score you are getting will always be the sum up to the ith stone

	So here we've to figure out our sum[] array

	-------

	2. Let's suppose we have 2 sums left, and it's Alice's turn
		sum = [a, b]

		Will alice take the sum a, or will she just take the b and skipping the a?
			It depends on Math.max(b, a - b)

		How about 3 sums left?

			sum = [a, b, c]

			so alice in this case have 3 possibilities

				1. Alice takes the first sum 'a'

					Later Bob will back the sum = [b, c] the previous case

					Bob will take Math.max(c, b - c) as previously concluded

					The difference will be (a - Math.max(c, b - c))

				2. Alice takes b, and Bob will take c

					The difference will be (b - c)

				3. Alice takes c

					The difference will be c

	-------

	Dp will be as follows:

		f(n) = sum[n]

		f(n - 1) = Math.max(sum[n - 1] - f(n), f(n))

		.......

		f(i) = Math.max(sum[i] - f[i + 1], f[i + 1])

*/

class Solution {
	public int stoneGameVII(int[] stones) {
		int[] sum = new int[stones.length];
		sum[0] = stones[0];
		for (int i = 1; i < stones.length; ++i) {
			sum[i] = sum[i - 1] + stones[i];
		}
		int[] dp = new int[stones.length];
		dp[stones.length - 1] = sum[stones.length - 1];
		for (int i = stones.length - 2; i >= 0; --i) {
			dp[i] = Math.max(sum[i] - dp[i + 1], dp[i + 1]);
		}
		// Alice cannot take one stone, so it has to be starting from dp[1], not dp[0]
		return dp[1];
	}
}