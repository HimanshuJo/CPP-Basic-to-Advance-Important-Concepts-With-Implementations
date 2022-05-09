#include<bits/stdc++.h>
#include<chrono>
using namespace std;

void subsetsUtil(vector<int> &A, vector<vector<int>> &res, vector<int> &subset, int index)
{
	res.push_back(subset);
	for (int i = index; i < A.size(); ++i)
	{
		subset.push_back(A[i]);
		subsetsUtil(A, res, subset, i + 1);
		subset.pop_back();
	}
	return;
}

vector<vector<int>> subsets(vector<int> &A)
{
	vector<int> subset;
	vector<vector<int>> res;
	int index = 0;
	subsetsUtil(A, res, subset, index);
	return res;
}

int main(){
    vector<int>tmp{2,0,1};
    vector<vector<int>>res=subsets(tmp);
    for(auto &vals: res){
    	for(auto &nums: vals)
    		cout<<nums<<" ";
    	cout<<endl;
    }
}