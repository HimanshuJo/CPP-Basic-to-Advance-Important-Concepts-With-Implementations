/*
Check if a graph is strongly connected | Set 1 (Kosaraju using DFS)

Given a directed graph, find out whether the graph is strongly connected or not.

Strong Connected Graph:

    "A directed graph is strongly connected if there is a path between any two pair of vertices"

For example, following is a strongly connected graph.

        0->1->2->3->0
             \|/
              4->2

It is easy for undirected graph, we can just do a BFS and DFS starting from any vertex.
If BFS or DFS visits all vertices, then the given undirected graph is connected.

This approach won’t work for a directed graph. For example, consider the following graph which is not strongly connected.

                    0->1->2->3->4

If we start DFS (or BFS) from vertex 0, we can reach all vertices, but if we start from any other vertex, 
we cannot reach all vertices.
*/

/*
A simple idea is to use a all pair shortest path algorithm like Floyd Warshall or find Transitive Closure of graph.
Time complexity of this method would be O(v3).

We can also do DFS V times starting from every vertex. If any DFS, doesn’t visit all vertices,
then graph is not strongly connected. 

This algorithm takes O(V*(V+E)) time which can be same as transitive closure for a dense graph.

A better idea can be Strongly Connected Components (SCC) algorithm. We can find all SCCs in O(V+E) time.
If number of SCCs is one, then graph is strongly connected. The algorithm for SCC does extra work as it finds all SCCs.

Following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph:
1) Initialize all vertices as not visited.
2) Do a DFS traversal of graph starting from any arbitrary vertex v. 
If DFS traversal doesn’t visit all vertices, then return false.
3) Reverse all arcs (or find transpose or reverse of graph)
4) Mark all vertices as not-visited in reversed graph.
5) Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2).
If DFS traversal doesn’t visit all vertices, then return false. Otherwise return true.
The idea is, if every node can be reached from a vertex v, and every node can reach v, then the graph
is strongly connected. In step 2, we check if all vertices are reachable from v. In step 4, we check if
all vertices can reach v 
(In reversed graph, if all vertices are reachable from v, then all vertices can reach v in original graph).
*/

// C++ Implementation of Kosaraju's algorithm to print all SCCs
#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph
{
    int V; // No. of vertices
    list<int> *adj; // An array of adjacency lists

    // Fills Stack with vertices (in increasing order of finishing
    // times). The top element of stack has the maximum finishing
    // time
    void fillOrder(int v, bool visited[], stack<int> &Stack);

    // A recursive function to print DFS starting from v
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);

    void addEdge(int v, int w);

    // The main function that finds and prints strongly connected
    // components
    void printSCCs();

    // Function that returns reverse (or transpose) of this graph
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

// A recursive function to print DFS starting from v
void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::fillOrder(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            fillOrder(*i, visited, Stack);

    // All vertices reachable from v are processed by now, push v
    Stack.push(v);
}

// The main function that finds and prints all strongly connected
// components
void Graph::printSCCs()
{
    stack<int> Stack;

    // Mark all the vertices as not visited (For first DFS)
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Fill vertices in stack according to their finishing times
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            fillOrder(i, visited, Stack);

    // Create a reversed graph
    Graph gr = getTranspose();

    // Mark all the vertices as not visited (For second DFS)
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Print Strongly connected component of the popped vertex
        if (visited[v] == false)
        {
            gr.DFSUtil(v, visited);
            cout << endl;
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();

    return 0;
}

/*
Output:
0
1
2
3
4
*/