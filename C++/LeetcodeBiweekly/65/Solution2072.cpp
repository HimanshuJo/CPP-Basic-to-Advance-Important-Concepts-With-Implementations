#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

	int check(vector<int>&tasks, int mid, vector<int>&workers, int pills, int strength) {
		multiset<int>st(workers.begin(), workers.end());
		while (mid >= 1 && st.size()) {
            multiset<int>::iterator it;
            it=st.end(); it--;
			if (tasks[mid-1] <= *st.rbegin()) {}
			else if (pills) {
				it = st.lower_bound(tasks[mid - 1] - strength);
				if (it == st.end()) return 0;
				--pills;
			}
			else return 0;
			st.erase(it);
			--mid;
		}
		return mid == 0;
	}

	int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
		sort(tasks.begin(), tasks.end());
		int left = 0, right = tasks.size(), ans = 0;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			int chk = check(tasks, mid, workers, pills, strength);
			if (chk) {
				ans = mid;
				left = mid + 1;
			} else {
				right = mid - 1;
			}
            //cout<<mid<<endl;
		}
		return ans;
	}
};;

int main() {}