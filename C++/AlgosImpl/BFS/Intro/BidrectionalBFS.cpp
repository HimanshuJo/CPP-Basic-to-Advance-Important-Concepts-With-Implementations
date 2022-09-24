// Bidirectional Search
/*
Why bidirectional approach?

	Because in many cases it is faster, it dramatically reduce the amount of required exploration.

	Suppose if branching factor of tree is b and distance of goal vertex from source is d, then 
	the normal BFS/DFS searching complexity would be O(b^d). 

	On the other hand, if we execute two search operation then the complexity would be O(b^d/2) for each search and 
	total complexity would be O(b^d/2 + b^d/2) which is far less than O(b^d).

-------

When to use bidirectional approach?

	We can consider bidirectional approach when- 

		Both initial and goal states are unique and completely defined.
		
		The branching factor is exactly the same in both directions.

-------

Performance measures

	Completeness : Bidirectional search is complete if BFS is used in both searches.
	
	Optimality : It is optimal if BFS is used for search and paths have uniform cost.
	
	Time and Space Complexity : Time and space complexity is O(b^d/2).
*/

#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;

class Graph{
private:
	int V;
	vector<int>*adj;
public:
	Graph(int V);
	int isIntersecting(vector<bool>&frnt_visited, vector<bool>&end_visited);
	void addEdge(int src, int dest);
    void getPath(vector<int>&frnt_parent, vector<int>&end_parent, int strt, int end, int intersectingNode);
    void bfs(queue<int>&q, vector<bool>&visited, vector<int>&parent);
    int bidirectionalSearch(int src, int target);
};

Graph::Graph(int V){
    this->V=V;
    adj=new vector<int>[V];
};

void Graph::addEdge(int src, int dest){
    this->adj[src].push_back(dest);
    this->adj[dest].push_back(src);
};

void Graph::bfs(queue<int>&q, vector<bool>&visited, vector<int>&parent){
    int curvert=q.front();
    visited[curvert]=true;
    q.pop();
    for(auto &nei: adj[curvert]){
        if(!visited[nei]){
            parent[nei]=curvert;
            q.push(nei);
            visited[nei]=true;
        }
    }
};

int Graph::isIntersecting(vector<bool>&frnt_visited, vector<bool>&end_visited){
    int intersecting_node=-1;
    for(int i=0; i<V; ++i){
        if(frnt_visited[i]&&end_visited[i]){
            intersecting_node=i;
            break;
        }
    }
    return intersecting_node;
};

void Graph::getPath(vector<int>&frnt_parent, vector<int>&end_parent, int strt, int end, int intersectingNode){
    vector<int>path;
    int i=intersectingNode;
    while(i!=strt){
        path.push_back(frnt_parent[i]);
        i=frnt_parent[i];
    }
    reverse(path.begin(), path.end());
    path.push_back(intersectingNode);
    i=intersectingNode;
    while(i!=end){
        path.push_back(end_parent[i]);
        i=end_parent[i];
    }
    for(auto &vals: path){
        cout<<vals<<" ";
    }
    cout<<endl;
};

int Graph::bidirectionalSearch(int src, int target){
    vector<bool>frnt_visited(V, false), end_visited(V, false);
    vector<int>frnt_parent(V), end_parent(V);
    queue<int>frnt_q, end_q;
    int intersectingNd=-1;
    frnt_q.push(src);
    frnt_visited[src]=true;
    frnt_parent[src]=-1;
    end_q.push(target);
    end_visited[target]=true;
    end_parent[target]=-1;
    bool flag=false;
    while(!frnt_q.empty()&!end_q.empty()){
        bfs(frnt_q, frnt_visited, frnt_parent);
        bfs(end_q, end_visited, end_parent);
        intersectingNd=isIntersecting(frnt_visited, end_visited);
        if(intersectingNd!=-1){
            getPath(frnt_parent, end_parent, src, target, intersectingNd);
            flag=true;
            break;
        }
    }
    return !flag?-1:INT_MAX;
};

int main(){
    int n=15;
    int s=0;
    int t=14;
    Graph g(n);
    g.addEdge(0, 4);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(8, 10);
    g.addEdge(9, 11);
    g.addEdge(9, 12);
    g.addEdge(10, 13);
    g.addEdge(10, 14);
    if(g.bidirectionalSearch(s, t)==-1)
        cout << "Path don't exist between "
             << s << " and " << t << "\n";
    return 0;
}