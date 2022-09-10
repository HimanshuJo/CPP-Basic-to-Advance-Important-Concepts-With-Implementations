// Print all paths from a given source to a destination
/*
Given a directed graph, a source vertex ‘src’ and a 
destination vertex ‘dst’, print all paths from given ‘src’ to ‘dst’.
*/
/*
Algorithm :  

create a queue which will store path(s) of type vector
initialize the queue with first path starting from src

Now run a loop till queue is not empty
   Get the front-most path from queue
   
   Check if the last-node of this path is destination
    	if true then print the path
   
   Run a loop for all the vertices connected to the
   current vertex i.e. lastnode extracted from path
      
      if the vertex is not visited in current path
      
         a) create a new path from earlier path and append this vertex
      
         b) insert this new path to queue
*/

#include<vector>
#include<queue>
#include<iostream>
using namespace std;

void printPath(vector<int>&path){
	int sz=path.size();
	for(int i=0; i<sz; ++i){
		cout<<path[i]<<" ";
	}
	cout<<endl;
}

/*
If current vertex is already present in the path
*/
int isNotVisited(int x, vector<int>&path){
	int sz=path.size();
	for(int i=0; i<sz; ++i){
		if(path[i]==x) return 0;
	}
	return 1;
}

void findPaths(vector<vector<int>>&gr, int src, int dest, int v){
	queue<vector<int>>q;
	vector<int>path;
	path.push_back(src);
	q.push(path);
	while(!q.empty()){
		path=q.front();
		q.pop();
		int last=path[path.size()-1];
		if(last==dest){
			printPath(path);
		}
		for(int i=0; i<gr[last].size(); ++i){
			if(isNotVisited(gr[last][i], path)){
				vector<int>newPath(path);
				newPath.push_back(gr[last][i]);
				q.push(newPath);
			}
		}
	}
}

int main(){
	vector<vector<int> > g;
 	int v = 4;
	g.resize(4);
	g[0].push_back(3);
	g[0].push_back(1);
	g[0].push_back(2);
	g[1].push_back(3);
	g[2].push_back(0);
	g[2].push_back(1);
	int src = 2, dst = 3;
	cout << "path from src " << src
	     << " to dst " << dst << " are \n";
	findPaths(g, src, dst, v);
	return 0;
}