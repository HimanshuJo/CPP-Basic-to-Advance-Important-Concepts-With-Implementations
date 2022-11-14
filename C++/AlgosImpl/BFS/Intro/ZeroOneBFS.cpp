/*
0-1 BFS (Shortest Path in a Binary Weight Graph)

Given a graph where every edge has weight as either 0 or 1. 
A source vertex is also given in the graph. Find the shortest path from source vertex to every other vertex.

Example: 

Input : Source Vertex = 0 and below graph 
Output : Shortest distances from given source
         0 0 1 1 2 1 2 1 2

Explanation : 
Shortest distance from 0 to 0 is 0
Shortest distance from 0 to 1 is 0
Shortest distance from 0 to 2 is 1
*/
/*
In normal BFS of a graph all edges have equal weight but in 0-1 BFS some edges may have 0 weight 
and some may have 1 weight. 

In this we will not use boolean array to mark visited nodes but at each step we will 
check for the optimal distance condition. 

We use double ended queue to store the node.

While performing BFS if a edge having weight = 0 is found node is pushed at front of 
double ended queue and if a edge having weight = 1 is found, it is pushed at back of double ended queue.

The approach is similar to Dijkstra that the if the shortest distance to node 
is relaxed by the previous node then only it will be pushed in the queue.

The above idea works in all cases, when pop a vertex (like Dijkstra), 
it is the minimum weight vertex among remaining vertices. 

If there is a 0 weight vertex adjacent to it, then this adjacent has same distance. 

If there is a 1 weight adjacent, then this adjacent has maximum distance among all vertices in 
dequeue (because all other vertices are either adjacent of currently popped vertex or adjacent of 
previously popped vertices).

-------

This problem can also be solved by Dijkstra but the time complexity will be 
O(E+VLogV) whereas by BFS it will be O(E+V).
*/

#include<deque>
#include<vector>
#include<iostream>
using namespace std;
#define V 9

struct Node{
	int to, weight;
};

vector<Node>edges[V];

void zeroOneBFS(int src){
	int dist[V];
	for(int i=0; i<V; ++i){
		dist[i]=INT_MAX;
	}
	deque<int>dq;
	dist[src]=0;
	dq.push_back(src);
	while(!dq.empty()){
		int sz=dq.size();
		while(sz--){
			int v=dq.front();
			dq.pop_front();
			for(int i=0; i<edges[v].size(); ++i){
				if(dist[edges[v][i].to]>dist[v]+edges[v][i].weight){
					dist[edges[v][i].to]=dist[v]+edges[v][i].weight;
					if(edges[v][i].weight==0){
						dq.push_front(edges[v][i].to);
					} else{
						dq.push_back(edges[v][i].to);
					}
				}
			}
		}
	}
	for(int i=0; i<V; ++i){
		cout<<dist[i]<<" ";
	}
}

void addEdge(int u, int v, int wt){
	edges[u].push_back({v, wt});
	edges[v].push_back({u, wt});
}

int main()
{
    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 5, 0);
    addEdge(2, 8, 1);
    addEdge(3, 4, 1);
    addEdge(3, 5, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(6, 7, 1);
    addEdge(7, 8, 1);
    int src = 0;
    zeroOneBFS(src);
    return 0;
}