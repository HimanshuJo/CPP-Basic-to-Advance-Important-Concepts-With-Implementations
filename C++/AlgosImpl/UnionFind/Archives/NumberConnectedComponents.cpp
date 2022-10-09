/*
In DSU algorithm, there are two main functions, i.e. connect() and root() function.

connect(): Connects an edge.
root(): Recursively determine the topmost parent of a given edge.

For each edge {a, b}, check if a is connected to b or not. 
	If found to be false, connect them by appending their top parents.

After completing the above step for every edge, print the total number of the 
distinct top-most parents for each vertex.

Time Complexity: O(N+M)
Auxiliary Space: O(N+M)
*/

#include<vector>
#include<iostream>
#include<set>
using namespace std;

int parent[100000];

int root(int a){
	if(a==parent[a]) return a;
	return (parent[a]=root(parent[a]));
}

void connect(int a, int b){
	a=root(a);
	b=root(b);
	if(a!=b){
		parent[b]=a;
	}
}

int connectedComponentsUtil(int n){
	set<int>s;
	for(int i=0; i<n; ++i){
		s.insert(root(parent[i]));
	}
	return s.size();
}

int connectedComponents(int n, vector<vector<int>>&edges){
	for(int i=0; i<=n; ++i){
		parent[i]=i;
	}
	int sz=edges.size();
	for(int i=0; i<sz; ++i){
		connect(edges[i][0], edges[i][1]);
	}
	int ans=connectedComponentsUtil(n);
	return ans;
}

int main(){
	int n=8;
	vector<vector<int>>edges{{1, 0}, {0, 2}, {5, 3}, {3, 4}, {6, 7}};
	int cnt=connectedComponents(n, edges);
	cout<<cnt<<endl;
}