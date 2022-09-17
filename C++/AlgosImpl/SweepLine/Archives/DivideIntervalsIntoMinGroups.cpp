// 2406. Divide Intervals Into Minimum Number of Groups
/*
You are given a 2D integer array intervals where intervals[i] = [lefti, righti] 
represents the inclusive interval [lefti, righti].

You have to divide the intervals into one or more groups such that each interval is in exactly 
one group, and no two intervals that are in the same group intersect each other.

Return the minimum number of groups you need to make.

Two intervals intersect if there is at least one common number between them. For example, 
the intervals [1, 5] and [5, 8] intersect.

Example 1:

Input: intervals = [[5,10],[6,8],[1,5],[2,3],[1,10]]
Output: 3
Explanation: We can divide the intervals into the following groups:
- Group 1: [1, 5], [6, 8].
- Group 2: [2, 3], [5, 10].
- Group 3: [1, 10].
It can be proven that it is not possible to divide the intervals into fewer than 3 groups.
Example 2:

Input: intervals = [[1,3],[5,6],[8,10],[11,13]]
Output: 1
Explanation: None of the intervals overlap, so we can put all of them in one group.
 

Constraints:

1 <= intervals.length <= 10^5
intervals[i].length == 2
1 <= lefti <= righti <= 10^6
*/

/*
TLE: 27 / 35

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<vector<int>>combs;
        int sz=intervals.size();
        for(int i=0; i<sz; ++i){
            vector<int>temp;
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            temp.push_back(i);
            combs.push_back(temp);
        }
        sort(combs.begin(), combs.end());
        vector<int>seen(sz+1, -1);
        int res=0;
        for(auto &vals: combs){
            if(seen[vals[2]]==-1){
                vector<vector<int>>curcomb;
                seen[vals[2]]=1;
                vector<int>one=vals;
                curcomb.push_back(one);
                int curend=curcomb.back()[1];
                for(auto &vals_: combs){
                    if(seen[vals_[2]]==-1){
                        if(vals_[0]>curend){
                            vector<int>two=vals_;
                            curcomb.push_back(two);
                            curend=curcomb.back()[1];
                            seen[vals_[2]]=1;
                        }
                    }
                }
                res++;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<>>pq;
        for(auto &vals: intervals){
            if(!pq.empty()&&pq.top()<vals[0]){
                pq.pop();
            }
            pq.push(vals[1]);
        }
        return pq.size();
    }
};

// -------*******-------

class Solution2 {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<long long>ans(2e6+1, 0);
        for(auto &vals: intervals){
            int start=vals[0], end=vals[1];
            ans[start]+=1, ans[end+1]-=1;
        }
        long long maxEle=LONG_MIN;
        for(int i=1; i<=1e6; ++i){
            long long curans=ans[i]+ans[i-1];
            ans[i]=curans;
            maxEle=max(maxEle, curans);
        }
        return maxEle;
    }
};