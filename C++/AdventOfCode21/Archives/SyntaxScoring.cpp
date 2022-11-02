#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 98;
	ll smBrcC = 0, capBrcC = 0, curlBrcC = 0, angBrcC = 0;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		stack<char>stk;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '{' || s[i] == '(' || s[i] == '[' || s[i] == '<') {
				stk.push(s[i]);
			}
			else if ((s[i] == ')' && stk.top() == '{') || (s[i] == ')' && stk.top() == '[') || (s[i] == ')' && stk.top() == '<')) {
				smBrcC++;
				break;
			} else if ((s[i] == '}' && stk.top() == '(') || (s[i] == '}' && stk.top() == '[') || (s[i] == '}' && stk.top() == '<')) {
				curlBrcC++;
				break;
			} else if ((s[i] == ']' && stk.top() == '(') || (s[i] == ']' && stk.top() == '{') || (s[i] == ']' && stk.top() == '<')) {
				capBrcC++;
				break;
			} else if ((s[i] == '>' && stk.top() == '(') || (s[i] == '>' && stk.top() == '{') || (s[i] == '>' && stk.top() == '[')) {
				angBrcC++;
				break;
			}
			else {
				if (!stk.empty()) {
					stk.pop();
				}
			}
		}
	}
	ll ans = 0;
	ans += (smBrcC != 0 ? smBrcC * 3 : 0) + (capBrcC != 0 ? capBrcC * 57 : 0) + (curlBrcC != 0 ? curlBrcC * 1197 : 0) + (angBrcC != 0 ? angBrcC * 25137 : 0);
	cout << "-------\n";
	cout << ans;
}
