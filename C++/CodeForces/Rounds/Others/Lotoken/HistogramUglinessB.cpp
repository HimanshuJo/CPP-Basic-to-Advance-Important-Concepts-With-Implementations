// Histogram Ugliness

/*

Little Dormi received a histogram with n bars of height a1,a2,…,an for Christmas. 

However, the more he played with his new histogram, the more he realized its imperfections, 
so today he wanted to modify it to his liking.

To modify the histogram, Little Dormi is able to perform the following operation an arbitrary number of times:

    Select an index i (1≤i≤n) where ai>0, and assign ai:=ai−1.

Little Dormi defines the ugliness score of his histogram (after performing some number of operations)
    as the sum of the vertical length of its outline and the number of operations he performed on it. 
    
    And to make the histogram as perfect as possible, he would like to minimize the ugliness score 
    after modifying it with some number of operations.

However, as his histogram is very large, Little Dormi is having trouble minimizing the ugliness score,
    so as Little Dormi's older brother, help him find the minimal ugliness.

Input

Each test contains multiple test cases. The first line contains the number of test cases t
(1≤t≤10^4). Description of the test cases follows.

The first line of each test case contains a single integer n
(1≤n≤4⋅10^5).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤10^9).

It is guaranteed that the sum of n over all test cases does not exceed 4⋅10^5

Output

For each test case output one integer, the minimal ugliness Little Dormi can achieve
    with the histogram in that test case.

Example
Input

2
4
4 8 9 6
6
2 1 7 4 0 0

Output

17
12

*/

/*
    It's only optimal to decrease a column if ai > ai + 1, and ai > ai - 1, as that would reduce the
        vertical length of the outline by 2 while only costing 1 operation.

    Additionally, observe that decreasing a column will never affect whether it is optimal to decrease
        an other column, so we can treat the operations as independent

    Thus, our algorithm is as follows, while it is optimal to decrease a column, we will do it

    Once this is no longer the case, we can calculate the final value of the histogram

    Final Time: O(n)
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxSize = 4e5 + 2;
ll arr[maxSize];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        arr[n + 1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> arr[i];
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ll temp = min(arr[i], max(arr[i - 1], arr[i + 1]));
            ans += arr[i] - temp + abs(temp - arr[i - 1]);
            arr[i] = temp;
        }
        cout << ans + arr[n] << "\n";
    }
}