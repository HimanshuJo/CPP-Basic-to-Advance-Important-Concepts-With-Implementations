#include <bits/stdc++.h>

using namespace std;

#define N 200100
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)

int x, y;
void dfs(int k, vector<vector<int>>&gr, set<int>&seen) {
	seen.insert(k);
	x++;
	y += gr[k].size();
	rep(i, gr[k].size()){
		auto it=seen.find(gr[k][i]);
		if (it==seen.end())
			dfs(gr[k][i], gr, seen);
	}
	return;
}

int main(void) {
	int n, m;
	ll ans = 1;
	cin >> n >> m;
	vector<vector<int>>gr(n+1);
	rep(i, m) {
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	set<int>seen;
	rep(i, n) {
		auto it=seen.find(i+1);
		if (it==seen.end()) {
			x = 0;
			y = 0;
			dfs(i+1, gr, seen);
			if (y == (x * 2))ans = (ans * 2) % MOD;
			else ans = 0;
		}
	}
	cout << ans << endl;
	return 0;
}

