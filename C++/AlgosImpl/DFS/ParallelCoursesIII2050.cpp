// 2050. Parallel Courses III
/*
You are given an integer n, which indicates that there are n courses labeled from 1 to n.
You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that
course prevCoursej has to be completed before course nextCoursej (prerequisite relationship).
Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months
it takes to complete the (i+1)th course.

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
Course 4 can be taken only after course 3 is completed, i.e., after 3 months. It is completed after 3 + 4 = 7 months.
Course 5 can be taken only after courses 1, 2, 3, and 4 have been completed, i.e., after max(1,2,3,7) = 7 months.
Thus, the minimum time needed to complete all the courses is 7 + 5 = 12 months.
*/

class Solution {
public:

	int minimumTime(int n, vector<vector<int>>& mat, vector<int>& time) {
		// make a adj list such that edge points from the next node to prev node
		vector<int> adj[n + 1];
		for (auto it : mat)
		{
			int prev = it[0], next = it[1];
			adj[next].push_back(prev);
		}

		// Now, we know that for every node, its children are prerequisite
		// So the earlist we can start the doing current course is when
		// all its children(prerequisites) are finished

		// Here, dp[i] is the lowest time take to complete ith course

		vector<int> memo(n + 1, -1);
		for (int i = 1; i <= n; i++)
		{
			if (memo[i] == -1)
				memo[i] = dfs(i, adj, time, dp);
		}

		// among the least times taken to complete each course... take max
		return *max_element(memo.begin(), memo.end());
	}

	int dfs(int node, const vector<int> adj[], const vector<int>& time, vector<int>& memo)
	{
		if (memo[node] != -1) return memo[node];

		// we can only start a particular course when all the children (prerequisites)
		// are finish
		int timeToStart = 0;
		for (int child : adj[node])
		{
			timeToStart = max(timeToStart, dfs(child, adj, time, memo));
		}

		// time to complete the course = timeToStart + timeToComplete
		return memo[node] = (timeToStart + time[node - 1]);
	}
};