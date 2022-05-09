#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n;
        cin >> k;

        int arr[n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        bool kEnd = false;
        int j = n - 1;

        for (int i = 0; i < n; ++i)
        {
            while (k > 0 && arr[i] > 0)
            {
                arr[i]--;
                arr[n - 1]++;
                k--;
            }
        }

        for (int nm : arr)
            cout << nm << " "
                 << "\n";
    }
}