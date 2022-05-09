// time complexity is O(E log V)
/*
Prim's:
	It starts to build the Minimum Spanning Tree from any vertex in the graph.

	It traverses one node more than one time to get the minimum distance.

	Prim’s algorithm has a time complexity of O(V2), V being the number of vertices and 
	can be improved up to O(E log V) using Fibonacci heaps.

	Prim’s algorithm gives connected component as well as it works only on connected graph.

	Prim’s algorithm runs faster in dense graphs.

	Prim’s algorithm uses List Data Structure.

Kruksal's:

	It starts to build the Minimum Spanning Tree from the vertex carrying minimum weight in the graph.

	It traverses one node only once.

	Kruskal’s algorithm’s time complexity is O(E log V), V being the number of vertices.

	Kruskal’s algorithm can generate forest(disconnected components) at any instant as well as it can work on disconnected components

	Kruskal’s algorithm runs faster in sparse graphs.

	Kruskal’s algorithm uses Heap Data Structure.
*/

#include<bits/stdc++.h>
using namespace std;

struct Edge{
public:
	int src, dest, weight;
};

struct Graph{
public:
	int V, E;
	struct Edge* edge;
};

struct Subset{
public:
	int parent;
	int rank;
};

Graph* createGraph(int V, int E){
	struct Graph* graph=(struct Graph*)(malloc(sizeof(struct Graph)));
	graph->V=V;
	graph->E=E;
	graph->edge=(struct Edge*)(malloc(sizeof(struct Edge)*E));
	return graph;
}

int find(Subset subsets[], int i){
	if(subsets[i].parent!=i){
		subsets[i].parent=find(subsets, subsets[i].parent);
	}
	return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y){
	int xroot=find(subsets, x);
	int yroot=find(subsets, y);
	if(subsets[xroot].rank<subsets[yroot].rank){
		subsets[xroot].parent=yroot;
	} else if(subsets[yroot].rank<subsets[xroot].rank){
		subsets[yroot].parent=xroot;
	} else{
		subsets[yroot].parent=xroot;
		subsets[xroot].rank++;
	}
}

int custComp(const void* a, const void* b){
	struct Edge* a1=(struct Edge*)a;
	struct Edge* b1=(struct Edge*)b;
	return a1->weight<b1->weight;
}

void KruskalMST(Graph* graph){
	int V=graph->V;
	struct Edge result[V];
	int e=0, i=0;
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), custComp);
	struct Subset* subsets=(struct Subset*)malloc(V*sizeof(struct Subset));
	for(int v=0; v<V; ++v){
		subsets[v].parent=v;
		subsets[v].rank=0;
	}
	while(e<V-1&&i<graph->E){
		struct Edge nextEdge=graph->edge[i++];
		int x=find(subsets, nextEdge.src);
		int y=find(subsets, nextEdge.dest);
		if(x!=y){
			result[e++]=nextEdge;
			Union(subsets, x, y);
		}
	}
	int minCost=0;
	for(int i=0; i<e; ++i){
		cout<<result[i].src<<" "<<result[i].dest<<" "<<result[i].weight<<endl;
		minCost+=result[i].weight;
	}
	return;
}

int main(){
	int V=1000;
	int E=5;
	struct Graph* graph=createGraph(V, E);
	graph->edge[0].src=0;
	graph->edge[0].dest=1;
	graph->edge[0].weight=10;
	graph->edge[1].src=0;
	graph->edge[1].dest=2;
	graph->edge[1].weight=6;
	graph->edge[2].src=0;
	graph->edge[2].dest=3;
	graph->edge[2].weight=5;
	graph->edge[3].src=1;
	graph->edge[3].dest=3;
	graph->edge[3].weight=15;
	graph->edge[4].src=2;
	graph->edge[4].dest=3;
	graph->edge[4].weight=4;
	KruskalMST(graph);
	return 0;
}