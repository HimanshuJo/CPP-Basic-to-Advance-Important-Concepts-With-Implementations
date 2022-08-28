// 1986. Minimum Number of Work Sessions to Finish the Tasks
/*
There are n tasks assigned to you.
The task times are represented as an integer array tasks of length n,
where the ith task takes tasks[i] hours to finish.
A work session is when you work for at most sessionTime consecutive
hours and then take a break.

You should finish the given tasks in a way that satisfies the
following conditions:

If you start a task in a work session, you must complete it
in the same work session.
You can start a new task immediately after finishing the previous one.
You may complete the tasks in any order.
Given tasks and sessionTime, return the minimum number of work
sessions needed to finish all the tasks following the conditions above.

The tests are generated such that sessionTime is greater than
or equal to the maximum element in tasks[i].

Example 2:

Input: tasks = [3,1,3,1,1], sessionTime = 8
Output: 2
Explanation: You can finish the tasks in two work sessions.
- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
- Second work session: finish the last task in 1 hour.
*/
/*
Algorithm

We use 2 things -> mask to denote which elements are processed. If ith bit is 1 means ith element is
processed. -> currentTime we start with 0 as current time.

At each call go through all the unprocessed elements only.

We can choose to include the ith unprocessed element in current session like
this -> help(a, mask | (1<<i), currTime + a[i])

Or choose to include it in next session like this -> 1 + help(a, mask | (1<<i), a[i])

Take minimum of step 3 and 4 across all unprocessed elements like this ->
ans = min({ans, includeInCurrentSession, includeInNextSession}).

If currentTime becomes more than targetTime it is invalid state.

If all elements are processed then its the end of our algorithm.

Note:
When we do mask | (1<<i) we set the ith bit in mask to indicate element at ith position is processed.
When we do mask & (1<<i) we are checking if ith bit in mask is set or not.
*/

class Solution {
public:
    int n, time, allOnes;
    int ans;

    int minSessions(vector<int>& a, int t) {
        vector<vector<int>>memo(100000, vector<int>(16, -1));
        time = t;
        n = a.size();
        allOnes = (1 << n) - 1;
        ans = 1;
        ans = dfs(a, 0, 0, memo);
        return ans;
    }

    int dfs(vector<int> &a, int mask, int currTime, vector<vector<int>>&memo) {
        if (currTime > time) return INT_MAX;
        if (mask == allOnes) return 1;
        if (memo[mask][currTime] != -1) return memo[mask][currTime];
        int ans = INT_MAX;
        for (int i = 0 ; i < n ; i++) {
            if ((mask & (1 << i)) == 0) {
                int includeInCurrentSession = dfs(a, mask | (1 << i), currTime + a[i], memo);
                int includeInNextSession = 1 + dfs(a, mask | (1 << i), a[i], memo);
                ans = min({ans, includeInCurrentSession, includeInNextSession});
            }
        }
        return memo[mask][currTime] = ans;
    }
};