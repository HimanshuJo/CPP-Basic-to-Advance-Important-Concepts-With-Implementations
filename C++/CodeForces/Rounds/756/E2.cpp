// E2. Escape The Maze (hard version)
/*
The only difference with E1 is the question of the problem.

Vlad built a maze out of n rooms and n−1 bidirectional corridors. From any room u any other room v can be reached through a sequence of corridors. Thus, the room system forms an undirected tree.

Vlad invited k friends to play a game with them.

Vlad starts the game in the room 1 and wins if he reaches a room other than 1, into which exactly one corridor leads. 
Friends are placed in the maze: the friend with number i is in the room xi, and no two friends are in the same room (that is, xi!=xj for all i!=j).
Friends win if one of them meets Vlad in any room or corridor before he wins.

For one unit of time, each participant of the game can go through one corridor. All participants move at the same time. Participants may not move. Each room can fit all participants at the same time.

Friends know the plan of a maze and intend to win. They don't want to waste too much energy. They ask you to determine if they can win and if they can, 
what minimum number of friends must remain in the maze so that they can always catch Vlad.

In other words, you need to determine the size of the minimum (by the number of elements) subset of friends who can catch Vlad or say that such a subset does not exist.

Example
input
4

8 2
5 3
4 7
2 5
1 6
3 6
7 2
1 7
6 8

8 4
6 5 7 3
4 7
2 5
1 6
3 6
7 2
1 7
6 8

3 1
2
1 2
2 3

3 2
2 3
3 1
1 2
output
-1
2
1
2
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>gr;
vector<int>nearest;

int dfs(int v, int dist, int p){
	bool children=true;
	int s=0;
	for(auto &nei: gr[v]){
		if(nei==p) continue;
		int c=dfs(nei, dist+1, v);
		if(c<0) children=false;
		nearest[v]=min(nearest[v], nearest[nei]+1);
		s+=c;
	}
	if(nearest[v]<=dist) return 1;
	if(s==0||!children) return -1;
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		gr.assign(n, vector<int>(0));
		nearest.assign(n, n);
		for(int i=0; i<k; ++i){
			int x;
			cin>>x;
			--x;
			nearest[x]=0;
		}
		for(int i=1; i<n; ++i){
			int u, v;
			cin>>u>>v;
			--u, --v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		int res=dfs(0, 0, -1);
		cout<<res<<"\n";
	}
}
