#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = (int)1e9 + 7;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ++ii)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		if ((n & 1) != 0 || s[0] == '0' || s[n - 1] == '0')
		{
			cout << "NO"
				 << "\n";
			continue;
		}
		int l = 0, h = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '1')
			{
				++l;
			}
			else
			{
				++h;
			}
		}
		if (l % 2 == 1 || h % 2 == 1)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		string a = "", b = "";
		int l1 = 1, h1 = 0;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == '1')
			{
				if (l1 <= l / 2)
				{
					a += '(';
					b += '(';
				}
				else
				{
					a += ')';
					b += ')';
				}
				++l1;
			}
			else
			{
				if (h1 == 0)
				{
					a += '(';
					b += ')';
				}
				else
				{
					a += ')';
					b += '(';
				}
				h1 ^= 1;
			}
		}
		cout << a << "\n";
		cout << b << "\n";
	}
}