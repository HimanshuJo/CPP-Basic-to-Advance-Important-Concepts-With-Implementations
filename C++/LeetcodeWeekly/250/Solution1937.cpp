// Maximum Number of Points with Cost

/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number 
of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. 
For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) 
will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

    x for x >= 0.
    -x for x < 0.

Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
*/

/*
Now we know that for each element P[i][j], we need to traverse the whole previous row, 
but it will lead to O(m) time for one element and O(m^2) time for one complete row, and O(m^2 n) for whole matrix.

So for each element in a row, instead of traversing prev whole row
what we can do is that keep left and right vectors to get max from 0 to i-1th in left side, and i+1th to n-1 in right side

left[i] = max(point[i], left[i-1] - 1)

using left we will get max from left side, using right vector we will get max from right side
and at each step we will also compare them with same col val

so for left[0] = prev[0], because there is no element in left side
for left[1] = max(prev[1], left[0] - 1), this -1 is the difference in cols (0 - 1)

Now next step is important
for left[2] = max(prev[2], left[1]-1)

at this step, if left[1] had value of just above then we had only subtracted 1 from it, and only 1 should be subtracted only
but if left[1] had left[0]-1 in it, then left[2] = left[0] - 2, now we can see it automatically subtracted 2 if 0th was max

hence in this logic it subtracts correct absolute difference of columns while choosing the maximum value
try running this more, you will understand better

// Let's try it with an example

[1,  3,  4,  2,  5] 
__  __  __  __  __
 0   1   2   3   4

what is max in left side of 0th element nothing, so it should have just above value
 1   __  __  __  __
 0   1   2   3   4

for 1th element, we have two choices, {above - 0, 0th - (1 - 0) }
0th = left[0]
left[1] = max { 3, 1 - 1 } = 3
 1   3  __  __  __
 0   1   2   3   4

for 2nd element, we have three choices, {above - 0, 0th - (2 - 0), 1st - (2 - 1) }
max of  0th - (1 - 0), 1st - (0)  = left[1] 
max of  0th - (1 - 0) - 1, 1st - (0) - 1  = left[1] - 1
left[1] = max { 4, 3 - 1 } = 4
 1   3   4  __  __
 0   1   2   3   4

for 3rd element, we have four choices, {above - 0, 0th - (3 - 0), 1st - (3 - 1), 2nd - (3 - 2) }
0th - (2 - 0), 1st - (2 - 1), 2nd - (0)  = left[2] 
max of  0th - (2 - 0) - 1, 1st - (2 - 1) - 1, 2nd - (0) - 1  = left[2] - 1
left[1] = max { 2, 4 - 1 } = 3
 1   3   4   3  __
 0   1   2   3   4

similarly, right[m-1] = prev[m-1], nothing in right side
else right[i] = max(prev[i], right[i+1] - 1)

When we have build left and right arrays for a column,
then just find the max from left or right side and add it to the current cell value
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    public:
    ll maxPoints(vector<vector<int>> &P) {
        ll n = P.size(), m = P[0].size();
        vector<ll> prev(m);
        for (int i = 0; i < m; ++i) {
            prev[i] = P[0][i];
        }
        for (int i = 1; i < n; ++i) {
            vector<ll> curr(m, 0);
            auto right = curr, left = curr;
            left[0] = prev[0];
            for (int j = 1; j < m; ++j) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }
            right[m - 1] = prev[m - 1];
            for (int j = m - 2; j >= 0; --j) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }
            for (int j = 0; j < m; ++j) {
                curr[j] = P[i][j] + max(left[j], right[j]);
            }
            prev = curr;
        }
        ll ans = prev[0];
        for (auto &i : prev) {
            ans = max(ans, i);
        }
        return ans;
    }
};