// Minimum Cost Graph
/*
	Given N nodes on a 2-D plane represented as (xi, yi).
	The nodes are said to be connected if the manhattan distance between them is 1. 
	You can connect two nodes that are not connected at the cost of euclidean distance 
	between them. The task is to connect the graph such that every node has a path from 
	any node with minimum cost.

Input: N = 3, edges[][] = {{1, 1}, {1, 1}, {2, 2}, {3, 2}} 
Output: 1.41421 
Since (2, 2) and (2, 3) are already connected. 
So we try to connect either (1, 1) with (2, 2) 
or (1, 1) with (2, 3) but (1, 1) with (2, 2) 
yields the minimum cost.

Input: N = 3, edges[][] = {{1, 1}, {2, 2}, {3, 3}} 
Output: 2.82843
*/

// Time Complexity: O(N*N)
// Auxiliary Space: O(N*N)

#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N=510;

int parent[N], sz[N];

void initialize(){
	for(int i=1; i<N; ++i){
		parent[i]=i;
		sz[i]=i;
	}
}

int root(int node){
	if(parent[node]==node) return node;
	return (parent[node]=root(parent[node]));
}

void connect(int a, int b){
	a=root(a);
	b=root(b);
	if(a!=b){
		if(sz[a]<sz[b]){
			swap(a, b);
		}
		sz[a]+=sz[b];
		parent[b]=a;
	}
}

double minCost(vector<pair<int, int>>&p){
	int n=(int)p.size();
	vector<pair<double, pair<int, int>>>cost;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			if(i!=j){
				int x=abs(p[i].first-p[j].first)+abs(p[i].second-p[j].second);
				if(x==1){
					cost.push_back({0, {i+1, j+1}});
					cost.push_back({0, {j+1, i+1}});
				} else{
					int a=p[i].first-p[j].first;
					int b=p[i].second-p[j].second;
					a*=a, b*=b;
					double d=sqrt(a+b);
					cost.push_back({d, {i+1, j+1}});
					cost.push_back({d, {j+1, i+1}});
				}
			}
		}
	}
	sort(cost.begin(), cost.end());
	initialize();
	double ans=0.00;
	for(auto &vals: cost){
		double c=vals.first;
		int a=vals.second.first, b=vals.second.second;
		if(root(a)!=root(b)){
			connect(a, b);
			ans+=c;
		}
	}
	return ans;
}

int main(){
	vector<pair<int, int>>points{{ 1, 1 }, { 2, 2 }, { 2, 3 }};
	double res=minCost(points);
	cout<<res<<endl;
	return 0;
}
