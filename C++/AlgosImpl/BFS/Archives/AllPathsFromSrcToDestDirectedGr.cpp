/*
	Given a directed path, print all the paths from the source to the destination

	E.g. 
	
		Graph {{0, 3}, {0, 1}, {0, 2}, {1, 3}, {2, 0}, {2, 1}}

		Source = 2, Destination = 3

		Output: {{2, 0, 3}, {2, 1, 3}, {2, 0, 1, 3}}
*/

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

bool ifCurNodeAlreadyInPath(vector<int>&nwPath, int node){
	auto it=find(nwPath.begin(), nwPath.end(), node);
	return it==nwPath.end();
}

void bfs(vector<vector<int>>&gr, int src, int dest, vector<vector<int>>&res, vector<int>&bgnPath){
	queue<vector<int>>q;
	bgnPath.push_back(src);
	q.push(bgnPath);
	while(!q.empty()){
		int sz=q.size();
		while(sz--){
			vector<int>curPath=q.front();
			q.pop();
			int curLastNode=curPath.back();
			if(curLastNode==dest){
				res.push_back(curPath);
			}
			for(auto &vals: gr[curLastNode]){
				bool flag=ifCurNodeAlreadyInPath(curPath, vals);
				if(flag){
					vector<int>nwPath=curPath;
					nwPath.push_back(vals);
					q.push(nwPath);
				}
			}
		}
	}
}

vector<vector<int>> findAllPathsFromSrcToDestination(int maxNodes, vector<pair<int, int>>&edges, int src, int dest){
	vector<vector<int>>gr(maxNodes);
	for(auto &vals: edges){
		gr[vals.first].push_back(vals.second);
	}
	vector<vector<int>>res;
	vector<int>bgnPath;
	bfs(gr, src, dest, res, bgnPath);
	return res;
}

int main(){
	vector<pair<int, int>>edges;
	int maxNodes=4;
	edges.push_back({0, 3});
	edges.push_back({0, 1});
	edges.push_back({0, 2});
	edges.push_back({1, 3});
	edges.push_back({2, 0});
	edges.push_back({2, 1});
	int src=2, dest=3;
	vector<vector<int>>allPathsFromSrcToDest=findAllPathsFromSrcToDestination(maxNodes, edges, src, dest);
	for(auto &entries: allPathsFromSrcToDest){
		for(auto &vals: entries){
			cout<<vals<<" "; 
		}
		cout<<endl;
	}
}