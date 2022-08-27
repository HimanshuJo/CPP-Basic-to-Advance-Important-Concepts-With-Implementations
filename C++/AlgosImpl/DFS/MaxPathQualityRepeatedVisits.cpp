// Maximum Path Quality of a Graph
/*
There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). 
You are given a 0-indexed integer array values where values[i] is the value of the ith node. 
You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] 
indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to 
travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, 
and takes at most maxTime seconds to complete. 
You may visit the same node multiple times. The quality of a valid path is the sum of 
the values of the unique 
nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
Explanation:
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	int maximalPathQuality(vector<int>&values, vector<vector<int>>&edges, int maxTime){
		int n=values.size();
		int res=values[0];
		vector<vector<pair<int, int>>>gr(n);
		for(int i=0; i<edges.size(); ++i){
			gr[edges[i][0]].push_back({edges[i][1], edges[i][2]});
			gr[edges[i][1]].push_back({edges[i][0], edges[i][2]});
		}
		vector<int>visited(n, 0);
		dfs(gr, values, visited, res, 0, 0, 0, maxTime);
		return res;
	}

	void dfs(vector<vector<pair<int, int>>>&gr, vector<int>&values, vector<int>&visited, 
		int &res, int node, int score, int time, int maxTime){
		if(time>maxTime) return;
		if(visited[node]==0) score+=values[node];
		visited[node]++;
		if(node==0) res=max(res, score);
		for(auto &it: gr[node]){
			int nei=it.first;
			int newTime=time+it.second;
			dfs(gr, values, visited, res, nei, score, newTime, maxTime);
		}
		visited[node]--;
	}
};