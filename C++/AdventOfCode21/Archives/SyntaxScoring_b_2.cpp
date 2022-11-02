#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll>res;
	ll ans = 0;
	ifstream infile("./Test/10_inp.txt");
	string line;
	while (getline(infile, line))
	{
		istringstream iss(line);
		string s;
		if (!(iss >> s)) { break; }
		cout << s << endl;
		stack<char>stk;
		bool flag = false;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '{' || s[i] == '(' || s[i] == '[' || s[i] == '<') {
				stk.push(s[i]);
			}
			else if ((s[i] == ')' && stk.top() == '{') || (s[i] == ')' && stk.top() == '[') || (s[i] == ')' && stk.top() == '<')) {
				flag = true;
				break;
			} else if ((s[i] == '}' && stk.top() == '(') || (s[i] == '}' && stk.top() == '[') || (s[i] == '}' && stk.top() == '<')) {
				flag = true;
				break;
			} else if ((s[i] == ']' && stk.top() == '(') || (s[i] == ']' && stk.top() == '{') || (s[i] == ']' && stk.top() == '<')) {
				flag = true;
				break;
			} else if ((s[i] == '>' && stk.top() == '(') || (s[i] == '>' && stk.top() == '{') || (s[i] == '>' && stk.top() == '[')) {
				flag = true;
				break;
			}
			else {
				if (!stk.empty()) {
					stk.pop();
				}
			}
		}
		if (!flag) {
			vector<char>temp_;
			while (!stk.empty()) {
				temp_.push_back(stk.top());
				stk.pop();
			}
			ll currScore = 0;
			for (auto &vals : temp_) {
				currScore *= 5;
				currScore += (vals == '[' ? 2 : vals == '(' ? 1 : vals == '{' ? 3 : vals == '<' ? 4 : 0);
			}
			res.push_back(currScore);
		}
	}
	sort(res.begin(), res.end());
	int n_ = res.size();
	ans = res[n_ / 2];
	for (auto &vals : res)
		cout << vals << " ";
	cout << endl;
	cout << "-------\n";
	cout << ans;
}
