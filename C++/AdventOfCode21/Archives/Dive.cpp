#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
using ll = long long;

vector<string> splitString(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string tok;
	while (getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
	return internal;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll forward = 0, down = 0, aim = 0;
	int n = 1000;
	vector<pair<string, ll>>in(n);
	for (int i = 0; i < n; ++i) {
		string dir;
		cin >> dir;
		ll val;
		cin >> val;
		in[i] = {dir, val};
	}
	for (auto &vals : in) {
		string curr = vals.first;
		ll dir = vals.second;
		if (curr[0] == 'f') {
			forward += dir;
			down += (aim * dir);
		} else if (curr[0] == 'd') {
			aim += dir;
		} else if (curr[0] == 'u') {
			aim -= dir;
		}
	}
	ll ans = forward * down;
	cout << "-------\n";
	cout << ans << endl;
}
