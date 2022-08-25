/*
You are given an array a1,a2,…,an consisting of n distinct integers.
Count the number of pairs of indices (i,j) such that i<j and ai⋅aj=i+j
Input

The first line contains one integer t (1≤t≤10^4) — the number of test cases.
Then t cases follow.

The first line of each test case contains one integer n (2≤n≤10^5) — the length of array a

The second line of each test case contains n space separated integers a1,a2,…,an (1≤ai≤2⋅n) — the array a

It is guaranteed that all elements are distinct.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5

Output

For each test case, output the number of pairs of indices (i,j) such that i<j and ai⋅aj=i+j

Example
Input

3
2
3 1
3
6 1 5
5
3 1 5 9 2

Output

1
1
3

Note

For the first test case, the only pair that satisfies the constraints is (1,2), as a1⋅a2=1+2=3

For the second test case, the only pair that satisfies the constraints is (2,3)

For the third test case, the pairs that satisfy the constraints are (1,2), (1,5), and (2,3).
*/

/*
    Intuition: Are there any pairs which can be leaved out (or we don't need to check these pairs)

        In the given equation: (ai * aj = i + j) we've to apply some properties

        Suppose our ai = 5, so the product of ai with any number will be a multiple of 5

            For that we have to keep (i + j) also in the multiple of 5

        Suppose currently the value of i=3, so if i=3 what could be the value of j
            so that it should remian the multiple of 5

            in essence we want i+j = 5 * y
                so if i=3, then j could be 2, 7, 12, 17, 22.. and so on

            so for a particular i, where the value of ai was 5 and the value of i was 3
                we always want to keep (i+j) as a multiple of 5

            Doing this, we are checking the numbers ina gap of 5 e.g. we won't be checking the
                value of j from 8 till 12 and so on

        -------

        So for a particular array, we first have to check for all possible i's
            but only for limited j's

            e.g. i=2 and ai=6

                    here we know that if a[i]=6, so 6*a[j] will be a multiple of 6

                    so in this we will place 2+j such that it should also be the multiple of 6

                    so in this case we can place 4, 10, 16
*/
/*
    Brute Force:

        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;

        int check(int i, int j, ll arr, ll arr2)
        {
            int res = -1;
            if (arr * arr2 == i + j)
            {
                res = 1;
                return res;
            }
            return res;
        }

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
                ll arr[n];
                for (int i = 0; i < n; ++i)
                {
                    cin >> arr[i];
                }
                int res = 0;
                for (int i = 0; i < n - 1; ++i)
                {
                    for (int j = i + 1; j < n; ++j)
                    {
                        int temp = check(i + 1, j + 1, arr[i], arr[j]);
                        res = temp == -1 ? res : res + 1;
                    }
                }
                cout << res << "\n";
            }
            return 0;
        }
*/
/*
    Constraints:
    
        Hint 1: i+j <= 2* n

        Hint 2: The number of pairs(a, b) such that a*b <= x is O(xlogx)

    Algo:

        We can loop over all the value of ai and aj. Because i+j <= 2 * n, we only care about pairs
            (ai, aj) if ai * aj <= 2 * n

        The number of such pairs is O(n * log n), so we can brute force all the pairs

        The reason all the pairs is O(nlogn) is because if the first element of the pair is x,
            there are only 2*n/x possible values of:

                y * 2*n/1 + 2*n/2 + 2*n/3 + ... + 2*n/n
                = 2 * n (1/1 + 1/2 + 1/3 ... + 1/n) = O(nlogn) by the harmonic series
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(int i, int j, ll arr, ll arr2)
{
    int res = -1;
    if (arr * arr2 == i + j && i < j)
    {
        res = 1;
        return res;
    }
    return res;
}

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
        ll arr[n + 1];
        for (int i = 1; i < n + 1; ++i)
        {
            cin >> arr[i];
        }
        int res = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = arr[i] - i; j <= n; j += arr[i])
            {
                if (j >= 0)
                {
                    int temp = check(i, j, arr[i], arr[j]);
                    res = temp == -1 ? res : res + 1;
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}