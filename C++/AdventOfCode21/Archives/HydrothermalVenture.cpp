#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;
using ll = long long;

int drwHorizontalLine(vector<vector<int>>&grd, int y1, int x1, int x2) {
	int intersections = 0;
	int bgn = min(x1, x2);
	int end = max(x1, x2);
	for (int i = bgn; i <= end; ++i) {
		grd[i][y1] += 1;
		if (grd[i][y1] == 2) {
			intersections += 1;
		}
	}
	return intersections;
}

int drwVerticalLine(vector<vector<int>>&grd, int x1, int y1, int y2) {
	int intersections = 0;
	int bgn = min(y1, y2);
	int end = max(y1, y2);
	for (int i = bgn; i <= end; ++i) {
		grd[x1][i] += 1;
		if (grd[x1][i] == 2) {
			intersections += 1;
		}
	}
	return intersections;
}

int drwDiagonalLine(vector<vector<int>>&grd, int x1, int y1, int x2, int y2) {
	int intersections = 0;
	int end = abs(x2 - x1);
	for (int i = 0; i <= end; ++i) {
		grd[x1][y1] += 1;
		if (grd[x1][y1] == 2) {
			intersections += 1;
		}
		x1 = x2 > x1 ? x1 + 1 : x1 - 1;
		y1 = y2 > y1 ? y1 + 1 : y1 - 1;
	}
	return intersections;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 500;
	vector<vector<int>>segs(n);
	int maxx = INT_MIN;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		segs[i] = {x1, y1, x2, y2};
		if (x1 > maxx) maxx = x1;
		if (y1 > maxx) maxx = y1;
		if (x2 > maxx) maxx = x2;
		if (y2 > maxx) maxx = y2;
	}
	cout << "maxx " << maxx << endl;
	int ans = 0;
	vector<vector<int>>grd(maxx + 1, vector<int>(maxx + 1, 0));
	for (auto &vals : segs) {
		vector<int>curr = vals;
		if (curr[0] == curr[2]) {
			ans += drwVerticalLine(grd, curr[0], curr[1], curr[3]);
		} else if (curr[1] == curr[3]) {
			ans += drwHorizontalLine(grd, curr[1], curr[0], curr[2]);
		} else {
			ans += drwDiagonalLine(grd, curr[0], curr[1], curr[2], curr[3]);
		}
	}
	cout << "-------\n";
	cout << ans << endl;
}
