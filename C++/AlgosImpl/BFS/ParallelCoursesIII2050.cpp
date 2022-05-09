// 2050. Parallel Courses III
/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n.
You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that
course prevCoursej has to be completed before course nextCoursej (prerequisite relationship).
Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many 
months it takes to complete the (i+1)th course.

You must find the minimum number of months needed to complete all the courses following these rules:

You may start taking a course at any time if the prerequisites are met.
Any number of courses can be taken at the same time.
Return the minimum number of months needed to complete all the courses.

Note: The test cases are generated such that it is possible to complete every course 
(i.e., the graph is a directed acyclic graph).

Input: n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
Output: 12
Explanation: The figure above represents the given graph and the time required to complete each course.
You can start courses 1, 2, and 3 at month 0.
You can complete them after 1, 2, and 3 months respectively.
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. 
It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, 
i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.
*/

class Solution {
public:
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
		vector<int> inDegree(n);
		vector<vector<int>> graph(n, vector<int>());
		for (auto& edge : relations) {
			int prev = edge[0] - 1, next = edge[1] - 1;
			graph[prev].push_back(next);
			inDegree[next]++;
		}

		vector<int> dist(n);
		queue<int> q;
		for (int u = 0; u < n; ++u) {
			if (inDegree[u] == 0) {
				q.push(u);
				dist[u] = time[u];
			}
		}
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : graph[u]) {
				// Update `dist[v]` using the maximum dist of the predecessor nodes
				dist[v] = max(dist[v], dist[u] + time[v]);
				if (--inDegree[v] == 0)
					q.push(v);
			}
		}
		return *max_element(dist.begin(), dist.end());
	}
};