// Topological Sorting
/*
	Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
	for every directed edge u v, vertex u comes before v in the ordering.
	Topological Sorting for a graph is not possible if the graph is not a DAG.

	For example, a topological sorting of the following graph is “5 4 2 3 1 0”.
	There can be more than one topological sorting for a graph.
	For example, another topological sorting of the following graph is “4 5 2 3 1 0”.

	**The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges)
*/

/*
Topological Sorting vs Depth First Traversal (DFS):

	In DFS, we print a vertex and then recursively call DFS for its adjacent vertices.
	In topological sorting, we need to print a vertex before its adjacent vertices.

						 5 	        4
					d/       \d  d/   \d
				    2          0       1
				    \d                /u
					 \d              /u
					          3

		For example, in the given graph, the vertex ‘5’ should be printed before vertex ‘0’,
		but unlike DFS, the vertex ‘4’ should also be printed before vertex ‘0’.

		So Topological sorting is different from DFS.

		For example, a DFS of the shown graph is “5 2 3 1 0 4”, but it is not a topological sorting.
*/

/*
	We can modify DFS to find Topological Sorting of a graph.
	In DFS, we start from a vertex, we first print it and then recursively call DFS for its adjacent vertices.

	In topological sorting, we use a temporary stack.

	We don’t print the vertex immediately, we first recursively call topological sorting
	for all its adjacent vertices, then push it to a stack.

	Finally, print contents of the stack. Note that a vertex is pushed to stack only when all of its
	adjacent vertices (and their adjacent vertices and so on) are already in the stack.
*/

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
	int V;
	list<int>* adj;
	void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void topologicalSort();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack)
{
	visited[v] = true;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			topologicalSortUtil(*i, visited, Stack);
	Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			topologicalSortUtil(i, visited, Stack);
	while (Stack.empty() == false) {
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	cout << "Following is a Topological Sort of the given graph \n";
	g.topologicalSort();
	return 0;
}
