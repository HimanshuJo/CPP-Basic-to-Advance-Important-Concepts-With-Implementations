/*
Print all paths from a given source to a destination

Given a directed graph, a source vertex ‘s’ and a destination vertex ‘d’, print all paths from given ‘s’ to ‘d’. 

Approach:
 
The idea is to do Depth First Traversal of given directed graph.

Start the DFS traversal from source.

Keep storing the visited vertices in an array or HashMap say ‘path[]’.

If the destination vertex is reached, print contents of path[].

The important thing is to mark current vertices in the path[] as visited also so 
that the traversal doesn’t go in a cycle.

-------

Complexity Analysis: 
 
Time Complexity: O(V^V). 

The time complexity is polynomial. 
From each vertex there are v vertices that can be visited from current vertex

-------

Auxiliary space: O(V^V). 
To store the paths V^V space is needed.
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int>*adj;
	void printAllPathsUtil(int, int, bool[], int[], int&);

public:
	Graph(int V);
	void addEdge(int u, int v);
	void printAllPaths(int src, int dest);
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void Graph::printAllPaths(int src, int dest){
	bool *visited=new bool[V];
	int *path=new int[V];
	int path_index=0;
	for(int i=0; i<V; ++i){
		visited[i]=false;
	}
	printAllPathsUtil(src, dest, visited, path, path_index);
}

void Graph::printAllPathsUtil(int src, int dest, bool visited[], int path[], int &path_index){
	visited[src]=true;
	path[path_index]=src;
	path_index++;
	if(src==dest){
		for(int i=0; i<path_index; ++i){
			cout<<path[i]<<" ";
		}
		cout<<endl;
	} else{
		list<int>::iterator i;
		for(i=adj[src].begin(); i!=adj[src].end(); ++i){
			if(!visited[*i]){
				printAllPathsUtil(*i, dest, visited, path, path_index);
			}
		}
	}
	path_index--;
	visited[src]=false;
}

int main(){
 	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printAllPaths(s, d);
    return 0;
}