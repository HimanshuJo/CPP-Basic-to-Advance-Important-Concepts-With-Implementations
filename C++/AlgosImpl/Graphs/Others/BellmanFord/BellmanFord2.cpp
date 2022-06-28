/*
Given a graph and a source vertex src in graph, find shortest paths from src to all 
vertices in the given graph. 

The graph may contain negative weight edges

-------

Dijkstra’s algorithm is a Greedy algorithm and time complexity is O((V+E)LogV) (with the use of Fibonacci heap). 

Dijkstra doesn’t work for Graphs with negative weights, 

Bellman-Ford works for such graphs. 

	Bellman-Ford is also simpler than Dijkstra and suites well for distributed systems. 

	But time complexity of Bellman-Ford is O(VE), which is more than Dijkstra.

-------

Algorithm:

	Input: Graph and a source vertex src

	Output: Shortest distance to all vertices from src. 

			If there is a negative weight cycle, then shortest distances are not calculated, 
			negative weight cycle is reported.

	-------

	1) This step initializes distances from the source to all vertices as infinite and 
	   distance to the source itself as 0. 

	   Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

   2) This step calculates shortest distances. 

	  Do following |V|-1 times where |V| is the number of vertices in given graph.

		a) Do following for each edge u-v 
			
			If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
			
			dist[v] = dist[u] + weight of edge uv

	3) This step reports if there is a negative weight cycle in graph. 

		Do following for each edge u-v 
			
			If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”

	The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t 
	contain a negative weight cycle. 

	If we iterate through all edges one more time and get a shorter path for any vertex, 
	then there is a negative weight cycle

-------

How does this work? 

Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. 

	It first calculates the shortest distances which have at-most one edge in the path. 

	Then, it calculates the shortest paths with at-most 2 edges, and so on. 

	After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. 

		There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. 

		The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths 
		with at most i edges, then an iteration over all edges guarantees to give shortest path 
		with at-most (i+1) edges
*/

// Time Complexity: O(VE)
#include<iostream>
#include<climits>
using namespace std;

void bellmanFord(int graph[][3], int V, int E, int src){
	int dist[V];
	for(int i=0; i<V; ++i){
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	/*
	Relaxing all the edges |V|-1 times. A simple shortest path from src to any other
	vertex can have at most |V|-1 edges
	*/
	for(int i=0; i<V-1; ++i){
		for(int j=0; j<E; ++j){
			if(dist[graph[j][0]]!=INT_MAX&&dist[graph[j][0]]+graph[j][2]<dist[graph[j][1]]){
				dist[graph[j][1]]=dist[graph[j][0]]+graph[j][2];
			}
		}
	}
	/*
	Checking negative weight cycles. The above step guarantees shortest distances if the graph
	doesn't contain negative cycles. If here we get a shorter path, then there is a cycle in the graph
	*/
	for(int i=0; i<E; ++i){
		int x=graph[i][0];
		int y=graph[i][1];
		int weight=graph[i][2];
		if(dist[x]!=INT_MAX&&dist[x]+weight<dist[y]){
			cout<<"Graph contain negative weight cycle"<<endl;
		}
	}
	cout<<"Vertex distances from the source"<<endl;
	for(int i=0; i<V; ++i){
		cout<<i<<"\t\t"<<dist[i]<<endl;
	}
}

int main(){
	int V=5, E=8;
	int graph[][3]={{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, 
	                {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, 
					{3, 1, 1}, {4, 3, -3}};
	bellmanFord(graph, V, E, 0);
	return 0;
}
