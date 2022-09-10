#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int INF=1e9+7;

class Solution{
public:

	bool isValid(vector<vector<int>>&in, vector<vector<int>>&res, 
	             int i, int j, int rws, int cols){
		return (i>=0&&j>=0&&i<rws&&j<cols&&in[i][j]!=0&&res[i][j]!=1);
	}

	bool dfs(vector<vector<int>>&in, vector<vector<int>>&res, int i, int j, int rws, int cols){
		if(i==rws-1&&j==cols-1&&in[i][j]==1){
			res[i][j]=1;
			return true;
		}
		if(isValid(in, res, i, j, rws, cols)){
			res[i][j]=1;
			if(dfs(in, res, i+1, j, rws, cols)) return true;
			if(dfs(in, res, i, j+1, rws, cols)) return true;
			res[i][j]=INF;
			return false;
		}
		return false;
	}
};

// -------*******-------

class Solution2{
public:

	bool isValid(vector<vector<int>>&in, vector<vector<int>>&res, 
	             int i, int j, int rws, int cols){
		return (i>=0&&j>=0&&i<rws&&j<cols&&in[i][j]!=0&&res[i][j]!=1);
	}

	bool dfs(vector<vector<int>>&in, vector<vector<int>>&res, int i, int j, int rws, int cols){
		if(i==rws-1&&j==cols-1&&in[i][j]==1){
			res[i][j]=1;
			return true;
		}
		if(isValid(in, res, i, j, rws, cols)){
			res[i][j]=1;
			if(dfs(in, res, i+1, j, rws, cols)) return true;
			res[i][j]=INF;
		}
		if(isValid(in, res, i, j, rws, cols)){
			res[i][j]=1;
			if(dfs(in, res, i, j+1, rws, cols)) return true;
			res[i][j]=INF;
			return false;
		}
		return false;
	}
};

int main(){
	vector<vector<int>>in{ { 1, 1, 1, 1 }, { 0, 0, 0, 1 }, { 0, 1, 0, 1 }, { 1, 1, 1, 1 } };
	int rws=in.size(), cols=in[0].size();
	vector<vector<int>>res(rws, vector<int>(cols, INF));
	Solution2 obj;
	bool ans=obj.dfs(in, res, 0, 0, rws, cols);
	if(ans){
		for(int i=0; i<rws; ++i){
			for(int j=0; j<cols; ++j){
				cout<<res[i][j]<<" ";
			}
			cout<<endl;
		}
	} else cout<<"No Path "<<endl;
}