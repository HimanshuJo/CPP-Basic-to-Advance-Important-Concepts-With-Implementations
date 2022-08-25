/*

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Given two integers n and k, construct a permutation a of numbers from 1 to n which has exactly k peaks.

An index i of an array a of size n is said to be a peak if 1<i<n and ai>ai−1 and ai>ai+1.

If such permutation is not possible, then print −1

Input

The first line contains an integer t
(1≤t≤100) — the number of test cases.

Then t lines follow, each containing two space-separated integers n (1≤n≤100) and k (0≤k≤n) —
the length of an array and the required number of peaks.

Output

Output t lines.

For each test case, if there is no permutation with given length and number of peaks, then print −1.
Otherwise print a line containing n space-separated integers which forms a permutation of numbers from 1 to n and
contains exactly k peaks.

If there are multiple answers, print any.

Example
Input

5
1 0
5 2
6 6
2 1
6 1

Output

1
2 4 1 5 3
-1
-1
1 3 6 5 4 2

Note

In the second test case of the example, we have array a=[2,4,1,5,3]
. Here, indices i=2 and i=4 are the peaks of the array. This is because (a2>a1, a2>a3) and (a4>a3, a4>a5).

*/

/*

The key idea is we try to use the first k largest elements from n to n - k + 1 to construct the k peaks

So try constructing the array like this:

    1, n, 2, n - 1, 3, n - 2, ..... , n - k + 1, k + 1, k + 2, ...., n - k

For this answer to be possible n - k + 1 > k + 1

    that means n > 2 * k

    If this is not the case we output -1

*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> res(n + 1);
        int num = n;
        // first filling at even places
        for (int i = 2; i < n; i += 2)
        {
            if (k == 0) break;
            res[i] = num--;
            k--;
        }
        if (k)
        {
            cout << -1 << "\n";
            continue;
        }
        int cur = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (!res[i])
            {
                res[i] = cur++;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << res[i] << " ";
            cout << "\n";
        }
    }
}