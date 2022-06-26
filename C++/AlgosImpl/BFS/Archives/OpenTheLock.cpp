/*
You have a lock in front of you with 4 circular wheels.

Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'.

The wheels can rotate freely and wrap around: for example we can turn
'9' to be '0', or '0' to be '9'.

Each move consists of turning one wheel one slot.

The lock initially starts at '0000', a string representing the state of the 4 wheels.

You are given a list of dead ends, meaning if the lock displays any of these codes,
the wheels of the lock will stop turning and you will be unable to open it.

Given a target representing the value of the wheels that will unlock the lock,

return the minimum total number of turns required to open the lock, or -1 if
it is impossible.

Example 1:

Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
Output: 6
Explanation:
A sequence of valid moves would be
"0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202"
would be invalid,
because the wheels of the lock become stuck after the display becomes the
dead end "0102".

Example 2:

Input: deadends = ["8888"], target = "0009"
Output: 1
Explanation:
We can turn the last wheel in reverse to move from "0000" -> "0009".

Example 3:

Input: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"],
target = "8888"
Output: -1
Explanation:
We can't reach the target without getting stuck.

Example 4:

Input: deadends = ["0000"], target = "8888"
Output: -1

Constraints:

1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target will not be in the list deadends.
target and deadends[i] consist of digits only.
*/

class Solution
{
public:
    set<string> deadSet;
    int openLock(vector<string> &deadends, string target)
    {
        copy(deadends.begin(), deadends.end(), inserter(deadSet, deadSet.begin()));
        if (deadSet.count("0000"))
        {
            return -1;
        }
        deadSet.insert("0000");
        queue<string> q({"0000"});
        int steps = 0;
        while (!q.empty())
        {
            int qSz = q.size();
            while (qSz--)
            {
                auto curr = q.front();
                q.pop();
                if (curr == target)
                {
                    cout << steps;
                    return steps;
                }
                for (int i = 0; i < 4; ++i)
                {
                    int newDig1 = ((curr[i] - '0') + 1) % 10;
                    string nwCode1 = curr.substr(0, i);
                    nwCode1 += to_string(newDig1);
                    nwCode1 += curr.substr(i + 1, curr.length() - i + 1);
                    auto it1 = deadSet.find(nwCode1);
                    if (it1 == deadSet.end())
                    {
                        q.push(nwCode1);
                        deadSet.insert(nwCode1);
                    }
                    int newDig2 = ((curr[i] - '0') + 9) % 10;
                    string nwCode2 = curr.substr(0, i);
                    nwCode2 += to_string(newDig2);
                    nwCode2 += curr.substr(i + 1, curr.length() - i + 1);
                    auto it2 = deadSet.find(nwCode2);
                    if (it2 == deadSet.end())
                    {
                        q.push(nwCode2);
                        deadSet.insert(nwCode2);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};


int main() {
    Solution obj;
    vector<string>deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    obj.openLock(deadends, target);
}