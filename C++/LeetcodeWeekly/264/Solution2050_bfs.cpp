#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        map<int, int>indeg;
        for(int i=1; i<=n; ++i){
            indeg[i]=0;
        }
        vector<vector<int>>gr_(n+1);
        set<int>seen;
        map<int, int>times;
        for(auto &vals: relations){
            gr_[vals[0]].push_back(vals[1]);
            indeg[vals[1]]++;
        }
        for(int i=0; i<time.size(); ++i){
            times[i+1]=time[i];
        }
        vector<int>indegZ;
        for(auto &entry: indeg){
            if(entry.second==0){
                indegZ.push_back(entry.first);
            }
        }
        vector<int>dist_(n+1);
        queue<int> q;
        for(auto &vals: indegZ){
            dist_[vals]=times[vals];
            q.push(vals);
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : gr_[u]) {
                // Update `dist[v]` using the maximum dist of the predecessor nodes
                dist_[v] = max(dist_[v], dist_[u] + times[v]);
                if (--indeg[v] == 0) 
                    q.push(v);
            }
        }
        return *max_element(dist_.begin(), dist_.end());
    }
};
