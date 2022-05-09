#include<bits/stdc++.h>
using namespace std;

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
