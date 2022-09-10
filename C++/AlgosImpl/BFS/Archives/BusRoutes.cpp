/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

    For example, if routes[0] = [1, 5, 7], this means that the

        0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

    You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. 

    You can travel between bus stops by buses only.

    Return the least number of buses you must take to travel from source to target. 

    Return -1 if it is not possible.

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, 
then take the second bus to the bus stop 6.

Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1

Constraints:

    1 <= routes.length <= 500.
    1 <= routes[i].length <= 10^5
    All the values of routes[i] are unique.
    sum(routes[i].length) <= 10^5
    0 <= routes[i][j] < 10^6
    0 <= source, target < 10^6
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int S, int T){
        map<int, vector<int>>busStpInWhchRt;
        int rtSz=routes.size();
        for(int i=0; i<rtSz; ++i){
            vector<int>curr=routes[i];
            for(auto &busStps: curr){
                busStpInWhchRt[busStps].push_back(i);
            }
        }
        set<int>visBusStp;
        set<int>visRoutes;
        queue<int>busStpsQueue;
        busStpsQueue.push(S);
        int res=0;
        while(!busStpsQueue.empty()){
            int queueSz=busStpsQueue.size();
            set<int>nextBusStps;
            for(int i=0; i<queueSz; ++i){
                int currBusStp=busStpsQueue.front();
                if(currBusStp==T){
                    return res;
                }
                busStpsQueue.pop();
                if(visBusStp.count(currBusStp)==1){
                    continue;
                }
                visBusStp.emplace(currBusStp);
                vector<int>currBusStpRoutes=busStpInWhchRt[currBusStp];
                for(auto &entries: currBusStpRoutes){
                    if(visRoutes.count(entries)!=1){
                        for(auto &busStps: routes[entries]){
                            nextBusStps.emplace(busStps);
                        }
                        visRoutes.emplace(entries);
                    }
                }
            }
            for(auto &entries: nextBusStps){
                busStpsQueue.push(entries);
            }
            res++;
        }
        return -1;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> routes={{1,2,7},{3,6,7}};
    vector<vector<int>> routes2={{7,12},{4,5,15},{6},{15,19},{9,12,13}};
    int S=1;
    int T=6;
    int S2=15;
    int T2=12;
    obj.numBusesToDestination(routes, S, T);
    cout<<endl;
    obj.numBusesToDestination(routes2, S2, T2);
}