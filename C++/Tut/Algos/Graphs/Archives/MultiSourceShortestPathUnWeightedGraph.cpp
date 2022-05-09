/*
Suppose there are n towns connected by m bidirectional roads.
There are s towns among them with a police station.
We want to find out the distance of each town from the nearest police station.
If the town itself has one the distance is 0.

Example:

Input :
Number of Vertices = 6
Number of Edges = 9
Towns with Police Station : 1, 5
Edges:
1 2
1 6
2 6
2 3
3 6
5 4
6 5
3 4
5 3

Output :
1 0
2 1
3 1
4 1
5 0
6 1

-------

Naive Approach:

	We can loop through the vertices and from each vertex run a BFS to find the closest town with
		police station from that vertex.

	This will take O(V.E).

	-------

	#include <bits/stdc++.h>
	using namespace std;
	#define N 100000 + 1
	#define inf 1000000

	// array that will store the distances of the vertices from the nearest source
	int dist[N];

	// we need a hash array where sourceCust[i] = 1, that means that vertex i is a source
	int sourceCust[N];

	// the BFS Queue, here the pairs are of the form (vertex, distance from the current source)
	deque<pair<int, int>> BFSQueue;

	// we need a visited array for remembering visited vertices
	int visited[N];

	// the BFS function
	void BFS(vector<int> graph[], int currVert)
	{
	    // since we are running bfs for each vertex therefore clearing it first
	    while (!BFSQueue.empty())
	    {
	        BFSQueue.pop_back();
	    }
	    // pushing back starting vertices
	    BFSQueue.push_back({currVert, 0});
	    while (!BFSQueue.empty())
	    {
	        int s = BFSQueue.front().first;
	        int d = BFSQueue.front().second;
	        visited[s] = 1;
	        BFSQueue.pop_front();

	        // we will terminate as soon as we reach the first source during BFS
	        if (sourceCust[s] == 1)
	        {
	            dist[currVert] = d;
	            return;
	        }

	        // pushing the adjacent unvisited vertices with the distance from the
	        // current source = this vertex's distance + 1
	        for (int i = 0; i < graph[s].size(); ++i)
	        {
	            if (visited[graph[s][i]] == 0)
	            {
	                BFSQueue.push_back({graph[s][i], d + 1});
	            }
	        }
	    }
	}

	// function to calculate the distance of each vertex from the nearest source, this function will call the BFS
	void nearestTown(vector<int> graph[], int n, int sources[], int sizeOfSources)
	{
	    // resetting the source hash array
	    for (int i = 1; i <= n; ++i)
	    {
	        sourceCust[i] = 0;
	    }
	    for (int i = 0; i <= sizeOfSources - 1; ++i)
	    {
	        sourceCust[sources[i]] = 1;
	    }

	    // we have to loop through all the vertices and run a BFS from each vertex to
	    // find the distance to the nearest town from it
	    for (int i = 1; i <= n; ++i)
	    {
	        for (int i = 1; i <= n; ++i)
	        {
	            visited[i] = 0;
	        }
	        BFS(graph, i);
	    }
	    for (int i = 1; i <= n; ++i)
	    {
	        cout << i << " " << dist[i] << endl;
	    }
	}

	void addEdge(vector<int> graph[], int u, int v)
	{
	    graph[u].push_back(v);
	    graph[v].push_back(u);
	}

	int main()
	{
	    int n = 6;
	    vector<int> graph[n + 1];
	    addEdge(graph, 1, 2);
	    addEdge(graph, 1, 6);
	    addEdge(graph, 2, 6);
	    addEdge(graph, 2, 3);
	    addEdge(graph, 3, 6);
	    addEdge(graph, 5, 4);
	    addEdge(graph, 6, 5);
	    addEdge(graph, 3, 4);
	    addEdge(graph, 5, 3);
	    int sources[] = {1, 5};
	    int sizeOfSources = sizeof(sources) / sizeof(sources[0]);
	    nearestTown(graph, n, sources, sizeOfSources);
	    return 0;
	}

	-------

	1 0
	2 1
	3 1
	4 1
	5 0
	6 1

	-------

	import java.util.ArrayList;
	import java.util.Arrays;
	import java.util.Deque;
	import java.util.LinkedList;

	class Pair {
		int first, second;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}
	}

	class Main {
		static final int N = 100000 + 1;
		static final int inf = 1000000;

		// array that will store distances of the vertices from the nearest source
		static int[] dist = new int[N];

		// a hash array where sourceCust[i] = 1 means vertex i is a source
		static int[] sourceCust = new int[N];

		// the bfs Queue
		// here the pairs are of the form (vertex, distance from the current source)
		static Deque<Pair> BFSQueue = new LinkedList<>();

		// visited array for remembering visited vertices
		static int[] visited = new int[N];

		// bfs function
		static void BFS(ArrayList<Integer>[] graph, int currVert) {
			// clearing the queue
			while (!BFSQueue.isEmpty()) {
				BFSQueue.removeLast();
			}

			// pushing back current vertices
			BFSQueue.add(new Pair(currVert, 0));
			while (!BFSQueue.isEmpty()) {
				int s = BFSQueue.peekFirst().first;
				int d = BFSQueue.peekFirst().second;
				visited[s] = 1;
				BFSQueue.removeFirst();

				// we will stop as soon as we reach the first source
				if (sourceCust[s] == 1) {
					dist[currVert] = d;
					return;
				}

				// pushing back the adjacent vertices with distance from the current source =
				// this vertex's distance + 1
				for (int i = 0; i < graph[s].size(); ++i) {
					if (visited[graph[s].get(i)] == 0) {
						BFSQueue.add(new Pair(graph[s].get(i), d + 1));
					}
				}
			}
		}

		// function to calculate the distance of each vertex from the nearest source
		static void nearestTown(ArrayList<Integer>[] graph, int n, int sources[], int sizeOfSources) {
			// resetting the source hash array
			for (int i = 1; i <= n; ++i) {
				sourceCust[i] = 0;
			}
			for (int i = 0; i <= sizeOfSources - 1; ++i) {
				sourceCust[sources[i]] = 1;
			}

			// loop through all the vertices and run a bfs from each vertex to find the 
			// distance to the nearest town from it
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					visited[j] = 0;
				}
				BFS(graph, i);
			}
			for (int i = 1; i <= n; ++i) {
				System.out.println(i + " " + dist[i]);
			}
		}

		static void addEdge(ArrayList<Integer>[] graph, int u, int v) {
			graph[u].add(v);
			graph[v].add(u);
		}

		public static void main(String[] args) {
			int n = 6;
			@SuppressWarnings("unchecked")
			ArrayList<Integer>[] graph = new ArrayList[n + 1];
			Arrays.fill(graph, new ArrayList<>());
			addEdge(graph, 1, 2);
			addEdge(graph, 1, 6);
			addEdge(graph, 2, 6);
			addEdge(graph, 2, 3);
			addEdge(graph, 3, 6);
			addEdge(graph, 5, 4);
			addEdge(graph, 6, 5);
			addEdge(graph, 3, 4);
			addEdge(graph, 5, 3);
			int sources[] = { 1, 5 };
			int sizeOfSources = sources.length;
			nearestTown(graph, n, sources, sizeOfSources);
		}
	}

	Output:

	1 0
	2 1
	3 1
	4 1
	5 0
	6 1

-------

Time:

	O(V.E)

*/
/*
Efficient Way:

	A better way is to use Djikstra's algorithm in a modified way.

	Let's consider one of the sources as the original source and the other sources to be vertices with 0 cost paths
		from the original source

	Thus we can push all the sources into the Djikstra Queue with distance = 0, and the rest of the vertices with
		distance = infinity.

	The minimum distance of each vertex from the original source now calculated using the Dijkstra's Algorithm
		are now essentially the distances from the nearest source

Explanation:

	The C++ implementation uses a set of pairs (distance from the source, vertex) sorted 
	according to the distance from the source.

	Initially the set contains the sources with distance = 0 and all the other vertices with distance = infinity

	On each step, we will go to the vertex with the minimum distance(d) from the source,
		i.e the first element of the set (the source itself in the first step with distance = 0)

		We will go through all its adjacent vertices and if the distance of any vertex is > d + 1
			we replace its entry in the set with the new distance

		Then we will remove the current vertex from the set. We will continue this until the set is empty.

		The idea is there cannot be a shorter path to the vertex at the front of the set than the current one since
			any other path will be a sum of a longer path (>= its length) and a non-negative path length
			(unless we're considering negative edges)

		Since all the sources have a distance = 0, in the beginning,
		the adjacent non-source vertices will get a distance = 1.
		All the vertices will get distance = distance from their nearest source

*/

