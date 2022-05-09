#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define MOD (ll)998244353
#define ll long long
#define pb push_back
#define rep(i, n) for (ll i = 0; i < n; ++i)

vector<int> e[N];

int d[N][5];
int mx[5];
int mv[5];
int idx, blc, num, cnt;

void dfs(int k, int p)
{
    if (p == -1)
        d[k][idx] = 0;
    else
        d[k][idx] = d[p][idx] + 1;
    if (mx[idx] < d[k][idx])
    {
        mx[idx] = d[k][idx];
        mv[idx] = k;
    }
    if (d[k][idx] == num)
        cnt++;
    int sz = e[k].size();
    rep(i, sz)
    {
        if ((e[k][i] != blc) && (d[e[k][i]][idx] < 0))
            dfs(e[k][i], k);
    }
    return;
}

int main(void)
{
    int n;
    int u, v, sz;
    vector<int> a;
    ll x, ans;

    rep(i, 5)
    {
        rep(j, N) d[j][i] = -1;
        mx[i] = -1;
    }
    blc = -1;

    cin >> n;
    rep(i, n - 1)
    {
        cin >> u >> v;
        e[u - 1].pb(v - 1);
        e[v - 1].pb(u - 1);
    }

    idx = 0;
    dfs(0, -1);
    idx = 1;
    dfs(mv[0], -1);
    idx = 2;
    dfs(mv[1], -1);

    if (mx[1] % 2 == 1)
    {
        rep(i, n)
        {
            if ((d[i][1] == (mx[1] / 2)) && (d[i][2] == (mx[1] / 2) + 1))
                u = i;
            if ((d[i][2] == (mx[1] / 2)) && (d[i][1] == (mx[1] / 2) + 1))
                v = i;
        }

        idx = 3;
        num = mx[1] / 2;

        blc = v;
        cnt = 0;
        dfs(u, -1);
        a.pb(cnt);

        blc = u;
        cnt = 0;
        dfs(v, -1);
        a.pb(cnt);
    }
    else
    {
        rep(i, n)
        {
            if ((d[i][1] == (mx[1] / 2)) && (d[i][2] == (mx[1] / 2)))
                u = i;
        }

        idx = 3;
        num = (mx[1] / 2) - 1;
        blc = u;

        sz = e[u].size();
        rep(i, sz)
        {
            cnt = 0;
            dfs(e[u][i], -1);
            a.pb(cnt);
        }
    }

    sz = a.size();
    ans = 1;
    rep(i, sz)
    {
        x = a[i] + 1;
        ans = (ans * x) % MOD;
    }
    rep(i, sz)
    {
        x = a[i];
        ans = (ans + MOD - x) % MOD;
    }
    ans = (ans + MOD - 1) % MOD;

    cout << ans << endl;
    return 0;
}
