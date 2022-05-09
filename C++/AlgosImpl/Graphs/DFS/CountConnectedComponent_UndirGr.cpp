/*
1) Initialize all vertices as not visited.
2) Do following for every vertex 'v'.
       (a) If 'v' is not visited before, call DFSUtil(v)
       (b) Print new line character

DFSUtil(v)
1) Mark 'v' as visited.
2) Print 'v'
3) Do following for every adjacent 'u' of 'v'.
    If 'u' is not visited, then recursively call DFSUtil(u)
*/

// C++ program to print connected components in
// an undirected graph
#include <iostream>
#include <list>
#include<vector>
#include<set>
using namespace std;

vector<set<int>>allComps;

class Graph {
	int V;
	list<int>* adj;
	void DFSUtil(int v, set<int>&tmp, bool visited[]);

public:
	Graph(int V);
	~Graph();
	void addEdge(int v, int w);
	void connectedComponents();
};

void Graph::connectedComponents()
{
	bool* visited = new bool[V];
	for (int v = 0; v < V; v++)
		visited[v] = false;
	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {
			set<int>tmp;
			DFSUtil(v, tmp, visited);
			allComps.push_back(tmp);
		}
	}
	delete[] visited;
}

void Graph::DFSUtil(int v, set<int>&tmp, bool visited[])
{
	visited[v] = true;
	tmp.insert(v);
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i]) {
			DFSUtil(*i, tmp, visited);
		}
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int main()
{
	int N = 5;
	Graph g(N);
	g.addEdge(1, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.connectedComponents();
	cout << "No. connc. components: " << allComps.size() << endl;
	cout << "Following are connected components \n";
	cout << "-------\n";
	for (auto &vals : allComps) {
		for (auto &num : vals) {
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}
