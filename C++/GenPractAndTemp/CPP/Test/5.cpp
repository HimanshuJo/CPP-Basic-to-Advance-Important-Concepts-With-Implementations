#include <bits/stdc++.h>
 
using namespace std;
 
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<long long> s(n + 1);
	for (int i = n - k + 1; i <= n; ++i)
		cin >> s[i];
	if (k == 1)
	{
		cout << "YES" << endl;
		return;
	}
	vector<long long> a(n + 1);
	for (int i = n - k + 2; i <= n; ++i)
		a[i] = s[i] - s[i - 1];
	if (!std::is_sorted(a.begin() + n - k + 2, a.end()))
	{
		cout << "NO" << endl;
		return;
	}
	for(auto &vals: s){
		cout<<vals<<" ";
	}
	cout<<endl;
	for(auto &vals: a){
		cout<<vals<<" ";
	}
	cout<<endl;
	cout<<n-k+2<<" "<<a[n-k+2]<<" "<<n-k+1<<" "<<s[n-k+1]<<endl;
	if (s[n - k + 1] > a[n - k + 2] * (n - k + 1))
	{
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}
 
int main()
{
	int tests;
	cin >> tests;
	while (tests--) solve();
	return 0;
}