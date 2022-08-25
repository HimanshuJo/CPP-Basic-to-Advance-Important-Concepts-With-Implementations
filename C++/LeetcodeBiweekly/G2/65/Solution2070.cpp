// 2070. Most Beautiful Item for Each Query
/*
You are given a 2D integer array items where items[i] = [pricei, beautyi]
denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j],
you want to determine the maximum beauty of an item whose price is less than or
equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the
answer to the jth query.

Example 1:

Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
Output: [2,4,5,5,6,6]
Explanation:
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence,
  the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4].
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are
  [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.
Example 2:

Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
Output: [4]
Explanation:
The price of every item is equal to 1, so we choose the item with the maximum beauty 4.
Note that multiple items can have the same price and/or beauty.
Example 3:

Input: items = [[10,1000]], queries = [5]
Output: [0]
Explanation:
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.


Constraints:

1 <= items.length, queries.length <= 10^5
items[i].length == 2
1 <= pricei, beautyi, queries[j] <= 10^9
*/

/*
TLE: 34 / 35

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
*/

class Solution {
public:

	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		sort(items.begin(), items.end());
		int maxi = items[0][1];
		for (auto &xt : items)
		{
			maxi = max(maxi , xt[1]);
			xt[1] = maxi;
		}
		vector<int>ans;
		int n = items.size();

		for (int key : queries) {
			int left = 0;
			int right = n - 1;

			int count = 0;

			while (left <= right) {
				int mid = (right + left) / 2;
				if (items[mid][0] <= key) {
					count = mid + 1;
					left = mid + 1;
				}
				else
					right = mid - 1;
			}

			if (count == 0)
				ans.push_back(0);
			else
				ans.push_back(items[count - 1][1]);
		}
		return ans;
	}
};
