// 2065. Maximum Path Quality of a Graph
/*
There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). 
You are given a 0-indexed integer array values where values[i] is the value of the ith node.

You are also given a 0-indexed 2D integer array edges, where each 
edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the 
nodes uj and vj, and it takes timej seconds to travel between the two nodes. 

Finally, you are given an integer maxTime

A valid path in the graph is any path that starts at node 0, 
ends at node 0, and takes at most maxTime seconds to complete. 

You may visit the same node multiple times. 

The quality of a valid path is the sum of the values of the unique nodes 
visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
Output: 75
Explanation:
One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.

Input: values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
Output: 25
Explanation:
One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 20 <= 30.
The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.

Input: values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
Output: 7
Explanation:
One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken is 10 + 13 + 13 + 10 = 46 <= 50.
The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.

Constraints:

n == values.length
1 <= n <= 1000
0 <= values[i] <= 10^8
0 <= edges.length <= 2000
edges[j].length == 3
0 <= uj < vj <= n - 1
10 <= timej, maxTime <= 100
All the pairs [uj, vj] are unique.
There are at most four edges connected to each node.
The graph may not be connected.
*/

/*
Solution DFS:

We will do DFS in this problem. 
We have the condition here that we can visit a node any number of times but 
we shall add its value only once for that path for the calculation of its quality.

So, we would require a visited array which would keep track of the visited nodes 
so that we do not add its value again into the quality score.

Here, we are doing DFS and we increase the count of that node in visited array 
indicating how many times we have visited that node. 

If its being visited for the first time, we add its value to our sum. 
After we have processed all its neighbours, we then mark the current node as 
unvisited i.e. we reduce the count of that node from the visited array.

We do not use a boolean visited array since if we go that way we 
would not be able to track visited properly since if we turn visited 
back to false after processing its neighbours, it would mean we treat that node as 
non visited even if its been visited multiple times before. 

To account for that, we use counter based visited array which increases or 
decreases the visited count thus serving its purpose.
*/

class Solution {
	public:
		int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
			vector<pair<int, int>>grT(values.size());
			vector<pair<int, int>>grD(values.size());
			for(int i=0; i<edges.size(); ++i){
				grT[edges[0]].push_back({edges[1], edges[2]});
				grT[edges[1]].push_back({edges[0], edges[2]});
				grD[edges[0]].push_back({edges[1], values[edges[1]]});
				grD[edges[1]].push_back({edges[0], values[edges[0]]});
			}
			bool visited[values.size()];
			memset(visited, false, sizeof(visited));
			priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
			pq.push({values[0], 0});
			visited[0]=true;
			int currTime=0;
			int ans=0;
			while(!pq.empty()){
				auto [d, v]=pq.top();
				pq.pop();
				if(d<values[v]) continue;
				for(auto [nei, neiVal]: grD[v]){
					if(visited[nei]==false){
						if(d+neiVal>values[nei]){
							int currTime_=grT[nei][1];
							currTime_*=2;
							if(currTime+currTime_<=maxTime){
								currTime+=currTime_;
								ans+=d+neiVal;
								pq.push({d+neiVal, nei});
								visited[nei]=true;
							}
						}
					}
				}
			}
			return ans;
		}
};

// -------*******-------

class Solution2 {
public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        int res = values[0];
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> visited(n, 0);
        dfs(graph, values, visited, res, 0, 0, 0, maxTime);
        return res;
    }
    
    void dfs(vector<vector<pair<int,int>>>& graph, vector<int>& values, vector<int>& visited, int& res, int node, int score, int time, int& maxTime)
    {
        if(time > maxTime)
            return;
        if(visited[node] == 0)
            score += values[node];
        visited[node]++;
        if(node == 0)
            res = max(res, score);
        for(auto it : graph[node])
        {
            int neigh = it.first;
            int newTime = time + it.second;
            dfs(graph, values, visited, res, neigh, score, newTime, maxTime);
        }
        visited[node]--;
    }
};