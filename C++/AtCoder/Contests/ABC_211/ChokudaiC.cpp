#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

int main()
{
    int t = 1;
    while (t--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string s;
        cin >> s;
        s.insert(0, " ");
        string temp = " chokudai";
        int mod = 1e9 + 7;
        int m = s.length();
        int n = temp.length();
        int dp[m + 1][n + 1];
        for (int i = 0; i <= n; ++i)
        {
            dp[0][i] = 0;
        }
        for (int i = 0; i <= m; ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (s.at(i) != temp.at(j))
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else if (s.at(i) == temp.at(j))
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
                }
            }
        }
        cout << dp[m - 1][n - 1] << endl;
    }
}