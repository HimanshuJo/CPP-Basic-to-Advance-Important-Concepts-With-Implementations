/*
Print modified array after multiple array range increment operations
*/
/*
Given an array containing n integers and a value d. m queries are given. 
Each query has two values start and end. For each query, the problem is to increment 
the values from the start to end index in the given array by the given value d. 

A linear time-efficient solution is required for handling such multiple queries.

Examples: 
 

Input : arr[] = {3, 5, 4, 8, 6, 1}
        Query list: {0, 3}, {4, 5}, {1, 4}, 
                           {0, 1}, {2, 5}
        d = 2
Output : 7 11 10 14 12 5

Executing 1st query {0, 3}
arr = {5, 7, 6, 10, 6, 1}

Executing 2nd query {4, 5}
arr = {5, 7, 6, 10, 8, 3}

Executing 3rd query {1, 4}
arr = {5, 9, 8, 12, 10, 3}

Executing 4th query {0, 1}
arr = {7, 11, 8, 12, 10, 3}

Executing 5th query {2, 5}
arr = {7, 11, 10, 14, 12, 5}

Note: Each query is executed on the 
previously modified array.
*/
/*
Brute Force:

#include<iostream>
#include<vector>
using namespace std;

vector<int> modifiedArrAfterRngeIncr(vector<int>&in, vector<vector<int>>&qlist, int d){
	for(auto &entries: qlist){
		int bgn=entries[0], end=entries[1];
		for(int i=bgn; i<=end; ++i){
			in[i]+=d;
		}
	}
	return in;
}

int main(){
	vector<int>in{3, 5, 4, 8, 6, 1};
	vector<vector<int>>qlist{{0, 3}, {4, 5}, {1, 4}, {0, 1}, {2, 5}};
	int d=2;
	vector<int>ans=modifiedArrAfterRngeIncr(in, qlist, d);
	for(auto &vals: ans)
		cout<<vals<<" ";
}
*/

#include<iostream>
#include<vector>
using namespace std;


vector<int> modifiedArrAfterRngeIncr(vector<int>&in, vector<vector<int>>&qlist, int d){
	int sz=in.size();
	vector<int>aux(sz, 0);
	for(auto &entries: qlist){
		aux[entries[0]]+=d;
		if(entries[1]+1<=sz-1){
			/*
			We'll populate the previous aux values until the end_idx next,
			currently setting end_idx+1 as -d will result in populating of new values for a range
			and mark the end of the previous range
			e.g. arr=[3, 5, 4, 8, 6, 1]
			     qlist=[[0, 3]]
			     aux original=[2, 0, 0, 0, -2, 0]
			     aux final=[2, 2, 2, 2, 0, 0]
			     resultant arr=[5, 7, 6, 10, 6, 1]
			*/
			aux[entries[1]+1]-=d;
		}
	}
	for(int i=1; i<=sz-1; ++i){
		aux[i]+=aux[i-1];
	}
	for(int i=0; i<sz; ++i){
		aux[i]+=in[i];
	}
	return aux;
}

int main(){
	vector<int>in{3, 5, 4, 8, 6, 1};
	vector<vector<int>>qlist{{0, 3}};
	int d=2;
	vector<int>ans=modifiedArrAfterRngeIncr(in, qlist, d);
	for(auto &vals: ans)
		cout<<vals<<" ";
}