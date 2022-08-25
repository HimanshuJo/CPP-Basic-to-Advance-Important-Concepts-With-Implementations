// D. Weights Assignment For Tree Edges
/*
You are given a rooted tree consisting of n vertices. Vertices are numbered from 1 to n. Any vertex can be the root of a tree.

A tree is a connected undirected graph without cycles. A rooted tree is a tree with a selected vertex, which is called the root.

The tree is specified by an array of ancestors b containing n numbers: bi is an ancestor of the vertex with the number i. 
The ancestor of a vertex u is a vertex that is the next vertex on a simple path from u to the root. 
For example, on the simple path from 5 to 3 (the root), the next vertex would be 1, so the ancestor of 5 is 1.

The root has no ancestor, so for it, the value of bi is i (the root is the only vertex for which bi=i).

For example, if n=5 and b=[3,1,3,3,1], then the tree looks like this.

You are given an array p — a permutation of the vertices of the tree. If it is possible, assign any positive integer weights on the edges, 
so that the vertices sorted by distance from the root would form the given permutation p.

In other words, for a given permutation of vertices p, it is necessary to choose such edge weights so that the condition dist[pi]<dist[pi+1] is true for each i from 1 to n−1. 
dist[u] is a sum of the weights of the edges on the path from the root to u. In particular, dist[u]=0 if the vertex u is the root of the tree.

For example, assume that p=[3,1,2,5,4]. In this case, the following edge weights satisfy this permutation:

the edge (3,4) has a weight of 102;
the edge (3,1) has weight of 1;
the edge (1,2) has a weight of 10;
the edge (1,5) has a weight of 100.

The array of distances from the root looks like: dist=[1,11,0,102,101]. The vertices sorted by increasing the distance from the root form the given permutation p.

Print the required edge weights or determine that there is no suitable way to assign weights. If there are several solutions, then print any of them.

Example
input
4
5
3 1 3 3 1
3 1 2 5 4
3
1 1 2
3 1 2
7
1 1 2 3 4 5 6
1 2 3 4 5 6 7
6
4 4 4 4 1 1
4 2 1 5 6 3
output
1 10 0 102 100
-1
0 3 100 1 1 2 4
6 5 10 0 2 3
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>in(n+1);
		vector<int>permu(n+1);
		vector<int>dist(n+1, -1);
		for(int i=1; i<=n; ++i){
			cin>>in[i];
		}
		for(int j=1; j<=n; ++j){
			cin>>permu[j];
		}
		if(in[permu[1]]!=permu[1]){
			cout<<"-1\n";
		} else{
			dist[permu[1]]=0;
			bool flag=false;
			for(int i=2; i<=n; ++i){
				if(dist[in[permu[i]]]==-1){
					cout<<"-1\n";
					flag=true;
					break;
				}
				dist[permu[i]]=dist[permu[i-1]]+1;
			}
			if(!flag){
				for(int i=1; i<=n; ++i){
					cout<<dist[i]-dist[in[i]]<<" ";
				}
			}
		}
		cout<<"\n";
	}
}
