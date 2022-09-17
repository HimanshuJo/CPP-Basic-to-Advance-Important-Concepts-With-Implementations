// Ford-Fulkerson Algorithm for Maximum Flow Problem
/*
	Given a graph which represents a flow network where every edge has a capacity. 
	Also given two vertices source ‘s’ and sink ‘t’ in the graph, find the maximum possible flow from 
	s to t with following constraints:

	Flow on an edge doesn’t exceed the given capacity of the edge.
	Incoming flow is equal to outgoing flow for every vertex except s and t.
*/
/*
	The below implementation of Ford Fulkerson Algorithm is called Edmonds-Karp Algorithm. 
	The idea of Edmonds-Karp is to use BFS in Ford Fulkerson implementation as BFS always picks a 
	path with minimum number of edges. 

	When BFS is used, the worst case time complexity can be reduced to O(VE^2). 

	The below implementation uses adjacency matrix representation though where BFS takes O(V^2) time, 
	the time complexity of the above implementation is O(EV^3)

*/
/*
Ford-Fulkerson Algorithm 

	The following is simple idea of Ford-Fulkerson algorithm:

		Start with initial flow as 0.

		While there is a augmenting path from source to sink. 

			Add this path-flow to flow.

		Return flow.

-------

Time Complexity: 

	Time complexity of the above algorithm is O(max_flow * E). 

	We run a loop while there is an augmenting path. 

		In worst case, we may add 1 unit flow in every iteration. 
		Therefore the time complexity becomes O(max_flow * E).

-------

How to implement the above simple algorithm? 
	Let us first define the concept of Residual Graph which is needed for understanding the implementation. 

	Residual Graph of a flow network is a graph which indicates additional possible flow. 
	
		If there is a path from source to sink in residual graph, then it is possible to add flow. 
		
		Every edge of a residual graph has a value called residual capacity which is equal to original 
		capacity of the edge minus current flow. 
		
		Residual capacity is basically the current capacity of the edge.

-------

Residual capacity is 0 if there is no edge between two vertices of residual graph. 

We can initialize the residual graph as original graph as there is no initial flow and initially 
residual capacity is equal to original capacity. 

To find an augmenting path, we can either do a BFS or DFS of the residual graph. 
We have used BFS in below implementation. 

Using BFS, we can find out if there is a path from source to sink. 
BFS also builds parent[] array. 

Using the parent[] array, we traverse through the found path and find possible flow through 
this path by finding minimum residual capacity along the path. 

We later add the found path flow to overall flow. 
*/

#include<iostream>
#include<limits.h>
#include<queue>
#include<string.h>
using namespace std;
#define V 6

/*
	Returns true if there is a path from source 's' to sink 't' in a residual graph.
	Also fills parent[] to store the path
*/
bool bfs(int rGraph[V][V], int s, int t, int parent[]){
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue<int>q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v=0; v<V; ++v){
			if(visited[v]==false&&rGraph[u][v]>0){
				/*
					If we find a connection to the sink node, then there is no point in BFS
					anymore, we just have to set its parent can return true
				*/
				if(v==t){
					parent[v]=u;
					return true;
				}
				q.push(v);
				parent[v]=u;
				visited[v]=true;
			}
		}
	}
	return false;
}

// Returns max flow from 's' to 't' in the given graph
int fordFulkerson(int graph[V][V], int s, int t){
	int u, v;
	/*
		Creating a residual graph and fill the residual graph with the given
		capacities in the original graph as residual capacities in the residual graph

		rGraph[i][j] indicates residual capacity of edge from i to j(if there is an edge)
		If rGraph[i][j]=0, then there is not
	*/
	int rGraph[V][V];
	for(u=0; u<V; ++u){
		for(v=0; v<V; ++v){
			rGraph[u][v]=graph[u][v];
		}
	}
	int parent[V];
	int max_flow=0;
	// Augument the flow while there is a flow from source to sink
	while(bfs(rGraph, s, t, parent)){
		/*
			Finding min residual capacity of the edges along the path filled by BFS.
			Or we can say find the max flow through the path found
		*/
		int path_flow=INT_MAX;
		for(v=t; v!=s; v=parent[v]){
			u=parent[v];
			path_flow=min(path_flow, rGraph[u][v]);
		}
		/*
			Updating residual capacities of the edge and reverse edges along the path
		*/
		for(v=t; v!=s; v=parent[v]){
			u=parent[v];
			rGraph[u][v]-=path_flow;
			rGraph[v][u]+=path_flow;
		}
		max_flow+=path_flow;
	}
	return max_flow;
}

int main(){
    int graph[V][V]={ 
    		{ 0, 16, 13, 0, 0, 0 }, 
    		{ 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  
            { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   
            { 0, 0, 0, 0, 0, 0 }
        };
 
    cout << "The maximum possible flow is "
         << fordFulkerson(graph, 0, 5);
 
    return 0;
}