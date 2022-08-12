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

#include<bits/stdc++.h>
using namespace std;
#define N 100000+1
#define inf 100000

// we need an array that can store the distances of the vertices from the nearest source
int dist[N];

// we need an ordered set that contains the vertices not yet visited in increasing order 
// of the distances from
// the nearest source calculated till now
set<pair<int, int>>Q;

void djikstraUtil(vector<int>graph[], int currsrc){
    set<pair<int, int>>::iterator it;
    for (int i=0; i<graph[currsrc].size(); ++i){
        int nei=graph[currsrc][i];
        if (dist[nei]>dist[currsrc]+1){
            it=Q.find({dist[nei], nei});
            Q.erase(it);
            dist[nei]=dist[currsrc]+1;
            Q.insert({dist[nei], nei});
        }
    }
    if (Q.size()==0){
        return;
    }
    it=Q.begin();
    int next=it->second;
    Q.erase(it);
    djikstraUtil(graph, next);
}

void djikstra(vector<int>graph[], int n, int sources[], int sizeOfSources){
    int CustSource[n+1];
    for (int i=1; i<=n; ++i){
        CustSource[i]=0;
    }
    for (int i=0; i<=sizeOfSources-1; ++i){
        CustSource[sources[i]]=1;
    }
    for (int i=0; i<=n; ++i){
        if (CustSource[i]){
            dist[i]=0;
            Q.insert({0, i});
        } else {
            dist[i]=inf;
            Q.insert({inf, i});
        }
    }
    set<pair<int, int>>::iterator itr;
    itr=Q.begin();
    int start=itr->second;
    djikstraUtil(graph, start);
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
    djikstra(graph, n, sources, sizeOfSources);
    return 0;
}
