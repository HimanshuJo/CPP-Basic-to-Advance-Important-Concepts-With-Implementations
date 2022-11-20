// G - Longest Path
/*
There is a directed graph G with N vertices and M edges. 

The vertices are numbered 1,2,…,N, and for each i (1≤i≤M), 
the i-th directed edge goes from Vertex xi to yi. 

G does not contain directed cycles.

Find the length of the longest directed path in G. 
Here, the length of a directed path is the number of edges in it.

Constraints
All values in input are integers.
2≤N≤10^5
 
1≤M≤10^5
 
1≤xi,yi≤N

All pairs (xi,yi) are distinct.
G does not contain directed cycles.

Sample Input 1
4 5
1 2
1 3
3 2
2 4
3 4

Sample Output 1 
2
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int dfs(vector<vector<int>>&gr, unordered_map<int, int>&mp, int curvert){
	if(mp.find(curvert)!=mp.end()) return mp[curvert];
	int count=0;
	for(auto &child: gr[curvert]){
		count=max(count, 1+dfs(gr, mp, child));
	}
	return mp[curvert]=count;
}

int main(){
	int N, M;
	cin>>N>>M;
	vector<vector<int>>gr(N+1);
	unordered_map<int, int>mp;
	for(int i=0; i<M; ++i){
		int src, dest;
		cin>>src>>dest;
		gr[src].push_back(dest);
	}
	int ans=INT_MIN;
	for(int i=1; i<=N; ++i){
		if(mp.find(i)==mp.end()){
			dfs(gr, mp, i);
			ans=max(ans, mp[i]);
		}
	}
	cout<<ans;
}
