/*
	A minimum spanning tree (MST) or minimum weight spanning tree is a 
	subset of the edges of a connected, edge-weighted undirected graph that 
	connects all the vertices together, without any cycles and with the minimum 
	possible total edge weight.

	That is, it is a spanning tree whose sum of edge weights is as small as possible.

	More generally, any edge-weighted undirected graph (not necessarily connected) has 
	a minimum spanning forest, which is a union of the minimum spanning trees for 
	its connected components.

	-------

	There are many use cases for minimum spanning trees. 

		One example is a telecommunications company trying to lay cable in a new neighborhood. 

		If it is constrained to bury the cable only along certain paths (e.g. roads), 
		then there would be a graph containing the points (e.g. houses) connected by 
		those paths. 

		Some of the paths might be more expensive, because they are longer, or require the 
		cable to be buried deeper; these paths would be represented by edges with larger weights. 

		Currency is an acceptable unit for edge weight – there is no requirement for edge 
		lengths to obey normal rules of geometry such as the triangle inequality

	-------

	A spanning tree for that graph would be a subset of those paths that has no 
	cycles but still connects every house; there might be several spanning trees possible. 

	A minimum spanning tree would be one with the lowest total cost, representing the 
	least expensive path for laying the cable.

	-------

	Properties:

		Possible multiplicity:

			If there are n vertices in the graph, then each spanning tree has n − 1 edges.

			There may be several minimum spanning trees of the same weight; 
			in particular, if all the edge weights of a given graph are the same, 
			then every spanning tree of that graph is minimum.

		Uniqueness
			
			If each edge has a distinct weight then there will be only one, 
			unique minimum spanning tree. 

			This is true in many realistic situations, such as the telecommunications 
			company example above, where it's unlikely any two paths have exactly 
			the same cost. 

			This generalizes to spanning forests as well.
*/
// Time complexity is O(E log V)
/*
Prim's:
	It starts to build the Minimum Spanning Tree from any vertex in the graph.

	It traverses one node more than one time to get the minimum distance.

	Prim’s algorithm has a time complexity of O(V^2), V being the number of vertices and 
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