// 1997. First Day Where You Have Been in All the Rooms
/*
There are n rooms you need to visit, labeled from 0 to n - 1. Each day is labeled, starting from 0.
You will go in and visit one room a day.

Initially on day 0, you visit room 0. The order you visit the rooms for the coming days is determined by the
following rules and a given 0-indexed array nextVisit of length n:

Assuming that on a day, you visit room i,
if you have been in room i an odd number of times (including the current visit), on the next day you will
visit the room specified by nextVisit[i] where 0 <= nextVisit[i] <= i;

if you have been in room i an even number of times (including the current visit), on the next day you will visit
room (i + 1) mod n.

Return the label of the first day where you have been in all the rooms. It can be shown that such a day exists.
Since the answer may be very large, return it modulo 10^9 + 7.

Example 3:

Input: nextVisit = [0,1,2,0]
Output: 6
Explanation:
Your room visiting order for each day is: [0,0,1,1,2,2,3,...].
Day 6 is the first day where you have been in all the rooms.
*/
/*
Note 1: To the pass any index i the number of visits must become even
If the number of visits are odd you will end up going a index j = nextVisit[i] with 0 <= j <= i
(Since 0 <= nextVisit[i] <= i)

Assume days[i] = number of days required to pass i if you visit index i for the fist time

Note 2 If you visited i for the first time, it would always be an odd visit, and you will have to go to nextVisit[i].

Now let j = nextVisit[i]

Case 1
If j == i then you will again reach i and number of visits will become even and you can move to i+1. Thus, days[i] = 2

Case 2
If j < i, then this visit to j will always be odd one (Because you have already passed j earlier and thus number of
visits must have become even).

Thus, to calculate days[i] = number of days required to pass i, you need to first pass j, then you will reach j+1,
and now you have to pass j+1, then you reach j+2 and so on.

And then you will finally arrive at i and this time number of visits will be even and thus you can go to i+1.
Thus = days[i] = 2 + days[j] + days[j+1] + days[j+2] + ... + days[i-1]
2 because you also arrive at i 2 times.

But note that doing this naively will cause TLE thus you can use prefix sum approach to optimize the solution.
*/

int mod = 1000000007;

class Solution
{
public:
    int firstDayBeenInAllRooms(vector<int> &nextVisit)
    {
        int n = nextVisit.size();
        vector<int> days(n);
        // days[i] = number of days required to pass i if you visit index i for the fist time
        vector<int> pre(n + 1);
        pre[0] = 0;
        // pre[i] = days[0] + days[1] + ... + days[i-1]
        for (int i = 0; i < n; i++)
        {
            int j = nextVisit[i];
            if (j == i)
            {
                days[i] = 2;
            }
            else
            {
                assert(j < i);
                // days[i] = 2 + (days[j] + days[j+1] + days[j+2] + ... + days[i-1]);
                days[i] = 2 + (pre[i] - pre[j]);
                days[i] = days[i] % mod;
                if (days[i] < 0)
                    days[i] += mod;
            }
            pre[i + 1] = (pre[i] + days[i]) % mod;
        }
        return (pre[n - 1]) % mod;
    }
};

/*
Let dp[i] be the number of days needed to jump from room 0 to room i. The answer is dp[N - 1].

For dp[i], on top of the days needed for reaching room i-1, i.e. dp[i-1], we need these extra days to go from
room i-1 to room i.

If A[i-1] == i-1, we just need 2 days
Otherwise, we need to jump to room A[i-1] first, taking 1 day. Then spent dp[i-1] - dp[A[i-1]] days to go from
room A[i-1] to room i-1 again. Lastly, take 1 day to go from room i-1 to room i.

So in total, we need extra 2 + dp[i-1] - dp[A[i-1]] days.
*/

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& A) {
        long mod = 1e9 + 7, N = A.size();
        vector<int> dp(N + 1);
        for (int i = 1; i < N; ++i) {
            dp[i] = ((long)2 + 2 * dp[i - 1] - dp[A[i - 1]] + mod) % mod;
        }
        return dp[N - 1];
    }
};
