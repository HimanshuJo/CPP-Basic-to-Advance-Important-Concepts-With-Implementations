#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <math.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const int inf = 1000000000;
const ll llinf = 1000000000000000000;
const double eps = 1e-7;
const double pi = acos(-1.0);

struct query {
	int id, v, l, k;
};

vector<int> a;
vector<vector<int>> g;
vector<vector<query>> qs;
vector<int> cnt;
vector<set<int>> cnt_set;
vector<int> cnt_leq;
vector<int> ans;

void dfs(int u) {
	cnt_set[cnt[a[u] - 1]].erase(a[u] - 1);
	--cnt_leq[cnt[a[u] - 1]];
	++cnt[a[u] - 1];
	cnt_set[cnt[a[u] - 1]].insert(a[u] - 1);
	
	for (const query& q : qs[u]) {
		int nk = cnt_leq[q.l - 1] + q.k;
		auto it = lower_bound(cnt_leq.begin(), cnt_leq.end(), nk);
		ans[q.id] = (it == cnt_leq.end() ? -1 : *cnt_set[it - cnt_leq.begin()].begin() + 1);
	}
	
	for (int v : g[u])
		dfs(v);
	
	cnt_set[cnt[a[u] - 1]].erase(a[u] - 1);
	--cnt[a[u] - 1];
	++cnt_leq[cnt[a[u] - 1]];
	cnt_set[cnt[a[u] - 1]].insert(a[u] - 1);
}

void solve() {
	int n, q;
	cin >> n >> q;
	a.assign(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	g.assign(n, vector<int>());
	for (int v = 1; v < n; ++v) {
		int u;
		cin >> u;
		g[u - 1].push_back(v);
	}
	qs.assign(n, vector<query>());
	for (int i = 0; i < q; ++i) {
		int v, l, k;
		cin >> v >> l >> k;
		qs[v - 1].push_back({i, v - 1, l, k});
	}
	
	cnt.assign(n, 0);
	cnt_set.assign(n + 1, set<int>());
	cnt_leq.assign(n + 1, n);
	ans.assign(q, -1);
	dfs(0);
	
	for (int i = 0; i < q; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; ++i)
		solve();
	return 0;
}
