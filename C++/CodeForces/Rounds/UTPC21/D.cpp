#include<bits/stdc++.h>
using namespace std;

int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		int N, K, M;
		cin>>N>>K>>M;
		vector<int>houses(K);
		for(int i=0; i<K; ++i){
				cin>>houses[i];
		}
		vector<vector<pair<int, int>>>gr(N+1);
		for(int i=0; i<M; ++i){
				int mu, mv, mc;
				cin>>mu>>mv>>mc;
				gr[mu].push_back({mv, mc});
				gr[mv].push_back({mu, mc});
		}
		vector<int> dist(N+1, INT_MAX);
		dist[0]=0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
		pq.push({0, 0});
		while(!pq.empty()){
				auto [d, v]=pq.top();
				pq.pop();
				if(d>dist[v]) continue;
				for(auto [node, time]: gr[v]){
						if(d+time<dist[node]){
								dist[node]=d+time;
								pq.push({dist[node], node});
						}
				}
		}
		int totTime=0;
		int maxx=INT_MIN;
		for(auto &vals: houses){
				totTime+=dist[vals];
				if(dist[vals]>maxx){
						maxx=dist[vals];
				}
		}
		cout<<totTime*2<<" "<<maxx*2;
}


