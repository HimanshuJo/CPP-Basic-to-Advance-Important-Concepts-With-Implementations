/*
Given an n*m maze of boolean and a robot standing at origin, return any possible path from the origin
to the bottom right corner of the maze that is at {n-1, m-1}

True value in the maze denotes robot can visit the block and false value denotes, robot can't visit the
block. Robot can only move in the right and down direction.
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

bool getPathUtil(vector<vector<bool>>&maze, int rw, int col, vector<pair<int, int>>&path, set<pair<int, int>>&seenCoords){
	if(col<0||rw<0||!maze[rw][col]) return false;
	pair<int, int>curr={rw, col};
	auto it=seenCoords.find(curr);
	if(it!=seenCoords.end()) return false;
	bool isAtOrigin=(rw==0)&&(col==0);
	if(isAtOrigin||getPathUtil(maze, rw, col-1, path, seenCoords)||getPathUtil(maze, rw-1, col, path, seenCoords)){
		path.push_back(curr);
		return true;
	}
	seenCoords.insert(curr);
	return false;
}

vector<pair<int, int>> getPath(vector<vector<bool>>&maze){
	int n=maze.size();
	int m=maze[0].size();
	if(n==0) return {make_pair(0, 0)};
	vector<pair<int, int>>path;
	set<pair<int, int>>seenCoords;
	if(getPathUtil(maze, n-1, m-1, path, seenCoords)) return path;
	return {make_pair(0, 0)};	
}

int main(){
	vector<vector<bool>>maze{{true, true, true, true}, 
							 {true, false, true, true},
							 {false, true, false, true},
							 {true, true, true, true}};
	vector<pair<int, int>>res=getPath(maze);
	for(auto &vals: res){
		cout<<vals.first<<" "<<vals.second<<endl;
	}
}
