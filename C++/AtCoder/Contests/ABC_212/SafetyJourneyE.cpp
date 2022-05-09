#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int mod = 998'244'353;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<vector<int>> gr(N);
        while (M--)
        {
            int u, v;
            cin >> u >> v;
            --u, --v;
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        rep(i, N)
        {
            gr[i].push_back(i);
        }
        int dp[2][N];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        rep(i, K)
        {
            int s = 0;
            rep(j, N)
            {
                if (i % 2 == 0)
                {
                    s += dp[0][j];
                    s %= mod;
                }
                else
                {
                    s += dp[1][j];
                    s %= mod;
                }
            }
            rep(j, N)
            {
                if ((i + 1) % 2 == 0)
                {
                    dp[0][j] = s;
                }
                else
                {
                    dp[1][j] = s;
                }
                for (auto ii : gr[j])
                {
                    if ((i + 1) % 2 == 0)
                    {
                        if (i % 2 == 0)
                        {
                            dp[0][j] -= dp[0][ii];
                        }
                        else
                        {
                            dp[0][j] -= dp[1][ii];
                        }
                        dp[0][j] += mod;
                        dp[0][j] %= mod;
                    }
                    else
                    {
                        if (i % 2 == 0)
                        {
                            dp[1][j] -= dp[0][ii];
                        }
                        else
                        {
                            dp[1][j] -= dp[1][ii];
                        }
                        dp[1][j] += mod;
                        dp[1][j] %= mod;
                    }
                }
            }
        }
        cout << dp[K & 1][0] << "\n";
    }
}