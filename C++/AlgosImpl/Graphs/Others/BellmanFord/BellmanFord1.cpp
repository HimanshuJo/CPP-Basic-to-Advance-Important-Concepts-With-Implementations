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
		with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges
*/
// Time Complexity: O(VE)
#include<iostream>
#include<climits>
using namespace std;

struct Edge{
	int src, dest, weight;
};

struct Graph{
	int V, E;
	struct Edge *edge;
};

struct Graph* createGraph(int V, int E){
	struct Graph *graph=new Graph;
	graph->V=V;
	graph->E=E;
	graph->edge=new Edge[E];
	return graph;
}

void printArr(int dist[], int n){
	printf("Vertex\t Distance from Source\n");
	for(int i=0; i<n; ++i){
		printf("%d\t\t%d\n", i, dist[i]);
	}
}

/*
Finding shortest distance from src to all the other vertices.
This function also detects negative weight cycle
*/

void bellmanFord(struct Graph *graph, int src){
	int V=graph->V, E=graph->E;
	int dist[V];
	for(int i=0; i<V; ++i){
		dist[i]=INT_MAX;
	}
	dist[src]=0;
	/*
	Relaxing all the edges |V|-1 times. A simple shortest path from src to any other
	vertex can have at most |V|-1 edges
	*/
	for(int i=1; i<=V-1; ++i){
		for(int j=0; j<E; ++j){
			int u=graph->edge[j].src;
			int v=graph->edge[j].dest;
			int weight=graph->edge[j].weight;
			if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v]){
				dist[v]=dist[u]+weight;
			}
		}
	}
	/*
	Checking negative weight cycles. The above step guarantees shortest distances if the graph
	doesn't contain negative cycles. If here we get a shorter path, then there is a cycle in the graph
	*/
	for(int i=0; i<E; ++i){
		int u=graph->edge[i].src;
		int v=graph->edge[i].dest;
		int weight=graph->edge[i].weight;
		if(dist[u]!=INT_MAX&&dist[u]+weight<dist[v]){
			printf("Graph contain negative weight cycle");
			return;
		}
	}
	printArr(dist, V);
	return;
}

int main(){
	int V=5, E=8;
	struct Graph *graph=createGraph(V, E);
	graph->edge[0].src=0, graph->edge[0].dest=1, graph->edge[0].weight=-1;
	graph->edge[1].src=0, graph->edge[1].dest=2, graph->edge[1].weight=4;
	graph->edge[2].src=1, graph->edge[2].dest=2, graph->edge[2].weight=3;
	graph->edge[3].src=1, graph->edge[3].dest=3, graph->edge[3].weight=2;
	graph->edge[4].src=1, graph->edge[4].dest=4, graph->edge[4].weight=2;
	graph->edge[5].src=3, graph->edge[5].dest=2, graph->edge[5].weight=5;
	graph->edge[6].src=3, graph->edge[6].dest=1, graph->edge[6].weight=1;
	graph->edge[7].src=4, graph->edge[7].dest=3, graph->edge[7].weight=-3;
	bellmanFord(graph, 0);
	return 0;
}
