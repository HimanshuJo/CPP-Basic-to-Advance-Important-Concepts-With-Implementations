#include<vector>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_map<char, vector<char>> buildGraph(vector<pair<char, char>>&edges){
	unordered_map<char, vector<char>>gr;
	for(auto &vals: edges){
		gr[vals.first].push_back(vals.second);
		gr[vals.second].push_back(vals.first);
	}
	return gr;
}

bool hasPath(unordered_map<char, vector<char>>&gr, char src, char dest, unordered_set<char>&seen){
	if(src==dest) return true;
	if(seen.find(src)!=seen.end()) return false;
	seen.insert(src);
	for(auto &nei: gr[src]){
		if(hasPath(gr, nei, dest, seen)){
			return true;
		}
	}
	return false;
}

int main(){
	vector<pair<char, char>>edges{{'i', 'j'}, {'k', 'i'}, {'m', 'k'}, {'k', 'l'}, {'o', 'm'}};
	unordered_map<char, vector<char>>graph=buildGraph(edges);
	unordered_set<char>seen;
	bool res=hasPath(graph, 'j', 'm', seen);
	cout<<(res==1?"true":"false")<<"\n";
}
