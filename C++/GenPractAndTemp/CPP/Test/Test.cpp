// Shortest distance between a given source and a destination
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
	vector<vector<int>>vec{{5, 1}, {6, 8}, {9, 1}};
	vector<int>temp={9, INT_MAX, INT_MAX};
	auto it=upper_bound(vec.begin(), vec.end(), temp);
	cout<<it-vec.begin();
}