#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

class Solution{
public:
	int mod=1e9+7;
	int countPath(int n, vector<vector<int>>&rds){
		vector<vector<pll>>graph(n+1);
		for(auto &rd: rds){
			ll u=rd[0];
			ll v=rd[1];
			ll time=rd[2];
			graph[u].push_back(make_pair(v, time));
			graph[v].push_back(make_pair(u, time));
		}
		return dijkstra(graph, n, 0);
	}

	int dijkstra(const vector<vector<pll>>&graph, int n, int src){
		vector<ll>dist(n+1, LONG_MAX);
		vector<ll>ways(n+1);
		ways[src]=1;
		dist[src]=0;
		priority_queue<pll, vector<pll>, greater<>>minHeap;
		minHeap.push({0, 0});
		while(!minHeap.empty()){
			auto [d, u]=minHeap.top();
			minHeap.pop();
			if(d>dist[u]) continue;
			for(auto [v, time]: graph[u]){
				if(d+time<dist[v]){
					dist[v]=d+time;
					ways[v]=ways[u];
					minHeap.push({dist[v], v});
				} else if(dist[v]==d+time){
					ways[v]=(ways[v]+ways[u])%mod;
				}
			}
		}
		cout<<(ways[n])<<endl;
		return (ways[n]);
	}
};

int main(){
	Solution obj;
	vector<vector<int>>rds={{1, 2, 3}};
	obj.countPath(2, rds);
}

