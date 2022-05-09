#include<vector>
#include<algorithm>
#include<cassert>
#include<vector>
#include<iostream>
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
using namespace std;

const int maxn=300010;
int n, m, mm, k, u, v, x, y, t, a, b;
int U[maxn], V[maxn], W[maxn], ans[maxn], deg[maxn], pairr[maxn][3], mark[maxn];
vector<int>G[maxn][3], E[maxn];
vector<pair<int, int>>G2[maxn];


inline void orient(int i, int u){
	if(u==U[i]){
		ans[i]=1;
		deg[U[i]]-=W[i];
		deg[V[i]]+=W[i];
	} else{
		ans[i]=2;
		deg[U[i]]+=W[i];
		deg[V[i]]-=W[i];
	}
}

void MergePath(int i, int w){
	mm++;
	int v=i;
	while(1){
		while(SZ(G[v][w])&&mark[G[v][w].back()]){
			G[v][w].pop_back();
		}
		if(G[v][w].empty()) break;
		int i=G[v][w].back();
		assert(!mark[i]);
		mark[i]=1;
		E[mm].push_back(i);
		int u=(U[i]^V[i]^v);
		pairr[u][w]^=1;
		pairr[v][w]^=1;
		v=u;
	}
	if(E[mm].empty()){
		mm--;
		return;
	}
	G2[i].push_back({v, mm});
	G2[v].push_back({i, -mm});
}


void dfs(int v){
	while(SZ(G2[v])&&mark[abs(G2[v].back().second)]){
		G2[v].pop_back();
	}
	if(G2[v].empty()) return;
	int u=G2[v].back().first;
	int	id=G2[v].back().second;
	if(id<0){
		id*=-1;
		reverse(E[id].begin(), E[id].end());
	}
	mark[id]=1;
	for(int i: E[id]){
		orient(i, v);
		v^=V[i]^U[i];
	}
	assert(v==u);
	dfs(u);
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; ++i){
		cin>>U[i]>>V[i]>>W[i];
		pairr[U[i]][W[i]]^=1;
		pairr[V[i]][W[i]]^=1;
		G[U[i]][W[i]].push_back(i);
		G[V[i]][W[i]].push_back(i);
	}
	int sm=0;
	for(int i=1; i<=n; ++i){
		sm+=pairr[i][1];
	}
	for(int i=1; i<=n; ++i){
		for(int w:{1, 2}){
			if(pairr[i][w]){
				MergePath(i, w);
			}
		}
	}
	for(int i=1; i<=n; ++i){
		for(int w:{1, 2}){
			MergePath(i, w);
		}
	}
	for(int i=0; i<m; ++i){
		assert(mark[i]);
		mark[i]=0;
	}
	for(int i=1; i<=n; ++i){
		if(SZ(G2[i])&1){
			dfs(i);
		}
	}
	for(int i=1; i<=n; ++i){
		dfs(i);
	}
	cout<<sm<<"\n";
	for(int i=0; i<m; ++i){
		cout<<ans[i];
	}
	cout<<"\n";
}
