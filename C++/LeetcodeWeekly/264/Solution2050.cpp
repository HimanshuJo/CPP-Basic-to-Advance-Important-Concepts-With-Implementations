// 2050. Parallel Courses III
/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n. 
You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] 
denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). 

Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it 
takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course 
(i.e., the graph is a directed acyclic graph)

Input: n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
Output: 8
Explanation: The figure above represents the given graph and the time required to complete each course. 
We start course 1 and course 2 simultaneously at month 0.
Course 1 takes 3 months and course 2 takes 2 months to complete respectively.
Thus, the earliest time we can start course 3 is at month 3, and the total time required is 3 + 5 = 8 months.

Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
Output: 12
Explanation: The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.

Constraints:

1 <= n <= 5 * 10^4
0 <= relations.length <= min(n * (n - 1) / 2, 5 * 10^4)
relations[j].length == 2
1 <= prevCoursej, nextCoursej <= n
prevCoursej != nextCoursej
All the pairs [prevCoursej, nextCoursej] are unique.
time.length == n
1 <= time[i] <= 10^4
The given graph is a directed acyclic graph.
*/

class Solution {
public:

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        map<int, int>indeg;
        for(int i=1; i<=n; ++i){
            indeg[i]=0;
        }
        vector<vector<int>>gr_(n+1);
        map<int, int>times;
        for(auto &vals: relations){
            gr_[vals[0]].push_back(vals[1]);
            indeg[vals[1]]++;
        }
        for(int i=0; i<time.size(); ++i){
            times[i+1]=time[i];
        }
        vector<int>dist_(n+1);
        queue<int>q;
        for(auto &entry: indeg){
            if(entry.second==0){
                dist_[entry.first]=times[entry.first];
                q.push(entry.first);
            }
        }
        while(!q.empty()) {
            int u=q.front(); 
            q.pop();
            for(int v:gr_[u]) {
                // Update `dist[v]` using the maximum dist of the predecessor nodes
                dist_[v]=max(dist_[v], dist_[u]+times[v]);
                if (--indeg[v] == 0) 
                    q.push(v);
            }
        }
        return *max_element(dist_.begin(), dist_.end());
    }
};

// -------*******-------

class Solution2
{
public:
    int minimumTime(int n, vector<vector<int>>&rel, vector<int>&times)
    {
        vector<int>in(n+1);
        vector<vector<int>>out(n+1);
        for(const auto &r: rel)
        {
            in[r[1]]++;
            out[r[0]].push_back(r[1]);
        }
        using mp=pair<int, int>;
        priority_queue<mp, vector<mp>, greater<mp>> pq;
        for(int i=1; i<=n; i++)
            if(!in[i])
                pq.emplace(times[i-1], i);
        int res=0;
        while(!pq.empty())
        {
            auto[t, c]=pq.top();
            pq.pop();
            res=t;
            for(auto i: out[c])
            {
                in[i]--;
                if(!in[i])
                    pq.emplace(times[i-1]+t, i);
            }
        }
        return res;
    }
};