#include <bits/stdc++.h>
using namespace std;

#define N 200010
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(void) {
	int n;
	int a, b;
	vector<pair<int, int> >x;
	int cnt;
	int ans[N];
	rep(i, N)ans[i] = 0;

	cin >> n;
	rep(i, n) {
		cin >> a >> b;
		x.push_back({ a,1 });
		x.push_back({ a + b,-1 });
	}

	sort(x.begin(), x.end());

	cnt = 0;
	rep(i, (x.size())-1) {
		cnt += x[i].second;
		ans[cnt] += ((x[i + 1].first) - (x[i].first));
	}

	rep(i, n - 1)cout << ans[i + 1] << " ";
	cout << ans[n] << endl;

	return 0;
}
