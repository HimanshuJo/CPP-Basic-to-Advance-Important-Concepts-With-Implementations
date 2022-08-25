#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumDeletions(string s)
{
    int n = s.length();
    int ans = n;
    for (int i = n - 1; i >= 0; i--)
    {
        int t = s[i] - '0';
        if (t % 5 == 0)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                int num = (s[j] - '0') * 10 + t;
                if (num % 25 == 0)
                {
                    int k1 = i - j - 1;
                    int k2 = n - i - 1;
                    ans = min(ans, k1 + k2);
                }
            }
        }
    }
    if (ans == n)
    {
        for (int i = 0; i < n; i++)
        {
            int num = s[i] - '0';
            if (num % 25 == 0)
            {
                ans = n - 1;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string tmp = to_string(n);
        cout << minimumDeletions(tmp) << "\n";
    }
}