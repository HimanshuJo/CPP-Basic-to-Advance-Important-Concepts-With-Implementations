#include <bits/stdc++.h>
using ll = long long;
using namespace std;

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
        int arr[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        if (n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        int sz = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + sz);
        ll diffs[n - 1];
        for (int i = 0; i < n - 1; ++i)
        {
            diffs[i] = arr[i + 1] - arr[i];
        }
        ll res = 0L;
        for (int i = 0; i < n - 1; ++i)
        {
            res -= diffs[i] * (i + 1) * (n - 1 - i);
        }
        for (ll x : diffs)
        {
            res += x;
        }
        cout << res << "\n";
    }
}