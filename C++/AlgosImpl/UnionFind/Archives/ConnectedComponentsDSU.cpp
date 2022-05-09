/*
	Count number of connected components using DSU algo
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define N 6
using namespace std;

vector<int> parent(N), sz(N);

void initialize(){
	for(int i=0; i<=N; ++i){
		parent[i]=i;
		sz[i]=1;
	}
}

int root(int node){
	if(parent[node]==node) return node;
	return (parent[node]=root(parent[node]));
}

void connect(int a, int b){
	a=root(a), b=root(b);
	if(a!=b){
		if(sz[a]<sz[b]){
			swap(a, b);
		}
		sz[a]+=sz[b];
		parent[b]=a;
	}
}

int connectedComponentsUtil(int vertices){
	set<int>st;
	for(int i=0; i<vertices; ++i){
		st.insert(parent[i]);
	}
	return st.size();
}

int connectedComponents(vector<vector<int>>&edges, int vertices){
	initialize();
	for(auto &vals: edges){
		connect(vals[0], vals[1]);
		connect(vals[1], vals[0]);
	}
	int ans=connectedComponentsUtil(vertices);
	return ans;
}

int main(){
	int vertices=6;
	vector<vector<int>>edges{ { 0, 1, 4 }, { 3, 4, 5 },
            				  { 2, 3, 14 }, { 1, 5, 24 },
            				  { 2, 4, 12 }, { 0, 3, 42 },
            				  { 1, 2, 41 }, { 4, 5, 11 } };
	int res=connectedComponents(edges, vertices);
	for(int i=0; i<vertices; ++i)
	cout<<i<<" "<<parent[i]<<endl;
	cout<<res<<endl;
}