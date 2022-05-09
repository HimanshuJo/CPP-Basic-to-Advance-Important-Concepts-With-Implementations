// 2073. Time Needed to Buy Tickets
/*
There are n people in a line queuing to buy tickets, 
where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n 
where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. 

A person can only buy 1 ticket at a time and has to go back to the end of the line 
(which happens instantaneously) in order to buy more tickets. 

If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person at position k (0-indexed) to finish buying tickets.

Example 1:

Input: tickets = [2,3,2], k = 2
Output: 6
Explanation: 
- In the first pass, everyone in the line buys a ticket and the line becomes [1, 2, 1].
- In the second pass, everyone in the line buys a ticket and the line becomes [0, 1, 0].
The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6 seconds.
Example 2:

Input: tickets = [5,1,1,1], k = 0
Output: 8
Explanation:
- In the first pass, everyone in the line buys a ticket and the line becomes [4, 0, 0, 0].
- In the next 4 passes, only the person in position 0 is buying tickets.
The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1 + 1 + 1 = 8 seconds.
 

Constraints:

n == tickets.length
1 <= n <= 100
1 <= tickets[i] <= 100
0 <= k < n
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy1(vector<int>& tickets, int k) {
        int ans = 0;
        bool flag = false;
        while (tickets[k] != 0) {
            for (int i = 0; i < tickets.size(); ++i) {
                if (tickets[k] == 0) break;
                else {
                    if (tickets[i] > 0) {
                        tickets[i] -= 1;
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
        return ans;
    }

    int timeRequiredToBuy2(vector<int>& t, int k) {
        int res = 0, sz = t.size(), cap = t[k];
        for (int i = 0; i < sz; ++i)
            res += min(cap - (i > k), t[i]);
        cout << res << endl;
        return res;
    }

    int timeRequiredToBuy3(vector<int>&vec, int k) {
        int ans = 0, n = vec.size();
        for (int i = 0; i < n; ++i) {
            ans += (i <= k ? min(vec[i], vec[k]) : min(vec[i], vec[k] - 1));
        }
        cout << ans << endl;
        return ans;
    }

};

int main() {
    Solution obj;
    int k = 0;
    vector<int>tickets{1000000000, 2, 12, 13, 23};
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    ios_base::sync_with_stdio(false);
    obj.timeRequiredToBuy(tickets, k);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(9);
    cout << " sec" << endl;
    struct timespec start2, end2;
    clock_gettime(CLOCK_MONOTONIC, &start2);
    ios_base::sync_with_stdio(false);
    obj.timeRequiredToBuy3(tickets, k);
    clock_gettime(CLOCK_MONOTONIC, &end2);
    double time_taken_;
    time_taken_ = (end2.tv_sec - start2.tv_sec) * 1e9;
    time_taken_ = (time_taken_ + (end2.tv_nsec - start2.tv_nsec)) * 1e-9;
    cout << "Time taken by program is : " << fixed
         << time_taken_ << setprecision(9);
    cout << " sec" << endl;
    return 0;
}