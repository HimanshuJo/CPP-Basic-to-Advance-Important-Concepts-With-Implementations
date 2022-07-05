/*
	Given a directed graph and two nodes (S and E), design an algorithm to find out
	whether there is a route from S to E
*/

#include<vector>
#include<iostream>
#include<queue>
using namespace std;

enum class State {unvisited, visited};

class Node{
	public:
	int val;
	State state;
	Node(){}
	Node(int data,  State st){
		val=data;
		state=st;
	}
};

bool bfs1(const int source, const int dest, const int N, 
         vector<vector<int>>&adj, vector<bool>&seen){
	queue<int>q;
	q.push(source);
	seen[source]=true;
	while(!q.empty()){
		int sz=q.size();
		while(sz--){
			int curr=q.front();
			q.pop();
			if(curr==dest){
				return true;
			}
			for(auto &nei: adj[curr]){
				if(!seen[nei]){
					seen[nei]=true;
					q.push(nei);
				}
			}
		}
	}
	return false;
}

bool hasPath1(int source, int dest, int N, vector<vector<int>>&edges){
	vector<vector<int>>adj(N+1);
	for(auto &vals: edges){
		adj[vals[0]].push_back(vals[1]);
	}
	vector<bool>seen(N+1, false);
	bool ans=bfs1(source, dest, N, adj, seen);
	return ans;
}

bool bfs2(Node source, Node dest, vector<vector<Node>>&adj){
	queue<Node>q;
	Node u;
	q.push(source);
	while(!q.empty()){
		int sz=q.size();
		while(sz--){
			u=q.front();
			q.pop();
			if(u.val==dest.val){
				return true;
			}
			for(auto &nei: adj[u.val]){
				if(nei.state==State::unvisited){
					nei.state=State::visited;
					q.push(nei);
				}
			}
		}
	}
	return false;
}

bool hasPath2(Node source, Node dest, int N, vector<vector<Node>>&edges){
	vector<vector<Node>>adj(N+1);
	for(auto &vals: edges){
		adj[vals[0].val].push_back(vals[1]);
	}
	bool ans=bfs2(source, dest, adj);
	return ans;
}

int main(){
	State s1=State::unvisited;
	Node obj1(1, s1);
	Node obj2(2, s1);
	Node obj3(3, s1);
	Node obj4(4, s1);
	Node obj5(5, s1);
	Node obj6(6, s1);
	int N=6;
	/*
			   1--->2--->3-->5
                             | 
				--->4--->6<---

	*/
	vector<vector<int>>edges{{1, 2}, {2, 3}, {3, 5}, {1, 4}, {4, 6}, {5, 6}};
	vector<vector<Node>>edges_{{obj1, obj2}, {obj2, obj3}, {obj3, obj5}, 
	                           {obj1, obj4}, {obj4, obj6}, {obj5, obj6}};
	bool ans1=hasPath1(5, 1, N, edges);
	bool ans2=hasPath2(obj5, obj1, N, edges_);
	cout<<(ans1==1?"Yes":"No")<<endl;
	cout<<(ans2==1?"Yes":"No")<<endl;
}