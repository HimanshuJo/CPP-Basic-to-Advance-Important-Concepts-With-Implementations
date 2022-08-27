#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int N=9;

void bfs(vector<vector<int>>&gr, vector<bool>&seen, int src){
	queue<int>q;
	q.push(src);
	seen[src]=true;
	vector<int>dist(N+1, INT_MAX);
	dist[src]=0;
	while(!q.empty()){
		int currNode=q.front();
		q.pop();
		for(auto &nei: gr[currNode]){
			if(!seen[nei]){
				if(dist[nei]>dist[currNode]+1){
					dist[nei]=dist[currNode]+1;
					q.push(nei);
					seen[nei]=true;
				}
			}
		}
	}
	for(int i=1; i<N; ++i)
		cout<<i<<" : "<<dist[i]<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>>gr(9);
	gr[4].push_back(7);
	gr[7].push_back(4);

	gr[2].push_back(5);
	gr[5].push_back(2);

	gr[1].push_back(6);
	gr[6].push_back(1);

	gr[3].push_back(6);
	gr[6].push_back(3);

	gr[7].push_back(2);
	gr[2].push_back(7);

	gr[1].push_back(7);
	gr[7].push_back(1);

	gr[6].push_back(8);
	gr[8].push_back(6);
	vector<bool>seen(9, false);
	bfs(gr, seen, 1);
}
