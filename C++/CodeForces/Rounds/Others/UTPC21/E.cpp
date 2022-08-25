#include<bits/stdc++.h>
using namespace std;
int X=0;

void dfsUtil(int node, int count, bool visited[], int &maxCount, vector<vector<int>>&adj){
	visited[node]=true;
	count++;
	for(int i=0; i<=adj.size(); ++i){
		if(!visited[i]&&adj[node][i]==1){
			if(count>=maxCount){
				maxCount=count;
				X=i;
			}
			dfsUtil(i, count, visited, maxCount, adj);
		}
	}
}

void dfs(int node, int N, vector<vector<int>>&adj, int &maxCount){
	bool visited[51];
	int count=0;
	for(int i=0; i<=50; ++i){
		visited[i]=false;
	}
	dfsUtil(node, count+1, visited, maxCount, adj);
}

int diameter(vector<vector<int>>&adj, int N){
	int maxCount=INT_MIN;
	dfs(1, N, adj, maxCount);
	dfs(X, N, adj, maxCount);
	return maxCount;
}

void addEdge(vector<vector<int>>&arr, int src, int dest){
	arr[src][dest]=1;
	arr[dest][src]=1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int V1;
	cin>>V1;
	bool flag1=false;
	bool flag2=false;
	if(V1>1)
		flag1=true;
	vector<vector<int>>gr1(V1+1, vector<int>(V1+1));
	for(int i=0; i<=V1; ++i){
		for(int j=0; j<=V1; ++j){
			gr1[i][j]=0;
		}
	}
	for(int i=0; i<V1-1; ++i){
		int u, v;
		cin>>u>>v;
		addEdge(gr1, u, v);
	}
	int V2;
	cin>>V2;
	if(V2>1)
		flag2=true;
	vector<vector<int>>gr2(V2+1, vector<int>(V2+1));
	for(int i=0; i<=V2; ++i){
		for(int j=0; j<=V2; ++j){
			gr2[i][j]=0;
		}
	}
	for(int i=0; i<V2-1; ++i){
		int u, v;
		cin>>u>>v;
		addEdge(gr2, u, v);
	}	
	int d1=1;
	if(flag1)
		d1=diameter(gr1, V1);
	X=0;
	int d2=1;
	if(flag2)
		d2=diameter(gr2, V2);
	cout<<(d1+d2);
}
