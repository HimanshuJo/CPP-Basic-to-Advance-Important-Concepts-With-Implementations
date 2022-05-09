#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int dfs(int v, int pre, int goal, vector<vector<pair<int, int>>> &gr, vector<int> &C)
{
    if (v == goal)
        return 1;
    for (auto [vv, i] : gr[v])
        if (vv != pre)
        {
            if (dfs(vv, v, goal, gr, C))
            {
                C[i]++;
                return 1;
            }
        }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M);
    vector<vector<pair<int, int>>> gr(N);
    vector<int> C(N - 1);
    for (int i = 0; i < M; ++i)
    {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N - 1; ++i)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        gr[x].push_back({y, i});
        gr[y].push_back({x, i});
    }
    for (int i = 0; i < M - 1; ++i)
    {
        dfs(A[i], -1, A[i + 1], gr, C);
    }
    int S = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        S += C[i];
    }
    if ((S + K) % 2 || S + K < 0)
    {
        cout << 0;
        return 0;
    }
    vector<int> dp(100001);
    dp[0] = 1;
    for (int i = 0; i < N - 1; ++i)
    {
        for (int x = 100000; x >= C[i]; --x)
        {
            (dp[x] += dp[x - C[i]]) %= mod;
        }
    }
    cout << dp[(S + K) / 2];
}