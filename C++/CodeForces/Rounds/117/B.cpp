// B. Special Permutation
/*
A permutation of length n is an array p=[p1,p2,…,pn] which contains every integer from 1 to n
(inclusive) exactly once. For example, p=[4,2,6,5,3,1] is a permutation of length 6.

You are given three integers n, a and b, where n is an even number. Print any permutation of length n that
the minimum among all its elements of the left half equals a and the maximum among all its elements of the right half equals b.
Print -1 if no such permutation exists.

Input
The first line of the input contains one integer t (1≤t≤1000), the number of test cases in the test.
The following t lines contain test case descriptions.

Each test case description contains three integers n, a, b (2≤n≤100; 1≤a,b≤n; a≠b), where n is an even number (i.e. nmod2=0).

Output
For each test case, print a single line containing any suitable permutation. Print -1 no such permutation exists.
If there are multiple answers, print any of them.

Example
input
7
6 2 5
6 1 3
6 4 3
4 2 4
10 5 3
2 1 2
2 2 1

output
4 2 6 5 3 1
-1
6 4 5 1 3 2
3 2 4 1
-1
1 2
2 1
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		vector<int>res(n);
		res[0] = a;
		int temp = n;
		set<int>seen;
		seen.insert(a);
		for (int i = 1; i < n / 2; ++i) {
			auto it = seen.find(temp);
			if (it == seen.end() && temp != b) {
				seen.insert(temp);
				res[i] = temp--;
			}
			else {
				while (true) {
					temp--;
					auto it_ = seen.find(temp);
					if (it_ == seen.end()) break;
				}
				res[i] = temp;
				seen.insert(temp);
			}
		}
		res[n - 1] = b;
		seen.insert(b);
		for (int i = n / 2; i < n - 1; ++i) {
			auto it = seen.find(temp);
			if (it == seen.end()) {
				seen.insert(temp);
				res[i] = temp--;
			} else {
				while (true) {
					temp--;
					auto it_ = seen.find(temp);
					if (it_ == seen.end()) break;
				}
				res[i] = temp;
				seen.insert(temp);
			}
		}
		bool flag = false;
		for (int i = 0; i < n / 2; ++i) {
			if (res[i] < a) {
				flag = true;
				break;
			}
		}
		for (int i = n / 2; i < n; ++i) {
			if (res[i] > b) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "-1\n";
		} else {
			for (auto &vals : res) {
				cout << vals << " ";
			}
			cout << "\n";
		}
	}
}
