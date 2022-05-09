#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class AdjListNode{
	int v;
	int weight;
public:
	AdjListNode(int _v, int _weight){
		v=_v;
		weight=_weight;
	}
	int getV(){
		return v;
	}
	int getWeight(){
		return weight;
	}
};

class Graph{
	int V;
	list<AdjListNode>*adj;
	void topoSortUtil(int v, bool visited[], stack<int>&stk);
	public:
		Graph(int V);
		void addEdge(int u, int v, int weight);
		void shortestPath(int src);
};

Graph::Graph(int V){
	this->V=V;
	adj=new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight){
	AdjListNode node(v, weight);
	adj[u].push_back(node);
}

void Graph::topoSortUtil(int v, bool visited[], stack<int>&stk){
	visited[v]=true;
	list<AdjListNode>::iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); ++i){
		AdjListNode node=*i;
		if(!visited[node.getV()]){
			topoSortUtil(node.getV(), visited, stk);
		}
	}
	stk.push(v);
}

void Graph::shortestPath(int s){
	stack<int>stk;
	int v=V;
	int dist[v];
	bool *visited=new bool[v];
	for(int i=0; i<v; ++i){
		visited[i]=false;
	}
	for(int i=0; i<v; ++i){
		if(visited[i]==false){
			topoSortUtil(i, visited, stk);
		}
	}
	for(int i=0; i<v; ++i){
		dist[i]=INF;
	}
	dist[s]=0;
	while(!stk.empty()){
		int u=stk.top();
		stk.pop();
		list<AdjListNode>::iterator i;
		if(dist[u]!=INF){
			for(i=adj[u].begin(); i!=adj[u].end(); ++i){
				if(dist[i->getV()]>dist[u]+i->getWeight()){
					dist[i->getV()]=dist[u]+i->getWeight();
				}
			}
		}
	}
	for(int i=0; i<v; ++i){
		(dist[i]==INF?cout<<"INF ":cout<<dist[i]<<" ");
	}
}

int main(){
	Graph g(6);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 3);
	g.addEdge(1, 3, 6);
	g.addEdge(1, 2, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 4, 7);
	g.addEdge(3, 4, -1);
	g.addEdge(4, 5, -2);
	int s=1;
	g.shortestPath(s);
	return 0;
}