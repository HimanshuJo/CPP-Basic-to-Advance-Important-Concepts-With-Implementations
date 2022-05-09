#include <bits/stdc++.h>
using namespace std;
const int mod = 998'244'353;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    -- u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    g[i].push_back(i);
  }
  vector<vector<int>> dp(2, vector<int>(n));
    for (int i = 0; i < dp.size(); i++) {
        cout << i << " ";
        for (int j = 0; j < dp[i].size(); j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
  dp[0][0] = 1;
  for (int i = 0; i < k; ++i) {
    int s = 0;
    for (int j = 0; j < n; ++j) {
      s += dp[i & 1][j];
      s %= mod;
    }

    for (int j = 0; j < n; ++j) {
      dp[(i + 1) & 1][j] = s;
      for (auto l : g[j]) {
        dp[(i + 1) & 1][j] -= dp[i & 1][l];
        dp[(i + 1) & 1][j] += mod;
        dp[(i + 1) & 1][j] %= mod;
      }
    }
  }
  //cout << dp[k & 1][0] << "\n";

  return 0;
}