#include <bits/stdc++.h>
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
        int ans = 0;
        cin >> n;
        if (n == 9)
        {
            cout << 1 << "\n";
        }
        else
        {
            int temp = n % 10;
            if (temp == 9)
            {
                cout << n / 10 + 1 << "\n";
            }
            else
            {
                cout << n / 10 << "\n";
            }
        }
    }
}