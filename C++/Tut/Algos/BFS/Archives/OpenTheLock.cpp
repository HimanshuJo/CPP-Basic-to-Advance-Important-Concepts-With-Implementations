/*
You have a lock in front of you with 4 circular wheels. 

Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 

The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. 

Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of dead ends, meaning if the lock displays any of these codes, 
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock, 
return the minimum total number of turns required to open the lock, or -1 if it is impossible.

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
because the wheels of the lock become stuck after the display becomes the dead end "0102".

Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.

Example 4:

Input: deadends = ["0000"], target = "8888"
Output: -1

-------

Intuition:

	Every time we have a situation like getting minimum total number to reach from one state to another
		(where we have a very well defined 'start state' and a very well defined 'last state')
		we have to go for BFS

		And then while exploring the paths often we have some rules, in this particular case we have few deadends
			so, here these are the conditions we need to use whenever we try to explore the next paths

		If the next value is in the deadends list, we can't go that route

*/

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000"))
            return -1;
        queue<string> q({"0000"});
        for (int steps = 0; !q.empty(); ++steps)
        {
            for (int i = q.size(); i > 0; --i)
            {
                auto curr = q.front();
                q.pop();
                if (curr == target)
                    return steps;
                for (auto nei : neighbors(curr))
                {
                    if (deadSet.count(nei))
                        continue;
                    deadSet.insert(nei); // Marked as visited
                    q.push(nei);
                }
            }
        }
        return -1;
    }
    
    vector<string> neighbors(const string &code)
    {
        vector<string> result;
        for (int i = 0; i < 4; i++)
        {
            for (int diff = -1; diff <= 1; diff += 2)
            {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};

/*

-------

class Solution:
	def openLock(self, deadends: List[str], target: str) -> int:
		deadSet = set(deadends)
		# corner cases
		if "0000" in deadSet:
			return -1
		queue = deque(["0000"])
		ans = 0
		seen = set()
		seen.add("0000")
		while queue:
			lenQueue = len(queue)
			for _ in range(lenQueue):
				cur = queue.popleft()
				if cur == target:
					return ans
				for i in range(4):  # since we have 4 digits in total
					# for each digit either we can move forward or backward
					# for moving forward
					newDigit1 = (int(cur[i]) + 1) % 10  # why % 10 because for 9 we will be needing 0
					newCode1 = cur[:i] + str(newDigit1) + cur[i + 1:]
					if newCode1 not in seen and newCode1 not in deadSet:
						queue.append(newCode1)
						seen.add(newCode1)

					# for moving backward
					newDigit2 = (int(cur[i]) + 10 - 1) % 10
					newCode2 = cur[:i] + str(newDigit2) + cur[i + 1:]
					if newCode2 not in seen and newCode2 not in deadSet:
						queue.append(newCode2)
						seen.add(newCode2)

			ans += 1

		return -1

-------

Time: Total possible states here -> 10^4
		as we have 4 digits and each digit has 10 possible states

		we can form from 0000 ... 9999

	  In our program for each state we have a for loop here of size 4 and doing string concatenation

	  	therefore, 10^4 * 4^2 + 500 * 4 to put everything into the deadSet

  	  	so in total: 10^4 * 4^2 + 500 * 4

Space: 500 * 4 for deadSet

	   10^4 * 4 for queue <- dominated by queue

-------

Idea

    By using BFS, we can generate all possible of locks, initialize with "0000".

    For each step, we can generates neighbors of current lock state 
    	(by turning clockwise or counter-clockwise of 4 circular wheels) and go to its neighbors 
    	if neighbor is not in our deadends.

    If we meet the target then the current steps is minimum number of turns to open the target lock.

Complexity

    Time: O(N^2 * A^N + D), where N is number of dials (4 in our case), A is number of alphabet (10 in our case), D is size of deadends.
        There are 10^4 possible combinations => A^N
        For each combination, we are looping 4 times (which is N) and in each iteration, 
        there are substring operations which costs O(N) => O(N^2)

        Total O(D) to create the hashset

    Space: O(A^N), in worst case equal to number of combinations.
*/