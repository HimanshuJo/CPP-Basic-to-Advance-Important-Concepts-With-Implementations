// 332. Reconstruct Itinerary
/*
You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the 
arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". 
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical 
order when read as a single string.

For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
*/

#include<unordered_map>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    void dfs(string origin, unordered_map<string,  multiset<string>>&gr, vector<string>&ans){
        while(gr[origin].size()>0){
            string nextDest=*(gr[origin].begin());
            gr[origin].erase(gr[origin].begin());
            dfs(nextDest, gr, ans);
        }
        ans.push_back(origin);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>>gr;
        for(auto &ticket: tickets){
            gr[ticket[0]].insert(ticket[1]);
        }
        vector<string>ans;
        string origin="JFK";
        dfs(origin, gr, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){}