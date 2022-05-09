//  Minimum Cost to Reach Destination in Time

/*
 * There is a country of n cities numbered from 0 to n - 1 where all the cities are connected by
 * bi-directional roads. The roads are represented as a 2D integer array edges where
 * edges[i] = [xi, yi, timei] denotes a road between cities xi and yi that takes timei minutes to travel.
 * There may be multiple roads of differing travel times connecting the same two cities,
 * but no road connects a city to itself.

	Each time you pass through a city, you must pay a passing fee. This is represented as a
	0-indexed integer array passingFees of length n where passingFees[j] is the amount of
	dollars you must pay when you pass through city j.

	In the beginning, you are at city 0 and want to reach city n - 1 in maxTime minutes or less.
	The cost of your journey is the summation of passing fees for each city that you passed through at
	some moment of your journey (including the source and destination cities).

	Given maxTime, edges, and passingFees, return the minimum cost to complete your journey, or -1 if
	you cannot complete it within maxTime minutes.
 */

// Modified Dijkstra

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int dp[1002][1002];
    int go(int sum, vector<int> &cost, int src = 0)
    {
        if (sum < 0)
            return INT_MAX - 1000;
        if (src == cost.size() - 1)
            return sum >= 0 ? 0 : INT_MAX - 1000;
        if (dp[sum][src] != -1)
        {
            cout << dp[sum][src] << "\n";
            return dp[sum][src];
        }
        int res = INT_MAX - 1000;
        for (auto i : adj[src])
        {
            res = min(res, cost[src] + go(sum - i.second, cost, i.first));
        }
        cout << dp[sum][src] << "\n";
        return dp[sum][src] = res;
    }
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        adj.clear();
        for (auto i : edges)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        int ans = go(maxTime, cost);
        if (ans == 2147482647)
            return -1;
        return cost[cost.size() - 1] + ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> edges;
    vector<int> temp;
    temp.push_back(0);
    temp.push_back(1);
    temp.push_back(100);
    edges.push_back(temp);
    vector<int> passingFees;
    passingFees.push_back(2);
    passingFees.push_back(5);
    obj.minCost(100, edges, passingFees);
    return 0;
}