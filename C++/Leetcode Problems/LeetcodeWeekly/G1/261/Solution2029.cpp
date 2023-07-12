// 2029. Stone Game IX
/*
Alice and Bob continue their games with stones. There is a row of n stones, and each stone has an
associated value. You are given an integer array stones, where stones[i] is the value of the ith stone.

Alice and Bob take turns, with Alice starting first. On each turn, the player may remove
any stone from stones. The player who removes a stone loses if the sum of the values of all
removed stones is divisible by 3. Bob will win automatically if there are no remaining stones
(even if it is Alice's turn).

Assuming both players play optimally, return true if Alice wins and false if Bob wins.

Example 1:

Input: stones = [2,1]
Output: true
Explanation: The game will be played as follows:
- Turn 1: Alice can remove either stone.
- Turn 2: Bob removes the remaining stone.
The sum of the removed stones is 1 + 2 = 3 and is divisible by 3. Therefore, Bob loses and Alice wins the game.
Example 2:

Input: stones = [2]
Output: false
Explanation: Alice will remove the only stone, and the sum of the values on the removed stones is 2.
Since all the stones are removed and the sum of values is not divisible by 3, Bob wins the game.
Example 3:

Input: stones = [5,1,2,4,3]
Output: false
Explanation: Bob will always win. One possible way for Bob to win is shown below:
- Turn 1: Alice can remove the second stone with value 1. Sum of removed stones = 1.
- Turn 2: Bob removes the fifth stone with value 3. Sum of removed stones = 1 + 3 = 4.
- Turn 3: Alices removes the fourth stone with value 4. Sum of removed stones = 1 + 3 + 4 = 8.
- Turn 4: Bob removes the third stone with value 2. Sum of removed stones = 1 + 3 + 4 + 2 = 10.
- Turn 5: Alice removes the first stone with value 5. Sum of removed stones = 1 + 3 + 4 + 2 + 5 = 15.
Alice loses the game because the sum of the removed stones (15) is divisible by 3. Bob wins the game.


Constraints:

1 <= stones.length <= 10^5
1 <= stones[i] <= 10^4
*/

/*
Algo:

Reduce all numbers to remainders of 3. (4 + 1) % 3 has the same effect as ((4 % 3) + (1 % 3)) % 3.

This makes comparison much easier as it boils down to counts of 0's, 1's and 2's.

Realize that a multiple of 3 (i.e. mod value of 0) does not change the net sum. HOWEVER,
it can be used to flip the winner - but only if it's an odd number of times.

This is because, if it's an even number of times, each player can play it equally and it won't
make any difference to the outcome. However, with an odd number of occurrences, it can flip the winner.

If there are no 1's (i.e. no 1, 4, 7, etc.) then all you have are 2's

If there's less than three 2's, Bob always wins (since they both play one or two 2's and eventually
the game runs out while never meeting a multiple of 3).

If there are three or more 2's, then Bob wins as well, UNLESS there's a flip available.

Same as above if there are no 2's.

Next, if the gap between 1's and 2's exceeds 2, then Alice always wins.
This is because Alice plays the minority number first.
Then Bob is forced to play the same minority number, then Alice plays the majority number,
until that number is exhausted (on Bob's turn).

If there is a flip available, then Alice plays the majority number first, leading to the same outcome.

Finally, if none of the above work, Alice will be the default winner, unless there is a flip involved.
*/

#define ALICE true
#define BOB false

class Solution {
public:
	bool stoneGameIX(vector<int>& stones) {
		vector<int> a(3, 0);
		for (auto &x : stones)
			a[x % 3]++;
		bool flip = (a[0] % 2 > 0);
		if (!a[1])
			return (a[2] < 3 ? BOB : flip);
		if (!a[2])
			return (a[1] < 3 ? BOB : flip);
		if (abs(a[1] - a[2]) > 2)
			return ALICE;
		return !flip;
	}
};