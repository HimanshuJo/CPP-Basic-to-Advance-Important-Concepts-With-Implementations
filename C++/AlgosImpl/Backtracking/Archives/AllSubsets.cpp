/*
	Generate all the possible subsets of an array

	Example: arr={1, 2, 3, 4}

	         All subsets: (2^N) All proper subsets: (2^N-1)

	         	{}
	         	1
	         	2
	         	3
	         	4
	         	1 2
	         	1 2 3
				1 3 4
				1 2 4
				1 2 3 4
				1 3
				1 4
				2 3
				2 4
				2 3 4
				3 4
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int>&in, vector<vector<int>>&res, vector<int>&curr, int sz, int idx){
    res.push_back(curr);
    for(int i=idx; i<sz; ++i){
        curr.push_back(in[i]);
        dfs(in, res, curr, sz, i+1);
        curr.pop_back();
    }
}

vector<vector<int>> genAllSubsets(vector<int>&in){
    vector<vector<int>>res;
    vector<int>curr;
    int sz=in.size();
    dfs(in, res, curr, sz, 0);
    return res;
}

int main(){
    vector<int>in{1, 2, 3, 4, 5};
    vector<vector<int>>allSubsets=genAllSubsets(in);
    for(auto &entries: allSubsets){
        for(auto &vals: entries){
            cout<<vals<<" ";
        }
        cout<<endl;
    }
}