#include <bits/stdc++.h>
using namespace std;
#define N 100000 + 1
#define inf 1000000

// array that will store the distances of the vertices from the nearest source
int dist[N];

// this set contains the vertices not yet visited in increasing order of
// distance from the nearest source calculated till now
set<pair<int, int>> Q;

// util function for Multi-Source BFS
void multiSourceBFSUtil(vector<int> graph[], int s)
{
	set<pair<int, int>>::iterator it;
	int i;
	for (i = 0; i < graph[s].size(); ++i)
	{
		int v = graph[s][i];
		if (dist[s] + 1 < dist[v])
		{
			// if a shorter path to a vertex is found than the currently stored distance replace it in the Q
			it = Q.find({dist[v], v});
			Q.erase(it);
			dist[v] = dist[s] + 1;
			Q.insert({dist[v], v});
		}
	}
	// we will stop when the Q is empty -> All vertices have been visited.
	// And only visit a vertex when we are sure that a shorter path to that vertex is not possible
	if (Q.size() == 0)
	{
		return;
	}
	// go the the first vertex in Q and remove it from the Q
	it = Q.begin();
	int next = it->second;
	Q.erase(it);
	multiSourceBFSUtil(graph, next);
}

// this function calculates the distance of each vertex from the nearest source
void multiSourceBFS(vector<int> graph[], int n, int sources[], int sizeOfSources)
{
	// a hash array where source[i] = 1 means vertex i is a source
	int CustSource[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		CustSource[i] = 0;
	}
	for (int i = 0; i <= sizeOfSources - 1; ++i)
	{
		CustSource[sources[i]] = 1;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (CustSource[i])
		{
			dist[i] = 0;
			Q.insert({0, i});
		}
		else
		{
			dist[i] = inf;
			Q.insert({inf, i});
		}
	}
	set<pair<int, int>>::iterator itr;
	// get the vertex with the lowest distance
	itr = Q.begin();
	// currently one of the sources with distance = 0
	int start = itr->second;
	multiSourceBFSUtil(graph, start);
	for (int i = 1; i <= n; ++i)
	{
		cout << i << " " << dist[i] << endl;
	}
}

void addEdge(vector<int> graph[], int u, int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

int main()
{
	int n = 6;
	vector<int> graph[n + 1];
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 6);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 6);
	addEdge(graph, 5, 4);
	addEdge(graph, 6, 5);
	addEdge(graph, 3, 4);
	addEdge(graph, 5, 3);
	int sources[] = {1, 5};
	int sizeOfSources = sizeof(sources) / sizeof(sources[0]);
	multiSourceBFS(graph, n, sources, sizeOfSources);
	return 0;
}

/*
Output:

1 0
2 1
3 1
4 1
5 0
6 1

Time Complexity: O(E.logV)
*/