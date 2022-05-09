// E1. Escape The Maze (easy version)
/*
Vlad built a maze out of n rooms and n−1 bidirectional corridors. 
From any room u any other room v can be reached through a sequence of corridors. 
Thus, the room system forms an undirected tree.

Vlad invited k friends to play a game with them.

Vlad starts the game in the room 1 and wins if he reaches a room other than 1, 
into which exactly one corridor leads.

Friends are placed in the maze: the friend with number i is in the room xi, and 
no two friends are in the same room 
(that is, xi!=xj for all i!=j). 
Friends win if one of them meets Vlad in any room or corridor before he wins.

For one unit of time, each participant of the game can go through one corridor. 
All participants move at the same time. 
Participants may not move. 
Each room can fit all participants at the same time.

Friends know the plan of a maze and intend to win. Vlad is a bit afraid of their ardor. 
Determine if he can guarantee victory 
(i.e. can he win in any way friends play).

In other words, determine if there is such a sequence of Vlad's moves that 
lets Vlad win in any way friends play.

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

3 1
2
1 2
2 3

3 1
2
1 2
1 3

3 2
2 3
3 1
1 2

output
YES
NO
YES
NO
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int>color(n, -1);
		deque<int>q;
		for(int i=0; i<k; ++i){
			int x;
			cin>>x;
			color[--x]=0;
			q.push_back(x);
		}
		color[0]=1;
		q.push_back(0);
		vector<vector<int>>gr(n);
		for(int i=0; i<n-1; ++i){
			int u, v;
			cin>>u>>v;
			--u, --v;
			gr[u].push_back(v);
			gr[v].push_back(u);
		}
		while(!q.empty()){
			int v=q.front();
			q.pop_front();
			for(auto &nei: gr[v]){
				if(color[nei]==-1){
					color[nei]=color[v];
					q.push_back(nei);
				}
			}
		}
		bool flag=false;
		for(int v=1; v<n; ++v){
			if(gr[v].size()==1&&color[v]==1){
				flag=true;
				cout<<"YES\n";
				break;
			}
		}
		if(!flag)
			cout<<"NO\n";
	}
}
