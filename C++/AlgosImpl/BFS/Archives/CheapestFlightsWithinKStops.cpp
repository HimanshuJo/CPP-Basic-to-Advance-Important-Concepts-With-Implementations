// 787. Cheapest Flights Within K Stops
/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates 
that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from 
src to dst with at most k stops. If there is no such route, return -1.

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 10^4
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>gr(n+1);
        for(auto &vals: flights){
            gr[vals[0]].push_back(make_pair(vals[1], vals[2]));
        }
        vector<int>prices(n+1, INT_MAX);
        prices[src]=0;
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {src, prices[src]}});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int, pair<int, int>>curr=q.front();
                q.pop();
                int currStops=curr.first, currNode=curr.second.first, currPrice=curr.second.second;
                if(currStops>k) continue;
                for(auto &nei: gr[currNode]){
                    if(currPrice+nei.second<prices[nei.first]){
                        prices[nei.first]=currPrice+nei.second;
                        q.push({currStops+1, {nei.first, prices[nei.first]}});
                    }   
                }
            }
        }
        return prices[dst]==INT_MAX?-1:prices[dst];
    }
};