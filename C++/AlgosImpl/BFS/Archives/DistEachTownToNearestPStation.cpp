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
*/

/*
Naive Approach: 

	We can loop through the vertices and from each vertex run a BFS to find the closest town with 
		police station from that vertex. 
	
	This will take O(V.E).

*/

#include<bits/stdc++.h>
using namespace std;
#define N 100000+1
#define inf 1000000

int dist[N];

int visited[N];

// we need a hash array where sourceCust[i]==1 means that vertex i is the source
int sourceCust[N];

// we need a BFS queue, here the pairs are of the form (vertex, dist. from the current source)
deque<pair<int, int>> BFSQueue;

void BFS(vector<int>graph[], int currVert){
    while (!BFSQueue.empty()){
        BFSQueue.pop_back();
    }
    BFSQueue.push_back({currVert, 0});
    while (!BFSQueue.empty()){
        int s=BFSQueue.front().first;
        int d=BFSQueue.front().second;
        visited[s]=1;
        BFSQueue.pop_front();
        if (sourceCust[s]==1){
            dist[currVert]=d;
            return;
        }
        // pushing back the adjacent unvisited vertices with the distance from the current source
        // as this' vertex's distance + 1
        for (int i=0; i< graph[s].size(); ++i){
            if (visited[graph[s][i]]==0){
                BFSQueue.push_back({graph[s][i], d+1});
            }
        }
    }
}

void nearestTown(vector<int>graph[], int n, int sources[], int sizeOfSources){
    for (int i=1; i<=n; ++i){
        sourceCust[i]=0;
    }
    for (int i=0; i<=sizeOfSources-1; ++i){
        sourceCust[sources[i]]=1;
    }
    for (int i=1; i<=n; ++i){
        for (int i=1; i<=n; ++i){
            visited[i]=0;
        }
        BFS(graph, i);
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " " << dist[i] << endl;
    }
}

void addEdge(vector<int> graph[], int u, int v){
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