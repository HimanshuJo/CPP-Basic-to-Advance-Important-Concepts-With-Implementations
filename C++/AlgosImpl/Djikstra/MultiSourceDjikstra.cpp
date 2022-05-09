// Determine shortest distance from a vertex to all the other vertices in a graph, taking into account each vertex as a source
// in a directed graph

#include<vector>
#include<iostream>
#include<climits>
#include<queue>
#define N 9
#define INF 999999999
using namespace std;

void djikstra(vector<vector<pair<int, int>>>&gr, vector<int>&dist, int curSource){
	dist[curSource]=0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({0, curSource});
	while(!pq.empty()){
		int sz=pq.size();
		while(sz--){
			pair<int, int>cur=pq.top();
			pq.pop();
			int curVert=cur.second;
			int curWt=cur.first;
			if(curWt>dist[curVert]) continue;
			for(auto &nei: gr[curVert]){
				pair<int, int>curpair=nei;
				int nwV=curpair.first, nwW=curpair.second;
				if(dist[curVert]+nwW<dist[nwV]){
					dist[nwV]=dist[curVert]+nwW;
					pq.push({dist[nwV], nwV});
				}
			}
		}
	}
}


int main(){
	vector<vector<int>>in{{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7},
	                      {2, 8, 2}, {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10},
						  {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};

	vector<vector<pair<int, int>>>gr(N+1);
	for(auto &entries: in){
		gr[entries[0]].push_back({entries[1], entries[2]});
	}
	/*for(int i=0; i<N; ++i){
		cout<<i<<" : "<<endl;
		for(auto &entries: gr[i]){
			cout<<entries.first<<" "<<entries.second<<endl;
		}
		cout<<"-------\n";
	}*/
	cout<<"***---***\n";
	for(int i=0; i<N; ++i){
		vector<int>ans(N+1, INF);
		djikstra(gr, ans, i);
		for(int x=0; x<N; ++x){
			cout<<ans[x]<<" ";
		}
		cout<<"\n-------\n";
	}
}