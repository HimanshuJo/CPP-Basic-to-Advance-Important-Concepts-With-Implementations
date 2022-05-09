
/*

Let's call a positive integer n ordinary if in the decimal notation all its digits 
are the same. 

For example, 1, 2 and 99 are ordinary numbers, but 719 and 2021 are not ordinary numbers.

For a given number n , find the number of ordinary numbers among the numbers from 1 to n.

*/

#include <bits/stdc++.h>
typedef long long ll;

#define endl "\n"
#define cust                     \
    ios_base::sync_withstdio(0); \
    cin.tie(0);                  \
    cout.tie(0);

using namespace std;

void solve()
{
    int n;
    cin >> n;

    int ans = 0, t = 1;

    while (t <= n)
    {
        for (int i = 1; i <= 9; ++i)
            if (t * i <= n)
                ++ans;
        t = t * 10 + 1;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        solve();
    }
}