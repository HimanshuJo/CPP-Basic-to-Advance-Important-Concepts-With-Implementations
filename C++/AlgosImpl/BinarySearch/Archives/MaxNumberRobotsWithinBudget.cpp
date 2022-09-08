// 2398. Maximum Number of Robots Within Budget
/*
You have n robots. You are given two 0-indexed integer arrays, chargeTimes and runningCosts, 
both of length n. The ith robot costs chargeTimes[i] units to charge and costs runningCosts[i] 
units to run. You are also given an integer budget.

The total cost of running k chosen robots is equal to max(chargeTimes) + k * sum(runningCosts),
where max(chargeTimes) is the largest charge cost among the k robots and sum(runningCosts) is the 
sum of running costs among the k robots.

Return the maximum number of consecutive robots you can run such that the total cost does not exceed budget.

Example 1:

Input: chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
Output: 3
Explanation: 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 
6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
Example 2:

Input: chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
Output: 0
Explanation: No robot can be run that does not exceed the budget, so we return 0.
 

Constraints:

chargeTimes.length == runningCosts.length == n
1 <= n <= 5 * 104
1 <= chargeTimes[i], runningCosts[i] <= 10^5
1 <= budget <= 10^15
*/


class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int sz=chargeTimes.size();
        vector<long long>prefSum={0};
        for(int i=0; i<sz; ++i){
            prefSum.push_back(prefSum.back()+runningCosts[i]);
        }
        int ans=0, i=0, j=0;
        deque<int>dq;
        while(j<sz){
            while(!dq.empty()&&dq.back()<chargeTimes[j]){
                dq.pop_back();
            }
            dq.push_back(chargeTimes[j]);
            int cursz=j-i+1;
            long long currsm=dq.front()+cursz*(prefSum[j+1]-prefSum[i]);
            if(currsm<=budget){
                ans=max(ans, j-i+1);
            } else{
                if(dq.front()==chargeTimes[i++]){
                    dq.pop_front();
                }
            }
            j++;
        }
        return ans;
    }
};

// -------*******-------

class Solution2{
public:
    
    int maximumRobots(vector<int>& times, vector<int>& costs, long long budget) {
        long long i = 0, j, sum = 0, n = times.size();
        multiset<int> s;
        for (int j = 0; j < n; ++j) {
            sum += costs[j];
            s.insert(times[j]);
            if (*rbegin(s) + sum * (j - i + 1) > budget) {
                sum -= costs[i];
                s.erase(s.find(times[i++]));
            }
        }
        return n - i;
    }
};

// -------*******-------

class Solution3 {
    /******************** Segment Tree to find maximum in a range ********************/
    vector<int> arr;
    vector<int> tree;

    void build(int start, int end, int idx) {
        if(start == end) {
            tree[idx] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(start, mid, 2 * idx);
            build(mid + 1, end, 2 * idx + 1);
            tree[idx] = max(tree[2 * idx], tree[2 * idx + 1]);
        }
    }
    
    int query(int start, int end, int left, int right, int idx) {
        if(start > right || end < left) {
            return INT_MIN;
        }
        if(start >= left && end <= right) {
            return tree[idx];
        }
        int mid = (start + end) / 2;
        return max(query(start, mid, left, right, 2 * idx), query(mid + 1, end, left, right, 2 * idx + 1));
    }
    
    /******************** Checking if subarray of size K exists in the given budget ********************/
    bool check(vector<long long>& prefix, int k, int n, long long budget) {
        for(int i = 0; i + k <= n; i++) {
            int end = i + k;
            
            long long total = prefix[end];
            total -= prefix[i];
            total *= k;
            total += query(0, n - 1, i, end - 1, 1);
            
            if(total <= budget)
                return true;
        }
        return false;
    }
    
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        
        /******************** Building the Segment Tree ********************/
        arr = chargeTimes;
        tree = vector<int>(4 * n);
        build(0, n - 1, 1);
        
        /******************** Forming Prefix array for finding sum(runningCost) in range ********************/
        vector<long long> prefix(n + 1);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + runningCosts[i - 1];
        }
        
        /******************** Binary Search the Maximum Size ********************/
        int l = 1, r = n;
        int ans = 0;
        while(l <= r) { 
            int mid = (l + r) / 2;
            
            if(check(prefix, mid, n, budget)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    } 
};