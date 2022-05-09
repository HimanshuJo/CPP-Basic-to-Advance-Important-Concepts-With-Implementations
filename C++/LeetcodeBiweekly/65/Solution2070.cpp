#include<bits/stdc++.h>
using namespace std;

struct custComp {
	bool operator()(vector<int>A, vector<int>B) {
		return (A[0] == B[0] ? A[1] > B[1] : A[0] < B[0]);
	}
};

class Solution {
public:
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		sort(items.begin(), items.end(), custComp());
		vector<int>ans(queries.size());
		vector<pair<int, int>>queyNdInd;
		for (int i = 0; i < queries.size(); ++i) {
			queyNdInd.push_back({queries[i], i});
		}
		sort(queyNdInd.begin(), queyNdInd.end());
		int cnt = 0, maxx = 0;
		for (auto &vals : queyNdInd) {
			int q = vals.first;
			int ind = vals.second;
			while (cnt < items.size() && items[cnt][0] <= q) {
				maxx = max(items[cnt][1], maxx);
				cnt++;
			}
			ans[ind] = maxx;
		}
		return ans;
	}
};