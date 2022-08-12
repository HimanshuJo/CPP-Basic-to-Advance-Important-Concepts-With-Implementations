// 1928. Minimum Cost to Reach Destination in Time
/*
There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by bi-directional roads. 
The roads are represented as a 2D integer array edges where edges[i] = [xi, yi, timei] denotes a road between 
cities xi and yi that takes timei minutes to travel. There may be multiple roads of differing travel times 
connecting the same two cities, but no road connects a city to itself.

Each time you pass through a city, you must pay a passing fee. This is represented as a 0-indexed integer 
array passingFees of length n where passingFees[j] is the amount of dollars you must pay when you pass through city j.

In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less. 
The cost of your journey is the summation of passing fees for each city that you passed through at some 
moment of your journey (including the source and destination cities).

Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if you 
cannot complete it within maxTime minutes.

Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 11
Explanation: The path to take is 0 -> 1 -> 2 -> 5, which takes 30 minutes and has $11 worth of passing fees.

Input: maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 48
Explanation: The path to take is 0 -> 3 -> 4 -> 5, which takes 26 minutes and has $48 worth of passing fees.
You cannot take path 0 -> 1 -> 2 -> 5 since it would take too long.

Input: maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: -1
Explanation: There is no way to reach city 5 from city 0 within 25 minutes.

Constraints:

1 <= maxTime <= 1000
n == passingFees.length
2 <= n <= 1000
n - 1 <= edges.length <= 1000
0 <= xi, yi <= n - 1
1 <= timei <= 1000
1 <= passingFees[j] <= 1000 
The graph may contain multiple edges between two nodes.
The graph does not contain self loops.
*/

class Solution {
public:
    
    void dijkstras(int maxTime, vector<int>&passingFees, vector<vector<pair<int, int>>>&gr, vector<int>&cost, vector<int>&time,
                   int src, int dest){
        priority_queue<vector<int>, vector<vector<int>>, greater<>>pq;
        cost[src]=passingFees[0], time[src]=0;
        pq.push({cost[src], time[src], src});
        while(!pq.empty()){
            int sz=pq.size();
            while(sz--){
                vector<int>curr=pq.top();
                pq.pop();
                int curCost=curr[0], curTime=curr[1], curVert=curr[2];
                for(auto &nei: gr[curVert]){
                    if(curTime+nei.second<=maxTime){
                        if(curCost+passingFees[nei.first]<cost[nei.first]){
                            cost[nei.first]=curCost+passingFees[nei.first];
                            time[nei.first]=curTime+nei.second;
                            pq.push({cost[nei.first], time[nei.first], nei.first});
                        } else{
                            if(curTime+nei.second<time[nei.first]){
                                time[nei.first]=curTime+nei.second;
                                pq.push({curCost+passingFees[nei.first], time[nei.first], nei.first});
                            }
                        }
                    }
                }
            }
        }
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        vector<vector<pair<int, int>>>gr(1001);
        vector<int>cost(1001, INT_MAX);
        vector<int>time(1001, INT_MAX);
        int src=0, dest=passingFees.size()-1;
        for(auto &vals: edges){
            gr[vals[0]].push_back({vals[1], vals[2]});
            gr[vals[1]].push_back({vals[0], vals[2]});
        }
        dijkstras(maxTime, passingFees, gr, cost, time, src, dest);
        return cost[dest]==INT_MAX?-1:cost[dest];
    }
};

// -------*******-------

class Solution2 {
public:
    
    long long dfs(int maxTime, vector<vector<pair<int, int>>>&gr, vector<int>&passingFees, int src, int dest, int curTime, vector<int>&seen, vector<vector<long long>>&memo){
        if(src==dest){
            return passingFees[src];
        }
        if(memo[src][curTime]!=-1) return memo[src][curTime];
        long long ans=INT_MAX;
        for(auto &nei: gr[src]){
            if(seen[nei.first]==-1){
                if(curTime+nei.second<=maxTime){
                    long long curans=dfs(maxTime, gr, passingFees, nei.first, dest, curTime+nei.second, seen, memo);
                    ans=min(ans, curans+passingFees[src]);
                }
            }
        }
        return memo[src][curTime]=ans;
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int sz=passingFees.size();
        vector<vector<pair<int, int>>>gr(sz+1);
        vector<vector<long long>>memo(sz+1, vector<long long>(maxTime+1, -1));
        for(auto &vals: edges){
            gr[vals[0]].push_back({vals[1], vals[2]});
            gr[vals[1]].push_back({vals[0], vals[2]});
        }
        int src=0, dest=passingFees.size()-1, curTime=0, curFees=0;
        vector<int>seen(sz+1, -1);
        int ans=dfs(maxTime, gr, passingFees, src, dest, curTime, seen, memo);
        return ans>=INT_MAX?-1:ans;
    }
};