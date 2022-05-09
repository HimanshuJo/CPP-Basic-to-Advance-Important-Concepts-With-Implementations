// Shortest distance between a given source and a destination
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

void djks(map<char, vector<pair<char, int>>>&gr, char startNode, char endNode){
	map<char, int>dist;
	map<char, char>predecessor;
	priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>>pq;
	for(auto &entries: gr){
		char curr=entries.first;
		dist[curr]=INT_MAX;
	}
	dist[startNode]=0;
	pq.push({0, startNode});
	while(!pq.empty()){
		pair<int, char>temp=pq.top();
		int d=temp.first;
		char u=temp.second;
		pq.pop();
		if(d>dist[u]) continue;
		vector<pair<char, int>> currNodeNei=gr[u];
		for(auto &vals: currNodeNei){
			int currDist=vals.second;
			char node=vals.first;
			if(d+currDist<dist[node]){
				dist[node]=d+currDist;
				predecessor[node]=u;
				pq.push({dist[node], node});
			}
		}
	}
	char currNode=endNode;
	vector<char>path;
	map<char, int>seenNodes;
	bool flag=false;
	while(currNode!=startNode){
		try{
			auto it=path.begin();
			path.insert(it, currNode);
			currNode=predecessor[currNode];
			if(seenNodes[currNode]==1){
				flag=true;
				cout<<"Path not reachable "<<endl;
				break;
			}
			seenNodes[currNode]=1;
		} catch(...){
			cout<<"Path not reachable "<<endl;
			break;
		}
	}
	if(!flag){
		auto it=path.begin();
		path.insert(it, startNode);
		cout<<"Path: ";
		for(auto &vals: path)
			cout<<vals<<" ";
		cout<<"\n-------\n";
	} else path.clear();
	auto it=dist.find(endNode);
	if(dist[endNode]!=INT_MAX&&it!=dist.end()){
		cout<<"Shortest dist: ";
		cout<<dist[endNode];
	} else{
		cout<<"No shortest distance"<<endl;
	}
}

int main(){
	map<char, vector<pair<char, int>>>gr;
	gr['a']={{'b', 10}, {'c', 3}};
	gr['b']={{'c', 1}, {'d', 2}};
	gr['c']={{'b', 4}, {'d', 8}, {'e', 2}};
	gr['d']={{'e', 7}};
	gr['e']={{'d', 9}};
	djks(gr, 'a', 'd');
}